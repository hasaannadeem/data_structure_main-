// red-black-tree-project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// L1F17BSCS0408	MUHAMMAD MUNEEB
// L1F17BSCS0270	M.DANISH
// L1F17BSCS0296	HASAAN NADEEM (IEEE MARKETING HEAD)


#include <iostream>
#include "windows.h"
using namespace std;
class Node
{
public:
	int Data;
	Node *Parent;
	char Color;
	Node *Left;
	Node *Right;
};
class RBT
{
	Node *Root;
	Node *q;
public:
	RBT()
	{
		q = NULL;
		Root = NULL;
	}
	/////////////////////////////////////////////////////////////////////////////
	void insert(int z)
	{
		int  i = 0;

		Node *p, *q;
		Node *t = new Node;
		t->Data = z;
		t->Left = NULL;
		t->Right = NULL;
		t->Color = 'r';
		p = Root;
		q = NULL;
		if (Root == NULL)
		{
			Root = t;
			t->Parent = NULL;
		}
		else
		{
			while (p != NULL)
			{
				q = p;
				if (p->Data < t->Data)
					p = p->Right;
				else
					p = p->Left;
			}
			t->Parent = q;
			if (q->Data < t->Data)
				q->Right = t;
			else
				q->Left = t;
		}
		insertcheck(t);
	}
	/////////////////////////////////////////////////////////////////////////////////
	void insertcheck(Node *t)
	{
		Node *u;
		if (Root == t)
		{
			t->Color = 'b';
			return;
		}
		while (t->Parent != NULL && t->Parent->Color == 'r')
		{
			Node *g = t->Parent->Parent;
			if (g->Left == t->Parent)
			{
				if (g->Right != NULL)
				{
					u = g->Right;
					if (u->Color == 'r')
					{
						t->Parent->Color = 'b';
						u->Color = 'b';
						g->Color = 'r';
						t = g;
					}
				}
				else
				{
					if (t->Parent->Right == t)
					{
						t = t->Parent;
						Leftrotate(t);
					}
					t->Parent->Color = 'b';
					g->Color = 'r';
					Rightrotate(g);
				}
			}
			else
			{
				if (g->Left != NULL)
				{
					u = g->Left;
					if (u->Color == 'r')
					{
						t->Parent->Color = 'b';
						u->Color = 'b';
						g->Color = 'r';
						t = g;
					}
				}
				else
				{
					if (t->Parent->Left == t)
					{
						t = t->Parent;
						Rightrotate(t);
					}
					t->Parent->Color = 'b';
					g->Color = 'r';
					Leftrotate(g);
				}
			}
			Root->Color = 'b';
		}
	}
	////////////////////////////////////////////////////////////////////////
	void del()
	{
		if (Root == NULL)
		{
			cout << "\nEmpty Tree.";
			return;
		}
		int x;
		cout << "\nEnter the Data of the Node to be deleted: ";
		cin >> x;
		Node *p;
		p = Root;
		Node *y = NULL;
		Node *q = NULL;
		int found = 0;
		while (p != NULL && found == 0)
		{
			if (p->Data == x)
				found = 1;
			if (found == 0)
			{
				if (p->Data < x)
					p = p->Right;
				else
					p = p->Left;
			}
		}
		if (found == 0)
		{
			cout << endl << "Element Not Found.";
			return;
		}
		else
		{
			cout << endl << "Deleted Element: " << p->Data;
			cout << endl << "Colour: ";
			if (p->Color == 'b')
				cout << "Black\n";
			else
				cout << "Red\n";

			if (p->Parent != NULL)
				cout << endl << "Parent: " << p->Parent->Data;
			else
				cout << endl << "There is no Parent of the Node.  ";
			if (p->Right != NULL)
				cout << endl << "Right Child: " << p->Right->Data;
			else
				cout << endl << "There is no Right child of the Node.  ";
			if (p->Left != NULL)
				cout << endl << "Left Child: " << p->Left->Data;
			else
				cout << endl << "There is no Left child of the Node.  ";
			cout << endl << "Node Deleted.";
			if (p->Left == NULL || p->Right == NULL)
				y = p;
			else
				y = successor(p);
			if (y->Left != NULL)
				q = y->Left;
			else
			{
				if (y->Right != NULL)
					q = y->Right;
				else
					q = NULL;
			}
			if (q != NULL)
				q->Parent = y->Parent;
			if (y->Parent == NULL)
				Root = q;
			else
			{
				if (y == y->Parent->Left)
					y->Parent->Left = q;
				else
					y->Parent->Right = q;
			}
			if (y != p)
			{
				p->Color = y->Color;
				p->Data = y->Data;
			}
			if (y->Color == 'b')
				delfix(q);
		}
	}
	////////////////////////////////////////////////////////////////////////////
	void delfix(Node *p)
	{
		Node *s;
		while (p != Root && p->Color == 'b')
		{
			if (p->Parent->Left == p)
			{
				s = p->Parent->Right;
				if (s->Color == 'r')
				{
					s->Color = 'b';
					p->Parent->Color = 'r';
					Leftrotate(p->Parent);
					s = p->Parent->Right;
				}
				if (s->Right->Color == 'b'&&s->Left->Color == 'b')
				{
					s->Color = 'r';
					p = p->Parent;
				}
				else
				{
					if (s->Right->Color == 'b')
					{
						s->Left->Color == 'b';
						s->Color = 'r';
						Rightrotate(s);
						s = p->Parent->Right;
					}
					s->Color = p->Parent->Color;
					p->Parent->Color = 'b';
					s->Right->Color = 'b';
					Leftrotate(p->Parent);
					p = Root;
				}
			}
			else
			{
				s = p->Parent->Left;
				if (s->Color == 'r')
				{
					s->Color = 'b';
					p->Parent->Color = 'r';
					Rightrotate(p->Parent);
					s = p->Parent->Left;
				}
				if (s->Left->Color == 'b'&&s->Right->Color == 'b')
				{
					s->Color = 'r';
					p = p->Parent;
				}
				else
				{
					if (s->Left->Color == 'b')
					{
						s->Right->Color = 'b';
						s->Color = 'r';
						Leftrotate(s);
						s = p->Parent->Left;
					}
					s->Color = p->Parent->Color;
					p->Parent->Color = 'b';
					s->Left->Color = 'b';
					Rightrotate(p->Parent);
					p = Root;
				}
			}
			p->Color = 'b';
			Root->Color = 'b';
		}
	}
	////////////////////////////////////////////////////////////////////////
	void Leftrotate(Node *p)
	{
		if (p->Right == NULL)
			return;
		else
		{
			Node *y = p->Right;
			if (y->Left != NULL)
			{
				p->Right = y->Left;
				y->Left->Parent = p;
			}
			else
				p->Right = NULL;
			if (p->Parent != NULL)
				y->Parent = p->Parent;
			if (p->Parent == NULL)
				Root = y;
			else
			{
				if (p == p->Parent->Left)
					p->Parent->Left = y;
				else
					p->Parent->Right = y;
			}
			y->Left = p;
			p->Parent = y;
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	void Rightrotate(Node *p)
	{
		if (p->Left == NULL)
			return;
		else
		{
			Node *y = p->Left;
			if (y->Right != NULL)
			{
				p->Left = y->Right;
				y->Right->Parent = p;
			}
			else
				p->Left = NULL;
			if (p->Parent != NULL)
				y->Parent = p->Parent;
			if (p->Parent == NULL)
				Root = y;
			else
			{
				if (p == p->Parent->Left)
					p->Parent->Left = y;
				else
					p->Parent->Right = y;
			}
			y->Right = p;
			p->Parent = y;
		}
	}
	////////////////////////////////////////////////////////////////////////
	Node* successor(Node *p)
	{
		Node *y = NULL;
		if (p->Left != NULL)
		{
			y = p->Left;
			while (y->Right != NULL)
				y = y->Right;
		}
		else
		{
			y = p->Right;
			while (y->Left != NULL)
				y = y->Left;
		}
		return y;
	}
	/////////////////////////////////////////////////////////////////////////
	void disp()
	{
		display(Root);
	}
	void display(Node *p)
	{
		if (Root == NULL)
		{
			cout << endl << "Empty Tree.";
			return;
		}
		if (p != NULL)
		{
			cout << endl << "\t Node: ";
			cout << endl << " Data: " << p->Data;
			cout << endl << " Colour: ";
			if (p->Color == 'b')
				cout << "Black";
			else
				cout << "Red";
			if (p->Parent != NULL)
				cout << endl << " Parent: " << p->Parent->Data;
			else
				cout << endl << " There is no Parent of the Node.  ";
			if (p->Right != NULL)
				cout << endl << " Right Child: " << p->Right->Data;
			else
				cout << endl << " There is no Right child of the Node.  ";
			if (p->Left != NULL)
				cout << endl << " Left Child: " << p->Left->Data;
			else
				cout << endl << " There is no Left child of the Node.  ";
			cout << endl;
			if (p->Left)
			{
				cout << endl << "\nLeft:\n";
				display(p->Left);
			}
			/*else
			cout<<"\nNo Left Child.\n";*/
			if (p->Right)
			{
				cout << endl << "\nRight:\n";
				display(p->Right);
			}
			/*else
			cout<<"\nNo Right Child.\n"*/
		}
	}
	//////////////////////////////////////////////////////////////////////////////////
	void search(int x)
	{
		if (Root == NULL)
		{
			cout << endl << "Empty Tree\n";
			return;
		}

		Node *p = Root;
		int found = 0;
		while (p != NULL && found == 0)
		{
			if (p->Data == x)
				found = 1;
			if (found == 0)
			{
				if (p->Data < x)
					p = p->Right;
				else
					p = p->Left;
			}
		}
		if (found == 0)
			cout << endl << "Element Not Found.";
		else
		{
			cout << endl << "\t FOUND Node: ";
			cout << endl << " Data: " << p->Data;
			cout << endl << " Colour: ";
			if (p->Color == 'b')
				cout << "Black";
			else
				cout << "Red";
			if (p->Parent != NULL)
				cout << endl << " Parent: " << p->Parent->Data;
			else
				cout << endl << " There is no Parent of the Node.  ";
			if (p->Right != NULL)
				cout << endl << " Right Child: " << p->Right->Data;
			else
				cout << endl << " There is no Right child of the Node.  ";
			if (p->Left != NULL)
				cout << endl << " Left Child: " << p->Left->Data;
			else
				cout << endl << " There is no Left child of the Node.  ";
			cout << endl;

		}
	}
};
/////////////////////////////////////////////////////////////////////////////////
int main()
{
	system("color F0");
	int ch, y = 0, x;
	RBT tree;
	do
	{
		system("color F0");
		y = 0;
		cout << endl << "\t RED BLACK TREE ";
		cout << endl << "1. Insert in  tree ";
		cout << endl << "2. Delete a node ";
		cout << endl << "3. Search for a value";
		cout << endl << "4. Display ";
		cout << endl << "5. Exit ";
		cout << endl << "Enter Option: "; cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter -1 to break insertion loop;" << endl;
			for (;;)
			{
				cout << "Enter value to node: ";
				cin >> x;
				if (x == -1)
					break;
				tree.insert(x);
			}
			system("color 2A");
			break;
		case 2:
			tree.del();
			system("color 38");
			break;
		case 3:
			cout << endl << "Enter Data of the Node to be searched: ";
			cin >> x;
			tree.search(x);
			system("color 48");
			break;
		case 4:
			tree.disp();
			system("color 54");
			break;
		case 5:
			y = 1;
			break;
		default: cout << endl << "Enter a Valid Choice.";
		}
		cout << endl;
		Sleep(1200);
		system("color A8");


	} while (y != 1);
	system("color 5A");
	cout << "PROGRAM EXITED " << endl;


	system("pause");
	return 0;
}
