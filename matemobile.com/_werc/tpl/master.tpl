<!doctype html>
<html>
<head> 
	<title>%($pageTitle%)</title>
	<link rel="stylesheet" type="text/css" href="/pub/style.css">
	<meta charset="utf-8"> 
</head> 
<body>
	<div id="header">
		<a href="/">%($"siteTitle%)</a> <span id="headerSubtitle">%($"siteSubtitle%)</span>
	</div>

	<div id="menu">
		<span class="right">
			<a href="http://suckless.org">suckless.org</a>
			<a href="http://eyjafjallajoekull.com">art</a>
		</span>
	</div>

	<div id="content">
% if(! ~ $#handlers_bar_left 0) {
	<div id="nav">
%   for(h in $handlers_bar_left) {
%       run_handler $$h
%   }
	</div>
% }

	<div id="main">

% run_handlers $handlers_body_head

% run_handler $handler_body_main

% run_handlers $handlers_body_foot

	</div>

	</div>

	<div id="footer">
	<span class="right">
	&copy; 2012 matemobile | <a href="http://garbe.us/Contact">Impressum</a>
	</span>
	</div>
</body>
</html>