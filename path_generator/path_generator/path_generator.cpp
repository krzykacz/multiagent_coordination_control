// path_generator.cpp
//

#include "stdafx.h"
#include "udp_handler.h"



int main()
{
	//Setup communication handler
	udp_handler *uh = new udp_handler();
	uh->setup_comunication();

	//start path generation
	printf("Press Enter to start path generation\n");
	getchar();

	///////// Path Generation //////////
	char msg[MSG_LENGTH];
	for (int i = 0; i < 100; i++) {

		//compute data
		float x = i * 0.1;
		float y = x * 2;


		// erase msg buffer
		memset(&msg, 0, sizeof(msg));

		//put data values in msg buffer
		float * x1 = (float*) msg;
		float * y1 = (float*) &msg[4];
		*x1 = x;
		*y1 = y;

		//send message
		uh->send(msg);

		Sleep(100);
	}

    return 0;
}

