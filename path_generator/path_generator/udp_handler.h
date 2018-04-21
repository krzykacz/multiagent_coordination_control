#pragma once

#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <WinSock2.h>
#include <Windows.h>

#pragma comment (lib, "Ws2_32.lib")

// 2 float values = 4 bytes
#define MSG_LENGTH 8

class udp_handler
{
private:
	WSADATA wsaData; //Winsock
	SOCKET sock; //Socket
	struct sockaddr_in sa; //Socket address

	const int port = 333; //port

public:
	udp_handler();
	~udp_handler();

	bool setup_comunication();

	bool send(char msg[MSG_LENGTH]);


	inline bool check_if_error(int check_value, int expected_err_value, int err_code, const char* err_msg);
};

