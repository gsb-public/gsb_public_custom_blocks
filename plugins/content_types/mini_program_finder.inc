<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Exec Ed: Program Finder (mini)'),
  'description' => t('Shows mini program finder configuration options.'),
  'category' => t('Custom blocks'),
  'edit form' => 'gsb_public_custom_blocks_mini_program_finder_edit_form',
  'render callback' => 'gsb_public_custom_blocks_mini_program_finder_content_type_render',
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_mini_program_finder_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

  $select = db_select('node','n');
  $select->condition('n.status', 1);
  $select->condition('n.type', 'program_instance');
  //Program Title
  $select->leftJoin('field_data_field_program', 'p', 'n.nid = p.entity_id AND p.deleted = 0');
  $select->leftJoin('node', 'n2', 'n2.nid = p.field_program_target_id');
  //Program Category
  $select->leftJoin('field_data_field_program_category', 'pc', 'n2.nid = pc.entity_id AND pc.deleted = 0');
  $select->leftJoin('taxonomy_term_data', 'ttd_pc', 'pc.field_program_category_tid = ttd_pc.tid');

  //Dates
  $select->leftJoin('field_data_field_instance_date', 'dt', 'n.nid = dt.entity_id AND dt.deleted = 0');
  $select->addField('dt', 'field_instance_date_value', 'start_date');
  $select->addField('dt', 'field_instance_date_value2', 'end_date');

  //Topics
  $select->leftJoin('field_data_field_program_topics', 'pt', 'n2.nid = pt.entity_id AND pt.deleted = 0');
  $select->leftJoin('taxonomy_term_data', 'ttd_pt', 'pt.field_program_topics_tid = ttd_pt.tid');
  $select->addField('ttd_pt', 'tid', 'program_topics_tid');
  $select->addField('ttd_pt', 'name', 'program_topics');
  $select->leftJoin('field_data_field_display_on_finder', 'df', 'n.nid = df.entity_id AND df.deleted = 0');
  $select->condition('df.field_display_on_finder_value', 1);
  $today = new DateTime();
  $today = $today->format('Y-m-d\T00:00:00');
  $select->condition('dt.field_instance_date_value', $today, '>=');
  $select->orderBy('program_topics','ASC');
  $select->distinct();
  $query = $select->execute();
  $topics = array();
  $start_date = array();
  $end_date = array();
  while ($result = $query->fetchObject()) {
      if ($result->program_topics_tid) {
        $key = drupal_html_class($result->program_topics);
        $topics[$key] = $result->program_topics;
      }
      if ($result->start_date && $result->end_date) {
        $sdate = date('Ymd', strtotime($result->start_date));
        $edate = date('Ymd', strtotime($result->end_date));
        $start_date[$sdate] = $sdate;
        $end_date[$edate] = $edate;
      }
  }

  $minifinder_setting = array(
     'minifinder' => array(
       "start_date" => $today,
       "end_date" => date('Y-m-d', strtotime(max($end_date))),
     ),
  );
  drupal_add_js($minifinder_setting, 'setting');
  $img = array('finder_img' => $conf['finder_image']);
  $output = theme('gsb_public_custom_blocks_mini_program_finder', $img);
    $output .= '<div class="mini-program-finder-title-filters"><div class="inner">
  <h1>' . t('Find An Executive Education Program') . '</h1><div class="mini-finder-filters">' . mini_finder_render($topics) . '</div></div></div>';


  return (object) array(
    'content' => array(
      '#markup' => $output,
    ),
  );
}
