

<form id='prc-adp-launch-form-<?php echo $node->nid ?>' action='<?php echo $full_path ?>' method='post'>
  <input type='hidden' name='testKey' value='<?php echo $test_key ?>' />
  <input type='hidden' name='name' value='' />
  <p>
  <a href="<?php echo url('practice-tests/'.$node->nid); ?>" class="prc-adp-launch-test-link">
    Computer-Based Item Set
  </a>
  </p>
</form>
