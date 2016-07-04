<div class="filter-form-date">
  <?php $form = drupal_get_form('booking_form_date_filter'); ?>
  <?php print render($form) ?>
</div>
<div class="nw-week-wraper">
  <div class="nw-week-content"><?php print $data; ?></div>
  <div class="nw-week-paging">
    <?php if($page < $total_page): ?>
      <div class="nw-week-previous action-links" ><a class="nw-week-previous-action" href="javascript:void(0)"><?php print t('<< Tuần trước'); ?></a></div>
      <div class="nw-week-next action-links" data="1"><a class="nw-week-next-action" href="javascript:void(0)"><?php print t('Tuần tới >>'); ?></a></div>
    <?php endif; ?>
  </div>
  <span class="nw-week-current-page" data="<?php print $current_week; ?>"></span>
  <span class="nw-week-total-page" data="<?php print $total_page; ?>"></span>
</div>
<div class="clearfix"></div>

<div style="display: none;" class="loading"><img src="<?php print base_path().drupal_get_path('module','booking') ?>/images/loading7_orange.gif" width="80" height="auto"/></div>