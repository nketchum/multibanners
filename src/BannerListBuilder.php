<?php

namespace Drupal\multibanners;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Routing\LinkGeneratorTrait;
use Drupal\Core\Url;

/**
 * Defines a class to build a listing of Banner entities.
 *
 * @ingroup multibanners
 */
class BannerListBuilder extends EntityListBuilder {

  use LinkGeneratorTrait;

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['name'] = $this->t('Name');
    $header['operations'] = $this->t('Operations');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var $entity \Drupal\multibanners\Entity\Banner */
    $row['name'] = $this->l(
      $entity->label(),
      new Url(
        'entity.banner.canonical', array(
          'banner' => $entity->id(),
        )
      )
    );
    $row['operations'] = $this->l(
      'Edit',
      new Url(
        'entity.banner.edit_form', array(
          'banner' => $entity->id(),
        )
      )
    );
    return $row + parent::buildRow($entity);
  }

}
