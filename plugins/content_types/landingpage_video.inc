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

  $entityId = "0_pl30xzcu"; // 0_lold7yx2 and 0_pl30xzcu

$content = <<<EOF
  <div style="width: 100%;display: inline-block;position: relative;"> 
    <div id="dummy" style="margin-top: 56.25%;"></div>
    <div id="kaltura-player1" style="position:absolute;top:0;left:0;left: 0;right: 0;bottom:-36px;border:solid thin black;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
    </div>
  </div>
  <script>
    kWidget.embed({
      'targetId': 'kaltura-player1',
      'wid': '_2063281',
      'uiconf_id' : '43211942',
      'entry_id' : '<entity-goes-here>',
      'autoplay' : true,
      'automute' : true,
      'uiVars': [{
        'autoplay' : true,
        'loop' : true,
        'automute' : true
      }],
      'flashvars' : {
        'autoMute' : true,
        'autoPlay' : true,
        'inlineScript' : false,			
        'loop' : true
      },
    });
  </script>
EOF;

  $content = str_replace("<entity-goes-here>", $entityId, $content);

  return (object) array(
    'content' => array(
      '#attached' => array(
        'js' => array(
          '//cdnapisec.kaltura.com/p/243342/sp/24334200/embedIframeJs/uiconf_id/43211942/partner_id/2063281/entry_id/' . $entityId . '?entry_id=' . $entityId =>
          array(
            'type' => 'external',
          ),
        ),
      ),
      '#markup' => $content,
    ),
  );
}
