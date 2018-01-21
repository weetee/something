#include "WindowManager.h"

void WindowManager::Clear(screen_idx index)
{
	Screen &sc = m_screens[index];
	sc.m_contents = std::string(sc.m_height * sc.m_width, ' ');
}