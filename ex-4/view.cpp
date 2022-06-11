#include "view.h"


void display_matrix(std::vector<task> first_quarter, std::vector<task> second_quarter,
	std::vector<task> third_quarter, std::vector<task> fourth_quarter) {

	// 1st quarter (URGENT AND IMPORTANT)

	print_horizontal_line(55);
	std::cout << "\t\tURGENT AND IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < first_quarter.size(); i++)
	{
		display_checkbox(first_quarter[i].is_completed);
		std::cout << first_quarter[i].description << std::endl;
	}

	// 2nd quarter (NOT URGENT AND IMPORTANT)

	std::cout << std::endl << std::endl;
	print_horizontal_line(55);
	std::cout << "\t\tNOT URGENT AND IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < second_quarter.size(); i++)
	{
		display_checkbox(second_quarter[i].is_completed);
		std::cout << second_quarter[i].description << std::endl;
	}

	// 3rd quarter (URGENT AND NOT IMPORTANT)

	std::cout << std::endl << std::endl;
	print_horizontal_line(55);
	std::cout << "\t\tURGENT AND NOT IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < third_quarter.size(); i++)
	{
		display_checkbox(third_quarter[i].is_completed);
		std::cout << third_quarter[i].description << std::endl;
	}

	// 4th quarter (NOT URGENT AND NOT IMPORTANT)

	std::cout << std::endl << std::endl;
	print_horizontal_line(55);
	std::cout << "\t\tNOT URGENT AND NOT IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < fourth_quarter.size(); i++)
	{
		display_checkbox(fourth_quarter[i].is_completed);
		std::cout << fourth_quarter[i].description << std::endl;
	}

	std::cout << std::endl << std::endl;
	print_horizontal_line(55);
	std::cout << std::endl << std::endl;

}

void display_checkbox(bool is_completed) {

	char checkbox;

	if (is_completed)
	{
		checkbox = 'X';
	}
	else {
		checkbox = 'O';
	}

	std::cout << checkbox << " ";

}

void print_horizontal_line(int length) {

	for (int i = 0; i < length; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;

}

void set_importance(std::vector<task> urgent_and_important) {

	std::cout << "Is this task important?";

	std::cin >> urgent_and_important[0].is_important;

	urgent_and_important[1].is_important;

}

