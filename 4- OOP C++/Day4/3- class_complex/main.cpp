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



Complex operator- (int num, Complex C)    // C3 = 7 - C2   // Must be standalone since number cant call class
        {
            Complex Result(num - C.getReal(), C.getImg() );

            return Result;
        }


istream& operator>> (istream &in, Complex &C)                       // Must be standalone cin >> number cant call class
{
    int real, img;
    in >> real >> img;
    C.setReal(real);
    C.setImg(img);
    return in;
}



ostream& operator<< (ostream &out, Complex &C)
{
//    out << C.getReal();
//    if (C.getImg() >= 0) out << "+";
//    out << C.getImg() << "i";

    if (C.getReal() != 0)
            {
                cout << C.getReal();
            }
            if (C.getImg() != 0)
            {
                if ( (C.getImg()) > 0 && (C.getReal()) != 0)
                {
                    cout << "+";
                }
                cout << (C.getImg()) << "i";
            }
            if ( (C.getReal()) == 0 && (C.getImg()) == 0)
            {
                cout << "0";
            }

    return out;
}




int main() {
    Complex C1(3, 4), C2(1, 2), C3;

    cout <<"C1 = ";
    C1.PrintComplex();
    cout <<"\n";

    cout <<"C2 = ";
    C2.PrintComplex();
    cout <<"\n";


    /// Testing Addition (operator+)
    C3 = C1 + C2;
    cout << "C3 = C1 + C2: (" << C3.getReal() << ", " << C3.getImg() << ")\n";
    //cout << "C3 = C1 + C2: ";
    //C3.PrintComplex();


    /// Testing Subtraction (operator-)
    C3 = C1 - C2;
    //cout << "C3 = C1 - C2: (" << C3.Real << ", " << C3.Img << ")\n";
    cout << "\nC3 = C1 - C2: ";
    C3.PrintComplex();


    /// Testing Subtraction with number (operator- with int)
    C3 = C1 - 7;
    //cout << "C3 = C1 - 7: (" << C3.Real << ", " << C3.Img << ")\n";
    cout << "\nC3 = C1 - 7: ";
    C3.PrintComplex();


    /// Testing operator-=
    C1 -= C2;
    //cout << "C1 -= C2: (" << C1.Real << ", " << C1.Img << ")\n";
    cout << "\nC1 -= C2: ";
    C1.PrintComplex();


    /// Testing prefix decrement
    C3 = --C1;
    //cout << "Prefix --C1: (" << C3.Real << ", " << C3.Img << ")\n";
    cout << "\nC3 = --C1: ";
    C3.PrintComplex();


    /// Testing postfix decrement
    C3 = C1--;
    //cout << "Postfix C1--: (" << C3.Real << ", " << C3.Img << ")\n";
    //cout << "After postfix C1: (" << C1.Real << ", " << C1.Img << ")\n";
    cout << "\nC3 = C1--: ";
    C3.PrintComplex();


    /// Testing assignment operator
    C3 = C2;
    //cout << "C3 = C2: (" << C3.Real << ", " << C3.Img << ")\n";
    cout << "\nC3 = C2: ";
    C3.PrintComplex();


    cout <<"\nC1 = ";
    C1.PrintComplex();
    cout <<"\n";

    cout <<"C2 = ";
    C2.PrintComplex();
    cout <<"\n";



    /// Testing equality operator
    bool isEqual = (C1 == C2);
    cout << "C1 == C2: " << isEqual << "\n";

    /// Testing inequality operator
    bool isNotEqual = (C1 != C2);
    cout << "C1 != C2: " << isNotEqual << "\n";

    /// Testing greater than operator
    bool isGreater = (C1 > C2);
    cout << "C1 > C2: " << isGreater << "\n";

    /// Testing greater than or equal operator
    bool isGreaterEqual = (C1 >= C2);
    cout << "C1 >= C2: " << isGreaterEqual << "\n";

    // Testing less than operator
    bool isLess = (C1 < C2);
    cout << "C1 < C2: " << isLess << "\n";

    /// Testing less than or equal operator
    bool isLessEqual = (C1 <= C2);
    cout << "C1 <= C2: " << isLessEqual << "\n";

    /// Testing subscript operator for 'R' and 'I'
    cout << "C1['R']: " << C1['R'] << "\n";
    cout << "C1['I']: " << C1['I'] << "\n";

    /// Testing casting to int
    int intValue = int (C1);
    cout << "Casting C1 to int: " << intValue << "\n";

    cout << "Testing cin<< operator for complex\n";
    cout << "Enter Real then Imaginary: ";
    cin >> C1;

    cout << "Testing cout<< operator for complex\n";
    cout << C1;

    cout << "\nTesting cout chained";
    cout << endl << C1 << " and " << C2;

    return 0;

}
