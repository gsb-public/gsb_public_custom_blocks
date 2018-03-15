<?php

$plugin = array(
  'title' => t('EE Brochure Download'),
  'category' => t('Administrator Blocks'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_ee_brochure_download_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  module_load_include('inc','webform','includes/webform.submissions');
  $sid = $_GET['sid'];
  $output = "";
  $uploaded_files = array();
  if (!empty($sid)) {
    $submission = webform_get_submissions(array('sid' => $sid));
    $nid = $submission[$sid]->nid;
    $web_submission = webform_get_submission($nid, $sid);
    $node = node_load($nid);
    $output = webform_submission_render($node, $web_submission, NULL, 'html');

    $program_ids = null;

    if (!empty($output['brochure_list']) && !empty($output['brochure_list']['#value'])) {
      $program_ids = $output['brochure_list']['#value'];
    }

    if (!empty($output['apower_ids_hidden'])) {
      $parsed_url = parse_url($output['apower_ids_hidden']['#markup']);
      if (!empty($parsed_url['query']))
      {
        $query = $parsed_url['query'];
        parse_str($query, $query_array);
        $pids = urldecode($query_array['pid']);
        $program_ids = explode(",",$pids);
      }
    }

    $select = db_select('node', 'n');
    $select->fields('n', array('title', 'nid'));
    $select->leftJoin('field_data_field_brochure_pdf', 'pdf', 'n.nid = pdf.entity_id AND pdf.deleted = 0');
    $select->leftJoin('file_managed', 'fm', 'pdf.field_brochure_pdf_fid = fm.fid');
    $select->addField('pdf', 'field_brochure_pdf_fid', 'fid');
    $select->addField('fm', 'uri', 'uri');
    $select->addField('fm', 'filename', 'filename');
    $select->condition('pdf.entity_id', $program_ids, 'IN');
    $query = $select->execute();
    $records = $query->fetchAll();
    $output = "";
    $file_num = '';

    foreach ($records as $record) {
      $file_num .= $record->fid;
      $file_parts = explode('//' , $record->uri);
      //$uploaded_files[$record->filename] = $record->uri;
      $uploaded_files[$file_parts[1]] = $record->uri;
      $items[] = l(t($record->title), file_create_url($record->uri), array('attributes' => array('target' => 'blank')));
    }

    $zipped_file = "";
    if (sizeof($uploaded_files) > 1) {
      $dir = 'public://brochures/';
      if (!(file_prepare_directory($dir, FILE_CREATE_DIRECTORY))) {
        drupal_mkdir('public://brochures/', 0755);
      }
      $archive_uri = 'public://brochures/brochure_download_' . crc32($file_num) . '.zip';
      //$archive_uri = 'public://brochures_a/brochure_download_' . REQUEST_TIME . '.zip';
      if (!(file_exists($archive_uri))) {
        $zip = new ZipArchive;
        if ($zip->open(drupal_realpath($archive_uri), ZipArchive::CREATE) === TRUE) {
          foreach ($uploaded_files as $filename => $uri) {
            $zip->addFile(drupal_realpath($uri), $filename);
          }
          $zip->close();
        }
      }
        $zipped_file = l("Download All Brochures", file_create_url($archive_uri), $options = array('attributes' => array('class' => array('button'), 'name' => 'button',)));
    }
  }

  $program_info = array();
  $program_nodes = node_load_multiple($program_ids);
  $program_instances = _gsb_public_custom_blocks_ee_brochure_download_get_program_instances($program_ids);
  foreach ($program_nodes as $node) {
    $progam_instance = _gsb_public_custom_blocks_ee_brochure_download_find_program_instance($node->nid, $program_instances);
    $pi_node = node_load($progam_instance->nid);
    $apowerid = $pi_node->field_apower_id['und'][0]['value'];
    $program_info[] = array('title' => $node->title, 'apowerid' => $apowerid);
  }

  drupal_add_js(drupal_get_path('module', 'gsb_public_custom_blocks') . '/js/ee_brochure_download.js');
  $settings = array (
    'program_info' => $program_info,
  );
  drupal_add_js(array("ee_brochure_download_settings" => $settings), 'setting');

  $output .= theme('item_list', array('items' => $items)) . $zipped_file;
  return (object) array(
    'title' => t(''),
    'content' => $output,
  );
}

/**
 * Get the most current program instances related to each of these programs
 */
function _gsb_public_custom_blocks_ee_brochure_download_get_program_instances($program_nids) {

  $today = date('Y-m-d H:i:s', mktime(0,0,0));

  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'status', 'type'));
  $query->join('field_data_field_program', 'fp', "n.nid = fp.entity_id AND fp.entity_type = 'node' AND fp.deleted = '0'");
  $query->fields('fp', array('entity_id', 'entity_type', 'deleted', 'field_program_target_id'));
  $query->join('node', 'nodefp', 'fp.field_program_target_id = nodefp.nid');
  $query->fields('nodefp', array('nid'));
  $query->join('field_data_field_instance_date', 'fid', "n.nid = fid.entity_id AND fid.entity_type = 'node' AND fid.deleted = '0'");
  $query->fields('fid', array('field_instance_date_value'));
  $query->join('field_data_field_display_on_finder', 'dof', "n.nid = dof.entity_id AND dof.entity_type = 'node' AND dof.deleted = '0'");
  $query->condition('nodefp.nid', $program_nids, 'IN');
  $query->condition('n.status', '1');
  $query->condition('n.type', 'program_instance');
  $query->condition('fid.field_instance_date_value', $today, '>=');
  $query->condition('dof.field_display_on_finder_value', '1');
  $query->orderBy('fid.field_instance_date_value', 'ASC');
  $results = $query->execute();

  $program_instances = array();
  foreach($results as $instance) {
    $program_instances[] = $instance;
  }

  return $program_instances;
}

/**
 * Find a program instance related to the program
 */
function _gsb_public_custom_blocks_ee_brochure_download_find_program_instance($program_nid, $program_instances) {
  foreach ($program_instances as $pi) {
    if ($pi->field_program_target_id == $program_nid) {
      return $pi;
    }
  }
  return null;
}
