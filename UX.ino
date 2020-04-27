void setUX(){
  /*
  /DESKTOP UI 23/01/2016  - P. Diaz
  */
  server.on("/desktop", [](){
  
    // Prepare the UI response for desktop client
  String html = "<!doctype html>\r\n"
"<html lang=\"es\">\r\n"
"<head>\r\n"
"  <meta charset=\"utf-8\">\r\n"
"   <title>Descangallado - Live</title>\r\n"
"   <link rel=\"stylesheet\" href=\"//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css\">\r\n"
"   <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js\"></script>\r\n"
"   <script src=\"//code.jquery.com/ui/1.11.4/jquery-ui.js\"></script>\r\n"
"   <script src=\"https://combinatronics.com/dmauro/Keypress/development/keypress-2.1.5.min.js\"></script>\r\n"
"   <script src=\"https://combinatronics.com/josepedrodiaz/Rover_NodeMCU/master/js/ux.js\"></script>\r\n"
"  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\" integrity=\"sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==\" crossorigin=\"anonymous\">\r\n"
"  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css\" integrity=\"sha384-aUGj/X2zp5rLCbBxumKTCw2Z50WgIr1vs/PFN4praOTvYXWlVyh2UtNUU0KAUhAX\" crossorigin=\"anonymous\">\r\n"
"  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js\" integrity=\"sha512-K1qjQ+NcF2TYO/eI3M6v8EiNYZfA95pQumfvcVrTHtwQVDG+aHRqLi/ETn2uB+1JqwYqVG3LIvdm9lj6imS/pQ==\" crossorigin=\"anonymous\"></script>\r\n"
"</head>\r\n"
"<body style=\"background-color:rgba(0,0,0,0.6)\">\r\n"
"<br /><br /><br /><br /><br /><br /><h1 align=\"center\" style=\"color:#03a9f4\">Dale que so' vo!!</h1>"
"     <!-- <iframe width=\"100%\" src=\"http://pedrodiaz.no-ip.org:8081\" id=\"ifm\"  frameBorder=\"0\"></iframe> -->\r\n"
"     <script languaje=\"JavaScript\">\r\n"
"      var buffer = 20; //scroll bar buffer\r\n"
"      //var iframe = document.getElementById('ifm');\r\n"
"      function pageY(elem) {\r\n"
"          return elem.offsetParent ? (elem.offsetTop + pageY(elem.offsetParent)) : elem.offsetTop;\r\n"
"      }\r\n"
"      function resizeIframe() {\r\n"
"          var height = document.documentElement.clientHeight;\r\n"
"          height -= pageY(document.getElementById('ifm'))+ buffer ;\r\n"
"          height = (height < 0) ? 0 : height;\r\n"
"          //document.getElementById('ifm').style.height = height + 'px';\r\n"
"      }\r\n"
"      //if (iframe.attachEvent) {\r\n"
"        //  iframe.attachEvent('onload', resizeIframe);\r\n"
"      //} else {\r\n"
"        //  iframe.onload=resizeIframe;\r\n"
"      //}\r\n"
"      //window.onresize = resizeIframe;\r\n"
"  var listener = new window.keypress.Listener();\r\n"
"  var ajaxRunning;\r\n"
"$(function() {\r\n"
"      $('#statusDiv').hide();//by default, hide ajax alert\r\n"
"$( \"#battLevelInfo\" ).click(function() {\r\n"
"if(ajaxRunning != true){\r\n"
"        $('#statusDiv').show();\r\n"
"        ajaxRunning = true;\r\n"    
"        $.ajax({type: 'GET',\r\n"
"                    url: 'battCheck'\r\n,"
"                    success:function(data, textStatus) {\r\n"
"                        $('#statusDiv').hide();\r\n"
"                        ajaxRunning = false;\r\n"
"                        $('#battLevelInfo').html(data);\r\n"
"                      },\r\n"
"                        error: function() {\r\n"
"                        alert('Algo anduvo mal');\r\n"
"                        }\r\n"
"                    });\r\n"
"      }\r\n"
"});\r\n"
"function sendCommand(command){  \r\n"
"      if(ajaxRunning != true){\r\n"
"        $('#statusDiv').show();\r\n"
"        ajaxRunning = true;\r\n"    
"        $.ajax({type: 'GET',\r\n"
"                    url: command\r\n,"
"                    success:function() {\r\n"
"                        $('#statusDiv').hide();\r\n"
"                        ajaxRunning = false;\r\n"
"                      },\r\n"
"                        error: function() {\r\n"
"                        alert('Algo anduvo mal');\r\n"
"                        }\r\n"
"                    });\r\n"
"      }\r\n"
"}\r\n"

"  function frena() {\r\n"
"    sendCommand('frena')\r\n"
"   }\r\n"
"  //SERVOS \r\n"
"  listener.simple_combo('shift left', function() {\r\n"
"    sendCommand('servoHorizontal/l')\r\n"
"    });\r\n"
"  listener.simple_combo('shift right', function() {\r\n"
"    sendCommand('servoHorizontal/r')\r\n"
"    });\r\n"
"  listener.simple_combo('shift up', function() {\r\n"
"    sendCommand('servoVertical/up')\r\n"
"    });\r\n"
"  listener.simple_combo('shift down', function() {\r\n"
"    sendCommand('servoVertical/down')\r\n"
"    });\r\n"
"  listener.simple_combo('up', function() {\r\n"
"    sendCommand('adelante')\r\n"
"    });\r\n"

"  listener.simple_combo('left', function() {\r\n"
"    sendCommand('izquierda')\r\n"
"    });\r\n"
"  listener.simple_combo('right', function() {\r\n"
"    sendCommand('derecha')\r\n"
"    });\r\n"
"  listener.simple_combo('down', function() {\r\n"
"    sendCommand('atras')\r\n"
"    });\r\n"
"  listener.simple_combo('l', function() {\r\n"
"    sendCommand('loco-izuierda')\r\n"
"    });\r\n"
"  listener.simple_combo('r', function() {\r\n"
"    sendCommand('loco-derecha')\r\n"
"    });\r\n"
"  listener.simple_combo('space', function() {\r\n"
"    frena();\r\n"
"  });\r\n"
"});\r\n"
"</script>\r\n"
"<div id=\"statusDiv\" style=\"color: rgb(255, 235, 59);margin-left: 45%;margin-top: 50px;\">Enviando...</div>\r\n"
"<!-- <button type=\"button\" id=\"checkBatt\"> Nivel de bater&iacute;a</button> -->\r\n"
"<!-- <div id=\"battLevelInfo\"></div> -->\r\n"
"  <script>\r\n"
"    (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){\r\n"
"    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),\r\n"
"    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)\r\n"
"    })(window,document,'script','//www.google-analytics.com/analytics.js','ga');\r\n"
"    ga('create', 'UA-49589151-1', 'no-ip.org');\r\n"
"    ga('send', 'pageview');\r\n"
"  </script>\r\n"
"</body>\r\n"
"</html>\r\n";
//END UI RESPONSE

  server.send(200, "text/html", html);
  });
}
