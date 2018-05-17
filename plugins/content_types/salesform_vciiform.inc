<?php

$plugin = array(
  'title' => t('VCII: Form | Subscribe'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_salesform_vciiform_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

$form_markup = <<<HTML

<!-- ---------------------------------------------------------------------- -->
<!-- NOTE: Please add the following <META> element to your page <HEAD>. -->
<!-- If necessary, please modify the charset parameter to specify the -->
<!-- character set of your HTML page. -->
<!-- ---------------------------------------------------------------------- -->

<META HTTP-EQUIV="Content-type" CONTENT="text/html; charset=UTF-8">

<!-- ---------------------------------------------------------------------- -->
<!-- NOTE: Please add the following <FORM> element to your page. -->
<!-- ---------------------------------------------------------------------- -->

<form action="https://webto.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST">

<input type=hidden name="oid" value="00D500000007AMA">
<input type=hidden name="retURL" value="https://www.gsb.stanford.edu/faculty-research/centers-initiatives/vcii/contact/subscribe/thank-you">
  
<!-- ---------------------------------------------------------------------- -->
<!-- NOTE: These fields are optional debugging elements. Please uncomment -->
<!-- these lines if you wish to test in debug mode. -->
<!-- <input type="hidden" name="debug" value=1> -->
<!-- <input type="hidden" name="debugEmail" value="matper@stanford.edu"> -->
<!-- ---------------------------------------------------------------------- -->

<div class="form-item webform-component webform-component-textfield">
<label for="first_name">First Name</label>
<input id="first_name" maxlength="40" name="first_name" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-textfield">
<label for="last_name">Last Name</label>
<input id="last_name" maxlength="80" name="last_name" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-email">
<label for="email">Email</label>
<input class="email form-text form-email" id="email" maxlength="80" name="email" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-textfield">
<label for="company">Company</label>
<input id="company" maxlength="40" name="company" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-textfield">
<label for="title">Title</label>
<input id="title" maxlength="40" name="title" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-textfield">
<label for="zip">ZIP Code</label>
<input id="zip" maxlength="20" name="zip" size="20" type="text" />
</div>

<div class="form-item webform-component webform-component-textfield">
<label for="country">Country</label>
<input id="country" maxlength="40" name="country" size="20" type="text" />
</div>

<div class="class="form-actions form-item">
<input class="webform-submit button-primary form-submit" type="submit" name="submit">
</div>

</form>

HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );
}
