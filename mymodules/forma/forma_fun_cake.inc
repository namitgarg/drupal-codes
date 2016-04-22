<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function form_fun_form1($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A simple form with a submit button'),
  );
  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('User Name'),
    '#required' => TRUE,
  );
  $form['password'] = array(
    '#type' => 'password_confirm',
    //'#title' => t('password'),
    '#required' => TRUE,
    '#maxlength' => 8,
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
  );
  $form['gender'] = array(
    '#type' => 'select',
    '#title' => t('GENDER'),
    '#options' => array(
      'male' => t('MALE'),
      'fermale' => t('FEMALE'),
    ),
  );


  // Adds a simple submit button that refreshes the form and clears its
  // contents. This is the default behavior for forms.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['button']['clear']=array(
    '#type'=>'submit',
    '#value'=>t('RESET'),
  '#submit'=>array('form_fun_form1_clear'),
    '#validate'=>array(),//this will skip deafult validation handler
  );
  return $form;
}
function form_fun_form1_clear()
{
drupal_set_message(t('fill again')) ; 
}
function form_fun_form1_validate($form, &$form_state)
 {
            $name=$form_state['values']['name'];
if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
 // $nameErr = "Only letters and white space allowed"; 
   form_set_error('name', t('Enter a valid name'));
}
$user=$form_state['values']['name'];
     //if($name)
      }


function form_fun_form1_submit($form, &$form_state) {
  $uname = $form_state['values']['username'];
  $pass = $form_state['values']['password'];
  //$name = $form_state['values']['name'];
  $name=$form_state['values']['name'];

  $gender = $form_state['values']['gender'];
  

  $id = db_insert('forma_table')->fields(array('username' => $uname,'password' => $pass,'name' => $name,'gender' => $gender))->execute();
 
  $query=db_select('forma_table','f')->fields('f');
       $result=$query->execute();
echo"<table>";
       while($record =$result->fetchAssoc())
       {
         echo"<tr>";
        echo"<td>".$record['username']." </td><td> ".$record['password']." </td><td>  ".$record['name']." </td><td>  ".$record['gender']."</td>";
        echo" </tr>";
       }
echo "</table>".
    $form_state['redirect']='';
       die;
       }
      