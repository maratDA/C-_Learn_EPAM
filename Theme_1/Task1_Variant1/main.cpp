/**
 * @file main.cpp
 * @author DM
 * @brief Task_1 Variant_1
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//* Include *//
#include <iostream>
#include "Person.h"


//* Define *//
#define PERSON_AMOUNT        3


//* Class members *//
Person person[PERSON_AMOUNT];


//* Functions *//
void SortBy_AverageRating( )
{
	Person person_minAverage;
	for( auto i=0; i<PERSON_AMOUNT; i++ )
	{
		for( auto j=1; j<PERSON_AMOUNT; j++ )
		{
			if( person[j].AverageRating_Get() < person[j-1].AverageRating_Get() )
			{
				person_minAverage = person[j];
				person[j] = person[j-1];
				person[j-1] = person_minAverage;
			}
		}
	}
}

auto Find_AverageAgeOfAll()
{
	auto sumOfAges = 0;
	for( auto i=0; i<PERSON_AMOUNT; i++ )
	{
		sumOfAges += person[i].Age_Get();
	}
	sumOfAges /= PERSON_AMOUNT;
	return sumOfAges;
}


//* Main */
int main()
{
	person[0] = Person();
	person[1] = Person();
	person[2] = Person();

	person[0].Add("Ivanov",  "Ivan",  "Ivanovich",  21, 5);
	person[1].Add("Petrov",  "Petr",  "Petrovich",  18, 7);
	person[2].Add("Sidorov", "Sidor", "Sidorovich", 28, 4);

	std::cout << (" Average age of all Persons is: " +
	              std::to_string(Find_AverageAgeOfAll())) << std::endl;
	
	std::cout << "  Unsorted Persons massive: " << std::endl;
	person[0].InfoAboutPerson_Print();
	person[1].InfoAboutPerson_Print();
	person[2].InfoAboutPerson_Print();

	SortBy_AverageRating();
	
	std::cout << "  Sorted by average rating Persons massive: " << std::endl;
	person[0].InfoAboutPerson_Print();
	person[1].InfoAboutPerson_Print();
	person[2].InfoAboutPerson_Print();
}

//* END OF FILE *//