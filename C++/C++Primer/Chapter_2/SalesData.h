#ifndef	SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct SalesData
{
	std::string m_isbn;
	unsigned int m_soldcnt;
	double m_revenue;

};

bool Input(SalesData p_item)
{
    double price;
    if (std::cin >> p_item.m_isbn >> p_item.m_soldcnt >> price)
    {
	    p_item.m_revenue = p_item.m_soldcnt * price;
	    return true;
    }
    return false;
}


#endif //SALES_DATA_H
