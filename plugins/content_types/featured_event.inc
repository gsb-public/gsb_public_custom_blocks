<?php

$plugin = array(
  'title' => t('Event: Featured Event'),
  'category' => t('Custom Content & Features'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements featured event date formatter
 */
function gsb_featured_event_date_formatter() {

  $content = '';
  if ($nid = variable_get('feature_flag_event', 0)) {
    $node = node_load($nid);
    $language = $node->language;

    if ($node) {
      $content = node_view($node, 'featured');
      $ids = array($node->field_event_location[$language][0]['value']);
      $entity = entity_load('field_collection_item', $ids);
    }

  }
  $output ="";
  if ($node) {
    $params = array('entity_type' => 'node', 'bundle' => 'event');
    $event_instances = field_read_instances($params, array('include_deleted' => TRUE));
    foreach ($event_instances as $value) {
      if ($value['field_name'] === 'field_event_date') {
        $field_id = $value['field_id'];
        $form_info = field_info_field_by_id($field_id);
        $settings = $form_info['settings'];
        break;
      }
    }

    $item = $node->field_event_date[$language][0];
    $db_format = date_type_format($form_info['type']);
    $date = new DateObject($item['value'], $item['timezone_db'], $db_format);
    $timezone = isset($item['timezone']) ? $item['timezone'] : '';
    $timezone = timezone_open(date_get_timezone($settings['tz_handling'], $timezone));
    date_timezone_set($date, $timezone);

    $day = date_format_date($date, 'custom', 'l');
    $month_day = date_format_date($date, 'custom', 'M d');
    $time = date_format_date($date, 'custom', 'i') !== '00' ? date_format_date($date, 'custom', 'g:ia') : date_format_date($date, 'custom', 'ga');
    if (isset($item['value2'])) {
      $date2 = new DateObject($item['value2'], $item['timezone_db'], $db_format);
      date_timezone_set($date2, $timezone);
      if (date_format_date($date, 'custom', 'Y-m-d') == date_format_date($date2, 'custom', 'Y-m-d')) {
        //same date
        $time2 = date_format_date($date2, 'custom', 'i') !== '00' ? date_format_date($date2, 'custom', 'g:ia') : date_format_date($date2, 'custom', 'ga');
        if ($time2 != $time) {
          $time .= ' - ' . $time2;
        }
        $output = '<div class="event-calendar-featured-date"><div class="day">' . $day . '</div><div class="date"><strong>' . $month_day . '</strong></div><div class="time">' . $time . '</div></div>';
      }
      else {
        $month_day2 = date_format_date($date2, 'custom', 'M d');
        $output = '<div class="event-calendar-featured-date"><div class="date"><strong>' . $month_day . '</strong></div><span class="to">to</span><div class="date"><strong>' . $month_day2 . '</strong></div></div>';
      }
    }
    else {
      $output = '<div class="event-calendar-featured-date"><div class="day">' . $day . '</div><div class="date"><strong>' . $month_day . '</strong></div><div class="time">' . $time . '</div></div>';
    }

    $location = '';
    $address = $entity[$ids[0]]->field_address[$language][0];
    if ($address['locality'] != NULL) {
      $location = $address['locality'];
    }
    if ($address['country'] == 'US') {
      $location = ($address['administrative_area'] != NULL) ? $location . ', ' . $address['administrative_area'] : $location;
    }else {

      $location = ($address['country'] != NULL) ? $location . ', ' . $address['country'] : $location;
    }
 
  $output .= '<div class="event-calendar-featured-wrapper"</div><div class="event-calendar-featured-title"><a href="/' . drupal_get_path_alias($node->path['source']) . '">' . $node->title . '</a></div>';
  $output .= '<div class="event-calendar-featured-locality">' . $location.'</div>';
  $output .= '<div class="event-calendar-featured-summary">' . $node->field_editorial_summary[$language][0]['value'] . '</div></div>';
  $output .= '<div class="event-calendar-featured-image">' . render($content['field_image_single_public']) . '</div>';
  }
  return $output;
}

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_featured_event_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  if ($nid = variable_get('feature_flag_event', 0)) {
    $node = node_load($nid);
    if ($node) {
      return (object) array(
        'title' => '',
        'content' => array(
          '#markup' => gsb_featured_event_date_formatter(),
        ),
      );
    } else {
      return "";
    }

  }
}

