<button data-dropdown="drop" aria-controls="drop" aria-expanded="false" class="medium round button dropdown"><?php echo $dropdown_text ?></button><br>
<ul id="drop" data-dropdown-content class="f-dropdown" role="menu" aria-hidden="false" tabindex="-1">
<?php foreach ($items as $item): ?>
  <li><?php print $item; ?></li>
<?php endforeach; ?>
</ul>