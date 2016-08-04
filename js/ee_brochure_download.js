(function ($) {

Drupal.behaviors.ee_brochure_download = {
  attach: function (context, settings) {

    var data = settings.ee_brochure_download_settings.program_info;

    var total_downloads = data.length;
    var products = [];

    for (var index = 0; index < data.length; index++) {
      products[products.length] = {
        'sku': data[index].apowerid,
        'name': data[index].title,
        'category': 'PDF Download',
        'price': 1,
        'quantity': 1
      }
    }

    var rnd_tran_id = new Date().getTime();
    dataLayer.push({
      'transactionId': rnd_tran_id,
      'transactionAffiliation': 'Stanford GSB',
      'transactionTotal': total_downloads,
      'transactionTax': '0',
      'transactionShipping': '0',
      'transactionCity': '',               // city; do not use
      'transactionState': '',              // state or province; do not use
      'transactionCountry': '',            // country; do not use! !
      'transactionProducts': products
    });
    dataLayer.push({'event': 'trackTrans'});

  }
};

})(jQuery);