<?php
/**
 * @file
 * Theme functions for islandora_paged_tei_seadragon.
 */

/**
 * Implements hook_preprocess_theme().
 */
function islandora_paged_tei_seadragon_preprocess_islandora_paged_tei_seadragon_viewer(array &$variables) {
  module_load_include('inc', 'islandora_paged_tei_seadragon', 'includes/utilities');
  module_load_include('inc', 'islandora', 'includes/authtokens');
  $viewer_module_path = drupal_get_path('module', 'islandora_paged_tei_seadragon');
  $manuscript = $variables['object'];
  $transform = $variables['transform_object'];
  if (isset($_GET['islandora_paged_content_page'])) {
    $page_pid = $pages[$_GET['islandora_paged_content_page']]['PID'];
  }
  else {
    $page_entry = reset($variables['pages']);
    $page_pid = $page_entry['pid'];
  }
  $token = islandora_get_object_token($page_pid, 'JP2', 2);

  $variables['tei'] = islandora_paged_tei_seadragon_do_transform($manuscript, $transform);
  $variables['seadragon'] = theme(
    'islandora_openseadragon_viewer',
    array(
      'uri' => url(
        "islandora/object/$page_pid/datastream/JP2/view",
        array('absolute' => TRUE, 'query' => array('token' => $token))
      ),
      'fedora_object' => islandora_object_load($page_pid),
    )
  );
  drupal_add_css("$viewer_module_path/css/viewer.css");
}
