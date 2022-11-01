#include <iostream>
#include <string>

// Константа препроцессора

#define N 4

#if N == 2 + 2
#define PI 3.14 // Эти константа не занимает места в памяти!!!
#define MSG  " Hello World!"
#endif

// Программные конструкции
#define forever while (true)
#define begin {
#define end }

// #undef - удалят
#undef PI

// Макросы
#define sum(a,b) a + b
#define crtarr(t, n, s) t *n = new t[s] 
// макрос динамического массива

#define ctrmx(t, u, s1, s2) t ** u = new t * [s1];\
	for (int i = 0; i < s1; i++)\
		u[i] = new t[s2]; // Макрос двумерного динамического массива

// Условная компиляция - добавляет в текст часть кода, если условие истино
#if 1 == 2
void hi() {
	std::cout << "Hello!\n";
}
#elif 2 == 3
void hi() {
	std::cout << "Wow!\n";
}
#else
void hi() {
	std::cout << "Bye!\n";
}
#endif

#ifndef sum // если не существует
const int P = 10;
#else
const int P = 11;
#endif

#ifdef sum // если существует
const int K = 10;
#else
const int K = 11;
#error "Ошибка! sum дожно существовать."
#endif


#define print(v) std::cout << #v << " = " << v << '\n'

// Оператор конкатинации кода 
#define show(a,b) a ## b



int main() {
	setlocale(LC_ALL, "Russian");
	int x = 1, y = 2;
	int xy = 10;

	
	std::cout << show(x, y) << '\n';

	print(x);
	print(y);

	// Встроенные процессы(объекты) препроцессора
	std::cout << __LINE__ << std::endl; // показывает номер строчки

	std::cout << __FILE__ << std::endl; // показывает путь к файлу
	std::string date = __DATE__;
	std::cout << date << std::endl; // показывает текущуу дату

	int year = stoi(date.substr(date.rfind(" ") + 1)); // превращение строчки в число
	year += 10;
	std::cout << " Текущий год " << year << '\n';


	// Константа препроцессора
	/*
	std::cout << "PI = " << PI << '\n';
	std::cout << MSG << '\n';

#undef PI
*/

	// Программные конструкции
	/*
	x = 0;
	forever {
		std::cout << '.';
	x++;
	if (x >= 5)
		break;
	}
	std::cout << '\n';
	*/

	// Макросы
	/*
	std::cout << sum(1, 5.7) << '\n'; // 6.7
	crtarr(int, px, 5);
	px[0] = 1;
	delete[]px;

	ctrmx(int, mat, 5, 4);
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			mat[y][x] = y * x + 1;
			std::cout << mat[y][x] << '\t';
		}
		std::cout << '\n';
	}
	for (int i = 0; i < 4; i++)
		delete[]mat[i];
	delete[]mat;
	*/
	// Условная компиляция
	hi();


	return 0;
}