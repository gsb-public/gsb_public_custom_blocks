<?php

$plugin = array(
  'title' => t('Home Page Social Feed'),
  'category' => t('Administrator Blocks'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_homepage_social_feed_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'content' => array(
      '#attached' => array(
        'library' => array(
          array('gsb_feature_social_feed', 'gsb_tweetfeed'),
        ),
      ),
      '#markup' => '
        <ul class="icon-wrapper">
          <li><a href="https://twitter.com/stanfordbiz" target="_blank" class="circle social-block-twitter"></a></li>
          <li><a href="http://www.youtube.com/stanfordbusiness" target="_blank" class="circle social-block-youtube"></a></li>
          <li><a href="http://www.linkedin.com/company/stanford-graduate-school-of-business" target="_blank" class="circle social-block-linkedin"></a></li>
          <li><a href="https://www.facebook.com/StanfordGSB" target="_blank" class="circle social-block-facebook"></a></li>
        </ul>
        <div class="twitter-feed">
          <div class="twitter-handle">
            <a href="http://twitter.com/@stanfordbiz" target="_blank"><strong>Stanford Business</strong><br />@StanfordBiz</a>
          </div>
          <div id="fpp-tweets-front"></div>
        </div>
        <script>gsb_tweetfeed.init({
          search: \'@stanfordbiz\',
          numTweets: 2,
          appendTo: \'#fpp-tweets-front\',
          format: \'l, M j | a\'
        });</script>',
    ),
  );
}
