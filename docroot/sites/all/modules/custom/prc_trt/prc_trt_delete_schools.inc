<?php

/**
 * and... action!
 */

function prc_trt_delete_schools(&$node, $context) {
  node_delete($node->nid);
}

