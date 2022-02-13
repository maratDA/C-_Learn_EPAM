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
/**
 * @brief This class storing information about one person
 * 
 */
Person::Person() 
{
}

	//* Public *//
	/**
	 * @brief Adding information about one person to the class
	 * 
	 */
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
	
	/**
	 * @brief Returning age of person
	 * 
	 * @return unsigned int 
	 */
	unsigned int Person::Age_Get()
	{
		return _age;
	}

	/**
	 * @brief Returning average rating of person
	 * 
	 * @return unsigned int 
	 */
	unsigned int Person::AverageRating_Get()
	{
		return _rating;
	}

	/**
	 * @brief Print information about person
	 * 
	 */
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