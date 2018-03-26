#include "Screen.h"

Screen &Screen::MoveCursor(pos_t p_row, pos_t p_col)
{
	pos_t pos = p_row * m_width + p_col;
	m_cursor = pos;
	return *this;
}

Screen &Screen::SetCharacter(char c)
{
	m_contents[m_cursor] = c;
	return *this;
}
	
Screen &Screen::SetCharacter(pos_t p_row, pos_t p_col, char c)
{
	pos_t pos = p_row * m_width + p_col;
	m_contents[pos] = c;
	return *this;
}

Screen::pos_t Screen::GetSize() const
{
    return m_height * m_width;
}
