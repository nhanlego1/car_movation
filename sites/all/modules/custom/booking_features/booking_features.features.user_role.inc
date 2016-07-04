<?php
/**
 * @file
 * booking_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function booking_features_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 3,
  );

  // Exported role: driver.
  $roles['driver'] = array(
    'name' => 'driver',
    'weight' => 5,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  return $roles;
}
