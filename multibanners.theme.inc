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
 * Prepares variables for views multibanner templates.
 *
 * Default template: views-view-multibanner.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - view: A View object.
 */
function template_preprocess_views_view_multibanner(&$variables) {
  $handler  = $variables['view']->style_plugin;

  // Fetch classes from handler options.
  if ($handler->options['class']) {
    $class = explode(' ', $handler->options['class']);
    $class = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $class);
    $variables['list']['attributes'] = new Attribute(array('class' => $class));
  }

  // Fetch wrapper classes from handler options.
  if ($handler->options['wrapper_class']) {
    $wrapper_class = explode(' ', $handler->options['wrapper_class']);
    $variables['attributes']['class'] = array_map('\Drupal\Component\Utility\Html::cleanCssIdentifier', $wrapper_class);
  } else {
    $variables['attributes']['class'] = array();
  }

  // Prepare template variables/classes.
  $banner_count = count($variables['view']->result);
  $banner_type = 'slider';
  if ($node = \Drupal::routeMatch()->getParameter('node')) {
    if ($node->hasField('field_banner_type')) {
      if (count($node->get('field_banner_type')->getValue())) {
        $banner_type = $node->get('field_banner_type')->getValue()[0]['value'];
      }
    }
  }

  // Assign template variables.
  $variables['banner_type'] = $banner_type;
  $variables['banner_count'] = $banner_count;

  // Assign template classes.
  $variables['attributes']['class'][] = 'multibanners';
  $variables['attributes']['class'][] = 'multibanners-type-'. $banner_type;
  $variables['attributes']['class'][] = 'multibanners-count-'. $banner_count;

  // Finish rendering.
  template_preprocess_views_view_unformatted($variables);
}
