#include <iostream>

using namespace std;

/// 2nd Type of Polymorphism (Dynamic Binding)


class Parent
{
private:
    int x;
protected:
    int y;     /// Since protected all my inheritors can access it directly
public:
    /// Constructors
    Parent()
    {
        x = 0;
        y = 0;
        cout << "\nParent parameterless Ctor...";
    }
    Parent(int N1, int N2)
    {
        x = N1;
        y = N2;
        cout << "\nParent 2 parameters Ctor...";
    }

    /// Destructor
    ~Parent()
    {
        x = 0;
        y = 0;
        cout << "\nParent Destructor!";
    }

    /// Getters
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    /// Setters
    void SetX(int num)
    {
        x = num;
    }
    void setY(int num)
    {
        y = num;
    }

    /// function
    int Sum_X_Y()
    {
        return x + y;
    }

    int Sum()
    {
        return x + y;
    }

};



class Child : public Parent  /// ':' means inherit from  'public' means inherit all except private which needs getters/setters
{                            ///                          and if didn't set as public default will be private
private:
    int z;
public:
    /// Constructors
    Child() : Parent()
    {
        z = 0;
        cout << "\nChild parameterless Ctor...";
    }
    Child(int N1, int N2, int N3) : Parent(N1, N2)   /// ':' means jump to (Constructor Chaining)
    {
        z = N3;
        cout << "\nChild 3 parameters Ctor...";
    }

    /// Destructor
    ~Child()
    {
        z = 0;
        cout << "\nChild Destructor!";
    }

    /// Getters
    int getZ()
    {
        return z;
    }

    /// Setters
    void SetZ(int num)
    {
        z = num;
    }

    /// function
    int Sum_X_Y_Z()
    {
        return getX() + y + z;
    }

    int Sum()
    {
        return getX() + y + z;
    }

};



class GrandChild : public Child  /// ':' means inherit from  'public' means inherit all except private which needs getters/setters
{
private:
    int m;
public:
    /// Constructors
    GrandChild() : Child()
    {
        m = 0;
        cout << "\nGrandChild parameterless Ctor...";
    }
    GrandChild(int N1, int N2, int N3, int N4) : Child(N1, N2, N3)   /// ':' means jump to (Constructor Chaining)
    {
        m = N4;
        cout << "\nGrandChild 4 parameters Ctor...";
    }

    /// Destructor
    ~GrandChild()
    {
        m = 0;
        cout << "\nGrandChild Destructor!";
    }

    /// Getters
    int getM()
    {
        return m;
    }

    /// Setters
    void SetM(int num)
    {
        m = num;
    }

    /// function
    int Sum()
    {
        ///return getX() + y + getZ() + m;
        ///return Child::Sum()+ m;                                   /// equivalent to the above
        ///return Parent::Sum() + getZ() + m;                        /// equivalent to the above
        return Parent::Sum() + Child::Sum() - Parent::Sum() + m;     /// equivalent to the above
    }

};




int main()
{
    Parent P (2, 5);
    cout<< endl << P.Sum_X_Y();

    Child Chd (2, 3, 4);
    cout<< endl << "Chd.Sum_X_Y_Z() = " << Chd.Sum_X_Y_Z();     /// 9

    cout<< endl << "P.Sum() = " << P.Sum();       /// 7  /// we made this so we know even if all inheritors have the same function name accessing it with the the class object will refer to that specific class
    cout<< endl << "Chd.Sum() = " << Chd.Sum();   /// 9 /// we made this so we know even if all inheritors have the same function name accessing it with the the class object will refer to that specific class

    GrandChild GC (2, 3, 4, 5);
    cout<< endl << "GC.Sum_X_Y_Z_M() = " << GC.Sum();     /// 14



    ///P.x;  ///Incorrect - private                     needs getters
    ///P.y;  ///Incorrect - protected
    ///P.z;  ///Incorrect - z is not member of parent

    ///Chd.x;  ///Incorrect - private                   needs getters
    ///Chd.y;  ///Incorrect - protected
    ///Chd.z;  ///Incorrect - private                   needs getters



    return 0;
}
