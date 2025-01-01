#include <iostream>
#include <math.h>

using namespace std;


class Complex
{
    private:
        int Real;
        int Img;

    public:

        /// Constructors  (default) of 3 cases
        Complex(int r=0, int i=0)
        {
            this -> Real = r;
            this -> Img = i;
            //cout << "\nParameterized Default Ctor";
        }


        /// Copy Constructor
        Complex(const Complex &S1)
        {
            //cout<<"\ncopy Ctor";
            this -> Real = S1.Real;
            this -> Img  = S1.Img;
        }


        /// Destructor
        ~Complex()
        {
            //cout << "\nI am Destructor";
        }




        /// Simplified Setting Real, Img  (Default)
        void setComplexValues(int r=0, int i=0)
        {
            this -> Real = r;
            this -> Img = i;
        }


        /// Setters
        void setReal(int R)
        {
            this -> Real = R;
        }
        void setImg(int I)
        {
            this -> Img = I;
        }

        /// Getters
        int getReal()
        {
            return Real;
        }
        int getImg()
        {
            return Img;
        }


        /// Member functions
        Complex operator+ (Complex C)             /// C3 = C1 + C2
        {
            Complex Result;
            Result.setReal(this -> Real + C.getReal() );
            Result.setImg(this -> Img + C.getImg() );
            return Result;
        }

        Complex operator- (Complex C)             /// C3 = C1 - C2
        {
            Complex Result;
            Result.setReal(this -> Real - C.getReal() );
            Result.setImg(this -> Img - C.getImg() );
            return Result;
        }


        Complex& operator- (const int &num)    /// C3 = C2 - 7
        {
            Complex Result(this-> Real - num, this-> Img);

            return Result;
        }



        Complex& operator-= (const Complex &C)    /// C1 -= C2  /// if used const cant call function or use setReal or setImg getReal or getImg
        {
            this->Real = this->Real - C.Real;

            this->Img = this->Img - C.Img;

//           this->Real -= C.Real;
//           this->Img -= C.Img;

            return *this;
        }



        Complex operator-- ()    /// Prefix   C2 = --C1
        {
            Complex Result(-- this-> Real, this-> Img);

            return Result;
        }



        Complex operator-- (int)    /// Postfix   C2 = C1--
        {
            Complex Temp (*this);   /// equivalent to (this-> Real -- , this-> Img);
            this-> Real --;

            return Temp;
        }



        Complex operator= (Complex C)    /// C1 = C2
        {
            this->Real = C.Real;    /// or C.getReal() since it is member no need for get

            this->Img = C.Img;      /// or C.getImg() since it is member no need for get

            return C;               /// equivalent to return *this since C and *this equal
        }



        bool operator== (Complex C)    /// C1 == C2        // can be bool or int since 0 or 1
        {
            return (this-> Real == C.Real && this-> Img == C.Img);
        }



        int operator!= (Complex C)    /// C1 != C2        // can be bool or int since 0 or 1
        {
            return (this-> Real != C.Real || this-> Img != C.Img);
        }




        bool operator> (Complex C)    /// C1 > C2        // can be bool or int since 0 or 1
        {
            float CRes1;
            float CRes2;

            CRes1 = sqrt( (this-> Real)*(this-> Real) + (this-> Img)*(this-> Img) );

            CRes2 = sqrt( (C.Real)*(C.Real) + (C.Img)*(C.Img) );

            return (CRes1 > CRes2);
        }



        bool operator>= (Complex C)    /// C1 >= C2        // can be bool or int since 0 or 1
        {
            float CRes1;
            float CRes2;

            CRes1 = sqrt( (this-> Real)*(this-> Real) + (this-> Img)*(this-> Img) );

            CRes2 = sqrt( (C.Real)*(C.Real) + (C.Img)*(C.Img) );

            return (CRes1 >= CRes2);
        }



        bool operator< (const Complex &C)    /// C1 < C2        // can be bool or int since 0 or 1
        {
            float CRes1;
            float CRes2;

            CRes1 = sqrt( (this-> Real)*(this-> Real) + (this-> Img)*(this-> Img) );

            CRes2 = sqrt( (C.Real)*(C.Real) + (C.Img)*(C.Img) );

            return (CRes1 > CRes2);
        }



        bool operator<= (const Complex &C)    /// C1 <= C2        // can be bool or int since 0 or 1
        {
            float CRes1;
            float CRes2;

            CRes1 = sqrt( (this-> Real)*(this-> Real) + (this-> Img)*(this-> Img) );

            CRes2 = sqrt( (C.Real)*(C.Real) + (C.Img)*(C.Img) );

            return (CRes1 >= CRes2);
        }


        int operator[] (char ch)   ///   << C1['R'] / C1['I']  // extracting real or imaginary part   // casting
        {
            if(ch=='R' || ch=='r')
                return this->Real;

            else if(ch=='I' || ch=='i')
                return this->Img;
            else
                return -1;
        }



/*no return type*/  operator int ()           ///  (int) C1      // casting
                {
                        return this -> Real + this -> Img;
                }


       void PrintComplex()
        {
            //cout << "\n";
            if (this -> Real != 0)
            {
                cout << this -> Real;
            }
            if (Img != 0)
            {
                if ( (this -> Img) > 0 && (this -> Real) != 0)
                {
                    cout << "+";
                }
                cout << (this -> Img) << "i";
            }
            if ( (this -> Real) == 0 && (this -> Img) == 0)
            {
                cout << "0";
            }
            cout << endl;
        }

};



template<class T>
class Stack
{

private:

    ///Member Data

    /// Static Counter seen by all class
    static int counter;

    ///int stkArr[5];
    T* stkArr;
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
        this -> stkArr = new T [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        //cout<<"\n I am Stack parameterized Ctor...!\n";
        counter++;
        cout << "\nObjects created = " << Stack::getCounter() << "\n";
    }

    Stack(int Sz)
    {
        this -> StkSize = Sz;
        this -> stkArr = new T [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        this -> tos = 0;  ///refer to first empty place to Push into
        //cout<<"\n I am Stack parameterized Ctor...!\n";
        counter++;
        cout << "\nObjects created = " << Stack::getCounter() << "\n";
    }

//*****************************************************//

    /// Copy Constructor
    Stack(const Stack &S1)
    {
        //cout<<"\ncopy Ctor";
        this -> StkSize = S1.StkSize;
        this -> tos  = S1.tos;

        this -> stkArr = new T[StkSize];   /// object of viewcontent function

        for(int i=0; i<tos; i++)    ///deep copying
            this -> stkArr[i] = S1.stkArr[i];

        counter++;
        cout << "\nObjects created = " << Stack::getCounter() << "\n";
    }


    /// De-constructor
    ~Stack()
    {
        delete[] (this -> stkArr);
        //cout<<"\n I am Stack Destructor...!\n";
        counter--;
        cout << "\nDestroyed = 1 Object counter at " << Stack::getCounter() << "\n";
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

    void Push(T Value);


    T Pop()
    {
        if(IsEmpty() == false)
        {
            return stkArr[ --(this -> tos) ];
            cout<<"\n";
        }

        else
        {
            cout<<"\n Stak is Empty....!!";
            return -1;   /// MODIFY SO CAN WORK WELL SINCE MAY WORK WITH CHAR, INT,ETC.
        }
    }

//*****************************************************//


    T Peak()
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




    Stack& operator= (const Stack &S)    /// S1 = S2
        {
            this -> StkSize = S.StkSize;
            this -> tos  = S.tos;
            delete[] this -> stkArr;

            this -> stkArr = new int[StkSize];

            for(int i=0; i< this-> tos; i++)    ///deep copying
                this -> stkArr[i] = S.stkArr[i];


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



    int& operator[](int index)             /// S1[i] / S1[i]
    {
        if (index < 0 || index >= tos)
        {
            cout << "\nIndex out of range";
        }

        return stkArr[index]; // Return the reference to the element to modify
    }




};

template<typename T>
int Stack<T>::counter=0;



template<typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


/////////////////////////////////////////////////
template<class T>
void Stack<T>::Push(T Value)      /// Since of of class must say Stack<T>
{
    if( (IsFull()) == false)
        stkArr[ (this -> tos++) ] = Value;
    else
        cout<<"\n Stack is Full........!!";
}
/////////////////////////////////////////////////


int main()
{
    /// IN CLASSES MUST PUT THE TYPE SINCE COMPILER CANT INFER TYPE


    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.PrintComplex();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.PrintComplex();

    Stack<int> S;
    S.Push(10);
    S.Push(20);
    cout<< S.Pop();

    Stack<char> S2(3);
    S2.Push('A');
    S2.Push('B');
    S2.Push('C');
    cout<< S2.Pop();

    Stack<Complex> S3(4);
    S3.Push(C1);
    S3.Push(C2);
    Complex C = S3.Pop();
    C.PrintComplex();
}
