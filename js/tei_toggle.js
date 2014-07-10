(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon_tei_toggle = {
        attach: function (context, settings) {
            $("#paged-tei-seadragon-viewer-tei-toggle").click(function () {
                if ($("#paged-tei-seadragon-viewer-tei").css("display") == "none") {
                    // XXX: Should be something more like width of parents-width of sibling.
                    $("#paged-tei-seadragon-viewer-seadragon-pane").width("49%");
                }
                else {
                    $("#paged-tei-seadragon-viewer-seadragon-pane").width("80%");
                }
                $("#paged-tei-seadragon-viewer-tei").toggle();
            });
        }
    }
})(jQuery);
