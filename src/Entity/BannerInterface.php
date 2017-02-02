<?php

namespace Drupal\multibanners\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining Banner entities.
 *
 * @ingroup multibanners
 */
interface BannerInterface extends  ContentEntityInterface, EntityChangedInterface, EntityOwnerInterface {

  // Add get/set methods for your configuration properties here.

  /**
   * Gets the Banner name.
   *
   * @return string
   *   Name of the Banner.
   */
  public function getName();

  /**
   * Sets the Banner name.
   *
   * @param string $name
   *   The Banner name.
   *
   * @return \Drupal\multibanners\Entity\BannerInterface
   *   The called Banner entity.
   */
  public function setName($name);

  /**
   * Gets the Banner creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Banner.
   */
  public function getCreatedTime();

  /**
   * Sets the Banner creation timestamp.
   *
   * @param int $timestamp
   *   The Banner creation timestamp.
   *
   * @return \Drupal\multibanners\Entity\BannerInterface
   *   The called Banner entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Returns the Banner published status indicator.
   *
   * Unpublished Banner are only visible to restricted users.
   *
   * @return bool
   *   TRUE if the Banner is published.
   */
  public function isPublished();

  /**
   * Sets the published status of a Banner.
   *
   * @param bool $published
   *   TRUE to set this Banner to published, FALSE to set it to unpublished.
   *
   * @return \Drupal\multibanners\Entity\BannerInterface
   *   The called Banner entity.
   */
  public function setPublished($published);

}
