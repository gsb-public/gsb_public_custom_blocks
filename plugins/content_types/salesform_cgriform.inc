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

<!-- ---------------------------------------------------------------------  -->
<!-- Add the following META element to your page HEAD           -->
<!-- If necessary, please modify the charset parameter to specify the   -->
<!-- character set of your HTML page.                   -->
<!-- -------------------------------------------------------------------  -->

<!-- Add the following FORM element to your page.-->
<!-- ---------------------------------------------------------------------  -->

  <form name="f1" action="https://www.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST"  onSubmit="javascript: return required();">
  <form action="https://www.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST">
    <input type=hidden name="oid" value="00D500000007AMA">
    <input type=hidden name="retURL" value="http://www.gsb.stanford.edu/faculty-research/centers-initiatives/cgri/research/closer-look/subscribe/thank-you">
    <input type="hidden" id="00N500000032wXn" name="00N500000032wXn" type="checkbox" value="1" />
    <input type="hidden" id="lead_source" name="lead_source" value="CGRI" />
    <input type="hidden" id="cgri_email_list__c" name="cgri_email_list__c" value=“True” />
    <input type="hidden" id="status" name="status" value="Open - Not Contacted" />
    <input type="hidden" id="owner" name="owner" value=“mgutman” />

<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: These fields are optional debugging elements. Please uncomment    -->
<!--  these lines if you wish to test in debug mode.                          -->
<!--  <input type="hidden" name="debug" value=1>                              -->
<!--  <input type="hidden" name="debugEmail" value="marlen@stanford.edu">     -->
<!--  ----------------------------------------------------------------------  -->

  <div class="form-item">
    <label for="salutation">Salutation</label>
    <select id="salutation" name="salutation">
      <option value="">--None--</option>
      <option value="Admiral">Admiral</option>
      <option value="Ambassador">Ambassador</option>
      <option value="Baron">Baron</option>
      <option value="Brigadier General">Brigadier General</option>
      <option value="Brother">Brother</option>
      <option value="Captain">Captain</option>
      <option value="Captain (Ret.)">Captain (Ret.)</option>
      <option value="Colonel">Colonel</option>
      <option value="Colonel (Ret.)">Colonel (Ret.)</option>
      <option value="Commander">Commander</option>
      <option value="Commander (Ret.)">Commander (Ret.)</option>
      <option value="Count">Count</option>
      <option value="Dean">Dean</option>
      <option value="Dr.">Dr.</option>
      <option value="Father">Father</option>
      <option value="General">General</option>
      <option value="Ingeniero">Ingeniero</option>
      <option value="Judge">Judge</option>
      <option value="Justice">Justice</option>
      <option value="Lieutenant">Lieutenant</option>
      <option value="Lieutenant Colonel">Lieutenant Colonel</option>
      <option value="Lieutenant Commander">Lieutenant Commander</option>
      <option value="Lieutenant General">Lieutenant General</option>
      <option value="Lord">Lord</option>
      <option value="Major">Major</option>
      <option value="Major General">Major General</option>
      <option value="Miss">Miss</option>
      <option value="Mr/s.">Mr/s.</option>
      <option value="Mr.">Mr.</option>
      <option value="Mrs.">Mrs.</option>
      <option value="Ms.">Ms.</option>
      <option value="Pastor">Pastor</option>
      <option value="President">President</option>
      <option value="Professor">Professor</option>
      <option value="Professor Emeritus">Professor Emeritus</option>
      <option value="Rear Admiral">Rear Admiral</option>
      <option value="Sir">Sir</option>
      <option value="The Honorable">The Honorable</option>
      <option value="The Reverend">The Reverend</option>
      <option value="Marquis">Marquis</option>
      <option value="Ing.">Ing.</option>
      <option value="Senator">Senator</option>
      <option value="Minister of Employment">Minister of Employment</option>
      <option value="His Excellency">His Excellency</option>
      <option value="T.H.">T.H.</option>
    </select>
  </div>
  <div class="form-item">
    <label for="first_name">First Name<span class="form-required" title="This field is required.">*</span></label>
    <input id="first_name" maxlength="40" name="first_name" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="last_name">Last Name<span class="form-required" title="This field is required.">*</span></label>
    <input id="last_name" maxlength="80" name="last_name" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="email">Email</label><span class="form-required" title="This field is required.">*</span>
    <input id="email" maxlength="80" name="email" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="title">Title</label>
    <input id="title" maxlength="40" name="title" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="company">Company/Organization</label>
    <input id="company" maxlength="40" name="company" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="cgri_affiliation">Affiliation<span class="form-required" title="This field is required.">*</span></label>
    <select id="00N500000033Evx" name="00N500000033Evx" title="CGRI Affiliation">
      <option value="">--None--</option>
      <option value="Academia">Academia</option>
      <option value="Business">Business</option>
      <option value="Law">Law</option>
      <option value="Media">Media</option>
      <option value="Other">Other</option>
    </select>
  </div>
  <div class="form-item">
    <label for="street">Street Address</label>
    <input id="00N50000001aBOz" maxlength="150" name="00N50000001aBOz" size="20" type="text" /></div>
  </div>
  <div class="form-item">
    <label for="city">City</label>
    <input id="00N50000001aC6f" maxlength="40" name="00N50000001aC6f" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="state">State/Province</label>
    <input id="00N50000001aC6g" maxlength="20" name="00N50000001aC6g" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="zip">ZIP Code</label>
    <input id="00N50000001aC6k" maxlength="20" name="00N50000001aC6k" size="20" type="text" />
  </div>
  <div class="form-item">
    <label for="country">Country</label>
    <input id="00N50000001aC79" maxlength="40" name="00N50000001aC79" size="20" type="text" />
  </div>
  <div class="form-actions form-wrapper" id="edit-actions">
    <input type="submit" name="submit" class="form-submit">
  </div>
</form>
<script type="text/javascript">
function required() {
var reqfName = document.f1.elements["first_name"].value;
var reqlName = document.f1.elements["last_name"].value;
var reqEmail = document.f1.elements["email"].value;
if (reqfName == "" || reqlName == "" || reqEmail == "") {
alert("Please fill in all of the mandatory fields (denoted by *)");
return false;}}
</script>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );
}
