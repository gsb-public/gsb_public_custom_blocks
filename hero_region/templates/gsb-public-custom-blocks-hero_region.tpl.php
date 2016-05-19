<div class="hero-region-wrapper">
  <?php if (!empty($hero_region) && !empty($hero_region['image'])): ?>
      <?php print $hero_region['image']; ?>
  <?php endif; ?>
  <?php if (!empty($hero_region) && !empty($hero_region['slideshow'])): ?>
    <div class="hero-region-slideshow-wrapper">
      <?php print $hero_region['slideshow']; ?>
    </div>
  <?php endif; ?>
</div>