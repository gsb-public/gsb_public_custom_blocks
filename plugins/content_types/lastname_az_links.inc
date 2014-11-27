<?php

$plugin = array(
  'title' => t('A-Z Last Name filter'),
  'category' => t('Administrator Blocks'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_lastname_az_links_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  // Collect url and query params.
  $current_path = current_path();
  $query = drupal_get_query_parameters();
  // Save for later active item checks.
  $active_letter = isset($query['last_name']) ? $query['last_name'] : '';
  // Remove filter for All link.
  unset($query['last_name']);

  $items = array();

  // We use theme_link instead of l() to avoid active classes added to every link
  // it just provides more flexibility.
  // Add 'All' link.
  $variables['path'] = $current_path;
  $variables['options'] = array('query' => $query);
  $variables['options']['attributes'] = array();
  $variables['options']['html'] = FALSE;
  $variables['text'] = t('All');
  if ($active_letter == '') {
    $variables['options']['attributes'] = array('class' => array('active'));
  }
  $items[] .= theme('link', $variables);

  // Add letter links.
  for ($i = 65; $i <= 90; $i++) {
    $letter = chr($i);
    $query['last_name'] = $letter;
    $variables['path'] = $current_path;
    $variables['options'] = array('query' => $query);
    $variables['options']['attributes'] = array();
    $variables['options']['html'] = FALSE;
    $variables['text'] = $letter;
    if ($letter == $active_letter) {
      $variables['options']['attributes'] = array('class' => array('active'));
    }
    $items[] .= theme('link', $variables);
  }

  // Attach js that handles A-Z links slider.
  $attached['js'] = array(
    array(
      'data' => drupal_get_path('module', 'gsb_public_custom_blocks') . '/js/lastname_az_links.js',
      'options' => array(
        'scope' => 'footer',
      )
    )
  );

  return (object) array(
    'content' => array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#type' => 'ul',
      '#suffix' =>  '<div class="prev"></div>',
      '#prefix' => '<div class="next"></div>',
      '#attached' => $attached,
    )
  );
}

