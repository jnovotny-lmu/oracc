#include <string.h>
#include <stdlib.h>
const char * const cdf_rnc[] = {
  "#Concatenated cdf.rnc schema built by mk_cdfrnc_c.plx\n",
  "#See http://enlil.museum.upenn.edu/cdl/doc/CDF/ for more info\n",
  "default namespace = \"http://oracc.org/ns/xtf/1.0\"\n",
  "namespace n = \"http://oracc.org/ns/norm/1.0\"\n",
  "namespace xtr = \"http://oracc.org/ns/xtr/1.0\"\n",
  "namespace c = \"http://oracc.org/cdf/1.0\"\n",
  "namespace ci = \"http://oracc.org/cdf-inline/1.0\"\n",
  "namespace g = \"http://oracc.org/ns/gdl/1.0\"\n",
  "namespace syn = \"http://oracc.org/ns/syntax/1.0\"\n",
  "namespace xh = \"http://www.w3.org/1999/xhtml\"\n",
  "lV = xsd:string {\n",
  "   pattern = \"[aeiu]([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "lVCv = xsd:string {\n",
  "  pattern = \"([aeiu][\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz])+[aeiu]?([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "lCVc = xsd:string {\n",
  "  pattern = \"([\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz][aeiu])+[\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]?([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "lVCCvc = xsd:string {\n",
  "  pattern = \"([aeiu][\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]{1,2})+([aeiu][\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]?)([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "lCVCCvc = xsd:string {\n",
  "  pattern = \"(suen|kuara|[\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]([aeiu][\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]{1,2})+([aeiu][\\x{2BE}bdegh\\x{1E2B}i\\x{14B}klmnpqrs\\x{161}\\x{1E63}\\x{15B}t\\x{1E6D}uwyz]?))([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "uV = xsd:string {\n",
  "   pattern = \"[AEIU]([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "uVCv = xsd:string {\n",
  "  pattern = \"([AEIU][\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ])+[AEIU]?([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "uCVc = xsd:string {\n",
  "  pattern = \"([\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ][AEIU])+[\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]?([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "uVCCvc = xsd:string {\n",
  "  pattern = \"([AEIU][\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]{1,2})+([AEIU][\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]?)([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "uCVCCvc = xsd:string {\n",
  "  pattern = \"[\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]([AEIU][\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]{1,2})+([AEIU][\\x{2BE}BDEGH\\x{1E2A}I\\x{14A}KLMNPQRS\\x{160}\\x{1E62}\\x{15A}T\\x{1E6C}UWYZ]?)([\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}][\\x{2080}\\x{2081}\\x{2082}\\x{2083}\\x{2084}\\x{2085}\\x{2086}\\x{2087}\\x{2088}\\x{2089}]?|\\x{208A})?\"\n",
  "}\n",
  "\n",
  "grapheme = v | q | s | n | c | gloss | g | nongrapheme | punct | gsurro\n",
  "form     = attribute form { text }\n",
  "sb       = element g:b { s.model }\n",
  "vb       = element g:b { v.model }\n",
  "punct    = element g:p { p.model }\n",
  "lang     = attribute xml:lang { xsd:language }\n",
  "gsurro   = \n",
  "  element g:surro {\n",
  "    delim? , (s|c|n|punct) , groupgroup\n",
  "  }\n",
  "\n",
  "# Values\n",
  "#v.model  = \"x\" | lV | lVCv | lCVc | lVCCvc | lCVCCvc\n",
  "v.model = text\n",
  "v        = element g:v { form? , g.meta , lang? , (v.model | (vb , mods+)) }\n",
  "dingir   = element g:v { g.meta , lang? , (\"d\") }\n",
  "mister   = element g:v { g.meta , lang? , (\"m\") }\n",
  "\n",
  "# Names\n",
  "#s.model  =  \"N\" | \"X\" | uV | uVCv | uCVc | uVCCvc | uCVCCvc | lst | num\n",
  "s.model  = text\n",
  "\n",
  "lst    = xsd:string {\n",
  "  pattern=\"(..?SL|ABZ|BAU|HZL|KWU|LAK|M|MEA|MZL|REC|RSP|ZATU)\\d+[a-z]*\"\n",
  "}\n",
  "\n",
  "#[ABCD] is a stop-gap until lateuruk numbers are fixed\n",
  "num      = xsd:string { pattern = \"N|N\\d+[ABCD]?\" }\n",
  "\n",
  "s        = element g:s { form? , g.meta , (s.model | (sb , mods+)) }\n",
  "\n",
  "# Qualified graphemes\n",
  "q        = element g:q { form? , g.meta , (v|s|c) , (s|c|n) }\n",
  "\n",
  "# Numbers\n",
  "n.model  = r , (v|s|c|q)?\n",
  "\n",
  "r        = element g:r {\n",
  "             xsd:string {\n",
  "	       pattern = \"[nN]\\+[0-9]+|[nN]|[0-9]+|[n1-9]+/[n1-9]\" } }\n",
  "\n",
  "n        = element g:n { form? , g.meta , n.model , mods* }\n",
  "\n",
  "# Modifiers\n",
  "mods     = modifier | allograph | formvar\n",
  "\n",
  "modifier = element g:m { xsd:string { pattern = \"[a-z]|[0-9]{1,3}\" } }\n",
  "\n",
  "allograph= element g:a { xsd:string { pattern = \"[a-wyz0-9]+\" } }\n",
  "\n",
  "formvar = element g:f { xsd:string { pattern = \"[a-z0-9]+\" } }\n",
  "\n",
  "# Compounds\n",
  "c.model  = (compound , (o.join , compound)+) | unary | binary | ternary | (g , mods+)\n",
  "\n",
  "c        = element g:c { form? , g.meta , c.model , mods* }\n",
  "\n",
  "g        = element g:g { g.meta , c.model , mods* }\n",
  "\n",
  "compound = single | unary | binary\n",
  "\n",
  "single   = n | s | c | (g,mods*) | q\n",
  "\n",
  "unary    = o.unary , single\n",
  "\n",
  "binary   = single , o.binary , single\n",
  "\n",
  "ternary   = single , o.binary , single , o.binary , single\n",
  "\n",
  "o.join   = element g:o { attribute g:type { \"beside\" | \"joining\" | \"reordered\" } }\n",
  "\n",
  "o.unary  = element g:o { attribute g:type { \"repeated\" } , xsd:integer }\n",
  "\n",
  "o.binary =\n",
  "  element g:o {\n",
  "    attribute g:type {\n",
  "      \"containing\" | \"above\" | \"crossing\" | \"opposing\"\n",
  "    }\n",
  "  }\n",
  "\n",
  "# Punctuation\n",
  "p.model =\n",
  "    attribute g:type { \"*\"|\":\"|\":'\"|':\"'|\":.\"|\"::\"|\"|\"|\"/\" } , \n",
  "    g.meta , \n",
  "    (v|q|s|n|c)?\n",
  "g.meta = \n",
  "  break? , status.flags? , status.spans? , \n",
  "  paleography.attr? , linguistic.attr? , proximity.attr? ,\n",
  "  opener? , closer? , hsqb_o?, hsqb_c? , emhyph? ,\n",
  "  varnum? , sign_attr? , utf8? , delim? , notemark? ,\n",
  "  attribute xml:id { xsd:ID }? ,\n",
  "  breakStart? , breakEnd? ,\n",
  "  damageStart? , damageEnd? ,\n",
  "  surroStart? , surroEnd? ,\n",
  "  statusStart? , statusEnd? ,\n",
  "  accented?\n",
  "\n",
  "accented = attribute g:accented { text }\n",
  "breakStart = attribute g:breakStart { \"1\" }\n",
  "breakEnd = attribute g:breakEnd { xsd:IDREF }\n",
  "damageStart = attribute g:damageStart { \"1\" }\n",
  "damageEnd = attribute g:damageEnd { xsd:IDREF }\n",
  "surroStart = attribute g:surroStart { \"1\" }\n",
  "surroEnd = attribute g:surroEnd { xsd:IDREF }\n",
  "statusStart = attribute g:statusStart { \"1\" }\n",
  "statusEnd = attribute g:statusEnd { xsd:IDREF }\n",
  "\n",
  "notemark  = (attribute notemark  { text } , \n",
  "             attribute noteref { xsd:IDREF })\n",
  "\n",
  "break = attribute g:break  { \"damaged\" | \"missing\" }\n",
  "opener = attribute g:o     { text }\n",
  "closer = attribute g:c     { text }\n",
  "hsqb_o = attribute g:ho    { \"1\" }\n",
  "hsqb_c = attribute g:hc    { \"1\" }\n",
  "emhyph = attribute g:em    { \"1\" }\n",
  "sign_attr = attribute g:sign  { text }\n",
  "utf8   = attribute g:utf8  { text }\n",
  "delim  = attribute g:delim { text }\n",
  "varnum = (\n",
  "  attribute g:varo { text }? , \n",
  "  attribute g:vari { text }? ,  \n",
  "  attribute g:varc { text }?\n",
  ")\n",
  "\n",
  "status.flags =\n",
  "  attribute g:collated { xsd:boolean } ? ,\n",
  "  attribute g:queried  { xsd:boolean } ? ,\n",
  "  attribute g:remarked { xsd:boolean } ?\n",
  "\n",
  "gloss = det | glo\n",
  "pos = attribute g:pos { \"pre\" | \"post\" | \"free\" }\n",
  "det = element g:d { pos , dtyp , delim? , emhyph? , notemark? , surroStart? ,\n",
  "                    (dingir | mister | word.content*)}\n",
  "dtyp= attribute g:role { \"phonetic\" | \"semantic\" }\n",
  "glo = element g:gloss { attribute g:type { \"lang\" | \"text\" } , delim? , pos , words }\n",
  "\n",
  "status.spans =\n",
  "  attribute g:status {\n",
  "    \"ok\" | \"erased\" | \"excised\" | \"implied\" | \"maybe\" | \"supplied\"\n",
  "  }\n",
  "\n",
  "paleography.attr =\n",
  "  attribute g:script      { xsd:NCName }\n",
  "\n",
  "linguistic.attr =\n",
  "  attribute xml:lang      { xsd:language } ? ,\n",
  "#  attribute g:rws         { \"emegir\" | \"emesal\" | \"udgalnun\" }? ,\n",
  "  (attribute g:role       { \"sign\" | \"ideo\" | \"num\" | \"syll\" }\n",
  "  | (attribute g:role     { \"logo\" } ,\n",
  "     attribute g:logolang { xsd:language }))\n",
  "\n",
  "proximity.attr = \n",
  "  attribute g:prox { xsd:integer }\n",
  "\n",
  "nongrapheme = \n",
  "  element g:x {\n",
  "    ( attribute g:type { \"disambig\" | \"empty\" | \"newline\" | \"user\" }\n",
  "    | ( attribute g:type { \"ellipsis\" | \"word-absent\" | \"word-broken\" | \"word-linecont\" } \n",
  "        , status.spans , opener? , closer? , break? , notemark?)),\n",
  "    delim? , text? , varnum? ,\n",
  "    attribute xml:id { xsd:ID }? ,\n",
  "    breakStart? , breakEnd? ,\n",
  "    damageStart? , damageEnd? , emhyph? ,\n",
  "    surroStart? , surroEnd? ,\n",
  "    statusStart? , statusEnd?\n",
  "    }\n",
  "\n",
  "word.content = text | group | grapheme | nongrapheme\n",
  "\n",
  "words = (word | sword.head | sword.cont | nonword | nongrapheme)*\n",
  "\n",
  "word = \n",
  "  element g:w {\n",
  "    word.attributes,\n",
  "    word.content*\n",
  "  }\n",
  "\n",
  "sword.head = \n",
  "  element g:w {\n",
  "    attribute headform { text },\n",
  "    attribute contrefs { xsd:IDREFS },\n",
  "    word.attributes,\n",
  "    word.content*\n",
  "  }\n",
  "\n",
  "sword.cont = \n",
  "  element g:swc {\n",
  "    attribute xml:id { xsd:ID } ,\n",
  "    attribute xml:lang { xsd:language } ,\n",
  "    attribute form  { text }? ,\n",
  "    attribute headref { xsd:IDREF },\n",
  "    attribute swc-final { \"1\" | \"0\" },\n",
  "    delim? ,\n",
  "    word.content*\n",
  "  }\n",
  "\n",
  "word.attributes = \n",
  "    attribute xml:id { xsd:ID } ,\n",
  "    attribute xml:lang { xsd:language } ,\n",
  "    attribute form  { text }? ,\n",
  "    attribute lemma { text }? ,\n",
  "    attribute guide { text }? ,\n",
  "    attribute sense { text }? ,\n",
  "    attribute pos   { text }? ,\n",
  "    attribute morph { text }? ,\n",
  "    attribute base  { text }? ,\n",
  "    attribute norm  { text }? ,\n",
  "    delim? ,\n",
  "    syntax.attributes*\n",
  "\n",
  "nonword = \n",
  "  element g:nonw {\n",
  "    attribute xml:id { xsd:ID }? ,\n",
  "    attribute xml:lang { xsd:language }? ,\n",
  "    attribute type { \"comment\" | \"dollar\" | \"excised\" | \"punct\" | \"vari\" }? ,\n",
  "    attribute form { text }? ,\n",
  "    attribute lemma { text }? ,\n",
  "    syntax.attributes* ,\n",
  "    break? , status.flags? , status.spans? , opener? , closer? , delim? ,\n",
  "    word.content*\n",
  "  }\n",
  "\n",
  "group = \n",
  "  element g:gg {\n",
  "    attribute g:type { \n",
  "      \"correction\" | \"alternation\" | \"group\" | \"reordering\" | \"ligature\" | \"implicit-ligature\" | \"logo\" | \"numword\"\n",
  "    } ,\n",
  "    g.meta ,\n",
  "    (group | grapheme | normseg)+\n",
  "  }\n",
  "\n",
  "groupgroup = \n",
  "  element g:gg {\n",
  "    attribute g:type { \"group\" } ,\n",
  "    g.meta ,\n",
  "    (group | grapheme | normword)+\n",
  "  }\n",
  "\n",
  "syntax.attributes = \n",
  "  (attribute syn:brk-before { text } |\n",
  "   attribute syn:brk-after  { text } |\n",
  "   attribute syn:ub-before  { text } |\n",
  "   attribute syn:ub-after   { text } )\n",
  "\n",
  "normword = \n",
  "  element n:w { \n",
  "    word.attributes , \n",
  "    break? , status.flags? , status.spans? , opener? , closer? , \n",
  "    hsqb_o? , hsqb_c? ,\n",
  "    (normwordword | normwordgroup | gloss | nongrapheme | group)* ,\n",
  "    syntax.attributes*,\n",
  "    breakStart? , breakEnd? ,\n",
  "    damageStart? , damageEnd? ,\n",
  "    statusStart? , statusEnd?\n",
  "  }\n",
  "\n",
  "normwordgroup = \n",
  "  element n:word-group {\n",
  "     attribute g:type { \"alternation\" } ,\n",
  "     element n:grouped-word { normwordword }+\n",
  "  }\n",
  "\n",
  "normwordword = ( text | (normseg | normgroup)+)\n",
  "\n",
  "normseg =\n",
  "  element n:s {\n",
  "    n.meta ,\n",
  "    g.meta ,\n",
  "    text\n",
  "  }\n",
  "\n",
  "n.meta = normnum?\n",
  "\n",
  "normnum = attribute n:num { \"yes\" }\n",
  "\n",
  "normgroup = \n",
  "  element n:g {\n",
  "    attribute g:type {\n",
  "      \"correction\" | \"alternation\" | \"group\" | \"reordering\" | \"ligature\" | \"numword\"\n",
  "    } ,\n",
  "    g.meta ,\n",
  "    (normgroup | normseg)+\n",
  "  }\n",
  "\n",
  "translation =\n",
  "  element xtr:translation {\n",
  "    id,\n",
  "    attribute ref      { xsd:NMTOKEN },\n",
  "    attribute n        { text },\n",
  "    attribute project  { text },\n",
  "    attribute xml:lang { xsd:NMTOKEN },\n",
  "    attribute xtr:code { xsd:NMTOKEN },\n",
  "    attribute xtr:type { \n",
  "      \"interlinear\" | \"parallel\" | \"labeled\" | \"unitary\" \n",
  "    },\n",
  "    attribute xtr:cols { xsd:nonNegativeInteger }?,\n",
  "    (trans-unit | trans-note | trans-dollar | trans-comment | h)*,\n",
  "    map?\n",
  "  }\n",
  "\n",
  "id  = attribute xml:id { xsd:ID }\n",
  "cid = attribute xtr:cid { xsd:IDREF }\n",
  "ctr = attribute class { \"tr\" }\n",
  "\n",
  "trans-comment =\n",
  "  element xh:p {\n",
  "    attribute class { \"tr-comment\" },\n",
  "    htext*\n",
  "  }\n",
  "\n",
  "trans-dollar =\n",
  "  element xh:p {\n",
  "    attribute class { \"dollar\" },\n",
  "    silent?,\n",
  "    (standalone\n",
  "     | (ref | refs | (unit,refs?))),\n",
  "    new-labels? ,\n",
  "    htext* ,\n",
  "    innerp*\n",
  "  }\n",
  "\n",
  "trans-note = \n",
  "  element xh:div {\n",
  "    attribute class { \"note\" },\n",
  "    id?,\n",
  "    element xh:p { ctr , marker-ref , htext } ,\n",
  "    (element xh:p { ctr , htext } \n",
  "     | trans-comment)*\n",
  "  }\n",
  "\n",
  "trans-unit = \n",
  "  element xh:p {\n",
  "    id,\n",
  "    cid?,\n",
  "    ctr,\n",
  "    xtr-label, se-label,\n",
  "    (ref | refs | (unit,refs?)),\n",
  "    new-labels? ,\n",
  "    overlap? ,\n",
  "    spanall? ,\n",
  "    (innerp+ | htext)\n",
  "  }\n",
  "\n",
  "h = h1 | h2 | h3\n",
  "h1 = element xh:h1 { h-model }\n",
  "h2 = element xh:h2 { h-model }\n",
  "h3 = element xh:h3 { h-model }\n",
  "\n",
  "h-model = (id? , ctr , ( ref | hdr-ref)? , new-labels? , htext)\n",
  "\n",
  "innerp = element xh:innerp { htext | (comment, text) }\n",
  "htext = (text | trword | trcell | foreign | literal | marker \n",
  "         | supplied | uncertain | rspan | bspan | ispan | sign\n",
  "	 | bispan | smaller | sc | gdlspan | sup | lab | cun)*\n",
  "\n",
  "trword    = element xh:span { attribute class      { \"w\" },  \n",
  "			      attribute xtr:lem    { text }?,\n",
  "			      attribute xtr:disamb { text }?,\n",
  "			      attribute xtr:form   { text }?,\n",
  "			      id,\n",
  "			      (text | rspan | bspan | ispan | bispan | smaller | sc | sup | lab)* }\n",
  "\n",
  "trcell	  = element xh:span { attribute class { \"cell\" },  \n",
  "			      attribute xtr:span { xsd:nonNegativeInteger }?,\n",
  "			      htext }\n",
  "comment   = attribute class { \"tr-comment\" }\n",
  "foreign   = element xh:span { attribute class { \"foreign\" },  htext }\n",
  "literal   = element xh:span { attribute class { \"literal\" },  htext }\n",
  "supplied  = element xh:span { attribute class { \"supplied\" }, htext }\n",
  "uncertain = element xh:span { attribute class { \"uncertain\" },htext }\n",
  "rspan     = element xh:span { attribute class { \"r\" },        htext }\n",
  "bspan     = element xh:span { attribute class { \"b\" },        htext }\n",
  "ispan     = element xh:span { attribute class { \"i\" },        htext }\n",
  "bispan    = element xh:span { attribute class { \"bi\" },       htext }\n",
  "gdlspan   = element xh:span { attribute class { \"gdl\" },      l.inner }\n",
  "lab       = element xh:span { attribute class { \"lab\" },      htext }\n",
  "sc        = element xh:span { attribute class { \"sc\" },       htext }\n",
  "sign      = element xh:span { attribute class { \"sign\" },     htext }\n",
  "smaller   = element xh:span { attribute class { \"smaller\" },  htext }\n",
  "sup       = element xh:span { attribute class { \"sup\" },      htext }\n",
  "cun       = element xh:span { attribute class { \"cun\" },      htext }\n",
  "\n",
  "marker = \n",
  "  element xh:a {\n",
  "    attribute class { \"marker\" },\n",
  "    nrefs?,\n",
  "    xsd:string { pattern = \"\\d+[a-z]*\" }\n",
  "  }\n",
  "marker-ref = \n",
  "  element xh:span {\n",
  "    attribute class { \"marker\" },\n",
  "    xsd:string { pattern = \"\\d+[a-z]*\" }\n",
  "  }\n",
  "\n",
  "ref       = attribute xtr:ref     { xsd:IDREF }\n",
  "hdr-ref   = attribute xtr:hdr-ref { xsd:IDREF }\n",
  "refs      = start-ref , end-ref , all-refs? , new-labels? , rows\n",
  "start-ref = attribute xtr:sref    { xsd:IDREF  }\n",
  "end-ref   = attribute xtr:eref    { xsd:IDREF  }\n",
  "all-refs  = attribute xtr:refs    { xsd:IDREFS }\n",
  "uref      = attribute xtr:uref    { xsd:IDREF  }\n",
  "nrefs     = attribute xtr:nrefs   { xsd:IDREFS }\n",
  "rows 	  = attribute xtr:rows    { xsd:integer }\n",
  "overlap   = attribute xtr:overlap { xsd:boolean }\n",
  "silent    = attribute xtr:silent  { \"1\" }\n",
  "spanall   = attribute xtr:spanall { \"1\" }\n",
  "standalone= attribute xtr:standalone { \"1\" }\n",
  "xtr-label = (attribute xtr:label { text },\n",
  "             attribute xtr:rend-label { text }?)\n",
  "se-label = attribute xtr:se_label { text }\n",
  "unit  = attribute xtr:unit  { text }\n",
  "\n",
  "new-labels = \n",
  "	(attribute xtr:lab-start-lnum  { text },\n",
  "	 attribute xtr:lab-end-lnum    { text } ?,\n",
  "	 attribute xtr:lab-start-label { text },\n",
  "	 attribute xtr:lab-end-label   { text } ?\n",
  "	)\n",
  "\n",
  "map =\n",
  "  element xtr:map {\n",
  "    element xtr:l2t {\n",
  "      attribute lid { xsd:IDREF },\n",
  "      attribute tid { xsd:IDREF }\n",
  "    }*\n",
  "  }\n",
  "start = xtf | doctype\n",
  "xtf = element xtf { proto.outer? , doctype }\n",
  "doctype = score | translation | transliteration | composite | atf\n",
  "atf = element atf { attribute xml:id   { xsd:ID } , text }\n",
  "\n",
  "proto.outer = element protocols {\n",
  "  attribute scope { text },\n",
  "  proto.basket\n",
  "}\n",
  "\n",
  "proto.start = element protocols {\n",
  "  attribute scope { text },\n",
  "  (  proto.atf | proto.bib | proto.etcsl | proto.key | proto.lemmatizer \n",
  "     | proto.link | proto.project | proto.syntax | proto.version )*\n",
  "}\n",
  "\n",
  "proto.after = proto.note\n",
  "\n",
  "proto.inter = proto.bib | proto.etcsl | proto.lem | proto.link \n",
  "            | proto.note | proto.psu | proto.var\n",
  "\n",
  "proto.atf    = element protocol { attribute type { \"atf\" }    , text }\n",
  "proto.basket = element protocol { attribute type { \"basket\" } , text }\n",
  "proto.bib    = element protocol { attribute type { \"bib\" }    , text }\n",
  "proto.etcsl  = element protocol { attribute type { \"etcsl\" }  , text }\n",
  "proto.key    = element protocol { attribute type { \"key\" }    , text }\n",
  "proto.lem    = element protocol { attribute type { \"lem\" }    , text }\n",
  "proto.psu    = element protocol { attribute type { \"psu\" }    , text }\n",
  "proto.lemmatizer\n",
  "             = element protocol { attribute type { \"lemmatizer\" }, text }\n",
  "proto.link   = element protocol { attribute type { \"link\" }   , text }\n",
  "proto.note   = element protocol { attribute type { \"note\" }   , text }\n",
  "proto.project= element protocol { attribute type { \"project\" }, text }\n",
  "proto.syntax = element protocol { attribute type { \"syntax\" } , text }\n",
  "proto.var    = element protocol { attribute type { \"var\" }    , text }\n",
  "proto.version= element protocol { attribute type { \"version\" }, text }\n",
  "\n",
  "comments = cmt | note\n",
  "cmt = element cmt { text }\n",
  "note = element note {\n",
  "         attribute xml:id    { xsd:ID } ,\n",
  "         attribute notemark  { text }? , \n",
  "         attribute notelabel { text }? , \n",
  "	 htext }\n",
  "\n",
  "transliteration =\n",
  "  element transliteration {\n",
  "    attribute xml:id   { xsd:ID },\n",
  "    attribute n        { text },\n",
  "    attribute hand     { text }?,\n",
  "    attribute xml:lang { xsd:NMTOKEN },\n",
  "    project?,\n",
  "    implicit?,\n",
  "    haslinks?,\n",
  "    maxcells?,\n",
  "    (proto.start? , (object | nonobject | comments | sealing)*)\n",
  "  }\n",
  "n.attr = attribute n { text }\n",
  "n.attr.lc = attribute n { xsd:string { pattern=\"[a-z]\" }}\n",
  "haslinks = attribute haslinks { xsd:boolean }\n",
  "maxcells = attribute cols { xsd:nonNegativeInteger }\n",
  "project = attribute project { xsd:string { pattern=\"[a-z][a-z0-9/]+\" } }\n",
  "\n",
  "composite =\n",
  "  element composite {\n",
  "    composite-attlist,\n",
  "    sigdef*,\n",
  "    attribute hand     { text }?,\n",
  "    project?,\n",
  "    implicit?,\n",
  "    haslinks?,\n",
  "    maxcells?,\n",
  "    proto.start?,\n",
  "    composite-content,\n",
  "    (referto, comments?)*\n",
  "  }\n",
  "\n",
  "composite-attlist &=\n",
  "  attribute xml:id { xsd:ID },\n",
  "  attribute n { text },\n",
  "  attribute xml:lang { xsd:NMTOKEN }?\n",
  "\n",
  "object = \n",
  "  element object {\n",
  "    (implicit \n",
  "     | (attribute xml:id   { xsd:ID },\n",
  "        attribute label    { text })),\n",
  "    ( attribute type { known.object }\n",
  "     |(attribute type { user.object } , n.attr) \n",
  "    ) ,\n",
  "    status.flags,\n",
  "    (m.fragment | surface | sealing | comments | nonx)*\n",
  "  }\n",
  "known.object =    xsd:string { pattern=\"tablet|envelope|prism|bulla\" }\n",
  "user.object =     xsd:string { pattern=\"object\" }\n",
  "nonobject = nonx\n",
  "\n",
  "surface =\n",
  "  element surface { \n",
  "    (implicit \n",
  "     | (attribute xml:id   { xsd:ID },\n",
  "        attribute label    { text })),\n",
  "    (proto.inter | column | nonx | m | comments)* ,\n",
  "    (  attribute type { known.surface }\n",
  "     |(attribute type { face.surface } , n.attr.lc)\n",
  "     |(attribute type { edge.surface } , n.attr.lc?)\n",
  "     |(attribute type { user.surface | docket.surface | seal.surface } , n.attr)\n",
  "     ),\n",
  "    primes?,\n",
  "    status.flags\n",
  "  }\n",
  "\n",
  "known.surface =\n",
  "  xsd:string {\n",
  "    pattern=\"surface|obverse|reverse|left|right|top|bottom\"\n",
  "  }\n",
  "face.surface = xsd:string { pattern=\"face\" }\n",
  "edge.surface = xsd:string { pattern=\"edge\" }\n",
  "user.surface = xsd:string { pattern=\"surface\" }\n",
  "docket.surface = xsd:string { pattern=\"docket\" }\n",
  "seal.surface = xsd:string { pattern=\"seal\" }\n",
  "\n",
  "sealing =\n",
  "  element sealing {\n",
  "    attribute xml:id { xsd:ID },\n",
  "    attribute label    { text },\n",
  "    attribute n { xsd:NMTOKEN },\n",
  "    attribute scid { xsd:NMTOKEN }?,\n",
  "    (column | nonx | milestone | comments)*\n",
  "  }\n",
  "\n",
  "column = \n",
  "  element column { \n",
  "    (implicit\n",
  "     | (attribute xml:id   { xsd:ID },\n",
  "        attribute label    { text })),\n",
  "    (milestone | hdr | lg | l | nonl | nonx | comments | proto.inter)*,\n",
  "    attribute n { text },\n",
  "    attribute o { text }?,\n",
  "    primes?,\n",
  "    status.flags\n",
  "  }\n",
  "\n",
  "primes = \n",
  "  attribute primes { xsd:string { pattern=\"\\x{2032}+\" } }\n",
  "\n",
  "hdr = element h {\n",
  "  attribute level { xsd:nonNegativeInteger },\n",
  "  attribute xml:id   { xsd:ID },\n",
  "  htext\n",
  "}\n",
  "\n",
  "milestone = m | m.discourse\n",
  "\n",
  "m = element m { \n",
  "  attribute type { \"division\" | \"locator\" },\n",
  "  attribute subtype { text }?,\n",
  "  attribute n { text }?,\n",
  "  text\n",
  "}\n",
  "\n",
  "m.discourse = element m {\n",
  "  attribute type { \"discourse\" },\n",
  "  attribute subtype { \"body\" | \"catchline\" | \"colophon\" | \"date\" | \"linecount\" \n",
  "                      | \"witnesses\" | \"signature\" | \"summary\" \n",
  "		      | \"sealings\" | \"sealing\" },\n",
  "  attribute endflag { \"1\" }?,\n",
  "  text\n",
  "}\n",
  "\n",
  "m.fragment = element m { \n",
  "  attribute type { \"locator\" },\n",
  "  attribute subtype { \"fragment\" }?,\n",
  "  text\n",
  "}\n",
  "\n",
  "implicit = attribute implicit { \"1\" }\n",
  "\n",
  "nonx = element nonx { nonx-attlist, text }\n",
  "nonl = element nonl { nonl-attlist, text }\n",
  "nong = element nong { nong-attlist, text }\n",
  "\n",
  "nonx-attlist =\n",
  "  attribute xml:id { xsd:ID },\n",
  "  (attribute label { text },\n",
  "   attribute silent { \"1\" })?,\n",
  "  (\n",
  "   (attribute strict { \"1\" },\n",
  "    ((attribute ref     { text },\n",
  "      attribute scope   { text })\n",
  "     |(attribute extent { text },\n",
  "       attribute scope  { text },\n",
  "       attribute state  { text },\n",
  "       attribute flags  { xsd:string {\n",
  "                              pattern=\"[!?*]+\"\n",
  "			  }}?)))\n",
  "  |\n",
  "   (attribute strict { \"0\" },\n",
  "    attribute extent { text }?,\n",
  "    attribute ref    { text }?,\n",
  "    attribute scope  { text }?,\n",
  "    attribute state  { text }?)\n",
  "  |\n",
  "   (attribute strict { \"0\" },\n",
  "    attribute ref    { \"none\" },\n",
  "    attribute type   { \"empty\" })\n",
  "  |\n",
  "   (attribute type   { \"image\" },\n",
  "    attribute strict { \"0\" },\n",
  "    attribute ref    { xsd:string {\n",
  "                          pattern=\"[PQX][0-9]+@[0-9]+[a-z]*\" \n",
  "		       }},\n",
  "    attribute alt    { text })\n",
  "  )\n",
  "\n",
  "non-x-attr-set =\n",
  "  attribute type {\n",
  "    \"newline\" | \"broken\" | \"maybe-broken\" | \"traces\"\n",
  "    | \"maybe-traces\" | \"blank\" | \"ruling\" | \"image\"\n",
  "    | \"seal\" | \"docket\" | \"comment\" | \"bullet\" | \"other\"\n",
  "  },\n",
  "  attribute unit { \"self\" | \"quantity\" | \"ref\" }?,\n",
  "  attribute extent { text }?,\n",
  "  attribute ref { text }?,\n",
  "  attribute xml:id { xsd:ID }?\n",
  "noncolumn-attlist &= non-x-attr-set\n",
  "nonl-attlist &= non-x-attr-set\n",
  "nong-attlist &= non-x-attr-set\n",
  "\n",
  "l =\n",
  "  element l {\n",
  "    attribute xml:id { xsd:ID },\n",
  "    attribute n { text },\n",
  "    attribute o { text }?,\n",
  "    attribute label { text }?,\n",
  "    attribute spanall { \"1\" }?,\n",
  "    (cell+ | f+ | (ag | l.inner)*) \n",
  "  }\n",
  "\n",
  "l.inner = (surro | normword | words | glo)*\n",
  "\n",
  "cell = element c { span? , (f+ | l.inner) }\n",
  "span = attribute span { xsd:nonNegativeInteger }\n",
  "\n",
  "f = element f { f-attlist, (ag | l.inner)* }\n",
  "f-attlist &=\n",
  "  attribute xml:id { xsd:ID }?,\n",
  "  attribute n { text }?,\n",
  "  attribute type { xsd:NMTOKEN },\n",
  "  attribute xml:lang { xsd:NMTOKEN }?\n",
  "\n",
  "lg = element lg { \n",
  "  attribute xml:id { xsd:ID }?,\n",
  "  maxcells?,\n",
  "  attribute n { text }?,\n",
  "  (   (l,gus?,nts)\n",
  "    | (l,gus?,nts?,(proto.link?,bil+)+)\n",
  "    | (l,gus?,lgs) \n",
  "    | (l,gus?,nts,lgs) \n",
  "    | (l,gus?, (e | comments)*)),\n",
  "  proto.inter*,\n",
  "  var*\n",
  "}\n",
  "bil = element l { attribute type { \"bil\" } , l.inner* }\n",
  "nts = element l { attribute type { \"nts\" } , (ag | l.inner)* }\n",
  "lgs = element l { attribute type { \"lgs\" } , grapheme* }\n",
  "gus = element l { attribute type { \"gus\" } , l.inner* }\n",
  "var = element v { \n",
  "  attribute varnum { text | \"*\" } ,\n",
  "  attribute label  { text } ,\n",
  "  attribute ex_label { text }? ,\n",
  "  (l.inner | cell+)\n",
  "}\n",
  "\n",
  "# alignment groups\n",
  "ag = element ag { \n",
  "  attribute ref { xsd:string { pattern=\"[a-z]+\" } },\n",
  "  attribute form { text }?,\n",
  "  l.inner*\n",
  "}\n",
  "\n",
  "surro = element surro { l.inner }\n",
  "words |= surro?\n",
  "word |= surro?\n",
  "\n",
  "composite-content = \n",
  "  (milestone | \\include | \\div | variants | hdr | lg | l | comments | nonl | nonx | proto.inter)*\n",
  "\n",
  "\\include = element include { increfAttr }\n",
  "\n",
  "referto = element referto { increfAttr }\n",
  "\n",
  "increfAttr = \n",
  "  (attribute ref { text } , \n",
  "   attribute n { text } ,\n",
  "   (attribute from { text },\n",
  "    attribute to { text }?)?)\n",
  "\n",
  "\\div =\n",
  "  element div {\n",
  "    div-attlist, \n",
  "    composite-content\n",
  "  }\n",
  "div-attlist &=\n",
  "  attribute xml:id { xsd:ID }?,\n",
  "  attribute n { text }?,\n",
  "  attribute type { xsd:NMTOKEN },\n",
  "  attribute lang { text }?,\n",
  "  attribute place { text }?,\n",
  "  attribute subtype { text }?\n",
  "\n",
  "variants = element variants { variant* }\n",
  "\n",
  "variant = \n",
  "  element variant {\n",
  "    (\\div | variants | lg | l | comments | nonl | proto.inter | nonx)*\n",
  "  }\n",
  "\n",
  "score =\n",
  "  element score {\n",
  "    score-attlist, \n",
  "    proto.start? , sigdef*, \n",
  "    (object | surface | column | milestone | \\div | lg | comments | nonl)*\n",
  "  }\n",
  "score-attlist &=\n",
  "  attribute xml:id { xsd:ID },\n",
  "  attribute n { text },\n",
  "  score_mode,\n",
  "  score_type,\n",
  "  score_word?,\n",
  "  attribute xml:lang { xsd:NMTOKEN }?,\n",
  "  attribute hand     { text }?,\n",
  "  project?,\n",
  "  implicit?,\n",
  "  haslinks?,\n",
  "  maxcells?\n",
  "\n",
  "score_mode = attribute score-mode { \"parsed\" | \"unparsed\" }\n",
  "score_type = attribute score-type { \"matrix\" | \"synopsis\" }\n",
  "score_word = attribute score-word { \"yes\" }\n",
  "\n",
  "synopticon =\n",
  "  element synopticon { synopticon-attlist, sigdef*, (eg | comments | nonl)* }\n",
  "synopticon-attlist &=\n",
  "  attribute xml:id { xsd:ID },\n",
  "  attribute n { text },\n",
  "  attribute xml:lang { xsd:NMTOKEN }?\n",
  "sigdef = element sigdef { sigdef-attlist, empty }\n",
  "sigdef-attlist &=\n",
  "  attribute xml:id { xsd:ID },\n",
  "  attribute targ-id { xsd:NMTOKEN },\n",
  "  attribute targ-n { text }\n",
  "eg = element eg { eg-attlist, e* }\n",
  "eg-attlist &= attribute xml:id { xsd:ID }?\n",
  "e =\n",
  "  element e {\n",
  "    e-attlist,\n",
  "    (l.inner\n",
  "     | cell+\n",
  "     | f+)\n",
  "  }\n",
  "e-attlist &=\n",
  "  attribute xml:id { xsd:ID }?,\n",
  "  attribute sigref { xsd:IDREF }?,\n",
  "  attribute n { text }?,\n",
  "  attribute l { text }?,\n",
  "  attribute p { text }?,\n",
  "  attribute hlid { text }?,\n",
  "  attribute plid { text }?\n",
  "# include \"xtf.rnc\"\n",
  "cdf-inline = (text | rspan | ispan | sign | bispan | gdl )*\n",
  "cdf = element c:cdf { (document | transliteration | composite | translation)* }\n",
  "\n",
  "document = element c:document { section | toplev }\n",
  "\n",
  "toplev = ( bibliography | catalog | p | section | xtf )*\n",
  "\n",
  "bibliography = element c:bibliography { attribute type { \"by-year\" }? , bib+ }\n",
  "\n",
  "bib     = element c:bib     { (year , data) | (cdf-inline) }\n",
  "year    = element c:biby    { text }\n",
  "data    = element c:bibd    { text }\n",
  "\n",
  "catalog = element c:catalog { record* }\n",
  "record  = element c:record  { field*  }\n",
  "field   = element c:field   { key , val }\n",
  "key     = element c:key     { xsd:NMTOKEN }\n",
  "val     = element c:val     { cdf-inline }\n",
  "\n",
  "p       = element c:p       { cdf-inline }\n",
  "\n",
  "section = element c:section { attribute type { xsd:NMTOKEN } , toplev }\n",
  "\n",
  "gdl     = element c:gdl { words }\n",
  NULL };
int cdfrnc_len = 0;
static char *cdfbuf;
char *
cdfrnc()
{
  const char *const*p = cdf_rnc;
  if (!cdfrnc_len)
    {
      while (*p)
        cdfrnc_len += strlen(*p++);
      cdfbuf = malloc(cdfrnc_len+1);
      *cdfbuf = '\0';
      p = cdf_rnc;
      while (*p)
        strcat(cdfbuf,*p++);
    }
  return cdfbuf;
}
void
cdfrnc_term(void)
{
    free(cdfbuf);
}