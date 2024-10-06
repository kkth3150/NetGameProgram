#include "..\..\Common.h"

bool Check_Little() {
    u_int a = 0x12345678;
    char* c = (char*)&a;

    printf("4����Ʈ �޸𸮿� 0x12345678�� ������ �� ���� ����\n");
    printf("������ ����Ʈ���� ������� ���\n");

    for (int i = 0; i < sizeof(a); i++) {
        printf("����Ʈ %d: %#x\n", i, (unsigned char)c[i]);
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
		printf("��Ʋ����� ���");
	}
	else {
		printf("�򿣵�� ���");
	}

	return 0;
}
