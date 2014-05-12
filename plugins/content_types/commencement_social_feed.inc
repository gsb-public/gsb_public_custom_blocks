<?php

$plugin = array(
  'title' => t('Commencement: Social Feed'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_commencement_social_feed_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'content' => array(
    '#markup' => '<script src="http://static.getchute.com/display-runners/wall/wall.js" data-chute-wall="http://s3.amazonaws.com/store.getchute.com/5367de3cd652e62dab000001"></script>
    <img src="http://pixel.getchute.com/?dID=5367de3cd652e62dab000001&cID=63&eTp=view_served" style="width:0; height: 0">',
    ),
  );
}
