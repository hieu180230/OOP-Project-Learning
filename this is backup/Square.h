#pragma once
#include "Shape.h"
using namespace std;

class Square : public Shape
{
private:
	double side = 0;

public:
	Square() {};
	Square(double side) : Shape("Square"), side(side) {}
	~Square() {}

	inline double perimeter() override { return 4 * side; }
	inline double area() override { return side * side; }
	void output() override;
	void outputPnA() override;
};