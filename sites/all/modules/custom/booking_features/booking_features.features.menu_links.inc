<?php
/**
 * @file
 * booking_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function booking_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-cng-ty:company/manager.
  $menu_links['main-menu_qun-l-cng-ty:company/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'company/manager',
    'router_path' => 'company/manager',
    'link_title' => 'Quản lý công ty',
    'options' => array(
      'identifier' => 'main-menu_qun-l-cng-ty:company/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-thng-tin-h-thng:manage/information.
  $menu_links['main-menu_qun-l-thng-tin-h-thng:manage/information'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'manage/information',
    'router_path' => 'manage/information',
    'link_title' => 'Quản lý thông tin hệ thống',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_qun-l-thng-tin-h-thng:manage/information',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-xe:cars/manager.
  $menu_links['main-menu_qun-l-xe:cars/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'cars/manager',
    'router_path' => 'cars/manager',
    'link_title' => 'Quản lý xe',
    'options' => array(
      'identifier' => 'main-menu_qun-l-xe:cars/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_thm-ti-x:booking/driver.
  $menu_links['main-menu_thm-ti-x:booking/driver'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'booking/driver',
    'router_path' => 'booking/driver',
    'link_title' => 'Thêm tài xế',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_thm-ti-x:booking/driver',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Quản lý công ty');
  t('Quản lý thông tin hệ thống');
  t('Quản lý xe');
  t('Thêm tài xế');

  return $menu_links;
}
