(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon_tei_toggle = {
        attach: function (context, settings) {
            $("#paged-tei-seadragon-viewer-tei-toggle").click(function () {
                if ($("#paged-tei-seadragon-viewer-tei").css("display") == "none") {
                    $("#paged-tei-seadragon-viewer-seadragon-pane").width("49%");
                }
                else {
                    // XXX: Should be something more like
                    // `width of parents-width of sibling`. But taking manual
                    // control is a can of worms with re-size.
                    $("#paged-tei-seadragon-viewer-seadragon-pane").width("90%");
                }
                $("#paged-tei-seadragon-viewer-tei").toggle();
            });
        }
    }
})(jQuery);
