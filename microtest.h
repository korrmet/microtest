#ifndef MICROTEST_H
#define MICROTEST_H

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#define MT_INIT(name) \
  printf("testing module: %s\n", name); \
  unsigned int mt_testnum = 0; \
  unsigned int mt_testpass = 0;

#define MT_START(name) \
{ printf("  %s ", name); mt_testnum++; \
  for (unsigned int i = 0; i < 72 - strlen(name); i++) { printf("."); } \
  unsigned int err = 0;

#define MT_END() \
  if (err) { printf(" fail\n"); } else { printf(".. ok\n"), mt_testpass++; } }

#define MT_CHECK() \
  printf("statistics: %d/%d passed\n", mt_testpass, mt_testnum); \
  if (mt_testpass < mt_testnum) { return -1; } else { return 0; }

#endif// MICROTEST_H
