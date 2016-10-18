<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 */

function frm_nde_crt($form, &$form_state)
{
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
  );
  $form['bio'] = array(
    '#type' => 'textarea',
    '#title' => t('Bio'),
    
  );
  $form['gender']=array(
   '#title'=>t('gender'),
    '#type'=>'select',
    '#options'=>array(
       'male' => t('MALE'),
      'fermale' => t('FEMALE'),
           
    ),
  
  );
   $form['age']=array(
     '#title'=>t('age'),
     '#type'=>'textfield',
   );
   $form['button']=array(
     '#value'=>'Finish',
     '#type'=>'submit',
     '#submit'=>array('create_node')
   );
  return $form;
  
}

  function create_node($form, &$form_state)
  {   
 
    $name= $form_state['values']['name'];
   echo$name."</br>";
   $bio= $form_state['values']['bio'];
   echo $bio."</br>";
   $gender= $form_state['values']['gender'];
   echo $gender."</br>";
   $age= $form_state['values']['age'];
echo $age."</br>";
$node = new stdClass(); // We create a new node object
$node->type = "node1"; // Or any other content type you want
$node->title = $name;
$node->language = LANGUAGE_NONE; // Or any language code if Locale module is enabled. More on this below *
//$node->path = array('alias' => 'your node path'); // Setting a node path
node_object_prepare($node); // Set some default values.
$node->uid = 1; // Or any id you wish

// Let's add standard body field
$node->body[$node->language][0]['value'] = $bio;
$node->body[$node->language][0]['format'] = 'filtered_html'; // If field has a format, you need to define it. Here we define a default filtered_html format for a body field
$node->field_gender[$node->language][0]['value'] = $gender;
$node->field_age[$node->language][0]['value']= $age;
$node = node_submit($node); // Prepare node for a submit
node_save($node); // After this call we'll get a ni     // Save the node
       
die;
  }

 
