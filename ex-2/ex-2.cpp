#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <iterator> 

double calculate(std::vector<double>& numbers, std::vector<char>& operators);
template<class T>
void group(std::string input_string, std::regex pattern, std::vector<T>& container);
void addition_and_subtraction(std::vector<double>& numbers, std::vector<char>& operators);
void multiplication_and_division(std::vector<double>& numbers, std::vector<char>& operators);
void exponentiation_and_roots(std::vector<double>& numbers, std::vector<char>& operators);
int look_for_innermost_parentheses(std::vector<char> operators, int* parentheses_start, int* parentheses_stop);

int main() {

	std::string users_input = "((3.5+((3.5*2root49)^2)))";

	// TODO: Validate user input (with regular expressions?, to make sure that there's for instance no such weird sequence like here: "45+-5")

	const std::regex numbers_pattern("([0-9]*[.])?[0-9]+");
	const std::regex operators_pattern("[+\\-/*^()]|root");

	// group numbers and operators into separate vectors for further processing

	std::vector<double> numbers;
	std::vector<char> operators;

	group(users_input, numbers_pattern, numbers);
	group(users_input, operators_pattern, operators);

	double result = calculate(numbers, operators);

	std::cout << users_input << " = " << numbers[0];

	return 0;
}

double calculate(std::vector<double>& numbers, std::vector<char>& operators) {
	
	double result = HUGE_VAL;

	int nesting_level = -1;
	int parentheses_start, parentheses_stop; // indexes of the first and the last of the innermost parentheses

	while (nesting_level != 0)
	{

		// look for indexes of inner most parentheses
		nesting_level = look_for_innermost_parentheses(operators, &parentheses_start, &parentheses_stop);

		// if there are brackets ...
		if (nesting_level != 0) {
			// do a copy (subvector) of numbers and operators vectors
			std::vector<double> inner_numbers;
			std::vector<char> inner_operators;
			copy(operators.begin() + parentheses_start + 1, operators.begin() + parentheses_stop, std::back_inserter(inner_operators));
			copy(numbers.begin() + (parentheses_start - nesting_level + 1), numbers.begin() + (parentheses_stop - nesting_level + 1), std::back_inserter(inner_numbers));

			// recurently invoke this function on those subvectors 

			double result_of_parentheses = calculate(inner_numbers, inner_operators);

			// insert the result where the first element in brackets was

			numbers[(parentheses_start - nesting_level + 1)] = result_of_parentheses;

			// delete the rest of the elements from within the brackets

			std::vector<double>::iterator numbers_iterator;
			for (int i = parentheses_stop - nesting_level; i > parentheses_start - nesting_level + 1; i--) // it had to be reversed, because when we delete one element, indexes of next elements are being changed
			{
				numbers_iterator = numbers.begin() + i;
				numbers.erase(numbers_iterator);
			}

			std::vector<char>::iterator operators_iterator;
			for (int i = parentheses_stop; i >= parentheses_start; i--) // it had to be reversed, because when we delete one element, indexes of next elements are being changed
			{
				operators_iterator = operators.begin() + i;
				operators.erase(operators_iterator);
			}

		}
		else 	// ...if not...
		{
			// just do the calculations
			exponentiation_and_roots(numbers, operators);
			multiplication_and_division(numbers, operators);
			addition_and_subtraction(numbers, operators);
		}

	}
	if (numbers.size() == 1) {
		result = numbers[0];
	}

	return result;

}

template<class T>
void group(std::string input_string, std::regex pattern, std::vector<T>& container) {
	// groups sequences described by given pattern by searching input_string and save it to the given vector

	// to hold the matching sequence
	std::smatch match; 
	std::string match_str;

	// to iterate through matching sequences
	std::sregex_iterator words_begin =
		std::sregex_iterator(input_string.begin(), input_string.end(), pattern);
	std::sregex_iterator words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		match = *i;
		match_str = match.str();

		// if we're processing numbers, then cast the string to int
		if (std::is_same<T, double>::value) {
			double number;	
			number = stod(match_str);
			container.push_back(number);
		}

		//if it's supposed to be a char, then cast it to char
		if (std::is_same<T, char>::value) {
			container.push_back(match_str[0]);
		}
	}

}

void addition_and_subtraction(std::vector<double>& numbers, std::vector<char>& operators) {
	// TODO: There have to be certain relation between size of those containers (no_numbers = no_operators+1)
	// otherwise return an error message

	int i = 0;
	std::vector<double>::iterator numbers_iterator;  // we need those iterators to use vector.erase() function
	std::vector<char>::iterator operators_iterator;

	while (i < operators.size()) {

		// if it's the operation that we mean to perform, then take i-th and i+1-th numbers, do calculations,
		// save result in i-th element, and delete i+1-th, then delete the current operator (don't increment i though...)
		if (operators[i] == '+') { // addition
			numbers[i] = numbers[i] + numbers[i + 1];
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		}
		else if (operators[i] == '/') { // subtraction
			numbers[i] = numbers[i] - numbers[i + 1];
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		}
		// if it's not, increment i
		else { // skip the rest
			i++;
		}
	}
}

void multiplication_and_division(std::vector<double>& numbers, std::vector<char>& operators) {
	// TODO: There have to be certain relation between size of those containers (no_numbers = no_operators+1)
	// otherwise return an error message

	int i = 0;
	std::vector<double>::iterator numbers_iterator;  // we need those iterators to use vector.erase() function
	std::vector<char>::iterator operators_iterator;

	while (i < operators.size()) {

		// if it's the operation that we mean to perform, then take i-th and i+1-th numbers, do calculations,
		// save result in i-th element, and delete i+1-th, then delete the current operator (don't increment i though...)
		if (operators[i] == '*') { // multiplication
			numbers[i] = numbers[i] * numbers[i + 1];
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		} 
		else if (operators[i] == '/') { // division
			numbers[i] = numbers[i] / numbers[i + 1];
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		} // TODO: allow division with reminder  
		// if it's not, increment i
		else { // skip the rest
			i++;
		}
	}
}


void exponentiation_and_roots(std::vector<double>& numbers, std::vector<char>& operators) {
	// TODO: There have to be certain relation between size of those containers (no_numbers = no_operators+1)
	// otherwise return an error message

	int i = 0;
	std::vector<double>::iterator numbers_iterator;  // we need those iterators to use vector.erase() function
	std::vector<char>::iterator operators_iterator;

	while (i < operators.size()) {

		// if it's the operation that we mean to perform, then take i-th and i+1-th numbers, do calculations,
		// save result in i-th element, and delete i+1-th, then delete the current operator (don't increment i though...)
		if (operators[i] == '^') { // exponentiation
			double temp = std::pow(numbers[i], numbers[i + 1]);
			numbers[i] = std::pow(numbers[i], numbers[i + 1]);
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		}
		else if (operators[i] == 'r') { // roots
			numbers[i] = std::pow(numbers[i + 1], (1.0/numbers[i]) );
			numbers_iterator = numbers.begin() + i + 1;
			numbers.erase(numbers_iterator);
			operators_iterator = operators.begin() + i;
			operators.erase(operators_iterator);
		}
		// if it's not, increment i
		else { // skip the rest
			i++;
		}
	}
}

int look_for_innermost_parentheses(std::vector<char> operators, int* parentheses_start, int* parentheses_stop) {

	int nesting_level = 0;

	int temp_parentheses_start = 0;
	int temp_parentheses_stop = -1;

	int i = 0;

	while (i < operators.size() && temp_parentheses_stop == -1)
	{

		if (operators[i] == '(') {
			temp_parentheses_start = i;
			nesting_level++;
		}
		else if (operators[i] == ')') {
			temp_parentheses_stop = i;
		}

		i++;
	}

	*parentheses_start = temp_parentheses_start;
	*parentheses_stop = temp_parentheses_stop;

	return nesting_level;

}

