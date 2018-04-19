// robot.cpp
//

#include "stdafx.h"
#include "udp_handler.h"



int main()
{
	//Setup communication handler
	udp_handler *uh = new udp_handler();
	uh->setup_communication();



	for (;;) {
		uh->recieve();
		char* msg = uh->check_if_new_msg();
		printf("\n%s", msg);
	}

	getchar();
	return 0;
}
