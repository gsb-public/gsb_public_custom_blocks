<?php

$plugin = array(
  'title' => t('Landing Page Video'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_landingpage_video_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

  $landingPageVideo = variable_get('landingPageVideo', '/sites/gsb/files/landingpage.mp4');

  $content = <<<EOF
<video class="splash__video__media" autoplay muted loop playsinline>
  <source src="<landing-page-video-file-path-goes-here>" type="video/mp4">
</video>
EOF;

  $content = str_replace("<landing-page-video-file-path-goes-here>", $landingPageVideo, $content);

  return (object) array(
    'content' => array(
      '#markup' => $content
    ),
  );
}
