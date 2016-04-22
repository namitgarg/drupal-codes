<?php

$view = views_get_view('before_after_gallery');
$view->set_display('page');
$view->set_items_per_page(0);
$view->pre_execute();
$view->execute();
$object = $view->result;

foreach ($object as $values) {

  $nid_list[] = $values->nid;
}
$last = count($nid_list) - 1;
$cur_nid = arg(1);
foreach ($nid_list as $keys => $values) {
  if ($values == $cur_nid) {
    if ($keys == 0) {
      $next_nid = $nid_list[$keys + 1];
      $firstval = drupal_get_query_parameters();
      $firstval['count'] = $val['count'] + 1;
      $firstval['page'] = 0;
      print"<ul class='gal-pager'><li class='gal-first'>" . l('Next', 'node/' . $next_nid, array('query' => $firstval)) . "</li></ul>";
    }
    //for last gallery node
    elseif ($keys == $last) {

      $prev_nid = $nid_list[$keys - 1];
      $lastval = drupal_get_query_parameters();
      $lasttval['count'] = $lastval['count'] - 1;
      if ($keys % 10 == 0) {
        $lastval['page'] = $lastval['page'] - 1;
      }
      else {
        $lastval['page'] = $lastval['page'];
      }

      print"<ul class='gal-pager'><li class='gal-last'>" . l('Previous', 'node/' . $prev_nid, array('query' => $lastval)) . "</li></ul>";
    }
    else {
      if ($keys % 10 == 0) {
        $prev_nid = $nid_list[$keys - 1];
        $next_nid = $nid_list[$keys + 1];
        $currentval = drupal_get_query_parameters();
        $previousval['count'] = $currentval['count'] - 1;
        $previousval['page'] = $currentval['page'] - 1;
        $nextval['count'] = $currentval['count'] + 1;
        $nextval['page'] = $currentval['page'];
      }
      elseif ($keys % 10 == 9) {
        $prev_nid = $nid_list[$keys - 1];
        $next_nid = $nid_list[$keys + 1];
        $currentval = drupal_get_query_parameters();
        $previousval['count'] = $currentval['count'] - 1;
        $previousval['page'] = $currentval['page'];
        $nextval['count'] = $currentval['count'] + 1;
        $nextval['page'] = $currentval['page'] + 1;
      }
      else {
        $prev_nid = $nid_list[$keys - 1];
        $next_nid = $nid_list[$keys + 1];
        $currentval = drupal_get_query_parameters();
        $previousval['count'] = $currentval['count'] - 1;
        $previousval['page'] = $currentval['page'];
        $nextval['count'] = $currentval['count'] + 1;
        $nextval['page'] = $currentval['page'];
      }
      print"<ul class='gal-pager'><li class='gal-prev'>" . l('Previous', 'node/' . $prev_nid, array('query' => $previousval)) . "</li>";
      print"<li class='gal-next'>" . l('Next', 'node/' . $next_nid, array('query' => $nextval)) . "</li></ul>";
    }
  }
}
//code for back to gallery page
$cur_page=drupal_get_query_parameters();
print("<div class='back-to'>".l('Back to Before & After Galleries','before-after-gallery',array('query'=>$cur_page))."</a></div>");
//print $view->render(); 
?>