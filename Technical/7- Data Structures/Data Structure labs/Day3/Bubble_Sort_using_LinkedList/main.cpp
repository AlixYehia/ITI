#include <iostream>
#include "LinkedList.h"
#include "BubbleSort.h"

using namespace std;

int main()
{
    LinkedList list;


    list.add(64);
    list.add(34);
    list.add(25);
    list.add(12);
    list.add(22);
    list.add(11);
    list.add(90);


    cout << "Original List: ";
    list.display();


    list.bubbleSort();


    cout << "Sorted List: ";
    list.display();

    return 0;
}
