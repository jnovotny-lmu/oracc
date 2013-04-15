#!/bin/sh
umask 026
ORACC=/usr/local/oracc
ORACC_VAR=/var/local/oracc
ORACC_HOME=~/oracc-projects
ORACC_HOST=localhost
ORACC_MODE=single
ORACC_USER=no
export ORACC ORACC_VAR ORACC_HOME ORACC_HOST ORACC_MODE ORACC_USER
PATH=$PATH:$HOME/00bin:$ORACC/bin
export PATH
