<?php

$new_path = "namist.html";
$new_path = namit($new_path, 999);

print_r($new_path);

function namit($new_path, $counter) {
  $path = array("namit.html", "namit.html-0", "namit.html-1", "namit.html-2", "namit.html-3", "namit.html-4", "namit.html-5");
  if ($counter == 999) {
    $counter = 0;
    if (in_array($new_path, $path)) {
      return namit($new_path, $counter);
    }
    
    else {
      return $new_path;
    }
  }
  else {

    if (in_array($new_path . '-' . $counter, $path)) {
      $counter++;
      return namit($new_path, $counter);
    }
    else {
      return $new_path . '-' . $counter;
    }
  }
}
