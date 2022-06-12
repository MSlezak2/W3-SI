#include <iostream>
#include <string>
#include <vector> 
#include <ctime>
#include <time.h>

#include "model.h"
#include "view.h"

int main() {

	std::vector<task> urgent_and_important{ {false, true, "1st task", time(0)}, {false, true, "2nd task", time(0)}};
	std::vector<task> not_urgent_and_important{ {false, false, "3rd task", time(0)} };
	std::vector<task> urgent_and_not_important{ {false, true, "5th task", time(0)}, {false, true, "6th task", time(0)}, {true, false, "9th task", time(0)} };
	std::vector<task> not_urgent_and_not_important{ };

	ask_user_for_task(urgent_and_important, not_urgent_and_important,urgent_and_not_important, not_urgent_and_not_important);

	display_matrix(urgent_and_important, not_urgent_and_important, urgent_and_not_important, not_urgent_and_not_important);

	return 0;
}

	/*//-------------- code to operate on dates: ----------------------------
	
	// structure that can hold date value in human readable form
	tm deadline_tm;
	tm* deadline_tm_pointer = &deadline_tm;
	// function that initiates the structure based on time value stored in time_t variable
	gmtime_s(deadline_tm_pointer, &urgent_and_important[0].deadline);
		
	std::cout << deadline_tm_pointer->tm_mday << std::endl;
	// changing the value of particular part of the date (day for instance) inside of tm structure
	deadline_tm_pointer->tm_mday = 22;
	// "saving" previously applied change into the time_t variable
	urgent_and_important[0].deadline = mktime(deadline_tm_pointer);

	std::cout << deadline_tm_pointer->tm_mday << std::endl;
	// 
	double elapsed_time = difftime(urgent_and_important[0].deadline, not_urgent_and_important[0].deadline);
	std::cout << elapsed_time / 60.0 / 60.0 /24.0  << std::endl;

	//---------------------------------------------------------------------*/
