<?php

$plugin = array(
  'title' => t('Library: Search | Stanford Databases'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_searchworks_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'title' => "SearchWorks",
    'content' => array(
    '#markup' =>
      '<div id="tab_1_contents" class="tab_contents">
          <div class="search_text">Find books, journals, videos, and more in Stanford libraries. </div>
          <div class="search_form">
            <form target="_blank" title="Search form" method="get" action="https://searchworks.stanford.edu/?qt=search&amp;per_page=20&amp;q=">
              <div id="edit-search-wrapper">
                <input id="q" class="searchworks-search" name="q" size="50" type="text" placeholder="Search by title, author, or keyword" />
              </div>
              <input id="hidden_search_field" name="hidden_search_field" value="Search" type="hidden" />
           <!--   <input id="hidden_search_field" name="hidden_search_field" value="Search" type="hidden" />-->
              <input class="submit" align="absmiddle" value="Search" width="22" height="17" type="submit" />
            </form>
          </div>
      </div>',
    ),
  );
}
