
(function ($) {
  Drupal.behaviors.gsbPublicCustomBlocks = {
      attach: function () {
        // Update link to be the right anchor.
        $('div.pane-program-finder .field-group-tab-wrapper li.vertical-tab-button a strong').each(function (index) {
          var text = $(this).text();
          $(this).parent('a').attr('href', '#' + text).attr('name', text);
        });

        // Add our responsive javascript.
        if (Modernizr.mq('(max-width: 1165px)')) {
          $('.pane-program-finder .vertical-tabs-list').addClass('resp-tabs-list');
          $('.pane-program-finder .vertical-tabs').easyResponsiveTabs({type: 'accordion', activate: Drupal.gsbPublicCustomBlocks.clicked});

          // Activate tab if we have an anchor.
          $('div.pane-program-finder li.vertical-tab-button a[name="' + window.location.hash.substring(1) + '"]').parent().click();
        }
        else {
          // Load the tab on hover.
          $('div.pane-program-finder .field-group-tab-wrapper li.vertical-tab-button a').hover(function(){
            $(this).click();
          });

          // Activate tab if we have an anchor.
          $('div.pane-program-finder li.vertical-tab-button a[name="' + window.location.hash.substring(1) + '"]').click();
        }
      }
  };

  Drupal.gsbPublicCustomBlocks = Drupal.gsbPublicCustomBlocks || {};

  // We need to scroll the window into view if a tab has been clicked in mobile
  Drupal.gsbPublicCustomBlocks.clicked = function(currentTab) {
    // Make sure the animation is completed before we scroll it into view.
    $(currentTab.target).parent().find('.resp-tab-content-active').promise().done(function() {
      $(currentTab.target)[0].scrollIntoView();
    });
  }
})(jQuery);

