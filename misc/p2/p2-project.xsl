<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
		xmlns="http://www.w3.org/1999/xhtml"
		xmlns:xh="http://www.w3.org/1999/xhtml"
		xmlns:xforms="http://www.w3.org/2002/xforms"
		xmlns:xs="http://www.w3.org/2001/XMLSchema"
		xmlns:ev="http://www.w3.org/2001/xml-events"
		xmlns:xpd="http://oracc.org/ns/xpd/1.0"
		exclude-result-prefixes="xh"
		>

<xsl:include href="xpd.xsl"/>

<xsl:param name="project"/>

<xsl:variable name="oracc-home" select="'/usr/local/oracc/'"/>
<xsl:variable name="oracc-server" select="'http://oracc.museum.upenn.edu/'"/>
<xsl:variable name="project-data" 
	      select="concat('/usr/local/oracc/xml/',$project,'/project-data.xml')"/>
<xsl:variable name="config-xml" 
	      select="document(concat('/usr/local/oracc/www/',$project,'/config.xml'))"/>
<xsl:variable name="project-abbrev"
	      select="$config-xml/*/xpd:abbrev"/>

<xsl:variable name="nth-child" 
	      select="'.pll .value select option:nth-child('"/>
<xsl:variable name="border-top"
	      select="') { border-top: 1px solid red; }&#xa;'"/>

<xsl:output method="xml" encoding="utf-8" omit-xml-declaration="yes" indent="yes"/>

<xsl:template match="xh:html">
<!--  <xsl:processing-instruction name="xml-stylesheet"
			      >href="/xsltforms/xsltforms/xsltforms.xsl" type="text/xsl"</xsl:processing-instruction> -->
<!--  <xsl:processing-instruction name="xsltforms-options"
			      >debug="yes"</xsl:processing-instruction>
  <xsl:text>&#xa;</xsl:text> -->
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xsl:apply-templates/>
  </xsl:copy>
</xsl:template>

<xsl:template match="xh:head">
  <xsl:copy>
    <xsl:apply-templates/>
    <xsl:call-template name="pll-css"/>
  </xsl:copy>
</xsl:template>

<xsl:template match="xh:p[@class='glossaries']|xh:span[contains(@class,'glossaries')]">
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xforms:select1 ref="instance('browse')/glossary">
      <xforms:item>
	<xforms:label>Glossaries</xforms:label>
	<xforms:value>#none</xforms:value>
      </xforms:item>
      <xsl:for-each select="document($project-data)//glossary">
	<xforms:item>
	  <xforms:label><xsl:value-of select="."/></xforms:label>
	  <xforms:value><xsl:value-of select="@abbrev"/></xforms:value>
	</xforms:item>
      </xsl:for-each>
      <xforms:action ev:event="xforms-value-changed"
		     if="instance('browse')/glossary[not(.='#none')]">
	<xforms:send submission="post-glossary"/>
      </xforms:action>
      <xforms:action ev:event="xforms-value-changed"
		     if="instance('browse')/glossary[.='#none']">
	<xforms:setvalue ref="instance('pager')/glossary" value="''"/>
	<xforms:send submission="post-browse"/>
      </xforms:action>
    </xforms:select1>
  </xsl:copy>
</xsl:template>

<xsl:template match="xh:p[@class='outline-sorter']|xh:span[@class='outline-sorter']">
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xsl:copy-of select="document($project-data)//outline-sorters/*"/>
  </xsl:copy>
</xsl:template>

<xsl:template match="xh:span[@class='translations']">
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xforms:select1 ref="instance('pager')/translation">
      <xforms:label/>
      <xforms:itemset nodeset="choose(instance('pager')/transonly[.='false'],
			              instance('private')/notrans, 
				      instance('private')/no-such-node)">
	<xforms:label ref="@l"/>
	<xforms:value ref="@v"/>
      </xforms:itemset>
      <xsl:for-each select="document($project-data)//lang">
	<xforms:item>
	  <xforms:label><xsl:value-of select="."/></xforms:label>
	  <xforms:value><xsl:value-of select="@abbrev"/></xforms:value>
	</xforms:item>
      </xsl:for-each>
      <xforms:action ev:event="xforms-value-changed"
		     if="instance('pager')/item > 0">
	<xforms:send submission="post-pager"/>
      </xforms:action>
    </xforms:select1>
  </xsl:copy>
</xsl:template>

<xsl:template match="xh:span[@class='pll']|xh:span[contains(@class,'pll')]">
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xforms:select1 ref="instance('private')/pll">
      <xforms:label/>
      <xforms:item>
	<xforms:label><xsl:value-of select="$project-abbrev"/></xforms:label>
	<xforms:value><xsl:value-of select="concat($oracc-server,$project,'/')"/></xforms:value>
      </xforms:item>
      <xforms:item>
	<xforms:label>Oracc Home</xforms:label>
	<xforms:value><xsl:value-of select="$oracc-server"/></xforms:value>
      </xforms:item>
      <xsl:for-each select="document($project-data)/*/projects/project">
	<xforms:item>
	  <xforms:label><xsl:value-of select="@menu"/></xforms:label>
	  <xforms:value><xsl:value-of select="concat($oracc-server,@proj,'/')"/></xforms:value>
	</xforms:item>
      </xsl:for-each>
      <xsl:for-each select="document($project-data)/*/lists/list">
	<xforms:item>
	  <xforms:label><xsl:value-of select="@menu"/></xforms:label>
	  <xforms:value><xsl:value-of select="concat($oracc-server,$project,'/',@file)"/></xforms:value>
	</xforms:item>
      </xsl:for-each>
      <xsl:for-each select="document($project-data)/*/links/link">
	<xforms:item>
	  <xforms:label><xsl:value-of select="@menu"/></xforms:label>
	  <xforms:value><xsl:value-of select="@url"/></xforms:value>
	</xforms:item>
      </xsl:for-each>
      <xforms:action ev:event="xforms-value-changed"
		     if="instance('private')/pll[not(.='#none')]">
	<xforms:load>
	  <xforms:resource value="instance('private')/pll"/>
	</xforms:load>
      </xforms:action>
    </xforms:select1>
  </xsl:copy>
</xsl:template>

<xsl:template match="*">
  <xsl:copy>
    <xsl:copy-of select="@*"/>
    <xsl:apply-templates/>
  </xsl:copy>
</xsl:template>

<xsl:template name="pll-css">
  <style type="text/css">
    <xsl:text>.pll .value select option { border-bottom: 1px solid red; }&#xa;</xsl:text>
<!--
    <xsl:text>.pll .value select option:nth-child(3) { border-top: 1px solid red; }&#xa;</xsl:text>
    <xsl:call-template name="pll-lists-nth"/>
    <xsl:call-template name="pll-links-nth"/>
 -->
</style><xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template name="pll-lists-nth">
  <xsl:if test="count(document($project-data)/*/projects/project) > 0">
    <xsl:variable name="nth" select="2 + count(document($project-data)/*/projects/project)"/>
    <xsl:value-of select="concat($nth-child,$nth, $border-top)"/>
  </xsl:if>
</xsl:template>

<xsl:template name="pll-links-nth">
  <xsl:if test="count(document($project-data)/*/projects/project) > 0
		+ count(document($project-data)/*/lists/list) > 0">
    <xsl:variable name="nth" select="2 + count(document($project-data)/*/projects/project)
				     + count(document($project-data)/*/lists/list)"/>
    <xsl:value-of select="concat($nth-child,$nth, $border-top)"/>
  </xsl:if>
</xsl:template>

<!--
.pll .value select option:nth-child(1),
.pll .value select option:nth-child(2),
.pll .value select option:nth-child(3)
 { border-bottom: 1px solid red; }
 -->
</xsl:stylesheet>