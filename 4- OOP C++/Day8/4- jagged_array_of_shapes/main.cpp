#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;


class Shape
{
protected:
    int ShapeColor;

public:
    Shape() : ShapeColor(15)  // Default color is white
    {
        cout << "\nShape Param-less Ctor";
    }

    Shape(int c) : ShapeColor(c)
    {
        cout << "\nShape One-Param Ctor";
    }

    void setMyColor(int c) { ShapeColor = c; }

    /// virtual function left with empty implementation for late binding (will be inherited for all child classes and won't make them abstract since it is not pure virtual so no need to override it in them)
    virtual void setFilled(bool) {}

    /// pure virtual function for design only so will make this class as a design class and will be abstracted and prevent drawing Shape since it is design class only and can't be drawn
    virtual void Draw() = 0;
};


class Point
{
    int X, Y;
public:
    Point() : X(0), Y(0) { cout << "\nPoint Param-less Ctor"; }
    Point(int n) : X(n), Y(n) { cout << "\nPoint One-Param Ctor"; }
    Point(int n1, int n2) : X(n1), Y(n2) { cout << "\nPoint Two-Param Ctor"; }
    ~Point() { cout << "\nPoint Destructor"; }

    void setX(int x) { X = x; }
    void setY(int y) { Y = y; }
    int getX() const { return X; }
    int getY() const { return Y; }
};


class Line : public Shape
{
    Point Start, End;
public:
    Line() { cout << "\nLine Param-less Ctor"; }
    Line(int N1, int N2, int N3, int N4, int c) : Start(N1, N2), End(N3, N4) { ShapeColor = c; cout << "\nLine 4 Param Ctor"; }

    void Draw()
    {
        setcolor(ShapeColor);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
    ~Line() { cout << "\nLine Destructor"; }
};


class Rect : public Shape
{
    Point Upper_Left, Lower_Right;
public:
    Rect() : Shape() { cout << "\nRect Param-less Ctor"; }
    Rect(int N1, int N2, int N3, int N4, int c) : Upper_Left(N1, N2), Lower_Right(N3, N4) { ShapeColor = c; cout << "\nRect 4 Param Ctor"; }

    void Draw()
    {
        setcolor(ShapeColor);
        rectangle(Upper_Left.getX(), Upper_Left.getY(), Lower_Right.getX(), Lower_Right.getY());
    }
    ~Rect() { cout << "\nRect Destructor"; }
};


class Circle : public Shape
{
    Point Center;
    int Radius;
    bool filled;
public:
    Circle() : Center(), Radius(0), filled(false) { cout << "\nCircle Param-less Ctor"; }
    Circle(int N1, int N2, int r, int c) : Center(N1, N2), Radius(r), filled(false) { ShapeColor = c; cout << "\nCircle 3 Param Ctor"; }

    bool isFilled() const { return filled; }
    void setFilled(bool _filled) { filled = _filled; }

    void Draw()
    {
        setcolor(ShapeColor);
        if (filled)
        {
            setfillstyle(SOLID_FILL, ShapeColor);
            fillellipse(Center.getX(), Center.getY(), Radius, Radius);
        }
        else
        {
            circle(Center.getX(), Center.getY(), Radius);
        }
    }
    ~Circle() { cout << "\nCircle Destructor"; }
};


class Picture
{
    Shape*** pShapes;  /// 2D jagged array of pointers to Shape
    int* shapesPerRow; /// Array to store the number of shapes in each row
    int rows;

public:
    Picture(int r) : rows(r)
    {
        pShapes = new Shape**[rows];
        shapesPerRow = new int[rows];
    }

    void setShapesRow(int row, Shape** shapes, int numShapes)
    {
        pShapes[row] = shapes;
        shapesPerRow[row] = numShapes;
    }

    void Paint()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < shapesPerRow[i]; j++)
            {
                pShapes[i][j]->Draw();
            }
        }
    }

    ~Picture()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] pShapes[i];
        }
        delete[] pShapes;
        delete[] shapesPerRow;
    }
};


int main()
{
    cout << "Hello Graphics world" << endl;
    initwindow(400, 500);

    /// Creating individual shapes
    Circle C1(80, 50, 30, 4);
    Circle C2(320, 50, 30, 5);
    Rect R1(195, 80, 205, 110, 14);
    Line L1(160, 150, 240, 150, 9);

    /// Creating rows of shapes
    Shape* circles[] = { &C1, &C2 };
    Shape* rectangles[] = { &R1 };
    Shape* lines[] = { &L1 };

    /// Initializing Picture with jagged array of shapes
    Picture myPic(3);
    myPic.setShapesRow(0, circles, 2);       /// Row 0 for circles
    myPic.setShapesRow(1, rectangles, 1);    /// Row 1 for rectangles
    myPic.setShapesRow(2, lines, 1);         /// Row 2 for lines

    myPic.Paint();

    getch();
    closegraph();

    return 0;
}
