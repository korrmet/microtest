#include <stdio.h>
#include "microtest.h"

int main(int argc, char** argv)
{ MT_INIT("example");

  MT_START("2x2")
    if (2 * 2 != 4) { err = 1; }
  MT_END()

  MT_START("3x3")
    if (3 * 3 != 9) { err = 1; }
  MT_END()

  MT_START("sample error")
    MT_PRINT("error, but ok");
  MT_END()
  
  MT_START("sample error")
    err = 1;
    MT_PRINT("error, but not ok");
  MT_END()

  MT_SUMMARY(); }
