<?php

$plugin = array(
  'title' => t('Library: Chat With Us?'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_chat_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'title' => 'Chat With Us',
    'content' => array(
    '#markup' => '<div class="aConBox">
     <div jid="gsb-library@chat.libraryh3lp.com" class="libraryh3lp">Type here to chat, M-F 9am-5pm FT. Press ENTER to send.<iframe frameborder="0" style="width: 300px; height: 350px; border: 1px ;" src="https://libraryh3lp.com/chat/gsb-library@chat.libraryh3lp.com?skin=17350&amp;identity=Librarian"></iframe><br/>
    </div>
    <p align="left">Or text us at +1 (650) 204 8111</p>
    </div>
	<div class="libraryh3lp" style="display: none;">
  PUT YOUR OFFLINE OPTION HERE by inserting whatever HTML you want.
  You might point to your e-mail ref service or to your 24/7 backup chat
  service.
</div><!-- Place this script as near to the end of your BODY as possible. -->
<script 
 type="text/javascript"> 
  (function() {
    var x = document.createElement("script"); x.type = "text/javascript"; x.async = true;
    x.src = (document.location.protocol === "https:" ? "https://" : "http://") + "libraryh3lp.com/js/libraryh3lp.js?multi,poll";
    var y = document.getElementsByTagName("script")[0]; y.parentNode.insertBefore(x, y);
  })();
</script>
    ',
    ),
  );
}
