<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function mymenu_usertab($wildcard)
{
  if(is_numeric($wildcard) && ($account =  user_load($wildcard)))
  {
    $con=array(
      '#type'=>'markup',
      '#markup'=>'<h1>'.t("hiiii  you are @num user and your username is %username",array('@num' =>$wildcard,'%username'=>$account->name) ).'</h1>'
    );
    return $con;
   
  }
  else
    
  {
    return drupal_not_found ();
  }
  
}
