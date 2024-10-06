#include "..\..\Common.h"

bool Check_Little() {
    u_int a = 0x12345678;
    char* c = (char*)&a;

    printf("4바이트 메모리에 0x12345678을 저장할 때 저장 순서\n");
    printf("최하위 바이트부터 순서대로 출력\n");

    for (int i = 0; i < sizeof(a); i++) {
        printf("바이트 %d: %#x\n", i, (unsigned char)c[i]);
    }

    if ((unsigned char)c[0] == 0x78) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
	if (Check_Little()) {
		printf("리틀엔디언 방식");
	}
	else {
		printf("빅엔디언 방식");
	}

	return 0;
}
