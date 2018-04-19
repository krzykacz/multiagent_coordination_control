#include "stdafx.h"
#include "udp_handler.h"


udp_handler::udp_handler(){}


udp_handler::~udp_handler(){
	closesocket(sock);
	WSACleanup();
}

bool udp_handler::setup_comunication()
{
	// Initialize Winsock
	int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (err != 0) {
		printf("WSAStartup failed with error: %d\n", err);
		return false;
	}

	sock = INVALID_SOCKET;
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (check_if_error(sock, INVALID_SOCKET, WSAGetLastError(), "socket creation failed with error %d\n"))
		return false;

	//set socket address params
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //set ip address (in this example loopbask address = 127.0.0.1) 
	sa.sin_port = htons(333); //set port (in this example 127.0.0.1::333)

	return false;
}

bool udp_handler::send(char * msg)
{
	int bytes_send = sendto(sock, msg, sizeof msg, 0, (struct sockaddr*)&sa, sizeof(struct sockaddr_in));
	if (bytes_send < 0)
		printf("Error occured");
	return false;
}

inline bool udp_handler::check_if_error(int check_value, int expected_err_value, int err_code, const char * err_msg){
	if (check_value == expected_err_value) {
		printf(err_msg, err_code);
		WSACleanup();
	}
	return false;
}
