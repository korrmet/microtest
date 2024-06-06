#ifndef MICROTEST_H
#define MICROTEST_H

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#ifndef MT_WIDTH
#define MT_WIDTH 80 ///< total width of tests output, you may define it yourself
#endif

#if MT_WIDTH < 40
#define MT_WIDTH 40
#endif

/** \brief   initializing of test input
 *  \details place it in start of testing main function
 *
 *  \arg     ... name of module which you wanna test 
 *               \note arguments will be passed to printf so it has similar 
 *                     format */
#define MT_INIT(...)                                                           \
  printf("Testing ");                                                          \
  printf(__VA_ARGS__); printf("\n");                                           \
  unsigned int mt_testnum = 0;                                                 \
  unsigned int mt_testpass = 0;

/** \brief   start point of new test case
 *  \details test case body must be placed between MT_START and MT_END macro.
 *           prints name of test case and prepare inner variables to check
 *           result of testing and print output
 *
 *  \arg     ... name of current test case
 *               \note arguments will be passed to printf so it has similar 
 *                     format */
#define MT_START(...)                                                          \
{ int space_avail = MT_WIDTH;                                                  \
  printf("  "); space_avail -= 2;                                              \
  char namstr[MT_WIDTH] = { 0 }; snprintf(namstr, MT_WIDTH / 2, __VA_ARGS__);  \
  printf("%s", namstr); space_avail -= strlen(namstr);                         \
  printf(" "); space_avail--;                                                  \
  unsigned int err = 0; char retstr[MT_WIDTH] = { 0 };                         \
  mt_testnum++;

/** \brief   print comment for test result
 *  \details comment will be displayed between dotted line and result of test
 *           execution. should be short
 *  \warning you can call it only once by test case execution to reach correct
 *           output. also control yourself it's length to avoid incorrect output
 *
 *  \arg     ... comment body
 *               \note arguments will be passed to printf so it has similar
 *                     format */
#define MT_PRINT(...) { snprintf(retstr, space_avail - 9, __VA_ARGS__); }

/** \brief   check condition for registering erorr with message
 *  \details if no additional message needed, put empty string literal as second
 *           argument
 *  \arg     con condition to check
 *  \arg     ... comment body
 *               \note arguments will be passed to printf so it has similar
 *                     format */
#define MT_ASSERT(con, ...)                                                    \
  if (!err && (!(con))) { MT_PRINT(__VA_ARGS__); err = 1; }

/** \brief   end of test case
 *  \details test case body must be placed between MT_START and MT_END macro.
 *           print dotted line, comment and result of test case execution */
#define MT_END()                                                               \
  if (!err) { mt_testpass++; }                                                 \
  space_avail -= strlen(retstr);                                               \
  space_avail -= (strlen(retstr)) ? strlen(", ") : 0;                          \
  space_avail -= 1;                                                            \
  space_avail -= (err) ? strlen("fail") : strlen("ok");                        \
  for (unsigned int i = 0; i < space_avail; i++) { printf("."); }              \
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
  printf("Summary: %d/%d passed\n", mt_testpass, mt_testnum);               \
  if (mt_testpass < mt_testnum) { return -1; } else { return 0; }

#endif// MICROTEST_H
