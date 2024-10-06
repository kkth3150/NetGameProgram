#include "Common.h"
#include <iostream>

int f(int x) {
	if (x>=0) {
		SetLastError(0);
		return 0;

	}
	else {
		SetLastError(WSAEINVAL);
		return SOCKET_ERROR;
	}


}

int main(int argc, char *argv[])
{
	// 윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[알림] 윈속 초기화 성공\n");

	// 소켓 생성
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	int retval = f(-100);
	if (retval == INVALID_SOCKET) err_quit("f()");
	printf("[알림] 소켓 생성 성공\n");

	// 소켓 닫기
	closesocket(sock);

	// 윈속 종료
	WSACleanup();
	return 0;
}
