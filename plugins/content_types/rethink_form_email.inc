<?php

$plugin = array(
  'title' => t('Insights: Form | Email Subscription'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_rethink_form_email_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

$form = <<<HTML
<div id="mc_embed_signup">
<form action="https://stanford.us5.list-manage.com/subscribe/post?u=ce785d9b9016cd35fb68e83b7&id=0b5214e34b" method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate>
<div class="indicates-required"><span class="asterisk">*</span> indicates required</div>
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
<div class="clear"><input type="submit" value="Subscribe" name="subscribe" id="mc-embedded-subscribe" class="button"></div>
</form>
</div>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form,
    ),
  );

}
