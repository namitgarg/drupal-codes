<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function bretrieve() {
  $query = db_select('block_custom', 'f');
  $query->leftjoin('block', 'b', 'f.bid = b.delta');
  $results = $query->fields('f', array('body', 'info'))->fields('b', array('title', 'pages', 'region'))->condition('b.status', 0, '<>')->execute()->fetchAll();
 // print "<pre>";print_r($results);die;


  echo"<table border='1'><tr><th>INFO</th><th>TITLE</th><th>PAGES</th></tr>";
  foreach($results as $record) {
    
    //print "<pre>";print_r($record);die;
    echo"<tr>";
    //$pglink=explode($record['pages']);
    //echo"<td>".$record['info']." </td><td>".$record['title']."</td><td>".$GLOBALS['base_url'].$record['pages'];
    echo"<td>" . $record->info . " </td><td>" . $record->title . "</td>";
    $pglink = str_word_count($record->pages, 1, '/');
    echo "<td>";
    foreach ($pglink as $values) {
      echo "<a href='".$GLOBALS['base_url'] . '/'.$values . "</br>";
    }
          
    if(!$pglink)
    {
      echo $GLOBALS['base_url'];
    }
    echo "</td>";
    echo"</tr>";
  }
//print "<pre>";print_r($record);die;

  echo "</table>";

  die;
}
