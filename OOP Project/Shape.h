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
class Manager;

class Shape
{
protected:
	string name = "";
	int total = 0;
	vector<Shape*> _shapes;

	Shape() {};
	Shape(string shape_name) : name(shape_name) {}

	Manager* manager;

public:	
	~Shape() {}
	

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

	void ShapeFromString(vector<string> lines);

	virtual double perimeter() { return 0; }
	virtual double area() { return 0; }

	string getName();
	vector<Shape*> getShapes() { return this->_shapes; }
	int getTotal() { return this->total; }

	virtual void output() {}
	void outputSorted();
	virtual void outputPnA() {}

	int getTotalShape() { return this->total; }
	void setTotalShape(int total) { this->total = total; }

};


