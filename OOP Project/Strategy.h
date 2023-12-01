#pragma once
#include "Components.h"

class Strategy
{
public:
	void displayShape(Shape* shape)
	{
		shape->output();
	}
	
	void displayAllShape(Shape* shape)
	{
		int realTotal = shape->getShapes().size();
		cout << "Found " << realTotal << "/" << shape->getTotal() << " shapes." << endl;
		int i = 0;
		for (i; i < shape->getShapes().size(); i++)
		{
			cout << "| " << i + 1 << " | ";
			shape->getShapes()[i]->output();
		}
	}
};