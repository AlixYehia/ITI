#include <iostream>

using namespace std;

class Stack
{
    ///Member Data

    ///int stkArr[5];
    int* stkArr;
    int StkSize;
    int tos;

public:  ///Member Functions
    Stack()
    {
        this -> StkSize = 5;
        this -> stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        cout<<"\n I am Stack parameterized Ctor...!\n";
    }

    Stack(int Sz)
    {
        this -> StkSize = Sz;
        this -> stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        cout<<"\n I am Stack parameterized Ctor...!\n";
    }


    /// Copy Constructor
    Stack(const Stack &S1)
    {
        cout<<"\ncopy Ctor";
        this -> StkSize = S1.StkSize;
        this -> tos  = S1.tos;

        this -> stkArr = new int[StkSize];   /// object of viewcontent function

        for(int i=0; i<tos; i++)    ///deep copying
            this -> stkArr[i] = S1.stkArr[i];
    }



    ~Stack()
    {
        delete[] (this -> stkArr);
        cout<<"\n I am Stack Destructor...!\n";
    }

    bool IsFull()
    {
        return ( (this -> tos) == 5);

    }

    void Push(int Value)
    {
        if( (IsFull()) == false)
            stkArr[ (this -> tos++) ] = Value;
        else
            cout<<"\n Stack is Full........!!";
    }

    bool IsEmpty()
    {
        if( (this -> tos) == 0)
            return true;
        else
            return false;
    }

    int Pop()
    {
        if(IsEmpty() == false)
        {
            return stkArr[ --(this -> tos) ];
            cout<<"\n";
        }

        else
        {
            cout<<"\n Stak is Empty....!!";
            return -1;
        }
    }


    int Peak()
    {
        return (stkArr[ (this -> tos) -1 ]);
        cout<<"\n";
    }


    Stack Reverse()
    {
        Stack reversedStack(StkSize);  // Create a new stack to hold reversed elements

        // Push elements from temporary array into reversedStack in reverse order
        for (int i = (this -> tos) - 1; i >= 0; i--)
        {
            reversedStack.Push( (this -> stkArr[i]) );
        }

        return reversedStack;
    }





    void PrintStack()
    {
        if (IsEmpty())
        {
            cout << "\nStack is empty.";
            return;
        }
        cout << "\nStack elements: ";

        for (int i = 0; i < (this -> tos); i++)
        {
            cout << (this -> stkArr[i]) << "\n";
        }
        cout << endl;
    }


    friend void viewContent(Stack S);

};


/// Standalone Friend Function
void viewContent(Stack S)
{
    if (S.IsEmpty())
        {
            cout << "\nStack is empty.";
            return;
        }
        cout << "\nStack elements:\n";

        for (int i = 0; i < (S.tos); i++)
        {
            cout << (S.stkArr[i]) << "\n";
        }
        cout << endl;
}


int main()
{

//
//    Stack S1(5);
//
//	S1.Push(10);
//	S1.Push(20);
//	S1.Push(30);
//
//	cout<< S1.Peak() << "\n"; //30
//	cout<< S1.Peak() << "\n"; //30
//
//	cout<< S1.Pop() << "\n"; //30
//	cout<< S1.Pop() << "\n"; //20
//
//	Stack S2(5);
//
//	S2.Push(3);
//	S2.Push(4);
//	S2.Push(5);
//	S2.Push(6);
//
//	cout<< S2.Reverse().Pop() ;
//


///************* Copy Ctor Case(1): Pass by value to function ********************

    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    viewContent(S1);

    cout<<"Num = "<<S1.Pop()<<endl;
    cout<<"Num = "<<S1.Pop()<<endl;


///************* Copy Ctor Case(2): Return by value from function ********************
//
//    Stack S1;
//
//    S1.Push(10);
//    S1.Push(20);
//    S1.Push(30);
//    S1.Push(40);
//
//    //Stack SS = S1.Reverse();
//    //cout<SS.Pop();
//
//    cout<<S1.Reverse().Pop();
//
///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************
//
//    Stack S1;
//
//    S1.Push(10);
//    S1.Push(20);
//    S1.Push(30);
//    S1.Push(40);
//
//    Stack S3 ( S1 );
//
//    for(int i=0; i<10; i++)
//    S3.Pop();
//
//
//    for(int i=0; i<10; i++)
//        S3.Push(-1);
//
//    cout<<"Num\n = "<<S1.Pop()<<endl;
//    cout<<"Num\n = "<<S1.Pop()<<endl;
//



    return 0;
}
