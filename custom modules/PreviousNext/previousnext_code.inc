<?php

/* 
 To find the listo of nid of type gallery form node table
 */

function previousnext_list()
{
  
$query = db_select('node', 'n')
   ->fields('n', array('nid','created'))
   ->condition('type', 'gallery')
->orderBy('created', 'DESC');//ORDER BY created
 $results = $query->execute()->fetchAll();
$prev_nid=NULL;
$timestamp=0;
$mykeys=array_keys($results);
$numb=count($results);
foreach ($results as $key=>$values)
{
  if($key>0)
  {
  $prev = $results[$key-1]->nid;
 
   }
$cur=$values->nid;
$create=$values->created;
if($key<$numb)
{
  $next=$results[$key+1]->nid;
}
$mypath[$key]['previous']=$prev;
$mypath[$key]['curent']=$cur;
$mypath[$key]['created']=$create;
$mypath[$key]['next']=$next;
$ans=db_insert('gallery_nid')->fields(array('previous' => $prev,'current' =>$cur,'next' =>$next,'created' =>$create))->execute();
}
print("<pre>");
print_r($mypath);

}