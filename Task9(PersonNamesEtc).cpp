#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using std::string; using std::vector;
using namespace std;

//Problem1 
struct Node
{
	int   data;
	Node* next;
};

void addSorted(Node*& head, int data)
{
	if (head == nullptr || data <= head->data)
	{
		head = new Node{ data, head };
		return;
	}

	Node* tmp = head;
	while (tmp->next != nullptr && data >= tmp->next->data)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node{ data, tmp->next };
}

void showList(const Node* head)
{
	const Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

void deleteList(Node*& head)
{
	Node* next = NULL;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}

	*&head = NULL;
}

//==============================================================================================

//Problem2
struct Person
{
	string name;
	string nickname;
	int birthYear;
};

struct Name
{
	string name;
	vector<Person> pers;
};

Name* checkName(vector<Name>& names, const string& name)
{
	for (Name& fname : names)
	{
		if (fname.name == name)
		{
			return &fname;
		}
	}
	return nullptr;
}

vector<Name> groupByName(const vector<Person>& persons, std::function<bool(Name, Name)> pred)
{
	vector<Name> result;
	for (Person person : persons)
	{
		Name* tmp = checkName(result, person.name);
		if (tmp == nullptr)
		{
			result.push_back(Name{ person.name, vector<Person>{person} });
		}
		else
		{
			tmp->pers.push_back(person);
		}
	}
	std::sort(begin(result), end(result), pred);
	return result;
}

void printNames(const vector<Name>& names)
{
	for (Name name : names)
	{
		std::cout << name.name << " ( ";
		for (Person person : name.pers)
		{
			std::cout << person.nickname << " " << person.birthYear << " ";
		}
		std::cout << ")\n";
	}
}


int main()
{
	//Problem1 Main
	Node* head = nullptr;
	addSorted(head, 2); addSorted(head, 1);
	addSorted(head, 6); addSorted(head, 0);
	addSorted(head, 4); addSorted(head, 3);
	addSorted(head, 0); addSorted(head, 6);
	showList(head);
	deleteList(head);

	cout << endl;
	cout << "=================================================================\n";

	//Problem2 Main
	vector<Person> persons{
	{"Zara", "Crazy", 1989}, {"Zara", "Sugar", 2014},
	{"John", "Old", 1980}, {"Mary", "Sweet", 2004},
	{"Bill", "Fatso", 1990}, {"John", "Retard", 2010},
	{"Mary", "Redhead", 2001}, {"Mary", "Little", 2013},
	{"Bill", "Jojo", 2000}, {"Mary", "Bunny", 2020},
	{"Kate", "Honey", 1998} };

	vector<Name> res = groupByName(persons, [](Name n1, Name n2) {
		if (n1.pers.size() == n2.pers.size()) {
			return n1.name < n2.name;
		};
			return n1.pers.size() < n2.pers.size();
		});

	printNames(res);
}


