<?php

$plugin = array(
  'title' => t('Library: Button | Bookmarklet Link'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_bookmarklet_link_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'title' => '',
    'content' => array(
    '#markup' => '<a href="javascript:void(location.href=\'http://gsbproxy.stanford.edu/login?sourceid=gsbproxy-bookmarklet&amp;url=\'+location.href)">' . t('SUNet Login for eResources') . '</a>',
    ),
  );
}
