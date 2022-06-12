#pragma once

#include "model.h"

#include <iostream>
#include <vector>
#include <string>


void display_matrix(std::vector<task> first_quarter, std::vector<task> second_quarter,
	std::vector<task> third_quarter, std::vector<task> fourth_quarter);
void display_checkbox(bool is_completed);
void display_date(time_t date);
void print_horizontal_line(int length);
