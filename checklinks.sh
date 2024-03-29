#!/bin/sh
# check internal wiki links, uses md-printlinks.c

for t in */; do
find "$t" -name "*.md" -type f | while read -r f; do
	d=$(dirname "$f")
	b=$(basename "$f")

	./md-printlinks < "$f" | \
		grep -vE '^(http|https|gopher|irc|ircs|git)://' | \
		grep -vE '^\/\/(lists|dl|git|gunther|oldgit)\.' | \
		grep -vE '^mailto:' | \
		while read -r -- l; do

		# // relative
		p="${l#//}"
		if test x"$p" != x"$l"; then
			bp="${p%%/*}"
			# topmost dir doesn't exist, possibly // url to other site.
			if ! test -d "$bp"; then
				echo "$f	$l	$bp"
				continue
			fi
			path="$p"
		else
			p="${l#/}"
			if test x"$l" != x"$p"; then
				# prefix is "/", use topmost dir + path.
				path="$t/$l"
			else
				path="$d/$l"
			fi
		fi

		test -e "$path" || echo "$f	$l	$path"
	done
done
done
