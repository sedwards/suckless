#define _POSIX_C_SOURCE 200809L

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <dirent.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CONVERTER "smu"
#define LEN(x) (sizeof(x) / sizeof *(x))
#define TITLE_MAX 1024
#define TITLE_DEFAULT "suckless.org"
#define DIR_MAX 1024

char *html_header =
	"<!doctype html>\n"
	"<html>\n"
	"<head>\n"
	"	<meta charset=\"utf-8\">\n"
	"	<title>%s | suckless.org software that sucks less</title>\n"
	"	<link rel=\"stylesheet\" type=\"text/css\" href=\"//suckless.org/pub/style.css\">\n" \
	"</head>\n"
	"\n"
	"<div id=\"header\">\n"
	"	<a href=\"//suckless.org/\"><img src=\"//suckless.org/logo.svg\"/></a>\n"
	"	<a id=\"headerLink\" href=\"//suckless.org/\">suckless.org</a>\n"
	"	<span id=\"headerSubtitle\">%s</span>\n"
	"</div>\n";

char *html_nav_bar =
	"<span class=\"right\">\n"
	"	<a href=\"//dl.suckless.org\">download</a>\n"
	"	<a href=\"//git.suckless.org\">source</a>\n"
	"</span>\n";

char *html_footer = "<div id=\"footer\">\n"
	"<span class=\"right\">\n"
	"&copy; 2006-2018 suckless.org community\n"
	"| <a href=\"//ev.suckless.org/impressum\">Impressum</a>\n"
	"| <a href=\"//ev.suckless.org\">e.V.</a>\n"
	"</span>\n"
	"</div>\n";

char *domain_list[] = {
	"home.suckless.org",
	"dwm.suckless.org",
	"st.suckless.org",
	"core.suckless.org",
	"surf.suckless.org",
	"tools.suckless.org",
	"libs.suckless.org",
	NULL
};

void
die_perror(char *msg, ...)
{
	va_list ap;
	char *s;

	va_start(ap, msg);
	while ((s = va_arg(ap, char *)))
		fputs(s, stdout);
	fputs(": ", stdout);
	perror(NULL);
	exit(1);
}

void
die(char *msg, ...)
{
	va_list ap;
	char *s;

	va_start(ap, msg);
	while ((s = va_arg(ap, char *)))
		fputs(s, stdout);
	fputc('\n', stdout);
	exit(1);
}

int
stat_isdir(char *f)
{
	struct stat s;

	if (stat(f, &s) == -1) {
		perror(f);
		return 0;
	}
	return (s.st_mode & S_IFMT) == S_IFDIR;
}

int
stat_isfile(char *f)
{
	struct stat s;

	if (stat(f, &s) == -1) {
		perror(f);
		return 0;
	}
	return (s.st_mode & S_IFMT) == S_IFREG;
}

int
spawn_wait(char **argv)
{
        int status;

        switch (fork()) {
	case 0:
		execvp(argv[0], argv);
		exit(126);
	case -1:
		return -1;
        }
	if (wait(&status) == -1)
		return -1;

        return WIFEXITED(status) ? 0 : -1;
}

int
oneline(char *value, size_t len, char const *path)
{
	char *r = 0;
	FILE *fp;

	if (!(fp = fopen(path, "r"))) return perror(path), -1;
	r = fgets(value, len, fp);
	fclose(fp);

	return !!r;
}

int
dirname(char *path)
{
	char *s;

	if (!(s = strrchr(path, '/')))
		return -1;
	*s = '\0';
	return 0;
}

void
print_name(char *name)
{
	char *from = "_-", *to = "  ", *s;

	for (;*name; ++name) {
		if ((s = strchr(from, *name)) != NULL)
			putchar(to[s - from]);
		else
			putchar(*name);
	}
}

void
subdir(char *newdir, size_t len, char *base, char *add)
{
	*newdir = '\0';
	if (base) {
		strncat(newdir, base, len - 1); newdir[len - 1] = '\0';
		strncat(newdir, "/", len - 1); newdir[len - 1] = '\0';
	}
	strncat(newdir, add, len - 1); newdir[len - 1] = '\0';
}

void
print_header(char *domain, char *page)
{
	char title_file[PATH_MAX];
	char title[TITLE_MAX];
	(void)domain;

	if (oneline(title, sizeof title, ".title") <= 0)
		printf(html_header, TITLE_DEFAULT, TITLE_DEFAULT);
	else
		printf(html_header, title, title);
}

void
print_nav_bar(char *domain, char *page)
{
	char name[1024];
	char *s;
	char **d;
	(void)page;

	puts("<div id=\"menu\">");
	for (d = domain_list; *d; ++d) {
		fputs("\t<a ", stdout);
		if (strcmp(domain, *d) == 0)
			fputs("class=\"thisSite\" ", stdout);

		printf("href=\"//%s\">", *d);
		strncpy(name, *d, sizeof name - 1); name[sizeof name - 1] = '\0';
		if ((s = strchr(name, '.'))) {
			*s = '\0';
			fputs(name, stdout);
		}
		fputs("</a>\n", stdout);
	}

	puts("</div>");
}

int
qsort_strcmp(const void *a, const void *b)
{
	return strcmp(*(char **)a, *(char **)b);
}

void
menu_panel(char *domain, char *page, char *this)
{
	DIR *dp;
	struct dirent *de;
	char *d_list[DIR_MAX];
	char **d;
	size_t d_len = 0;

	if ((dp = opendir(this ? this : ".")) == NULL)
		die_perror("opendir ", this ? this : ".", NULL);

	while (d_len < LEN(d_list) && (de = readdir(dp)))
		d_list[d_len++] = de->d_name;
	d_list[d_len] = NULL;

	qsort(d_list, d_len, sizeof *d_list,
		&qsort_strcmp);

	for (d = d_list; *d != NULL; ++d) {
		int match;
		char newdir[PATH_MAX];

		if (**d == '.') continue;
		subdir(newdir, sizeof newdir, this, *d);
		if (!stat_isdir(newdir)) continue;

		fputs("\t<li><a", stdout);
		if (page && !strncmp(newdir, page, strlen(newdir)))
			fputs(" class=\"thisPage\"", stdout);
		printf(" href=\"//%s/%s\">", domain, newdir);
		print_name(*d);
		fputs("/</a>", stdout);
		if (page && !strncmp(newdir, page, strlen(newdir))) {
			puts("\t<ul>");
			menu_panel(domain, page, newdir);
			puts("\t</ul>");
		}
		puts("</li>");
	}
}

void
print_menu_panel(char *domain, char *page)
{
	char *s;

	fputs("<div id=\"nav\">\n\t<ul>\n\t<li><a", stdout);
	if (!page)
		fputs(" class=\"thisPage\"", stdout);
	puts(" href=\"/\">about</a></li>");
	menu_panel(domain, page, NULL);

	puts("\t</ul>");
	puts("</div>");
}

void
print_content(char *domain, char *page)
{
	char index[PATH_MAX];

	subdir(index, sizeof index, page, "index.md");

	puts("<div id=\"main\">\n");

	if (stat_isfile(index)) {
		char *argv[] = { CONVERTER, index, NULL };
		fflush(stdout);
		if (spawn_wait(argv) == -1)
			die_perror(CONVERTER, domain, "/", page, "/", index, NULL);
	}
	puts("</div>\n");
}

void
print_footer(char *domain, char *page)
{
	(void)domain;
	(void)page;
	fputs(html_footer, stdout);
}

int
main(int argc, char *argv[])
{
	char *domain;
	char *page;

	if (argc != 2)
		die("usage: ", argv[0], " directory");
	if ((page = strchr(argv[1], '/')))
		*page++ = '\0';
	domain = argv[1];
	if (chdir(domain) == -1)
		return perror(domain), 1;

	print_header(domain, page);
	puts("<div id=\"content\">");
	print_nav_bar(domain, page);
	print_menu_panel(domain, page);
	print_content(domain, page);
	puts("</div>\n");
	print_footer(domain, page);

	return 0;
}
