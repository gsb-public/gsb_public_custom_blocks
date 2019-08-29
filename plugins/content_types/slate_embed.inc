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
      '#markup' => '<div id="form_33a511e1-6411-4733-b550-125edba5f078">Loading...</div><script async="async" src="https://gsbslate.stanford.edu/register/?id=33a511e1-6411-4733-b550-125edba5f078&amp;output=embed&amp;div=form_33a511e1-6411-4733-b550-125edba5f078">/**/</script>',
    ),
  );
}
