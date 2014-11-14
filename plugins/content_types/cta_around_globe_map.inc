<?php

$plugin = array(
  'title' => t('TSE: Map | Around the World'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_cta_around_globe_map_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'content' => array(
      '#attached' => array(
        'js' => array(
          'http://api.tiles.mapbox.com/mapbox.js/v1.0.2/mapbox.js' => array(
            'type' => 'external',
          ),       
          drupal_get_path('module', 'gsb_public_custom_blocks') . '/js/cta_around_globe_map.js',
        ),
        'css' => array(
          'http://api.tiles.mapbox.com/mapbox.js/v1.0.2/mapbox.css' => array(
            'type' => 'external',
          ),
          drupal_get_path('module', 'gsb_public_custom_blocks') . '/css/cta_around_globe_map.css',
        ),       
      ),
      '#markup' => '<div class="mapwrap"><div id="map"></div></div>',
    ),
  );
}
