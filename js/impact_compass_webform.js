(function ($) {

Drupal.behaviors.impact_compass_webform = {
  attach: function (context, settings) {
  $("#errorMessage").hide();
  //hiding print button for mobile and tablet
  if (Modernizr.mq('(max-width: 1024px)')) {
    $("#print_bt").hide();
  }
  setTimeout(function() {
   let company = $("#company").val();
   let society = $("#valueToSocietyScore").val();
   let efficacy = $("#efficacyScore").val();
   let impactMagnitude = $("#impactMagnitudeScore").val();
   let scalability = $("#scalabilityScore").val();
   let missionAlignment = $("#missionAlignmentScore").val();
   let esg = $("#esgScore").val();
     var ctx = document.getElementById("myChart").getContext("2d");
     Chart.defaults.global.defaultFontSize = "20";
     Chart.defaults.global.defaultFontFamily = "NewsGothicBT","Avant Garde","Futura","Helvetica Neue","Helvetica,Arial,sans-serif";
      var myChart = new Chart(ctx, {
          type: "radar",
          data: {
              labels: ["Value to Society", "Efficacy", "Impact Magnitude", "Scalability", "Mission Alignment", "ESG"],
              datasets: [{
                  backgroundColor: "rgba(93,132,159, 0.2)",
                  borderColor: "rgb(93,132,159)",
                  pointBackgroundColor: "rgba(0,0,0,0.5)",
                  pointHoverBorderColor: "rgba(255,0,0,1)",
                  pointHoverBackgroundColor: "rgba(255,0,0,0.5)",
                  data: [],
          }]
      },

    options: {
    legend: {
          display: false,
        position: "bottom",
        fontSize: 12
          },
          title: {
              display: false,
              text: "Impact Compass"
          },
          scale: {
              pointLabels: {
                  fontSize: 14,
              },

        ticks: {
            min: 0, 
            max: 3, 
          fixedStepSize: 1,
          beginAtZero: true, 
          fontSize: 12,
              }
          }
      }

    });

  }, 2000);

  // A function to get the url parameter.
  $.urlParam = function(name){
      var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
      if (results==null){
        return null;
      }
      else{
        return results[1] || 0;
      }
    }

    //Check if the values have been passed through the url.
    // Get the values from the url.
    let company = $.urlParam('company');
    let society = $.urlParam('society');
    let efficacy = $.urlParam('efficacy');
    let impactMagnitude = $.urlParam('impactMagnitude');
    let scalability = $.urlParam('scalability');
    let missionAlignment = $.urlParam('missionAlignment');
    let esg = $.urlParam('esg');


    if (!company || !society || !efficacy || !impactMagnitude || !scalability || !missionAlignment || !esg) {
      // Do nothing if any value is not provided.
    }
    else {

      // Set the values in the form.
      $('#company').val(company);
      $("select[name='valueToSocietyScore']").val(society);
      $("select[name='efficacyScore']").val(efficacy);
      $("select[name='impactMagnitudeScore']").val(impactMagnitude);
      $("select[name='scalabilityScore']").val(scalability);
      $("select[name='missionAlignmentScore']").val(missionAlignment);
      $("select[name='esgScore']").val(esg);

      // render the chart
      renderChart();
    }

    /**
     * Renders the chart if the visualize button is clicked.
     */
    $('#submitButton').click(function(e) {
      e.preventDefault();
      // render the chart
      renderChart();
    });

    /**
     * Print pdf functionality
     */
    $('#print_bt').click(function (e) {
       e.preventDefault();
       $("#button-block").hide();
       $(".chart-container").css({"width": "95%", "height": "60%"});
       $(".chart-score").css({"text-align": "left","padding-left": "100px"});
       $("#imapct-compass-container").printThis({
            debug: false,               // show the iframe for debugging
            importCSS: true,            // import parent page css
            importStyle: true,         // import style tags
            printContainer: true,       // print outer container/$.selector
            loadCSS: "", // path to additional css file - use an array [] for multiple
            pageTitle: "",              // add title to print page
            removeInline: false,        // remove inline styles from print elements
            removeInlineSelector: "*",  // custom selectors to filter inline styles. removeInline must be true
            printDelay: 333,            // variable print delay
            header: null,               // prefix to html
            footer: null,               // postfix to html
            base: false,                // preserve the BASE tag or accept a string for the URL
            formValues: true,           // preserve input/form values
            canvas: true,              // copy canvas content
            doctypeString: '',       // enter a different doctype for older markup
            removeScripts: false,       // remove script tags from print content
            copyTagClasses: false,      // copy classes from the html & body tag
            beforePrintEvent: null,     // function for printEvent in iframe
            beforePrint: null,          // function called before iframe is filled
            afterPrint: null            // function called before iframe is removed
        });
       setTimeout(function() {
        $("#button-block").show();
        $(".chart-score").css({"text-align": "center","padding-left": "0px"});
       }, 2000);

    });

    /**
     * Render the chart.
     */
    function renderChart() {

      // Get the form variables and do error checking.
      let $errors = $('#errors');
      $errors.empty();
       
      let company = $('#company').val();
      if (!company) {
        $errors.append("Company or Opportunity is required.<br />");
      }

      let society = $("select[name='valueToSocietyScore']").val();
      //console.log(society);
      if (society == '') {
        console.log(society);
        $errors.append('Value to Society is required.<br />');
      }

      let efficacy = $("select[name='efficacyScore']").val();
      if (efficacy == '') {
        $errors.append('Efficacy is required.<br />');
      }

      let impactMagnitude = $("select[name='impactMagnitudeScore']").val();
      if (impactMagnitude == '') {
        $errors.append('Impact Magnitude is required.<br />');
      }

      let scalability = $("select[name='scalabilityScore']").val();
      if (scalability == '') {
        $errors.append('Scalability is required.<br />');
      }

      let missionAlignment = $("select[name='missionAlignmentScore']").val();
      if (missionAlignment == '') {
        $errors.append('Mission Alignment is required.<br />');
      }

      let esg = $("select[name='esgScore']").val();
      if (esg == '') {
        $errors.append('ESG is required.<br />');
      }
      if ($errors.text()) {
        /*jQuery('html, body').animate({
            scrollTop: 0
        }, 'slow');*/
        $("#errorMessage").show();
        return;
      }
      $("#errorMessage").hide();
      // Calculate the impact score.
      // Render the chart.
      let ctx = document.getElementById("myChart").getContext("2d");
      Chart.defaults.global.defaultFontSize = '20';
      Chart.defaults.global.defaultFontFamily = '"NewsGothicBT","Avant Garde","Futura","Helvetica Neue",Helvetica,Arial,sans-serif';
      var myChart = new Chart(ctx, {
        type: 'radar',
        data: {
          labels: ["Value to Society", "Efficacy", "Impact Magnitude", "Scalability", "Mission Alignment", "ESG"],
          datasets: [{
            backgroundColor: 'rgba(93,132,159, 0.2)',
            borderColor: 'rgb(93,132,159)',
            pointBackgroundColor: 'rgba(0,0,0,0.5)',
            pointHoverBorderColor: 'rgba(255,0,0,1)',
            pointHoverBackgroundColor: 'rgba(255,0,0,0.5)',
            data: [society, efficacy, impactMagnitude, scalability, missionAlignment, esg],
          }]
        },

        options: {
          legend: {
            display: false,
            position: 'bottom',
            fontSize: 12
          },
          title: {
            display: false,
            text: 'Impact Compass'
          },
          scale: {
            pointLabels: {
              fontSize: 14,
            },

            ticks: {
              min: 0,
              max: 3,
              fixedStepSize: 1,
              beginAtZero: true,
              fontSize: 12,
            }
          }
        }

      });
      //myChart.update();

      // Set the impact score
      let impactScore = parseInt(society) * parseInt(efficacy) * parseInt(impactMagnitude) * parseInt(scalability) * parseInt(missionAlignment) * parseInt(esg);
      $('#impactText').text(company + ' has an Impact Potential Score of: ' );
      $('#impactScore').text(' '+impactScore);
      // Push the new url parameters to the page.
      /*if (history.pushState) {
        const newURL = new URL(window.location.href);
        newURL.search = '?company=' + company + '&society=' + society + '&efficacy=' + efficacy + '&impactMagnitude=' +
          impactMagnitude + '&scalability=' + scalability + '&missionAlignment=' + missionAlignment + '&esg=' + esg;
        window.history.replaceState({ path: newURL.href }, '', newURL.href);
      }*/
    }
   
  }
};

})(jQuery);