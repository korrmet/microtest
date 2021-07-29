# microtest

Extremely minimal header-only testing framework for C (and sometimes C++)

# overview

Actually it's just formatter for output. Your tests is a part of programs, which
belongs between `MT_START` and `MT_END` macro. You must manually implement
testing environment which you need (e.g. there is no tools for fuzzing or
calling pure functions, measure performance, e.t.c.). It will be enough for most
purposes.

Main idea of using this framework is force to improve your code while testing.
Spartan frameworks like this can be used with well structured. Testing project
with dependency hell, or has ball of mud erchitecture is painful. There is two
solutions to ease the pain:

1. use another framework with extra features,
2. refactor and improve your project.

I'm prefer second way when i write code. But existing ball of mud can turn me
to chose first way. Will be better to chose second way for everything, but
sometimes we have not enough resources to do it.

# signs of shit

So you trying to test your code and you have a trouble. It means what your code
contain some shit and this trouble is a sign.

## can't test inner functions of a c-file

Not so shit but needs uncommon behavour. Just include c or cpp file in your test
program. When you doing that all lines from c file copies to inclusion point by
preprocessor. After that remember what you need to build just your test program
source, not target c or cpp file.

## i need to build a half of project to test just one entity

It's a sign of dependency hell. Cohesion, coupling, other bla-bla-bla... If you
have large experience this problem is not so frequent and big but newbies almost
always have this trouble. And only solution is refactor. It's not so painful if
you know ho to do it.

## i need to test one entity from source file but other entities make it trouble

This kind of shit looks like dependency hell but actually it's just problem of
logical design. You wanna test function with name `set_i_to_10_and_j_to_5` or
something like this, right? Main reason is you remember only DRY principle and
forgot other SOLID principles.

## i need to modify source to correctly test it

Often this happens when testing object is too big and have too complex behavour.
These code also will be painful to modify and support.
