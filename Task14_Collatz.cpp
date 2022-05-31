#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//Problem1
class Collatz {
	int number;
	int counter;
public:
	Collatz(int a0) {
		number = a0;
		counter = 0;
	}

	int operator()()
	{
		if (counter == 0)
		{
			counter++;
			return number;
		}
		if (number % 2 == 0)
		{
			number = number / 2;
		}
		else
		{
			number = 3 * number + 1;
		}
		counter++;
		return number;
	}

	bool hasNext()
	{
		return number != 1;
	}
};

//Problem2
class Person {
	char* name;

	friend class Couple;

public:
	explicit Person(const char* n) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	Person(const Person& os) {
		name = new char[strlen(os.name) + 1];
		strcpy(name, os.name);
	}

	Person& operator=(const Person& os) {
		if (this != &os) {
			delete[] name;
			name = new char[strlen(os.name) + 1];
			strcpy(name, os.name);
		}
		return *this;
	}

	~Person() {
		std::cout << "DEL " << name << std::endl;
		delete[] name;
	}

	friend std::ostream& operator<<(std::ostream& str, const Person& os) {
		return str << os.name;
	}
};

class Couple {
	Person* wife, * husband;
public:
	Couple(const Person& she, const Person& he) : wife(new Person(she)), husband(new Person(he)) {

	}

	Couple(const Couple& other) : wife(new Person(*other.wife)), husband(new Person(*other.husband)) {

	}

	Couple& operator=(const Couple& other) {
		if (this != &other) {
			delete wife;
			delete husband;
			wife = new Person(*other.wife);
			husband = new Person(*other.husband);
		}
		return *this;
	}

	~Couple() {
		delete wife;
		delete husband;
	};

	friend std::ostream& operator<<(std::ostream& str, const Couple& p) {
		str << "Couple: he " << *p.husband << ", she " << *p.wife;
		return str;
	}
};

int main()
{
	//Problem1 Main
	Collatz collatz(3);
	while (collatz.hasNext())
		std::cout << collatz() << " ";
	std::cout << '\n';

	//Problem2 Main
	using std::cout; using std::endl;
	Person* pjohn = new Person("John"),
		* pjane = new Person("Jane");
	Person mary("Mary"), mark("Mark");
	Couple* pcouple1 = new Couple(mary, *pjohn);
	Couple couple2(*pjane, mark);
	delete pjohn;
	delete pjane;
	cout << *pcouple1 << endl;
	cout << couple2 << endl;
	couple2 = *pcouple1;
	delete pcouple1;
	cout << couple2 << endl;

	return 0;
}

