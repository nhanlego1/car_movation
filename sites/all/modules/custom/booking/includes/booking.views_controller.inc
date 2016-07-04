<?php
class BookingViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data['booking']['created']['field']['handler'] = 'views_handler_field_date';
    $data['booking']['changed']['field']['handler'] = 'views_handler_field_date';
    $data['booking']['booking_from']['field']['handler'] = 'views_handler_field_date';
    $data['booking']['booking_to']['field']['handler'] = 'views_handler_field_date';
    $data['booking']['changed']['filter']['handler'] = 'views_handler_filter_date';
    $data['booking']['created']['filter']['handler'] = 'views_handler_filter_date';
    $data['booking']['booking_from']['filter']['handler'] = 'views_handler_filter_date';
    $data['booking']['booking_to']['filter']['handler'] = 'views_handler_filter_date';
    $data['booking']['status']['field']['handler'] = 'views_handler_field_boolean';
    $data['booking']['cars_id']['relationship']['handler'] = 'views_handler_relationship';
    $data['booking']['company_id']['relationship']['handler'] = 'views_handler_relationship';
    return $data;

  }
}