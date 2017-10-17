<?php

/**
 * @file
 * Misc callbacks.
 */

/**
 * Page callback; AJAX tilesource config acquisition.
 */
function _islandora_paged_tei_seadragon_tilesource_callback(AbstractObject $object) {
  module_load_include('inc', 'islandora_openseadragon', 'includes/utilities');
  drupal_json_output(array(
    'info' => islandora_openseadragon_datastream_tile_source($object['JP2']),
  ));
  return;
}
