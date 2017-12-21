#include <stdio.h>

void ByteOrder()
{
	union
	{
		short m_value;
		char m_bytes[sizeof(short)];
	} test;
	test.m_value = 0x0305;
	if (test.m_bytes[0] == 3 && test.m_bytes[1] == 5)
		printf("big endian~!\n");
	else if (test.m_bytes[0] == 5 && test.m_bytes[1] == 3)
		printf("little endian~!\n");
	else
		printf("unknow endian!!\n");
}

int main()
{
	ByteOrder();
	return 0;
}
