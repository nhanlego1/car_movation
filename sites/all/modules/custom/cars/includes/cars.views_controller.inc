<?php
class CarsViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data = parent::views_data();
    $data['cars']['created']['field']['handler'] = 'views_handler_field_date';
    $data['cars']['changed']['field']['handler'] = 'views_handler_field_date';
    $data['cars']['changed']['filter']['handler'] = 'views_handler_filter_date';
    $data['cars']['created']['filter']['handler'] = 'views_handler_filter_date';
    $data['cars']['status']['field']['handler'] = 'views_handler_field_boolean';
    return $data;
  }
}