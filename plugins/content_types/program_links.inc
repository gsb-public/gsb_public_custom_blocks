<?php

$plugin = array(
  'title' => t('Program Links'),
  'category' => t('Other'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_public_custom_blocks_program_links_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  return (object) array(
    'content' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'cta-red-gradient',
        ),
      ),
      'header' => array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'program-links-title',
        ),
        '#children' => t('Programs'),
      ),
      'links' => array(
        '#theme' => 'links',
        '#links' => array(
          'mba-program' => array(
            'title' => t('MBA Program'),
            'href' => 'programs/mba',
            'attributes' => array(
              'class' => array(
                'item-0',
                'cta-link',
              ),
            ),
          ),
          'msx-program' => array(
            'title' => t('MSx Program'),
            'href' => 'programs/msx',
            'attributes' => array(
              'class' => array(
                'item-1',
                'cta-link',
              ),
            ),
          ),          
          'phd-program' => array(
            'title' => t('PhD Program'),
            'href' => 'programs/phd',
            'attributes' => array(
              'class' => array(
                'item-2',
                'cta-link',
              ),
            ),
          ),
          'executive-education' => array(
            'title' => t('Executive Education'),
            'href' => 'programs/executive-education',
            'attributes' => array(
              'class' => array(
                'item-3',
                'cta-link',
              ),
            ),
          ),
          'all-programs' => array(
            'title' => t('See All Programs'),
            'href' => 'programs',
            'attributes' => array(
              'class' => array(
                'item-4',
                'cta-link',
              ),
            ),
          ),
        ),
      ),
    ),
  );
}
