#include <iostream>

using namespace std;

class Complex
{
    private:
        int Real;
        int Img;

    public:

        /// Constructors  (Overloading)
        Complex(int r, int i)
        {
            this -> Real = r;
            this -> Img = i;
            cout << "\nParameterized Ctor with 2 values";
        }

        Complex(int c)
        {
            this -> Real = Img = c;
            cout << "\nParameterized Ctor with 1 values";
        }

        Complex()
        {
            this -> Real = Img = 0;
            cout << "\nParameterless Ctor";
        }


        /// Copy Constructor
        Complex(const Complex &S1)
        {
            cout<<"\ncopy Ctor";
            this -> Real = S1.Real;
            this -> Img  = S1.Img;
        }



        /// Destructor
        ~Complex()
        {
            cout << "\nI am Destructor";
        }





        /// Simplified Setting Real, Img     (Overloading)
        void setComplexValues(int r, int i)
        {
            this -> Real = r;
            this -> Img = i;
        }

        void setComplexValues(int N)
        {
            this -> Real = Img = N;
        }

        void setComplexValues()
        {
            this -> Real = Img = 0;
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
        Complex AddComplex (Complex C)
        {
            Complex Result;
            Result.setReal(this -> Real + C.getReal() );
            Result.setImg(this -> Img + C.getImg() );
            return Result;
        }

        Complex SubComplex (Complex C)
        {
            Complex Result;
            Result.setReal(this -> Real - C.getReal() );
            Result.setImg(this -> Img - C.getImg() );
            return Result;
        }

        void PrintComplex();


};



void Complex:: PrintComplex()
        {
            cout << "\n";
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


int main()
{
//
    Complex C1(3,4);
    C1.PrintComplex();

    Complex C2(5);
    C2.PrintComplex();

    Complex C3;
    C3.PrintComplex();

    C3 = C1.AddComplex(C2);

    C3.PrintComplex();

/*
    Complex C1(3,4), C2(5), C3;
    C3 = C1.AddComplex(C2);

    C3.PrintComplex();
*/
    return 0;
}
