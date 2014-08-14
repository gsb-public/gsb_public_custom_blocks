(function ($) {
  Drupal.behaviors.gsb_public_custom_blocks_insights_search = {
    attach: function (context, settings) {
      $('#edit-submit-insights-search').click(function() {
     		// Don't submit the form just yet.
      	event.preventDefault();
      	if (!$('#edit-insights-search-keys').is(":visible")) {
      		$('#edit-insights-search-keys').show();
				  $('#edit-insights-search-keys').animate({
				    //width: [ "toggle", "swing" ]
				    width: '75%'
				  }, 500, 'linear', function() {
				    // done
				  });      		
      	}
      	else {
      		// todo: add submit handling here
      	}
      });
    }
  };

  Drupal.gsb_public_custom_blocks_insights_search = Drupal.gsb_public_custom_blocks_insights_search || {};

  Drupal.settings.gsb_public_custom_blocks_insights_search = Drupal.settings.gsb_public_custom_blocks_insights_search || {};

}(jQuery));
