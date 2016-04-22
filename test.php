
<?php
$iPod = stripos($_SERVER['HTTP_USER_AGENT'],"iPod");
$iPhone = stripos($_SERVER['HTTP_USER_AGENT'],"iPhone");
$iPad = stripos($_SERVER['HTTP_USER_AGENT'],"iPad");
$Android= stripos($_SERVER['HTTP_USER_AGENT'],"Android");
$webOS= stripos($_SERVER['HTTP_USER_AGENT'],"webOS");
$webMOS= stripos($_SERVER['HTTP_USER_AGENT'],"Windows Phone");
$nid=arg(1);
$node=node_load(arg(1));
$type=$node->type;

if(!( $iPod || $iPhone || $Android || $webOS || $webMOS)&& !(drupal_is_front_page()) && $type!='attorney') {
 return TRUE;
}
else{
return FALSE;
}