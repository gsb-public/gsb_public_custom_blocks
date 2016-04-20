<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Program Finder: Degree Programs'),
  'description' => t('Shows GSB degree programs.'),
  'category' => t('Custom Content & Features'),
  'render callback' => 'gsb_public_custom_blocks_degree_programs_content_type_render',
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_degree_programs_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  $select = db_select('node','n');
  $select->fields('n', array('title', 'nid'));
  $select->condition('n.status', 1);
  $select->condition('n.type', 'program');
  //Program Category
  $select->leftJoin('field_data_field_program_category', 'pc', 'n.nid = pc.entity_id AND pc.deleted = 0');
  $select->leftJoin('taxonomy_term_data', 'ttd_pc', 'pc.field_program_category_tid = ttd_pc.tid');
  $select->addField('ttd_pc', 'tid', 'program_category_tid');
  $select->addField('ttd_pc', 'name', 'program_category');
  //Detail Page and URL
  $select->leftJoin('field_data_field_program_detail', 'pd', 'n.nid = pd.entity_id AND pd.deleted = 0');
  $select->addField('pd', 'field_program_detail_value', 'program_detail_page');
  $select->leftJoin('field_data_field_link_single', 'pu', 'n.nid = pu.entity_id AND pu.deleted = 0');
  $select->addField('pu', 'field_link_single_url', 'link_url');
  //Program Teaser
  $select->leftJoin('field_data_field_overview_intro', 'ot', 'n.nid = ot.entity_id AND ot.deleted = 0');
  $select->addField('ot', 'field_overview_intro_value', 'program_teaser');
  $select->condition('ttd_pc.name', 'Degree Program');
  $select->orderBy('title','ASC');
  $query = $select->execute();

  $degree_programs = array();
  while ($result = $query->fetchObject()) {
    $nid = $result->nid;
    $degree_programs[$nid]['title'] = $result->title;
    $degree_programs[$nid]['program_teaser'] = $result->program_teaser;

  }

  $output = theme('gsb_public_custom_blocks_degree_programs', array('degree_programs' => $degree_programs));

  return (object) array(
    'content' => array(
      '#markup' => $output,
    ),
  );
}
