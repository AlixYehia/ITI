#include <iostream>
#include <cstdio>
using namespace std;

void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapByAddress: x = " << x << ", y = " << y << std::endl;
    swapByAddress(&x, &y);
    cout << "After swapByAddress: x = " << x << ", y = " << y << std::endl;

    return 0;
}
