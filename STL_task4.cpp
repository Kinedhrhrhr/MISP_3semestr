#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return 1;
	}

	std::ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		std::cerr << "File 1 was not open" << std::endl;
		return 1;
	}
	std::ofstream fout(argv[2]);
	if(!fout.is_open())
	{
		std::cerr << "File 2 was not open!" << std::endl;
		return 1;
	}
	int len;
	fin >> len;

	std::vector<int> values(len);
	for(int i = 0; i < len; i++)
	{
		fin >> values[i];
	}
	std::partial_sort(values.begin(), values.begin() + len/2, values.end());
	long long summ1 = std::accumulate(values.begin(), values.begin() + len/2, 0LL);
	long long summ2 = std::accumulate(values.begin() + len/2, values.end(), 0LL);

	long long summ = summ2 - summ1;
	std::cout << summ << std::endl;
	fout << summ << std::endl;
	return 0;
}



