<header role="banner" id="header">

  <div class="contain-to-grid">
    <nav class="top-bar">
      <ul class="title-area">
        <li class="name">
          <?php if ($logo): ?>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
          <?php endif; ?>
        </li>
        <li class="toggle-topbar menu-icon"><a href="#"><span></span></a></li>
      </ul>

      <?php if ($main_menu): ?>
        <section id="main-menu-section" class="top-bar-section">
          <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => 'left'))); ?>
        </section>
      <?php endif; ?>

      <div id="header-icons">
        <?php if ($secondary_menu): ?>
          <section id="secondary-menu-section" class="top-bar-section">
            <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => 'right'))); ?>
          </section>
        <?php endif; ?>
        <?php print render($page['header']); ?>
      </div>

    </nav> <!-- /.top-bar -->
  </div> <!-- /.contain-to-grid -->

  </header> <!-- /#header -->