#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << std::endl;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapByValue: x = " << x << ", y = " << y << std::endl;
    swapByValue(x, y);
    cout << "After swapByValue: x = " << x << ", y = " << y << std::endl;

    getchar();

    return 0;
}
