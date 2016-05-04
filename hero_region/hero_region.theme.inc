<?php

/**
 * Returns themed HTML for degree program custom blocks.
 */
function gsb_public_custom_blocks_preprocess_gsb_public_custom_blocks_hero_region(&$variables) {
  $node = menu_get_object('node');
  if ($node == null) {
    return;
  }
  $language = $node->language;
  if (!empty($node->field_hero_region_options[$language][0]['value']) && $node->field_hero_region_options[$language][0]['value'] == 'image') {
    $image = theme('image', array(
      'path' => $node->field_image_single_public[$language][0]['uri'],
      'width' => $node->field_image_single_public[$language][0]['width'],
      'height' => $node->field_image_single_public[$language][0]['height'],
      'alt' => $node->field_image_single_public[$language][0]['alt']
    ));
    $variables['hero_region'] = $image;
  }
}