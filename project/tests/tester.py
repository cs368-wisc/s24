import os, sys, json, traceback
from subprocess import run, PIPE, check_output
from os.path import exists
from os import remove

TEST_WEIGHT = 4

def remove_if_exists(*paths):
    for path in paths:
        if exists(path):
            remove(path)

def run_and_check(cmd):
    print("RUN: "+cmd)
    result = run(cmd, shell=True)
    if result.returncode != 0:
        raise Exception(f"This program exited with status code {result.returncode}: {cmd}")

def cpp_test(name):
    compiler = os.environ.get("CC", "g++-13")
    run_and_check(f"{compiler} -L . -I . -std=c++20 {name}.cpp -lsparrow -o {name}")
    run_and_check(f"./{name}")
    return None

# test PASSES: return None
# test FAILS: return string briefly describing the issue OR raise an exception

def test1_build():
    assert exists("Makefile")
    assert exists("sparrow.h")
    assert exists("sparrow.cpp")
    assert exists("p1.cpp")

    remove_if_exists("libsparrow.so", "p1")
    run_and_check("make")

    assert exists("libsparrow.so")
    assert exists("p1")

    return None

def test2_bitcounter():
    return cpp_test("test2_bitcounter")

def test3_overload():
    return cpp_test("test3_overload")

def test4_bit_and():
    return cpp_test("test4_bit_and")

def test5_p1_program():
    output = str(check_output("./p1"), "utf-8").strip()
    if output != "5":
        return f"p1 is supposed to compute and print 5, but it printed {output}."
    return None

def test6_struct():
    return cpp_test("test6_struct")

def test7_dropzero():
    return cpp_test("test7_dropzero")

def test8_average():
    return cpp_test("test8_average")

def test9_divide():
    return cpp_test("test9_divide")
    
def test10_p2_program():
    remove_if_exists("p2")
    run_and_check("make p2")
    assert exists("p2")

    output = str(check_output("./p2"), "utf-8")
    output = output.strip().split("\n")
    if output[-1] != "2.5":
        return f"p2 is supposed to compute and print 2.5 (as the last line), but it printed {output[-1]}."
    return None

def linter():
    for name in ["sparrow.h", "sparrow.cpp"]:
        with open(name) as f:
            code = f.read()
            if "printf" in code:
                return f"printf found in {name} -- that's not allowed."
            if "malloc" in code:
                return f"malloc found in {name} -- that's not allowed."

def main():
    # step 1: cleanup
    remove_if_exists("test.json")

    # step 2: enforce some basic rules, like no using malloc
    print("Running linter...")
    err = linter()
    if err:
        print(err)
        print("Exiting without running tests.")
        sys.exit(1)

    # step 3: run tests, and compute how many points they should get
    print("Running tests...")
    tests = [
        test1_build, test2_bitcounter, test3_overload, test4_bit_and, test5_p1_program,
        test6_struct, test7_dropzero, test8_average, test9_divide, test10_p2_program
    ]

    points = {}
    for test_fn in tests:
        print()
        print("="*40)
        print(test_fn.__name__)
        print("="*40)
        try:
            err = test_fn()
            if err:
                print(err)
            if err:
                print("Result: FAIL")
            else:
                print("Result: PASS")
        except Exception as ex:
            err = "exception"
            print(traceback.format_exc())
            print("Result: FAIL (exception)")
        points[test_fn.__name__] = 0 if err else TEST_WEIGHT
        if err and not "-a" in sys.argv:
                break

    # step 4: save/display results
    print()
    print("="*40)
    print("RESULTS (saved to test.json)")
    print("="*40)
    points_str = json.dumps(points, indent=2) + "\n"
    print(points_str)
    with open("test.json", "w") as f:
        f.write(points_str)

if __name__ == '__main__':
     main()
