<?php

$plugin = array(
  'title' => t('Library contact form'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_library_contact_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'content' => array(
    '#markup' => '<form name="f1" action="https://www.salesforce.com/servlet/servlet.WebToCase?encoding=UTF-8" method="POST" onsubmit="javascript: return required();">
<input name="orgid" value="00D500000007AMA" type="hidden">
<input name="retURL" value="http://www.gsb.stanford.edu/library/thank-you-library" type="hidden">
<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: These fields are optional debugging elements.  Please uncomment   -->
<!--  these lines if you wish to test in debug mode.                          -->
<!--  <input type="hidden" name="debug" value=1>                              -->
<!--  <input type="hidden" name="debugEmail" value="vamsit@uniseva.com">      -->
<!--  ----------------------------------------------------------------------  -->
<table>
<tbody><tr>
<td>
Your Name<span>*</span>:
</td>
<td>
<input id="00N50000002L6KR" maxlength="50" name="00N50000002L6KR" size="20" type="text" keyev="true">
</td>
</tr><tr>
<td>Email<span>*</span>:
</td>
<td>
<input id="email" maxlength="80" name="email" size="20" type="text">
</td>
</tr>
<tr>
<td>Affiliation:<span>*</span>:
</td>
<td>
<select id="Select1" name="00N50000002L6KS" title="Requestor affiliation">
<option value="">--None--</option>
<option value="MBA1">MBA1</option>
<option value="MBA2">MBA2</option>
<option value="GSB PhD Student">GSB PhD Student</option>
<option value="GSB Sloan Student">GSB Sloan Student</option>
<option value="GSB Student - Other">GSB Student - Other</option>
<option value="GSB Faculty">GSB Faculty</option>
<option value="GSB Staff">GSB Staff</option>
<option value="GSB Alumni">GSB Alumni</option>
<option value="Stanford Faculty">Stanford Faculty</option>
<option value="Stanford Student">Stanford Student</option>
<option value="Stanford Staff">Stanford Staff</option>
<option value="Other">Other</option>
</select>
</td>
</tr>
<tr>
<td>
Type of Request<span>*</span>:
</td>
<td>
<select id="00N50000002L6KP" name="00N50000002L6KP" title="Request Type">
<option selected="selected" value="">--None--</option>
<option value="Ask Us">Research Assistance</option>        
<option value="Suggestions">Feedback & Suggestions</option>
<option value="Resource Request">Suggest a Purchase</option>
<option value="Ask Us">Other</option>
</select>
</td>
</tr>
<tr>
<td>
Request<span>*</span>:</td>
</tr>
<tr>
<td colspan="2">
<textarea id="00N50000002L6KQ" name="00N50000002L6KQ" type="text" wrap="soft" rows="1"></textarea><br>
</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td colspan="2">
<input id="randomfield" disabled="disabled" maxlength="8" name="randomfield" value="p4c6n" type="text">
<br>
Type the above code below<br>
<input id="txtCaptcha" maxlength="5" name="txtCaptcha" type="text">
</td>
</tr>
<tr>
<td align="right">
</td>
<td><input name="submit" onclick="javascript: return required();" value="Submit" type="submit">
<input name="submit" onclick="javascript: return Clear();" value="Clear" type="submit">
</td>
</tr>
</tbody></table>
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
document.f1.elements["00N50000002L6KR"].value="";
document.f1.elements["email"].value="";
document.f1.elements["00N50000002L6KS"].value="";
document.f1.elements["00N50000002L6KQ"].value="";
document.f1.elements["txtCaptcha"].value = "";
document.f1.elements["00N50000002L6KP"].value = "";
return false;
}
function required()
{
var reqName = document.f1.elements["00N50000002L6KR"].value;
var reqEmail = document.f1.elements["email"].value;
var affiliation = document.f1.elements["00N50000002L6KS"].value;
var request=document.f1.elements["00N50000002L6KQ"].value;
var type=document.f1.elements["00N50000002L6KP"].value;

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
</form>',
    ),
  );
}