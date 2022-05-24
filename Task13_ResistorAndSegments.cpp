#include <iostream>;
#include <utility>;
using namespace std;

//Problem1
class Resistor {
private:
	double resistance;
public:
	Resistor() {
		resistance = 0;
	}

	Resistor(int r) {
		this->resistance = r;
	}

	double r() const {
		return resistance;
	}

	void r(double r) {
		resistance = r;
	}
};

ostream& operator<< (ostream& str, const Resistor& r)
{
	return str << r.r();
};

Resistor operator+ (const Resistor& r1, const Resistor& r2)
{
	return Resistor(r1.r() + r2.r());
};

Resistor operator* (const Resistor& r1, const Resistor& r2)
{
	return Resistor((r1.r() * r2.r()) / (r1.r() + r2.r()));
};

//=====================================================================================

//Problem2
class Segment {
	double A, B;

public:
	Segment(double A, double B) : A(A), B(B) {}

	double getA() const
	{
		return A;
	}

	double getB() const
	{
		return B;
	}

	Segment operator*(double d) const
	{
		return Segment(A * d, B * d);
	}

	Segment operator/(double d) const
	{
		return Segment(A / d, B / d);
	}

	Segment operator+(double d) const
	{
		return Segment(A + d, B + d);
	}

	Segment operator-(double d) const
	{
		return Segment(A - d, B - d);
	}

	bool operator()(double d) const
	{
		return A <= d && d <= B;
	}
};

Segment operator*(double d, const Segment& seg)
{
	return seg * d;
}

Segment operator+(double d, const Segment& seg)
{
	return seg + d;
}

Segment operator+(const Segment& seg1, const Segment& seg2)
{
	return Segment(std::min(seg1.getA(), seg2.getA()), std::max(seg1.getB(), seg2.getB()));
}

std::ostream& operator<<(std::ostream& str, const Segment& seg)
{
	return str << "[" << seg.getA() << "," << seg.getB() << "]";
}

int main()
{
	//Problem1 Main
	Resistor r1, r2{ 6 };
	r1.r(3);
	std::cout << (r1 + r2) << " " << (r1 * r2) << std::endl;

	cout << "======================================================\n";

	//Problem2 Main
	using std::cout; using std::endl;
	Segment seg{ 2,3 }, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;

	cout << s << endl << std::boolalpha;
	for (double x = 0.5; x < 4; x += 1)
		cout << "x=" << x << ": " << s(x) << endl;
}

