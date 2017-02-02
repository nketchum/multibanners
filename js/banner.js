/**
 * Iniatiates a slideshow banner type.
 */
(function ($, Drupal) {

  $(function() {
    $('.unslider-wrapper').unslider({
      animation: 'horizontal',
      arrows: true,
      autoplay: false,
      delay: 5000,
      infinite: true,
      nav: true,
      speed: 500
    })
  });

})(window.jQuery, window.Drupal, window.drupalSettings);
