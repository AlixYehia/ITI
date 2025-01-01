#include <iostream>
#include <limits>  /// Include this header to use numeric_limits

using namespace std;

int main()
{
    string str1 = "Ali";
    string str2 = "Yehia";

    /// length and size same thing and the number displayed is the index terminator as 'A' is 0, 'l' is 1, 'i' is 2, and '\0' is 3 so we can say number of letters anyway

    cout << "\n Length of str1 = " << str1.length();
    cout << "\n Size of str1 = " << str1.size();

    cout << "\n Length of str2 = " << str2.length();
    cout << "\n Size of str2 = " << str2.size();

    /// in c++ operator + is supports concatenation as it is overloaded in std library

    cout<<"\n str1 + str2 : " << str1 + " ... " + str2;

    /// note: that doesnt append str2 to str1 just for printing

    cout<<"\n str1: " << str1;
    cout<<"\n str2: " << str2;

    /// append function

    cout<<"\n Appending";

    str1.append(str2);

    cout<<"\n str1: " << str1;
    cout<<"\n str2: " << str2;

    /// copy (equal)

    cout<<"\n Equal";

    str1 = str2;

    cout<<"\n str1: " << str1;


    string FullName;
    cout<<"\n\n Enter your full name (doesn't support spacing): ";

    /// delimiter for cin is space also so can't concatenate names with space between
    cin>>FullName;
    cout<<"\n Your Full Name is (space is a delimiter and the part after it is stored in input buffer): " << FullName;


    cin.ignore(numeric_limits<streamsize>::max(), '\n');     /// I got this from the Internet which is equivalent to _flushall() in C since it is not supported in C++ as far as I know

    /// By using numeric_limits<streamsize>::max(), you effectively tell cin.ignore to ignore as many characters as necessary, up to the maximum number representable by streamsize --> max().
    /// After executing this line, firstName will contain "Ali". However, cin stops reading at the first whitespace, so "yehia" and the newline ('\n')

    /// it will:
    ///Ignore everything in the input buffer up to and including the newline character ('\n').
    ///Discard "yehia\n" from the buffer, effectively clearing any remaining input from this line.
    ///After this line, the buffer is clear, so your next cin operation will read from the next line of input as expected.


    cout<<"\n\n Enter your full name (supports spacing): ";
    getline(cin, FullName);
    cout<<"\n Your Full Name is (gets a whole line. Enter is the delimiter only): " << FullName <<endl;







    return 0;
}
