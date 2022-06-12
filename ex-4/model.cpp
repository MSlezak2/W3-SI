#include "model.h"
#include <time.h>
#include <ctime>

#include <iostream>

void ask_user_for_task(std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni) {

	std::string temp_description;
	bool temp_is_important;
	time_t temp_deadline = time(0); // variable that stores date in a form of number of seconds elapsed since some point in the past
	task temp_task;



	ask_for_description(temp_description);
	ask_for_importance(temp_is_important);
	ask_for_deadline(temp_deadline);

	// pack it all up into the task temporary variable...

	temp_task.description = temp_description;
	temp_task.is_important = temp_is_important;
	temp_task.deadline = temp_deadline;
	temp_task.is_completed = false;

	// ... and put it into right quarter of the matrix

	which_quarter(temp_task, ui, nui, uni, nuni);

}

void ask_for_description(std::string& temp_description)
{

	std::cout << "Enter description of the task:" << std::endl;
	std::cin >> temp_description; // TODO: pad string with spaces, for it to display properly
	std::cout << std::endl;
}

void ask_for_importance(bool& temp_is_important)
{

	std::cout << "Is this task important?" << std::endl;
	std::cin >> temp_is_important;
	std::cout << std::endl;
	// TODO: Validate the input
}

void ask_for_deadline(time_t& temp_deadline)
{
	int temp_month, temp_day;

	tm temp_deadline_tm; // structure that holds date in human readable form
	tm* temp_deadline_tm_p = &temp_deadline_tm;
	gmtime_s(temp_deadline_tm_p, &temp_deadline); // time_t (weird value) -> tm (human-readable)

	std::cout << "Now enter the deadline. First month (a number), then a day of the month..." << std::endl;
	std::cin >> temp_month;
	std::cin >> temp_day;
	std::cout << std::endl;

	temp_deadline_tm_p->tm_mon = temp_month - 1;
	temp_deadline_tm_p->tm_mday = temp_day;
	temp_deadline = mktime(temp_deadline_tm_p); // tm (human-readable) -> time_t (weird value)
}

void which_quarter(task given_task, std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni) {

	if (given_task.is_important) {
		ui.push_back(given_task);
	}
	else {
		uni.push_back(given_task);
	}
	// TODO: Take the deadline into account 
}	