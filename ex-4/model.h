#pragma once

#include <string>
#include <vector>

struct task {
	bool is_completed;
	bool is_important;
	std::string description;
	time_t deadline;
};

void ask_user_for_task(std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni);
void which_quarter(task given_task, std::vector<task>& ui, std::vector<task>& nui, std::vector<task>& uni, std::vector<task>& nuni);