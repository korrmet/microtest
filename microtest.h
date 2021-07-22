#ifndef MICROTEST_H
#define MICROTEST_H

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#define MT_WIDTH     80
#define MT_DOT_SPACE 1
#define MT_INDENT    2

#define MT_INIT(...) \
  printf("testing module: "); \
  printf(__VA_ARGS__); printf("\n"); \
  unsigned int mt_testnum = 0; \
  unsigned int mt_testpass = 0;

#define MT_START(...) \
{ unsigned int space_avail = MT_WIDTH;\
  for (unsigned int i = 0; i < MT_INDENT; i++) { printf(" "); space_avail--; }\
  char namstr[MT_WIDTH] = { 0 }; snprintf(namstr, MT_WIDTH, __VA_ARGS__); \
  printf("%s", namstr); space_avail -= strlen(namstr); \
  for (unsigned int i = 0; i < MT_DOT_SPACE; i++) \
  { printf(" "); space_avail--; } \
  unsigned int err = 0; char retstr[MT_WIDTH] = { 0 }; 

#define MT_PRINT(...) { snprintf(retstr, MT_WIDTH, __VA_ARGS__); }

#define MT_END(...) \
  if (!err) { mt_testpass++; } \
  space_avail -= strlen(retstr); \
  space_avail -= (strlen(retstr)) ? strlen(", ") : 0; \
  space_avail -= MT_DOT_SPACE; \
  space_avail -= (err) ? strlen("fail") : strlen("ok"); \
  for (unsigned int i = 0; i < space_avail; i++) { printf("."); } \
  printf(" %s", retstr); \
  if (strlen(retstr)) { printf(", "); } \
  if (err) { printf("fail"); } else { printf("ok"); } \
  printf("\n"); }

#define MT_SUMMARY() \
  printf("statistics: %d/%d passed\n", mt_testpass, mt_testnum); \
  if (mt_testpass < mt_testnum) { return -1; } else { return 0; }

#endif// MICROTEST_H
