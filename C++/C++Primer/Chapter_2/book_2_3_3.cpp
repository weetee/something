#include <iostream>

int main()
{
	int i = 10;
	int *p_i = &i;
	int *&rp_i = p_i;

	*p_i = 20;
	*rp_i = 5;

	std::cout << "p_i = " << *p_i << std::endl;
	std::cout << "rp_i = " << *rp_i << std::endl;

	int **pp_i = &p_i;
	int **&rp_i2 = pp_i;
	std::cout << "rp_i2 = " << **rp_i2 << std::endl;

	//int &*rp_i3 = p_i;	//error

	return 0;
}
