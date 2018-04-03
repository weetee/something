#include <iostream>
#include <queue>

using namespace std;

//层序遍历
void PrintTreeByLevel(BinaryTree *tree)
{
	if (tree == NULL) return;
	queue<BinaryTree*> node_que;
	BinaryTree *last = tree;
	BinaryTree *n_last = NULL;
	node_que.push(tree);
	while (!node_que.empty())
	{
		BinaryTree *cur_node = node_que.back();
		cout << cur_node->m_value;
		node_que.pop();
		if (cur_node->left)
		{
			node_que.push(cur_node->left);
			n_last = cur_node->left;
		}
		if (cur_node->right)
		{
			node_que.push(cur_node->right);
			n_last = cur_node->right;
		}
		if (last == cur_node)
		{
			cout << endl;
			last = n_last;
		}
		else
			cout << " ";
	}

}