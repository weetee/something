#ifndef STRING_FIND_H
#define STRING_FIND_H

/*
** 在字符串A中查找子串B
** 两种解法：BF算法和KMP算法
*/

/*
** BF(Brute Force)暴力算法
** BF算法的思想是将目标串A的第一个字符与模式串B的第一个字符进行匹配，若相等，则继续比较下去；
** 若不相等，则比较A的第二个字符和B的第一个字符，依次比较下去，直到得出最后的匹配结果
*/
char *BF(const char *str_a, const char *str_b)
{
	assert(str_a != NULL && str_b != NULL)
	int len_a = strlen(str_a);
	int len_b = strlen(str_b);

	if (len_a < len_b)
		return NULL;

	for (int i = 0; i < len_a - len_b; ++i)
	{
		for (int j = 0; j < len_b; ++j)
		{
			if (str_a[i + j] == str_b[j])
			{
				if (j == len_b - 1)
				{
					return str_a + i;
				}
			}
			else
				break;
		}
	}

	return NULL;
}

#endif 	//STRING_FIND_H