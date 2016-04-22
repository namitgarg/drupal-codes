<?php
  $query = db_select('views_display', 'vd')
      ->fields('vd', array('display_options'))
      ->condition('display_plugin', 'page');
   $results = $query->execute()->fetchAll();

  foreach ($results as $result) {
    $paths = unserialize($result->display_options);
    $required_path[] = $paths['path'];
  }
  foreach($required_path as $path2)
  {
   
      $path2=preg_replace("/%/","*", $path2);
       $final_path[]=$path2;
       
  }
  array_push($final_path,"search404","search404/*","search/*","blog-category/*","search-blog","search-blog/*");
  $final_path= array_unique($final_path);
//    print("<pre>");print_r($final_path);
    
  $current_path = arg(0);
  if(arg(1)!=NULL && arg(0)!='node')
  {
      $current_path=$current_path."/*";
  }
  if(arg(2)!=NULL  && arg(0)!='node')
  {
      $current_path=$current_path."/*";
  }
  if(arg(3)!=NULL && arg(0)!='node')
  {
      $current_path=$current_path."/*";
  }
//  print_r($current_path."</br>");
  if (in_array($current_path, $final_path)) {
     print("true");
    return TRUE;
  }
  else {
 return FALSE;
  }
?>