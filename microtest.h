#ifndef MICROTEST_H
#define MICROTEST_H

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#ifndef MT_WIDTH
#define MT_WIDTH     80 ///< total width of tests output
#endif

#ifndef MT_DOT_SPACE
#define MT_DOT_SPACE 1  ///< spacing between dotted line and symbols
#endif

#ifndef MT_INDENT
#define MT_INDENT    2  ///< indention of test cases
#endif

/** \brief   initializing of test input
 *  \details place it in start of testing main function
 *
 *  \arg     ... name of module which you wanna test 
 *               \note arguments will be passed to printf so it has similar 
 *                     format */
#define MT_INIT(...)                                                           \
  printf("testing module: ");                                                  \
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
{ unsigned int space_avail = MT_WIDTH;                                         \
  for (unsigned int i = 0; i < MT_INDENT; i++) { printf(" "); space_avail--; } \
  char namstr[MT_WIDTH] = { 0 }; snprintf(namstr, MT_WIDTH, __VA_ARGS__);      \
  printf("%s", namstr); space_avail -= strlen(namstr);                         \
  for (unsigned int i = 0; i < MT_DOT_SPACE; i++)                              \
  { printf(" "); space_avail--; }                                              \
  unsigned int err = 0; char retstr[MT_WIDTH] = { 0 }; 

/** \brief   print comment for test result
 *  \details comment will be displayed between dotted line and result of test
 *           execution. should be short
 *  \warning you can call it only once by test case execution to reach correct
 *           output. also control yourself it's length to avoid incorrect output
 *
 *  \arg     ... comment body
 *               \note arguments will be passed to printf so it has similar
 *                     format */
#define MT_PRINT(...) { snprintf(retstr, MT_WIDTH, __VA_ARGS__); }

/** \brief   end of test case
 *  \details test case body must be placed between MT_START and MT_END macro.
 *           print dotted line, comment and result of test case execution */
#define MT_END()                                                               \
  if (!err) { mt_testpass++; }                                                 \
  space_avail -= strlen(retstr);                                               \
  space_avail -= (strlen(retstr)) ? strlen(", ") : 0;                          \
  space_avail -= MT_DOT_SPACE;                                                 \
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
  printf("statistics: %d/%d passed\n", mt_testpass, mt_testnum);               \
  if (mt_testpass < mt_testnum) { return -1; } else { return 0; }

#endif// MICROTEST_H
