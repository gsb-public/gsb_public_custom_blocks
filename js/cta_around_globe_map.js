(function ($) {
  Drupal.behaviors.ctaAroundGlobeMap = {
    attach: function () {
	    var map = L.mapbox.map("map", "jennyhutch.GSB_test8,jennyhutch.GSBregions");
	    map.gridControl.options.sanitizer = function(x) { return x; };
    }
  };
})(jQuery);