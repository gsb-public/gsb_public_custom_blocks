<?php

$plugin = array(
  'title' => t('CGRI: Form | Contact'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_salesform_cgriform_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

$form_markup = <<<HTML
<!-- ---------------------------------------------------------------------- -->
<!-- Add the following META element to your page HEAD   -->   
<!-- If necessary, please modify the charset parameter to specify the  -->     
<!-- character set of your HTML page.                                 -->      
<!-- ------------------------------------------------------------------- -->
<META HTTP-EQUIV="Content-type" CONTENT="text/html; charset=UTF-8">
<!-- ---------------------------------------------------------------------- -->
<!-- Add the following FORM element to your page.-->
<!-- ---------------------------------------------------------------------- -->
<form action="https://www.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST">
<input type=hidden name="oid" value="00D500000007AMA">
<input type=hidden name="retURL" value="http://www.gsb.stanford.edu/faculty-research/centers-initiatives/cgri/research/closer-look/subscribe/thank-you">
<!--  ----------------------------------------------------------------------  -->
<div class="form-item">
<label for="first_name">First Name<span class="form-required" title="This field is required.">*</span></label><br />
<input id="first_name" maxlength="40" name="first_name" size="20" type="text" /></div>
<div class="form-item">
<label for="last_name">Last Name<span class="form-required" title="This field is required.">*</span></label><br />
<input id="last_name" maxlength="80" name="last_name" size="20" type="text" /></div>
<div class="form-item">
<label for="email">Email<span class="form-required" title="This field is required.">*</span></label><br />
<input id="email" maxlength="80" name="email" size="20" type="text" /></div>
<div class="form-item">
<label for="company">Company</label><br />
<input id="company" maxlength="40" name="company" size="20" type="text" /></div>
<div class="form-item">
<label for="street">Address</label><br />
<input id="00N50000001aBOz" maxlength="150" name="00N50000001aBOz" size="20" type="text"/></div>
<div class="form-item">
<label for="city">City</label><br />
<input id="city" maxlength="40" name="city" size="20" type="text" /></div>
<div class="form-item">
<label for="state">State/Province</label><br />
<input id="state" maxlength="20" name="state" size="20" type="text" /></div>
<div class="form-item">
<label for="zip">ZIP Code</label>
<input id="zip" maxlength="20" name="zip" size="20" type="text" /></div>
<div class="form-item">
<label for="country">Country</label><br />
<input id="country" maxlength="40" name="country" size="20" type="text" /></div>
<div class="form-item">
<p><input id="00N500000032wY2" name="00N500000032wY2" type="checkbox" value="1" />&nbsp;I am a journalist or in media relations.</p>
<input type="hidden" id="cgri_email_list__c" name="cgri_email_list__c" value=“True” />
<input type="hidden" id="00N500000032wXn" name="00N500000032wXn" type="checkbox" value="1" />
<input type="hidden" id="lead_source" name="lead_source" value="CGRI" />
<input type="hidden" id="status" name="status" value="Open - Not Contacted" />​</div>
<div class="form-item"><input type="submit" name="submit"></div>
</form>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );
}
