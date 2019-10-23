
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
class DList
{
private:
public:
	Node* head;
	DList()
	{
		head = NULL;
	}
	Node* CreateNode(int val);
	bool IsEmpty();
	void InsertLast(int);
	void InsertFirst(int);
	void InsertAtIndex(int, int);
	void RemoveLast(); 
	void RemoveFirst(); 
	void RemoveAtIndex(int);
	void Display(); 
	void DisplayReverse();
	int CountItems();
	void Find(int);
	void ChangeList();
	void FindSum();
	int CheckDuplicate(int);
	void Square();
	void CountEvenAndOdd();
};
Node* DList::CreateNode(int val) {
	Node *newNode = new Node();
	newNode->next = NULL;
	newNode->data = val;
	return newNode;
}
bool DList::IsEmpty() 
{
	if (head == NULL)
	{
		return true;
	}
	else
		return false;
}
void DList::InsertLast(int x)
{
	if (IsEmpty()) 
	{
		head = CreateNode(x);
	}
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		Node *newNode = CreateNode(x);
		newNode->prev = temp;
		temp->next = newNode;
	}
}
void DList::InsertFirst(int x)
{
	if (IsEmpty())
	{
		head = CreateNode(x);
	}
	else
	{
		Node* temp = head;
		Node* newNode = CreateNode(x);
		newNode->next = temp;
		newNode->prev = NULL;
		temp->prev = newNode;
		head = newNode;
	}
} 
void DList::InsertAtIndex(int index, int val) 
{
	int count=0;
	Node* temp = head;
	while(temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (index > count)
	{
		InsertLast(val);
	}
	else if (index == 0)
	{
		InsertFirst(val);
	}
	else
	{
		int ct = 0;
		temp = head;
		while (ct < index)
		{
			temp = temp->next;
			ct++;
		}
		Node* newNode = CreateNode(val);
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
	}
}
void DList::RemoveLast()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else {
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete(temp);
	}
}
void DList::RemoveFirst()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else {
		Node* temp = head;
		temp->next->prev = NULL;
		head = temp->next;
		delete(temp);
	}
}
void DList::RemoveAtIndex(int index)
{
	int count=0;
	Node* temp = head;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (index >= count)
	{
		RemoveLast();
	}
	else if (index == 0)
	{
		RemoveFirst();
	}
	else
	{
		int ct = 0;
		temp = head;
		while (ct < index)
		{
			temp = temp->next;
			ct++;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		temp->prev = NULL;
		temp->next = NULL;
		delete(temp);
		
	}
}
void DList::Display()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else {
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}

void DList::DisplayReverse() 
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else {
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
}
int DList::CountItems()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
		return 0;
	}
	else {
		Node* temp = head;
		int count = 1;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		cout << "List contains " << count << " elements." << endl;
		return count;
	}
}
void DList::Find(int x)
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else
	{
		Node* temp = head;
		int count = 0;
		bool Found = false;
		while (temp->next != NULL)
		{
			if (temp->data == x)
			{
				cout << "Element found at index : " << count << endl;
				Found = true;
				break;
			}
			count++;
			temp = temp->next;

		}
		if (Found == false)
		{
			cout << "Element not found." << endl;
		}
	}
}
void DList::ChangeList() //Weird
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else {
		Node* temp = head;
		Node* tmp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		if (tmp->data > temp->data)
		{
			int t = temp->data;
			temp->data = tmp->data;
			tmp->data = t;
			temp->prev->next = NULL;
			temp->prev = NULL;
			temp->next = tmp;
			tmp->prev = temp;
			head = temp;
		}
	}
}
void DList::FindSum()
{
	if (IsEmpty()) 
	{
		cout << "List is Empty !";
	}
	else {
		int Sum = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			Sum += temp->data;
			temp = temp->next;
		}
		cout << " Sum of All elements in the list is : " << Sum << endl;
	}
}
int DList::CheckDuplicate(int val)
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
		return 0;
	}
	else
	{
		Node* temp = head;
		int count = 0;
		while (temp->next != NULL)
		{
			if (temp->data == val)
			{	
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
}
void DList::Square()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else
	{
		Node* temp = head;
		while(temp != NULL)
		{
			temp->data = (temp->data * temp->data);
			temp = temp->next;
		}
	}
}
void DList::CountEvenAndOdd()
{
	if (IsEmpty())
	{
		cout << "List is Empty !";
	}
	else
	{
		Node* temp = head;
		int odd = 0;
		int even = 0;
		while (temp != NULL)
		{
			if ((temp->data % 2) == 0)
			{
				even++;
			}
			else if ((temp->data % 2) == 1)
			{
				odd++;
			}
			temp = temp->next;
		}
		cout << " Odd : " << odd << endl;
		cout << " Even : " << even << endl;
	}
}
int main()
{
	DList d;
	d.InsertFirst(12);
	d.InsertAtIndex(0,69);
	d.InsertAtIndex(1,22);
	d.InsertLast(47);
	d.InsertLast(39);
	d.InsertLast(12);
	d.Display();
	cout << "\n \n************************************************************\n \n";
	d.DisplayReverse();
	cout << "\n \n************************************************************\n \n";
	d.RemoveAtIndex(4);
	d.Display();
	cout << "\n \n************************************************************\n \n";
	d.CountItems();
	cout << "\n \n************************************************************\n \n";
	d.Find(22);
	cout << "\n \n************************************************************\n \n";
	d.Find(12);
	cout << "\n \n************************************************************\n \n";
	d.ChangeList();
	d.Display();
	cout << "\n \n************************************************************\n \n";
	d.FindSum();
	cout << "\n \n************************************************************\n \n";
	cout << "Number of 12's in the list : " << d.CheckDuplicate(12) << endl;
	cout << "\n \n************************************************************\n \n";
	d.Square();
	d.Display();
	cout << "\n \n************************************************************\n \n";
	d.CountEvenAndOdd();
	cout << "\n \n************************************************************\n \n";
}