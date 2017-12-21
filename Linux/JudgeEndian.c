#include <stdio.h>

void ByteOrder()
{
	union
	{
		short m_value;
		char m_bytes[sizeof(short)];
	} test;
	test.m_value = 0x0305;
}

int main()
{

}
