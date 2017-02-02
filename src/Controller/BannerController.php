<?php

namespace Drupal\featured_banners\Controller;

use Drupal\Core\Controller\ControllerBase;

/**
 * Class BannerController.
 *
 * @package Drupal\featured_banners\Controller
 */
class BannerController extends ControllerBase {

  /**
   * Administer enabled content bundles.
   */
  public function types() {
    return [
      '#type' => 'markup',
      '#markup' => $this->t('Manage banner-enabled content types.')
    ];
  }

}
