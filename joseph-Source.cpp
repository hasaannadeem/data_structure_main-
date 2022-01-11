#include <iostream>
#include <Windows.h>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>*next;
	Node<T>*prev;
};

template<class T>
class DCLL
{
	Node<T>*head;
	Node<T>*tail;
public:
	DCLL()
	{
		head = nullptr;
		tail = nullptr;
	}


	void insertAtHead(T val)
	{
		Node<T>*NEW = new Node<T>;
		NEW->data = val;
		NEW->next = nullptr;
		NEW->prev = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			tail = NEW;
			head = NEW;
			tail->next = head;
			head->prev = tail;
		}

		else
		{
			tail->next = NEW;
			NEW->prev = tail;
			head->prev = NEW;
			NEW->next = head;
			head = NEW;
		}
	}
	void insertAtTail(T val)
	{
		Node<T>*NEW = new Node<T>;
		NEW->data = val;
		NEW->next = nullptr;
		NEW->prev = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			tail = NEW;
			head = NEW;
			tail->next = head;
			head->prev = tail;
		}

		else
		{
			tail->next = NEW;
			NEW->prev = tail;
			NEW->next = head;
			head->prev = NEW;
			tail = NEW;
		}
	}



	void addSorted(T val)
	{
		if (head == nullptr && tail == nullptr)
		{
			insertAtTail(val);
		}

		else if (val < head->data)
			insertAtHead(val);

		else if (val > tail->data)
			insertAtTail(val);

		else
		{
			Node<T>*temp = head;
			while (1)
			{
				if (val > temp->data)
					temp = temp->next;
				else
					break;
			}

			Node<T>*newNode = new Node<T>;
			newNode->data = val;
			newNode->next = nullptr;
			newNode->prev = nullptr;

			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			temp->prev = newNode;
		}

	}
	void displayFromHead()
	{
		if (tail != nullptr)
		{
			Node<T>* temp = head->next;

			while (1)
			{
				cout << temp->data << endl;
				temp = temp->next;
				if (temp->next == head)
				{
					break;
				}
				if (temp == tail->next)
					break;
			}

		}
		else
		{
			cout << "CLL is Empty" << endl;
		}


	}
	void deletefromhead()
	{
		if (tail == nullptr)
		{
			cout << "Is empty" << endl;
		}
		Node<T>* temp = head;
		while (true)
		{

			temp = temp->next;
			if (temp->next == head)
			{
				break;
			}
		}
		Node<T>* temp1 = head;
		head = temp1->next;
		temp->next = head;
		delete temp1;
	}

	void joseph(T val, T start)
	{
		Node <T>* temp = head;
		while (true)
		{
			if (temp->next->data == start)
			{
				break;
			}
			temp = temp->next;
			if (temp == head)
			{
				cout << "Not correct";
			}
		}
		head = temp->next;
		while (head->next != head)
		{
			for (int i = 0; i < val; i++)
			{
				head = head->next;
			}
			deletefromhead();
			cout << endl << endl;
			displayFromHead();
			Sleep(300);
		}

	}
};


int main()
{
	//I use sleep function it will display answer atend
	DCLL<int> one;
	int user = 0;
	int n = 0;
	cout << "Press 1 to start the game: " << endl;
	cout << "Press 2 to Exit game: " << endl;
	cin >> user;
	if (user == 1)
	{
		cout << "Enter the number of values you want to add : ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			one.insertAtTail(i);
		}
		one.displayFromHead();
		one.joseph(n, 1);
	}
	if (user == 2)
	{
		return 0;
	}

	system("pause");
	return 0;
}