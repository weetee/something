#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <vector>
#include "Screen.h"

class WindowManager
{
private:
	std::vector<Screen> m_screens{Screen(24, 80)};
};

#endif //WINDOW_MANAGER_H