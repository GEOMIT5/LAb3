#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int chooseFillArray();
int chooseMenu();

class Vector;
class Array;

class Array {
private:
	int** arr;
	int n, m;
public:
	Array() {
		n = 5; m = 5;
		arr = new int* [n];
		for (int i = 0; i < n; i++)
			arr[i] = new int[m];
	}
	Array(int ValueN, int ValueM) {
		n = ValueN; m = ValueM;
		arr = new int* [n];
		for (int i = 0; i < n; i++)
			arr[i] = new int[m];
	}
	Array(const Array& mas) {
		n = mas.n;
		m = mas.m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = mas.arr[i][j];
	}
	~Array() {
		for (int i = 0; i < n; i++)
			delete[]arr[i];
		delete[]arr;
	}
	void fillArray();
	void printArray();
	friend class Vector;
	Array& operator=(const Array& mass) {
		n = mass.n;
		m = mass.m;
		delete[]arr;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				arr[i][j] = mass.arr[i][j];
				cout << arr[i][j] << endl;
			}
		return *this;
	}
	friend Array& operator*(Array& arr1, Vector& vec1);
};

class Vector {
private:
	int* vec;
	int m;
public:
	Vector() {
		m = 5;
		vec = new int[m];
	}
	Vector(int ValueM) {
		m = ValueM;
		vec = new int[m];
	}
	Vector(const Vector& mas) {
		m = mas.m;
		for (int i = 0; i < m; i++)
			vec[i] = mas.vec[i];
	}
	~Vector() {
		delete[]vec;
	}
	friend class Array;
	void fillVector();
	void printVector();
	friend Array& operator*(Array& arr1, Vector& vec1);
};

Array& operator*(Array& arr1, Vector& vec1) {
	Array mas(arr1.n, arr1.m);
	for (int i = 0; i < arr1.n; i++)
		for (int j = 0; j < arr1.m; j++)
			mas.arr[i][j] = arr1.arr[i][j] * vec1.vec[j];
	mas.printArray();
	return mas;
}

void Array::printArray() {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Array::fillArray() {
	int choose = chooseFillArray();
	if (choose == 0) {
		system("cls");
		cout << "Ââåäèòå ëåâóþ ãðàíèöó äèàïîçîíà: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Ââåäèòå ïðàâóþ ãðàíèöó äèàïîçîíà: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Ââåäèòå ýëåìåíòû ìàññèâà: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " - ñòðîêà èç " << m << " ñèìâîëîâ: ";
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
	}
}

void Vector::printVector() {
	system("cls");
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
	system("pause");
	system("cls");
}

void Vector::fillVector() {
	int choose = chooseFillArray();
	if (choose == 0) {
		system("cls");
		cout << "Ââåäèòå ëåâóþ ãðàíèöó äèàïîçîíà: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Ââåäèòå ïðàâóþ ãðàíèöó äèàïîçîíà: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < m; i++)
			vec[i] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Ââåäèòå ýëåìåíòû ìàññèâà: " << endl;
		for (int i = 0; i < m; i++) {
			cin >> vec[i];
		}
	}
}

int main() {
	setlocale(0, "rus");
	int n, m;
	cout << "Ââåäèòå ðàçìåð ìàòðèöû ";
	cin >> n;
	cout << "Ââåäèòå âòîðîé ðàçìåð ìàòðèöû è ðàçìåð âåêòîðà ";
	cin >> m;
	system("cls");
	Array arr(n, m);
	Vector vec(m);
	arr.fillArray();
	system("cls");
	vec.fillVector();
	Array Umn(n, m);
	system("cls");
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			arr* vec;
		}
		else
			if (choose == 1) {
				arr.printArray();
			}
			else
				if (choose == 2) {
					vec.printVector();
				}
				else
					break;
	}
	return 0;
}

int chooseFillArray() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Ñòðåëî÷êàìè ÂÂÅÐÕ è ÂÍÈÇ âûáåðèòå êàê çàïîëíèòü ìàòðèöó: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { cout << " -> ×åðåç ñëó÷àéíûå ÷èñëà" << endl; }
		else { cout << " ×åðåç ñëó÷àéíûå ÷èñëà" << endl; }

		if (choose_menu == 1) { cout << " -> Ñ êëàâèàòóðû" << endl; }
		else { cout << " Ñ êëàâèàòóðû" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Ñòðåëî÷êàìè ÂÂÅÐÕ è ÂÍÈÇ âûáåðèòå ïóíêò ìåíþ: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Óìíîæåíèå âåêòîðà íà ìàòðèöó è âûâîä èòîãîâîé ìàòðèöû." << endl; }
		else { cout << " Óìíîæåíèå âåêòîðà íà ìàòðèöó è âûâîä èòîãîâîé ìàòðèöû." << endl; }

		if (choose_menu == 1) { cout << " -> Âûâåñòè ìàòðèöó" << endl; }
		else { cout << " Âûâåñòè ìàòðèöó" << endl; }

		if (choose_menu == 2) { cout << " -> Âûâåñòè âåêòîð" << endl; }
		else { cout << " Âûâåñòè âåêòîð" << endl; }

		if (choose_menu == 3) { cout << " -> Çàâåðøèòü ïðîãðàììó" << endl; }
		else { cout << " Çàâåðøèòü ïðîãðàììó" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}
