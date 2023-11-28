#pragma once
#include "Components.h"
using namespace std;


class Circle : public Shape
{
private:
	
public:
	double radius = 0;
	Circle() : Shape("Circle") {}
	Circle(double radius) : Shape("Circle"), radius(radius) {}
	~Circle() {}

	inline double perimeter() override { return 2.0 * 3.14 * radius; }
	inline double area() override { return 3.14 * radius * radius; }
	void output() override;
	void outputPnA() override;
};
