<?php

$plugin = array(
  'title' => t('Alumni: VMOCK Signup'),
  'category' => t('Alumni'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_vmock_signup_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'content' => array(
      '#markup' => '
        <form action="/vmock-signup" target="_blank">
          <label for="edit-email">Email Address</label>
          <input type="text" name="email"/>
          <input type="submit" value="Signup" />
        </form>',
    ),
  );
}
