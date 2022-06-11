#include <iostream>
#include <string>
#include <vector> 
#include <ctime>


struct task {
	bool is_completed;
	bool is_important;
	std::string description;
	time_t deadline;
};


void display_matrix(std::vector<task> first_quarter, std::vector<task> second_quarter,
	std::vector<task> third_quarter, std::vector<task> fourth_quarter);
void display_checkbox(bool is_completed);

void ask_user_for_task(std::vector<task> &ui, std::vector<task> &nui, std::vector<task> &uni, std::vector<task> &nuni);
void which_quarter(task given_task, std::vector<task> &ui, std::vector<task> &nui, std::vector<task> &uni, std::vector<task> &nuni);

int main() {

	std::vector<task> urgent_and_important{ {false, true, "1st task", time(0)}, {false, true, "2nd task", time(0)}};
	std::vector<task> not_urgent_and_important{ {false, false, "3rd task", time(0)} };
	std::vector<task> urgent_and_not_important{ {false, true, "5th task", time(0)}, {false, true, "6th task", time(0)}, {true, false, "9th task", time(0)} };
	std::vector<task> not_urgent_and_not_important{ };

	ask_user_for_task(urgent_and_important, not_urgent_and_important,urgent_and_not_important, not_urgent_and_not_important);


	//tm* deadline_tm;

	//gmtime_s(deadline_tm, &urgent_and_important[0].deadline);
	
	//std::cout << deadline_tm->tm_mon <<std::endl;
	//std::cout << deadline_tm->tm_mday << std::endl;

	display_matrix(urgent_and_important, not_urgent_and_important, urgent_and_not_important, not_urgent_and_not_important);

	return 0;
}

void display_matrix(std::vector<task> first_quarter, std::vector<task> second_quarter,
	std::vector<task> third_quarter, std::vector<task> fourth_quarter) {

	// 1st quarter (URGENT AND IMPORTANT)

	std::cout << "URGENT AND IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < first_quarter.size(); i++)
	{
		display_checkbox(first_quarter[i].is_completed);
		std::cout << first_quarter[i].description << std::endl;
	}

	// 2nd quarter (NOT URGENT AND IMPORTANT)

	std::cout << std::endl << std::endl << "NOT URGENT AND IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < second_quarter.size(); i++)
	{
		display_checkbox(second_quarter[i].is_completed);
		std::cout << second_quarter[i].description << std::endl;
	}

	// 3rd quarter (URGENT AND NOT IMPORTANT)

	std::cout << std::endl << std::endl << "URGENT AND NOT IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < third_quarter.size(); i++)
	{
		display_checkbox(third_quarter[i].is_completed);
		std::cout << third_quarter[i].description << std::endl;
	}

	// 4th quarter (NOT URGENT AND NOT IMPORTANT)

	std::cout << std::endl << std::endl << "NOT URGENT AND NOT IMPORTANT" << std::endl << std::endl;

	for (int i = 0; i < fourth_quarter.size(); i++)
	{
		display_checkbox(fourth_quarter[i].is_completed);
		std::cout << fourth_quarter[i].description << std::endl;
	}

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

void set_importance(std::vector<task> urgent_and_important) {

	std::cout << "Is this task important?";

	std::cin >> urgent_and_important[0].is_important;

	urgent_and_important[1].is_important;

}

void ask_user_for_task(std::vector<task> &ui, std::vector<task> &nui, std::vector<task> &uni, std::vector<task> &nuni) {

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

void which_quarter(task given_task, std::vector<task> &ui, std::vector<task> &nui, std::vector<task> &uni, std::vector<task> &nuni) {

	if (given_task.is_important) {
		ui.push_back(given_task);
	}
	else {
		uni.push_back(given_task);
	}

}