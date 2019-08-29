<?php

$plugin = array(
  'title' => t('PhD Inquiry | Slate form'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_slate_embed_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'title' => '',
    'content' => array(
      '#markup' => '<a href="#">' . t('PhD Inquiry') . '</a>',
    ),
  );
}
