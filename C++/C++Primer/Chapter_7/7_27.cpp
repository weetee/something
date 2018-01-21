#include "Screen.h"

int main()
{
	Screen my_screen(5,5,'X');
	my_screen.MoveCursor(4, 0).SetCharacter('#').Display(std::cout);
	std::cout << "\n";
	my_screen.Display(std::cout);
	std::cout << "\n";
	system("pause");
	return 0;
}
