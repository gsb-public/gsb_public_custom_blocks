<div class="header">Full-Time Degree Programs</div>
<div class="degree-programs-wrapper">
  <?php
  if (!empty($degree_programs)): ?>
    <?php foreach ($degree_programs as $it => $itd): ?>
      <div class="degree-program">
        <div class="title">
          <?php if (!empty($itd['link_url'])): ?>
            <?php print l(t($itd['title']), $itd['link_url']); ?>
          <?php else: ?>
            <?php print l(t($itd['title']), drupal_lookup_path('alias', "node/". $it)); ?>
          <?php endif; ?>
          <?php //print $itd['title']; ?>
        </div>
        <div class="intro">
          <?php print $itd['program_teaser']; ?>
        </div>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>