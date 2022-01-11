#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
class MyStack
{
	T * arr;
	int currentSize;
	int maximumSize;
public:

	void init(int s)
	{
		arr = new T[s];
		maximumSize = s;
		currentSize = 0;
	}
	int getCurrentSze()
	{
		return currentSize;
	}
	void push(T value)
	{
		if (!isFull())
		{
			arr[currentSize] = value;
			currentSize++;
		}
		else
			cout << "\nStack is already full " << endl;
	}
	T Pop()
	{
		if (!isEmpty())
		{
			currentSize--;
			return arr[currentSize];
		}
		else
			cout << "\nStack is Empty \n";
	}
	T TOP()
	{
		if (!isEmpty())
			return arr[currentSize - 1];
		else
		{
			cout << "\nStack is Empty \n";
		}
	}
	bool isEmpty()
	{
		if (currentSize == 0)
		{
			return true;
		}
		else
			return false;
	}
	bool isFull()
	{
		if (currentSize == maximumSize)
		{
			return true;
		}
		else
			return false;
	}
};
void ReadFile(int &, int &, int** &);
void PrintMatrix(int, int, int **);
int main()
{
	MyStack<char> Stack, Stack2;
	int rows, columns, **Matrix, **solution, x = 0, y = 0;
	ReadFile(rows, columns, Matrix);
	Stack.init((rows*columns) - columns);
	solution = new int *[rows];
	for (int i = 0; i < rows; i++)
		solution[i] = new int[columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			solution[i][j] = 0;
		}
	}
	cout << "original maze\n";
	PrintMatrix(rows, columns, Matrix);
	solution[x][y] = 1;
	Stack.push('R');
	while (true)
	{
		if (x == rows - 1 && y == columns - 1)
			break;
		else if ((y < columns - 1) && ((Matrix[x][y + 1]) == 1))
		{
			solution[x][++y] = 1;
			if (Stack.TOP() == 'L')
			{
				Stack.Pop();
				Matrix[x][y - 1] = -1;
				solution[x][y - 1] = 0;
			}
			else
				Stack.push('R');
		}
		else if ((x < rows - 1) && ((Matrix[x + 1][y]) == 1))
		{
			solution[++x][y] = 1;
			if (Stack.TOP() == 'U')
			{
				Stack.Pop();
				Matrix[x - 1][y] = -1;
				solution[x - 1][y] = 0;
			}
			else
				Stack.push('D');
		}
		else if ((x > 0) && ((Matrix[x - 1][y]) == 1))
		{
			solution[--x][y] = 1;
			if (Stack.TOP() == 'D')
			{
				Stack.Pop();
				Matrix[x + 1][y] = -1;
				solution[x + 1][y] = 0;
			}
			else
				Stack.push('U');
		}
		else if ((y > 0) && ((Matrix[x][y - 1]) == 1))
		{
			solution[x][--y] = 1;
			if (Stack.TOP() == 'R')
			{
				Stack.Pop();
				Matrix[x][y + 1] = -1;
				solution[x][y + 1] = 0;
			}
			else
				Stack.push('L');
		}
	}
	cout << "\n\nSolution Matrix \n\n";
	PrintMatrix(rows, columns, solution);
	cout << "\n\original Matrix with -1\n\n";
	PrintMatrix(rows, columns, Matrix);
	cout << "\n\nStack Directions\n\n";
	Stack2.init(Stack.getCurrentSze());
	cout << endl;
	int size = Stack.getCurrentSze();
	for (int i = 0; i < size; i++)
	{
		Stack2.push(Stack.Pop());
	}
	cout << "\n{";
	for (int i = 0; i < size; i++)
	{
		if (i < (size - 1))
			cout << Stack2.Pop() << ",";
		else
			cout << Stack2.Pop();
	}
	cout << "}\n";
	cout << endl;
	return 0;
}
void PrintMatrix(int Rows, int columns, int **Matrix)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void ReadFile(int &Rows, int &columns, int **&Stack)
{
	char*name = new char[100];
	cout << "Enter Your File name :";
	cin >> name;
	ifstream fin(name);
	fin >> Rows >> columns;
	Stack = new int*[Rows];
	for (int i = 0; i < Rows; i++)
		Stack[i] = new int[columns];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			fin >> Stack[i][j];
		}
	}
}