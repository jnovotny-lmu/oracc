#!/bin/sh
type=`oraccopt . type`
if [ "$type" == "portal" ]; then
    if [ -d 00web/00config ]; then
	echo calling esp2.sh `oraccopt` ...
	free -m
	esp2.sh `oraccopt`
	echo calling esp2-live.sh `oraccopt` force ...
	esp2-live.sh `oraccopt` force
    else
	oracc esp
	echo You now need to call: oracc esp live to make the rebuilt portal live online
    fi
else
    echo o2-portal.sh: I only work with portal projects
    exit 1
fi
