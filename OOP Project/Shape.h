#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

class Circle;
class Square;
class Rectangle;

class Shape
{
protected:
	string name = "";
	int total = 0;
	vector<Circle*> circles;
	vector<Square> squares;
	vector<Rectangle> rectangles;

	Shape() {};
	Shape(string shape_name) : name(shape_name) {}

public:	
	~Shape(){}

	static Shape& getInstance()
	{
		static Shape instance;
		return instance;
	}

	static Shape& getInstance(string name)
	{
		static Shape instance(name);
		return instance;
	}

	double perimeter(){ return 0; }
	double area(){ return 0; }

	string getName();
	vector<Circle*> getCircles();
	vector<Square> getSquares();
	vector<Rectangle> getRectangles();

	void append(Circle* circle);
	void append(Square square);
	void append(Rectangle rectangle);
	
	void output();
	//void outputSorted();

	int getTotalShape() { return this->total; }
	void setTotalShape(int total) { this->total = total; }
};


