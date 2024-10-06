#include "../../Common.h"
#include <iostream>

int main() {

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	std::string domain;
	std::cin >> domain;

	hostent* data = gethostbyname(domain.c_str());

	if (data == NULL) {
		std::cout << "�������� ã�� �� �����ϴ�.";
		return 1;
	}
	else {

		std::cout << "������ ã�� �Ϸ�" << std::endl;
	}

	
	for (int i = 0; data->h_aliases[i] != NULL; ++i) {
		std::cout << "����" << i << "\t" << data->h_aliases[i] << std::endl;
	}

	for (int i = 0; data->h_addr_list[i] != NULL; ++i) {
		unsigned int IP = *(unsigned int*)data->h_addr_list[i];
		std::cout << "IP�ּ� " << i << "\t";
		unsigned char* IP_byte = (unsigned char*)&IP;
		std::cout << (int)IP_byte[0] << ".";
		std::cout << (int)IP_byte[1] << ".";
		std::cout << (int)IP_byte[2] << ".";
		std::cout << (int)IP_byte[3] <<std::endl;
	}

	WSACleanup();
	return 0;

}