(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon_update_page = {
        attach: function (context, settings) {
            var set_page = function (pid) {
                token = "";
                settings.islandoraOpenSeadragon.resourceUri = "http://dgi-vagrant-i7latest.local/islandora/object/"
                    + pid + "/datastream/JP2/view" + token;
                // Updating the PID to keep it consistent, it isn't used.
                settings.islandoraOpenSeadragon.pid = pid;
                tile_source = new OpenSeadragon.DjatokaTileSource(
                    settings.islandoraOpenSeadragon.settings.djatokaServerBaseURL,
                    settings.islandoraOpenSeadragon.resourceUri,
                    settings.islandoraOpenSeadragon
                );
                Drupal.settings.islandora_open_seadragon_viewer.open(tile_source);
            };
            $("#islandora_paged_tei_seadragon_pager").change(function () {
                set_page($(this).val());
            });
        }
    }
})(jQuery);
