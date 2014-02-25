(function ($) {
  Drupal.behaviors.ctaAroundGlobeMap = {
    attach: function () {
    	try {
    		var map = L.mapbox.map("map", "jennyhutch.h1g0laoo");
	    	map.gridControl.options.sanitizer = function(x) { return x; };    	
    	} catch(e) {
    	}
    }
  };
})(jQuery);
