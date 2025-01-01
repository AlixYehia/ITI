#include <iostream>
#include <cstring>  // For strcpy and strcat

using namespace std;

class myTestClass
{
private:
    int Number;
    char C;

public:

    /// Setters
    void setNum(int num)
    {
        Number = num;
    }

    void setChar(char c)
    {
        C = c;
    }

    /// Getters
    int getNum()
    {
        return Number;
    }

    char getChar()
    {
        return C;
    }

    /// Member functions (Overloading)

    ////////////// Integers ////////////////
    int Add(int N1, int N2)
    {
        return N1 + N2;  // Return the sum directly
    }

    int Add(int N1, int N2, int N3)
    {
        return N1 + N2 + N3;  // Return the sum directly
    }

    ////////////// Characters ////////////////
    void Add(char c1, char c2, char c3)
    {
        cout << c1 << c2 << c3 << endl;
    }

    ////////////// Strings ////////////////
    void Add(char* str1, char* str2)
    {
        char Result[100];
        strcpy(Result, str1);
        strcat(Result, str2);
        cout << Result << endl;
    }
};

int main()
{
    myTestClass object;
    int x, y, z;

    // Get input for integer addition
    cout << "Enter Number 1: ";
    cin >> x;

    cout << "Enter Number 2: ";
    cin >> y;

    cout << "Enter Number 3: ";
    cin >> z;

    // Add two integers
    int result1 = object.Add(x, y);
    cout << "Sum of two numbers: " << result1 << endl;

    // Add three integers
    int result2 = object.Add(x, y, z);
    cout << "Sum of three numbers: " << result2 << endl;

    // Concatenate characters
    object.Add('a', 'b', 'c');

    // Concatenate two strings
    char str1[] = "ALI, ";
    char str2[] = "-----";
    object.Add(str1, str2);

    return 0;
}

