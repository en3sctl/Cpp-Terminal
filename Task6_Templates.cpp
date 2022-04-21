#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <ctime>
#include <utility>

using namespace std;

//Problem1
template <class T>
T indexLargest(T array[], int max, int min, size_t size)
{
	max = array[0];
	min = array[0];
	int min_index = 0;
	int max_index = 0;

	for (int j = 0; j < size; j++)
	{
		if (max < array[j])
		{
			max = array[j];
			max_index = j;
		}
		if (min > array[j])
		{
			min = array[j];
			min_index = array[j];
		}
	}
	max_index += 1;
	min_index += 1;
}


//Problem2
using std::vector;
using std::function;

template <typename T, typename FunType>
vector<T> filter(const vector<T>& v, FunType p) 
{
	vector <T> filtered;
	for (auto i = v.cbegin(); i != v.cend(); ++i)
	{
		if (p(*i))
			filtered.push_back(*i);
	}
	return filtered;
}

template <typename T, typename FunType1, typename FunType2>
vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p) 
{
	vector <T> process_element;
	for (auto i = 0; i < v.size(); i++)
	{
		v[i] = t(v[i]);
		if (p(v[i]))
			process_element.push_back(v[i]);
	}
	return process_element;
}

template <typename T>
void printVec(const vector<T>& v) 
{
	cout << "[ ";
	for(auto elements : v)
	{
		cout << elements << ' ';
	}
	cout << "]\n";
}

//Problem3
template < typename T, typename FUN>
size_t part(T * arr, size_t size, FUN f) {
	T temp;
	size_t p = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (f(arr[i]))
		{
			temp = arr[p];
			arr[p++] = arr[i];
			arr[i] = temp;
		}
	}
	return p;
}

template < typename T>
void printTab(const T * t, size_t size) {
	cout << "[ ";
	for (size_t i = 0; i < size; i++) cout << t[i] << " ";
	cout << "]" << endl;	
}

bool isEven(int e) 
{
	return e % 2 == 0; 
}

bool isUnEven(int e)
{
	return e % 2 == 1;
}

bool isDividing7(int e)
{
	return e % 7 == 0;
}

int main()
{
	//Problem1 Main
	int a1 [] = {12,5,23,5,7,2};
	double a2 [] = { 12.3,5.5,23.8,5.1,7.2,2.4 };
	string a3 [] = { "12", "3", "4", "5"};

	//Problem2 Main
	vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
	printVec(v);
	vector<int> r = filter(v, [](int elements) { if (elements % 2 == 0) return true; });
	printVec(r);
	vector<int> s = filter(v, [](int elements) { if (elements > 0) return true; });
	printVec(s);
	vector<double> w{ 1.5, -3.1, 4.0, -2.0, 6.3 };
	printVec(w);
	double mn = -0.5, mx = 0.5;
	vector<double> d =
		transfilt(w, [](double elem) { return sin(elem); }, [mn, mx](double elem1) { return elem1 > mn && elem1 <= mx; });
	printVec(w);
	printVec(d);

	//Problem3 Main
	size_t ind = 0;
	
	int a1[] = { 1,2,3,4,5,6 };
	ind = part(a1, 6, isEven);
	std::cout << "ind = " << ind << " ";
	printTab(a1, 6);
	
	int a2[] = { 1,2,3,4,5,6 };
	// lambda as argument: a predicate checking
	// if the given number is odd
	ind = part(a2, std::size(a2), isUnEven);
	std::cout << "ind = " << ind << " ";
	printTab(a2, std::size(a2));

	std::string a3[] = { "Ala", "Ula", "Ela", "Ola", "Maja" };
	std::string mn = "Bea";
	std::string mx = "Sue";
	// lambda as argument: a predicate checking
	// if the given name is in the range [mn,mx]
	//->
	auto isBetween = [&mn, &mx](string e) -> bool {/*im having trouble here*/ };
	ind = part(a3, std::size(a3), isBetween);
	std::cout << "ind = " << ind << " ";
	printTab(a3, std::size(a3));
	
	constexpr size_t DIM = 500000;
	int* a4 = new int[DIM];
	srand(unsigned(time(0)));
	for (size_t i = 0; i < DIM; ++i) a4[i] = rand() % 21 + 1;
	// lambda as argument: a predicate checking
	// if the given number is divisible by 7
	ind = part(a4, DIM, isDividing7);
	std::cout << "ind = " << ind << std::endl;
	delete[] a4;
}

