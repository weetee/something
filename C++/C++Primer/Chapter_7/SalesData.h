#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class SalesData
{
	friend SalesData Add(const SalesData &p_lhs, const SalesData &p_rhs);
	friend std::istream &Read(std::istream &p_in, SalesData &p_item);
	friend std::ostream &Print(std::ostream &p_out, const SalesData &p_item);
public:
	SalesData(const std::string &p_booknum = "", int p_sold = 0, double p_price = 0.0) :
		m_book_num(p_booknum), m_total_sold(p_sold)
		{
			m_revenue = m_total_sold * p_price;
		}
	~SalesData() {}

	std::string Isbn() const
	{
		return m_book_num;
	}

	SalesData &Combine(SalesData &p_rhs);

private:
	std::string m_book_num;
	int m_total_sold;
	double m_revenue;
};

SalesData Add(const SalesData &p_lhs, const SalesData &p_rhs);
std::istream &Read(std::istream &p_in, SalesData &p_item);
std::ostream &Print(std::ostream &p_out, const SalesData &p_item);


#endif //SALES_DATA_H
