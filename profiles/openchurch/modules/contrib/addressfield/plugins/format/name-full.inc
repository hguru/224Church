<?php

/**
 * @file
 * Generates a first name + last name format.
 */

$plugin = array(
  'title' => t('Name (First name, Last name)'),
  'format callback' => 'addressfield_format_name_full_generate',
  'type' => 'name',
  'weight' => 0,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_name_full_generate(&$format, $address) {
  $format['name_block'] = array(
    '#type' => 'addressfield_container',
    '#attributes' => array(
      'class' => array('addressfield-container-inline', 'name-block'),
    ),
    '#weight' => -100,
    // The addressfield is considered empty without a country, hide all fields
    // until one is selected.
    '#access' => !empty($address['country']),
  );
  $format['name_block']['first_name'] = array(
    '#title' => t('First name'),
    '#size' => 30,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('first-name'),
      'x-autocompletetype' => 'given-name',
      'autocomplete' => 'given-name',
    ),
  );
  $format['name_block']['last_name'] = array(
    '#title' => t('Last name'),
    '#size' => 30,
    '#required' => TRUE,
    '#prefix' => ' ',
    '#attributes' => array(
      'class' => array('last-name'),
      'x-autocompletetype' => 'family-name',
      'autocomplete' => 'family-name',
    ),
  );
}
