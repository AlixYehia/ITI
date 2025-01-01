#include <iostream>

using namespace std;

int SUM(int x=0, int y=0, int z=0)
{
    return(x+y+z);
}


int main()
{
    int x,y,z;
    int result;

    cout << "\n******************* 3 Values Case *********************\n";

    cout << "Enter 1st no. to add to summation: ";
    cin >> x;

    cout << "Enter 2nd no. to add to summation: ";
    cin >> y;

    cout << "Enter 3rd no. to add to summation: ";
    cin >> z;

    result = SUM(x, y ,z);
    cout << "Result = " << result << endl;

    cout << "\n******************* 2 Values Case *********************\n";


    cout << "Enter 1st no. to add to summation: ";
    cin >> x;

    cout << "Enter 2nd no. to add to summation: ";
    cin >> y;

    result = SUM(x, y);
    cout << "Result = " << result << endl;


    cout << "\n******************* 1 Value Case *********************\n";


    cout << "Enter 1st no. to add to summation: ";
    cin >> x;

    result = SUM(x);
    cout << "Result = " << result << endl;


    cout << "\n******************* No Values Case *********************\n";


    result = SUM();
    cout << "Result = " << result << endl;


    return 0;
}
