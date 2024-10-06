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
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[�˸�] ���� �ʱ�ȭ ����\n");

	// ���� ����
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	int retval = f(-100);
	if (retval == INVALID_SOCKET) err_quit("f()");
	printf("[�˸�] ���� ���� ����\n");

	// ���� �ݱ�
	closesocket(sock);

	// ���� ����
	WSACleanup();
	return 0;
}
