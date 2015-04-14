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
<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: Please add the following <META> element to your page <HEAD>.      -->
<!--  If necessary, please modify the charset parameter to specify the        -->
<!--  character set of your HTML page.                                        -->
<!--  ----------------------------------------------------------------------  -->
<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: Please add the following <FORM> element to your page.             -->
<!--  ----------------------------------------------------------------------  -->
<form action="https://www.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST">
<input type=hidden name="oid" value="00D500000007AMA">
<input type=hidden name="retURL" value="http://www.gsb.stanford.edu/faculty-research/centers-initiatives/cgri/research/closer-look/subscribe/thank-you">
<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: These fields are optional debugging elements. Please uncomment    -->
<!--  these lines if you wish to test in debug mode.                          -->
<!--  <input type="hidden" name="debug" value=1>                              -->
<!--  <input type="hidden" name="debugEmail" value="marlen@stanford.edu">     -->
<!--  ----------------------------------------------------------------------  -->
<label for="first_name">First Name</label><input  id="first_name" maxlength="40" name="first_name" size="20" type="text" /><br><br>
<label for="last_name">Last Name</label><input  id="last_name" maxlength="80" name="last_name" size="20" type="text" /><br><br>
<label for="00N50000002InQ">Organization Relationship</label><input  id="00N50000002InQg" maxlength="100" name="00N50000002InQg" size="20" type="text" /><br><br>
<label for="email">Email</label><input  id="email" maxlength="80" name="email" size="20" type="text" /><br><br>
<label for="street">Address</label><textarea name="street"></textarea><br><br>
<input  id="00N500000032wY2" name="00N500000032wY2" type="checkbox" value="1" /> Journalist/Media<br><br>
<label for="lead_source">Lead Source</label>
<select  id="lead_source" name="lead_source"><option value="">--None--</option><option value="ACT Interest Form">ACT Interest Form</option>
<option value="Board Fellows Interest Form">Board Fellows Interest Form</option>
<option value="CGRI">CGRI</option>
<option value="CSI">CSI</option>
<option value="GIPR - Inquiry Form">GIPR - Inquiry Form</option>
<option value="GIPR - Summit Registration">GIPR - Summit Registration</option>
<option value="Impact Labs Application">Impact Labs Application</option>
<option value="Online inquiry">Online inquiry</option>
<option value="Online registration">Online registration</option>
<option value="Online subscription">Online subscription</option>
<option value="Podcast List">Podcast List</option>
<option value="SEED">SEED</option>
<option value="VCII">VCII</option>
<option value="Other">Other</option>
</select><br><br>
<input type="submit" name="submit">
</form>
HTML;

  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );
}
