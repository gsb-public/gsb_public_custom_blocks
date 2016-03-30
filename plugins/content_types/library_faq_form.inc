<?php

$plugin = array(
  'title' => t('Library: Search | FAQ'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_faq_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'title' => 'Business Research FAQ',
    'content' => array(
    '#markup' => '<div id="tab_1_contents" class="tab_contents">
    <div class="search_text">Find tips on using research resources, as well as features and services of the business library. </div>
      <div class="search_form">
        <form method="get" target="_blank" name="searchForm">
          <input id="s" class="hidden" name="svalue" maxlength="128" value="" size="30" type="text" placeholder="Search for topic" />
          <input class="submit" align="absmiddle" value="Search" width="22" height="17" type="submit" />
        </form>
      </div>
    </div>
    <script>
      var searchForm = jQuery.find("[name=' . "'searchForm'" . ']");
      var searchValue = jQuery.find("[name=' . "'svalue'" . ']");
      jQuery(searchForm).on("submit", function (event) {
        event.preventDefault();
        event.stopImmediatePropagation()
        window.open("https://businessfaq.stanford.edu/search/node/" + jQuery(searchValue).val(), "_blank");
      });
    </script>
    ',
    ),
  );
}
