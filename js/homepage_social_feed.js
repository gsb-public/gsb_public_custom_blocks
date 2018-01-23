(function ($) {

 /**
  * Behaviour for HomePage Social Feed block.
  */
 Drupal.behaviors.homepage_social_feed = {
   attach: function (context, settings) {
    gsb_tweetfeed.init({
      search: '@stanfordgsb',
      numTweets: 2,
      appendTo: '#fpp-tweets-front',
      format: 'l, M j | a'
    });
  }
 }

})(jQuery);
