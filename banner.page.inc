<?php

/**
 * @file
 * Contains banner.page.inc.
 *
 * Page callback for Banner entities.
 */

use Drupal\Core\Render\Element;

/**
 * Prepares variables for Banner templates.
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
  // $variables['title'] = $variables['elements']['#banner']->getName();
  // if (count($img = $variables['elements']['#banner']->get('field_banner_image')->getValue())) {
  //   $fs = \Drupal::entityManager()->getStorage('file');
  //   $file = $fs->load($img[0]['target_id']);
  //   $variables['image'] = '<img src="'. $file->url() .'">';;
  // }

  // Render elements using core's display system.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

}
