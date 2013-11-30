#!/bin/sh
PROG=oracc-server-web-pack.sh
project=$1
if [ ! -f $ORACC/www/$project/config.xml ]; then
    echo $PROG: 'must be run in an Oracc directory (no $ORACC/www/$project/config.xml). Stop.'
    exit 1
fi
cd $ORACC/$project
version=`cat .version`
if [ "$version" = "" ]; then
    echo $PROG: no .version file--run oracc version
    version=000
fi
u=`uname`
if [ "$uname" = "Darwin" ]; then
    COMPRESS=-y
else
    COMPRESS=-j
fi
destdir=$ORACC/www/runtimes ; mkdir -p $destdir
zip=web.tar.gz ; export zip
ziplist=$ORACC/$project/01tmp/web-files
sublist=$ORACC/$project/01tmp/subprojects
rm -f $zip
rm -f $ziplist.*
rm -f $sublist
# COPYFILE_DISABLE suppresses addition of ._* files under Mac OS X at least up
# to 10.8
COPYFILE_DISABLE=1 ; export COPYFILE_DISABLE

# Make list of sub projects: these will be omitted from web pack
(cd $ORACC/www/$project ; find . -maxdepth 2 -name config.xml | cut -d/ -f1-2 | grep -v ^./config.xml | sed s/^..// >$sublist)

# Make lists of files in each directory which will contribute to the pack
if [ -s $sublist ]; then
    for a in pub xml www ; do
	(cd $ORACC/$a/$project ; find . -type f | grep -v -f $sublist >$ziplist.$a)
    done
else
    for a in pub xml www ; do
	(cd $ORACC/$a/$project ; find . -type f >$ziplist.$a)
    done    
fi

# Merge lists so that each member is relative to $ORACC
for a in pub xml www ; do
    sed s,^.,$a/$project, <$ziplist.$a >>$ziplist.lst
done

# Add contents of texts generated in bld because the pack needs them as well
(cd $ORACC ; find bld/$project/[PQX][0-9][0-9][0-9] >>$ziplist.lst)

# Create runtime pack
fproj=`/bin/echo -n $project | tr / -`
(cd $ORACC ; tar --exclude www/$project/estindex -zcf $destdir/web-$fproj.tar.gz -T $ziplist.lst)

export version zip