(function($) {
	var PrcTrt = {
		progressBar: null,
		progressBarLabel: null,

		init: function() {
			this.progressBar = $('#trtProgressBar');
			this.progressBarLabel = $('#trtProgressBarLabel');
			this.progressBar.progressbar({
				value: 0
			});
			this.progressBarLabel.text('0%');
		},

		executeTest: function() {
			$('#trtInProgress').show();

			// execute tests

			$('#trtInProgress').hide();
			$('#trtResults').show();
		},

		setProgress: function(valueComplete) {
			this.progressBar.progressbar('value', valueComplete);
			this.progressBarLabel.text(valueComplete + '%');
		}
	};

	$(window).bind('load', function() {
		PrcTrt.init();
		PrcTrt.executeTest();		
	});
})(jQuery);
