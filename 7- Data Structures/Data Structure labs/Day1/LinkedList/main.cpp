#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {
    LinkedList mylist;
    mylist.Append(10);
    mylist.Append(20);
    mylist.Append(30);
    mylist.Display();

    cout << "Insert 15 after 10:" << endl;
    mylist.InsertAfter(15, 10);
    mylist.Display();

    cout << "Insert 5 before 10:" << endl;
    mylist.InsertBefore(5, 10);
    mylist.Display();

    cout << "Number of nodes: " << mylist.Getcounter() << endl;

    cout << "Data at index 0: " << mylist.GetDataByIndex(0) << endl;
    cout << "Data at index 2: " << mylist.GetDataByIndex(2) << endl;
    cout << "Data at index 4: " << mylist.GetDataByIndex(4) << endl;

    return 0;
}
