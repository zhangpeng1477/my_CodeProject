#include <iostream>
using namespace std;

class Base{
public:
	Base(const int val=0);
	~Base();

public:
	void setival(const int val);

protected:
	int getival()const;

private:
	int ival;
};

Base::Base(const int val){
	ival = val;
	cout << "Base: normal------------\n";
}

Base::~Base(){
	cout << "Base: ~  ------------\n";
}

void Base::setival(const int val)
{
	ival = val;
}

int Base::getival()const
{
	return ival;
}

/////////////////////////////////////////////////////////////

class subcls : private Base{
public:
	subcls(const int val, const char ch);
	~subcls();

	void setcval(const char val);
	char getcval()const;

private:
	char ch;
};

subcls::subcls(const int val, const char ch):
	Base(val)
{
	setival(val);

	this->ch = ch;
	cout << "subcls: normal------------\n";
}

subcls::~subcls()
{
	cout << "subcls: ~   ------------\n";
}

void subcls::setcval(const char val)
{
	setival(456);
	ch = val;
}

char subcls::getcval()const
{
	cout << "ival = " <<  getival() << endl;

	return ch;
}

int main()
{
	subcls a(123, 'a');

	a.setcval('c');

	//a.setival(456);
	//cout << "ival = " << a.getival() << endl;
	cout << "ch = " << a.getcval() << endl;
	

}


