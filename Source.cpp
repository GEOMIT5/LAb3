/*#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class String
{
    char* data = nullptr;
    size_t sz = 0;

public:
    String(void) = default;
    String(const char* s)
    {
        sz = strlen(s);
        data = new char[sz + 1];
        for (size_t i = 0; i < sz; ++i)
            data[i] = s[i];
        data[sz] = '\0';
    }

    String(const String& other)
    {
        sz = other.sz;
        for (size_t i = 0; i <= sz; ++i)
            data[i] = other.data[i];
    }

    ~String(void) 
    { 
        
        delete[] data; 
    
    }

    int operator = (const String&);
    

    char operator++(void);
    

    char operator++(int);
    

    const char* c_str(void) const { return data; }

};

int String:: operator = (const String&other)
{
    if (&other == this)
        return *this;
    delete[] data;
    sz = other.sz;
    data = new char[sz + 1];
    for (size_t i = 0; i <= sz; ++i)
        data[i] = other.data[i];
    return *this;
}

char String::operator++(void)
{
    char tmp = data[0];
    for (size_t i = 0; i < sz - 1; ++i)
        data[i] = data[i + 1];
    return *this;
}

char String::operator++(int)
{
    String copy = *this;
    char tmp = data[sz - 1];
    for (size_t i = sz - 1; i > 0; --i)
        data[i] = data[i - 1];
    data[0] = tmp;
    return copy;
}



int main()
{





}*/
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
	friend Vector& operator*(Array& arr1, Vector& vec1);
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
	friend Vector& operator*(Array& arr1, Vector& vec1);
};

Vector& operator*(Array& arr1, Vector& vec1) {
	Vector vect(vec1.m);
	
	for (int i = 0; i < arr1.n; i++) {
		float temp=0;
		for (int j = 0; j < arr1.m; j++) {
			temp += arr1.arr[i][j] * vec1.vec[i];
			
		}
		vect.vec[i] = temp;
	}
	vect.printVector();
	return vect;
}

void Array::printArray() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	system("pause");
	
}

void Array::fillArray() {
	int choose = chooseFillArray();
	if (choose == 0) {
		
		cout << "Введите левую границу диапозона: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Введите правую границу диапозона: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Введите элементы массива: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " - строка из " << m << " символов: ";
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
	}
}

void Vector::printVector() {
	
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
	system("pause");
	
}

void Vector::fillVector() {
	int choose = chooseFillArray();
	if (choose == 0) {
		
		cout << "Введите левую границу диапозона: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Введите правую границу диапозона: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < m; i++)
			vec[i] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Введите элементы массива: " << endl;
		for (int i = 0; i < m; i++) {
			cin >> vec[i];
		}
	}
}

int main() {
	setlocale(0, "rus");
	int n, m;
	cout << "Введите размер матрицы ";
	cin >> n;
	cout << "Введите второй размер матрицы и размер вектора ";
	cin >> m;
	
	Array arr(n, m);
	Vector vec(m);
	arr.fillArray();
	vec.fillVector();
	Vector Umn(m);
	
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			arr * vec;
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
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите как заполнить матрицу: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { cout << " -> Через случайные числа" << endl; }
		else { cout << " Через случайные числа" << endl; }

		if (choose_menu == 1) { cout << " -> С клавиатуры" << endl; }
		else { cout << " С клавиатуры" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) {  return choose_menu; }
		
	}
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Умножение вектора на матрицу и вывод итоговой матрицы." << endl; }
		else { cout << " Умножение вектора на матрицу и вывод итоговой матрицы." << endl; }

		if (choose_menu == 1) { cout << " -> Вывести матрицу" << endl; }
		else { cout << " Вывести матрицу" << endl; }

		if (choose_menu == 2) { cout << " -> Вывести вектор" << endl; }
		else { cout << " Вывести вектор" << endl; }

		if (choose_menu == 3) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) {  return choose_menu; }
		
	}
}