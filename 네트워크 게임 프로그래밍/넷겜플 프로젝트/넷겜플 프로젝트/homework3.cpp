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
		std::cout << "도메인을 찾을 수 없습니다.";
		return 1;
	}
	else {

		std::cout << "도메인 찾기 완료" << std::endl;
	}

	
	for (int i = 0; data->h_aliases[i] != NULL; ++i) {
		std::cout << "별명" << i << "\t" << data->h_aliases[i] << std::endl;
	}

	for (int i = 0; data->h_addr_list[i] != NULL; ++i) {
		unsigned int IP = *(unsigned int*)data->h_addr_list[i];
		std::cout << "IP주소 " << i << "\t";
		unsigned char* IP_byte = (unsigned char*)&IP;
		std::cout << (int)IP_byte[0] << ".";
		std::cout << (int)IP_byte[1] << ".";
		std::cout << (int)IP_byte[2] << ".";
		std::cout << (int)IP_byte[3] <<std::endl;
	}

	WSACleanup();
	return 0;

}