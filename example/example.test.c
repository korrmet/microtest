#include <stdio.h>
#include "microtest.h"
#include "example.h"

int main(int argc, char** argv)
{ MT_INIT("sum function tests")

  MT_START("two and two, easy peasy")
    MT_ASSERT(sum(2, 2) == 4, "");
  MT_END()

  MT_START("three and three, similar")
    MT_ASSERT(sum(3, 3) == 6, "");
  MT_END()

  MT_START("four and four, piece of cake")
    int s = sum(4, 4);
    MT_ASSERT(s == 8, "");
    MT_PRINT("%d", s);
  MT_END()

  MT_START("explicit false, would block the build")
    MT_ASSERT(0, "");
  MT_END()

  MT_SUMMARY() }
