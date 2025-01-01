#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

/// Association (Weak)                                          // Student and Teacher                 // Lifetime Independent to each other
/// Aggregation (Strong)      (Stronger form of Association)    // Paper cut from Book                 // Lifetime Independent to each other
/// Composition (Very Strong) (Stronger form of Aggregation)    // Dot inside Circle used to draw it   // Lifetime of Part Dependent on Whole and if Dot doesn't exist cant draw the Circle and without Circle no Dot

/// Destructors can't be seen since once I close the graphics window, the console will close too

class Point
{
    int X;
    int Y;
public:
    Point() : X(0), Y(0)
    {
        cout << "\nPoint Param-less Ctor";
    }

    Point(int n) : X(n), Y(n) {
        cout << "\nPoint One-Param Ctor";
    }

    Point(int n1, int n2) : X(n1), Y(n2)
    {
        cout << "\nPoint Two-Param Ctor";
    }

    ~Point()
    {
        cout << "\nPoint Destructor";
    }

    int getX() { return X; }
    int getY() { return Y; }
};

class Line
{
    Point Start;   /// Composition relationship (Obj of Point inside Line)
    Point End;
public:
    Line(int N1, int N2, int N3, int N4) : Start(N1, N2), End(N3, N4)
    {
        ///Start.setX(N1);   /// Using initializer list to avoid extra calls to setX and setY
        ///Start.setY(N2);

        ///End.setX(N3);
        ///End.setY(N4);

        cout << "\nLine 4 Param Ctor";
    }

    void Draw()
    {
        setcolor(CYAN);
        /// Built-in function to draw line in graphics
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }

    ~Line()
    {
        cout << "\nLine Destructor";
    }
};


class Rect
{
    Point Upper_Left;   /// Composition relationship (Obj of Point inside Rect)
    Point Lower_Right;
public:
    Rect(int N1, int N2, int N3, int N4) : Upper_Left(N1, N2), Lower_Right(N3, N4)
    {
        ///Upper_Left.setX(N1);    /// Using initializer list to avoid extra calls to setX and setY
        ///Upper_Left.setY(N2);

        ///Lower_Right.setX(N3);
        ///Lower_Right.setY(N4);

        cout << "\nRect 4 Param Ctor";
    }

    void Draw()
    {
        setcolor(MAGENTA);
        /// Built-in function to draw Rect in graphics
        rectangle(Upper_Left.getX(), Upper_Left.getY(), Lower_Right.getX(), Lower_Right.getY());
    }

    ~Rect()
    {
        cout << "\nRect Destructor";
    }
};

class Circle
{
    Point Center;   /// Composition relationship (Obj of Point inside Circle)
    int Radius;
public:
    Circle(int N1, int N2, int r) : Center(N1, N2), Radius(r)
    {
        ///Center.setX(N1);    /// Using initializer list to avoid extra calls to setX and setY
        ///Center.setY(N2);
        Radius = r;

        cout << "\nCircle 3 Param Ctor";
    }

    void Draw()
    {
        setcolor(RED);
        /// Built-in function to draw circle in graphics
        circle(Center.getX(), Center.getY(), Radius);
    }

    ~Circle()
    {
        cout << "\nCircle Destructor";
    }
};

int main()
{
    cout << "Hello Graphics world" << endl;
    initwindow(400, 500);  /// Opens Graphics Window

    Line myLine(10, 20, 50, 100);
    myLine.Draw();

    Rect myRect(50, 100, 200, 300);
    myRect.Draw();

    Circle myCircle(125, 200, 100);
    myCircle.Draw();

    getch();
    closegraph();  /// Closes graphics window

    return 0;
}
