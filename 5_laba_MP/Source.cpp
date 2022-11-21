#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<iomanip>
#include<fstream>
#include<cctype>
#define EOL '\n'
#define buffer numeric_limits<streamsize>::max(), '\n'
using namespace std;

class date {

	int y;
	int m;
	int d;
	string e;

	bool check_v(int y)
	{
		bool v;
		if ((!(y % 4) && (y % 100)) || (!(y % 400))) v = true;
		else v = false;
		return v;
	}

public:

	date() {}

	date(int year, int month, int day, string event) :y(year), m(month), d(day), e(event) {}

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
	friend ofstream& operator << (ofstream& out, date& ref);
	date operator- (date ref) {
		int post_y;
		int post_m;
		int post_d;
		//y >= ref.y
		if (y > ref.y) {
			post_y = y - ref.y;

			if (m > ref.m) {
				post_m = m - ref.m;
				if (d > ref.d) { post_d = d - ref.d; }
				else {
					if (check_v(ref.y)) { // visocosnyy god (y >= ref.y; m >= ref.m
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
						{
							post_d = 31 - ref.d + d;
						}
						else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
							post_d = 30 - ref.d - d;
						}
						else { post_d = 29 - ref.d + d; }
					}

					else {
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
						{
							post_d = 31 - ref.d + d;
						}
						else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
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
		// esli ref.y > y
		else {
			post_y = ref.y - y;
			if (ref.m > m) {
				post_m = ref.m - m;
				if (ref.d >= d) { post_d = ref.d - d; }
				else {
					if (check_v(y)) {
						if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
						{
							post_d = 31 + ref.d - d;
						}
						else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 29 + ref.d - d; }
					}

					else {
						if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
						{
							post_d = 31 + ref.d - d;
						}
						else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 28 + ref.d - d; }
					}
					post_m--;
				}
			}
			else {
				post_m = 12 - m + ref.m; post_y--;
				if (d <= ref.d) { post_d = ref.d - d; }
				else {
					if (check_v(y)) {
						if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
						{
							post_d = 31 + ref.d - d;
						}
						else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
							post_d = 30 + ref.d - d;
						}
						else { post_d = 29 + ref.d - d; }
					}

					else {
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
						{
							post_d = 31 + ref.d - d;
						}
						else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
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
};
class Event {
	date d1, d2;
	string e1, e2;


public:

	Event()
	{
		e1 = e2 = " ";
	}

	Event(date da, string ev, date dat, string eve) {
		d1 = da;
		e1 = ev;
		d2 = dat;
		e2 = eve;
	}

	Event(const Event& ref) : d1(ref.d1), e1(ref.e1), d2(ref.d2), e2(ref.e2) {}
	~Event() {}

	void SetD1(date D1) { d1 = D1; }
	void SetE1(string E1) { e1 = E1; }
	void SetD2(date D2) { d2 = D2; }
	void SetE2(string E2) { e2 = E2; }

	date GetD1() { return d1; }
	string GetE1() { return e1; }
	date GetD2() { return d2; }
	string Get2() { return e2; }

	date difference(Event& ref)
	{
		date d;
		if ((ref.e1 != " ") && (ref.e2 != " ")) {
			d = ref.d1 - ref.d2;
		}
		return d;
	}
	friend ostream& operator << (ostream&, Event& ref);
	friend istream& operator >> (istream&, Event& ref);
	friend ofstream& operator << (ofstream&, Event& ref);
	friend ifstream& operator >> (ifstream&, Event& ref);
};
ostream& operator << (ostream& out, Event& ref) {
	out << ref.e1 << " -> " << ref.d1 << endl;
	out << ref.e2 << " -> " << ref.d2 << endl;
	return out;
}
ofstream& operator << (ofstream& out, Event& ref) {
	out << ref.e1 << " -> " << ref.d1 << endl;
	out << ref.e2 << " -> " << ref.d2 << endl;
	return out;
}
ofstream& operator << (ofstream& out, date& ref) {
	out << ref.d << " days " << ref.m << " monthes " << ref.y << " years " << endl;
	return out;
}
ostream& operator << (ostream& out, date& ref) {
	out << ref.d << " days " << ref.m << " monthes " << ref.y << " years " << endl;	return out;
}
istream& operator>> (istream& in, Event& ref) {     //Перегрузка оператора ввода с консоли
	string s1, s2;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;            //Счетчики проверок
	while ((k1 != ref.e1.length()) || (k2 != ref.e2.length()) || (k3 != 10) || (k4 != 10)) {
		in >> ref.e1 >> s1 >> ref.e2 >> s2;            //Считываем все данные в строки
		while (in.peek() != '\n') {      //Если после считывания еще что-то есть в строке
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR" << endl;                     //Пишем ошибку
			in >> ref.e1 >> s1 >> ref.e2 >> s2;        //Считываем еще раз
		}
		k1 = 0;
		k2 = 0;
		k3 = 0;
		k4 = 0;
		for (int i = 0; i < ref.e1.length(); i++) {   //Цикл на проверку города отправления
			if ((ref.e1[i] <= '0') || (ref.e1[i] >= '9')) { //Если символ не цифра
				k1++;
			}
		}
		for (int i = 0; i < ref.e2.length(); i++) {   //Цикл на проверку города прибытия
			if ((ref.e2[i] <= '0') || (ref.e2[i] >= '9')) {
				k2++;
			}
		}
		if (s1.length() == 10) {                    //Если длина не 5, точно неверный ввод
			for (int i = 0; i < s1.length(); i++) { //Цикл на проверку времени отправления
				if (((s1[i] >= '0') && (s1[i] <= '9')) || ((s1[i] == '.') && ((i == 4) || (i == 7)))) {
					k3++;
				}
			}
			if (((int(s1[5] - '0') * 10 + int(s1[6] - '0')) > 12)) { k3--; } // Month
			else {
				int year_check = int(s1[0] - '0') * 1000 + int(s1[1] - '0') * 100 + int(s1[2] - '0') * 10 + int(s1[3] - '0');
				bool v;
				if ((!(year_check % 4) && (year_check % 100)) || (!(year_check % 400))) v = true; // year
				else v = false;
				int month_check = int(s1[5] - '0') * 10 + int(s1[6] - '0'); // кол-во месяцев
				int day_check = int(s1[8] - '0') * 10 + int(s1[9] - '0'); // кол-во дней
				if (v) { // високосный
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k3--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k3--;
					}

					else if ((month_check == 2) && (day_check > 29)) { k3--; }
				}
				else {
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k3--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k3--;
					}

					else if ((month_check == 2) && (day_check > 28)) { k3--; }
				}
			}
		}
		if (s2.length() == 10) {
			for (int i = 0; i < s2.length(); i++) {
				if (((s2[i] >= '0') && (s2[i] <= '9')) || ((s2[i] == '.') && ((i == 4) || (i == 7)))) {
					k4++;
				}
			}
				if (((int(s2[5] - '0') * 10 + int(s2[6] - '0')) > 12)) { k4--; } // Month
				else {
					int year_check = int(s2[0] - '0') * 1000 + int(s2[1] - '0') * 100 + int(s2[2] - '0') * 10 + int(s2[3] - '0');
					bool v;
					if ((!(year_check % 4) && (year_check % 100)) || (!(year_check % 400))) v = true; // year
					else v = false;
					int month_check = int(s2[5] - '0') * 10 + int(s2[6] - '0'); // кол-во месяцев
					int day_check = int(s2[8] - '0') * 10 + int(s2[9] - '0'); // кол-во дней
					if (v) { // високосный
						if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
							|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
							k4--;
						}
						else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
							&& day_check > 30) {
							k4--;
						}

						else if ((month_check == 2) && (day_check > 29)) { k4--; }
					}
					else {
						if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
							|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
							k4--;
						}
						else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
							&& day_check > 30) {
							k4--;
						}
						else if ((month_check == 2) && (day_check > 28)) { k4--; }
					}
				}
			
		}
		if ((k1 != ref.e1.length()) || (k2 != ref.e2.length()) || (k3 != 10) || (k4 != 10)) { //Если условия не выполнены
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR - reput again:" << endl;                               //Сообщаем об ошибке
		}
	}
	ref.d1.year(int(s1[0] - '0') * 1000 + int(s1[1] - '0') * 100 + int(s1[2] - '0') * 10 + int(s1[3] - '0')); //Устанавливаем через аски код все времена
	ref.d1.month(int(s1[5] - '0') * 10 + int(s1[6] - '0'));
	ref.d1.day(int(s1[8] - '0') * 10 + int(s1[9] - '0'));
	ref.d2.year(int(s2[0] - '0') * 1000 + int(s2[1] - '0') * 100 + int(s2[2] - '0') * 10 + int(s2[3] - '0'));
	ref.d2.month(int(s2[5] - '0') * 10 + int(s2[6] - '0'));
	ref.d2.day(int(s2[8] - '0') * 10 + int(s2[9] - '0'));
	return in; //Возвращаем поток

}
ifstream& operator>> (ifstream& in, Event& ref) {     //Перегрузка оператора ввода с консоли
	string s1, s2;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;            //Счетчики проверок
	while (!(in.eof()) && (k1 != ref.e1.length()) || (k2 != ref.e2.length()) || (k3 != 5) || (k4 != 5)) {
		in >> ref.e1 >> s1 >> ref.e2 >> s2;            //Считываем все данные в строки
		k1 = 0;
		k2 = 0;
		k3 = 0;
		k4 = 0;
		for (int i = 0; i < ref.e1.length(); i++) {   //Цикл на проверку города отправления
			if ((ref.e1[i] <= '0') || (ref.e1[i] >= '9')) { //Если символ не цифра
				k1++;
			}
		}
		for (int i = 0; i < ref.e2.length(); i++) {   //Цикл на проверку города прибытия
			if ((ref.e2[i] <= '0') || (ref.e2[i] >= '9')) {
				k2++;
			}
		}
		if (s1.length() == 10) {                    //Если длина не 5, точно неверный ввод
			for (int i = 0; i < s1.length(); i++) { //Цикл на проверку времени отправления
				if (((s1[i] >= '0') && (s1[i] <= '9')) || ((s1[i] == '.') && ((i == 4) || (i == 7)))) {
					k3++;
				}
			}
			if (((int(s1[5] - '0') * 10 + int(s1[6] - '0')) > 12)) { k3--; } // Month
			else {
				int year_check = int(s1[0] - '0') * 1000 + int(s1[1] - '0') * 100 + int(s1[2] - '0') * 10 + int(s1[3] - '0');
				bool v;
				if ((!(year_check % 4) && (year_check % 100)) || (!(year_check % 400))) v = true; // year
				else v = false;
				int month_check = int(s1[5] - '0') * 10 + int(s1[6] - '0'); // кол-во месяцев
				int day_check = int(s1[8] - '0') * 10 + int(s1[9] - '0'); // кол-во дней
				if (v) { // високосный
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k3--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k3--;
					}

					else if ((month_check == 2) && (day_check > 29)) { k3--; }
				}
				else {
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k3--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k3--;
					}

					else if ((month_check == 2) && (day_check > 28)) { k3--; }
				}
			}
		}
		if (s2.length() == 10) {
			for (int i = 0; i < s2.length(); i++) {
				if (((s2[i] >= '0') && (s2[i] <= '9')) || ((s2[i] == '.') && ((i == 4) || (i == 7)))) {
					k4++;
				}
			}
			if (((int(s2[5] - '0') * 10 + int(s2[6] - '0')) > 12)) { k4--; } // Month
			else {
				int year_check = int(s2[0] - '0') * 1000 + int(s2[1] - '0') * 100 + int(s2[2] - '0') * 10 + int(s2[3] - '0');
				bool v;
				if ((!(year_check % 4) && (year_check % 100)) || (!(year_check % 400))) v = true; // year
				else v = false;
				int month_check = int(s2[5] - '0') * 10 + int(s2[6] - '0'); // кол-во месяцев
				int day_check = int(s2[8] - '0') * 10 + int(s2[9] - '0'); // кол-во дней
				if (v) { // високосный
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k4--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k4--;
					}

					else if ((month_check == 2) && (day_check > 29)) { k4--; }
				}
				else {
					if (((month_check == 1) || (month_check == 3) || (month_check == 5) || (month_check == 7)
						|| (month_check == 8) || (month_check == 10) || (month_check == 12)) && (day_check > 31)) {
						k4--;
					}
					else if (((month_check == 4) || (month_check == 6) || (month_check == 9) || (month_check == 11))
						&& day_check > 30) {
						k4--;
					}
					else if ((month_check == 2) && (day_check > 28)) { k4--; }
				}
			}
			if (!(in.eof()) && ((k1 != ref.e1.length()) || (k2 != ref.e2.length()) || (k3 != 10) || (k4 != 10))) { //Если условия не выполнены
				ref.e1 = ref.e2 = " ";
				cout << "ERROR" << endl;     //Сообщаем об ошибке
				in.ignore(buffer);
			}
		}
		if ((ref.e1 != " ") && (ref.e2 != " ")) {
			ref.d1.year(int(s1[0] - '0') * 1000 + int(s1[1] - '0') * 100 + int(s1[2] - '0') * 10 + int(s1[3] - '0')); //Устанавливаем через аски код все времена
			ref.d1.month(int(s1[5] - '0') * 10 + int(s1[6] - '0'));
			ref.d1.day(int(s1[8] - '0') * 10 + int(s1[9] - '0'));
			ref.d2.year(int(s2[0] - '0') * 1000 + int(s2[1] - '0') * 100 + int(s2[2] - '0') * 10 + int(s2[3] - '0'));
			ref.d2.month(int(s2[5] - '0') * 10 + int(s2[6] - '0'));
			ref.d2.day(int(s2[8] - '0') * 10 + int(s2[9] - '0'));
		}
		return in; //Возвращаем поток
	}
}

//___________________________________________________разделение______________________________________________________

bool check_amount_string(string input_string)
{
	if (input_string.empty())
		return false;
	bool dot_found = false;
	for (int i = 0; i < input_string.length(); i++)
	{
		char symbol = input_string[i];
		if (symbol == '.') return false;
		if (symbol == '-') return false;
		if (isdigit(symbol) == 0 && symbol != '.' && symbol != '-')
			return false;
		if (isspace(symbol) != 0)
			return false;
	}
	return true;
}

int entering_array_size() {
	string s;
	bool input = true;
	while (input) {
		getline(cin, s);
		input = !check_amount_string(s);
	}
	return stoi(s);
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

void users_guide()
{
	cout << "Now you will see a app for calculating difference in two dates" << endl << endl;
	cout << "If you'd like to enter dates from a text file - enter information by this way: " << endl;
	cout << "Event	year	month	day" << endl;
	cout << "(Example: \n birthday 2004.12.21  now 2022.01.21)" << endl;
	cout << "If you want to enter dates from console - you'll see guide later" << endl << endl;
}

bool entering_way()
{
	bool flag = true;
	char symbol;
	cout << "Enter the way you'd like to enter information" << endl;
	cout << "if you want to use console - press '1'" << endl;
	cout << "if you want to use file - press '2'" << endl;
	while (!(cin >> symbol) || flag) {
		cin.clear();
		if ((symbol == '2') && (cin.peek() == EOL)) {
			flag = false;
			return false;
		}
		else if ((symbol == '1') && (cin.peek() == EOL)) {
			flag = false;
			return true;
		}
		else {
			flag = true;
		}
		while (cin.get() != EOL);
		cout << "Enter 1 || 2: " << endl;
	}
}

date calc(Event& ref) {
	Event d;
	return d.difference(ref);
}

vector<Event> console_input() 
{
	cout << "Enter amount of elements in array" << endl;
	int amount = entering_array_size();
	vector<Event>vec;
	Event d;
	for (int i = 0; i < amount; i++) {
		cout << "Enter " << i + 1 << " element" << endl;
		cin >> d;
		vec.push_back(d);
	}
	return vec;
}

vector<date> console_result()
{
	vector<Event> vec = console_input();
	vector<date> res;
	date d;
	for (int i = 0; i < vec.size(); i++) {
		d = calc(vec[i]);
		res.push_back(d);
	}
	return res;
}

int check_file() 
{
	int a;
	while (!(cin >> a) || (cin.peek() != EOL) || (a != 1))
	{
		cin.clear();
		cout << "Incorrect input" << endl;
		cin.ignore(buffer);
		cout << "Retry input" << endl;
	}
	return a;
}

void getting_file() 
{
	cout << "Enter information into text file 'input.txt'" << endl;
	cout << "if you are ready press '1'" << endl;
	int a = check_file();
}

vector<Event> file_input()
{
	ifstream in("input.txt");
	vector<Event> vec;
	Event e;
	cout << "_______________________________________________________________" << endl;
	while (!(in.eof())) {
		in >> e;
		vec.push_back(e);
	}
	in.close();
	return vec;
}

vector<date> file_result()
{
	vector<Event> vec = file_input();
	vector<date> res;
	date d;
	cout << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		d = calc(vec[i]);
		res.push_back(d);
	}
	return res;
}

bool entering_output_way()
{
	bool flag = true;
	char symbol;
	cout << endl << "Choose the way you'd like to output information" << endl;
	cout << "If you want to see result in console - press '1'" << endl;
	cout << "If you want to see result in file - press '2'" << endl;
	while (!(cin >> symbol) || flag) {
		cin.clear();
		if ((symbol == '2') && (cin.peek() == EOL)) {
			flag = false;
			return false;
		}
		else if ((symbol == '1') && (cin.peek() == EOL)) {
			flag = false;
			return true;
		}
		else {
			flag = true;
		}
		while (cin.get() != EOL);
		cout << "Press 1 || 2 " << endl;
	}
}

void console_output(vector<date>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
}

void file_output(vector<date>& vec)
{
	ofstream out("output.txt", ios::app);
	for (int i = 0; i < vec.size(); i++)
	{
		out << vec[i];
	}
	out.close();
}

int main()
{
	users_guide();
	bool iteration = true;
	while (iteration) {
		vector<date> result;
		if (entering_way()) 
		{ 
			result = console_result();
			bool output = entering_output_way();
			if (output)
			{
				console_output(result);
			}
			else
			{
				file_output(result);
			}
		}
		else 
		{
			result = file_result();
			bool output = entering_output_way();
			if (output)
			{
				console_output(result);
			}
			else
			{
				file_output(result);
			}
		}
		result.clear();
		iteration = continue_check();
		system("cls");
	}
}
