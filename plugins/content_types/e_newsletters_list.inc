<?php

$plugin = array(
  'title' => t('ReThink form: e-newsletters'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_e_newsletters_list_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

$form = <<<HTML

<h2>Archive</h2>
<script language="javascript" src="http://us5.campaign-archive1.com/generate-js/?u=ce785d9b9016cd35fb68e83b7&fid=3777&show=5" type="text/javascript"></script>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form,
    ),
  );

}
