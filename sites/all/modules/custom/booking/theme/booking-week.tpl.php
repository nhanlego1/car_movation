
<table class="table table-condensed table-bordered schedule-table">
  <tr>
    <?php foreach ($data as $day => $values): ?>
      <td class="header-week">
      <div class="label-day-week">
        <div class="title-calendar"><?php print booking_get_day_in_week(strtotime($day)); ?>  </div>
        <div class="date-week"><?php print  date('d M Y',strtotime($day)) ?></div>
      </div>
      <?php if (empty($values)): ?>
        <?php continue; ?>
        </td>
      <?php endif; ?>


      <?php foreach ($values as $key => $value): ?>
        <div class="row-task <?php if ($key % 2 == 0): ?> odd <?php else: ?> even <?php endif; ?>">
          <h4><?php print $value->booking_name; ?></h4>

          <div class="car-number"><strong><?php print car_get_number($value->cars_id); ?></strong>&nbsp;</div>
          <div class="driver">TX: <strong><?php print $value->driver; ?></strong>&nbsp;/
            &nbsp;<strong><?php print $value->phone; ?></strong></div>
          <div class="guide">HD: <strong><?php print $value->guide ?>&nbsp; /
              &nbsp;<?php print $value->guide_phone ?></strong></div>
          <div class="company-code">
            <div class="code"><?php print $value->tour_code; ?></div>
            <div class="company"><?php print company_get_name($value->company_id); ?></div>
          </div>

        </div>
      <?php endforeach; ?>

    <?php endforeach; ?>
  </tr>
</table>
<div class="mobile-template-wrapper">
  <ul class="calendar-wrapper">
    <?php foreach ($data as $date => $bookings): ?>
      <li class="date-list">
        <div class="date-item">
          <div class="title-calendar"><?php print booking_get_day_in_week(strtotime($date)); ?> - <?php print  date('d M Y',strtotime($day)) ?></div>
        </div>

        <?php foreach ($bookings as $key => $value): ?>
        <ul class="item-child <?php if ($key % 2 == 0): ?> odd <?php else: ?> even <?php endif; ?>">
            <li><h4><?php print $value->booking_name; ?></h4></li>
            <li class="car-number"><strong><?php print car_get_number($value->cars_id); ?></strong>&nbsp;</li>
            <li class="driver">TX: <strong><?php print $value->driver; ?></strong>&nbsp;/
              &nbsp;<strong><?php print $value->phone; ?></strong></li>
            <li class="car-name">Xe: <strong><?php print car_get_name($value->cars_id); ?></strong></li>
            <li class="guide">HD: <strong><?php print $value->guide ?>&nbsp; /
                &nbsp;<?php print $value->guide_phone ?></strong></li>
            <li class="company-code">
              <div class="code"><?php print $value->tour_code; ?></div>
              <div class="company"><?php print company_get_name($value->company_id); ?></div>
            </li>
        </ul>
        <?php endforeach; ?>

      </li>
    <?php endforeach; ?>
  </ul>
</div>

