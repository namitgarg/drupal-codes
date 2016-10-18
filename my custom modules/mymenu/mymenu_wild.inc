<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function mymenu_wild($card,$card2)
{
  $mycontent=array(
   '#type'=>'markup',
  '#markup'=>'<p>'.t(" there  @wild    @wild2",array('@wild' => $card,'@wild2'=>$card2) ).'</p>',
  );
    // echo $card."hiiiii".$card2;
  return $mycontent;
}
