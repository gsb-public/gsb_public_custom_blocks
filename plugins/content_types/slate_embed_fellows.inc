<?php

$plugin = array(
  'title' => t('Research Fellows Inquiry | Slate form'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_slate_embed_fellows_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'title' => '',
    'content' => array(
      '#markup' => '<div id="form_6ec11bc6-f1eb-4b78-9b4e-d28a26abb720">Loading...</div><script async="async" src="https://gsbslate.stanford.edu/register/?id=6ec11bc6-f1eb-4b78-9b4e-d28a26abb720&amp;output=embed&amp;div=form_6ec11bc6-f1eb-4b78-9b4e-d28a26abb720">/**/</script>',
    ),
  );
}
