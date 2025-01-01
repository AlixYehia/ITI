#include <iostream>
#include <math.h>

using namespace std;

/// Abstract class
/// Class has at least one pure virtual function
/// Class I can't create any object from it "class just for design" if it has at least one virtual function
class GeoShape
{
protected:
    int Dim1;
    int Dim2;
public:
    GeoShape()
    {
        Dim1 = Dim2 = 0;
        cout<< "\nGeoShape Param-less Ctor";
    }

    GeoShape(int n)
    {
        Dim1 = Dim2 = n;
        cout<< "\nGeoShape One-Param Ctor";
    }

    GeoShape(int n1, int n2)
    {
        Dim1 = n1;
        Dim2 = n2;
        cout<< "\nGeoShape Two-Param Ctor";
    }

    void setDim1(int n1)
    {
        Dim1 = n1;
    }

    void setDim2(int n2)
    {
        Dim2 = n2;
    }

    int getDim1()
    {
        return Dim1;
    }

    int getDim2()
    {
        return Dim2;
    }


    /// Pure virtual function when value is set to zero but if only virtual if not set to '0' (in other languages called Abstraction function)
    virtual float CalcArea() = 0;  /// I don't know its implementation therefore cant call it in main
};


/// Concrete Class
/// Must override (introduce implementation to) the virtual functions inherited from the design class so that these classes won't have any virtual functions and become concrete



class Rectangle : public GeoShape
{
public:
    Rectangle() : GeoShape()
    {

    }

    Rectangle(int a, int b) : GeoShape(a, b)
    {

    }

    float CalcArea()   /// Overriding
    {
        cout << "\nRectangle CalcArea Method....";
        return Dim1 * Dim2;  ///Only if Dim1 and Dim2 Protected
    }

};


class Square : public GeoShape
{
public:
    Square() : GeoShape()
    {

    }

    Square(int a) : GeoShape(a)
    {

    }

    ///
    void setDims(int n)
    {
        Dim1 = Dim2 = n;
    }
    ///


    float CalcArea()   /// Overriding so can access normally
    {
        cout << "\nSquare CalcArea Method....";
        return Dim1 * Dim2;  ///Only if Dim1 and Dim2 Protected
    }

};


class Circle : public GeoShape
{
public:
    Circle() : GeoShape()
    {

    }

    Circle(int r) : GeoShape(r)
    {

    }

    ///
    void setDims(int r)
    {
        Dim1 = Dim2 = r;
    }
    ///


    float CalcArea()   /// Overriding
    {
        cout << "\nCircle CalcArea Method....";
        return 3.14 * Dim1 * Dim2;  ///Only if Dim1 and Dim2 Protected
    }

};


class Triangle : public GeoShape
{
public:
    Triangle() : GeoShape()
    {

    }

    Triangle(int b, int h) : GeoShape(b, h)
    {

    }

    ///
    void setDims(int b, int h)
    {
        Dim1 = b;
        Dim2 = h;
    }
    ///


    float CalcArea()   /// Overriding
    {
        cout << "\nTriangle CalcArea Method....";
        return 0.5 * Dim1 * Dim2;  ///Only if Dim1 and Dim2 Protected
    }

};


/// Solid
/// Opened-Closed principle: Code should be Opened for Extension, but Closed for modifications

float SumOfAllShapesArea( GeoShape* ShArr[], int n )  /// Equivalent to GeoShape** Shape
{
    cout<< "\n\nSum of all shapes method";
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += ShArr[i]->CalcArea();

    return sum;
}


int main()
{
    Rectangle R(2,3);
    cout<< endl << R.CalcArea();

    Circle C(5);
    cout<< endl << C.CalcArea();

    Square S(4);
    cout<< endl << S.CalcArea();

    Triangle T(4,4);
    cout<< endl << T.CalcArea();

    GeoShape* Arr[4];
    Arr[0] = &R;
    Arr[1] = &C;
    Arr[2] = &S;
    Arr[3] = &T;


    cout << "\nSumOfAllShapesArea = " << SumOfAllShapesArea(Arr, 4);



    /// need to prevent this by using protected
//    S.setDim1(5);
//    S.setDim2(6);


    ///Virtual prevent using of design class
    //GeoShape G(4,7);




    return 0;
}
