<?php

$plugin = array(
  'title' => t('Library: Form | Contact'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_contact_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

	$form_markup = '<form name="f1" action="https://webto.salesforce.com/servlet/servlet.WebToCase?encoding=UTF-8" method="POST" onsubmit="javascript: return required();">
	<input name="orgid" value="@@orgid " type="hidden">
	<input name="retURL" value="http://www.gsb.stanford.edu/library/contact/thank-you" type="hidden">
	<!--  ----------------------------------------------------------------------  -->
	<!--  NOTE: These fields are optional debugging elements.  Please uncomment   -->
	<!--  these lines if you wish to test in debug mode.                          -->
	<!--  <input type="hidden" name="debug" value=1>                              -->
	<!--  <input type="hidden" name="debugEmail" value="vamsit@uniseva.com">      -->
	<!--  ----------------------------------------------------------------------  -->
	<div><label for="fullname">Your Name<span>*</span></label>
	<input id="@@name" maxlength="50" name="@@name" size="34" type="text" keyev="true"><br/><br/>
	<label for="email">Email<span>*</span></label>
	<input id="email" maxlength="80" name="email" size="34" type="text"><br/><br/>
	<label for="affiliation">Affiliation<span>*</span></label>
	<select id="Select1" name="@@select" title="Requestor affiliation" style="width:286px">
	<option value="">--None--</option>
	<option value="MBA1">MBA 1</option>
	<option value="MBA2">MBA 2</option>
	<option value="GSB PhD Student">GSB PhD Student</option>
	<option value="GSB MSx Student">GSB MSx Student</option>
	<option value="GSB Student - Other">GSB Student - Other</option>
	<option value="GSB Faculty">GSB Faculty</option>
	<option value="GSB Staff">GSB Staff</option>
	<option value="GSB Alumni">GSB Alumni</option>
	<option value="Stanford Faculty">Stanford Faculty</option>
	<option value="Stanford Student">Stanford Student</option>
	<option value="Stanford Staff">Stanford Staff</option>
	<option value="Stanford Alumni">Stanford Alumni</option>
	<option value="Visiting Scholar">Visiting Scholar</option>
	<option value="Visitor">Visitor</option>
	</select><br/><br/>
	<label for="requesttype">Type of Request<span>*</span></label>
	<select id="@@requesttype" name="@@requesttype" title="Request Type" style="width:286px">
	<option selected="selected" value="">--None--</option>
	<option value="Ask Us">Research Assistance</option>
	<option value="Suggestions">Feedback & Suggestions</option>
	<option value="Suggest a Purchase">Suggest a Purchase</option>
	<option value="Ask Us">Other</option>
	</select><br/><br/>
	<label for="requesttype">Request<span>*</span></label>
	<textarea id="@@requesttext" name="@@requesttext" type="text" wrap="soft" rows="1"></textarea><br/><br/>
	<input id="randomfield" disabled="disabled" maxlength="8" name="randomfield" value="p4c6n" type="text"></br>
	<br>
	<label for="textCaptcha">Type the above code below<br></label>
	<input id="txtCaptcha" maxlength="5" name="txtCaptcha" type="text" class="captcha"><br/><br/>
	<input name="submit" onclick="javascript: return required();" value="Submit" type="submit">
	<input name="submit" onclick="javascript: return Clear();" value="Clear" type="submit">
	</div>
	<script type="text/javascript">
	window.onload = function randomString() {
	var chars = "0123456789abcdefghiklmnopqrstuvwxyz";
	var string_length = 5;
	var randomstring = "";
	for (var i = 0; i < string_length; i++) {
	var rnum = Math.floor(Math.random() * chars.length);
	randomstring += chars.substring(rnum, rnum + 1);
	}
	document.f1.elements["randomfield"].value = randomstring;
	}

	function Clear()
	{
	document.f1.elements["@@name"].value="";
	document.f1.elements["email"].value="";
	document.f1.elements["@@select"].value="";
	document.f1.elements["@@requesttext"].value="";
	document.f1.elements["txtCaptcha"].value = "";
	document.f1.elements["@@requesttype"].value = "";
	return false;
	}
	function required()
	{
	var reqName = document.f1.elements["@@name"].value;
	var reqEmail = document.f1.elements["email"].value;
	var affiliation = document.f1.elements["@@select"].value;
	var request=document.f1.elements["@@requesttext"].value;
	var type=document.f1.elements["@@requesttype"].value;

	if (reqName == "" || reqEmail == "" || affiliation == ""  || request=="" || type=="" ) {
	alert("Please fill in all of the mandatory fields (denoted by *)");
	return false;
	}
	else {
	var reg = /^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/;
	if (reqEmail == "") {
	if (document.f1.elements["randomfield"].value == document.f1.elements["txtCaptcha"].value) {
	document.myform.submit();
	}
	else {
	alert("Invalid Code");
	return false;
	}
	}
	else {
	if (reg.test(reqEmail) == false) {
	alert("Invalid Email Address");
	return false;
	}
	else {
	if (document.f1.elements["randomfield"].value == document.f1.elements["txtCaptcha"].value) {
	document.myform.submit();
	}
	else {
	alert("Invalid Code");
	return false;
	}
	}
	}
	}
	}
	</script>
	</form>';

	$library_contact_form_vars = variable_get('library_contact_form_vars','');

	$form_markup = str_replace("@@orgid", $library_contact_form_vars['@@orgid'], $form_markup);
	$form_markup = str_replace("@@name", $library_contact_form_vars['@@name'], $form_markup);
	$form_markup = str_replace("@@select", $library_contact_form_vars['@@select'], $form_markup);
	$form_markup = str_replace("@@requesttype", $library_contact_form_vars['@@requesttype'], $form_markup);
	$form_markup = str_replace("@@requesttext", $library_contact_form_vars['@@requesttext'], $form_markup);

    return (object) array(
    'content' => array(
    '#markup' => $form_markup,
    ),
  );
}