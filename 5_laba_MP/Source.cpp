#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<iomanip>
#define EOL '\n'
using namespace std;

class date {
public:

	date(){}

	date(int year, int month, int day) :y(year), m(month), d(day) {}

	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }

	void year(int year)
	{
		y = year;
	}
	void day(int day)
	{
		d = day;
	}
	void month(int month)
	{
		m = month;
	}

	friend ostream& operator << (ostream& out, date& ref);
	friend istream& operator >> (istream& in, date& ref);

	date operator- (date ref) {
		int days;
		int post_y;
		int post_m;
		int post_d;

		if (y >= ref.y) {
			post_y = y - ref.y;
			if (m >= ref.m) {
				post_m = m - ref.m;
				if (d >= ref.d) { post_d = d - ref.d; }
				else { 
					if (check_v(ref.y)) {
						if (ref.m == 1 || ref.m == 3 || ref.m == 5 || ref.m == 7 || ref.m == 8 || ref.m == 10 || ref.m == 12)
						{
							post_d = 31 - ref.d + d;
						}
						else if (ref.m == 4 || ref.m == 6 || ref.m == 9 || ref.m == 11) {
							post_d = 30 - ref.d - d;
						}
						else { post_d = 29 - ref.d + d; }
					}

					else {
						if (ref.m == 1 || ref.m == 3 || ref.m == 5 || ref.m == 7 || ref.m == 8 || ref.m == 10 || ref.m == 12)
						{
							post_d = 31 - ref.d + d;
						}
						else if (ref.m == 4 || ref.m == 6 || ref.m == 9 || ref.m == 11) {
							post_d = 30 - ref.d - d;
						}
						else { post_d = 28 - ref.d + d; }
					}
					post_m--; 

				}
			}
			else {
				post_m = 12 - ref.m + m; post_y--;
				if (d >= ref.d) { post_d = d - ref.d; }
				else {
					if (check_v(ref.y)) {
						if (ref.m == 1 || ref.m == 3 || ref.m == 5 || ref.m == 7 || ref.m == 8 || ref.m == 10 || ref.m == 12)
						{
							post_d = 31 - ref.d + d;
						}
						else if (ref.m == 4 || ref.m == 6 || ref.m == 9 || ref.m == 11) {
							post_d = 30 - ref.d - d;
						}
						else { post_d = 29 - ref.d + d; }
					}

					else {
						if (ref.m == 1 || ref.m == 3 || ref.m == 5 || ref.m == 7 || ref.m == 8 || ref.m == 10 || ref.m == 12)
						{
							post_d = 31 - ref.d + d;
						}
						else if (ref.m == 4 || ref.m == 6 || ref.m == 9 || ref.m == 11) {
							post_d = 30 - ref.d + d;
						}
						else { post_d = 28 - ref.d + d; }
					}
					post_m--;

				}
			}
		}
		else {
			post_y = ref.y - y;
			if (ref.m >= m) {
				post_m = ref.m - m;
				if (ref.d >= d) { post_d = ref.d - d; }
				else { 
					if (check_v(y)) {
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							post_d = 31 + ref.d - d;
						}
						else if (m == 4 || m == 6 || m == 9 || m == 11) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 29 + ref.d - d; }
					}

					else {
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							post_d = 31 + ref.d - d;
						}
						else if (m == 4 || m == 6 || m == 9 || m == 11) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 28 + ref.d - d; }
					}
					post_m--;
				}
			}
			else {
				post_m = 12 - m + ref.m; post_y--;
				if (d < ref.d) { post_d = ref.d - d; }
				else {
					if (check_v(y)) {
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							post_d = 31 + ref.d - d;
						}
						else if (m == 4 || m == 6 || m == 9 || m == 11) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 29 + ref.d - d; }
					}

					else {
						if (ref.m == 1 || ref.m == 3 || ref.m == 5 || ref.m == 7 || ref.m == 8 || ref.m == 10 || ref.m == 12)
						{
							post_d = 31 + ref.d - d;
						}
						else if (ref.m == 4 || ref.m == 6 || ref.m == 9 || ref.m == 11) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 28 + ref.d - d; }
					}
					post_m--;

				}
			}
		}
		date difference(post_y, post_m, post_d);
		return difference;
		}

	date dif(date ref1, date ref2)
	{
		date d;
		d = ref1 - ref2;
		return d;
	}

private:
	int y;
	int m;
	int d;

	bool check_v(int y)
	{
		bool v;
		if ((!(y % 4) && (y % 100)) || (!(y % 400))) v = true;
		else v = false;
		return v;
	}
};
ostream& operator << (ostream& out, date& ref) {
	out << "Difference in dates is: " << endl;
	out << ref.d << '\t' << "days" << endl;
	out << ref.m << '\t' << "monthes" << endl;
	out << ref.y << '\t' << "years" << endl;
	return out;
}
istream& operator >> (istream& in, date& ref) {
	cout << "Enter year" << endl;
	in >> ref.y;
	if (ref.y < 0) {
		cout << "Incorrect year" << endl;
		while (ref.y < 0) 
		{
			in >> ref.y;
		}
	}
	bool v;
	if ((!(ref.y % 4) && (ref.y % 100)) || (!(ref.y % 400))) v = true;
	else v = false;
	cout << "Enter month" << endl;
	in >> ref.m;
	while (ref.m > 12 || ref.m < 1)
	{
			in >> ref.m;
	}
	cout << "Enter day" << endl;
	in >> ref.d;
	{
		if (ref.m == 3)
		{
			if (ref.d < 1 || ref.d > 31)
			cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 5)
		{
			if (ref.d < 1 || ref.d > 31)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 7)
		{
			if (ref.d < 1 || ref.d > 31)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 8)
		{
			if (ref.d < 1 || ref.d > 31)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 10)
		{
			if (ref.d < 1 || ref.d > 31)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 12)
		{
			if (ref.d < 1 || ref.d > 31)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 31) in >> ref.d;
		}
		else if (ref.m == 4)
		{
			if (ref.d < 1 || ref.d > 30)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 30) in >> ref.d;
		}
		else if (ref.m == 6)
		{
			if (ref.d < 1 || ref.d > 30)
			cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 30) in >> ref.d;
		}
		else if (ref.m == 9)
		{
			if (ref.d < 1 || ref.d > 30)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 30) in >> ref.d;
		}
		else if (ref.m == 11)
		{
			if (ref.d < 1 || ref.d > 30)
				cout << "Incorrect input" << endl;
			while (ref.d < 1 || ref.d > 30) in >> ref.d;
		}
		else 
		{
			if (v) {
				if (ref.d < 1 || ref.d > 29)
				cout << "Incorrect day" << endl;
				while (ref.d < 1 || ref.d > 29) in >> ref.d;
			}
			else if(!v) {
				if (ref.d < 1 || ref.d > 28)
				cout << "Incorrect input" << endl;
				while (ref.d < 1 || ref.d > 28) in >> ref.d;
			}
		}
	}
	return in;
}

bool continue_check()
{
	bool flag = true;
	char symbol;
	cout << endl << "Do you want to continue?" << endl;
	cout << "If you want - press q or Q" << endl;
	cout << "If you want to quit - press x or X" << endl;
	while (!(cin >> symbol) || flag) {
		cin.clear();
		if ((symbol == 'X' || symbol == 'x') && (cin.peek() == EOL)) {
			flag = false;
			return false;
		}
		else if ((symbol == 'Q' || symbol == 'q') && (cin.peek() == EOL)) {
			flag = false;
			return true;
		}
		else {
			flag = true;
		}
		while (cin.get() != EOL);
		cout << "Do you want to continue? --> Q / X / q / x" << endl;
	}
}

int main()
{
	bool iteration = true;
	while (iteration) {
		date d1;
		cin >> d1;
		system("cls");
		cout << "Enter second date" << endl << endl;
		date d2;
		cin >> d2;
		date res;
		date d_res = res.dif(d1, d2);
		system("cls");
		cout << d1.day() << '.' << d1.month() << '.' << d1.year() << endl;
		cout << d2.day() << '.' << d2.month() << '.' << d2.year() << endl;
		cout << d_res;
		iteration = continue_check();
		system("cls");
	}
}