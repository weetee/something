#ifndef PRIMER_PERSON_H
#define PRIMER_PERSON_H

#include <iostream>
#include <string>

class Person
{
	friend std::istream &Read(std::istream &p_in, Person &p_p);
	friend std::ostream &Print(std::ostream &p_out, const Person &p_p);

public:
	Person() {}
	~Person() {}

	std::string GetName() const
	{
		return m_name;
	}
	std::string GetAddress() const
	{
		return m_address;
	}
private:
	std::string m_name;
	std::string m_address;
};

std::istream &Read(std::istream &p_in, Person &p_p);
std::ostream &Print(std::ostream &p_out, const Person &p_p);

#endif //PRIMER_PERSON_H