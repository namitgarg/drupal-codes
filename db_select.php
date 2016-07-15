   $subquery = db_select('comment','c');
   
     $subquery->join('field_data_comment_body', 'cb', 'c.cid = cb.entity_id');
     $subquery->fields('c', array('cid','nid', 'subject'))
              ->fields('cb', array('entity_id','comment_body_value'));
    
	$results = $subquery->execute()->fetchAll();