#include <iostream>

/// (Late Binding) Dynamic Binding Rules:

/// 1- Existence of this function as Virtual function in *first* parent class in public section (Only in public inheritance)
/// 2- Override it in public section in child class
/// 3- Pointer from Parent type -> Child Obj

/// If all satisfied latest version of this method will be called for each call including the parent itself

///****************** NOTE******************///
/// Pointer from Child type -> Parent Obj ERROR ///

/// Every Child is a Parent but Every Parent isn't a Child ///


using namespace std;

class Base
{
public:
    int X;

    Base()
    {
        X = 0;
        cout<<"\n Base Param-Less Ctor";
    }

    Base(int x)
    {
        X = x;
        cout<<"\n Base Param-One  Ctor";
    }

    void MyMethod()
    {
        cout<<"\n Base Method.......";
    }


};


class Drived : public Base
{
public:
    int Y;

    Drived()
    {
        Y = 0;
        cout<<"\n Drived Param-Less Ctor";
    }

    Drived(int N) : Base(N)
    {
        Y = N;
        cout<<"\n Drived Param-One  Ctor";
    }

    Drived(int L, int M) : Base(L)
    {
        Y = M;
        cout<<"\n Drived Param-Two  Ctor";
    }

    virtual void MyMethod()
    {
        cout<<"\n Drived Method......";
    }


};


class Drived_2 : public Drived
{
public:
    int Z;

    Drived_2()
    {
        Z = 0;
        cout<<"\n Drived_2 Param-Less Ctor";
    }

    Drived_2(int G, int H, int J) : Drived(G,H)
    {
        Z = J;
        cout<<"\n Drived_2 Param-Two  Ctor";
    }

    void MyMethod()
    {
        cout<<"\n Drived_2 Method......";
    }


};


int main()
{
    Base B(4);
    cout<< "\n B.X = " << B.X;
    ///cout<< "\n B.Y = " << B.Y;  // Invalid
    B.MyMethod();

    Drived D(5,6);
    cout<< "\n D.X = " << D.X;
    cout<< "\n D.Y = " << D.Y;
    D.MyMethod();
    cout<<endl;

    Base* Bptr;
    Bptr = &B;
    cout<< "\n Bptr -> X = " << Bptr -> X;
    Bptr -> MyMethod(); /// this will still give me the current version of MyMethod since in late binding will see that Bptr points at B which is of class Base
    cout<<endl;

    Drived* Dptr;
    Dptr = &D;
    cout<< "\n Dptr -> X = " << Dptr -> X;
    cout<< "\n Dptr -> Y = " << Dptr -> Y;
    Dptr -> MyMethod();


    cout<<"\n******************************";

    Bptr = &D;  /// Since D is drived from base (inherited) then can use pointer of type base
    cout<< "\n Bptr -> X = " << Bptr -> X;
    ///cout<< "\n Bptr -> Y = " << Bptr -> Y;    // Base pointer doesn't have a member named Y


    cout<<"\n******************************";

    Drived_2 D2(10,20,30);
    cout<< "\n D2.X = " << D2.X;
    cout<< "\n D2.Y = " << D2.Y;
    cout<< "\n D2.Z = " << D2.Z;
    D2.MyMethod();

    Drived* D2ptr;
    D2ptr = &D2;
    cout<< "\n D2ptr -> X = " << D2ptr -> X;
    cout<< "\n D2ptr -> Y = " << D2ptr -> Y;
    ///cout<< "\n D2ptr -> Z = " << D2ptr -> Z;   /// Error since Z not defined in Drived class but in Drived_2 class

    cout<<endl;
    cout<<"\n virtual inheritance check for late binding (Drived -> Drived-2) with only Drived as Virtual and Base non Virtual";
    cout<<"\n ----------------------------------------------------------------------------------------------------------------";
    D2ptr -> MyMethod();
    cout<<endl;

    cout<<"\n virtual inheritance check for late binding (Base -> Drived-2) with only Drived as Virtual and Base non Virtual";
    cout<<"\n ---------------------------------------------------------------------------------------------------------------";
    Base* D2ptr2;
    D2ptr2 = &D2;
    D2ptr2 -> MyMethod();
    cout<<endl;

    return 0;
}
