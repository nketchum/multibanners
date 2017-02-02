<?php

namespace Drupal\featured_banners\Entity;

use Drupal\views\EntityViewsData;

/**
 * Provides Views data for Banner entities.
 */
class BannerViewsData extends EntityViewsData {

  /**
   * {@inheritdoc}
   */
  public function getViewsData() {
    $data = parent::getViewsData();

    // Additional information for Views integration, such as table joins, can be
    // put here.

    return $data;
  }

}
