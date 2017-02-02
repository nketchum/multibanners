<?php

namespace Drupal\featured_banners\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'Banner block' block.
 *
 * @Block(
 *  id = "banner_block",
 *  admin_label = @Translation("Banner block"),
 * )
 */
class BannerBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return array(
      'style' => 'default',
      'type' => 'simple',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form['style'] = array(
      '#type' => 'radios',
      '#title' => $this->t('Banner style'),
      '#description' => $this->t('Toggle an alternate style.'),
      '#options' => array(
        'default' => $this->t('Default'),
        'alternative' => $this->t('Alternative'),
      ),
      '#default_value' => $this->configuration['style'],
    );
    $form['type'] = array(
      '#type' => 'select',
      '#title' => $this->t('Banner type'),
      '#description' => $this->t('Choose a layout type.'),
      '#options' => array(
        'simple' => $this->t('Simple'),
        'normal' => $this->t('Normal'),
        'complex' => $this->t('Complex'),
      ),
      '#default_value' => $this->configuration['type'],
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    $this->configuration['style'] = $form_state->getValue('style');
    $this->configuration['type'] = $form_state->getValue('type');
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $node = \Drupal::routeMatch()->getParameter('node');
    $value = '';
    $active_type = 'page';
    if ($node) {
      if ($node->getType() === $active_type) {
        $value .= $node->id();
        $value .= ' ';
        $value .= $node->getType();
        $value .= ' ';
        $value .= $node->get('field_test_str')->value;
      }
    }
    return array(
      '#type' => 'markup',
      '#markup' => $this->configuration['style'] .' '. $this->configuration['type'] .' '. $value,
      '#cache' => array(
        'max-age' => 0
      ),
    );
  }

}
