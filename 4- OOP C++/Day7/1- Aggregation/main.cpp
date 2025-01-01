#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;


/// Association (Weak)                                          // Student and Teacher                 // Lifetime Independent to each other
/// Aggregation (Strong)      (Stronger form of Association)    // Paper cut from Book                 // Lifetime Independent to each other
/// Composition (Very Strong) (Stronger form of Aggregation)    // Dot inside Circle used to draw it   // Lifetime of Part Dependent on Whole and if Dot doesn't exist cant draw the Circle and without Circle no Dot


/// Destructors cant be seen since once i close the graphics window the console will close too

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



class Line
{
    Point Start;   /// Composition relationship (Obj of Point inside Line)
    Point End;
public:
    Line() : Start(), End()
    {
        ///Start.setX(0);    /// Wafr 3la nafsk kda kda Point() Hysfrhom Less frames in memory
        ///Start.setY(0);

        ///End.setX(0);
        ///End.setY(0);

        cout<< "\nLine Param-less Ctor";
    }

    Line(int N1, int N2, int N3, int N4) : Start(N1, N2), End(N3, N4)
    {
        ///Start.setX(N1);
        ///Start.setY(N2);

        ///End.setX(N3);
        ///End.setY(N4);

        cout<< "\nLine 4 Param Ctor";
    }

    Line(Point P1, Point P2) : Start( P1.getX(), P1.getY() ), End( P2.getX(), P2.getY() )
    {
        ///Start.setX( P1.getX() );
        ///Start.setY( P1.getY() );

        ///End.setX( P2.getX() );
        ///End.setY( P2.getY() );

        cout<< "\nLine with 2 Points Ctor";
    }

    void Draw()
    {
        setcolor(CYAN);
        /// Built-in Function to draw line in Graphics
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }



    ~Line()
    {
        cout<< "\nLine Destructor";
    }

};



class Rect
{
    Point Upper_Left;   /// Composition relationship (Obj of Point inside Rect)
    Point Lower_Right;
public:
    Rect() : Upper_Left(), Lower_Right()
    {
        ///Upper_Left.setX(0);    /// Wafr 3la nafsk kda kda Point() Hysfrhom Less frames in memory
        ///Upper_Left.setY(0);

        ///Lower_Right.setX(0);
        ///Lower_Right.setY(0);

        cout<< "\nRect Param-less Ctor";
    }

    Rect(int N1, int N2, int N3, int N4) : Upper_Left(N1, N2), Lower_Right(N3, N4)
    {
        ///Upper_Left.setX(N1);
        ///Upper_Left.setY(N2);

        ///Lower_Right.setX(N3);
        ///Lower_Right.setY(N4);

        cout<< "\nRect 4 Param Ctor";
    }

    Rect(Point P1, Point P2) : Upper_Left( P1.getX(), P1.getY() ), Lower_Right( P2.getX(), P2.getY() )
    {
        ///Upper_Left.setX( P1.getX() );
        ///Upper_Left.setY( P1.getY() );

        ///Lower_Right.setX( P2.getX() );
        ///Lower_Right.setY( P2.getY() );

        cout<< "\nPoint with 2 Points Ctor";
    }

    void Draw()
    {
        setcolor(MAGENTA);
        /// Built-in Function to draw Rect in Graphics
        rectangle(Upper_Left.getX(), Upper_Left.getY(), Lower_Right.getX(), Lower_Right.getY());
    }



    ~Rect()
    {
        cout<< "\nRect Destructor";
    }

};


class Circle
{
    Point Center;   /// Composition relationship (Obj of Point inside Circle)
    int Radius;
    bool filled;
public:
    Circle() : Center(), Radius(0), filled(false)
    {
        cout<< "\nCircle Param-less Ctor";
    }

    Circle(int N1, int N2, int r) : Center(N1, N2), Radius(r), filled(false)
    {
        cout<< "\nCircle 3 Param Ctor";
    }

    Circle(Point P1, int r) : Center(P1.getX(), P1.getY()), Radius(r), filled(false)
    {
        cout<< "\nCircle with 1 Point Ctor";
    }

    void Draw()
    {
        if (filled)
        {
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            fillellipse(Center.getX(), Center.getY(), Radius, Radius);
        } else
        {
            setcolor(RED);
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
    int cNum;
    int rNum;
    int lNum;

    Rect* pRects;
    Circle* pCircles;
    Line* pLines;

public:
    Picture()
    {
        cNum = 0;
        rNum = 0;
        lNum = 0;

        pRects = NULL;
        pCircles = NULL;
        pLines = NULL;
    }

    Picture(int rn, int cn, int ln, Rect* pr, Circle* pc, Line* pl)
    {
        cNum = rn;
        rNum = cn;
        lNum = ln;

        pRects = pr;
        pCircles = pc;
        pLines = pl;
    }

    void setCircle(int, Circle*);
    void setRect(int, Rect*);
    void setLine(int, Line*);

    void Paint();

    Circle* getCircle(int index);
};


void Picture::setCircle(int cn, Circle* cPtr)
{
      cNum = cn;
      pCircles = cPtr;
}

Circle* Picture::getCircle(int index)
{
    return &pCircles[index];
}

void Picture::setRect(int rn, Rect* rPtr)
{
      rNum = rn;
      pRects = rPtr;
}

void Picture::setLine(int ln, Line* lPtr)
{
      lNum = ln;
      pLines = lPtr;
}


void Picture::Paint()
{
    int i;
    for(i=0; i<cNum; i++)
    {
        pCircles[i].Draw();
    }

    for(i=0; i<rNum; i++)
    {
        pRects[i].Draw();
    }

    for(i=0; i<lNum; i++)
    {
        pLines[i].Draw();
    }
}


int main()
{
    cout << "Hello Graphics world" << endl;

    initwindow(400,500);  /// Opens Graphics Window

    Picture myPic;
    myPic.Paint();

    Circle cArr[5] = { Circle(80, 50, 30), Circle(200, 100, 100), Circle(320, 50, 30), Circle(160, 70, 10),Circle(250, 70, 10)  };
    myPic.setCircle(5, cArr);
    myPic.Paint();

    Rect rArr[2] = { Rect(195, 80, 205, 110) };
    myPic.setRect(2, rArr);
    myPic.Paint();

    Line lArr[1] = { Line(160, 150, 240, 150) };
    myPic.setLine(1, lArr);
    myPic.Paint();

    while (1)
    {
        char ch = getch();
        if (ch == 32)
        {
            myPic.getCircle(3)->toggleFill();
            myPic.getCircle(4)->toggleFill();
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
