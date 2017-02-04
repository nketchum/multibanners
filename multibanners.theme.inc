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
  }
  $view = $variables['view'];
  $rows = $variables['rows'];
  $style = $view->style_plugin;
  $options = $style->options;

  $variables['default_row_class'] = !empty($options['default_row_class']);
  foreach ($rows as $id => $row) {
    $variables['rows'][$id] = array();
    $variables['rows'][$id]['content'] = $row;
    $variables['rows'][$id]['attributes'] = new Attribute();
    if ($row_class = $view->style_plugin->getRowClass($id)) {
      $variables['rows'][$id]['attributes']->addClass($row_class);
    }
  }
}
