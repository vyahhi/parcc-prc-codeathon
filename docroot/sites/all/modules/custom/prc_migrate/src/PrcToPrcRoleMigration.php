<?php

/**
 * @file
 * Extending of DrupalroleMigration for PRC sources.
 */
class PrcToPrcRoleMigration extends DrupalRole7Migration {
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // On initial import, if this role already exists, just map to the
    // existing rid and don't allow it to be deleted. When updating, we can
    // take the existing rid from the map instead of querying for it. Make sure
    // when updating an imported role that we don't apply this logic.
    if (empty($row->migrate_map_destid1)) {
      $new_rid = db_select('role', 'r')
        ->fields('r', array('rid'))
        ->condition('name', $row->name)
        ->execute()
        ->fetchField();
    }
    elseif ($row->migrate_map_needs_update == MigrateMap::STATUS_IGNORED &&
      $row->migrate_map_rollback_action == MigrateMap::ROLLBACK_PRESERVE) {
      $new_rid = $row->migrate_map_destid1;
    }

    if (!empty($new_rid)) {
      $hash = isset($row->migrate_map_hash) ? $row->migrate_map_hash : NULL;
      $this->map->saveIDMapping($row, array($new_rid), MigrateMap::STATUS_IGNORED,
        MigrateMap::ROLLBACK_PRESERVE, $hash);
      $this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
      return FALSE;
    }

    // Add the path to the source row, if relevant
    if ($this->moduleExists('path')) {
      $path = $this->version->getPath('role/' . $row->rid);
      if ($path) {
        $row->path = $path;
      }
    }

    return TRUE;
  }

}