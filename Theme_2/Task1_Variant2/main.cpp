/**
 * @file main.cpp
 * @author DM
 * @brief Task_1 Variant_1
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//* Include *//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


//* Namespace *//
using namespace std;


//* Functions *//
/**
 * @brief Reading input by user information and saving it
 * 
 * @param iteamWeight Each of iteam wiight
 * @param iteamCost Each of iteam cost
 * @param bagCapacity Bag capacity
 * @return true If ((iteamWeight == iteamCost) && (bagCapacity > 0))
 * @return false If ((iteamWeight != iteamCost) && (bagCapacity <= 0))
 */
bool BagInfo_ReadFromUser( std::vector<int> * iteamWeight, std::vector<int> * iteamCost, int * bagCapacity )
{
	bool ret = true;	
	std::string stringBuf, word;
	std::vector<std::string> vectstr;
	std::cout << "Enter bag capacity: ";
	std::getline( cin, word );
	*bagCapacity = stoi(word);

	if (*bagCapacity <= 0)
	{
		std::cout << "Bag capacity can't be zero or less than zero!";
		ret = false;
	}

	if (ret != false)
	{
		std::cout << "Enter each of iteam weight, which you want to place to bag: ";
		std::getline( cin, stringBuf );
		std::stringstream s(stringBuf);
		try
		{
			while (s >> word) iteamWeight->push_back(stoi(word));
		}
		catch(const std::exception& e)
		{
			std::cout << "Some of entered values is wrong!" << std::endl;
			ret = false;
		}
		stringBuf.clear();
		word.clear();
	}
	
	if (ret != false)
	{
		std::cout << "Enter each of iteam cost, which you want to place to bag: ";
		std::getline( cin, stringBuf );
		std::stringstream s(stringBuf);
		try
		{
			while (s >> word) iteamCost->push_back(stoi(word));
		}
		catch(const std::exception& e)
		{
			std::cout << "Some of entered values is wrong!" << std::endl;
			ret = false;
		}
	}

	if((ret != false)  && (iteamWeight->size() != iteamCost->size()))
	{
		std::cout << "Weight and cost vectors have different length!" << std::endl;
		ret = false;
	}

	return ret ;
}

/**
 * @brief Find greed of each iteam and write sorted by greed iteams iterators to the vector
 * 
 * @param iteamWeight Each of iteam weight
 * @param iteamCost  Each of iteam cost
 * @param bagCapacity Bag capacity
 * @param fitInBagIteams  Returning vector with sorted by greed iteams iterators
 * @return double Maximal capacity, which can be putted to the bag
 */
double Find_FitInBagIteams( std::vector<int> * iteamWeight, std::vector<int> * iteamCost, 
                                                          int bagCapacity, std::vector<int> * fitInBagIteams )
{
	std::vector<double> greed;
	double capacityNow = 0;
	greed.resize( iteamWeight->size() );

	std:transform(iteamWeight->begin(), iteamWeight->end(), iteamCost->begin(), greed.begin(),
				 [](int weight, int cost) {
					 return ((double)cost / (double)weight);
				 }
	);

	for (auto i = 0; i < iteamWeight->size(); i++)
	{
		int maxGreedIteamIndex = max_element(greed.begin(), greed.end())-greed.begin();
		
		
		if ((capacityNow + greed[maxGreedIteamIndex]) < (double)bagCapacity)
		{
			capacityNow = capacityNow + greed[maxGreedIteamIndex];
			fitInBagIteams->push_back( maxGreedIteamIndex );
		}
		greed.at(maxGreedIteamIndex) = 0;
	}
	return capacityNow;
}

/**
 * @brief Printing bag content
 * 
 * @param iteamWeight Each of iteam weight
 * @param iteamCost Each of iteam cost
 * @param bagCapacity Bag capacity
 * @param resultCapacity Maximal capacity, which can be putted to the bag
 * @param fitInBagIteams Vector with sorted by greed iteams iterators
 */
void Print_BagContent( std::vector<int> * iteamWeight, std::vector<int> * iteamCost, 
                                                       int bagCapacity, double resultCapacity, std::vector<int> * fitInBagIteams )
{
	std::cout << " Content in bag (sorted by greed):" << std::endl;
	for (int i : *fitInBagIteams)
	{
		std::cout << "  Iteam index: " << std::to_string(i) << ";  cost: " << std::to_string(iteamCost->at(i))
													<< ";  weight: " << std::to_string(iteamWeight->at(i)) << "." << std::endl;;
	}
	std::cout << " Initial bag capacity: " << std::to_string(bagCapacity) << std::endl;
	std::cout << " Resulting bag capacity: " << std::to_string(resultCapacity) << std::endl;

}	


//* Main *//
int main()
{
	int capacity = 0;
	double resultCapacity = 0;
	std::vector<int> weight, cost, fitInBagIteams;

	if( BagInfo_ReadFromUser(&weight, &cost, &capacity) )
	{
		resultCapacity = Find_FitInBagIteams( &weight, &cost, capacity, &fitInBagIteams );
		Print_BagContent( &weight, &cost, capacity, resultCapacity,  &fitInBagIteams );
	}
}

//* END OF FILE *//