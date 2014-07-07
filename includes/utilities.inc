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
 * @return string
 *   The string of the transformed TEI.
 */
function islandora_paged_tei_seadragon_do_transform(AbstractObject $manuscript, AbstractObject $transform) {
  $tei_dom = new DOMDocument();
  $xsl_dom = new DOMDocument();
  $xsl_processor = new XSLTProcessor();

  $tei_dom->loadXML($manuscript['TEI']->content);
  $xsl_dom->loadXML($transform['XSLT']->content);
  $xsl_processor->importStyleSheet($xsl_dom);

//  return $xsl_processor->transformToXML($tei_dom);
  return '<div data-paged-viewer-page="1">
1 1 1 1 1 1 1 1
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="2">
2 2 2 2 2 2 2
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="3">
3 3 3 3 3 3 3
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="4">
4 4 4 4 4 4 4 4 4
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="5">
5 5 5 5 5 5 5
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="6">
6 6 6 6 6 6 6 6
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="7">
7 7 7 7 7 7 7
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="8">
8 8 8 8 8 8 8
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="9">
9 9 9 9 9 9 9 9
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="10">
10 10 10 10 10
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div><div data-paged-viewer-page="11">
<br/>
11 11 11 11 11 11
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/><br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
<br/>
asdf
<br/>
iuanb
<br/>
qeiltubnqeirng
<br/>
qebtqerg
<br/>
<br/>
<br/>
qergqergqer
qergqergqe qergqergqer qerg qergqerg qergqerhtyujeytuj536hj5h
<br/>
</div>';
}
