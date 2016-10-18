<?php
/**
 * @file
 * Contains core functions for the Views module support.
 */

/*
 * Implements hook_views_plugins().
 *
 * This function annnounces the style plugin for allaround views.
 */
function all_around_views_plugins() {
  return array(
    'style' => array(
      // Style plugin for the All Around Slider.
      'allaround' => array(
        'title' => t('All Around Slider'),
        'help' => t('Display the results in a All Around Slider.'),
        'handler' => 'allaround_plugin_style',
        'theme' => 'all_around',
        'theme file' => 'all_around.theme.inc',
        'theme path' => drupal_get_path('module', 'all_around') . '/theme',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'even empty' => FALSE,
      ),
    ),
  );
}
