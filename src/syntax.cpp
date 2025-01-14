#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory> // For smart pointers

using namespace std;

// Macros and Constants
#define MAX_VALUE 100
const double PI = 3.14159;

// Enum and Enum Class
enum Color { RED, GREEN, BLUE };
enum class Day { MONDAY, TUESDAY, WEDNESDAY };

// Struct
struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

// Template Function
template <typename T>
T add(T a, T b) { return a + b; }

// Abstract Class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Shape() = default;      // Virtual destructor
};

// Derived Class
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

// Another Derived Class
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return PI * radius * radius; }
};

// Function with Lambda
void printVector(const vector<int>& v) {
    for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
    cout << endl;
}

// Main Function
int main() {
    // Basic Variables
    int x = 10;
    double y = 5.5;
    string name = "C++";
    bool isFun = true;

    // Input/Output
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    // Arrays and STL Containers
    int arr[] = {1, 2, 3};
    vector<int> nums = {5, 3, 8};
    sort(nums.begin(), nums.end());
    printVector(nums);

    // Pointers and Smart Pointers
    int* ptr = &x;
    unique_ptr<Shape> shape = make_unique<Rectangle>(4, 5);
    cout << "Rectangle area: " << shape->area() << endl;

    // Conditional and Loop
    if (isFun) {
        for (int n : nums) {
            cout << "Number: " << n << endl;
        }
    }

    // Struct and Enum
    Point p(10, 20);
    cout << "Point: (" << p.x << ", " << p.y << ")" << endl;
    Color favoriteColor = BLUE;
    Day favoriteDay = Day::WEDNESDAY;
    cout << "Favorite color: " << favoriteColor << ", Favorite day: " << static_cast<int>(favoriteDay) << endl;

    // Template Function
    cout << "Sum: " << add(2.5, 3.5) << endl;

    return 0;
}
