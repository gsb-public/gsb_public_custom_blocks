<?php

$plugin = array(
  'title' => t('Who should attend'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_program_who_should_attend_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  $language = $context['panelizer']->data->language;
  $program_nid = $context['panelizer']->data->field_program[$language][0]['target_id'];
  $program_node = node_load($program_nid);
  $text = array();
  foreach($program_node->field_event_who_attend[$language] as $who_attend) {
    $text[] = $who_attend['safe_value'];
  }
  return (object) array(
    'title' => 'Who Should Attend',
    'content' => array(
      '#markup' => theme('item_list', array('items' => $text)),
    ),
  );
}
