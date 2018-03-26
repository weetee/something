#ifndef	SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct SalesData
{
	std::string m_isbn;
	unsigned int m_soldcnt;
    double m_price;
	double m_revenue;

    void Output();
};

bool Input(SalesData &p_item)
{
    if (std::cin >> p_item.m_isbn >> p_item.m_soldcnt >> p_item.m_price)
    {
	    p_item.m_revenue = p_item.m_soldcnt * p_item.m_price;
	    return true;
    }
    return false;
}

void SalesData::Output()
{
    std::cout << m_isbn << " " << m_soldcnt << " " << m_price << " "
     << m_revenue << std::endl;
}


#endif //SALES_DATA_H
