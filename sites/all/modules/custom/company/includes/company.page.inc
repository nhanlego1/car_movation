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
function company_add_form($form, &$form_state, $entity)
{
  global $user;
  if (isset($entity)) {
    $form_state['company'] = $entity;
  }
  $form['company'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );
  $form['company']['company_name'] = array(
    '#title' => t('Tên công ty'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->company_name) ? $entity->company_name : '',
    '#require' => true,
  );
  $form['company']['company_contract'] = array(
    '#title' => t('Số hợp đồng'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->company_contract) ? $entity->company_contract : '',
    '#require' => true,
  );
  $form['company']['company_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Địa chỉ'),
    '#default_value' => isset($entity->company_address) ? $entity->company_address : '',
    '#require' => true,
  );

  $form['company']['company_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => isset($entity->company_email) ? $entity->company_email : '',
    '#require' => true,
  );
  $form['company']['company_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Điện thoại'),
    '#default_value' => isset($entity->company_phone) ? $entity->company_phone : '',
    '#require' => true,
  );
  $form['company']['company_contact'] = array(
    '#type' => 'textfield',
    '#title' => t('Người liên hệ'),
    '#default_value' => isset($entity->company_contact) ? $entity->company_contact : '',
    '#require' => true,
  );

  $form['company']['status'] = array(
    '#type' => 'select',
    '#title' => t('Trạng thái'),
    '#default_value' => isset($entity->status) ? $entity->status : '',
    '#options' => array(
      1 => 'Hoạt động', 0 => 'Không hoạt động'
    ),
    '#require' => true,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu công ty')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for company
 */

function company_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['company_name'])) {
    form_set_error('company_name', t('Vui lòng nhập tên xe.'));
  }
  if (company_get_company('company_name', $form_state['values']['company_name']) && empty($form_state['company'])) {
    drupal_set_message(t('Công ty ' . $form_state['values']['car_name'] . ' đã tồn tại trong hệ thống. Bạn nên cân nhắc khi thêm.'), 'warning');
  }

}

/**
 * Implement hook_form_submit()
 * Save company
 */

function company_add_form_submit($form, &$form_state)
{
  //check is_new or update
  global $user;
  if (isset($form_state['company']) && !empty($form_state['company'])) {
    $entity = $form_state['company'];
    $entity->uid = $user->uid;
    $entity->company_name = $form_state['values']['company_name'];
    if (!empty($form_state['values']['company_contract'])) {
      $entity->company_contract = $form_state['values']['company_contract'];
    }
    if (!empty($form_state['values']['company_address'])) {
      $entity->company_address = $form_state['values']['company_address'];
    }
    if (!empty($form_state['values']['company_phone'])) {
      $entity->company_phone = $form_state['values']['company_phone'];
    }
    if (!empty($form_state['values']['company_email'])) {
      $entity->company_email = $form_state['values']['company_email'];
    }
    if (!empty($form_state['values']['company_contact'])) {
      $entity->company_contact = $form_state['values']['company_contact'];
    }
    $entity->status = $form_state['values']['status'];
    $entity->changed = REQUEST_TIME;
    if (company_save($entity)) {
      drupal_set_message(t('Công ty ' . $form_state['values']['company_name'] . ' đã được cập nhật thành công.'), 'status');
      $form_state['redirect'] = 'company/manager';
    } else {
      drupal_set_message(t('Xe ' . $form_state['values']['car_name'] . ' không được cập nhật thành công. Vui lòng thử lại.'), 'error');
    }
  } else {
    $entity = new stdClass();
    $entity->uid = $user->uid;
    $entity->company_name = $form_state['values']['company_name'];
    if (!empty($form_state['values']['company_contract'])) {
      $entity->company_contract = $form_state['values']['company_contract'];
    }
    if (!empty($form_state['values']['company_address'])) {
      $entity->company_address = $form_state['values']['company_address'];
    }
    if (!empty($form_state['values']['company_phone'])) {
      $entity->company_phone = $form_state['values']['company_phone'];
    }
    if (!empty($form_state['values']['company_email'])) {
      $entity->company_email = $form_state['values']['company_email'];
    }
    if (!empty($form_state['values']['company_contact'])) {
      $entity->company_contact = $form_state['values']['company_contact'];
    }
    $entity->status = $form_state['values']['status'];
    $entity->changed = REQUEST_TIME;
    $entity->created = REQUEST_TIME;
    if (company_save($entity)) {
      drupal_set_message(t('Công ty ' . $form_state['values']['company_name'] . ' đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'company/manager';
    } else {
      drupal_set_message(t('Xe ' . $form_state['values']['company_name'] . ' không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
  }

}

/**
 * Implement hook_form()
 * Form delete company
 */
function company_delete_form($form, &$form_state, $entity)
{
  $form_state['company'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->company_name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'company/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
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
function company_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['company'];
  company_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->company_name)), 'status');
  $form_state['redirect'] = 'company/manager';
}