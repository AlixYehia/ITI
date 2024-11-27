#include <iostream>

using namespace std;

#include "Stack.h"

int main()
{

    Stack stk;
    stk.push(10) ? cout<<"Data Entered \n":cout<<"Data Not Entered \n";
    stk.push(20) ? cout<<"Data Entered \n":cout<<"Data Not Entered \n";
    stk.push(30) ? cout<<"Data Entered \n":cout<<"Data Not Entered \n";
    stk.push(40) ? cout<<"Data Entered \n":cout<<"Data Not Entered \n";
    stk.push(50) ? cout<<"Data Entered \n":cout<<"Data Not Entered \n";

    stk.display();

    int data;
    while(stk.pop(data)){
        cout<<"POP Success \n data = "<<data<<endl;
    }

    return 0;
}
