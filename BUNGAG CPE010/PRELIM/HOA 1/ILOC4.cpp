/*ILO 4*/
#include<iostream>
#include<cmath>
class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
        double sideA, sideB, sideC;
    public:
        Triangle(double A, double B, double C, double a, double b, double c);
        void setAngles(double A, double B, double C);
        bool validateTriangle();
        double computeArea();
        double computePerimeter();
        void validateType();

};

Triangle::Triangle(double A, double B, double C, double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;

    sideA = a;
    sideB = b;
    sideC = c;
}
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}
bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

double Triangle::computeArea() {
    double side = (sideA + sideB + sideC) / 2;
    return sqrt(side * (side - sideA)*(side - sideB)*(side - sideC));
}
double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}
void Triangle::validateType() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        std::cout<<"The Angle is an Acute Angle"<<std::endl;
    }
    else if (angleA == 90 || angleB == 90 || angleC == 90) {
        std::cout<<"The Angle is a Right Angle"<<std::endl;

    }
    else if (angleA > 90 || angleB > 90 || angleC == 90) {
        std::cout<<"The Angle is an Obtuse Angle"<<std::endl;
    }
    else {
        std::cout<<"Other Angle of Not an Angel"<<std::endl;
    }
}

int main()
{
    Triangle setl(80, 80, 20, 25, 25, 25);
    if (setl.validateTriangle()) {
        std::cout<<"The Shape is a Triangle"<<std::endl;
        std::cout<<"The Area is: "<<setl.computeArea()<<std::endl;
        std::cout<<"The Perimeter is: "<<setl.computePerimeter()<<std::endl;

        setl.validateType();

    } else {
        std::cout<<"The Shape is NOT a Triangle"<<std::endl;
    }
    return 0;
}