#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node<T>*rightchild;
	Node<T>*leftchild;
};
template <class T>
class binarytree
{
private:
	Node<T>*root;
	void ps(Node<T>*p)
	{
		if (p != nullptr)
		{
			ps(p->leftchild);
			ps(p->rightchild);
			cout << p->data << endl;

		}
	}
	void pre(Node<T>*p)
	{
		if (p != nullptr)
		{
			cout << p->data << endl;
			pre(p->leftchild);
			pre(p->rightchild);
		}
	}
	void in(Node<T>*p)
	{

		if (p != nullptr)
		{
			in(p->leftchild);
			cout << p->data << endl;
			in(p->rightchild);
		}
	}
	void rnl(Node<T>*p)
	{
		if (p != nullptr)
		{
			in(p->rightchild);
			cout << p->data << endl;
			in(p->leftchild);
		}
	}
	void rln(Node<T>*p)
	{
		if (p != nullptr)
		{
			in(p->rightchild);
			in(p->leftchild);
			cout << p->data << endl;
		}
	}
	void nrl(Node<T>*p)
	{
		if (p != nullptr)
		{
			cout << p->data << endl;
			in(p->rightchild);
			in(p->leftchild);
		}
	}
	int findh(Node<T>*temp)
	{
		if (temp == nullptr)
		{
			return 0;
		}
		else
		{
			int ll = findh(temp->leftchild);
			int rl = findh(temp->rightchild);
			if (ll >= rl)
			{
				return (ll + 1);
			}
			else
			{
				return (rl + 1);
			}
		}
	}
public:
	binarytree()
	{
		root = nullptr;
	}
	void print2DUtil(Node<T> *root, int space)
	{
		int COUNT = 7;
		if (root == NULL)
			return;
		space += COUNT;
		print2DUtil(root->rightchild, space);

		cout << endl;
		for (int i = COUNT; i < space; i++)

			cout << " ";

		cout << root->data;
		print2DUtil(root->leftchild, space);
	}
	void print2D()
	{
		print2DUtil(root, 0);
	}

	void insertion(T val)
	{
		Node<T>*New = new Node<T>;
		New->data = val;
		New->rightchild = nullptr;
		New->leftchild = nullptr;
		if (root == nullptr)
		{
			root = New;
		}
		else
		{
			Node<T>*temp = root;
			while (true)
			{
				if (val >= temp->data)
				{
					if (temp->rightchild == nullptr)
					{
						temp->rightchild = New;
						break;
					}
					else
					{
						temp = temp->rightchild;
					}
				}
				else
				{
					if (temp->leftchild == nullptr)
					{
						temp->leftchild = New;
						break;
					}
					else
					{
						temp = temp->leftchild;
					}
				}
			}
		}
	}
	void LNR()
	{
		in(root);
	}
	void LRN()
	{
		ps(root);
	}
	void NLR()
	{
		pre(root);
	}
	void RNL()
	{
		rnl(root);
	}
	void RLN()
	{
		rln(root);
	}
	void NRL()
	{
		nrl(root);
	}
	void FindH()
	{
		cout << endl << "Height of tree is : " << findh(root) << endl;
	}
};
int main()
{
	system("color 9F");
	binarytree<int> t;
	cout << "Enter the value of tree" << endl;
	cout << "Enter -1 to Exit" << endl;
	for (int i;;)
	{
		cout << "Enter Element";
		cin >> i;
		if (i == -1)
		{
			break;
		}
		else
			t.insertion(i);

	}
	int n;
	do{
		cout << "Press 1 To find height of tree" << endl;
		cout << "Press 2 to LNR" << endl;
		cout << "Press 3 to LRN" << endl;
		cout << "Press 4 to NLR" << endl;
		cout << "Press 5 to NRL" << endl;
		cout << "Press 6 to RLN" << endl;
		cout << "Press 7 to RNL" << endl;
		cout << "Press 8 to display tree" << endl;
		cout << "Enter Yourr choice" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
				  t.FindH();
				  cout << endl;
				  break;
		}
		case 2:
		{
				  t.LNR();
				  cout << endl;
		}
		case 3:
		{
				  t.LRN();
				  cout << endl;

		}
		case 4:
		{
				  t.NLR();
				  cout << endl;
		}
		case 5:
		{
				  t.NRL();
				  cout << endl;
		}
		case 6:
		{
				  t.RLN();
				  cout << endl;

		}
		case 7:
		{
				  t.RNL();
				  cout << endl;


		}
		case 8:
		{
				  t.print2D();
		}
		default:
			break;
		}
	} while (n != -1);
	system("pause");
	return 0;
}