<?php
/**
 * @file
 * Helpers for this module.
 */

/**
 * Runs the transform on a manuscript.
 *
 * @param AbstractObject $manuscript
 *   The manuscript containing the TEI.
 * @param AbstractObject $transform
 *   The object contianing the transform.
 *
 * @return string|bool
 *   The string of the transformed TEI, FALSE if it does not exist.
 */
function islandora_paged_tei_seadragon_do_transform(AbstractObject $manuscript, AbstractObject $transform) {
  $tei_dom = new DOMDocument();
  $xsl_dom = new DOMDocument();
  $xsl_processor = new XSLTProcessor();

  if (isset($manuscript['TEI'])) {
    $tei_dom->loadXML($manuscript['TEI']->content);
    $xsl_dom->loadXML($transform['XSLT']->content);
    $xsl_processor->importStyleSheet($xsl_dom);

    return $xsl_processor->transformToXML($tei_dom);
  }
  else {
    return FALSE;
  }
}
