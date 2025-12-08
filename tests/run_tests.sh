#!/usr/bin/env bash
set -e

g++ -std=c++17 main.cpp scheduler.cpp -o sched

passed=0
total=1

run() {
    input=$1
    expected=$2

    ./sched < $input > out.txt

    if diff -q out.txt $expected > /dev/null; then
        echo "PASS $input"
        passed=$((passed+1))
    else
        echo "FAIL $input"
        diff out.txt $expected
    fi
}

run tests/input1.txt tests/output1.txt

echo "$passed / $total tests passed."

if [ $passed -eq $total ]; then exit 0; else exit 1; fi
