#include <iostream>

using namespace std;

class Stack
{

private:

    ///Member Data

    /// Static Counter seen by all class
    static int counter;

    ///int stkArr[5];
    int* stkArr;
    int StkSize;
    int tos;

public:

    ///Member Functions


    static int getCounter()
    {
        return counter;
    }


    Stack()
    {
        this -> StkSize = 5;
        this -> stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        //cout<<"\n I am Stack parameterized Ctor...!\n";
        counter++;
        cout << "Objects created = " << Stack::getCounter() << "\n";
    }

    Stack(int Sz)
    {
        this -> StkSize = Sz;
        this -> stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        //cout<<"\n I am Stack parameterized Ctor...!\n";
        counter++;
        cout << "Objects created = " << Stack::getCounter() << "\n";
    }

//*****************************************************//

    /// Copy Constructor
    Stack(const Stack &S1)
    {
        //cout<<"\ncopy Ctor";
        this -> StkSize = S1.StkSize;
        this -> tos  = S1.tos;

        this -> stkArr = new int[StkSize];   /// object of viewcontent function

        for(int i=0; i<tos; i++)    ///deep copying
            this -> stkArr[i] = S1.stkArr[i];

        counter++;
        cout << "Objects created = " << Stack::getCounter() << "\n";
    }


    /// De-constructor
    ~Stack()
    {
        delete[] (this -> stkArr);
        //cout<<"\n I am Stack Destructor...!\n";
        counter--;
        cout << "Destroyed = 1 Object counter at " << Stack::getCounter() << "\n";
    }


//*****************************************************//

    bool IsFull()
    {
        return ( (this -> tos) == 5);

    }


    bool IsEmpty()
    {
        if( (this -> tos) == 0)
            return true;
        else
            return false;
    }

//*****************************************************//

    void Push(int Value)
    {
        if( (IsFull()) == false)
            stkArr[ (this -> tos++) ] = Value;
        else
            cout<<"\n Stack is Full........!!";
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

//*****************************************************//


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



//*****************************************************//

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
            cout << "\n" << (this -> stkArr[i]) << "\n";
        }
        cout << endl;
    }


    friend void viewContent(Stack S);



    Stack& operator= (const Stack &S)    /// S1 = S2
        {
            if (this != &S)  /// Self-assignment check to avoid creating new frame without need
            {
                this -> StkSize = S.StkSize;
                this -> tos  = S.tos;
                delete[] this -> stkArr;

                this -> stkArr = new int[StkSize];

                for(int i=0; i< this-> tos; i++)    ///deep copying
                this -> stkArr[i] = S.stkArr[i];
            }



            return *this;     /// or S since both equal
        }



    Stack operator+ (const Stack &S)             /// S3 = S1 + S2
    {
        Stack Result;
        Result.StkSize = this -> StkSize + S.StkSize ;
        Result.tos = this -> tos + S.tos ;

        Result.stkArr = new int[Result.StkSize];

            ///deep copying of S1 to result
            for(int i=0; i< this-> tos; i++)
                 Result.stkArr[i] = this -> stkArr[i];

            ///deep copying of S2 to result
            for(int i = 0 ; i< S.tos; i++)
                 Result.stkArr[this -> tos + i] = S.stkArr[i];


        return Result;

    }



    int& operator[](int index)             /// S1[i] / S1[i] = X
    {
        if (index < 0 || index >= tos)
        {
            cout << "\nIndex out of range";
        }

        return stkArr[index]; // Return the reference to the element to modify
    }




};


/// Standalone Friend Function
void viewContent(Stack S)
{
    if (S.IsEmpty())
        {
            cout << "\nStack is empty.";
            return;
        }
        cout << "\nStack elements:";

        for (int i = 0; i < (S.tos); i++)
        {
            cout << (S.stkArr[i]) << "\n";
        }
        cout << endl;
}





ostream& operator<< (ostream &out, Stack &S)
{
//    out << C.getReal();
//    if (C.getImg() >= 0) out << "+";
//    out << C.getImg() << "i";

}



int Stack::counter=0;


int main()
{


    Stack S1(3), S2(4), S3;

	S1.Push(10);
	S1.Push(20);
	S1.Push(30);

	//cout<< S1.Peak() << "\n"; //30
	//cout<< S1.Peak() << "\n"; //30

	//cout<< S1.Pop() << "\n"; //30
	//cout<< S1.Pop() << "\n"; //20

	S2.Push(3);
	S2.Push(4);
	S2.Push(5);
	S2.Push(6);

	S1 = S2;


	cout << "S2";
	S2.PrintStack();

	cout << "S1";
	S1.PrintStack();

	S3 = S1 + S2;

	cout << "S3";
	S3.PrintStack();

	cout<< "S1[3] = " << S1[3] << "\n";

	cout<< "S1[3] = 8 ----> ";
	S1[3] = 8;
	cout << S1[3] << "\n";



	//cout<< S2.Reverse().Pop() ;


    return 0;

}
