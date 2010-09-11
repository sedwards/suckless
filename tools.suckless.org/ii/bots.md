Its very easy to write shell script based bots with ii. As a short example look at this:

    tail -f \\#<CHANNEL>/out |  
    while read foo ; do  
        name=$(echo $foo | awk '{print $2}' | sed 's,<\\(.*\\)>,\\1,')  
        if awk 'BEGIN{srand(); exit rand()<.1)}' ; then  
            echo "$name: WHAT??" ;  
        fi;  
    done

Its just spamming a channel but I guess your imagination is boundless.
I also heard about people using it together with nagios to get the notifications into IRC.
Remember to strip input for example with tr(1), tr -cd "0-9a-zA-Z" for example would only allow numbers and characters.

If you want to see a live demonstration of a bot written for ii, join #grml on freenode, the grml-tips bot which searches
for [grml](http://www.grml.org) tips and gives a link or error messages is written in 45 lines of /bin/sh. No, I will not publish
the code since I really suck in shell programming :)

Stat scripts
------------

If you want to use for example [pisg](http://pisg.sf.net/) to generate channel stats this will also work if you choose the irssi log format.

Automatic reconnects
--------------------

If you want some kind of automatic reconnects in ii you can make a something like this in a shell script:

    while true; do  
        ii -s irc.oftc.net -n iifoo -f "John Doe"  
        iipid=$!  
        sleep 5  
        echo "/j #ii" > ~/irc/irc.oftc.net/in  
        while [[ -e /proc/$iipid ]]; do  
            sleep 30  
        done  
    done  

bots for irc it (ii)
====================

nagios
------

Simple Perl script "nagios_post.pl" as interface between [Nagios](http://www.nagios.org/) and ii:

    #!/usr/bin/perl -w

    my $users = "your_nickname(s)";
    my $pipe = "$ENV{HOME}/irc/your_irc_server/#your_channel/in";
    my %color = (
       red    => "\0034",
       purple => "\0036",
       yellow => "\0038",
       clear  => "\00315",
       blue   => "\0032\002",
       green  => "\0033",
       normal => "\0031",
       );

    open(PIPE, '>', $pipe) or die "Can't write to $pipe: $!";
    while (<>) {
          s/Host [a-z0-9_.]+ is down/$color{red}$&$color{normal}/i;
          s/PROBLEM.*?CRITICAL/$color{red}$&$color{normal}/i;

          s/PROBLEM.*?WARNING/$color{yellow}$&$color{normal}/i;
          s/Host [a-z0-9_.]+ is up/$color{green}$&$color{normal}/i;

          s/RECOVERY.*?OK/$color{green}$&$color{normal}/i;

          print PIPE "$users: $_";
    }
    close(PIPE);

The appropriate Nagios configuration looks like this:

    # 'notify-by-irc' command definition
    define command{
            command_name    notify-by-irc
            command_line    /usr/bin/printf "%b" "$TIME$ $NOTIFICATIONTYPE$ $HOSTNAME$/$SERVICEDESC$ $SERVICESTATE$ $SERVICEOUTPUT$\n" | /home/nagios/bin/nagios_post.pl 
           }

    # 'host-notify-by-irc' command-notification
    define command{
            command_name    host-notify-by-irc
            command_line    /usr/bin/printf "%b" "$TIME$ Host $HOSTALIAS$ is $HOSTSTATE$ -- $HOSTOUTPUT$\n" | /home/nagios/bin/nagios_post.pl
           }

Start ii appropriately and add notify-by-irc and host-notify-by-irc to the appropriate "service&#x5f;notification&#x5f;commands" and "host&#x5f;notification&#x5f;commands" -- and you have your own Nagios IRC bot.

rsstail
-------

Just piping the output of [rsstail](http://www.vanheusden.com/rsstail/) into the fifo "in" should work. More detailed examples are welcome.