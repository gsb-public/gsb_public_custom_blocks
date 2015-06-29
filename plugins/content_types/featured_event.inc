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
    if ($node) {
      $content = node_view($node, 'featured');
    }
  }

  $params = array('entity_type' => 'node', 'bundle' => 'event');
  $event_instances = field_read_instances($params, array('include_deleted' => TRUE));
  foreach($event_instances as $value) {
    if ($value['field_name'] === 'field_event_date') {
      $field_id = $value['field_id'];
      $form_info = field_info_field_by_id($field_id);
      $settings = $form_info['settings'];
      break;
    }
  }

  $item = $node->field_event_date[LANGUAGE_NONE][0];
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
        $output = '<div class="event-calendar-featured "><div class="day">' . $day . '</div><div class="date"><strong>' . $month_day . '</strong></div><div class="time">' . $time . '</div></div>';
      }
      else {
        $month_day2 = date_format_date($date2, 'custom', 'M d');
        $output = '<div class="event-calendar-featured"><div class="date"><strong>' . $month_day . '</strong></div><span class="to">to</span><div class="date"><strong>' . $month_day2 . '</strong></div></div>';
      }
    }
    else {
      $output = '<div class="event-calendar-featured"><div class="day">' . $day . '</div><div class="date"><strong>' . $month_day . '</strong></div><div class="time">' . $time . '</div></div>';
    }

  $location = $node->field_address[LANGUAGE_NONE][0];
  $output .= '<div class="event-calendar-featured-title">'.$node->title.'</div>';
  $output .= '<div class="event-calendar-featured-locality">'.$location['locality'].', '.$location['administrative_area'].'</div>';
  $output .= '<div class="event-calendar-featured-summary">'.$node->field_editorial_summary[LANGUAGE_NONE][0]['value'].'</div>';
  $output .= '<div class="event-calendar-featured-image">'.render($content['field_image_single_public']).'</div>';
  return $output;
}

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_featured_event_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'title' => '',
    'content' => array(
    '#markup' => gsb_featured_event_date_formatter(),
    ),
  );
}

