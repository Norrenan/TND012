// ===============================================================
// TND012: Practical Lesson 9
// Exercise 1: to test the debugger
//
// Set a breakpoint
// Step from instruction to instruction, e.g. loops (F10)
// Inspect variables values
// Step into/out a function (F11 and Shift+F11)
// Run to a point in the code quickly using the mouse
// ===============================================================

#include <iostream>
#include <string>

using namespace std;

int foo(unsigned n) {
    int sum = 0;

    while (n >= 0) {
        sum += n;

        n -= 2;
    }

    return sum;
}

int main() {

    unsigned value = 0;

    cout << "Enter a non-negative integer: ";
    cin >> value;

    int res = foo(value);

    cout << "Result = " << res << endl;

    return 0;
}
