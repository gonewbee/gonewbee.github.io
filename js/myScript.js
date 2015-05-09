
/* http://stackoverflow.com/questions/23709700/embed-tag-inside-bootstrap-modal-not-visible-in-firefox */
$('#button_modal').click(function () {
    /*$('#myModal').modal('show');*/
    $("#myModalLabel").text("雅少直播间");
    $("#live-modal-body").html("<iframe id='live_iframe' height=475 width=800 src='http://www.huomaotv.com/index.php?c=outplayer&live_id=15' frameborder=0 allowfullscreen></iframe>")
    $("#myModal").css("display", "block");
});
$('#button_modal2').click(function () {
    /*$('#myModal').modal('show');*/
    $("#myModalLabel").text("冷冷直播间");
    $("#live-modal-body").html("<embed src='http://staticlive.douyutv.com/common/share/play.swf?room_id=20360' quality='high' width='100%' height='550' align='middle' allowScriptAccess='always' allowFullScreen='true' mode='transparent' type='application/x-shockwave-flash'></embed>");
    $("#myModal").css("display", "block");
});
$('#button_close1, #button_close2').click(function () {
    $("#myModal").css("display", "none");
});
