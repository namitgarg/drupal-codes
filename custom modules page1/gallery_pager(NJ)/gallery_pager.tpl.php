<?php
$pre = drupal_get_query_parameters();
$type = $pre['type'];
$arg1 = $type;
foreach ($list as $values) {
  if (!empty($values[1]) && !empty($values[0])) {
    $first_args[] = $values[0];
    $second_args[] = $values[1];
  }
}
foreach ($first_args as $keys => $values) {
  if ($values == $type) {
    $args1 = $type;
    $args2 = $second_args[$keys];
  }
}

$args = array($args1, $args2);
$myview = views_get_view_result('gallery_block', $display_id = 'block_2');
$view = views_get_view('gallery_block');
$view->set_display('block_2');
$view->set_items_per_page(0);
$view->set_arguments($args);
$view->pre_execute();
$view->execute();
$object = $view->result;

foreach ($object as $values) {

  $nid_list[] = $values->nid;
}
$cur_nid = arg(1);
foreach ($nid_list as $keys => $values) {
  if ($values == $cur_nid) {
    if (!empty($nid_list[$keys - 1]))
      $previous_output = '<span class="previous-gallery gal-nav">'.l("Previous", "node/" . $nid_list[$keys - 1], array('fragment' => 'main-content','query' => $pre)).'</span>';
    if (!empty($nid_list[$keys + 1]))
      $next_output = '<span class="next-gallery gal-nav">'.l("Next", "node/" . $nid_list[$keys + 1], array('fragment' => 'main-content','query' => $pre)).'</span>';
  }
}
if (!empty($previous_output))
  print$previous_output;
if (!empty($next_output))
  print($next_output);

//print $view->render(); 
?>