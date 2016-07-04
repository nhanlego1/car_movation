<?php
class CompanyViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data = parent::views_data();
    $data['company']['created']['field']['handler'] = 'views_handler_field_date';
    $data['company']['changed']['field']['handler'] = 'views_handler_field_date';
    $data['company']['changed']['filter']['handler'] = 'views_handler_filter_date';
    $data['company']['created']['filter']['handler'] = 'views_handler_filter_date';
    $data['company']['status']['field']['handler'] = 'views_handler_field_boolean';
    return $data;
  }
}