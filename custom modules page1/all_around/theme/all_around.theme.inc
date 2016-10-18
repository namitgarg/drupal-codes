<?php

/**
 * @file
 * Theme functions for All Around Slider Views
 */

/**
 * Add a preprocessor to prepare data from All Around Slider Views and send to the tpl file to render the formated data.
 */
function template_process_all_around(&$vars) {
  if (!empty($vars['view'])) {
    $vars['items'] = $vars['view']->result;
  }
  return $vars;
}