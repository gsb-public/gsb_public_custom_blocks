<?php

$plugin = array(
  'title' => t('ReThink form: Email Only'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_rethink_form_email_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

$form = <<<HTML
<!-- Begin MailChimp Signup Form
<link href="//cdn-images.mailchimp.com/embedcode/classic-081711.css" rel="stylesheet" type="text/css">
<style type="text/css">
#mc_embed_signup
{background:#fff; clear:left; font:14px Helvetica,Arial,sans-serif; }
/* Add your own MailChimp form style overrides in your site stylesheet or in this style block.
We recommend moving this block and the preceding CSS link to the HEAD of your HTML file. */
</style> -->
<div id="mc_embed_signup">
<form action="http://stanford.us5.list-manage1.com/subscribe/post?u=ce785d9b9016cd35fb68e83b7&id=0b5214e34b" method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate>
<div class="mc-field-group">
<label for="mce-EMAIL">Email Address <span class="asterisk">*</span>
</label>
<input type="email" value="" name="EMAIL" class="required email" id="mce-EMAIL">
</div>
<div id="mce-responses" class="clear">
<div class="response" id="mce-error-response" style="display:none"></div>
<div class="response" id="mce-success-response" style="display:none"></div>
</div> <!-- real people should not fill this in and expect good things - do not remove this or risk form bot signups-->
<div style="position: absolute; left: -5000px;"><input type="text" name="b_ce785d9b9016cd35fb68e83b7_0b5214e34b" tabindex="-1" value=""></div>
<div class="clear"><input type="submit" value="Subscribe Now" name="subscribe" id="mc-embedded-subscribe" class="button"></div>
</form>
</div>
<!-- End mc_embed_signup -->
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form,
    ),
  );

}
