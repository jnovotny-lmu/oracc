include ../../oracc-am-rules.txt

bin_SCRIPTS = install-00bin.sh mk-wrapper.plx un-perl-hex.plx \
	create-single.sh delete-single.sh

mk-wrapper.plx: mk-wrapper.plx.in
	$(ORACCIFY) mk-wrapper.plx.in

install-00bin.sh: install-00bin.sh.in
	$(ORACCIFY) install-00bin.sh.in

EXTRA_DIST = \
	install-00bin.sh.in \
	mk-wrapper.plx.in \
	un-perl-hex.plx
