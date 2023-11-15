#include "Components.h"

void readFile_n(const char* filename, vector<string> &shapes, int& total)
{
	cout << "Reading data from file: " << filename << "..." << endl;
	fstream file(filename);
	string line;
	int n = 0;
	file >> n;
	total = n;
	while (getline(file, line))
	{	
		if (line.length() > 0) shapes.push_back(line);
		n--;
	}
	file.close();
	cout << "Done reading data from file: " << filename << endl;
}
