<?php

$plugin = array(
  'title' => t('ReThink form'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_rethink_form_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    return (object) array(
    'content' => array(
    '#markup' => '<form name="f1" action="http://stanford.us5.list-manage.com/subscribe/post" method="POST" onSubmit="javascript: return required();">

<input type="hidden" name="u" value="ce785d9b9016cd35fb68e83b7">
<input type="hidden" name="id" value="0b5214e34b">

<div id="mergeTable" class="mergeTable">
  
  <div class="mergeRow dojoDndItem mergeRow-email" id="mergeRow-0">
    <label for="MERGE0"><strong>Email Address</strong> <span class="asterisk">*</span></label>
    <div class="field-group">
      <input type="email" autocapitalize="off" autocorrect="off" name="MERGE0" id="MERGE0" size="25" value="">    
    </div>
  </div>

  <div class="mergeRow dojoDndItem mergeRow-text" id="mergeRow-1">
    <label for="MERGE1">First Name</label>
    <div class="field-group">
      <input type="text" name="MERGE1" id="MERGE1" size="25" value="">    
    </div>
  </div>

  <div class="mergeRow dojoDndItem mergeRow-text" id="mergeRow-2">
    <label for="MERGE2">Last Name</label>
    <div class="field-group">
      <input type="text" name="MERGE2" id="MERGE2" size="25" value="">    
    </div>
  </div>

  <div class="mergeRow dojoDndItem mergeRow-radio" id="mergeRow-3">
    <label for="MERGE3"><strong>Are you a Stanford GSB alum?</strong> <span class="asterisk">*</span></label>
    <div class="field-group">
      <div class="interestgroup_field radio-group" id="MERGE3"> 
        <label class="radio" for="MERGE3-0">
        <input type="radio" data-dojo-type="dijit/form/RadioButton" name="MERGE3" id="MERGE3-0" value="Yes"  class="av-radio"> Yes</label>
        <label class="radio" for="MERGE3-1">
        <input type="radio" data-dojo-type="dijit/form/RadioButton" name="MERGE3" id="MERGE3-1" value="No"  class="av-radio"> No</label>
        <label class="radio" for="MERGE3-2">
        <input type="radio" data-dojo-type="dijit/form/RadioButton" name="MERGE3" id="MERGE3-2" value="No, but I\'dm currently a student at Stanford GSB"  class="av-radio"> No, but I\'m currently a student at Stanford GSB</label> 
      </div>
    </div>
  </div>

</div>

<br>

<div class="submit_container">
<input type="submit" class="button" name="submit" value="Subscribe Now">
</div>

<script type="text/javascript">
function required() {
	var req_email = document.f1.elements["MERGE0"].value;
  var req_radio_alumni = document.f1.elements["MERGE3"].value;
	if (req_email == "" || req_radio_alumni == "") {
		alert("Please fill in all of the mandatory fields (denoted by *)");
		return false;
	} else {
		document.myform.submit();
	}
}
</script>
</form>',
    ),
  );
}
