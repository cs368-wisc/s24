# Sparrow Project

## Overview

This term, you'll implement a simple-prototype of Arrow (Sparrow).
The [Arrow project](https://arrow.apache.org/) is a protocol and
library for analyzing tables efficiently.  Some of you might have
experience using the pandas Python library for analyzing tables of
data.  Wes McKinney started pandas in 2008, but has [more recently](https://wesmckinney.com/blog/apache-arrow-pandas-internals/)
worked on Arrow, trying to solve the shortcomings of pandas.  Arrow is faster and is supported in many programming languages, including C++.

If `t` is a Sparrow table, here are some examples of things you'll be able to do with your Sparrow library by the end of the term:

* `t["c"]` to extract column `c` from the table
* `t["x"] + t["y"]` to add the numbers in column `x` to the numbers in column `y` (without needing a loop!)
* `t["c"].apply(f)` to call a function `f` on every value in column `c` to produce a new column of values
* `t["c"] > 3` to get a column of Booleans with a true for every value greater than 3
* `t[t["c"] > 3]` to get a smaller table only containing rows where the condition applies
* have a way to represent missing integers in a column (this is a useful feature because int primitives don't have something equivalent to `NaN` for floats)

## Stages

Although this is all part of one big project, there will be six stages, P1-P6:

* [P1: tooling and basics](p1.md)
* [P2: structs and pointers](p2.md)
* P3
* P4
* P5
* P6

## Tester

The tests used for grading will be in the [tests](./tests) directory.
These will usually be used to directly compute your grades, but I
reserve the right to modify grades as appropriate.  I might lower
grades if somebody is trying to game the tests (for example, by
hardcoding expected output) or does not follow specific directions
about how to implement something.

You can copy everything from the tests directory to where your code is
and run `python3 tester.py`.  Most tests correspond to a single
program named something like `testN_????.cpp` -- tester.py will build
and run this for you.  When debugging, it may be easier to directly
run these test programs yourself, however.

The `tester.py` program will run until it encounters a first test
failure.  If you want it to keep trying to run all the tests, you can
pass `python3 tester.py -a` ("a" for "all").  Upon completion,
test.json will summarize points earned (each test is worth 4 points).
