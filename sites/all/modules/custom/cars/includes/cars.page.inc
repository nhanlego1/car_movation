<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/9/16
 * Time: 2:19 PM
 * To change this template use File | Settings | File Templates.
 */
/**
 * Implement hook_form()
 * Form add order
 */
function cars_add_form($form, &$form_state, $entity)
{
  global $user;
  if (isset($entity)) {
    $form_state['cars'] = $entity;
  }
  $form['cars'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );
  $form['cars']['car_name'] = array(
    '#title' => t('Tên Xe'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->car_name) ? $entity->car_name : '',
    '#require' => true,
  );
  $form['cars']['car_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Số xe'),
    '#default_value' => isset($entity->car_number) ? $entity->car_number : '',
    '#require' => true,
  );
  $form['cars']['car_type'] = array(
    '#type' => 'select',
    '#title' => t('Loại xe'),
    '#default_value' => isset($entity->car_type) ? $entity->car_type : '',
    '#options' => array(
      '7 chổ'=>'7 chổ',
      '12 chổ'=>'12 chổ',
      '16 chổ'=>'16 chổ',
      '25 chổ'=>'25 chổ',
      '29 chổ'=>'29 chổ',
      '35 chổ'=>'35 chổ',
      '40 chổ'=>'40 chổ',
      '45 chổ' =>'45 chổ'
    ),
    '#require' => true,

  );

  $form['cars']['status'] = array(
    '#type' => 'select',
    '#title' => t('Trạng thái'),
    '#default_value' => isset($entity->status) ? $entity->status : '',
    '#options' => array(
      1=>'Hoạt động',0=>'Không hoạt động'
    ),
    '#require' => true,

  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu Xe')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for cars
 */

function cars_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['car_name'])) {
    form_set_error('car_name', t('Vui lòng nhập tên xe.'));
  }
  if (cars_get_cars('car_name', $form_state['values']['car_name']) && empty($form_state['cars'])) {
    drupal_set_message(t('Xe '.$form_state['values']['car_name'].' đã tồn tại trong hệ thống. Bạn nên cân nhắc khi thêm.'),'warning');
  }
  if (empty($form_state['values']['car_number'])) {
    form_set_error('car_number', t('Vui lòng nhập số xe.'));
  }
  if (empty($form_state['values']['car_type'])) {
    form_set_error('car_type', t('Vui lòng chọn loại xe.'));
  }
}

/**
 * Implement hook_form_submit()
 * Save cars
 */

function cars_add_form_submit($form, &$form_state)
{
  //check is_new or update
  global $user;
  if (isset($form_state['cars']) && !empty($form_state['cars'])) {
    $entity = $form_state['cars'];
    $entity->uid = $user->uid;
    $entity->car_name = $form_state['values']['car_name'];
    $entity->car_number = $form_state['values']['car_number'];
    $entity->car_type = $form_state['values']['car_type'];
    $entity->status = $form_state['values']['status'];
    $entity->changed = REQUEST_TIME;
    if (cars_save($entity)) {
      drupal_set_message(t('Xe ' . $form_state['values']['car_name'] . ' đã được cập nhật thành công.'), 'status');
      $form_state['redirect'] = 'cars/manager';
    } else {
      drupal_set_message(t('Xe ' . $form_state['values']['car_name'] . ' không được cập nhật thành công. Vui lòng thử lại.'), 'error');
    }
  } else {
    $entity = new stdClass();
    $entity->uid = $user->uid;
    $entity->car_name = $form_state['values']['car_name'];
    $entity->car_number = $form_state['values']['car_number'];
    $entity->car_type = $form_state['values']['car_type'];
    $entity->status = $form_state['values']['status'];
    $entity->changed = REQUEST_TIME;
    $entity->created = REQUEST_TIME;
    if (cars_save($entity)) {
      drupal_set_message(t('Xe ' . $form_state['values']['car_name'] . ' đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'cars/manager';
    } else {
      drupal_set_message(t('Xe ' . $form_state['values']['car_name'] . ' không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
  }

}

/**
 * Implement hook_form()
 * Form delete cars
 */
function cars_delete_form($form, &$form_state, $entity)
{
  $form_state['cars'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->car_name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'cars/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete')
  );
  return $form;

}

/**
 * Implement hook_form_submit
 * Delete drink
 */
function cars_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['cars'];
  cars_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->car_name)), 'status');
  $form_state['redirect'] = 'cars/manager';
}