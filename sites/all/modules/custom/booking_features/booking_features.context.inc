<?php
/**
 * @file
 * booking_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function booking_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'Front';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-booking_manager-block_1' => array(
          'module' => 'views',
          'delta' => 'booking_manager-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'header',
          'weight' => '-15',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'booking-app_user' => array(
          'module' => 'booking',
          'delta' => 'app_user',
          'region' => 'menu',
          'weight' => '-9',
        ),
        'booking-app_info' => array(
          'module' => 'booking',
          'delta' => 'app_info',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  $export['global'] = $context;

  return $export;
}
