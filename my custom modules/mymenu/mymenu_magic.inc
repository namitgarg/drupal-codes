<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function mymenu_node_magic($node)
{
 // if(is_numeric($nid) && $node = node_load($nid))
  
$text=mymenu_change($node->body['und'][0]['value']);
  $output=array(
    '#type' => 'markup',
    '#markup' => $text,
  );
  return $output;

}
function mymenu_change($text)
{
  $txt2=  strrev($text);
  return $txt2;
}