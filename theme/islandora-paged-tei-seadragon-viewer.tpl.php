<?php
/**
 * @file
 * Template file for the paged TEI seadragon viewer.
 */
?>
<div class="paged-tei-seadragon-viewer-pane" id="paged-tei-seadragon-viewer-tei-pane">
  <div>
    <div class="left-toolbar">
      <button type="button" id="paged-tei-seadragon-viewer-tei-toggle">Toggle TEI</button>
    </div>
  </div>
  <div id="paged-tei-seadragon-viewer-tei">
    <?php print $tei;?>
  </div>
</div>
<div class="paged-tei-seadragon-viewer-pane" id="paged-tei-seadragon-viewer-seadragon-pane">
  <div>
    <div class="paged-tei-seadragon-viewer-left-toolbar">
      <?php print $pager;?>
    </div>
    <div class="paged-tei-seadragon-viewer-right-toolbar">
      <?php print $clipper;?>
    </div>
  </div>
  <div id="paged-tei-seadragon-viewer-seadragon">
    <?php print $seadragon;?>
  </div>
</div>
