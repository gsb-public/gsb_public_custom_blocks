<?php
$plugin = array(
  'title' => t('Impact Compass Interactive Tool'),
  'category' => t('Custom blocks'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_impact_compass_webform_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {

  $form_markup = '<div id="imapct-compass-container"><div class="imapct-compass-title">
    <h2>Impact Compass Interactive Tool</h2>
  </div>
  
  <form action="" method="post" id="gsb-impact-compass-form" accept-charset="UTF-8" class="webform-client-form">
  <div class="form-item alert-warning" id="errorMessage"><p id="errors"></p></div>
  <div class="form-item form-group">
  <label for="edit-submitted-first-name" class="control-label">Company or Opportunity<span class="form-required" title="This field is required."> *</span></label>
  <input required="required" type="text" id="company" name="company" value="" size="60" maxlength="150" class="form-text required">
  </div>
  <div class="form-item padding-top-15"><h4>Screen for Zeroing Factors</h4></div>
  <div class="form-item form-group-row">
	<div class="form-checkboxes select-or-other-select">
	<div class="item-check form-type-checkbox">
	 <input class="select-or-other-select form-checkbox" type="checkbox" id="checkbox-one" name="checkbox-one" value="No Proven failure">  <label class="option" for="">No Proven failure </label>
	</div>
	<div class="item-check item-check-2 form-type-checkbox">
	 <input class="select-or-other-select form-checkbox" type="checkbox" id="checkbox-two" name="checkbox-two" value="No negative social outcome">  <label class="option" for="">No negative social outcome</label>
	</div>
	<div class="item-check form-type-checkbox">
	 <input class="select-or-other-select form-checkbox" type="checkbox" id="" name="No unethical behavior" value="No unethical behavior">  <label class="option" for="">No unethical behavior</label>
	</div>
   </div>
 </div>
 <div class="form-item padding-top-15"><h4>Six Dimensions of Impact</h4></div>
 <div class="form-item form-group-row">
	 <div class="item">
	 <label for="edit-submitted-value-to-society">Value to Society </label>
	 <div class="tooltip select-width">
	 <select name="valueToSocietyScore" required="required" id="valueToSocietyScore" >
		<option value="0"></option>
		<option value="1">Society positive </option>
		<option value="2">Needed social progress</option>
		<option value="3">Most needed progress</option>
	 </select>
	 <span class="tooltiptext">To what extent does the intended outcome deliver societal value?</span></div>
	 </div>
	 <div class="item">
	 <label for="efficacy">Efficacy</label>
	 <div class="tooltip select-width">
	 <select id="efficacyScore" name="efficacyScore" title="Efficacy" required="required" >
	    <option value="0"></option>
	    <option value="1">Unknown outcomes</option>
	    <option value="2">Positive pilot</option>
	    <option value="3">Proven results</option>
	 </select>
	 <span class="tooltiptext">How certain are we of the effects of the solution?</span></div>
	 </div>
	<div class="item">
	 <label for="impact_magnitude">Impact Magnitude</label>
	 <div class="tooltip select-width">
	 <select id="impactMagnitudeScore" name="impactMagnitudeScore" title="Impact Magnitude" >
	    <option value="0"></option>
	    <option value="1">Small dent in problem</option>
	    <option value="2">Problem partially solved </option>
	    <option value="3">Problem eliminated</option>
	 </select>
	 <span class="tooltiptext impact-magi-tooltptxt">How meaningful is the magnitude of the intervention per person/unit?</span></div>
	</div>
</div>
<div class="form-item"></div>
<div class="form-item form-group-row">
	<div class="item">
		<label for="scalabilityScore">Scalability</label>
		<div class="tooltip select-width">
		<select id="scalabilityScore" name="scalabilityScore" title="Scalability" >
		    <option value="0"></option>
		    <option value="1">Thousands</option>
		    <option value="2">Millions</option>
		    <option value="3">Billions</option>
		</select>
		<span class="tooltiptext">How much of the affected population can this model address?</span></div>
	</div>
	<div class="item">
		<label for="impact_magnitude">Mission Alignment</label>
		<div class="tooltip select-width">
		<select id="missionAlignmentScore" name="missionAlignmentScore" title="Mission Alignment" >
		    <option value="0"></option>
		    <option value="1"><2 indicators in place</option>
		    <option value="2">2-3 indicators in place</option>
		    <option value="3">All indicators in place</option>
		</select>
		<span class="tooltiptext">To what extent is the organization driving toward outcomes? Indicators demonstrating mission alignment include:
		<br/>- A well-articulated theory of change
		<br/>- A commitment to impact measurement and reporting
		<br/>- Structural and capital choices that protect the mission
		<br/>- Aligned economic and impact models</span></div>
	</div>
	<div class="item">
	<label for="impact_magnitude">ESG</label>
	<div class="tooltip select-width">
	<select id="esgScore" name="esgScore" title="ESG" >
	    <option value="0"></option>
	    <option value="1">No severe difficiency</option>
	    <option value="2">1 exemplary dimension</option>
	    <option value="3">2+ exemplary dimensions</option>
	</select>
	<span class="tooltiptext esg-tooltptxt">How does the organization perform in the following three dimensions?
	<br/>- How does it impact society, including its employees, suppliers, clients, and the communities it operates in?
	<br/>- How does it impact the natural environment, including the water, air, climate, wilderness habitat, ...?
	<br/>- Is it governed with transparency and with concern for corruption and the law?
	</span></div>
	</div>
</div>
<div class="form-item"></div>
<div class="form-item button-row" id="button-block">
<input name="visualize" id="submitButton" class="webform-submit button-primary form-submit" value="Visualize" type="submit">
<input name="print" id="print_bt" class="buttonReset webform-submit button-primary form-submit"  value="Print" type="submit">
</div>
<div class="chart-container" >
  <canvas  id="myChart"></canvas>
  <div class="form-item chart-score">
	<p id="impactText"></p><span id="impactScore"></span>
  </div>
</div>
</form>
</div>';
 return (object) array(
    'content' => array(
      '#attached' => array(
        'js' => array(
          'https://www.chartjs.org/dist/2.6.0/Chart.bundle.js' => array(
            'type' => 'external',
          ), 
        drupal_get_path('module', 'gsb_public_custom_blocks') . '/js/impact_compass_webform.js',
        drupal_get_path('module', 'gsb_public_custom_blocks') . '/js/printThis.js'

        ),
        'css' => array(
           drupal_get_path('theme', 'gsb_theme'). '/css/conditionals/blocks/impact-compass.css',
        ), 
      ),
      '#markup' => $form_markup,
    ),
  );

}


