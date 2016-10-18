<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function form_states($form)
{
$form=array();
  $form['name']=array(
    '#type'=>'textfield',
    '#title'=>'Name',
  );
  $form['gender']=array(
    '#type'=>'checkbox',
    '#title'=>'GENDER',
    //'#options'=>array('male'=>'MALE','female'=>"FEMALE"),
       
  );
  $form['partner']=array(
    '#type'=>'container',
    '#states'=>array(
      'visible'=> array(
        ':input[name="gender"]' => array('checked' =>TRUE),
        //#states is used to add css javascript or jqueryscript 
        //visible is the property that we want to modify 
        //:input is super selector that will find any input on the page last line shows that when gender box is checked  call this value true
      ),
    ),
  );
   $form['partner']['name'] = array(
    '#type' => 'textfield',
    '#title'=>t('My partners name'),
  
     );
   $form['partner']['modus_operandi']=array(
     '#type'=>'select',
     '#title'=>t('My partners MO'),
     '#options'=>array(
       1=>('Lock Picking'),
       2=>('bbbbbbbbb'),
       3=>('cccccccccccc'),
       
            ),
     
     
   );
   $form['submit']=array(
     '#type'=>'submit',
     '#value'=>'SUBMIT',
   );
  
  return $form;
 
 
}
//function forma_form_states_alter(&$form, &$form_state, $form_id) {
//    drupal_set_message("hiiidffdfdfdfii");
//    echo"namit";
//    die;
//
//    $form['actions']['submit']['#submit'][] = 'form_states_submit'; // custom callback name
//}
function form_states_submit($form,&$form_state)
{
  $form_state['page_value'][1]=$form_state['values'];
  

  $form_state['#redirect']='form/funcake';
}

