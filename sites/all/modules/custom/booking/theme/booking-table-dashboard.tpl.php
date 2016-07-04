<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/21/16
 * Time: 9:29 PM
 * To change this template use File | Settings | File Templates.
 */
?>
<table>
  <tr>
    <?php foreach($weeks as $key => $week): ?>
    <th><?php print $week; ?> <?php print date('d/m/Y'); ?></th>
    <?php endforeach; ?>
  </tr>
</table>