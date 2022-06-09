#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cstdlib>

template<class T>
void group(std::string input_string, std::regex pattern, std::vector<T>& container);

int main() {

	std::string users_input = "45 + 9 * 9 - 1 00 /5";

	// TODO: Validate user input (with regular expressions?, to make sure that there's for instance no such weird sequence like here: "45+-5")

	std::regex numbers_pattern("[0-9]+");
	std::regex operators_pattern("[+-/*]");

	std::vector<int> numbers;
	std::vector<char> operators;

	group(users_input, numbers_pattern, numbers);
	group(users_input, operators_pattern, operators);

	// display extracted groups:
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < operators.size(); i++)
	{
		std::cout << operators[i] << " ";
	}

	return 0;
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
		if (std::is_same<T, int>::value) {
			int number;	
			number = stoi(match_str);
			container.push_back(number);
		}

		//if it's supposed to be a char, then cast it to char
		if (std::is_same<T, char>::value) {
			container.push_back(match_str[0]);
		}
	}

}
