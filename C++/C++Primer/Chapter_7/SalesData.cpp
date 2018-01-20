#include "SalesData.h"

SalesData &SalesData::Combine(SalesData &p_rhs)
{
	m_total_sold += p_rhs.m_total_sold;
	m_revenue += p_rhs.m_revenue;
	return *this;
}

SalesData Add(const SalesData &p_lhs, const SalesData &p_rhs)
{

}

std::istream &Read(std::istream &p_in, SalesData &p_item)
{
	double price;
	p_in >> p_item.m_book_num >> p_item.m_total_sold >> price;
	p_item.m_revenue = p_item.m_total_sold * price;
	return p_in;
}

std::ostream &Print(std::ostream &p_out, const SalesData &p_item)
{
	p_out << "book No. = " << p_item.m_book_num << ", total sold = "
	<< p_item.m_total_sold << ", revenue = " << p_item.m_revenue << endl;
	return p_out;
}
