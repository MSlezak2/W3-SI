#include <iostream>
#include <string>
#include <regex>

void group(std::string input_string, std::regex pattern);

int main() {

	std::string users_input = "45 + 9 * 9 - 1 00 /5";

	// TODO: Validate user input (with regular expressions?, to make sure that there's for instance no such weird sequence like here: "45+-5")

	std::regex numbers_pattern("[0-9]+");
	std::regex operators_pattern("[+-/*]");

	group(users_input, numbers_pattern);

	group(users_input, operators_pattern);

	return 0;
}

void group(std::string input_string, std::regex pattern) {
	// eventually it should group sequences described by pattern by searching input_string and save it to the list (which also should be
	// given as a parameter)

	std::smatch number;

	std::sregex_iterator words_begin =
		std::sregex_iterator(input_string.begin(), input_string.end(), pattern);
	std::sregex_iterator words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		number = *i;
		std::string match_str = number.str();
		std::cout << match_str << '\n';
	}

	// TODO: Use arraylist (is indexible :P) / list (isn't, but I guess it's more efficitent) / vector?

}
