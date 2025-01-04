#include <iostream>
using namespace std;

#define PI 3.14159 // Macro definition for PI

int main()
{
    /*
        Question1: In a program, input the side of a square. You have to output the area of the square.
        Input: n (side)
        Output: n*n (area)
    */
    int side;
    cout << "Enter the side of the square: ";
    cin >> side;

    int area = side * side;
    cout << "Area of the square is: " << area << endl;

    /*
        Question 2: Enter cost of 3 items from the user (using float data type) - a pencil, a pen and an eraser.
        You have to output the total cost of the items back to the user as their bill.
        (Add on: You can also try adding 18% GST tax to the items in the bill as an advanced problem)
    */
    float pencil, pen, eraser, total, gst;
    cout << "Enter the cost of a pencil: ";
    cin >> pencil;
    cout << "Enter the cost of a pen: ";
    cin >> pen;
    cout << "Enter the cost of an eraser: ";
    cin >> eraser;

    total = pencil + pen + eraser;
    gst = total * 0.18;

    cout << "Total cost including GST: " << total + gst << endl;

    /*
        Question 3: Build a Simple Interest Calculator.
        Input: principal (P), rate (R), time (T)
        Output: (P * R * T) / 100
    */
    float P, R, T, SI;
    cout << "Enter the principal amount: ";
    cin >> P;
    cout << "Enter the rate of interest: ";
    cin >> R;
    cout << "Enter the time period in years: ";
    cin >> T;

    SI = (P * R * T) / 100;

    cout << "Simple Interest: " << SI << endl;

    /*
        Question 4: Write a program to calculate the area of a circle.
        Input: r (radius)
        Output: PI * r * r (area)
    */
    float radius, area_circle;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    area_circle = PI * radius * radius;

    cout << "Area of the circle is: " << area_circle << endl;

    return 0;
}