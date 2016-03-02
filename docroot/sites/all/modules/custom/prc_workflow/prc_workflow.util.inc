<?php
/**
 * Created by PhpStorm.
 * User: oz.heller
 * Date: 8/3/2015
 * Time: 10:03 AM
 */


/**
 * Delete a menu item based on its menu, title, and path.
 */
function prc_workflow_kill_menu_item($menu_name, $link_title, $link_path) {
  $query = 'SELECT mlid FROM {menu_links} WHERE menu_name = ? AND link_title = ? AND link_path = ?';
  if ($mlid = db_query($query, array($menu_name, $link_title, $link_path))->fetchField()) {
    menu_link_delete($mlid);
  }
}