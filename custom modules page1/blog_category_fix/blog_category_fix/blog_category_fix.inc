<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function taxonomy_fix()
{
      $query = db_select('field_data_field_category', 'gd')
      ->fields('gd', array('entity_id','field_category_tid'))
      ->condition('bundle', 'blog');
  $results = $query->execute()->fetchAll();
  print("<pre>");
  $query1= db_select('taxonomy_index','ti')
   ->fields('ti',array('nid','tid','sticky','created'));
  $results1 =$query1->execute()->fetchAll();
   // print_r($results1);
      
  foreach ($results as $values)
  {
      
      $nnid=$values->entity_id;
      $tax=$values->field_category_tid;
       
db_merge('taxonomy_index')
  ->insertFields(array(
     'sticky'=> '1',
    'created'=>time()
  ))
  ->updateFields(array(
  
    'sticky'=> '0',
    'created'=>time()
  ))
  ->key(array('nid' => $nnid,'tid'=>$tax))
  ->execute();
      
      
      print_r($tax ."->". $nnid);
      print("<br>");
  }
  
}