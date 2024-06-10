#include <stdio.h>
#include "microtest.h"
#include "example.h"

int main(int argc, char** argv)
{ int s;
  MT_INIT("sum function tests");

  MT_START("two and two, easy peasy", NULL);
    MT_ASSERT(sum(2, 2) == 4, "2 + 2 == %d", sum(2, 2));
  MT_END();

  MT_START("three and three, similar", NULL);
    MT_ASSERT(sum(3, 3) == 6, "3 + 3 == %d", sum(3, 3));
  MT_END();

  MT_START("four and four, piece of cake", NULL);
    s = sum(4, 4);
    MT_ASSERT(s == 8, "4 + 4 == %d", sum(4, 4));
    MT_PRINT("%d", s);
  MT_END();

  MT_START("explicit false, would block the build", NULL);
    MT_ASSERT(0, "failed", NULL);
  MT_END();

  MT_SUMMARY(); }
