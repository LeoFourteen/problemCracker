#include "Cracker.h"
#include<iostream>
Cracker::Cracker() 
{
	makeResultTry(1);
}

const Cracker::ResultsVec& Cracker::getResults()
{
	return m_results;
}

void Cracker::makeResultTry(size_t prblmNo)
{
	if (prblmNo <= 10)
	{
		for (char ans = 'A'; ans <= 'D'; ans++)
		{
			m_resultTry.push_back(ans);
			makeResultTry(prblmNo + 1);
			m_resultTry.pop_back();
		}
	}
	else
	{
		if (checkResult())
		{
			m_results.push_back(m_resultTry);
		}
	}
}

bool Cracker::checkResult()
{
	getMinAndMax();

	if (!checkPrblm1())return false;
	if (!checkPrblm2())return false;
	if (!checkPrblm3())return false;
	if (!checkPrblm4())return false;
	if (!checkPrblm5())return false;
	if (!checkPrblm6())return false;
	if (!checkPrblm7())return false;
	if (!checkPrblm8())return false;
	if (!checkPrblm9())return false;
	if (!checkPrblm10())return false;

	return true;
}

bool Cracker::checkPrblm1()
{
	return true;
}

bool Cracker::checkPrblm2()
{
	switch (m_resultTry[1])
	{
	case 'A':
		return m_resultTry[4] == 'C' ? true : false;
	case 'B':
		return m_resultTry[4] == 'D' ? true : false;
	case 'C':
		return m_resultTry[4] == 'A' ? true : false;
	default:
		return m_resultTry[4] == 'B' ? true : false;
	}
}

bool Cracker::checkPrblm3()
{
	switch (m_resultTry[2])
	{
	case 'A':
		if (m_resultTry[2] != m_resultTry[5] && m_resultTry[5] == m_resultTry[1] && m_resultTry[1] == m_resultTry[3])
			return true;
		else
			return false;
	case 'B':
		if (m_resultTry[2] != m_resultTry[5] && m_resultTry[2] == m_resultTry[1] && m_resultTry[1] == m_resultTry[3])
			return true;
		else
			return false;
	case 'C':
		if (m_resultTry[2] == m_resultTry[5] && m_resultTry[5] != m_resultTry[1] && m_resultTry[5] == m_resultTry[3])
			return true;
		else
			return false;
	default:
		if (m_resultTry[2] == m_resultTry[5] && m_resultTry[5] == m_resultTry[1] && m_resultTry[1] != m_resultTry[3])
			return true;
		else
			return false;
	}
}

bool Cracker::checkPrblm4()
{
	switch (m_resultTry[3])
	{
	case 'A':
		return m_resultTry[0] == m_resultTry[4] ? true : false;
	case 'B':
		return m_resultTry[1] == m_resultTry[6] ? true : false;
	case 'C':
		return m_resultTry[0] == m_resultTry[8] ? true : false;
	default:
		return m_resultTry[5] == m_resultTry[9] ? true : false;
	}
}

bool Cracker::checkPrblm5()
{
	switch (m_resultTry[4])
	{
	case 'A':
		return m_resultTry[7] == m_resultTry[4] ? true : false;
	case 'B':
		return m_resultTry[3] == m_resultTry[4] ? true : false;
	case 'C':
		return m_resultTry[8] == m_resultTry[4] ? true : false;
	default:
		return m_resultTry[6] == m_resultTry[4] ? true : false;
	}
}

bool Cracker::checkPrblm6()
{
	switch (m_resultTry[5])
	{
	case 'A':
		return (m_resultTry[1] == m_resultTry[3] && m_resultTry[1] == m_resultTry[7]) ? true : false;
	case 'B':
		return (m_resultTry[0] == m_resultTry[5] && m_resultTry[0] == m_resultTry[7]) ? true : false;
	case 'C':
		return (m_resultTry[2] == m_resultTry[9] && m_resultTry[2] == m_resultTry[7]) ? true : false;
	default:
		return (m_resultTry[4] == m_resultTry[8] && m_resultTry[4] == m_resultTry[7]) ? true : false;
	}
}

bool Cracker::checkPrblm7()
{
	switch (m_resultTry[6])
	{
	case 'A':
		return m_counts['C'] == m_chosenMin ? true : false;
	case 'B':
		return m_counts['B'] == m_chosenMin ? true : false;
	case 'C':
		return m_counts['A'] == m_chosenMin ? true : false;
	default:
		return m_counts['D'] == m_chosenMin ? true : false;
	}
}

bool Cracker::checkPrblm8()
{
	char ans1 = m_resultTry[0];

	switch (m_resultTry[7])
	{
	case 'A':
		return (m_resultTry[6] != ans1 - 1 && m_resultTry[6] != ans1 + 1) ? true : false;
	case 'B':
		return (m_resultTry[4] != ans1 - 1 && m_resultTry[4] != ans1 + 1) ? true : false;
	case 'C':
		return (m_resultTry[1] != ans1 - 1 && m_resultTry[1] != ans1 + 1) ? true : false;
	default:
		return (m_resultTry[9] != ans1 - 1 && m_resultTry[9] != ans1 + 1) ? true : false;
	}
}

bool Cracker::checkPrblm9()
{
	bool res1 = (m_resultTry[0] == m_resultTry[5]);
	bool res2;
	switch (m_resultTry[8])
	{
	case 'A':
		res2 = (m_resultTry[4] == m_resultTry[5]);
		break;
	case 'B':
		res2 = (m_resultTry[4] == m_resultTry[9]);
		break;
	case 'C':
		res2 = (m_resultTry[4] == m_resultTry[1]);
		break;
	default:
		res2 = (m_resultTry[4] == m_resultTry[8]);
	}
	if ((!res1&&res2) || (res1&&!res2))
		return true;
	return false;
}

bool Cracker::checkPrblm10()
{
	size_t diff = m_max - m_min;
	switch (m_resultTry[9])
	{
	case 'A':
		return diff == 3 ? true : false;
	case 'B':
		return diff == 2 ? true : false;
	case 'C':
		return diff == 4 ? true : false;
	default:
		return diff == 1 ? true : false;
	}
}
void Cracker::getMinAndMax()
{
	m_max = 0;
	m_min = 10;
	m_chosenMin = 10;
	for (char c = 'A'; c <= 'D'; c++)
	{
		m_counts[c] = 0;
	}
	for (auto ans : m_resultTry)
	{
		if (m_counts.find(ans) == m_counts.end())
		{
			m_counts[ans] = 1;
		}
		else
		{
			m_counts[ans]++;
		}
	}
	for (auto c : m_counts)
	{
		if (c.second > m_max)
		{
			m_max = c.second;
		}
		if (c.second < m_min)
		{
			m_min = c.second;
		}
		if (c.second < m_chosenMin && c.second > 0)
		{
			m_chosenMin = c.second;
		}
	}
}