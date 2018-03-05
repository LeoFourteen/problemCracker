#ifndef _CRACK_HPP_
#define _CRACK_HPP_

#include<vector>
#include<array>
#include <map>

class Cracker
{
public:
	typedef std::array<char, 10> ResultTryArr;
	typedef std::vector<ResultTryArr> ResultsVec;
public:
	Cracker();
	const ResultsVec& getResults();	
private:
	void makeResultTry(size_t prblmNo);
	bool checkResult();
	bool checkPrblm1();
	bool checkPrblm2();
	bool checkPrblm3();
	bool checkPrblm4();
	bool checkPrblm5();
	bool checkPrblm6();
	bool checkPrblm7();
	bool checkPrblm8();
	bool checkPrblm9();
	bool checkPrblm10();

	void getMinAndMax();
private:
	ResultTryArr m_resultTry;
	ResultsVec m_results;
	size_t m_min;
	size_t m_max;
	size_t m_chosenMin;
	std::map<char, size_t> m_counts;
};

#endif
