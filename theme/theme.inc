<?php
/**
 * @file
 * Theme functions for islandora_paged_tei_seadragon.
 */

/**
 * Implements hook_preprocess_theme().
 */
function template_preprocess_islandora_paged_tei_seadragon_viewer(array &$variables) {
  module_load_include('inc', 'islandora_paged_tei_seadragon', 'includes/utilities');
  module_load_include('inc', 'islandora', 'includes/authtokens');
  module_load_include('inc', 'islandora', 'includes/datastream');

  $variables['pages_populated'] = TRUE;
  $variables['left_pane'] = FALSE;
  $variables['page_pid'] = FALSE;
  $viewer_module_path = drupal_get_path('module', 'islandora_paged_tei_seadragon');
  $manuscript = $variables['object'];
  $transform = $variables['transform_object'];
  $tei = FALSE;
  if (isset($_GET['islandora_paged_content_page'])) {
    foreach ($variables['pages'] as $page_info) {
      if ($page_info['page'] == $_GET['islandora_paged_content_page']) {
        $page_pid = $page_info['pid'];
        break;
      }
    }
  }
  if (!isset($page_pid)) {
    $page_entry = reset($variables['pages']);
    $page_pid = $page_entry['pid'];
  }

  drupal_add_css("$viewer_module_path/css/viewer.css");
  // Only want to display TEI in the event that a associated transform is
  // present.
  if ($transform) {
    $tei = islandora_paged_tei_seadragon_do_transform($manuscript, $transform);
  }
  if ($page_pid) {
    $token = islandora_get_object_token($page_pid, 'JP2', 2);

    // Not using a render array because it was adding impeding divs.
    $options = array();
    foreach ($variables['pages'] as $pid => $page_info) {
      $options[$pid] = $page_info['page'];
    }
    $pager_variables = array(
      '#options' => $options,
      '#attributes' => array('id' => array('islandora_paged_tei_seadragon_pager')),
      '#value' => $page_pid,
    );
    $variables['pager'] = '<strong>' . t('Page:') . ' </strong>' . t('!page_selector of @total', array(
      '!page_selector' => theme('select', array('element' => $pager_variables)),
      '@total' => count($variables['pages']),
    ));
    $left_src = file_create_url("$viewer_module_path/images/back.png");
    $right_src = file_create_url("$viewer_module_path/images/next.png");

    $variables['nav_left'] = '<a title="Previous" href="#" id="islandora-paged-tei-seadragon-navigate-left"><img src="' . $left_src . '"></img></a>';
    $variables['nav_right'] = '<a title="Next" href="#" id="islandora-paged-tei-seadragon-navigate-right"><img src="' . $right_src . '"></img></a>';
    $dsids_to_render = array('PDF', 'JP2', 'TIFF');
    $download_prefix = t('<strong>Download: </strong>');
    $page = islandora_object_load($page_pid);
    $datastreams = array();
    foreach ($dsids_to_render as $key => $dsid) {
      if (isset($page[$dsid]) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $page[$dsid])) {
        $size = islandora_datastream_get_human_readable_size($page[$dsid]);
        $link = l(t("@dsid (@size)", array('@dsid' => $dsid, '@size' => $size)), islandora_datastream_get_url($page[$dsid], 'download'));
        $datastreams[$dsid] = array(
          '#markup' => "$download_prefix$link",
          '#prefix' => '<div id="paged-tei-seadragon-viewer-download-datastream-' . $dsid . '">',
          '#suffix' => '</div>',
        );
      }
      else {
        // Prevents some extra calls from JS, this is a heuristic choice.
        unset($dsids_to_render[$key]);
      }
    }
    drupal_add_js(
      array(
        'islandora_paged_tei_seadragon' => array(
          'page_dsids' => $dsids_to_render,
          'download_prefix' => $download_prefix,
        ),
      ),
      'setting'
    );
    if ($tei) {
      drupal_add_js(
        array(
          'islandora_paged_tei_tei' => array(
            'populated_tei' => $tei,
          ),
        ),
        'setting'
      );
    }
    $variables['datastreams'] = drupal_render($datastreams);

    $variables['clipper'] = theme(
      'islandora_openseadragon_clipper',
      array('pid' => $page_pid)
    );

    if (islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $page['JP2'])) {
      module_load_include('inc', 'islandora_openseadragon', 'includes/utilities');
      $variables['seadragon'] = theme(
        'islandora_openseadragon_viewer',
        array(
          'pid' => $page_pid,
          'tile_sources' => array(
            islandora_openseadragon_datastream_tile_source($page['JP2']),
          ),
        )
      );
    }

    if (isset($transform['CSS'])) {
      drupal_add_css($transform['CSS']->content, array('type' => 'inline'));
    }
    drupal_add_js("$viewer_module_path/js/update_page.js");

    drupal_add_js("$viewer_module_path/js/tei_toggle.js");
    $variables['button_label'] = t('Toggle TEI');
    $variables['page_pid'] = $page_pid;
  }

  // Set if we have populated pages and TEI.
  if (!$tei && !$page_pid) {
    $variables['pages_populated'] = FALSE;
  }
  if ($tei) {
    $variables['left_pane'] = $tei;
  }
  $variables['tei'] = $tei;
  $variables['tei_pane_class'] = $page_pid ? '' : '-full';
}
