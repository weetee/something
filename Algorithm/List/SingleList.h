#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

/*
** 该单链表有头节点，而头节点中的value值无用
*/

#include <iostream>
using std::cout;
using std::endl;

class SingleList
{
public:
	struct Node
	{
		int m_val;
		struct Node *m_next;
		Node(int val = 0) : m_val(val), m_next(NULL) {};
	};

	SingleList()
	{
		m_head = new Node();
		m_size = 0;
	}
	~SingleList()
	{
		while (m_head)
		{
			struct Node *cur_node = m_head;
			m_head = m_head->m_next;
			if (cur_node != NULL)
				delete cur_node;
		}
	}

	int InsertList(int val, int key = -1) // 默认在表尾插入，key为0表示在表头插入
	{
		if (key != -1 && key > m_size)
		{
			cout << "not find key position!" << endl;
			return -1;
		}
		
		struct Node *cur_node = m_head;
		int cur_cnt = 0;
		while (cur_node != NULL)
		{
			if ((key == cur_cnt) || (cur_node->m_next == NULL && key == -1))
			{
				struct Node *new_node = new Node(val);
				struct Node *next = cur_node->m_next;
				cur_node->m_next = new_node;
				new_node->m_next = next;
				++m_size;
				break;
			}
			cur_node = cur_node->m_next;
			++cur_cnt;
		}
		return 0;
	}

	int RemoveList(int key) 	//删除key位置上的元素，起始为1
	{
		if (key < 1 || key > m_size)
		{
			cout << "Remove list not find key position." << endl;
			return -1;
		}
		struct Node *cur_node = m_head;
		int cur_cnt = 0;
		while (cur_node->m_next != NULL)
		{
			if (cur_cnt + 1 == key)
			{
				struct Node *prev = cur_node;
				struct Node *del = cur_node->m_next;
				struct Node *next = del->m_next;
				prev->m_next = next;
				delete del;
				--m_size;
				break;
			}
			++cur_cnt;
			cur_node = cur_node->m_next;
		}
		return 0;
	}

	bool IsEmpty()
	{
		return m_size == 0;
	}

	void PrintList()
	{
		if (m_head != NULL)
		{
			struct Node *cur_node = m_head->m_next;
			while (cur_node != NULL)
			{
				cout << cur_node->m_val << " ";
				cur_node = cur_node->m_next;
			}
			cout << endl;
		}
	}

	void ReverseList()
	{
		if (m_size > 0)
		{
			struct Node *cur_node = m_head->m_next;
			struct Node *prev_node = NULL;
			while (cur_node != NULL)
			{
				struct Node *next = cur_node->m_next;
				if (!next)
				{
					cur_node->m_next = prev_node;
					prev_node = cur_node;
					break;
				}
				else
				{
					cur_node->m_next = prev_node;
					prev_node = cur_node;
					cur_node = next;
				}
			}
			m_head->m_next = prev_node;
		}
	}

private:
	struct Node *m_head;
	int m_size;
};

#endif //SINGLE_LIST_H