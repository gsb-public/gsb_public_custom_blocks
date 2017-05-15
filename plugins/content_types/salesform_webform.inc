<?php

$plugin = array(
  'title' => t('Programs: Form | GIP Contact'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_salesform_webform_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

  $form_markup = '<form name="f1" action="https://webto.salesforce.com/servlet/servlet.WebToLead?encoding=UTF-8" method="POST" onSubmit="javascript: return required();">
<input type="hidden" name="oid" value="@@orgid">
<input type="hidden" name="retURL" value="http://www.gsb.stanford.edu/programs/thank-you-inquiry">
<input type="hidden" name="lead_source" value="GIPR - Inquiry Form" id="lead_source">
<input type="hidden" id="@@commitmentname" name="@@commitmentname" title="Commitment Name" value="GIPR Contact" />
<input type="hidden" id="@@commitmentrole" name="@@commitmentrole" title="Commitment Role" value="GIPR - Inquiry" />
<!--  ----------------------------------------------------------------------  -->
<!--  NOTE: These fields are optional debugging elements.  Please uncomment   -->
<!--  these lines if you wish to test in debug mode.                          -->
<!--  <input type="hidden" name="debug" value=1>                              -->
<!--  <input type="hidden" name="debugEmail" value="vamsit@uniseva.com">      -->
<!--  ----------------------------------------------------------------------  -->
<div><label for="first_name">First Name<span>*</span></label>
<input id="first_name" maxlength="40" name="first_name" size="34" type="text"><br/><br/>
<label for="last_name">Last Name<span>*</span></label>
<input id="last_name" maxlength="80" name="last_name" size="34" type="text"><br/><br/>
<label for="email">Email<span>*</span></label>
<input id="email" maxlength="80" name="email" size="34" type="text"><br/><br/>
<label for="country">Country<span>*</span></label>
<input id="country" style="display:none;" maxlength="80" name="country" type="text">
<select name="emma_member_country" id="emma_member_country" style="width:286px">
<option value=""></option>
<option value="United States">United States</option>
<option value="Afghanistan">Afghanistan</option>
<option value="Albania">Albania</option>
<option value="Algeria">Algeria</option>
<option value="American Samoa">American Samoa</option>
<option value="Andorra">Andorra</option>
<option value="Angola">Angola</option>
<option value="Anguilla">Anguilla</option>
<option value="Antarctica">Antarctica</option>
<option value="Antigua and Barbuda">Antigua and Barbuda</option>
<option value="Argentina">Argentina</option>
<option value="Armenia">Armenia</option>
<option value="Aruba">Aruba</option>
<option value="Australia">Australia</option>
<option value="Austria">Austria</option>
<option value="Azerbaijan">Azerbaijan</option>
<option value="Bahamas">Bahamas</option>
<option value="Bahrain">Bahrain</option>
<option value="Bangladesh">Bangladesh</option>
<option value="Barbados">Barbados</option>
<option value="Belarus">Belarus</option>
<option value="Belgium">Belgium</option>
<option value="Belize">Belize</option>
<option value="Benin">Benin</option>
<option value="Bermuda">Bermuda</option>
<option value="Bhutan">Bhutan</option>
<option value="Bolivia">Bolivia</option>
<option value="Bosnia and Herzegovina">Bosnia and Herzegovina</option>
<option value="Botswana">Botswana</option>
<option value="Bouvet Island">Bouvet Island</option>
<option value="Brazil">Brazil</option>
<option value="British Indian Ocean Territory">British Indian Ocean Territory</option>
<option value="Brunei">Brunei</option>
<option value="Bulgaria">Bulgaria</option>
<option value="Burkina Faso">Burkina Faso</option>
<option value="Burundi">Burundi</option>
<option value="Cambodia">Cambodia</option>
<option value="Cameroon">Cameroon</option>
<option value="Canada">Canada</option>
<option value="Cape Verde">Cape Verde</option>
<option value="Cayman Islands">Cayman Islands</option>
<option value="Central African Republic">Central African Republic</option>
<option value="Chad">Chad</option>
<option value="Chile">Chile</option>
<option value="China">China</option>
<option value="Christmas Island">Christmas Island</option>
<option value="Cocos (Keeling) Islands">Cocos (Keeling) Islands</option>
<option value="Colombia">Colombia</option>
<option value="Comoros">Comoros</option>
<option value="Congo">Congo</option>
<option value="Cook Islands">Cook Islands</option>
<option value="Costa Rica">Costa Rica</option>
<option value="Cote d&#39;Ivoire">Cote d\'Ivoire</option>
<option value="Croatia (Hrvatska)">Croatia (Hrvatska)</option>
<option value="Cuba">Cuba</option>
<option value="Cyprus">Cyprus</option>
<option value="Czech Republic">Czech Republic</option>
<option value="Congo (DRC)">Congo (DRC)</option>
<option value="Denmark">Denmark</option>
<option value="Djibouti">Djibouti</option>
<option value="Dominica">Dominica</option>
<option value="Dominican Republic">Dominican Republic</option>
<option value="East Timor">East Timor</option>
<option value="Ecuador">Ecuador</option>
<option value="Egypt">Egypt</option>
<option value="El Salvador">El Salvador</option>
<option value="Equatorial Guinea">Equatorial Guinea</option>
<option value="Eritrea">Eritrea</option>
<option value="Estonia">Estonia</option>
<option value="Ethiopia">Ethiopia</option>
<option value="Falkland Islands (Islas Malvinas)">Falkland Islands (Islas Malvinas)</option>
<option value="Faroe Islands">Faroe Islands</option>
<option value="Fiji Islands">Fiji Islands</option>
<option value="Finland">Finland</option>
<option value="France">France</option>
<option value="French Guiana">French Guiana</option>
<option value="French Polynesia">French Polynesia</option>
<option value="French Southern and Antarctic Lands">French Southern and Antarctic Lands</option>
<option value="Gabon">Gabon</option>
<option value="Gambia">Gambia</option>
<option value="Georgia">Georgia</option>
<option value="Germany">Germany</option>
<option value="Ghana">Ghana</option>
<option value="Gibraltar">Gibraltar</option>
<option value="Greece">Greece</option>
<option value="Greenland">Greenland</option>
<option value="Grenada">Grenada</option>
<option value="Guadeloupe">Guadeloupe</option>
<option value="Guam">Guam</option>
<option value="Guatemala">Guatemala</option>
<option value="Guinea">Guinea</option>
<option value="GuineaBissau">GuineaBissau</option>
<option value="Guyana">Guyana</option>
<option value="Haiti">Haiti</option>
<option value="Heard Island and McDonald Islands">Heard Island and McDonald Islands</option>
<option value="Honduras">Honduras</option>
<option value="Hong Kong SAR">Hong Kong SAR</option>
<option value="Hungary">Hungary</option>
<option value="Iceland">Iceland</option>
<option value="India">India</option>
<option value="Indonesia">Indonesia</option>
<option value="Iran">Iran</option>
<option value="Iraq">Iraq</option>
<option value="Ireland">Ireland</option>
<option value="Israel">Israel</option>
<option value="Italy">Italy</option>
<option value="Jamaica">Jamaica</option>
<option value="Japan">Japan</option>
<option value="Jordan">Jordan</option>
<option value="Kazakhstan">Kazakhstan</option>
<option value="Kenya">Kenya</option>
<option value="Kiribati">Kiribati</option>
<option value="Korea">Korea</option>
<option value="Kuwait">Kuwait</option>
<option value="Kyrgyzstan">Kyrgyzstan</option>
<option value="Laos">Laos</option>
<option value="Latvia">Latvia</option>
<option value="Lebanon">Lebanon</option>
<option value="Lesotho">Lesotho</option>
<option value="Liberia">Liberia</option>
<option value="Libya">Libya</option>
<option value="Liechtenstein">Liechtenstein</option>
<option value="Lithuania">Lithuania</option>
<option value="Luxembourg">Luxembourg</option>
<option value="Macau SAR">Macau SAR</option>
<option value="Macedonia Former Yugoslav Republic of">Macedonia Former Yugoslav Republic of</option>
<option value="Madagascar">Madagascar</option>
<option value="Malawi">Malawi</option>
<option value="Malaysia">Malaysia</option>
<option value="Maldives">Maldives</option>
<option value="Mali">Mali</option>
<option value="Malta">Malta</option>
<option value="Marshall Islands">Marshall Islands</option>
<option value="Martinique">Martinique</option>
<option value="Mauritania">Mauritania</option>
<option value="Mauritius">Mauritius</option>
<option value="Mayotte">Mayotte</option>
<option value="Mexico">Mexico</option>
<option value="Micronesia">Micronesia</option>
<option value="Moldova">Moldova</option>
<option value="Monaco">Monaco</option>
<option value="Mongolia">Mongolia</option>
<option value="Montserrat">Montserrat</option>
<option value="Morocco">Morocco</option>
<option value="Mozambique">Mozambique</option>
<option value="Myanmar">Myanmar</option>
<option value="Namibia">Namibia</option>
<option value="Nauru">Nauru</option>
<option value="Nepal">Nepal</option>
<option value="Netherlands">Netherlands</option>
<option value="Netherlands Antilles">Netherlands Antilles</option>
<option value="New Caledonia">New Caledonia</option>
<option value="New Zealand">New Zealand</option>
<option value="Nicaragua">Nicaragua</option>
<option value="Niger">Niger</option>
<option value="Nigeria">Nigeria</option>
<option value="Niue">Niue</option>
<option value="Norfolk Island">Norfolk Island</option>
<option value="North Korea">North Korea</option>
<option value="Northern Mariana Islands">Northern Mariana Islands</option>
<option value="Norway">Norway</option>
<option value="Oman">Oman</option>
<option value="Pakistan">Pakistan</option>
<option value="Palau">Palau</option>
<option value="Panama">Panama</option>
<option value="Papua New Guinea">Papua New Guinea</option>
<option value="Paraguay">Paraguay</option>
<option value="Peru">Peru</option>
<option value="Philippines">Philippines</option>
<option value="Pitcairn Islands">Pitcairn Islands</option>
<option value="Poland">Poland</option>
<option value="Portugal">Portugal</option>
<option value="Puerto Rico">Puerto Rico</option>
<option value="Qatar">Qatar</option>
<option value="Reunion">Reunion</option>
<option value="Romania">Romania</option>
<option value="Russia">Russia</option>
<option value="Rwanda">Rwanda</option>
<option value="St. Kitts and Nevis">St. Kitts and Nevis</option>
<option value="St. Lucia">St. Lucia</option>
<option value="St. Vincent and the Grenadines">St. Vincent and the Grenadines</option>
<option value="Samoa">Samoa</option>
<option value="San Marino">San Marino</option>
<option value="S&amp;atilde;o Too Tom&amp;eacute; and Principe">So Too Tom? and Principe</option>
<option value="Saudi Arabia">Saudi Arabia</option>
<option value="Senegal">Senegal</option>
<option value="Seychelles">Seychelles</option>
<option value="Sierra Leone">Sierra Leone</option>
<option value="Singapore">Singapore</option>
<option value="Slovakia">Slovakia</option>
<option value="Slovenia">Slovenia</option>
<option value="Solomon Islands">Solomon Islands</option>
<option value="Somalia">Somalia</option>
<option value="South Africa">South Africa</option>
<option value="South Georgia and the South Sandwich Islands">South Georgia and the South Sandwich Islands</option>
<option value="Spain">Spain</option>
<option value="Sri Lanka">Sri Lanka</option>
<option value="St. Helena">St. Helena</option>
<option value="St. Pierre and Miquelon">St. Pierre and Miquelon</option>
<option value="Sudan">Sudan</option>
<option value="Suriname">Suriname</option>
<option value="Svalbard and Jan Mayen">Svalbard and Jan Mayen</option>
<option value="Swaziland">Swaziland</option>
<option value="Sweden">Sweden</option>
<option value="Switzerland">Switzerland</option>
<option value="Syria">Syria</option>
<option value="Taiwan">Taiwan</option>
<option value="Tajikistan">Tajikistan</option>
<option value="Tanzania">Tanzania</option>
<option value="Thailand">Thailand</option>
<option value="Togo">Togo</option>
<option value="Tokelau">Tokelau</option>
<option value="Tonga">Tonga</option>
<option value="Trinidad and Tobago">Trinidad and Tobago</option>
<option value="Tunisia">Tunisia</option>
<option value="Turkey">Turkey</option>
<option value="Turkmenistan">Turkmenistan</option>
<option value="Turks and Caicos Islands">Turks and Caicos Islands</option>
<option value="Tuvalu">Tuvalu</option>
<option value="Uganda">Uganda</option>
<option value="Ukraine">Ukraine</option>
<option value="United Arab Emirates">United Arab Emirates</option>
<option value="United Kingdom">United Kingdom</option>
<option value="Uruguay">Uruguay</option>
<option value="Uzbekistan">Uzbekistan</option>
<option value="Vanuatu">Vanuatu</option>
<option value="Vatican City">Vatican City</option>
<option value="Venezuela">Venezuela</option>
<option value="Viet Nam">Viet Nam</option>
<option value="Virgin Islands (British)">Virgin Islands (British)</option>
<option value="Virgin Islands">Virgin Islands</option>
<option value="Wallis and Futuna">Wallis and Futuna</option>
<option value="Yemen">Yemen</option>
<option value="Yugoslavia">Yugoslavia</option>
<option value="Zambia">Zambia</option>
<option value="Zimbabwe">Zimbabwe</option>
</select><br/><br/>
<label for="gip_title">Title<span>*</span></label>
<input id="title" maxlength="40" name="title" size="34" type="text"><br/><br/>
<label for="company">Organization<span>*</span></label>
<input id="company" maxlength="40" name="company" size="34" type="text"><br/><br/>
<label for="affiliation">Affiliation</label>
<select id="@@gipaffilation" name="@@gipaffilation" title="GIP Affiliation" style="width:286px">
<option value="Other">Other</option>
<option value="Stanford GSB Student">Stanford GSB Student</option>
<option value="Stanford GSB Alumni">Stanford GSB Alumni</option>
<option value="Stanford GSB Faculty &amp; Staff">Stanford GSB Faculty &amp; Staff</option>
<option value="Stanford Student">Stanford Student</option>
<option value="Stanford Alumni">Stanford Alumni</option>
<option value="Stanford Faculty &amp; Staff">Stanford Faculty &amp; Staff</option>
<option value="Stanford Exec Ed Past Participant">Stanford Exec Ed Past Participant</option>
</select><br/><br/>
<label for="phone">Phone</label>
<input id="phone" maxlength="12" name="phone" size="34" type="text"><br/><br/>
<label for="program">Please select the program(s) you would like to learn more about
(Ctr + Click for multiple selection) (Command key on a Mac)
</label>
<select id="@@program" multiple="multiple" name="@@program" title="Program">
'._gsb_public_custom_blocks_get_gip_programs_taxonomy().'
</select><br/><br/>
<label for="source">Source</label>
<select id="@@select" name="@@select">
<option value="Web - Inquiry">Web - Inquiry</option>
</select><br/><br/>
<label for="comments">Comments (Optional; Maximum 500 characters):</label>
<textarea id="@@commenttext" name="@@commenttext" rows="15" cols="62" type="text" wrap="soft"></textarea><br>
<span>* required</span>
<div>
<input id="randomfield" disabled="disabled" maxlength="8" name="randomfield" value="ot0dn" type="text">
</div>
<label for="captcha">Type the above code below</label>
<input id="txtCaptcha" maxlength="5" name="txtCaptcha" type="text">
<br/>
<input name="submit" onClick="javascript: return required();" value="Submit" type="submit">
<input name="submit" onClick="javascript: return Clear();" value="Clear" type="button">
</div>       
<script type="text/javascript">
window.onload = function randomString() {
var chars = "0123456789abcdefghikmnopqrstuvwxyz";
var string_length = 5;
var randomstring = "";
for (var i = 0; i < string_length; i++) {
var rnum = Math.floor(Math.random() * chars.length);
randomstring += chars.substring(rnum, rnum + 1);}
document.f1.elements["randomfield"].value = randomstring;}
function Clear() {
document.f1.elements["first_name"].value = "";
document.f1.elements["last_name"].value = "";
document.f1.elements["phone"].value = "";
document.f1.elements["email"].value = "";
document.f1.elements["emma_member_country"].value = "";
document.f1.elements["@@commenttext"].value = "";
document.f1.elements["title"].value = "";
document.f1.elements["company"].value = "";
document.f1.elements["@@gipaffilation"].value = "Other";
document.f1.elements["company"].value = "";
document.f1.elements["txtCaptcha"].value = "";
return false;}
function required() {
var reqfName = document.f1.elements["first_name"].value;
var reqlName = document.f1.elements["last_name"].value;
var reqEmail = document.f1.elements["email"].value;
var reqCountry = document.f1.elements["emma_member_country"].value;
var title = document.f1.elements["title"].value;
var company = document.f1.elements["company"].value;
document.f1.elements["country"].value = reqCountry;
if (reqfName == "" || reqlName == "" || reqEmail == "" || reqCountry == "" || title == "" || company == "") {
alert("Please fill in all of the mandatory fields (denoted by *)");
return false;}
else {
var reg = /^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/;
if (reqEmail == "") {
if (document.f1.elements["randomfield"].value == document.f1.elements["txtCaptcha"].value) {
document.myform.submit();}
else {
alert("Invalid Code");
return false;}}
else {
if (reg.test(reqEmail) == false) {
alert("Invalid Email Address");
return false;}
else {
if (document.f1.elements["randomfield"].value == document.f1.elements["txtCaptcha"].value) {
var reqPhone = document.f1.elements["phone"].value;
if (reqPhone != "") {
if (reqPhone.length < 10) {
alert("Invalid Phone number");
return false;}}
document.myform.submit();}
else {
alert("Invalid Code");
return false;}}}}}
</script>
</form>';

  $salesform_webform_vars = variable_get('salesform_webform_vars','');

  if (!empty($salesform_webform_vars)) {
    $form_markup = str_replace("@@orgid", $salesform_webform_vars['@@orgid'], $form_markup);
    $form_markup = str_replace("@@commitmentname", $salesform_webform_vars['@@commitmentname'], $form_markup);
    $form_markup = str_replace("@@commitmentrole", $salesform_webform_vars['@@commitmentrole'], $form_markup);
    $form_markup = str_replace("@@program", $salesform_webform_vars['@@program'], $form_markup);
    $form_markup = str_replace("@@gipaffilation", $salesform_webform_vars['@@gipaffilation'], $form_markup);
    $form_markup = str_replace("@@select", $salesform_webform_vars['@@select'], $form_markup);
    $form_markup = str_replace("@@commenttext", $salesform_webform_vars['@@commenttext'], $form_markup);
  }
  
  return (object) array(
    'content' => array(
      '#markup' => $form_markup,
    ),
  );

}

/**
 * Returns the gip programs taxonomy for gip form
 */
function _gsb_public_custom_blocks_get_gip_programs_taxonomy() {
  $options = '';
  $vocabulary = taxonomy_vocabulary_machine_name_load('gip_programs');

  $node = menu_get_object();

  if ($terms = taxonomy_get_tree($vocabulary->vid)) {
    foreach ($terms as $term) {
      $taxonomy_term = taxonomy_term_load($term->tid);
      if (isset($taxonomy_term->field_gip_program_value[$node->language])) {
        $gip_program_value = $taxonomy_term->field_gip_program_value[$node->language][0]['value'];
        $options .= '<option value="'.check_plain($gip_program_value).'">'.check_plain($term->name).'</option>';
      }
    }
  }

  return $options;
}
