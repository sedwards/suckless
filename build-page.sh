#!/bin/sh -e

# Given a directory name, generate a static page out of:
# - ./**/index.md - the markdown files.
# - ./title - the title of the website.
# - ./domains - file with one domain per line (corresponding to ./<domain>/)
# - ./*/title - one file per subdirectory with the subtitle.


## setup ##

page="$1/index.md"
this_domain="${page%%/*}"

domain_list='
	home.suckless.org
	dwm.suckless.org
	st.suckless.org
	core.suckless.org
	surf.suckless.org
	tools.suckless.org
	libs.suckless.org
'


## functions ##

#1 current page
#2 directory to list
nav() {
	ls "$2" | while IFS= read dir
	do
		test -d "$2/$dir" || continue
		expr "$1" : "$2/$dir/." >/dev/null &&
			match=' class="thisPage"' ||
			match=
		printf '<li><a%s href="%s">' "$match" "//$2/$dir/"
		printf '%s/</a>' "$dir" | tr _- '  '
		if test "$match"
		then
			printf '<ul>\n'
			nav "$1" "$2/$dir"
			printf '</ul>\n'
		fi
		printf '</li>\n'
	done
}


## header ##

test -f "$page" &&
	title=$(sed 's,^#* *,,; q' "$page") ||
	title=$(basename "$(dirname "$page")")

cat <<EOF
<!doctype html>
<html>
<head>
	<meta charset="utf-8">
	<title>$title | suckless.org software that sucks less</title>
	<link rel="stylesheet" type="text/css" href="//suckless.org/pub/style.css">
</head>

<div id="header">
	<a href="//suckless.org/"><img src="//suckless.org/logo.svg"/></a>
	<a id="headerLink" href="//suckless.org/">suckless.org</a>
	<span id="headerSubtitle">$subtitle</span>
</div>
EOF


## nav bar ##

printf '<div id="menu">\n'
for domain in $domain_list
do
	printf '<a '
	test "$this_domain" = "$domain" && printf 'class="thisSite" '
	printf 'href="%s">%s</a>\n' "//$domain" "${domain%%.*}"
done

cat <<EOF
<span class="right">
	<a href="//dl.suckless.org">download</a>
	<a href="//git.suckless.org">source</a>
</span>
EOF

printf '</div>\n\n'


printf '<div id="content">\n\n'


## menu panel ##

printf '<div id="nav">\n<ul>\n<li><a'
test "${page%/*}" = "$this_domain"  && printf ' class="thisPage"'
printf ' href="/">about</a></li>'
nav "$page" "$this_domain"
printf '</ul>\n</div>\n\n'


## content ##

printf '<div id="main">\n'
if test -f "$page"
then
	smu < "$page"
else
	printf '<ul>\n'
	ls "${page%/index.md}" | while IFS= read -r dir
	do
		path=${page%/index.md}/$dir/
		test -d "$path" || continue
		printf '<li><a href="%s">' "//$path"
		printf '%s</a></li>\n' "$dir" | tr _- '  '
	done
	printf '</ul>\n'
fi
printf '</div>\n\n'


printf '</div>\n\n' # end of id="content"


## footer ##

cat <<EOF
<div id="footer">
<span class="right">
&copy; 2006-2018 suckless.org community
| <a href="//ev.suckless.org/impressum">Impressum</a>
| <a href="//ev.suckless.org">e.V.</a>
</span>
</div>
EOF
