/**
 * @file main.cpp
 * @author DM
 * @brief Task_3 Variant_1
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


//* Functions *//
/**
 * @brief Template function to calculate sum of each 
 *        element (with same position number)
 * 
 * @tparam T 
 * @param vect_1 Vector 1
 * @param vect_2 Vector 2
 * @return std::vector<T> Result vector 
 */
template <typename T>
std::vector<T> VectorsElementsSum(const std::vector<T> * vect_1, const std::vector<T> * vect_2)
{
	std::vector<T> ret(vect_1->size());
	for( auto i=0; i<vect_1->size(); i++ )
	{
			ret.at(i) = (vect_1->at(i) + vect_2->at(i));
	}
	return ret;
}

/**
 * @brief Template function to print elements of vector
 * 
 * @tparam T 
 * @param vect Vector, which elements need to print
 */
template <typename T>
void Print_Vector(std::vector<T> * vect)
{
	for( auto i=0; i<vect->size(); i++ )
	{
		std::stringstream ss;
		ss << vect->at(i);
		std::cout << (" [" + std::to_string(i) + "] = "
		                + ss.str()) << std::endl;
	}
}


//* Main *//
int main()
{
	/**
	 * @brief Vectors with type 'int'
	 */
	std::vector<int> vector_1_int = {3, 4, 2, 8, 6};
	std::vector<int> vector_2_int = {9, 5, 4, 7, 2};
	std::vector<int> vector_int_result(5);

	/**
	 * @brief Vectors with type 'double'
	 */
	std::vector<double> vector_1_double = {1.25, 3.22, 1.69, 4.63};
	std::vector<double> vector_2_double = {4.55, 3.67, 8.12, 7.89};
	std::vector<double> vector_double_result(4);

	/**
	 * @brief Vectors with type 'string'
	 */
	std::vector<std::string> vector_1_string = {"Hello ", "Hi ",  "Good ",    "Thank "};
	std::vector<std::string> vector_2_string = {"world!", "all!", "morning!", "you!"};
	std::vector<std::string> vector_string_result(4);

	/**
	 * @brief Vectors with type 'float'
	 */
	std::vector<float> vector_1_float = {5.6, 2.8, 9.4, 1.9};
	std::vector<float> vector_2_float = {4.6, 6.6, 2,9, 7.8};
	std::vector<float> vector_float_result(4);


	/**
	 * @brief Calculationg sum of each element of 'int' vectors with same positions
	 */
	std::cout << "Summ of each elements of 'int' type vector:" << std::endl;
	vector_int_result = VectorsElementsSum(&vector_1_int, &vector_1_int);
	Print_Vector( &vector_int_result );

	/**
	 * @brief Calculationg sum of each element of 'double' vectors with same positions
	 */
	std::cout << "Summ of each elements of 'double' type vector:" << std::endl;
	vector_double_result = VectorsElementsSum(&vector_1_double, &vector_2_double);
	Print_Vector( &vector_double_result );

	/**
	 * @brief Calculationg sum of each element of 'string' vectors with same positions
	 */
	std::cout << "Summ of each elements of 'string' type vector:" << std::endl;
	vector_string_result = VectorsElementsSum(&vector_1_string, &vector_2_string);
	Print_Vector( &vector_string_result );

	/**
	 * @brief Calculationg sum of each element of 'float' vectors with same positions
	 */
	std::cout << "Summ of each elements of 'float' type vector:" << std::endl;
	vector_float_result = VectorsElementsSum(&vector_1_float, &vector_2_float);
	Print_Vector( &vector_float_result );
}

//* END OF FILE *//