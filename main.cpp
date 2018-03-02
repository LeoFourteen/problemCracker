#include<iostream>
#include "Cracker.h"

int main()
{
	Cracker cracker;
	const Cracker::ResultsVec& results = cracker.getResults();
	std::cout << "Answers:" << std::endl;
	std::cout << "========================" << std::endl;
	size_t index = 1;
	for (const auto& result : results)
	{
		std::cout << "Answer_"<<index<<":";
		for (auto c : result)
		{
			std::cout << c;
		}
		std::cout << std::endl;
		index++;
	}
	std::cout << "========================" << std::endl;
}