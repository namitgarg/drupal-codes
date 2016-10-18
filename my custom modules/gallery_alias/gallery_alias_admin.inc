<?php

function gallery_alias_form($form, &$form_state) {

  $query = db_select('taxonomy_vocabulary', 'tv')
      ->fields('tv', array('machine_name', 'name'));
  $results = $query->execute()->fetchAll();
  foreach ($results as $values) {

    $vocab_list[$values->machine_name] = $values->name;
  }

  $form['voc_name'] = array(
    '#type' => 'select',
    '#options' => $vocab_list,
    '#required' => TRUE,
    '#default_value' => 'gallery',
    '#title' => t('Vocabulary Machine name'),
    '#required' => TRUE,
    '#description' => t('Enter The machine name for the taxonomy you want to add Alias automatically'),
  );

  $form['prefix'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Prefix Text '),
    '#default_value' => 'before-after',
    '#description' => t('Enter the prefix text that you want to add before Term Name'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#submit' => array('gallery_alias_form_submit'),
  );


  return $form;
}

function gallery_alias_form_submit($form, &$form_state) {

  $vmname = serialize($form_state['values']['voc_name']);
  $alias_prefix = serialize($form_state['values']['prefix']);
  $galval=serialize('gallery');
print_r($galval);
// print_r($vmname);
// print_r($alias_prefix);
 die;


  db_merge('variable')
  ->key(array('name' =>'alias_gallery_name'))
  ->updateFields(array( 
    'value' => $vmname,
          ))
      ->insertFields(array(
     'name'=> 'alias_gallery_name',
    'value' => $vmname,
  ))
      ->execute();
  
  
  db_merge('variable')
  ->key(array('name' =>'alias_gallery_prefix'))
  ->updateFields(array( 
    'value' => $alias_prefix,
          ))
      ->insertFields(array(
     'name'=> 'alias_gallery_prefix',
    'value' => $alias_prefix,
  ))
    ->execute();
  
  
  
  drupal_set_message("Updated value in Variable Table");

}
