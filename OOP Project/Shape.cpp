#include "Shape.h"
#include "Components.h"

string Shape::getName() { return this->name; }

void Shape::output()
{
	int realTotal = _shapes.size();
	cout << "Found " << realTotal << "/" << this->total << " shapes." << endl;
	int i = 0;
	for (i; i < _shapes.size(); i++)
	{
		cout << "| " << i + 1 << " | ";
		_shapes[i]->output();
	}
}

void Shape::outputSorted()
{
	vector<Shape*> sortShapes = _shapes;
	int c = 0, s = 0, r = 0;
	sort(sortShapes.begin(), sortShapes.end(), [](Shape* a, Shape* b) {return a->area() < b->area(); });
	cout << "Calculating..." << endl;
	for (Shape* s : sortShapes)
	{
		s->outputPnA();
	}
}
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

void Shape::ShapeFromString(vector<string> lines)
{
	for (int i = 0; i < lines.size(); i++)
	{
		string name = lines[i].substr(0, lines[i].find(":"));
		if (strcmp(name.c_str(), "Circle") == 0)
		{
			double r = 0;
			try
			{
				r = stod(lines[i].substr(lines[i].find_last_of("r") + 2, lines[i].length() - lines[i].find("r") - 2));
				Circle* newCir = manager->parseShape<Circle>(ShapeTypes::CIRCLE, r);
				_shapes.push_back(newCir);
			}
			catch (...)
			{
				continue;
			}
		}
		else if (strcmp(name.c_str(), "Square") == 0)
		{
			double a = 0;
			try
			{
				a = stod(lines[i].substr(lines[i].find_last_of("a") + 2, lines[i].length() - lines[i].find("a") - 2));
				Square* newSqr = manager->parseShape<Square>(ShapeTypes::SQUARE, a);
				_shapes.push_back(newSqr);
			}
			catch (...)
			{
				continue;
			}
		}
		else if (strcmp(name.c_str(), "Rectangle") == 0)
		{
			double w = 0, h = 0;
			try
			{
				if (lines[i].find("w") < lines[i].find("h"))
				{
					w = stod(lines[i].substr(lines[i].find_last_of("w") + 2, lines[i].length() - lines[i].find("w") - 2 - lines[i].find(",")));
					h = stod(lines[i].substr(lines[i].find_last_of("h") + 2, lines[i].length() - lines[i].find("h") - 2));
				}
				else
				{
					w = stod(lines[i].substr(lines[i].find_last_of("w") + 2, lines[i].length() - lines[i].find("w") - 2));
					h = stod(lines[i].substr(lines[i].find_last_of("h") + 2, lines[i].length() - lines[i].find("h") - 2 - lines[i].find(",")));
				}
				Rectangle* newRec = manager->parseShape<Rectangle>(ShapeTypes::RECTANGLE, w, h);
				_shapes.push_back(newRec);
			}
			catch (...)
			{
				continue;
			}
		}
	}
}