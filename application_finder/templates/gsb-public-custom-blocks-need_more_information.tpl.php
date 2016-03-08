<h4 ><?php print t('Need More Information?'); ?></h4>
<div >
  <?php if (!empty($cta)): ?>
    <?php foreach ($cta as $it => $itd): ?>
      <div class="cta-list" >
        <?php
        $parsed = parse_url($itd['url']);
        if ($parsed['scheme'] == 'http' || $parsed['scheme'] == 'https' ):
          print l(t($itd['title']), $itd['url'] , array('external' => TRUE ));
        else:
          print l(t($itd['title']), $itd['url']);
        endif;
        ?>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>