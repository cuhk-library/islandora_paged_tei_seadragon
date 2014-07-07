(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon_update_page = {
        attach: function (context, settings) {
            // TEI pane's width can't be set via CSS.
            $("#paged-tei-seadragon-viewer-tei").height($(".openseadragon-canvas").height());
            Drupal.settings.islandora_paged_tei_seadragon_update_page = function (pid, page_number) {
                $.ajax({
                    url: Drupal.settings.basePath + "islandora/rest/v1/object/"
                        + pid + "/datastream/JP2/token",
                    cache: false,
                    success: function(token) {
                        // Update seadragon.
                        settings.islandoraOpenSeadragon.resourceUri =
                            location.protocol + "//" + location.host + "/" +
                            Drupal.settings.basePath + "islandora/object/" + pid
                            + "/datastream/JP2/view?token=" + token;
                        tile_source = new OpenSeadragon.DjatokaTileSource(
                            settings.islandoraOpenSeadragon.settings.djatokaServerBaseURL,
                            settings.islandoraOpenSeadragon.resourceUri,
                            settings.islandoraOpenSeadragon
                        );
                        Drupal.settings.islandora_open_seadragon_viewer.open(tile_source);
                        // Updating the PID to keep it consistent, it isn't used.
                        settings.islandoraOpenSeadragon.pid = pid;
                        // Scroll TEI.
                        $("#paged-tei-seadragon-viewer-tei").scrollTop(
                            $("div[data-paged-viewer-page='" + page_number + "']").position().top +
                            $("#paged-tei-seadragon-viewer-tei").scrollTop()
                        );
                    }
                })
            };
            $("#islandora_paged_tei_seadragon_pager").change(function () {
                Drupal.settings.islandora_paged_tei_seadragon_update_page(
                    $(this).val(),
                    $(this).children("option:selected").text()
                );
            });
        }
    }
})(jQuery);
