// подключение библиотек
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#define EOL '\n'
#define buffer numeric_limits<streamsize>::max(), '\n'
using namespace std;

// класс дат
class date {

	int y; // поля класса
	int m;
	int d;
	bool check_v(int y) // проверка на високосность года
	{
		bool v;
		if ((!(y % 4) && (y % 100)) || (!(y % 400))) v = true;
		else v = false;
		return v;
	}

public:

	date() {} // конструктор по умолчанию

	date(int year, int month, int day) :y(year), m(month), d(day) {} // конструктор

	date(const date& ref) : d(ref.d), m(ref.m), y(ref.y) {} // конструктор копирования

	// сеттеры и геттеры
	int Getyear() const { return y; }
	int Getmonth() const { return m; }
	int Getday() const { return d; }
	void year(int year) { y = year; }
	void day(int day) { d = day; }
	void month(int month) { m = month; }

	friend ostream& operator << (ostream& out, date& ref);
	friend ofstream& operator << (ofstream& out, date& ref);
	friend istream& operator >> (istream& in, date& ref);
	date operator- (date ref) {
		int post_y;
		int post_m;
		int post_d;
		//y >= ref.y
		if (y > ref.y) {
			post_y = y - ref.y;

			if (m > ref.m) { // если месяц растёт
				post_m = m - ref.m;
				if (d > ref.d) { post_d = d - ref.d; }
				else {
					if (check_v(ref.y)) { // visocosnyy god (y >= ref.y; m >= ref.m)
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
						{
							post_d = 31 - ref.d + d;
						}
						else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
							post_d = 30 - ref.d - d;
						}
						else { post_d = 29 - ref.d + d; }
					}

					else { // кол-во днеё в зависимости от месяца и года
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
						{
							post_d = 31 - ref.d + d;
						}
						else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
							post_d = 30 - ref.d + d;
						}
						else { post_d = 28 - ref.d + d; }
					}
					post_m--;
				}
			}
			else {
				post_m = 12 - ref.m + m; post_y--; // если месяцев не хватает
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
		else if (ref.y > y) {
			post_y = ref.y - y;
			if (ref.m >= m) {
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
						if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) ||	(ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
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
		else {
		post_y = 0;
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
		else if (m > ref.m) {
			post_m = m - ref.m;
			if (d >= ref.d) { post_d = ref.d - d; }
			else  {
				if (check_v(y)) {
					if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
					{
						post_d = 31 - ref.d + d;
					}
					else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
						post_d = 30 - ref.d + d;
					}
					else { post_d = 29 - ref.d + d; }
				}
				else {
					if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
					{
						post_d = 31 - ref.d + d;
					}
					else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11)) {
						post_d = 30 - ref.d + d;
					}
					else { post_d = 28 - ref.d + d; }
				}
				post_m--;
			}
		}
		else {
			post_m = 0;
			if (ref.d > d) { post_d = ref.d - d; }
			else { post_d = d - ref.d; }
		}
		}
		date difference(post_y, post_m, post_d); // возврат конечного значения
		return difference;
	}
};
// класс событий
class Event {
	date d1, d2; // поля класса
	string e1, e2;

public:

	Event(){} // конструктор по умолчанию
	Event(date da, string ev, date dat, string eve) : d1(da), e1(ev), d2(dat), e2(eve) {} // конструктор

	Event(const Event& ref) : d1(ref.d1), e1(ref.e1), d2(ref.d2), e2(ref.e2) {} // конструктор
	~Event() {} // деструктор
	// сеттеры и геттеры
	void SetD1(date D1) { d1 = D1; }
	void SetE1(string E1) { e1 = E1; }
	void SetD2(date D2) { d2 = D2; }
	void SetE2(string E2) { e2 = E2; }
	date GetD1() { return d1; }
	string GetE1() { return e1; }
	date GetD2() { return d2; }
	string Get2() { return e2; }
	// метод класса
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
	return out; // возвращаем поток
}
ofstream& operator << (ofstream& out, Event& ref) {
	out << ref.e1 << ' ' << ref.d1 << ' ' << ref.e2 << ' ' << ref.d2;
	return out;
}
ofstream& operator << (ofstream& out, date& ref) {
	out << ref.y << '.' << ref.m << '.' << ref.d << ' ';
	return out;
}
ostream& operator << (ostream& out, date& ref) {
	out << ref.d << '.' << ref.m << '.' << ref.y ;	return out;
}
istream& operator>> (istream& in, Event& ref) {    
	cout << "Enter first data: " << endl;
	in >> ref.e1 >> ref.d1;
	cout << "Enter second data: " << endl;
	in >> ref.e2 >> ref.d2;
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
		for (int i = 0; i < ref.e1.length(); i++) {   //Цикл на проверку события
			if ((ref.e1[i] <= '0') || (ref.e1[i] >= '9')) { //Если символ не цифра
				k1++;
			}
		}
		for (int i = 0; i < ref.e2.length(); i++) {   //Цикл на проверку 2 события
			if ((ref.e2[i] <= '0') || (ref.e2[i] >= '9')) {
				k2++;
			}
		}
		if (s1.length() == 10) {                    //Если длина не 10, точно неверный ввод (диапазон лет от 0000 до 9999)
			for (int i = 0; i < s1.length(); i++) { //Цикл на проверку дату
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
				if (v) { // високосный // проверка по дням в месяцах и годах
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
		if (s2.length() == 10) { // тот же механизм
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
				if (v) { // проверка по кол-ву дней в месяце в n-ом году
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
			ref.d1.year(int(s1[0] - '0') * 1000 + int(s1[1] - '0') * 100 + int(s1[2] - '0') * 10 + int(s1[3] - '0')); // возвращаем значение даты в с помощью сеттеров и преобразования типов
			ref.d1.month(int(s1[5] - '0') * 10 + int(s1[6] - '0'));
			ref.d1.day(int(s1[8] - '0') * 10 + int(s1[9] - '0'));
			ref.d2.year(int(s2[0] - '0') * 1000 + int(s2[1] - '0') * 100 + int(s2[2] - '0') * 10 + int(s2[3] - '0'));
			ref.d2.month(int(s2[5] - '0') * 10 + int(s2[6] - '0'));
			ref.d2.day(int(s2[8] - '0') * 10 + int(s2[9] - '0'));
		}
		return in; //Возвращаем поток
	}
}
istream& operator >> (istream& in, date& ref) {
	cout << "Enter year" << endl;
	while (!(in >> ref.y) || (in.peek() != EOL) || (ref.y < 0)) // простая проверка на дату
	{
		in.clear(); // сброс флага ошибки
		in.ignore(buffer); // очистка буфера
		cout << "Incorrect date format!" << endl; // вывод сообщения
	}
	bool v;
	if ((!(ref.y % 4) && (ref.y % 100)) || (!(ref.y % 400))) v = true; // проверка на високосность года
	else v = false;
	cout << "Enter month" << endl;
	while (!(in >> ref.m) || (in.peek() != EOL) || (ref.m < 1) || (ref.m > 12)) // тот же механизм
	{
		in.clear();
		in.ignore(buffer);
		cout << "Incorrect date format!" << endl;
	}
	cout << "Enter day" << endl;
	{
		if ((ref.m == 1) || (ref.m == 3) || (ref.m == 5) || (ref.m == 7) || (ref.m == 8) || (ref.m == 10) || (ref.m == 12))
		{
			while (!(in >> ref.d) || (in.peek() != EOL) || (ref.d < 1) || (ref.d > 31))
			{
				in.clear();
				in.ignore(buffer);
				cout << "Incorrect date format!" << endl;
			}
		}
		else if ((ref.m == 4) || (ref.m == 6) || (ref.m == 9) || (ref.m == 11))
		{
			while (!(in >> ref.d) || (in.peek() != EOL) || (ref.d < 1) || (ref.d > 30))
			{
				in.clear();
				in.ignore(buffer);
				cout << "Incorrect date format!" << endl;
			}
		}
		else
		{
			if (v) {
				while (!(in >> ref.d) || (in.peek() != EOL) || (ref.d < 1) || (ref.d > 29))
				{
					in.clear();
					in.ignore(buffer);
					cout << "Incorrect date format!" << endl;
				}
			}
			else if (!v) {
				while (!(in >> ref.d) || (in.peek() != EOL) || (ref.d < 1) || (ref.d > 28))
				{
					in.clear();
					in.ignore(buffer);
					cout << "Incorrect date format!" << endl;
				}
			}
		}
	}
	return in;
}

//___________________________________________________разделение______________________________________________________


int entering_array_size() {
	int a;
	while (!(cin >> a) || (cin.peek() != EOL) || (a < 0)) // стандартный механизм проверки ввода
	{
		cin.clear(); // сброс флага ошибки
		cin.ignore(buffer); // очистка буфера
		cout << "Incorrect input!" << endl; // вфвод сообщения об ошибке
	}
	return a;
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
			flag = false; // сброс цикла
			return false;
		}
		else if ((symbol == 'Q' || symbol == 'q') && (cin.peek() == EOL)) {
			flag = false; // сброс цикла
			return true;
		}
		else {
			flag = true; // продолжение цикла проверки
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
	// та же самая проверка что и в continue_check()
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
	//вызов метода класса
	Event d;
	return d.difference(ref);
}

vector<Event> console_input() 
{
	// запись в вектор типа класса Event (начальный вектор)
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

vector<date> console_result(vector<Event>& vec)
{
	//запись в вектор элементов типа date (результирующий вектор)
	vector<date> res;
	date d;
	for (int i = 0; i < vec.size(); i++) {
		d = calc(vec[i]);
		res.push_back(d);
	}
	return res;
}

vector<Event> file_input()
{
	// запись в вектор типа класса Event (начальный вектор)
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
	// запись в вектор типа класса date (результирующий вектор)
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
	// та же самая проверка что и в continue_check()
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

void console_output(vector<date>& res, vector<Event>& vec)
{
	// вывод в консоль элементы результирующего и исходного векторов
	for (int i = 0; i < res.size(); i++)
	{
		cout << vec[i];
		cout << res[i] << endl;
	}
}

void file_output(vector<date>& res, vector<Event>& vec)
{
	// вывод в файл элементы результирующего и исходного векторов
	ofstream out("output.txt", ios::app);
	for (int i = 0; i < res.size(); i++)
	{
		out << vec[i] << endl;
		out << res[i] << endl;
	}
	out.close();
}

int main()
{
	users_guide();
	bool iteration = true;
	while (iteration) {
		vector<Event> input;
		vector<date> result;
		if (entering_way())
		{
			input = console_input();
			result = console_result(input);
			bool output = entering_output_way();
			if (output)
			{
				console_output(result, input);
			}
			else
				file_output(result, input);
		}
		else
		{
			input = file_input();
			result = file_result();
			bool output = entering_output_way();
			if (output)
			{
				console_output(result, input);
			}
			else
				file_output(result, input);
		}
		result.clear();
		iteration = continue_check();
		system("cls");
	}
}
