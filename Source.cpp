#include <iostream>
using namespace std;

class Time
{
private:
	int* P;

public:
	int gethours() { return P[0]; }
	int getminutes() { return P[1]; }
	int getseconds() { return P[2]; }

	void sethours(int* P) { P[0] = this -> P[0]; }
	void setminutes(int* P) { P[1] = this -> P[1]; }
	void setseconds(int* P) { P[2] = this -> P[2]; }

	Time(int valuehours, int valueminutes, int valueseconds)
	{
		P = new int[3];
		P[0] = valuehours;
		P[1] = valueminutes;
		P[2] = valueseconds;
	}

	~Time() 
	{
		delete[]P;
	}

	void gettime(int valuehours, int valueminutes, int valueseconds)
	{
		if (valuehours < 10) { cout << "0" << valuehours << ":"; }
		else { cout << valuehours << ":"; }
		if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
		else { cout << valueminutes << ":"; }
		if (valueseconds < 10) { cout << "0" << valueseconds << "|"; }
		else { cout << valueseconds << "|"; }

		if (valuehours <= 12)
		{
			if (valuehours < 10) { cout << "0" << valuehours << ":"; }
			else { cout << valuehours << ":"; }
			if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
			else { cout << valueminutes << ":"; }
			if (valueseconds < 10) { cout << "0" << valueseconds << "AM"; }
			else { cout << valueseconds << "AM"; }
		}
		else
		{
			if (valuehours < 10) { cout << "0" << valuehours << ":"; }
			else { cout << valuehours << ":"; }
			if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
			else { cout << valueminutes << ":"; }
			if (valueseconds < 10) { cout << "0" << valueseconds << "PM"; }
			else { cout << valueseconds << "PM"; }
		}
	}

	void increasedtime(int valuehours, int valueminutes, int valueseconds)
	{
		if (valueseconds == 59)
		{
			valueseconds = 00;
			valueminutes++;
		}
		else { valueseconds++; }

		if (valueminutes == 59)
		{
			valueminutes = 00;
			valuehours++;
		}
		else if (valueminutes == 60)
		{
			valueminutes = 01;
			valuehours++;
		}
		else { valueminutes++; }

		if (valuehours == 23)
		{
			valuehours = 00;
		}
		else if (valuehours == 60)
		{
			valuehours = 01;
		}
		else { valuehours++; }
		if (valuehours == 25)
		{
			valuehours = 01;
		}

		gettime(valuehours, valueminutes, valueseconds);
	}
};

int main()
{
	system("chcp 1251");
	int valuehours, valueminutes, valueseconds;
	cout << "Введіть годину -> ";
	cin >> valuehours;
	if (valuehours > 23)
	{
		cout << "Не вірні дані";
		return 0;
	}
	cout << "Введіть хвилину -> ";
	cin >> valueminutes;
	if (valueminutes > 59)
	{
		cout << "Не вірні дані";
		return 0;
	}
	cout << "Введіть секунду -> ";
	cin >> valueseconds;
	if (valueseconds > 59)
	{
		cout << "Не вірні дані";
		return 0;
	}

	Time time1(valuehours, valueminutes, valueseconds);

	cout << "Введений час : ";
	time1.gettime(valuehours, valueminutes, valueseconds);
	cout << "\nЗбільшений на одну годину, хвилину та секунду введений час : ";
	time1.increasedtime(valuehours, valueminutes, valueseconds);


	return 0;
}
