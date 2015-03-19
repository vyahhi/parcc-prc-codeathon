<footer role="contentinfo">
  <div id="footer-wrapper" class="row">
    <?php if (!empty($page['footer'])): ?>
      <!--<div class="footer large-12 columns">
        <?php // print render($page['footer']); ?>
      </div> -->
    <?php endif; ?>

    <?php if ($site_name) :?>
      <div id="footer-copyright" class="small-6 large-4 columns">
        <p>&copy; <?php print date('Y') . ' ' . check_plain($site_name) . ' ' . t('All rights reserved.'); ?> Lorem ipsum  dolor sit amet, consectetur adipiscing elit Aenean euismod bibendum la Proin gravida dolor sit amet lacus accumsan. <a href = "#">Terms of Use</a></p>
      </div>
    <?php endif; ?>
    <div id="footer-contact" class="small-6 large-4 columns">
      <p><span class="uppercase">Contact PARCC</span><br />
      info@EmailAddress.com<br />
      !+ 000.000.000</p>
    </div>
    <div id="footer-social" class="show-for-medium-up large-4 columns">
      <p>Social</p>
    </div>
  </div>
</footer>