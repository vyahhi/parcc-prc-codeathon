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
      <p>1747 Pennsylvania Avenue NW<br>
        6th Floor<br>
        Washington, DC 20006<br>
        Phone: 202-748-8100<br>
        Email: <a href="mailtp:questions@parcconline.org">questions@parcconline.org</a></p>
    </div>
    <div id="footer-social" class="hide-for-medium-down large-4 columns">
      <a href = "https://www.facebook.com/PARCC" title="PARCC Facebook"><img src="/<?php print path_to_theme(); ?>/images/facebook-icon.png" alt="Facebook"></a>
      <a href = "https://twitter.com/parccplace" title="PARCC Twitter"><img src="/<?php print path_to_theme(); ?>/images/twitter-icon.png" alt="Twitter"></a>
    </div>
  </div>
</footer>