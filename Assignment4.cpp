#include <iostream>
using namespace std;

template<typename T>
class Queue {
	struct Node {
		T data;
		Node* next;
		Node(const T& x) : data(x), next(nullptr)
		{
		}
	};

	typedef Node* pnode;
	pnode head, tail;

public:
	Queue();
	bool empty() const
	{
		return head == nullptr;
	}

	void put(const T& data);
	T get();
	void destructor()const;
	~Queue();
};

// implementation

template<class T>
Queue<T>::Queue()
{
	head = nullptr;
}

template <class T>
void Queue<T>::put(T x)
{
	if (empty())
		head = tail = new Node(x);
	else
	{
		pnode h = tail;
		tail = new Node(x);
		h->next = tail;
	}
}

template<class T>
T Queue<T>::get()
{
	if (empty())
		throw out_of_range("Empty");
	T temp = head->data;
	pnode old = head;
	head = head->next;
	delete old;
	return temp;
}

template <class T>
void Queue<T>::destructor()const
{
	pnode help = head;
	while (help != nullptr)
	{
		cout << help->data << endl;
		help = help->next;

	}
}

template <class T> 
Queue<T>::~Queue()
{
	while (head != nullptr)
		get();
}

int main()
{
	int data1, data2;
	Queue<int>* q = new Queue<int>();
	q->put(1);
	data1 = q->get();
	std::cout << " data1=" << data1 << std::endl;

	q->put(1);
	q->put(2);
	data1 = q->get();
	data2 = q->get();
	std::cout << " data1=" << data1
		<< " data2=" << data2 << std::endl;
	q->put(1); q->put(2); q->put(3);
	q->put(4); q->put(5); q->put(6);
	while (!q->empty())
		std::cout << " " << q->get();
	std::cout << std::endl;
	q->put(1); q->put(2); q->put(3);

	q->destructor();

	delete q;
}

