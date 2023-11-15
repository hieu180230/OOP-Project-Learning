#include "Components.h"
#include <typeinfo>

Manager manager;

int main()
{
	vector<string> lines;
	Shape* shapes = &Shape::getInstance();
	int total = 0;
	readFile_n("input.txt", lines, total);
	shapes->ShapeFromString(lines);
	shapes->setTotalShape(total);
	shapes->outputSorted();
}