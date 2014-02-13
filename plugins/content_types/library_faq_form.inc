<?php

$plugin = array(
  'title' => t('Library: How do I find?'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_faq_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'title' => 'How do I find...?',
    'content' => array(
    '#markup' => '<div id="tab_1_contents" class="tab_contents">
    <div class="search_text">Enter subjects or categories to find tips and guidance on using research resources. </div>
    <div class="search_form">
    <form method="get" target="_blank" action="http://www.stanford.edu/group/gsblibrary/cgi-bin/faq/"><input id="s" class="hidden" name="s" maxlength="128" value="" size="30" type="text" placeholder="Search for topic" /> <input class="submit" align="absmiddle" value="Search" width="22" height="17" type="submit" /></form></div></div>',
    ),
  );
}
