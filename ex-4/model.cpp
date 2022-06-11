#include "model.h"

#include <iostream>

void ask_user_for_task(std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni) {

	std::string temp_description;
	bool temp_is_important;
	task temp_task;

	// ask for description
	system("cls");

	std::cout << "Enter description of the task:" << std::endl;
	std::cin >> temp_description;
	std::cout << std::endl;

	// ask for importance

	std::cout << "Is this task important?" << std::endl;
	std::cin >> temp_is_important;
	std::cout << std::endl;
	// TODO: Validate the input

	temp_task.description = temp_description;
	temp_task.is_important = temp_is_important;
	temp_task.is_completed = false;

	which_quarter(temp_task, ui, nui, uni, nuni);

}

void which_quarter(task given_task, std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni) {

	if (given_task.is_important) {
		ui.push_back(given_task);
	}
	else {
		uni.push_back(given_task);
	}

}	