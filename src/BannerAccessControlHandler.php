<?php

namespace Drupal\featured_banners;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Banner entity.
 *
 * @see \Drupal\featured_banners\Entity\Banner.
 */
class BannerAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\featured_banners\Entity\BannerInterface $entity */
    switch ($operation) {
      case 'view':
        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished banner entities');
        }
        return AccessResult::allowedIfHasPermission($account, 'view published banner entities');

      case 'update':
        return AccessResult::allowedIfHasPermission($account, 'edit banner entities');

      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete banner entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add banner entities');
  }

}
