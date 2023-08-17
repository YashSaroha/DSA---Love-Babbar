/*
    macros are a piece of code in a program that is replaced by value of macro
    #define   is used to define or create a macro

    e.g   pi => 3.14  use krna hai

    1) writing '3.14'       kr skte hai but agr change krna pda to hr jagah change krna is not feasible
    2) double pi = 3.14     use kr skte but isse kuch nuksnan hain jaise
        -> memory me storage le lega 8 byte ki jisse minimal si performance effect hogi
        -> pi = pi + 1 jaise changes kr skte hai jisse code khrab ho skta
    3) #define PI 3.14      ye agr use krenge to fayde honge jaise
        -> memory me storage nhi lega...compile krne se phle PI ki jagah 3.14 value aa jaegi
        -> changes is not possible   PI = PI + 1 jaisa kuch nhi kr skte, error dega
*/

#include<iostream>
using namespace std;

#define PI 3.14
#define rect(l,b) (l*b)

int main()
{
    int r = 5;
    double area = PI * r * r;
    cout << "area of circle is " << area << endl;   

    int length = 2;
    int breadth = 3;
    int rect_area = rect(length,breadth);
    cout << "area of rectangle is " << rect_area << endl;
    // whenever the compiler finds AREA(l, b) in the program it replaces it with the macros definition
    // i.e., (l*b). The values passed to the macro template AREA(l, b) will also be replaced by the statement (l*b).

    // https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/

}


