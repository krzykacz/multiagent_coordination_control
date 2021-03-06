#include "stdafx.h"
#include "udp_handler.h"


udp_handler::udp_handler(){
	memset(&buff, 0, sizeof(buff)); //clean msg buffer
	new_msg_available = false;
}


udp_handler::~udp_handler(){
	WSACleanup();
}


bool udp_handler::setup_communication()
{
	// Initialize Winsock
	int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (err != 0) {
		printf("WSAStartup failed with error: %d\n", err);
		return false;
	}

	//set socket address params
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY); //set ip address (in this example INADDR_ANY means that app should listen msg from any ip address)
	sa.sin_port = htons(port); //set port (in this example port 333)

							   //Create socket
	sock = INVALID_SOCKET;
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (check_if_error(sock, INVALID_SOCKET, WSAGetLastError(), "socket creation failed with error %d\n"))
		return false;

	//Bind socket
	err = bind(sock, (SOCKADDR *)&sa, sizeof(sa));
	if (check_if_error(err, SOCKET_ERROR, WSAGetLastError(), "socket binding failed with error %d\n"))
		return false;

	return true;
}


void udp_handler::recieve()
{
	int recsize;
	char temp[MSG_LENGTH];
	recsize = recv(sock, temp, MSG_LENGTH, 0);
	if (recsize < 0)
		printf("Recieve error");

	//TODO Mutex

	//copy new message to buff
	for(int i=0;i<MSG_LENGTH; i++)
		buff[i] = temp[i];

	new_msg_available = true;
}


void udp_handler::check_if_new_msg(float *x, float *y)
{
	//TODO Mutex

	if (new_msg_available) {		
		*x = *(float*)buff;
		*y = *(float*)(buff +4);	

		new_msg_available = false;
	}
}
