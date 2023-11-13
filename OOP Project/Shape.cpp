#include "Shape.h"
#include "ShapeTypes.h"

string Shape::getName() { return this->name; }
vector<Circle*> Shape::getCircles() { return this->circles; }
vector<Square> Shape::getSquares() { return this->squares; }
vector<Rectangle> Shape::getRectangles() { return this->rectangles; }

void Shape::append(Circle* circle) { this->circles.push_back(circle); }
void Shape::append(Square square) { this->squares.push_back(square); }
void Shape::append(Rectangle rectangle) { this->rectangles.push_back(rectangle); }

void Shape::output()
{
	int realTotal = circles.size() + squares.size() + rectangles.size();
	cout << "Found " << realTotal << "/" << this->total << " shapes." << endl;
	int i = 0;
	for (i = 0; i < circles.size(); i++)
	{
		cout << "| " << i + 1 << " | ";
		circles[i]->output();
	}
	for (i -= circles.size(); i < squares.size(); i++)
	{
		cout << "| " << i + 1 + circles.size() << " | ";
		squares[i].output();
	}
	for (i -= squares.size(); i < rectangles.size(); i++)
	{
		cout << "| " << i + 1 + circles.size() + squares.size() << " | ";
		rectangles[i].output();
	}
}
/*
void Shape::outputSorted()
{
	int c = 0, s = 0, r = 0;
	vector<Circle> circlesSorted = circles;
	vector<Square> squaresSorted = squares;
	vector<Rectangle*> rectanglesSorted = rectangles;
	sort(circlesSorted.begin(), circlesSorted.end(), [](Circle a, Circle b) {return a.area() < b.area(); });
	sort(squaresSorted.begin(), squaresSorted.end(), [](Square a, Square b) {return a.area() < b.area(); });
	sort(rectanglesSorted.begin(), rectanglesSorted.end(), [](Rectangle a, Rectangle b){return a.area() < b.area(); });
	map<double, string> shapeSort;
	vector<double> areas;
	cout << "Calculating..." << endl;

	for (c; c < circlesSorted.size(); c++)
	{
		shapeSort.insert(pair<double, string>(circlesSorted[c].area(), "c" + to_string(c)));
		areas.push_back(circlesSorted[c].area());
	}
	
	for (s; s < squaresSorted.size(); s++)
	{
		auto it = shapeSort.begin();
		for (int i = 0; i < areas.size(); i++)
		{
			if (squaresSorted[s].area() < areas[i])
			{
				areas.insert(areas.begin() + i, squaresSorted[s].area());
				shapeSort.insert(it, pair<double, string>(squaresSorted[s].area(), "s" + to_string(s)));
				break;
				
			}
			if (i == areas.size() - 1)
			{
				i++;
				it++;
				areas.insert(areas.begin() + i, squaresSorted[s].area());
				shapeSort.insert(it, pair<double, string>(squaresSorted[s].area(), "s" + to_string(s)));
				break;
			}
			it++;
		}
	}
	for (r; r < rectanglesSorted.size(); r++)
	{
		auto it = shapeSort.begin();
		for (int i = 0; i < areas.size(); i++)
		{
			if (rectanglesSorted[r]->area() < areas[i])
			{
				areas.insert(areas.begin() + i, rectanglesSorted[r]->area());
				shapeSort.insert(it, pair<double, string>(rectanglesSorted[r]->area(), "r" + to_string(r)));
				break;
			}
			if (i == areas.size() - 1)
			{
				i++;
				it++;
				areas.insert(areas.begin() + i, rectanglesSorted[r]->area());
				shapeSort.insert(it, pair<double, string>(rectanglesSorted[r]->area(), "r" + to_string(r)));
				break;
			}
			it++;
		}
	}


	for (int i = 0; i < areas.size(); i++)
	{
		string pos = shapeSort[areas[i]];
		char type = pos[0];
		int index = stoi(&pos[1]);
		switch (type)
		{
		case 'r':
			cout << "| " << i + 1 << " | ";
			rectanglesSorted[index]->outputPnA();
			break;
		case 'c':
			cout << "| " << i + 1 << " | ";
			circlesSorted[index].outputPnA();
			break;
		case 's':
			cout << "| " << i + 1 << " | ";
			squaresSorted[index].outputPnA();
			break;
		}
	}
}
*/
void Circle::output()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Radius=" << setw(5) << radius << "|" << endl;
}
void Circle::outputPnA()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Perimeter=" << setw(6) << fixed << setprecision(1) << this->perimeter()
		<< setw(5) << "|" << "Area=" << setw(7) << fixed << setprecision(2) << this->area() << "|" << endl;
}

void Rectangle::output()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Width=" << setw(6) << width << setw(5) << "|" << "Height=" << setw(5) << height << "|" << endl;
}
void Rectangle::outputPnA()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Perimeter=" << setw(6) << fixed << setprecision(1) << this->perimeter()
		<< setw(5) << "|" << "Area=" << setw(7) << fixed << setprecision(2) << this->area() << "|" << endl;
}

void Square::output()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Side=" << setw(7) << side << "|" << endl;
}
void Square::outputPnA()
{
	cout << left << setw(11) << this->getName() << setw(4) << "|" << "Perimeter=" << setw(6) << fixed << setprecision(1) << this->perimeter()
		<< setw(5) << "|" << "Area=" << setw(7) << fixed << setprecision(2) << this->area() << "|" << endl;
}