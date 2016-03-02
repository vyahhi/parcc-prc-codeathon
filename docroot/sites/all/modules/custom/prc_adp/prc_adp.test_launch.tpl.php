

<form id='prc-adp-launch-form' action='<?php echo $full_path ?>' method='post'>
  <input type='hidden' name='testKey' value='<?php echo $test_key ?>' />
  <input type='hidden' name='name' value='' />
</form>


<script type="application/javascript">
  jQuery(document).ready(
    function(){
      jQuery("#prc-adp-launch-form").submit();
    }
  );
</script>