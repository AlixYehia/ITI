#include <iostream>
#include <math.h>

using namespace std;

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


    float CalcArea()
    {
        cout << "Geoshape CalcArea Method....";
        return 0;
    }

};


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


class Square : protected GeoShape
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


class Circle : protected GeoShape
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



int main()
{
    Rectangle R(2,3);
    cout<< endl << R.CalcArea();

    R.setDim1(9);
    R.setDim1(8);
    cout<< endl << "Rectangle Set dimensions method\n" << R.CalcArea();

    Square S(5);
    cout<< endl << S.CalcArea();

    S.setDims(5);
    cout<< endl << "Square Set dimension method\n" << S.CalcArea();

    /// need to prevent this by using protected
    ///S.setDim1(5);
    ///S.setDim2(6);

    Circle C(3);
    cout<< endl << C.CalcArea();

    C.setDims(3);
    cout<< endl << " Circle Set dimension method\n" << C.CalcArea();


    Triangle T(2,4);
    cout<< endl << T.CalcArea();

    T.setDims(2, 4);
    cout<< endl << " Triangle Set dimension method\n" << T.CalcArea();



    return 0;
}
