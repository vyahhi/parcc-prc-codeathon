<footer role="contentinfo">
  <div id="footer-wrapper" class="row">

    <?php if ($site_name) :?>
      <div id="footer-copyright" class="medium-6 large-4 columns">
        <p>Copyright &copy; <?php print date('Y') . '. ' . t('All rights reserved.'); ?> <br><a href = "<?php
          global $base_url;
          $tos_url = $base_url . '/content/terms-use';
          print $tos_url;
          ?>">Terms of Use</a><br>
        <a href = "<?php
        global $base_url;
        $tos_url = $base_url . '/content/user-generated-content-disclaimer';
        print $tos_url;
        ?>">User Generated Content Disclaimer</a></p>
      </div>
    <?php endif; ?>
    <div id="footer-contact" class="medium-6 large-4 columns">
      <p>Comments, questions, help, call us at <a href="tel:18668452110">1-866-845-2110</a><br />
        or email us at
        <a href="mailto:prc-questions@parcconline.org">prc-questions@parcconline.org</a>.</p>
    </div>
    <div id="footer-social" class="hide-for-medium-down large-4 columns">
      <a href = "https://www.facebook.com/PARCC" class="facebook" title="PARCC Facebook">Facebook</a>
      <a href = "https://twitter.com/parccplace" class="twitter" title="PARCC Twitter">Twitter</a>
    </div>
  </div>
</footer>