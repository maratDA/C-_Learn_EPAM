/**
 * @file Person.cpp
 * @author DM
 * @brief Person class
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//* Include *//
#include "Person.h"


//* Class members *//
Person::Person() 
{
}

	//* Public *//
	void Person::Add( std::string family_name, \
			  std::string name, \
			  std::string father_name, \
			  unsigned int age,\
			  unsigned int rating )
	{
		
		_family_name  = family_name;
		_name         = name;
		_father_name  = father_name;
		_age          = age;
		_rating       = rating;
	}
	
	unsigned int Person::Age_Get()
	{
		return _age;
	}

	unsigned int Person::AverageRating_Get()
	{
		return _rating;
	}

	void Person::InfoAboutPerson_Print()
	{
		std::cout << (" Name: " + 
		              _family_name + " " +
					  _name + " " +
					  _father_name + ";  Age: " +
					  std::to_string(_age) + "; Rating: " +
					  std::to_string(_rating)) << std::endl;
	}

	//* Private *//


Person::~Person()
{
}


//* END OF FILE *//