#pragma once

#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <WinSock2.h>
#include <Windows.h>
#include <cstring>

#pragma comment (lib, "Ws2_32.lib")

// 2 float values = 4 bytes
#define MSG_LENGTH 8

class udp_handler
{
private:

	WSADATA wsaData; //Winsock
	struct sockaddr_in sa; //Socket address
	SOCKET sock;	//Socket
	int port = 333;

	char buff[MSG_LENGTH];
	bool new_msg_available;

public:

	udp_handler();
	~udp_handler();

	bool setup_communication();
	void recieve();
	void check_if_new_msg(float *x, float *y);

	//Checks if error occured and mange to handle it
	inline bool check_if_error(int check_value, int expected_err_value, int err_code, const char* err_msg) {
		if (check_value == expected_err_value) {
			printf(err_msg, err_code);
			WSACleanup();
			return true;
		}
		return false;
	};


};
