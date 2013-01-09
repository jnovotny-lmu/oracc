/* C code produced by gperf version 3.0.3 */
/* Command-line: gperf -N xcltok -tT xcltok.g  */
/* Computed positions: -k'1' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "xcltok.g"

#include <string.h>
#include <stddef.h>
#include "xcl.h"

#define TOTAL_KEYWORDS 17
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 11
#define MIN_HASH_VALUE 4
#define MAX_HASH_VALUE 25
/* maximum key range = 22, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static unsigned char asso_values[] =
    {
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 20,  5,
      10, 26, 26,  5, 26, 26, 26, 26, 10, 26,
       5, 26,  0, 26, 26,  0,  0, 26, 26, 15,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26
    };
  return len + asso_values[(unsigned char)str[0]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct xcl_tok_tab *
xcltok (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct xcl_tok_tab wordlist[] =
    {
      {""}, {""}, {""}, {""},
#line 13 "xcltok.g"
      {"text",	   xcl_node_c, xcl_c_text},
#line 27 "xcltok.g"
      {"punct",	   xcl_node_d, xcl_d_punct},
#line 18 "xcltok.g"
      {"phrase",	   xcl_node_c, xcl_c_phrase},
#line 28 "xcltok.g"
      {"surface",   xcl_node_d, xcl_d_surface},
#line 16 "xcltok.g"
      {"sentence",  xcl_node_c, xcl_c_sentence},
#line 29 "xcltok.g"
      {"nonx", 	   xcl_node_d, xcl_d_nonx},
#line 15 "xcltok.g"
      {"chunk",	   xcl_node_c, xcl_c_chunk},
#line 17 "xcltok.g"
      {"clause",	   xcl_node_c, xcl_c_clause},
      {""},
#line 23 "xcltok.g"
      {"cell-end",  xcl_node_d, xcl_d_cell_end},
#line 25 "xcltok.g"
      {"gloss-end", xcl_node_d, xcl_d_gloss_end},
#line 22 "xcltok.g"
      {"cell-start",xcl_node_d, xcl_d_cell_start},
#line 24 "xcltok.g"
      {"gloss-start",xcl_node_d, xcl_d_gloss_start},
      {""},
#line 19 "xcltok.g"
      {"line-var",  xcl_node_c, xcl_c_line_var},
#line 14 "xcltok.g"
      {"discourse", xcl_node_c, xcl_c_discourse},
#line 21 "xcltok.g"
      {"line-start",xcl_node_d, xcl_d_line_start},
      {""}, {""},
#line 20 "xcltok.g"
      {"word-var",  xcl_node_c, xcl_c_text},
      {""},
#line 26 "xcltok.g"
      {"break",	   xcl_node_d, xcl_d_break}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}