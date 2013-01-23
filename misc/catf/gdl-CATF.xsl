<?xml version='1.0' encoding='utf-8'?>

<xsl:stylesheet version="1.0" 
  xmlns:g="http://oracc.org/ns/gdl/1.0"
  xmlns:x="http://oracc.org/ns/xtf/1.0"
  xmlns:c="http://oracc.org/ns/xcl/1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text" indent="no" encoding="utf-8"/>

<!-- GDL -->

<xsl:template match="g:a">
  <xsl:text>~</xsl:text>
  <xsl:apply-templates/>
</xsl:template>

<xsl:template match="g:b|g:r|g:s|g:v">
  <xsl:call-template name="g-begin"/>
  <xsl:apply-templates/>
  <xsl:call-template name="g-end"/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template mode="no-breakage" match="g:b|g:r|g:s|g:v">
  <xsl:apply-templates/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template match="g:c">
  <xsl:call-template name="g-begin"/>
  <xsl:text>|</xsl:text>
  <xsl:apply-templates mode="no-breakage"/>
  <xsl:text>|</xsl:text>
  <xsl:call-template name="g-end"/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template match="g:d">
  <xsl:text>{</xsl:text>
  <xsl:call-template name="g-begin"/>
  <xsl:apply-templates/>
  <xsl:call-template name="g-end"/>
  <xsl:text>}</xsl:text>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template match="g:f">
  <!-- Form variants (rarely used sub-sub-glyph-form tags) are dropped in C-ATF -->
</xsl:template>

<xsl:template match="g:g">
  <xsl:text>(</xsl:text>
  <xsl:apply-templates/>
  <xsl:text>)</xsl:text>
</xsl:template>

<xsl:template match="g:m">
  <xsl:text>@</xsl:text>
  <xsl:apply-templates/>
</xsl:template>

<xsl:template match="g:n">
  <xsl:call-template name="g-begin"/>
  <xsl:call-template name="g-n"/>
  <xsl:call-template name="g-end"/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template mode="no-breakage" match="g:n">
  <xsl:call-template name="g-n"/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template name="g-n">
  <xsl:choose>
    <xsl:when test="g:b">
      <xsl:for-each select="g:b">
        <xsl:apply-templates select="g:r"/>
        <xsl:text>(</xsl:text>
        <xsl:apply-templates select="*[2]"/>
	<xsl:apply-templates select="g:a|g:m"/>
        <xsl:text>)</xsl:text>
      </xsl:for-each>
     </xsl:when>
    <xsl:otherwise>
      <xsl:apply-templates select="g:r"/>
      <xsl:text>(</xsl:text>
      <xsl:apply-templates select="*[2]"/>
      <xsl:text>)</xsl:text>
    </xsl:otherwise>
  </xsl:choose>
  <xsl:apply-templates select="g:a|g:m"/>
</xsl:template>

<xsl:template match="g:o">
  <xsl:choose>
    <xsl:when test="@type='beside'"><xsl:text>.</xsl:text></xsl:when>
    <xsl:when test="@type='joining'"><xsl:text>+</xsl:text></xsl:when>
    <xsl:when test="@type='containing'"><xsl:text>×</xsl:text></xsl:when>
    <xsl:when test="@type='above'"><xsl:text>&amp;</xsl:text></xsl:when>
    <xsl:when test="@type='crossing'"><xsl:text>%</xsl:text></xsl:when>
    <xsl:when test="@type='opposing'"><xsl:text>@</xsl:text></xsl:when>
    <xsl:when test="@type='repeated'">
      <xsl:value-of select="concat(.,'x')"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:message>gdl-CATF: <xsl:value-of select="@type"/> not handled</xsl:message>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="g:prox">
  <!-- Proximity notations are dropped in CATF -->
</xsl:template>

<xsl:template match="g:q">
  <xsl:apply-templates select="*[1]"/>
  <xsl:text>(</xsl:text>
  <xsl:apply-templates select="*[2]"/>
  <xsl:text>)</xsl:text>
</xsl:template>

<xsl:template match="g:gg|n:g">
  <xsl:choose>
    <xsl:when test="@type='correction'">
    </xsl:when>
    <xsl:when test="@type='alternation'">
      <xsl:for-each select="*">
	<xsl:apply-templates select="."/>
	<xsl:if test="not(position()=last())">
	  <xsl:text>/</xsl:text>
	</xsl:if>
      </xsl:for-each>
    </xsl:when>
    <xsl:when test="@type='group'">
      <xsl:text>(</xsl:text>
      <xsl:apply-templates/>
      <xsl:text>)</xsl:text>
    </xsl:when>
    <xsl:when test="@type='reordering'">
      <xsl:for-each select="*">
	<xsl:apply-templates select="."/>
	<xsl:if test="not(position()=last())">
	  <xsl:text>:</xsl:text>
	</xsl:if>
      </xsl:for-each>
    </xsl:when>
    <xsl:when test="@type='ligature'">
      <xsl:for-each select="*">
	<xsl:apply-templates select="."/>
	<xsl:if test="not(position()=last())">
	  <xsl:text>+</xsl:text>
	</xsl:if>
      </xsl:for-each>
    </xsl:when>
    <xsl:when test="@type='logo'">
      <!-- drop grouping in ATF -->
      <xsl:apply-templates/>
    </xsl:when>
    <xsl:otherwise>
      <!-- TODO: implicit-ligature -->
      <xsl:message>gdl-CATF.xsl: can't handle g:gg with type=<xsl:value-of select="@type"/></xsl:message>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- TODO: split-word support -->
<xsl:template match="g:w">
  <xsl:choose>
    <xsl:when test="preceding-sibling::* and following-sibling::*">
      <xsl:if test="not(@xml:lang) = preceding-sibling::*[@xml:lang][1]/@xml:lang">
	<xsl:call-template name="lang-switch"/>
      </xsl:if>
    </xsl:when>
    <xsl:when test="count(preceding-sibling::*) = 0">
      <xsl:call-template name="lang-switch"/>
    </xsl:when>
    <xsl:otherwise> <!-- last word -->
      
    </xsl:otherwise>
  </xsl:choose>
  <xsl:apply-templates/>
  <xsl:choose>
    <xsl:when test="preceding-sibling::*[@xml:lang]">
      <xsl:if test="not(@xml:lang) = preceding-sibling::*[@xml:lang][1]/@xml:lang">
	<xsl:call-template name="lang-close"/>
      </xsl:if>
    </xsl:when>
    <xsl:when test="count(following-sibling::*[@xml:lang])=0">
      <xsl:if test="not(@xml:lang) = preceding-sibling::*[@xml:lang][1]/@xml:lang">
	<xsl:call-template name="lang-close"/>
      </xsl:if>
    </xsl:when>
    <xsl:otherwise>
      <xsl:call-template name="g-delim"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="g:nonw">
  <xsl:choose>
    <xsl:when test="@type='comment' or @type='dollar'">
      <!-- inline comments and dollar-lines are dropped in CATF -->
    </xsl:when>
    <xsl:when test="@type='excised'">
      <xsl:text>&lt;&lt;</xsl:text>
      <xsl:apply-templates/>
      <xsl:text>&gt;&gt;</xsl:text>
    </xsl:when>
    <xsl:otherwise>
      <xsl:message>gdl-CATF.xsl: can't handle g:nonw with type=<xsl:value-of select="@type"/></xsl:message>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="g:*">
  <xsl:message>gdl-CATF: unhandled GDL tag <xsl:value-of select="name()"/></xsl:message>
  <xsl:apply-templates/>
</xsl:template>

<!-- TODO:
  g-surro suport
 -->
<xsl:template name="g-begin">
  <xsl:value-of select="@g:o"/>
</xsl:template>

<!-- Varnum is dropped in CATF -->
<!-- Notemarks are dropped in CATF -->
<xsl:template name="g-end">
  <xsl:call-template name="g-status-flags"/>
  <xsl:choose>
    <xsl:when test="string-length(@g:c)>0">
      <xsl:value-of select="@g:c"/>
    </xsl:when>
    <xsl:when test="@g:break='damaged'">
      <xsl:value-of select="'#'"/>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="g-delim">
  <xsl:choose>
    <xsl:when test="@g:delim='--'">
      <!-- Double-hyphen delimiters (sometimes used to separate name segments) are rendered as single hyphens in C-ATF. -->
      <xsl:text>-</xsl:text>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="@g:delim"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="g-status-flags">
  <xsl:if test="@g:collated = 'yes' or g:collated='true'">
    <xsl:text>*</xsl:text>
  </xsl:if>
  <xsl:if test="@g:queried = 'yes' or g:queried='true'">
    <xsl:text>?</xsl:text>
  </xsl:if>
  <xsl:if test="@g:remarked = 'yes' or g:remarked='true'">
    <xsl:text>!</xsl:text>
  </xsl:if>
</xsl:template>

<!-- NORM -->
<!--TODO: check how words, segs and flags interact -->
<xsl:template match="n:w">
  <xsl:apply-templates/>
  <xsl:call-template name="g-delim"/>
</xsl:template>

<xsl:template match="n:s">
  <xsl:call-template name="g-begin"/>
  <xsl:apply-templates/>
  <xsl:call-template name="g-end"/>
</xsl:template>

<!-- n:g merged with template for g:gg -->

<xsl:template match="n:word-group">
  <xsl:for-each select="*">
    <xsl:apply-templates/>
    <xsl:if test="not(position()=last())">
      <xsl:text>/</xsl:text>
    </xsl:if>
  </xsl:for-each>
</xsl:template>

<xsl:template match="n-grouped-word">
  <xsl:apply-templates/>
</xsl:template>

<!-- XTF -->

<xsl:template match="x:protocols">
</xsl:template>

<xsl:template match="x:transliteration">
  <xsl:value-of select="concat('&amp;',@xml:id,' = ',@n,'&#xa;')"/>
  <xsl:apply-templates/>
</xsl:template>

<xsl:template match="x:composite">
  <!-- Composites are dropped in CATF -->
</xsl:template>

<xsl:template match="x:score">
  <!-- Scores are dropped in CATF -->
</xsl:template>

<xsl:template match="x:sealing">
  <xsl:value-of select="'@sealing', ' ', @n, '&#xa;'"/>
</xsl:template>

<xsl:template match="x:object">
  <xsl:value-of select="concat('@',@type')"/>
  <xslif test="@type='object'">
    <xsl:value-of select="concat(' ',@n)"/>
  </xslif>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template match="x:surface">
  <xsl:value-of select="concat('@',@type')"/>
  <xsl:choose>
    <xsl:when test="@type='surface'">
      <xsl:value-of select="concat(' ',@n)"/>
    </xsl:when>
    <xsl:when test="@type='fragment' or @type='seal'">
      <xsl:value-of select="concat(' ',@n)"/>
    </xsl:when>
  </xsl:choose>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template match="x:column">
  <xsl:value-of select="concat('@',@type')"/>
  <xslif test="@type='object'">
    <xsl:value-of select="concat(' ',@n)"/>
  </xslif>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template match="x:cmt|x:note"/>

<xsl:template match="x:lg">
  <xsl:apply-templates/>
</xsl:template>

<xsl:template match="x:l">
  <xsl:choose>
    <xsl:when test="bil">
      <xsl:text>==</xsl:text><xsl:value-of select="@xml:lang"/><xsl:text> </xsl:text>
    </xsl:when>
    <xsl:when test="nts">
      <xsl:text>=. </xsl:text>
    </xsl:when>
    <xsl:when test="lgs">
      <xsl:text>=: </xsl:text>
    </xsl:when>
    <xsl:when test="gus">
      <!-- Gloss-underneath lines are dropped in CATF -->
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="concat(@label, '. ')"/>
    </xsl:otherwise>
  </xsl:choose>
  <xsl:apply-templates/>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template match="x:m">
  <xsl:choose>
    <xsl:when test="@type='discourse'">
      <xsl:text>@</xsl:text>
      <xsl:if test="@endflag='1'">
	<xsl:text>end </xsl:text>
      </xsl:if>
      <xsl:value-of select="concat(@subtype, '&#xa;')"/>
    </xsl:when>
    <xsl:when test="@subtype='fragment'">
      <xsl:value-of select="concat('@fragment ', text(), '&#xa;')"/>
    </xsl:when>
    <xsl:when test="@type='division'">
      <xsl:value-of select="concat('@div ',@subtype,' ',@n,' ',text(),'&#xa;')"/>
    </xsl:when>
    <xsl:when test="@type='locator'">
      <xsl:value-of select="concat('@m=locator ',@subtype,' ',@n,' ',text(),'&#xa;')"/>      
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template match="x:nonx|nonl">
  <xsl:call-template name="x-non-whatever"/>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template match="x:nong">
  <xsl:call-template name="x-non-whatever"/>
</xsl:template>

<xsl:template name="x-non-whatever">
  <xsl:choose>
    <xsl:when test="starts-with(., '(')">
      <xsl:apply-templates/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:text>(</xsl:text>
      <xsl:apply-templates/>
      <xsl:text>)</xsl:text>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="x:v|x:ag">
  <!-- Variants are dropped in CATF -->
  <!-- Alignment groups are dropped in CATF -->
</xsl:template>

<xsl:template match="x:*">
  <xsl:message>gdl-OATF: xtf:<xsl:value-of select="name()"/> not handled</xsl:message>
  <xsl:apply-templates/>  
</xsl:template>

</xsl:stylesheet>