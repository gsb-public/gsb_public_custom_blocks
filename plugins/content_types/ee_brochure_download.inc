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

    $program_ids = $output['brochure_list']['#value'];
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
      $uploaded_files[$record->filename] = $record->uri;
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

  $output .= theme('item_list', array('items' => $items)) . $zipped_file;
  return (object) array(
    'title' => t(''),
    'content' => $output,
  );
}