include ../../oracc-am-rules.txt

bin_SCRIPTS = l2p2-g2c.plx l2p2-langs.plx l2p2-g2x.plx l2p2-rewrite-ids.plx l2p2-sig-g2a.plx \
	l2p2-sig-slicer.plx l2p2-union.plx l2p2.sh l2p2-letters.plx
scriptdata_DATA = cbd-super-periods.xsl cbd-usage-ids.xsl g2-articles.xsl g2-base-s.xsl \
	g2-primary-base.xsl g2-see-cpds.xsl g2-summaries.xsl l2p2-list-ids.xsl g2-periods.xsl \
	l2p2-xis-merge.xsl g2-toc-banner.xsl
config_DATA = l2p2.xcf 
data_DATA = dummy.xis

l2p2-g2c.plx: l2p2-g2c.plx.in
	$(ORACCIFY) l2p2-g2c.plx.in

l2p2-langs.plx: l2p2-langs.plx.in
	$(ORACCIFY) l2p2-langs.plx.in

g2-articles.xsl: g2-articles.xsl.in
	$(ORACCIFY) g2-articles.xsl.in

g2-periods.xsl: g2-periods.xsl.in
	$(ORACCIFY) g2-periods.xsl.in

EXTRA_DIST = \
	cbd-super-periods.xsl \
	cbd-usage-ids.xsl \
	g2-articles.xsl.in \
	g2-base-s.xsl \
	g2-primary-base.xsl \
	g2-see-cpds.xsl \
	g2-summaries.xsl \
	l2p2-g2c.plx.in \
	l2p2-g2x.plx \
	l2p2-langs.plx.in \
	l2p2-list-ids.xsl \
	l2p2-rewrite-ids.plx \
	l2p2-sig-g2a.plx \
	l2p2-sig-slicer.plx \
	l2p2-union.plx \
	l2p2.sh \
	l2p2.xcf
