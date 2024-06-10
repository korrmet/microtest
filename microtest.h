#ifndef MICROTEST_H
#define MICROTEST_H

#ifdef __cplusplus
#include <cstring>
#include <cstdio>
#else
#include <string.h>
#include <stdio.h>
#endif

#ifndef snprintf
/** \brief redefinition to fix false-error in GCC -Wall -Werror -pedantic */
int snprintf(char *buf, size_t size, const char *fmt, ...);
#endif

#ifndef MT_WIDTH
/** \brief total widht of tests output, you may define it yourself */
#define MT_WIDTH 80
#endif

#if MT_WIDTH < 40
#define MT_WIDTH 40
#endif

/** \brief   initializing of test input
 *  \details place it in start of testing main function
 *
 *  \arg     name name of module which you wanna test, c-string */
#define MT_INIT(name)                                                          \
  unsigned int mt_testnum, mt_testpass, mt_idx;                                \
  mt_testnum = 0; mt_testpass = 0; mt_idx = 0;                                 \
  printf("Testing %s\n", name)

/** \brief   start point of new test case
 *  \details test case body must be placed between MT_START and MT_END macro.
 *           prints name of test case and prepare inner variables to check
 *           result of testing and print output
 *
 *  \arg     fmt comment body format string, like in printf
 *  \arg     var optional variable, may be NULL if no needed */
#define MT_START(fmt, var)                                                     \
{ int space_avail;                                                             \
  char namstr[MT_WIDTH], retstr[MT_WIDTH];                                     \
  unsigned int err;                                                            \
  space_avail = MT_WIDTH;                                                      \
  memset(retstr, 0, MT_WIDTH); memset(namstr, 0, MT_WIDTH);                    \
  err = 0; printf("  "); space_avail -= 2;                                     \
  snprintf(namstr, (MT_WIDTH / 2), fmt, var);                                  \
  printf("%s", namstr); space_avail -= strlen(namstr);                         \
  printf(" "); space_avail--; mt_testnum++;

/** \brief   print comment for test result
 *  \details comment will be displayed between dotted line and result of test
 *           execution. should be short
 *  \warning you can call it only once by test case execution to reach correct
 *           output. also control yourself it's length to avoid incorrect output
 *
 *  \arg     fmt comment body format string, like in printf
 *  \arg     var optional variable, may be NULL if no needed */
#define MT_PRINT(fmt, var)                                                     \
  if (fmt) { snprintf(retstr, space_avail - 9, fmt, var); }

/** \brief   check condition for registering erorr with message
 *  \details if no additional message needed, put empty string literal as second
 *           argument
 *  \arg     con condition to check
 *  \arg     fmt comment body format string, like in printf
 *  \arg     var optional variable, may be NULL if no needed */
#define MT_ASSERT(con, fmt, var)                                               \
  if (!err && (!(con))) { MT_PRINT(fmt, var); err = 1; }

/** \brief   end of test case
 *  \details test case body must be placed between MT_START and MT_END macro.
 *           print dotted line, comment and result of test case execution */
#define MT_END()                                                               \
  if (!err) { mt_testpass++; }                                                 \
  space_avail -= strlen(retstr);                                               \
  space_avail -= (strlen(retstr)) ? strlen(", ") : 0;                          \
  space_avail -= 1;                                                            \
  space_avail -= (err) ? strlen("fail") : strlen("ok");                        \
  for (mt_idx = 0; mt_idx < space_avail; mt_idx++) { printf("."); }            \
  printf(" %s", retstr);                                                       \
  if (strlen(retstr)) { printf(", "); }                                        \
  if (err) { printf("fail"); } else { printf("ok"); }                          \
  printf("\n"); }

/** \brief   print summary of testing
 *  \details place it in end of your test main function. also invoke return
 *  \return  result of testing
 *  \retval  0  all tests passed
 *  \retval  -1 some of tests not passed */
#define MT_SUMMARY()                                                           \
  printf("Summary: %d/%d passed\n", mt_testpass, mt_testnum);                  \
  if (mt_testpass < mt_testnum) { return -1; } else { return 0; }

#endif
