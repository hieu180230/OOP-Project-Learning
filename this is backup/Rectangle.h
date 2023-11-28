#pragma once
#include "Shape.h"
using namespace std;

class ARectangle : public Shape
{
private:
	double width = 0;
	double height = 0;

public:
	ARectangle() {};
	ARectangle(double width, double height) : Shape("Rectangle"), width(width), height(height) {}
	~ARectangle() {}

	inline double perimeter() override { return 2 * (width + height); }
	inline double area() override { return width * height; }
	void output() override;
	void outputPnA() override;
};

