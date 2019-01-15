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
  module_load_include('inc', 'islandora', 'includes/authtokens');
  $out = array('info' => NULL);
  if (isset($object['JP2']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $object['JP2'])) {
    $out['info'] = islandora_openseadragon_tile_source($object->id, 'JP2', islandora_get_object_token($object->id, 'JP2', 2));
  }
  drupal_json_output($out);
}
