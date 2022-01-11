#include<iostream>
#include<string>
using namespace std;
class Student{
public:
	int rollNo;
	string name;
	Student(){

	}
};


class MyHashTable{
	Student **arr;
	int size;
public:

	MyHashTable(int s){
		size = s;
		arr = new Student*[size]();

		for (int i = 0; i < size; i++)
			arr[i] = nullptr;

	}

	int hashIt(int n){
		return n%size;
	}

	void insertItem(int key, string value){
		int hashIndex = hashIt(key);
		while (arr[hashIndex] != nullptr){
			hashIndex = (hashIndex + 1) % size;
		}
		arr[hashIndex] = new Student();
		arr[hashIndex]->rollNo = key;
		arr[hashIndex]->name = value;
	}

	string getItem(int key){
		int hashIndex = hashIt(key);
		while (arr[hashIndex]->rollNo != key){
			hashIndex = (hashIndex + 1) % size;
			cout << "searching from linear probe" << endl;
		}
		return arr[hashIndex]->name;
	}

	void deleteItem(int key){
		int hashIndex = hashIt(key);
		while (arr[hashIndex]->rollNo != key){
			hashIndex = (hashIndex + 1) % size;
		}

		delete arr[hashIndex];
		arr[hashIndex] = nullptr;
	}

	void displayAll(){
		for (int i = 0; i < size; i++){
			if (arr[i] != nullptr)
				cout << "HASH_TABLE[" << i << "]: key=> " << arr[i]->rollNo << " value => " << arr[i]->name << endl;
		}
	}
	~MyHashTable(){
		for (int i = 0; i < size; i++){
			if (arr[i] != nullptr){
				cout << "deleting key = > " << arr[i]->rollNo << " value = > " << arr[i]->name << endl;
				delete arr[i];
				arr[i] = nullptr;
			}

		}
	}
};

int main(){

	MyHashTable mht(20);

	mht.insertItem(65401, "Ali");
	mht.insertItem(65421, "Ali 2");
	mht.insertItem(65404, "Zain");
	mht.insertItem(65403, "Taha");
	mht.insertItem(65405, "Ahmad");
	mht.insertItem(654715, "Zaid");
	mht.insertItem(654718, "Muazzaz");
	mht.insertItem(654719, "Arham");
	mht.insertItem(654711, "Adan");
	mht.insertItem(654713, "Ismaeel");

	cout << mht.getItem(654713) << endl;
	cout << mht.getItem(65421) << endl;

	mht.displayAll();


	return 0;
}
