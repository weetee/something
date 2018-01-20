#include "SalesData.h"

SalesData &SalesData::Combine(const SalesData &p_rhs)
{
	m_total_sold += p_rhs.m_total_sold;
	m_revenue += p_rhs.m_revenue;
	return *this;
}

SalesData Add(const SalesData &p_lhs, const SalesData &p_rhs)
{
	SalesData sum = p_lhs;
	sum.Combine(p_rhs);
	return sum;
}

std::istream &Read(std::istream &p_in, SalesData &p_item)
{
	double price;
    std::string book_num;
    int total;
    p_in >> book_num >> total >> price;
    p_item = SalesData(book_num, total, price);
	return p_in;
}

std::ostream &Print(std::ostream &p_out, const SalesData &p_item)
{
	p_out << "book No. = " << p_item.m_book_num << ", total sold = "
	<< p_item.m_total_sold << ", revenue = " << p_item.m_revenue;
	return p_out;
}
