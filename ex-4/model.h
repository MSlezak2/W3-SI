#pragma once

#include <string>
#include <vector>
#include <time.h>
#include <ctime>

struct task {
	bool is_completed;
	bool is_important;
	std::string description;
	time_t deadline;
};

void ask_user_for_task(std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni);
void ask_for_description(std::string& temp_description);
void ask_for_importance(bool& temp_is_important);
void ask_for_deadline(time_t& temp_deadline);
void which_quarter(task given_task, std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni);