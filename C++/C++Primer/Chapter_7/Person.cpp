#include "Person.h"

std::istream &Read(std::istream &p_in, Person &p_p)
{
	p_in >> p_p.m_name >> p_p.m_address;
	return p_in;
}

std::ostream &Print(std::ostream &p_out, const Person &p_p)
{
	p_out << "name: " << p_p.m_name << ", address:" << p_p.m_address;
	return p_out;
}
