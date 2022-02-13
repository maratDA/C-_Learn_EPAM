/**
 * @file main.cpp
 * @author DM
 * @brief Task_2 Variant_1
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//* Include *//
#include <iostream>
#include <vector>
#include <string>


//* Main *//
int main()
{
	/**
	 * @brief New vector
	 */
	std::vector<int> TestVector = { 4, 2, 5, 9, 3, 8, 6, 0, 7, 1 };

	/**
	 * @brief Print TestVector one element
	 */
	auto Print_TestVectorElement { 
		[](int elNum, int elVal)
		{
			std::cout << (" [" + std::to_string(elNum) +
	    	          "] element value is: " + std::to_string(elVal)) << std::endl;
		} 
	};

	/**
	 * @brief Sort TestVector elements and 
	 *        count elements positions changing while sorting 
	 */
	auto SortAndSortCount_TestVectorElement {  
		[](std::vector<int> * vect)
		{
			static int positionChangeCounter = 0;
			int buf = 0;
			for( auto i=0; i<vect->size(); i++ )
			{
				for(auto j=1; j<vect->size(); j++ )
				{
					if( vect->at(j) < vect->at(j-1) )
					{
						buf = vect->at(j);
						vect->at(j) = vect->at(j-1);
						vect->at(j-1) = buf;
						positionChangeCounter++;
					}
				}
			}
			return positionChangeCounter;
		}
	};

	/**
	 * @brief Printing unsorted TestVector
	 */
	std::cout << "Unsorted vector:" << std::endl;
	for( auto i=0; i<TestVector.size(); i++ )
	{
		Print_TestVectorElement( i, TestVector[i] );
	}

	/**
	 * @brief Sorting TestVector and counting elements positions changing
	 */
	auto posChanged = SortAndSortCount_TestVectorElement( &TestVector );

	/**
	 * @brief Printing sorted TestVector
	 */
	std::cout << "Sorted vector:" << std::endl;
	for( auto i=0; i<TestVector.size(); i++ )
	{
		Print_TestVectorElement( i, TestVector[i] );
	}
	
	/**
	 * @brief Printing TestVector elements positions changing times whie sorting
	 */
	std::cout << ("While the vector sorted elements positions changed " + 
	              std::to_string(posChanged) + " times") << std::endl;
	
}

//* END OF FILE *//