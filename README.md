# microtest

Extremely minimal header-only testing framework for C (and sometimes C++)

# overview

Actually it's just formatter for output. Your tests is a part of programs, which
belongs between `MT_START` and `MT_END` macro. You must manually implement
testing environment which you need (e.g. there is no tools for fuzzing or
calling pure functions, measure performance, e.t.c.). It will be enough for most
purposes.

Main idea of using this framework is force to improve your code while testing.
Spartan frameworks like this can be used with well structured projects.

Testing project with dependency hell, or has ball of mud erchitecture is painful.
There is two solutions to ease the pain:

1. use another framework with extra features,
2. refactor and improve your project.

I'm prefer second way when i write code. But existing ball of mud can turn me
to chose first way. Will be better to chose second way for everything, but
sometimes we have not enough resources to do it.
