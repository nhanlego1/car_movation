<?php
/**
 * @file
 * booking_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function booking_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'booking_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'booking';
  $view->human_name = 'Booking Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý booking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'booking:*:manager';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/booking/add">Thêm booking</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Booking: Booking ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'booking';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Booking: Cars_id */
  $handler->display->display_options['fields']['cars_id']['id'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['table'] = 'booking';
  $handler->display->display_options['fields']['cars_id']['field'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['label'] = '';
  $handler->display->display_options['fields']['cars_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cars_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cars_id']['separator'] = '';
  /* Field: Booking: Company_id */
  $handler->display->display_options['fields']['company_id']['id'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['table'] = 'booking';
  $handler->display->display_options['fields']['company_id']['field'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['label'] = '';
  $handler->display->display_options['fields']['company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['company_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['company_id']['separator'] = '';
  /* Field: Booking: Booking_name */
  $handler->display->display_options['fields']['booking_name']['id'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_name']['field'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['label'] = 'Booking';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Xe';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$car = cars_load($row->cars_id);
print $car->car_name;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Công ty';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$co = company_load($row->company_id);
print $co->company_name;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Booking: Booking_from */
  $handler->display->display_options['fields']['booking_from']['id'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_from']['field'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['label'] = 'Từ ngày';
  $handler->display->display_options['fields']['booking_from']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_from']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_from']['second_date_format'] = 'long';
  /* Field: Booking: Booking_to */
  $handler->display->display_options['fields']['booking_to']['id'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_to']['field'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['label'] = 'Đến ngày';
  $handler->display->display_options['fields']['booking_to']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_to']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_to']['second_date_format'] = 'long';
  /* Field: Booking: Driver */
  $handler->display->display_options['fields']['driver']['id'] = 'driver';
  $handler->display->display_options['fields']['driver']['table'] = 'booking';
  $handler->display->display_options['fields']['driver']['field'] = 'driver';
  $handler->display->display_options['fields']['driver']['label'] = 'Tài xế';
  /* Field: Booking: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'booking';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = 'Điện thoại';
  /* Field: Booking: Tour_code */
  $handler->display->display_options['fields']['tour_code']['id'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_code']['field'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['label'] = 'Mã tour';
  /* Field: Booking: Tour_name */
  $handler->display->display_options['fields']['tour_name']['id'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_name']['field'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['label'] = 'Tên tour';
  /* Field: Booking: Guide */
  $handler->display->display_options['fields']['guide']['id'] = 'guide';
  $handler->display->display_options['fields']['guide']['table'] = 'booking';
  $handler->display->display_options['fields']['guide']['field'] = 'guide';
  $handler->display->display_options['fields']['guide']['label'] = 'Hướng dẫn';
  /* Field: Booking: Guide_phone */
  $handler->display->display_options['fields']['guide_phone']['id'] = 'guide_phone';
  $handler->display->display_options['fields']['guide_phone']['table'] = 'booking';
  $handler->display->display_options['fields']['guide_phone']['field'] = 'guide_phone';
  $handler->display->display_options['fields']['guide_phone']['label'] = 'ĐT hướng dẫn';
  /* Field: Booking: Price */
  $handler->display->display_options['fields']['price']['id'] = 'price';
  $handler->display->display_options['fields']['price']['table'] = 'booking';
  $handler->display->display_options['fields']['price']['field'] = 'price';
  $handler->display->display_options['fields']['price']['label'] = 'Tổng cộng';
  $handler->display->display_options['fields']['price']['precision'] = '0';
  $handler->display->display_options['fields']['price']['suffix'] = ' đ';
  /* Field: Booking: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'booking';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Trạng thái';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Booking: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'booking';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Ngày cập nhật';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Booking: Booking ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'booking';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Action';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" href="/booking/edit/[id]">Edit</a><a id="edit-cancel" href="/booking/delete/[id]">Delete</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Sort criterion: Booking: Booking_day */
  $handler->display->display_options['sorts']['booking_day']['id'] = 'booking_day';
  $handler->display->display_options['sorts']['booking_day']['table'] = 'booking';
  $handler->display->display_options['sorts']['booking_day']['field'] = 'booking_day';
  /* Filter criterion: Booking: Booking_name */
  $handler->display->display_options['filters']['booking_name']['id'] = 'booking_name';
  $handler->display->display_options['filters']['booking_name']['table'] = 'booking';
  $handler->display->display_options['filters']['booking_name']['field'] = 'booking_name';
  $handler->display->display_options['filters']['booking_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['booking_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['booking_name']['expose']['operator_id'] = 'booking_name_op';
  $handler->display->display_options['filters']['booking_name']['expose']['label'] = 'Booking';
  $handler->display->display_options['filters']['booking_name']['expose']['operator'] = 'booking_name_op';
  $handler->display->display_options['filters']['booking_name']['expose']['identifier'] = 'booking_name';
  $handler->display->display_options['filters']['booking_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Date: Date (booking) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'booking';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+10';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'booking.booking_from' => 'booking.booking_from',
    'booking.booking_to' => 'booking.booking_to',
  );
  /* Filter criterion: Booking: Tour_code */
  $handler->display->display_options['filters']['tour_code']['id'] = 'tour_code';
  $handler->display->display_options['filters']['tour_code']['table'] = 'booking';
  $handler->display->display_options['filters']['tour_code']['field'] = 'tour_code';
  $handler->display->display_options['filters']['tour_code']['operator'] = 'contains';
  $handler->display->display_options['filters']['tour_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tour_code']['expose']['operator_id'] = 'tour_code_op';
  $handler->display->display_options['filters']['tour_code']['expose']['label'] = 'Mã Tour';
  $handler->display->display_options['filters']['tour_code']['expose']['operator'] = 'tour_code_op';
  $handler->display->display_options['filters']['tour_code']['expose']['identifier'] = 'tour_code';
  $handler->display->display_options['filters']['tour_code']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Booking: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'booking';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Trạng thái';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Ngưng hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Hoàn thành',
      'operator' => '=',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'booking/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý booking';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Booking: Booking ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'booking';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Booking: Cars_id */
  $handler->display->display_options['fields']['cars_id']['id'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['table'] = 'booking';
  $handler->display->display_options['fields']['cars_id']['field'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['label'] = '';
  $handler->display->display_options['fields']['cars_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cars_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cars_id']['separator'] = '';
  /* Field: Booking: Company_id */
  $handler->display->display_options['fields']['company_id']['id'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['table'] = 'booking';
  $handler->display->display_options['fields']['company_id']['field'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['label'] = '';
  $handler->display->display_options['fields']['company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['company_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['company_id']['separator'] = '';
  /* Field: Booking: Booking_name */
  $handler->display->display_options['fields']['booking_name']['id'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_name']['field'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['label'] = 'Booking';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Xe';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$car = cars_load($row->cars_id);
print $car->car_name;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Công ty';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$co = company_load($row->company_id);
print $co->company_name;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Booking: Booking_from */
  $handler->display->display_options['fields']['booking_from']['id'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_from']['field'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['label'] = 'Từ ngày';
  $handler->display->display_options['fields']['booking_from']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_from']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_from']['second_date_format'] = 'long';
  /* Field: Booking: Booking_to */
  $handler->display->display_options['fields']['booking_to']['id'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_to']['field'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['label'] = 'Đến ngày';
  $handler->display->display_options['fields']['booking_to']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_to']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_to']['second_date_format'] = 'long';
  /* Field: Booking: Driver */
  $handler->display->display_options['fields']['driver']['id'] = 'driver';
  $handler->display->display_options['fields']['driver']['table'] = 'booking';
  $handler->display->display_options['fields']['driver']['field'] = 'driver';
  $handler->display->display_options['fields']['driver']['label'] = 'Tài xế';
  /* Field: Booking: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'booking';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = 'Điện thoại';
  /* Field: Booking: Tour_code */
  $handler->display->display_options['fields']['tour_code']['id'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_code']['field'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['label'] = 'Mã tour';
  /* Field: Booking: Tour_name */
  $handler->display->display_options['fields']['tour_name']['id'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_name']['field'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['label'] = 'Tên tour';
  /* Field: Booking: Guide */
  $handler->display->display_options['fields']['guide']['id'] = 'guide';
  $handler->display->display_options['fields']['guide']['table'] = 'booking';
  $handler->display->display_options['fields']['guide']['field'] = 'guide';
  $handler->display->display_options['fields']['guide']['label'] = 'Hướng dẫn';
  /* Field: Booking: Guide_phone */
  $handler->display->display_options['fields']['guide_phone']['id'] = 'guide_phone';
  $handler->display->display_options['fields']['guide_phone']['table'] = 'booking';
  $handler->display->display_options['fields']['guide_phone']['field'] = 'guide_phone';
  $handler->display->display_options['fields']['guide_phone']['label'] = 'ĐT hướng dẫn';
  /* Field: Booking: Price */
  $handler->display->display_options['fields']['price']['id'] = 'price';
  $handler->display->display_options['fields']['price']['table'] = 'booking';
  $handler->display->display_options['fields']['price']['field'] = 'price';
  $handler->display->display_options['fields']['price']['label'] = 'Tổng cộng';
  $handler->display->display_options['fields']['price']['precision'] = '0';
  $handler->display->display_options['fields']['price']['suffix'] = ' đ';
  /* Field: Booking: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'booking';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Trạng thái';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Booking: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'booking';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Ngày cập nhật';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['path'] = 'booking/manager/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'booking/manager';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Quản lý booking dài hạn';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Booking: Booking ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'booking';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Booking: Cars_id */
  $handler->display->display_options['fields']['cars_id']['id'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['table'] = 'booking';
  $handler->display->display_options['fields']['cars_id']['field'] = 'cars_id';
  $handler->display->display_options['fields']['cars_id']['label'] = '';
  $handler->display->display_options['fields']['cars_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cars_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cars_id']['separator'] = '';
  /* Field: Booking: Company_id */
  $handler->display->display_options['fields']['company_id']['id'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['table'] = 'booking';
  $handler->display->display_options['fields']['company_id']['field'] = 'company_id';
  $handler->display->display_options['fields']['company_id']['label'] = '';
  $handler->display->display_options['fields']['company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['company_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['company_id']['separator'] = '';
  /* Field: Booking: Booking_name */
  $handler->display->display_options['fields']['booking_name']['id'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_name']['field'] = 'booking_name';
  $handler->display->display_options['fields']['booking_name']['label'] = 'Booking';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Xe';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$car = cars_load($row->cars_id);
print $car->car_name;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Công ty';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$co = company_load($row->company_id);
print $co->company_name;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Booking: Booking_from */
  $handler->display->display_options['fields']['booking_from']['id'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_from']['field'] = 'booking_from';
  $handler->display->display_options['fields']['booking_from']['label'] = 'Từ ngày';
  $handler->display->display_options['fields']['booking_from']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_from']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_from']['second_date_format'] = 'long';
  /* Field: Booking: Booking_to */
  $handler->display->display_options['fields']['booking_to']['id'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['table'] = 'booking';
  $handler->display->display_options['fields']['booking_to']['field'] = 'booking_to';
  $handler->display->display_options['fields']['booking_to']['label'] = 'Đến ngày';
  $handler->display->display_options['fields']['booking_to']['date_format'] = 'custom';
  $handler->display->display_options['fields']['booking_to']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['booking_to']['second_date_format'] = 'long';
  /* Field: Booking: Driver */
  $handler->display->display_options['fields']['driver']['id'] = 'driver';
  $handler->display->display_options['fields']['driver']['table'] = 'booking';
  $handler->display->display_options['fields']['driver']['field'] = 'driver';
  $handler->display->display_options['fields']['driver']['label'] = 'Tài xế';
  /* Field: Booking: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'booking';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = 'Điện thoại';
  /* Field: Booking: Tour_code */
  $handler->display->display_options['fields']['tour_code']['id'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_code']['field'] = 'tour_code';
  $handler->display->display_options['fields']['tour_code']['label'] = 'Mã tour';
  /* Field: Booking: Tour_name */
  $handler->display->display_options['fields']['tour_name']['id'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['table'] = 'booking';
  $handler->display->display_options['fields']['tour_name']['field'] = 'tour_name';
  $handler->display->display_options['fields']['tour_name']['label'] = 'Tên tour';
  /* Field: Booking: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'booking';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Trạng thái';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Booking: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'booking';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Ngày cập nhật';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Booking: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'booking';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  /* Filter criterion: Booking: Booking_long */
  $handler->display->display_options['filters']['booking_long']['id'] = 'booking_long';
  $handler->display->display_options['filters']['booking_long']['table'] = 'booking';
  $handler->display->display_options['filters']['booking_long']['field'] = 'booking_long';
  $handler->display->display_options['filters']['booking_long']['value']['value'] = '1';
  $export['booking_manager'] = $view;

  $view = new view();
  $view->name = 'cars_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cars';
  $view->human_name = 'Cars manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý xe';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'cars:*:manager';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/cars/add">Thêm Xe</a></li></ul>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Cars: Cars ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'cars';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Cars: Car_name */
  $handler->display->display_options['fields']['car_name']['id'] = 'car_name';
  $handler->display->display_options['fields']['car_name']['table'] = 'cars';
  $handler->display->display_options['fields']['car_name']['field'] = 'car_name';
  $handler->display->display_options['fields']['car_name']['label'] = 'Tên xe';
  /* Field: Cars: Car_number */
  $handler->display->display_options['fields']['car_number']['id'] = 'car_number';
  $handler->display->display_options['fields']['car_number']['table'] = 'cars';
  $handler->display->display_options['fields']['car_number']['field'] = 'car_number';
  $handler->display->display_options['fields']['car_number']['label'] = 'Số xe';
  /* Field: Cars: Car_type */
  $handler->display->display_options['fields']['car_type']['id'] = 'car_type';
  $handler->display->display_options['fields']['car_type']['table'] = 'cars';
  $handler->display->display_options['fields']['car_type']['field'] = 'car_type';
  $handler->display->display_options['fields']['car_type']['label'] = 'Loại xe';
  /* Field: Cars: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'cars';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Ngày cập nhật';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Cars: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'cars';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Trạng thái';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Cars: Cars ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'cars';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Quản lý';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action-links" href="/cars/edit/[id]">Edit</a><a id="edit-cancel" href="/cars/delete/[id]">Delete</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Sort criterion: Cars: Changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'cars';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Cars: Car_type */
  $handler->display->display_options['filters']['car_type']['id'] = 'car_type';
  $handler->display->display_options['filters']['car_type']['table'] = 'cars';
  $handler->display->display_options['filters']['car_type']['field'] = 'car_type';
  $handler->display->display_options['filters']['car_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['car_type']['expose']['operator_id'] = 'car_type_op';
  $handler->display->display_options['filters']['car_type']['expose']['label'] = 'Car_type';
  $handler->display->display_options['filters']['car_type']['expose']['operator'] = 'car_type_op';
  $handler->display->display_options['filters']['car_type']['expose']['identifier'] = 'car_type';
  $handler->display->display_options['filters']['car_type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['car_type']['group_info']['label'] = 'Loại xe';
  $handler->display->display_options['filters']['car_type']['group_info']['identifier'] = 'car_type';
  $handler->display->display_options['filters']['car_type']['group_info']['group_items'] = array(
    1 => array(
      'title' => '7 chổ',
      'operator' => '=',
      'value' => '7 chổ',
    ),
    2 => array(
      'title' => '12 chổ',
      'operator' => '=',
      'value' => '12 chổ',
    ),
    3 => array(
      'title' => '16 chổ',
      'operator' => '=',
      'value' => '16 chổ',
    ),
    4 => array(
      'title' => '25 chổ',
      'operator' => '=',
      'value' => '25 chổ',
    ),
    5 => array(
      'title' => '29 chổ',
      'operator' => '=',
      'value' => '29 chổ',
    ),
    6 => array(
      'title' => '35 chổ',
      'operator' => '=',
      'value' => '35 chổ',
    ),
    7 => array(
      'title' => '40 chổ',
      'operator' => '=',
      'value' => '40 chổ',
    ),
    8 => array(
      'title' => '45 chổ',
      'operator' => '=',
      'value' => '45 chổ',
    ),
  );
  /* Filter criterion: Cars: Car_number */
  $handler->display->display_options['filters']['car_number']['id'] = 'car_number';
  $handler->display->display_options['filters']['car_number']['table'] = 'cars';
  $handler->display->display_options['filters']['car_number']['field'] = 'car_number';
  $handler->display->display_options['filters']['car_number']['operator'] = 'contains';
  $handler->display->display_options['filters']['car_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['car_number']['expose']['operator_id'] = 'car_number_op';
  $handler->display->display_options['filters']['car_number']['expose']['label'] = 'Số xe';
  $handler->display->display_options['filters']['car_number']['expose']['operator'] = 'car_number_op';
  $handler->display->display_options['filters']['car_number']['expose']['identifier'] = 'car_number';
  $handler->display->display_options['filters']['car_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Cars: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'cars';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Trạng thái';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Đang hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Ngưng hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'cars/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý xe';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cars_manager'] = $view;

  $view = new view();
  $view->name = 'company_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'company';
  $view->human_name = 'Company Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý công ty';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'company:*:manager';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/company/add">Thêm Công ty</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Company: Company ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'company';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Company: Company_name */
  $handler->display->display_options['fields']['company_name']['id'] = 'company_name';
  $handler->display->display_options['fields']['company_name']['table'] = 'company';
  $handler->display->display_options['fields']['company_name']['field'] = 'company_name';
  $handler->display->display_options['fields']['company_name']['label'] = 'Công ty';
  /* Field: Company: Company_contract */
  $handler->display->display_options['fields']['company_contract']['id'] = 'company_contract';
  $handler->display->display_options['fields']['company_contract']['table'] = 'company';
  $handler->display->display_options['fields']['company_contract']['field'] = 'company_contract';
  $handler->display->display_options['fields']['company_contract']['label'] = 'Hợp đồng';
  /* Field: Company: Company_contact */
  $handler->display->display_options['fields']['company_contact']['id'] = 'company_contact';
  $handler->display->display_options['fields']['company_contact']['table'] = 'company';
  $handler->display->display_options['fields']['company_contact']['field'] = 'company_contact';
  $handler->display->display_options['fields']['company_contact']['label'] = 'Người liên hệ';
  /* Field: Company: Company_email */
  $handler->display->display_options['fields']['company_email']['id'] = 'company_email';
  $handler->display->display_options['fields']['company_email']['table'] = 'company';
  $handler->display->display_options['fields']['company_email']['field'] = 'company_email';
  $handler->display->display_options['fields']['company_email']['label'] = 'Email';
  /* Field: Company: Company_phone */
  $handler->display->display_options['fields']['company_phone']['id'] = 'company_phone';
  $handler->display->display_options['fields']['company_phone']['table'] = 'company';
  $handler->display->display_options['fields']['company_phone']['field'] = 'company_phone';
  $handler->display->display_options['fields']['company_phone']['label'] = 'Điện thoại';
  /* Field: Company: Company_address */
  $handler->display->display_options['fields']['company_address']['id'] = 'company_address';
  $handler->display->display_options['fields']['company_address']['table'] = 'company';
  $handler->display->display_options['fields']['company_address']['field'] = 'company_address';
  $handler->display->display_options['fields']['company_address']['label'] = 'Địa chỉ';
  /* Field: Company: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'company';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Trạng thái';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Company: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'company';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Ngày cập nhật';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Company: Company ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'company';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Action';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" href="/company/edit/[id]">Edit</a><a id="edit-cancel" href="/company/delete/[id]">Delete </a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Sort criterion: Company: Company_name */
  $handler->display->display_options['sorts']['company_name']['id'] = 'company_name';
  $handler->display->display_options['sorts']['company_name']['table'] = 'company';
  $handler->display->display_options['sorts']['company_name']['field'] = 'company_name';
  /* Filter criterion: Company: Company_contact */
  $handler->display->display_options['filters']['company_contact']['id'] = 'company_contact';
  $handler->display->display_options['filters']['company_contact']['table'] = 'company';
  $handler->display->display_options['filters']['company_contact']['field'] = 'company_contact';
  $handler->display->display_options['filters']['company_contact']['operator'] = 'contains';
  $handler->display->display_options['filters']['company_contact']['exposed'] = TRUE;
  $handler->display->display_options['filters']['company_contact']['expose']['operator_id'] = 'company_contact_op';
  $handler->display->display_options['filters']['company_contact']['expose']['label'] = 'Người liên hệ';
  $handler->display->display_options['filters']['company_contact']['expose']['operator'] = 'company_contact_op';
  $handler->display->display_options['filters']['company_contact']['expose']['identifier'] = 'company_contact';
  $handler->display->display_options['filters']['company_contact']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Company: Company_name */
  $handler->display->display_options['filters']['company_name']['id'] = 'company_name';
  $handler->display->display_options['filters']['company_name']['table'] = 'company';
  $handler->display->display_options['filters']['company_name']['field'] = 'company_name';
  $handler->display->display_options['filters']['company_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['company_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['company_name']['expose']['operator_id'] = 'company_name_op';
  $handler->display->display_options['filters']['company_name']['expose']['label'] = 'Công ty';
  $handler->display->display_options['filters']['company_name']['expose']['operator'] = 'company_name_op';
  $handler->display->display_options['filters']['company_name']['expose']['identifier'] = 'company_name';
  $handler->display->display_options['filters']['company_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Company: Company_phone */
  $handler->display->display_options['filters']['company_phone']['id'] = 'company_phone';
  $handler->display->display_options['filters']['company_phone']['table'] = 'company';
  $handler->display->display_options['filters']['company_phone']['field'] = 'company_phone';
  $handler->display->display_options['filters']['company_phone']['operator'] = 'contains';
  $handler->display->display_options['filters']['company_phone']['exposed'] = TRUE;
  $handler->display->display_options['filters']['company_phone']['expose']['operator_id'] = 'company_phone_op';
  $handler->display->display_options['filters']['company_phone']['expose']['label'] = 'Điện thoại';
  $handler->display->display_options['filters']['company_phone']['expose']['operator'] = 'company_phone_op';
  $handler->display->display_options['filters']['company_phone']['expose']['identifier'] = 'company_phone';
  $handler->display->display_options['filters']['company_phone']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Company: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'company';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Trạng thái';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Đang hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Ngưng hoạt động',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'company/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý công ty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['company_manager'] = $view;

  $view = new view();
  $view->name = 'user_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý người dùng';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/admin/people/create?destination=account/manager">Thêm account</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'account/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý người dùng';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['user_management'] = $view;

  return $export;
}
