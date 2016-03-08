<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Need more Information'),
  'description' => t('Shows a need more information configuration options.'),
  'category' => t('Custom blocks'),
  'edit form' => 'gsb_public_custom_blocks_need_more_information_edit_form',
  'render callback' => 'gsb_public_custom_blocks_need_more_information_content_type_render',
   );

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_need_more_information_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
dpm($conf);
  $ctas = array('cta' => $conf['cta']);
  $output = theme('gsb_public_custom_blocks_need_more_information', $ctas);

  return (object) array(
    'content' => array(
      '#markup' => $output,
    ),
  );
}
?>