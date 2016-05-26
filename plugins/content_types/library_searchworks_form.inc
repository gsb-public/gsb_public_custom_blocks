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
    'title' => "Search Stanford’s Libraries",
    'content' => array(
    '#markup' =>
      '<div id="tabbed_box_1" class="tabbed_box">
        <div class="tabbed_area">
          <ul class="searchworks-tabs">
            <li><a href=javascript:tabSwitch("tab_1","content_1"); id="tab_1" class="active">SearchWorks</a></li>
            <li><a href=javascript:tabSwitch("tab_2","content_2"); id="tab_2">eJournals</a></li>
          </ul>
          <div id="content_1" class="searchworks-content">
            <form target="_blank" title="Search form" method="get" action="http://searchworks.stanford.edu/?qt=search&amp;per_page=20&amp;q=">
              <div id="edit-search-wrapper">
                <input id="q" class="searchworks-search" name="q" size="50" type="text" placeholder="Search by title, author, or keyword" />
              </div>
              <input id="hidden_search_field" name="hidden_search_field" value="Search" type="hidden" />
              <input id="hidden_search_field" name="hidden_search_field" value="Search" type="hidden" />
              <input class="submit" value="Search" type="submit" />
            </form>
          </div>
          <div id="content_2" class="searchworks-content">
            <form target="_blank" method="get" name="SS_EJPSearchForm" action="http://sul-sfx.stanford.edu/sfxlcl41/az" onsubmit="doSubmit();">
              <input name="V" value="1.0" type="hidden" />
              <input name="N" value="100" type="hidden" />
              <input name="L" value="TC8VW9NW8J" type="hidden" />
              <select name="param_textSearchType_value" id="param_textSearchType_value" class="searchworks-select">
                <option value="startsWith">Title begins with</option>
                <option value="exactMatch">Title equals</option>
                <option selected="selected" value="contains">Title contains all words</option>
                <option value="issn">ISSN equals</option>
              </select>
              <div id="edit-search-wrapper" class="searchworks-ejournal">
                <input type="text" name="param_pattern_value" size="24" placeholder="Search by title, or keyword" value="" id="param_pattern_value">
              </div>
              <input class="submit" value="Search" type="submit" />
              <input name="param_issn_value" value="" id="param_issn_value" type="hidden">
              <input name="param_perform_value" value="locate" id="param_perform_value" type="hidden">
            </form>
          </div>
        </div>
        <script>
          function doSubmit() {
            setISSNValue();
          }
          function setISSNValue() {
            var selectedValue = document.getElementById("param_textSearchType_value").value;
            if (selectedValue == "issn") {
              var searchValue = document.getElementById("param_pattern_value").value;
              document.getElementById("param_issn_value").value = searchValue;
              document.getElementById("param_pattern_value").value = "";
            }
            else {
              document.getElementById("param_issn_value").value = "";
            }
          }
          function tabSwitch(new_tab, new_content) {
            document.getElementById("content_1").style.display = "none";
            document.getElementById("content_2").style.display = "none";
            document.getElementById(new_content).style.display = "block";
            document.getElementById("tab_1").className = "";
            document.getElementById("tab_2").className = "";
            document.getElementById(new_tab).className = "active";
          }
        </script>
      </div>',
    ),
  );
}
