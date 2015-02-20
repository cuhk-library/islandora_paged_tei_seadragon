(function ($) {
    Drupal.behaviors.islandora_paged_tei_seadragon_update_page = {
        attach: function (context, settings) {
            // TEI pane's height can't be set via CSS.
            $("#paged-tei-seadragon-viewer-tei").height($(".openseadragon-canvas").height());
            // If there's no TEI populated want the viewer to take up the
            // whole page.
            var tei_defined = Drupal.settings.islandora_paged_tei_tei !== undefined && Drupal.settings.islandora_paged_tei_tei.populated_tei !== undefined;
            var tei_populated = tei_defined && Drupal.settings.islandora_paged_tei_tei.populated_tei;
            if (!tei_populated) {
                $("#paged-tei-seadragon-viewer-seadragon-pane").width("100%");
            }
            // Function for handling page changes.
            Drupal.settings.islandora_paged_tei_seadragon_update_page = function (pid, page_number) {
                // Drop out here if we are the most current request.
                if (pid == Drupal.settings.islandora_paged_tei_seadragon.current_page) {
                    return;
                }
                // Update current URL.
                // @todo preserve query params here.
                var params = {};
                params.islandora_paged_content_page = page_number;
                history.pushState({}, "", location.pathname + "?" + $.param(params));
                // Update current page to prevent race conditions.
                Drupal.settings.islandora_paged_tei_seadragon.current_page = pid;

                // Update page rendering.
                $.ajax({
                    url: Drupal.settings.basePath + "islandora/rest/v1/object/"
                        + pid + "/datastream/JP2/token?" + $.param({"uses": 2}),
                    cache: false,
                    success: function(token) {
                        // Drop out here if we are not the most current request.
                        if (pid != Drupal.settings.islandora_paged_tei_seadragon.current_page) {
                            return;
                        }
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
                        // Scroll TEI silently fails on bad transforms
                        if ($("div[data-paged-viewer-page='" + page_number + "']").position() != null) {
                            $("#paged-tei-seadragon-viewer-tei").scrollTop(
                                $("div[data-paged-viewer-page='" + page_number + "']").position().top +
                                $("#paged-tei-seadragon-viewer-tei").scrollTop()
                            );
                        }

                        // Swap out datastream download links.
                        var iteration;
                        var page_dsids = Drupal.settings.islandora_paged_tei_seadragon.page_dsids;
                        for (iteration = 0; iteration < page_dsids.length; ++iteration) {
                            var dsid = page_dsids[iteration];
                            $("#paged-tei-seadragon-viewer-download-datastream-" + dsid).empty();
                            $.ajax({
                                url: Drupal.settings.basePath + "islandora/rest/v1/object/"
                                    + pid + "/datastream/" + dsid + "?" + $.param({"content": "FALSE"}),
                                cache: false,
                                success: function(datastream_info) {
                                    // Drop out here if we are not the most current request.
                                    if (pid != Drupal.settings.islandora_paged_tei_seadragon.current_page) {
                                        return;
                                    }
                                    var kilobyte = 1024;
                                    var megabyte = kilobyte * 1024;
                                    var gigabyte = megabyte * 1024;
                                    var terabyte = gigabyte * 1024;
                                    var bytes = datastream_info.size;
                                    var size = 0;

                                    // Round is less precise than Islandora's PHP side.
                                    if ((bytes >= 0) && (bytes < kilobyte)) {
                                        size = bytes + ' B';
                                    }
                                    else if ((bytes >= kilobyte) && (bytes < megabyte)) {
                                        size = Math.round(bytes / kilobyte) + ' KiB';
                                    }
                                    else if ((bytes >= megabyte) && (bytes < gigabyte)) {
                                        size = Math.round(bytes / megabyte) + ' MiB';
                                    }
                                    else if ((bytes >= gigabyte) && (bytes < terabyte)) {
                                        size = Math.round(bytes / gigabyte) + ' GiB';
                                    }
                                    else if (bytes >= terabyte) {
                                        size = Math.round(bytes / terabyte) + ' TiB';
                                    }
                                    else {
                                        size = bytes + ' B';
                                    }
                                    download = "<div>" + Drupal.settings.islandora_paged_tei_seadragon.download_prefix
                                        + "<a href=" + Drupal.settings.basePath + "islandora/object/"
                                    + pid + "/datastream/" + datastream_info.dsid + "/download" + ">" + datastream_info.dsid + " (" + size + ")" + "</a></div>";
                                    $("#paged-tei-seadragon-viewer-download-datastream-" + datastream_info.dsid).html(download);
                                }
                            });
                        }

                    }
                })
            };

            // Bind page changes to the select.
            $("#islandora_paged_tei_seadragon_pager").change(function () {
                Drupal.settings.islandora_paged_tei_seadragon_update_page(
                    $(this).val(),
                    $(this).children("option:selected").text()
                );
            });
        }
    }
})(jQuery);
