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

		uh->recieve();	//tell uh to listen to new message

		float x, y;

		uh->check_if_new_msg(&x, &y); //assign new message to msg buffer

		printf("\nx: %f    y: %f", x, y);
	}

	getchar();
	return 0;
}
