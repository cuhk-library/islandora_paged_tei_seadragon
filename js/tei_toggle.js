(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon = {
        attach: function (context, settings) {
            $("#paged-tei-seadragon-viewer-tei-toggle").click(function () {
                $("#paged-tei-seadragon-viewer-tei").toggle();
            });
        }
    }
})(jQuery);
