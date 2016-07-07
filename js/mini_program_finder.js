(function ($) {
  Drupal.behaviors.minifinder = {
    attach: function (context, settings) {

          var $miniFilterCheckboxes = $('#mini-program-finder select.isotopify-filter-checkboxes');
          var $miniFilterDateRange = $('.isotopify-filter-daterange');
          //var $miniFilterDateRange = $('.form-type-textfield');
          //Handle checkboxes
          if ($miniFilterCheckboxes.length) {
            // Remove unused filter options. This needs to ru
            $miniFilterCheckboxes.each(function () {
              var checkedOptions = [];
              var $select = $(this);
              $select.find('option').each(function () {
                $option = $(this);

                // Also check if the checkbox is checked to set defaults.
                if ($option.is(':checked')) {
                  checkedOptions.push($option.val());
                }
              });

              // If we have checked checkboxes the set the defaults.
              // Use the label for the placeholder and hide it.
              var $label = $select.prev('label');
              $label.hide();

              var multipleSelectOptions = {
                width: 180,
                maxHeight: 300,
                selectAll: false,
                minimumCountSelected: 0,
                countSelected: $label.text(),
                placeholder: $label.text()
              }

              if ($select.hasClass('isotopify-multiple')) {
                multipleSelectOptions.multiple = true;
                multipleSelectOptions.multipleWidth = 220;
              }

              // Add the multipleSelect library
              $select.multipleSelect(multipleSelectOptions);
              var $applyButton = $('<button class="checkbox-apply">' + Drupal.t('Done') + '</button>').click(function (e) {
                e.preventDefault();
                var choices = $select.multipleSelect("getSelects");
                $select.parent().find('button.ms-choice').click();
              });

              var $clearAllButton = $('<button class="checkbox-clear-all">Clear All</button>').click(function (e) {
                e.preventDefault();
                $select.multipleSelect('uncheckAll');
              });

              var $dropdown = $select.next().find('.ms-drop');
              // $dropdown.append($applyButton);
              //$dropdown.append($clearAllButton);
            });
          }
          /**
           * Handle daterange
           */
          if ($miniFilterDateRange.length) {

            // Add the button to the page.
            title = "Date Range";
            var $miniFilterDateRangeButton = $('<button class="mini-filter-daterange-button">' + title + '</button>');

            if ($(".mini-filter-daterange-button").length == 0) {
              $miniFilterDateRange.append($miniFilterDateRangeButton);
            }
            $miniFilterDateRangeButton.click(function (e) {
              e.preventDefault();
            });

            $miniFilterDateRange.find('.form-type-textfield').hide();

            // Get the current range
            var minDate = null;
            var maxDate = null;
            minDate = Drupal.settings.minifinder.start_date;
            maxDate = Drupal.settings.minifinder.end_date;
            $miniFilterDateRangeButton.dateRangePicker({
              startDate: minDate,
              endDate: maxDate,
              hoveringTooltip: false,
              singleMonth: false,
              stickyMonths: true,
              customTopBar:  "Select a Start Date",
              setValue: function (s) {
              }
            }).bind('datepicker-first-date-selected', function(event, obj) {
              /* This event will be triggered when first date is selected */

              $("div.custom-top").show();
              $("div.custom-top").text("Select an End Date");

            }).bind('datepicker-change', function (event, obj) {
              /* This event will be triggered when second date is selected */

              if (obj.value == '1969-12-31 to 1969-12-31' || obj.date1 == 'Invalid Date' || obj.date2 == 'Invalid Date') {
                $("#edit-date-range-to").val('');
                $("#edit-date-range-from").val('');
              }
              else {
                /* This event will be triggered when user done selecting dates */
                var date1 = new Date(obj.date1);
                var beginDateRange = Drupal.minifinder.convertDateObj(date1);
                var date2 = new Date(obj.date2);
                var endDateRange = Drupal.minifinder.convertDateObj(date2);
                $("#edit-date-range-to").val(endDateRange);
                $("#edit-date-range-from").val(beginDateRange);
                var formattedStartDate = Drupal.minifinder.convertDateObjFormat(date1);
                var formattedEndDate = Drupal.minifinder.convertDateObjFormat(date2)
                $miniFilterDateRangeButton.text( formattedStartDate + ' - ' + formattedEndDate );
                $("div.custom-top").hide();
              }

            }).click(function (e) { // Close picker if the button is clicked when it's opened
              e.preventDefault();
              if ($(this).hasClass('open')) {
                $(this).data('dateRangePicker').close();
              }


            }).bind('datepicker-opened', function () { // Add classes when the picker is opened
              $(this).removeClass('closed');
              $("div.custom-top").text("Select a Start Date");
              $("div.custom-top").show();
              $(this).addClass('open');
            }).bind('datepicker-closed', function () { // Add classes when the picker is closed
              $(this).removeClass('open');
              $(this).addClass('closed');
            });

            // Move the close button.
            $('.date-picker-wrapper .drp_top-bar').not(':last').remove();
            $('.apply-btn').remove();
          }

          // date formatter
          Drupal.minifinder = Drupal.minifinder || {};

          Drupal.minifinder.convertDateObj = function (date) {
            var dateYear = date.getFullYear();
            var dateYearStr = dateYear.toString();
            var dateMonth = date.getMonth() + 1;
            var dateMonthStr = dateMonth.toString();
            if (dateMonthStr.length == 1) {
              dateMonthStr = '0' + dateMonthStr;
            }
            var dateDay = date.getDate();
            var dateDayStr = dateDay.toString();
            if (dateDayStr.length == 1) {
              dateDayStr = '0' + dateDayStr;
            }
            return dateYearStr + dateMonthStr + dateDayStr;
          }
          Drupal.minifinder.convertDateObjFormat = function (date) {
            var dateYear = date.getFullYear();
            var dateYearStr = dateYear.toString();
            var dateMonth = date.getMonth() + 1;
            var dateMonthStr = dateMonth.toString();
            if (dateMonthStr.length == 1) {
              dateMonthStr = '0' + dateMonthStr;
            }
            var dateDay = date.getDate();
            var dateDayStr = dateDay.toString();
            if (dateDayStr.length == 1) {
              dateDayStr = '0' + dateDayStr;
            }

            return  dateMonthStr + '/' +  dateDayStr + '/' + dateYearStr ;
          }
        }
      }
  })(jQuery);
