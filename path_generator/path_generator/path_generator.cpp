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
	char msg[1024];
	for (int i = 0; i < 100; i++) {

		float x = i * 0.1;

		memset(&msg, 0, sizeof(msg)); // erase msg buffer
		snprintf(msg, sizeof x, "%f", x); //fill buffer with new data
		uh->send(msg);

		Sleep(100);
	}

    return 0;
}

