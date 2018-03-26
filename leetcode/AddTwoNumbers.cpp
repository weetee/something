/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int num1 = 0, num2 = 0;
        int count = 0;
        int carry = 0;

        ListNode *lst_head = NULL;
        ListNode *current = NULL;

        while (l1 != NULL || l2 != NULL)
        {
        	int cur_num1 = 0, cur_num2 = 0;
        	ListNode *node = new ListNode(0);
        	if (l1 != NULL && l2 != NULL)
        	{
        		cur_num1 = l1->val;
        		cur_num2 = l2->val;
        		int sum = cur_num1 + cur_num2 + carry;
        		if (sum >= 10)
        		{
        			sum -= 10;
        			carry = 1;
        		}
        		else
        			carry = 0;
        		node->val = sum;
        		if (lst_head == NULL)
        		{
        			current = node;
        			lst_head = node;
        		}
        		else
        		{
        			current->next = node;
        			current = current->next;
        		}

        		for (int i = 0; i < count; ++i)
        		{
        			cur_num1 *= 10;
        			cur_num2 *= 10;
        		}
        		num1 += cur_num1;
        		num2 += cur_num2;
        		l1 = l1->next;
        		l2 = l2->next;
        		++count;
        	}
        	else if (l1 != NULL)
        	{
        		cur_num1 = l1->val;
        		int sum = cur_num1 + carry;
        		if (sum >= 10)
        		{
        			sum -= 10;
        			carry = 1;
        		}
        		else
        			carry = 0;
        		node->val = sum;

        		if (lst_head == NULL)
        		{
        			current = node;
        			lst_head = current;
        		}
        		else
        		{
        			current->next = node;
        			current = current->next;
        		}

        		for (int i = 0; i < count; ++i)
        		{
        			cur_num1 *= 10;
        		}
        		num1 += cur_num1;
        		l1 = l1->next;
        		++count;
        	}
        	else if (l2 != NULL)
        	{
        		cur_num2 = l2->val;
        		int sum = cur_num2 + carry;
        		if (sum >= 10)
        		{
        			sum -= 10;
        			carry = 1;
        		}
        		else
        			carry = 0;
        		node->val = sum;

        		if (lst_head == NULL)
        		{
        			current = node;
        			lst_head = current;
        		}
        		else
        		{
        			current->next = node;
	        		current = current->next;
        		}

        		for (int i = 0; i < count; ++i)
        		{
        			cur_num2 *= 10;
        		}
        		num2 += cur_num2;
        		l2 = l2->next;
        		++count;
        	}
        	else
        		delete node;
        }
        if (carry == 1)
        {
        	ListNode *node = new ListNode(1);
        	current->next = node;
        }
        int ret_sum = num1 + num2;
        std::cout << ret_sum << std::endl;
        return lst_head;
    }
};