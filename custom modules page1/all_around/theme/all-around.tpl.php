<?php
$jsdata = '';

$image_field_default = get_image_field_key_name($items[0]);

function get_image_field_key_name($param) {
  $image_field_key = '';

  foreach ($param->_field_data['nid']['entity'] as $key => $value) {

    if (gettype($value) == 'array') {

      if (isset($param->_field_data['nid']['entity']->{$key}['und'][0]['uri']) && !empty($param->_field_data['nid']['entity']->{$key}['und'][0]['uri'])) {
        if (isset($param->_field_data['nid']['entity']->{$key}['und'][0]['filemime']) && !empty($param->_field_data['nid']['entity']->{$key}['und'][0]['filemime']) && strstr($param->_field_data['nid']['entity']->{$key}['und'][0]['filemime'], 'image')) {
          $image_field_key = $key;
        }
      }
    }
  }
  return $image_field_key;
}

foreach ($items as $key => $rows) {
  if(isset($rows->_field_data['nid']['entity']->title) && !empty($rows->_field_data['nid']['entity']->title)) {
    $get_title = $rows->_field_data['nid']['entity']->title;
  }

  $title = $get_title;
  $nid = $rows->_field_data['nid']['entity']->nid;
  $body = $rows->_field_data['nid']['entity']->body['und'][0]['value'];
  $image = $rows->_field_data['nid']['entity']->{$image_field_default}['und'][0]['uri'];

  $newval[$key]['title'] = $title;
  if (isset($body)) {
    $newval[$key]['body'] = $body;
  }
  $newval[$key]['nid'] = $nid;

  $path = $imagepath = file_create_url($image);
  $jsdata .= "{image: '" . $path . "', link_rel: 'prettyPhoto'},";
}
?>

<script type="text/javascript">
  jQuery(document).ready(function () {
      var image_array = new Array();
      image_array = [<?php echo $jsdata; ?>];
      jQuery('#slider1').content_slider({
          map: image_array,
          max_shown_items: 5,
          responsive_by_available_space: 1,
          hv_switch: 0,
          active_item: 4,
          middle_click: 1,
          border_radius: 0,
          mode: 2,
          dinamically_set_position_class: 1,
          border_on_off: 0
      });
  });

</script>





<div class="content_slider_wrapper" id="slider1">
    <?php foreach ($newval as $key => $val): ?>
      <div class="circle_slider_text_wrapper" id="<?php print 'sw' . $key; ?>" style="display: none;">
          <div class="content_slider_text_block_wrap">
              <h3><?php echo l($val['title'], "node/" . $val['nid'], array('attributes' => array('class' => array('attorney-slider', 'attorney-title')))); ?></h3>
              <div>
                  <?php
                  if (isset($val['body'])) {
                    print substr(strip_tags($val['body']), 0, 200);
                    if (strlen($val['body']) > 200) {
                      print '....';
                    }
                  }
                  ?></div>
              <?php echo l('Learn More', "node/" . $val['nid'], array('attributes' => array('class' => 'button_regular'), 'html' => true)); ?>
          </div>
      </div>
    <?php endforeach; ?>
</div>