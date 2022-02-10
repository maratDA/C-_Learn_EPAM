/**
 * @file Person.cpp
 * @author DM
 * @brief Person class
 * @version 0.1
 * @date 2022-02-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once


//* Include *//
#include <iostream>
#include <string>


//* Class *//
class Person
{
private:
	std::string  _family_name;
	std::string  _name;
	std::string  _father_name;
	unsigned int _age;
	unsigned int _rating;
	
public:
	Person();

	void Add( std::string family_name, \
			  std::string name, \
			  std::string father_name, \
			  unsigned int age,\
			  unsigned int rating );

	unsigned int Age_Get();
	unsigned int AverageRating_Get();

	void InfoAboutPerson_Print();

	~Person();
};





//* END OF FILE *//