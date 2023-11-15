#pragma once
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{
private:
	double width = 0;
	double height = 0;

public:
	Rectangle() {};
	Rectangle(double width, double height) : Shape("Rectangle"), width(width), height(height) {}
	~Rectangle() {}

	inline double perimeter() override { return 2 * (width + height); }
	inline double area() override { return width * height; }
	void output() override;
	void outputPnA() override;
};

