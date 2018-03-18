#include <iostream>
#include <iomanip>
using namespace std;
class Distance
{
	private:
		int feet;
		int inches;
	public:
		Distance(){
			feet = 0;
			inches = 0;
		}
		Distance(int f, int i){
			cout << "Constructor" << endl;
			feet = f;
			inches = i;
		}
		Distance operator+(int);
		Distance operator-(Distance);
		Distance operator=(Distance);
		Distance operator++();
		Distance operator++(int);
		bool operator==(Distance);
		Distance operator()(int, int);
		friend Distance operator+(Distance, Distance);
		friend ostream& operator<<( ostream&, const Distance& );
		friend istream& operator>>( istream&, Distance& );
};
Distance operator+(Distance d1,Distance d2)
{
	cout << "Calling Friend Function" << endl;
    Distance d3;
    d3.inches = d1.inches + d2.inches;
    d3.feet = d1.feet + d2.feet;
    if(d3.inches >= 12)
        d3.feet++;
    d3.inches = d3.inches % 12;
    return d3;
}
Distance Distance :: operator+(int d)
{
    Distance d3;
    d3.feet = feet + d;
    d3.inches = inches;
    return d3;
}
Distance Distance :: operator-(Distance d2)
{
    int iLen1, iLen2;
    iLen1 = feet * 12 + inches;
    iLen2 = d2.feet * 12 + d2.inches;
    if(iLen1 < iLen2)
    {
        cout << "Wrong Input" << endl;
    }
    else
    {
        Distance d3;
        d3.inches = (iLen1-iLen2)%12;
        d3.feet = (iLen1-iLen2)/12;
        return d3;
    }
}
Distance Distance :: operator=(Distance d2)
{
    inches = d2.inches;
    feet = d2.feet;
    return *this;
}

bool Distance :: operator==(Distance d2)
{
    if(inches == d2.inches && feet == d2.feet)
        return true;
    return false;
}
Distance Distance :: operator++()
{
	feet++;
	return *this;
}
Distance Distance :: operator++(int dummy)
{
	feet++;
	return *this;
}
ostream& operator<<(ostream &output, const Distance &D)
{
    output << "F : " << setw(2) << D.feet << " --- " << "I : " << setw(2) << D.inches;
    return output;		//chaining
}
istream& operator>>(istream &input, Distance &D)
{
    input >> D.feet >> D.inches;
    return input;
}

int main()
{
	Distance D1(11, 6), D2, D3, D4, D5;
	cout << "First Distance :\t" << D1 << endl;
	cout << "Enter the value of Second Distance object : " ;
	cin >> D2;
	D3 = D1 + D2;
	D4 = D1 - D2;
	cout << "First Distance :\t" << D1 << endl;
	cout << "Second Distance :\t" << D2 << endl;
	cout << "Sum Distance :\t\t" << D3 << endl;
	cout << "Diffference : \t\t" << D4 << endl;
	cout << "First Distance :\t" << D1 << endl;
	++D1;
	cout << "Updated First Distance :\t" << D1 << endl;
	D1++;
	cout << "Updated First Distance :\t" << D1 << endl;
	return 0;
}

