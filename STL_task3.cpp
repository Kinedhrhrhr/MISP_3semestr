#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return 1;
	}

	std::ifstream fin(argv[1]);
	if(!fin.is_open())
	{
		std::cerr << "File 1 was not open!" << std::endl;
		return 1;
	}
	std::ofstream fout(argv[2]);
	if(!fout.is_open())
	{
		std::cerr << "File 2 was not open!" << std::endl;
		return 1;
	}
	int x;
	std::vector<int> values;

	while (fin >> x)
	{
		values.push_back(x);
	}

	auto last = std::unique(values.begin(), values.end());
	values.erase(last, values.end());

	int zeros = std::count(values.begin(), values.end(), 0);
	int ones = std::count(values.begin(), values.end(), 1);

	fout << zeros << " " << ones << std::endl;
	std::cout << zeros << " " << ones << std::endl;
	return 0;
}

