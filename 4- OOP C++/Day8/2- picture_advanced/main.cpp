#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

class Shape
{
protected:
    int ShapeColor;

public:
    Shape()
    {
        ShapeColor = 15; ///White
        cout << "\n Shape Param-less Ctor";
    }

    Shape(int c)
    {
        ShapeColor = c;
        cout << "\n Shape One-Param Ctor";
    }

    void setMyColor(int c)
    {
        ShapeColor = c;
    }

    /// virtual function left with empty implementation for late binding (will be inherited for all child classes and won't make them abstract since it is not pure virtual so no need to override it in child classes)

    ///virtual void setFilled(bool) {}


    ///***************************************************************************** NOTE **************************************************************************************************///

    /// In here I made it pure virtual just to to override it in the child classes for testing purposes and learn that I can prevent them from being abstracted once I override this function
    virtual void setFilled(bool) = 0;


    virtual void Draw() = 0; ///Force every child class inherit shape to override Draw function
};


class Point
{
    int X;
    int Y;
public:
    Point()
    {
        X = Y = 0;
        cout<< "\nPoint Param-less Ctor";
    }

    Point(int n)
    {
        X = Y = n;
        cout<< "\nPoint One-Param Ctor";
    }

    Point(int n1, int n2)
    {
        X = n1;
        Y = n2;
        cout<< "\nPoint Two-Param Ctor";
    }

    ~Point()
    {
        cout<< "\nPoint Destructor";
    }


    void setX(int x)
    {
        X = x;
    }

    void setY(int y)
    {
        Y = y;
    }

    int getX()
    {
        return X;
    }

    int getY()
    {
        return Y;
    }

};



class Line : public Shape
{
    Point Start;   /// Composition relationship (Obj of Point inside Line)
    Point End;
public:
    Line() /// : Start(), End()
    {
        ///Start.setX(0);    /// Wafr 3la nafsk kda kda Point() Hysfrhom Less frames in memory
        ///Start.setY(0);

        ///End.setX(0);
        ///End.setY(0);

        cout<< "\nLine Param-less Ctor";
    }

    Line(int N1, int N2, int N3, int N4, int c) : Start(N1, N2), End(N3, N4)
    {
        ShapeColor = c;

        ///Start.setX(N1);
        ///Start.setY(N2);

        ///End.setX(N3);
        ///End.setY(N4);

        cout<< "\nLine 4 Param Ctor";
    }

    Line(Point P1, Point P2, int c) : Start( P1.getX(), P1.getY() ), End( P2.getX(), P2.getY() )
    {
        ShapeColor = c;

        ///Start.setX( P1.getX() );
        ///Start.setY( P1.getY() );

        ///End.setX( P2.getX() );
        ///End.setY( P2.getY() );

        cout<< "\nLine with 2 Points Ctor";
    }


    void setFilled(bool) override {}  /// Empty implementation for Line to avoid being abstract


    void Draw()
    {
        setcolor(ShapeColor);
        /// Built-in Function to draw line in Graphics
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }



    ~Line()
    {
        cout<< "\nLine Destructor";
    }

};



class Rect : public Shape
{
    Point Upper_Left;   /// Composition relationship (Obj of Point inside Rect)
    Point Lower_Right;
public:
    Rect() : Upper_Left(), Lower_Right(), Shape()
    {

        ///Upper_Left.setX(0);    /// Wafr 3la nafsk kda kda Point() Hysfrhom Less frames in memory
        ///Upper_Left.setY(0);

        ///Lower_Right.setX(0);
        ///Lower_Right.setY(0);

        cout<< "\nRect Param-less Ctor";
    }

    Rect(int N1, int N2, int N3, int N4, int c) : Upper_Left(N1, N2), Lower_Right(N3, N4)
    {
        ShapeColor = c;

        ///Upper_Left.setX(N1);
        ///Upper_Left.setY(N2);

        ///Lower_Right.setX(N3);
        ///Lower_Right.setY(N4);

        cout<< "\nRect 4 Param Ctor";
    }

    Rect(Point P1, Point P2, int c) : Upper_Left( P1.getX(), P1.getY() ), Lower_Right( P2.getX(), P2.getY() )
    {
        ShapeColor = c;

        ///Upper_Left.setX( P1.getX() );
        ///Upper_Left.setY( P1.getY() );

        ///Lower_Right.setX( P2.getX() );
        ///Lower_Right.setY( P2.getY() );

        cout<< "\nPoint with 2 Points Ctor";
    }


    void setFilled(bool) override {}   /// Empty implementation to avoid being abstract


    void Draw()
    {
        setcolor(ShapeColor);
        /// Built-in Function to draw Rect in Graphics
        rectangle(Upper_Left.getX(), Upper_Left.getY(), Lower_Right.getX(), Lower_Right.getY());
    }



    ~Rect()
    {
        cout<< "\nRect Destructor";
    }

};


class Circle : public Shape
{
    Point Center;   /// Composition relationship (Obj of Point inside Circle)
    int Radius;
    bool filled;
public:
    Circle() : Center(), Radius(0), filled(false)
    {
        cout<< "\nCircle Param-less Ctor";
    }

    Circle(int N1, int N2, int r, int c) : Center(N1, N2), Radius(r), filled(false)
    {
        ShapeColor = c;
        cout<< "\nCircle 3 Param Ctor";
    }

    Circle(Point P1, int r, int c) : Center(P1.getX(), P1.getY()), Radius(r), filled(false)
    {
        ShapeColor = c;
        cout<< "\nCircle with 1 Point Ctor";
    }


    bool isFilled() const { return filled; } /// Method to check if circle is filled

    void setFilled(bool _filled)
    {
        filled = _filled;
    }



    void Draw()
    {
        if (filled)
        {
            setcolor(ShapeColor);
            setfillstyle(SOLID_FILL, ShapeColor);
            fillellipse(Center.getX(), Center.getY(), Radius, Radius);
        } else
        {
            setcolor(ShapeColor);
            circle(Center.getX(), Center.getY(), Radius);
        }
    }

    void toggleFill()
    {
        filled = !filled;
    }

    ~Circle()
    {
        cout<< "\nCircle Destructor";
    }
};


class Picture
{
    Shape** pShapes;  /// Shape* pShapes[3];
    int shNum;

public:
    Picture()
    {
        pShapes = NULL;
        shNum = 0;
    }

    Picture(Shape** shPtr, int shN)
    {
        pShapes = shPtr;
        shNum = shN;
    }

    void setShapes(Shape** shPtr, int shN)
    {
        pShapes = shPtr;
        shNum = shN;
    }

    void Paint()
    {
        for(int i=0; i<shNum; i++)
        {
            pShapes[i]->Draw();
        }
    }
};


int main()
{
    cout << "Hello Graphics world" << endl;

    initwindow(400,500);  /// Opens Graphics Window

    Line L(160, 150, 240, 150, 9);
    Rect R(195, 80, 205, 110, 14);
    Circle C0(80, 50, 30, 4);
    Circle C1(200, 100, 100, 2);
    Circle C2(320, 50, 30, 5);
    Circle C3(160, 70, 10, 7);
    Circle C4(250, 70, 10, 3);

    Shape* ShapeArr[7];

    ShapeArr[0] = &L;
    ShapeArr[1] = &R;
    ShapeArr[2] = &C0;
    ShapeArr[3] = &C1;
    ShapeArr[4] = &C2;
    ShapeArr[5] = &C3;
    ShapeArr[6] = &C4;

    Picture myPic;

    myPic.setShapes(ShapeArr, 7);
    myPic.Paint();


    while (1)
    {
        char ch = getch();
        if (ch == 32)
        {

            C3.setFilled(!C3.isFilled());
            C4.setFilled(!C4.isFilled());

            cleardevice();
            myPic.Paint();
        }

        else if (ch == 27)
        {
            break;
        }
    }

    getch();
    closegraph();  /// Close


    return 0;
}
