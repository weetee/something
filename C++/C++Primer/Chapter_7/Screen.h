#ifndef PRIMER_SCREEN_H
#define PRIMER_SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class WindowManager
{
public:
	using screen_idx = std::vector<Screen>::size_type;
	WindowManager() = default;

	inline void Clear(screen_idx index);
private:
	std::vector<Screen> m_screens;
};


class Screen
{
	friend void WindowManager::Clear(screen_idx index);
public:
	typedef std::string::size_type pos_t;
	//using pos_t = std::string::size_type;

	Screen() = default;
	Screen(pos_t p_h, pos_t p_w) : m_height(p_h), m_width(p_w),
		m_contents(p_h * p_w, ' ')
	{ }
	Screen(pos_t p_h, pos_t p_w, char c) : m_height(p_h),
		m_width(p_w), m_contents(p_h * p_w, c)
	{ }

	char GetCharacter() const
	{
		return m_contents[m_cursor];
	}
	inline char GetCharacter(pos_t p_row, pos_t p_col) const;
	Screen &MoveCursor(pos_t p_row, pos_t p_col);
	Screen &SetCharacter(char c);
	Screen &SetCharacter(pos_t p_row, pos_t p_col, char c);
	Screen &Display(std::ostream &os) 	//根据对象是不是const来决定调用const或非const的Display
	{
		DoDisplay(os);
		return *this;
	}
	const Screen &Display(std::ostream &os) const
	{
		DoDisplay(os);
		return *this;
	}

    pos_t GetSize() const;

private:
	void DoDisplay(std::ostream &os) const
	{
		os << m_contents;
	}

private:
	pos_t m_cursor = 0;		//光标位置
	pos_t m_height = 0, m_width = 0;	//窗口的高和宽
	std::string m_contents;	//内容
};

inline char Screen::GetCharacter(pos_t p_row, pos_t p_col) const
{
	pos_t pos = p_row * m_width + p_col;
	return m_contents[pos];
}

inline void WindowManager::Clear(screen_idx index)
{
	Screen &sc = m_screens[index];
	sc.m_contents = std::string(sc.m_height * sc.m_width, ' ');
}


#endif //PRIMER_SCREEN_H
