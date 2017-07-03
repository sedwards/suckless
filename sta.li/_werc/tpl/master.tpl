<!doctype html>
<html>
<head> 
	<title>%($pageTitle%)</title>
	<link rel="stylesheet" type="text/css" href="/pub/style.css">
	<meta charset="utf-8"> 
</head> 
<body>
	<div id="header">
		<a href="/"><img src="/logo.svg" /></a>
		<span id="headerSubtitle">static linux</span>
	</div>

	<div id="menu">
		<span class="left">
% if(~ $site 'suckless.org') {
		<a class="thisSite" href="http://suckless.org">home</a>
% }
% if not {
		<a href="http://suckless.org">home</a>
% }
% if(~ $site 'dwm.suckless.org') {
		<a class="thisSite" href="http://dwm.suckless.org">dwm</a>
% }
% if not {
		<a href="http://dwm.suckless.org">dwm</a>
% }
% if(~ $site 'st.suckless.org') {
		<a class="thisSite" href="http://st.suckless.org">st</a>
% }
% if not {
		<a href="http://st.suckless.org">st</a>
% }
% if(~ $site 'core.suckless.org') {
		<a class="thisSite" href="http://core.suckless.org">core</a>
% }
% if not {
		<a href="http://core.suckless.org">core</a>
% }
% if(~ $site 'sta.li') {
		<a class="thisSite" href="http://sta.li">stali</a>
% }
% if not {
		<a href="http://sta.li">stali</a>
% }
% if(~ $site 'surf.suckless.org') {
		<a class="thisSite" href="http://surf.suckless.org">surf</a>
% }
% if not {
		<a href="http://surf.suckless.org">surf</a>
% }
% if(~ $site 'tools.suckless.org') {
		<a class="thisSite" href="http://tools.suckless.org">tools</a>
% }
% if not {
		<a href="http://tools.suckless.org">tools</a>
% }
% if(~ $site 'libs.suckless.org') {
		<a class="thisSite" href="http://libs.suckless.org">libs</a>
% }
% if not {
		<a href="http://libs.suckless.org">libs</a>
% }
% if(~ $site 'ev.suckless.org') {
		<a class="thisSite" href="http://ev.suckless.org">e.V.</a>
% }
% if not {
		<a href="http://ev.suckless.org">e.V.</a>
% }
		</span>
		<span class="right">
			<a href="http://dl.sta.li">download</a>
			<a href="http://git.sta.li">source</a>
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
	&copy; 2010-2017 stali project @ suckless.org| <a href="http://garbe.us/Contact">Impressum</a>
	</span>
	</div>
</body>
</html>
