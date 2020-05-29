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
<div class="pane-content">
<!-- ---------------------------------------------------------------------  -->
<!-- Add the following META element to your page HEAD           -->
<!-- If necessary, please modify the charset parameter to specify the   -->
<!-- character set of your HTML page.                   -->
<!-- -------------------------------------------------------------------  -->
<!-- Add the following FORM element to your page.-->
<!-- ---------------------------------------------------------------------  -->
<script src="https://www.google.com/recaptcha/api.js"></script>
<script>
 function timestamp() { var response = document.getElementById("g-recaptcha-response"); if (response == null || response.value.trim() == "") {var elems = JSON.parse(document.getElementsByName("captcha_settings")[0].value);elems["ts"] = JSON.stringify(new Date().getTime());document.getElementsByName("captcha_settings")[0].value = JSON.stringify(elems); } } setInterval(timestamp, 500);
</script>

  <form name="f1" action="https://test.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST" onsubmit="javascript: return required();">
    <input type=hidden name='captcha_settings' value='{"keyname":"GSB_Public_Site","fallback":"true","orgId":"00D3J0000008aOs","ts":""}'>
    <input type="hidden" name="oid" value="00D3J0000008aOs">
    <input type="hidden" name="retURL" value="http://public2-stage.gsb.stanford.edu/faculty-research/centers-initiatives/cgri/research/closer-look/subscribe/thank-you">
    <input type="hidden" id="00N500000032wXn" name="00N500000032wXn" value="1">
    <input type="hidden" id="lead_source" name="lead_source" value="CGRI">
    <input type="hidden" id="00N5000000336R1" name="00N5000000336R1" title="All Lead Sources" value="GIPR - Inquiry Form">
    <input type="hidden" id="cgri_email_list__c" name="cgri_email_list__c" value="“True”">
    <input type="hidden" id="status" name="status" value="Open - Not Contacted">
    <input type="hidden" id="owner" name="owner" value="“mgutman”">

<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: These fields are optional debugging elements. Please uncomment    -->
<!--  these lines if you wish to test in debug mode.                          -->
<!--  <input type="hidden" name="debug" value=1>                              -->
<!--  <input type="hidden" name="debugEmail" value="marlen@stanford.edu">     -->
<!--  ----------------------------------------------------------------------  -->

  <div class="form-item">
    <label for="salutation">Salutation</label>
    <select id="salutation" name="salutation" class="hasCustomSelect" style="-webkit-appearance: menulist-button; width: 111px; position: absolute; opacity: 0; height: 38px; font-size: 14px;">
      <option value="">--None--</option>
      <option value="Dr.">Dr.</option>
      <option value="Mr.">Mr.</option>
      <option value="Mrs.">Mrs.</option>
      <option value="Ms.">Ms.</option>
      <option value="Professor">Professor</option>
    </select><span class="customSelect" style="display: inline-block;"><span class="customSelectInner" style="width: 82px; display: inline-block;">--None--</span></span>
  </div>
  <div class="form-item">
    <label for="first_name">First Name<span class="form-required" title="This field is required.">*</span></label>
    <input id="first_name" maxlength="40" name="first_name" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="last_name">Last Name<span class="form-required" title="This field is required.">*</span></label>
    <input id="last_name" maxlength="80" name="last_name" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="email">Email<span class="form-required" title="This field is required.">*</span></label>
    <input id="email" maxlength="80" name="email" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="cgri_affiliation">Affiliation<span class="form-required" title="This field is required.">*</span></label>
    <select id="00N500000033Evx" name="00N500000033Evx" title="CGRI Affiliation" class="hasCustomSelect" style="-webkit-appearance: menulist-button; width: 117px; position: absolute; opacity: 0; height: 38px; font-size: 14px;">
      <option value="">--None--</option>
      <option value="Academia">Academia</option>
      <option value="Business">Business</option>
      <option value="Law">Law</option>
      <option value="Media">Media</option>
      <option value="Other">Other</option>
    </select><span class="customSelect" style="display: inline-block;"><span class="customSelectInner" style="width: 88px; display: inline-block;">--None--</span></span>
  </div>
  <div class="form-item">
    <input id="00N38000003f042" name="00N38000003f042" type="checkbox" value="1">&nbsp;I am a Stanford alumnus/a.
  </div>
  <div class="form-item">
    <label for="sunetid">Stanford Username (<a href="https://alumni-gsb.stanford.edu/get/page/forgot-username?pg=no=&amp;nu=https%3A**alumni.stanford.edu" target="_blank">forgot username</a>)</label>
    <input id="00N38000003f047" maxlength="100" name="00N38000003f047" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="title">Title</label>
    <input id="title" maxlength="40" name="title" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="company">Company/Organization</label>
    <input id="company" maxlength="40" name="company" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="street">Street Address</label>
    <input id="00N50000001aBOz" maxlength="150" name="00N50000001aBOz" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="city">City</label>
    <input id="00N50000001aC6f" maxlength="40" name="00N50000001aC6f" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="state">State/Province</label>
    <input id="00N50000001aC6g" maxlength="20" name="00N50000001aC6g" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="zip">ZIP Code</label>
    <input id="00N50000001aC6k" maxlength="20" name="00N50000001aC6k" size="20" type="text">
  </div>
  <div class="form-item">
    <label for="country">Country</label>
    <input id="00N50000001aC79" maxlength="40" name="00N50000001aC79" size="20" type="text">
  </div>
  <div class="form-item">
    <div class="g-recaptcha" data-sitekey="6Lf3zv0UAAAAAK-aHnnwevBvhwcGPruDMG9F4V3-" data-callback="reCaptchaResponse"></div>
  </div>
  <div class="form-actions form-wrapper" id="edit-actions">
    <input type="submit" name="submit" class="form-submit">
  </div>
</form>
<script type="text/javascript">
var isValid;
var reCaptchaResponse = function(response) {
isValid = response.replace(/\s+/g, '');
};
function required() {
var reqfName = document.f1.elements["first_name"].value;
var reqlName = document.f1.elements["last_name"].value;
var reqEmail = document.f1.elements["email"].value;
if (reqfName == "" || reqlName == "" || reqEmail == "") {
alert("Please fill in all of the mandatory fields (denoted by *)");
return false;}
if (typeof isValid === 'undefined' || isValid === '') {
alert("Correct captcha is required");
return false;
}}
</script>
</div>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );
}

