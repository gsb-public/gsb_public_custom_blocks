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
  // render image
  $variables['hero_region']['image'] = array();
  if (!empty($node->field_hero_region_options[$language][0]['value']) && $node->field_hero_region_options[$language][0]['value'] == 'image') {
    if (!empty($node->field_image_single_public[$language])) {
      $image = theme_image_style(array(
        'style_name' => 'compress',
        'path' => $node->field_image_single_public[$language][0]['uri'],
        'width' => $node->field_image_single_public[$language][0]['width'],
        'height' => $node->field_image_single_public[$language][0]['height'],
        'alt' => $node->field_image_single_public[$language][0]['alt']
      ));
      $variables['hero_region']['image'] = $image;
    }
  }

  // Don't add slideshow, if device/agent is mobile
  if (_gsb_public_custom_blocks_isMobile()) {
    return;
  }
  // render slideshow
  $variables['hero_region']['slideshow'] = array();
  if (!empty($node->field_hero_region_options[$language][0]['value']) && $node->field_hero_region_options[$language][0]['value'] == 'slideshow') {
    // Assemble the slides
    $slides = array();
    foreach($node->field_slideshow_slides[$language] as $index => $data) {
      if (is_integer($index)) {
        if ($slide_info = field_collection_field_get_entity($data)) {
          $slides[] = theme('slideshow_slide', array('slide_info' => $slide_info));
        }
      }
    }
    $variables['hero_region']['slideshow'] = implode('',$slides);
  }
}

function _gsb_public_custom_blocks_isMobile() {
  return preg_match("/(android|avantgo|blackberry|bolt|boost|cricket|docomo|fone|hiptop|mini|mobi|palm|phone|pie|tablet|up\.browser|up\.link|webos|wos)/i", $_SERVER["HTTP_USER_AGENT"]);
}
