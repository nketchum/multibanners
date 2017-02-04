<?php

use Drupal\Core\Template\Attribute;
use Drupal\Core\Render\Element;

/**
 * Prepares variables for banner templates.
 *
 * Default template: banner.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - title: The name of the banner entity.
 *   - image: The path to the banner background image.
 */
function template_preprocess_banner(&$variables) {
  // Render elements using core's display system.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}

/**
 * Prepares variables for views multibanner banner templates.
 *
 * Default template: views-view-banner.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - view: A View object.
 */
function template_preprocess_views_view_banner(&$variables) {
  $handler  = $variables['view']->style_plugin;
  // Fetch classes from handler options.
  if ($handler->options['class']) {
    $class = explode(' ', $handler->options['class']);
    $class = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $class);
    // Initialize a new attribute class for $class.
    $variables['list']['attributes'] = new Attribute(array('class' => $class));
  }
  // Fetch wrapper classes from handler options.
  if ($handler->options['wrapper_class']) {
    $wrapper_class = explode(' ', $handler->options['wrapper_class']);
    $variables['attributes']['class'] = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $wrapper_class);
    // $variables['attributes']['class'][] = 'test';
  }
  template_preprocess_views_view_unformatted($variables);
}

/**
 * Prepares variables for views multibanner flex templates.
 *
 * Default template: views-view-flex.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - view: A View object.
 */
function template_preprocess_views_view_flex(&$variables) {
  $handler  = $variables['view']->style_plugin;
  // Fetch classes from handler options.
  if ($handler->options['class']) {
    $class = explode(' ', $handler->options['class']);
    $class = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $class);
    // Initialize a new attribute class for $class.
    $variables['list']['attributes'] = new Attribute(array('class' => $class));
  }
  // Fetch wrapper classes from handler options.
  if ($handler->options['wrapper_class']) {
    $wrapper_class = explode(' ', $handler->options['wrapper_class']);
    $variables['attributes']['class'] = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $wrapper_class);
    // $variables['attributes']['class'][] = 'test';
  }
  template_preprocess_views_view_unformatted($variables);
}

/**
 * Prepares variables for views multibanner video templates.
 *
 * Default template: views-view-video.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - view: A View object.
 */
function template_preprocess_views_view_video(&$variables) {
  $handler  = $variables['view']->style_plugin;
  // Fetch classes from handler options.
  if ($handler->options['class']) {
    $class = explode(' ', $handler->options['class']);
    $class = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $class);
    // Initialize a new attribute class for $class.
    $variables['list']['attributes'] = new Attribute(array('class' => $class));
  }
  // Fetch wrapper classes from handler options.
  if ($handler->options['wrapper_class']) {
    $wrapper_class = explode(' ', $handler->options['wrapper_class']);
    $variables['attributes']['class'] = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $wrapper_class);
    // $variables['attributes']['class'][] = 'test';
  }
  template_preprocess_views_view_unformatted($variables);
}
