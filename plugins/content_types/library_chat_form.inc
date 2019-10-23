<?php

$plugin = array(
  'title' => t('Library: Chat'),
  'category' => t('Custom Content & Features'),
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
     <div jid="gsb-library@chat.libraryh3lp.com" class="libraryh3lp"><!--Type here to chat, M-F 9am-5pm FT. Press ENTER to send.--><iframe frameborder="0" title="Embedded Chat Box" style="width: 300px; height: 350px; border: 1px ;" src="https://us.libraryh3lp.com/chat/gsb-library@chat.libraryh3lp.com?skin=15904&identity=Librarian"></iframe>
    </div>
    <div class="helptext"><strong>Or Text Us</strong>: +1 (650) 204-8111</div>
    </div>
    <div class="libraryh3lp" style="display: none;">
    PUT YOUR OFFLINE OPTION HERE by inserting whatever HTML you want.
    You might point to your e-mail ref service or to your 24/7 backup chat
    service.
    </div>
    <!-- This div handles when the queue is busy or away. -->
<div class="libraryh3lp" style="display: none;" id="not-available">
Sorry, were busy helping someone else or stepped away for a moment.  We will be back soon.  <br />
<img alt="we are away" src="http://docs.libraryh3lp.com/images/away-busy-bubbles.png" />
</div>
    <!-- Place this script as near to the end of your BODY as possible.
    <script type="text/javascript">
    (function() {
    var x = document.createElement("script"); x.type = "text/javascript"; x.async = true;
    x.src = (document.location.protocol === "https:" ? "https://" : "http://") + "libraryh3lp.com/js/libraryh3lp.js?multi";
    var y = document.getElementsByTagName("script")[0]; y.parentNode.insertBefore(x, y);
    })();
    </script>-->
    ',
    ),
  );
}
