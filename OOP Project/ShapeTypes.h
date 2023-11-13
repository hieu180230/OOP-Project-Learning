#pragma once
#include "Shape.h"
using namespace std;

class Circle : public Shape
{
private:

	Circle() : Shape("Circle") {}

	Circle(double radius) : Shape("Circle"), radius(radius) {}

public:
	~Circle() {}
	double radius = 0;

	static Circle& getInstance()
	{
		static Circle instance;
		return instance;
	}
	static Circle& getInstance(double radius)
	{
		static Circle instance(radius);
		return instance;
	}

	inline double perimeter() { return 2.0 * 3.14 * radius; }
	inline double area() { return 3.14 * radius * radius; }
	void output();
	void outputPnA();
};

class Rectangle : public Shape
{
private:
	double width = 0;
	double height = 0;

	static Rectangle* instancePtr;
	Rectangle() {};
	Rectangle(double width, double height) : Shape("Rectangle"), width(width), height(height) {}

public:
	~Rectangle() { if (!instancePtr) delete instancePtr; }

	static Rectangle* getInstance()
	{
		if (!instancePtr)
			instancePtr = new Rectangle();
		return instancePtr;
	}
	static Rectangle* getInstance(double width, double height)
	{
		if (!instancePtr)
			instancePtr = new Rectangle(width, height);
		return instancePtr;
	}

	inline double perimeter() { return 2 * (width + height); }
	inline double area() { return width * height; }
	void output();
	void outputPnA();
};

class Square : public Shape
{
private:
	double side = 0;

	static Square* instancePtr;
	Square() {};
	Square(double side) : Shape("Square"), side(side) {}

public:
	~Square() { if (!instancePtr) delete instancePtr; }

	static Square* getInstance()
	{
		if (!instancePtr)
			instancePtr = new Square();
		return instancePtr;
	}
	static Square* getInstance(double side)
	{
		if (!instancePtr)
			instancePtr = new Square(side);
		return instancePtr;
	}

	inline double perimeter() { return 4 * side; }
	inline double area() { return side * side; }
	void output();
	void outputPnA();
};