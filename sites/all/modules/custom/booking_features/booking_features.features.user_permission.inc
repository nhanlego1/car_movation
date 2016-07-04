<?php
/**
 * @file
 * booking_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function booking_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'booking:*:add'.
  $permissions['booking:*:add'] = array(
    'name' => 'booking:*:add',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'booking',
  );

  // Exported permission: 'booking:*:delete'.
  $permissions['booking:*:delete'] = array(
    'name' => 'booking:*:delete',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'booking',
  );

  // Exported permission: 'booking:*:driver'.
  $permissions['booking:*:driver'] = array(
    'name' => 'booking:*:driver',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'booking',
  );

  // Exported permission: 'booking:*:edit'.
  $permissions['booking:*:edit'] = array(
    'name' => 'booking:*:edit',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'booking',
  );

  // Exported permission: 'booking:*:manager'.
  $permissions['booking:*:manager'] = array(
    'name' => 'booking:*:manager',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'booking',
  );

  // Exported permission: 'cars:*:add'.
  $permissions['cars:*:add'] = array(
    'name' => 'cars:*:add',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'cars',
  );

  // Exported permission: 'cars:*:delete'.
  $permissions['cars:*:delete'] = array(
    'name' => 'cars:*:delete',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'cars',
  );

  // Exported permission: 'cars:*:edit'.
  $permissions['cars:*:edit'] = array(
    'name' => 'cars:*:edit',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'cars',
  );

  // Exported permission: 'cars:*:manager'.
  $permissions['cars:*:manager'] = array(
    'name' => 'cars:*:manager',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'cars',
  );

  // Exported permission: 'company:*:add'.
  $permissions['company:*:add'] = array(
    'name' => 'company:*:add',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'company',
  );

  // Exported permission: 'company:*:delete'.
  $permissions['company:*:delete'] = array(
    'name' => 'company:*:delete',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'company',
  );

  // Exported permission: 'company:*:edit'.
  $permissions['company:*:edit'] = array(
    'name' => 'company:*:edit',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
    ),
    'module' => 'company',
  );

  // Exported permission: 'company:*:manager'.
  $permissions['company:*:manager'] = array(
    'name' => 'company:*:manager',
    'roles' => array(
      'admin' => 'admin',
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'company',
  );

  return $permissions;
}
