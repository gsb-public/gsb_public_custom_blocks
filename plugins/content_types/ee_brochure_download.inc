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
    $select->condition('pdf.entity_id', $program_ids , 'IN');
    $query = $select->execute();
    $records = $query->fetchAll();
    $output = "<p> Download brochures for selected program(s) here</p> ";
    foreach ($records as $record) {
      $items[] = l(t($record->title), file_create_url($record->uri), array('attributes'=>array('target'=>'blank')));
    }
  }
  $output .= theme('item_list', array('items' => $items));
  return (object) array(
    'title' => t(''),
    'content' => $output,
  );
}