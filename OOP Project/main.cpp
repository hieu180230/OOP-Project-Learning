#include "Components.h"
Square* Square::instancePtr = nullptr;
Rectangle* Rectangle::instancePtr = nullptr;

int main()
{
	vector<string> lines;
	Shape* shapes = &Shape::getInstance();
	int total = 0;
	readFile_n("input.txt", lines, total);
	shapes->setTotalShape(total);
	for (int i = 0; i < lines.size(); i++)
	{
		string name = lines[i].substr(0, lines[i].find(":"));
		if (strcmp(name.c_str(), "Circle") == 0)
		{
			double r = 0;
			try
			{
				r = stod(lines[i].substr(lines[i].find_last_of("r") + 2, lines[i].length() - lines[i].find("r") - 2));
				Circle* newCir = &Circle::getInstance(r);
				shapes->append(newCir);
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
				Square* newSqr = Square::getInstance(a);
				shapes->append(*newSqr);
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
				Rectangle* newRec = Rectangle::getInstance(w, h);
				shapes->append(*newRec);
			}
			catch (...)
			{
				continue;
			}
		}
	}
	shapes->output();
}