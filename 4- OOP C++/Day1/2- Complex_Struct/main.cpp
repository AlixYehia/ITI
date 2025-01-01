#include <iostream>
using namespace std;

class Complex
{
    private:
        int Real;
        int Img;

    public:
        // Setters
        void setReal(int r) {
            Real = r;
        }

        void setImg(int i) {
            Img = i;
        }

        // Getters
        int getReal() {
            return Real;
        }

        int getImg() {
            return Img;
        }

        // Member function for addition
        Complex addm(Complex C) {
            Complex result;
            result.setReal(Real + C.getReal());
            result.setImg(Img + C.getImg());
            return result;
        }

        // Print function
    void print()
    {
        if (Real != 0)
        {
            cout << Real;
        }
        if (Img != 0)
        {
            if (Img > 0 && Real != 0)
            {
                cout << "+";
            }
            cout << Img << "i";
        }
        if (Real == 0 && Img == 0) {
            cout << "0";
        }
        cout << endl;
    }
};

// Standalone function for addition
Complex add(Complex C1, Complex C2) {
    Complex result;
    result.setReal(C1.getReal() + C2.getReal());
    result.setImg(C1.getImg() + C2.getImg());
    return result;
}

// Standalone function for subtraction
Complex subtract(Complex C1, Complex C2) {
    Complex result;
    result.setReal(C1.getReal() - C2.getReal());
    result.setImg(C1.getImg() - C2.getImg());
    return result;
}

int main() {
    Complex C1, C2;
    int realPart, imgPart;


    cout << "Enter the real part of the first complex number: ";
    cin >> realPart;
    C1.setReal(realPart);

    cout << "Enter the imaginary part of the first complex number: ";
    cin >> imgPart;
    C1.setImg(imgPart);


    cout << "Enter the real part of the second complex number: ";
    cin >> realPart;
    C2.setReal(realPart);

    cout << "Enter the imaginary part of the second complex number: ";
    cin >> imgPart;
    C2.setImg(imgPart);


    Complex memberSum = C1.addm(C2);
    cout << "Sum using member function: ";
    memberSum.print();


    Complex standaloneSum = add(C1, C2);
    cout << "Sum using standalone function: ";
    standaloneSum.print();

    // Using standalone function for subtraction
    Complex difference = subtract(C1, C2);
    cout << "Difference: ";
    difference.print();

    return 0;
}
