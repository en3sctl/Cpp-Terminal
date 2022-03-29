#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Problem1
void merge(const int* a, size_t dima, const int* b, size_t dimb, int* c) 
{
	for (int k = 0, i = 0, j = 0; k < dima; ++k) {
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
}

void printArr(const int* a, size_t dima, const char* m) 
{ 
	std::cout << m << " [ "; 
	for (size_t i = 0; i < dima; ++i)
		std::cout << a[i] << " "; 
	std::cout << "]\n"; 
}

//Problem2
std::vector<size_t> smallSum3(const std::vector<int>& a)
{

}

//Problem3
size_t length(const char* cstr)
{
	cout << cstr << strlen(cstr);
}

bool isLetter(char c)
{
	if (c >= 'A' && c <= 'Z')
		cout << c << " is an uppercase character\n";
	else if (c >= 'a' && c <= 'z')
		cout << c << " is ann lowercase character\n";
	else
		cout << c << " is not an alphabetic character\n";
}

char* reverse(char* cstr)
{
	int a, b;
	char* beginning, * ending, ch;

	a = strlen(cstr); //get the length of the string
	beginning = cstr;
	ending = cstr;

	for (b = 0; b < a - 1; b++)  // moving the ending part to the last character
		ending++;

	for (b = 0; b < a / 2; b++) { // swap the char from start and end // index using beginning and ending
		ch = *ending;
		*ending = *beginning;
		*beginning = ch;

		beginning++; //updates the pointer positions
		ending++;
	}
}

size_t words(const char* cstr)
{
	int count = 0;

	while (*cstr != '\0') {
		if (*cstr == ' ')
			count++;
	}
	return count;
}

size_t words2(const char* cstr)
{

}

char* concat(char* t, const char* s)
{

}

int main()
{
   //Problem 1 Main
	int a[] = { 1,4,4,5,8 };
	int b[] = { 1,2,2,4,6,6,9 };
	constexpr size_t dima = std::size(a);
	constexpr size_t dimb = std::size(b);
	constexpr size_t dimc = dima + dimb;
	int c[dimc];

	merge(a, dima, b, dimb, c);

	printArr(a, dima, "a");
	printArr(b, dimb, "b");
	printArr(c, dimc, "c");

	//Problem 2 Main
	std::vector<int> a{ 2,-13,3,6,4,5,-14,1,-15 };
	auto r = smallSum3(a);

	std::printf("Sum=%d for elements " "a[%u]=%d, a[%u]=%d, a[%u]=%d\n",
		a[r[0]] + a[r[1]] + a[r[2]],
		r[0], a[r[0]], r[1], a[r[1]], r[2], a[r[2]]);

	//Problem 3 Main
	using std::cout; using std::endl;
	char s1[] = "Alice in Wonderland";
	cout << "reverse: " << reverse(s1) << endl;
	cout << "length : " << length(s1) << endl;

	char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
	cout << "words  : " << words(s2) << endl;
	cout << "words2 : " << words2(s2) << endl;

	char s3[100] = "Hello";
	cout << "concat : "
		<< concat(concat(s3, ", world"), "!") << endl;
}
