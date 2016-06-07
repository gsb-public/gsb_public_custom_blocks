<?php if (!empty($hero_region) && !empty($hero_region['image'])): ?>
  <div class="hero-region-wrapper">
    <?php print $hero_region['image']; ?>
  </div>
<?php endif; ?>
<?php if (!empty($hero_region) && !empty($hero_region['slideshow'])): ?>
  <div class="hero-region-wrapper">
    <div class="hero-region-slideshow-wrapper">
      <?php print $hero_region['slideshow']; ?>
    </div>
  </div>
<?php endif; ?>
