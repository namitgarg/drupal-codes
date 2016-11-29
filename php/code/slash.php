<?php

$path="namit/gar&g";
$nam=custompath_val ($path);
print_r($nam);

function custompath_val ($path) {

   if (preg_match("![^a-z0-9]!i", $path)) {
      $path = preg_replace('/[^a-zA-Z0-9\/\']/', '-', $path);
      while (preg_match('/--/', $path)) {
        $path = preg_replace('/--/', '-', $path);
    }
      $path = rtrim($path, "-");
      $path = strtolower($path);
      }

  return $path;
}


?>