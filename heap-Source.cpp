#include <iostream>
#include <stdlib.h>
using namespace std;
template <class h>
class Heap
{
private:
	h * Array;
	int maxSize;
	int index;
	void swap(h &a, h &b)
	{
		h x = a;
		a = b;
		b = x;
	}
	void DisplayDcn()
	{
		cout << "Next index = " << index << endl;
		for (int i = Array[0]; i > 1; i--)
		{
			cout << Array[i - 1] << " " << endl;
		}
	}
	void maxheap(int *a, int i, int n)
	{
		int j, temp;
		temp = a[i];
		j = 2 * i;
		while (j <= n)
		{
			if (j < n && a[j + 1] > a[j])
				j = j + 1;
			if (temp > a[j])
				break;
			else if (temp <= a[j])
			{
				a[j / 2] = a[j];
				j = 2 * j;
			}
		}
		a[j / 2] = temp;
		return;
	}
	void Maxsort()
	{
		int i, temp;
		for (i = index - 1; i >= 2; i--)
		{
			temp = Array[i];
			Array[i] = Array[1];
			Array[1] = temp;
			maxheap(Array, 1, i - 1);
		}
	}

public:

	Heap()
	{
		maxSize = 150;
		index = 1;
		Array = new h[maxSize];
	}
	void Ascending()
	{
		Maxsort();
		Display();
	}
	void Decendiong()
	{
		Maxsort();
		DisplayDcn();
	}
	void MinInsert(h val)
	{
		if (index == 1)
		{
			Array[index++] = val;
			Array[0] = index;
		}
		else
		{
			Array[index++] = val;
			Array[0] = index;
			int x = Array[0] - 1;
			while (Array[x]< Array[x / 2] && x != 1)
			{
				swap(Array[x], Array[x / 2]);
				x = x / 2;
			}
		}
	}

	void MaxInsert(h val)
	{
		if (index == 1)
		{
			Array[index++] = val;
			Array[0] = index;
		}
		else
		{
			Array[index++] = val;
			Array[0] = index;
			int x = Array[0] - 1;
			while (Array[x] > Array[x / 2] && x != 1)
			{
				swap(Array[x], Array[x / 2]);
				x = x / 2;
			}
		}
	}
	void Display()
	{
		cout << "Next Index" << index << endl;
		for (int i = 1; i < Array[0]; i++)
		{
			cout << i << "." << Array[i] << " " << endl;
		}
	}
	void DeleteMinHeap()
	{
		index--;
		Array[0]--;
		swap(Array[1], Array[Array[0]]);
		if (Array[0] > 1)
		{
			int i = 1;
			int j = 1 * 2;
			int k = 1 * 2 + 1;
			while (1)
			{
				if (i >= Array[0] || j >= Array[0] || k >= Array[0])
				{
					break;
				}
				if (Array[i] > Array[j] && Array[i] > Array[k])
				{
					if (Array[j] <= Array[k])
					{
						swap(Array[i], Array[j]);

						i *= 2;
						j = i * 2;
						k = i * 2 + 1;
					}
					else
					{
						swap(Array[i], Array[k]);
						i *= 2;
						i++;
						j = i * 2;
						k = i * 2 + 1;
					}
				}
				else if (Array[i] > Array[j])
				{
					swap(Array[i], Array[j]);
					i *= 2;
					j = i * 2;
					k = i * 2 + 1;
				}
				else if (Array[i] > Array[k])
				{
					swap(Array[i], Array[k]);
					i *= 2;
					i++;
					j = i * 2;
					k = i * 2 + 1;
				}
			}
		}
		else
		{
			cout << "Heap Is Empty!!!" << endl;
		}
	}

	void DeleteMaxHeap()
	{
		index--;
		Array[0]--;
		swap(Array[1], Array[0]);
		if (Array[0] > 1)
		{
			int i = 1;
			int j = 1 * 2;
			int k = 1 * 2 + 1;
			while (1)
			{
				if (i == Array[0] || j == Array[0] || k == Array[0])
				{
					break;
				}
				if (Array[i] < Array[j] && Array[i] < Array[k])
				{
					if (Array[j] >= Array[k])
					{
						swap(Array[i], Array[j]);
						i *= 2;
						j = i * 2;
						k = i * 2 + 1;
					}
					else
					{
						swap(Array[i], Array[k]);
						i *= 2;
						i++;
						j = i * 2;
						k = i * 2 + 1;
					}
				}
				else if (Array[i] < Array[j])
				{
					swap(Array[i], Array[j]);
					i *= 2;
					j = i * 2;
					k = i * 2 + 1;
				}
				else if (Array[i] < Array[k])
				{
					swap(Array[i], Array[k]);
					i *= 2;
					i++;
					j = i * 2;
					k = i * 2 + 1;
				}
			}
		}
		else
		{
			cout << "Heap Is Empty!!!" << endl;
		}
	}

};
int main()
{
	Heap<int> hp;
	int n;
	do{
		cout << "Enter Your Choice" << endl;
		cout << "Press 1: To Insert min heap" << endl;
		cout << "Press 2: To Insert max heap" << endl;
		cout << "Press 3: To delete min heap" << endl;
		cout << "Press 4: To delete max heap" << endl;
		cout << "Press 5: Ascending order using min heaps" << endl;
		cout << "Press 6: Descending order using max heaps" << endl;
		cout << "Press 7: To Display" << endl;
		cout << "Press -1: To exit" << endl;
		cin >> n; 
		cout <<endl;
		if (n == 1)
		{
			cout << "Enter value to full heap,press -1 to exit" << endl;
			int n1 = 0;
			do
			{
				cin >> n1;
				hp.MinInsert(n1);
			} while (n1 != -1);
			
		}
		if (n == 2)
		{
			cout << "Enter value to full heap,press -1 to exit" << endl;
			int n2 = 0;
			do
			{
				cin >> n2;
				hp.MaxInsert(n2);
			} while (n2 != -1);
			
		}
		if (n == 3)
		{
			hp.DeleteMinHeap();
			
		}
		if (n == 4)
		{
			hp.DeleteMaxHeap();
			
		}
		if (n == 5)
		{
			hp.Ascending();
			
		}
		if (n == 6)
		{
			hp.Decendiong();
			
		}
		if (n == 7)
		{
			hp.Display();

		}
	} while (n != -1);
	
	return 0;
}