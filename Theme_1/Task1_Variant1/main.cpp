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
/**
 * @brief Sorting information about person by the average
 *        rating field
 * 
 */
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

/**
 * @brief Finding average age of every persons by the formula:
 *        (age_of_person[0] + age_of_person[1] + ...) / sum_of_persons = average_age
 * 
 * @return auto 
 */
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

	/**
	 * @brief Adding information of each person
	 */
	person[0].Add("Ivanov",  "Ivan",  "Ivanovich",  21, 5);
	person[1].Add("Petrov",  "Petr",  "Petrovich",  18, 7);
	person[2].Add("Sidorov", "Sidor", "Sidorovich", 28, 4);

	/**
	 * @brief Print average age of all the persons
	 */
	std::cout << (" Average age of all Persons is: " +
	              std::to_string(Find_AverageAgeOfAll())) << std::endl;
	
	/**
	 * @brief Print unsorted persont massive
	 */
	std::cout << "  Unsorted Persons massive: " << std::endl;
	person[0].InfoAboutPerson_Print();
	person[1].InfoAboutPerson_Print();
	person[2].InfoAboutPerson_Print();

	/**
	 * @brief Sort information about all persons by the average rating field
	 * 
	 */
	SortBy_AverageRating();
	
	/**
	 * @brief Print sorted persont massive
	 */
	std::cout << "  Sorted by average rating Persons massive: " << std::endl;
	person[0].InfoAboutPerson_Print();
	person[1].InfoAboutPerson_Print();
	person[2].InfoAboutPerson_Print();
}

//* END OF FILE *//