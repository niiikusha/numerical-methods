#include <iostream>
#include <cmath>
using namespace std;

double F(double x) {
return x * x - cos(5*x); //любая функция
}

int main() {
	setlocale(LC_ALL, "Russian");

	double a, b, sigma = 0.001, c, f_a = 0, f_b, f_c, X;
	cout << "Введите границы интервала a и b: ";
	cin >> a;
	cin >> b;
	cout << endl;

	//метод дихотомии
	f_a = F(a);
	f_b = F(b);
	while(b - a > sigma) {
		c = (a + b)/2; // находим середину отрезка (so)
		f_c = F(c);
		if(f_a * f_c <= 0) {
			b = c;
			f_b = f_c;
		} else {
			a = c;
			f_a = f_c;
		}
	}
	X = (a + b)/2;
	cout << "по методу дихотомии х = " << X << endl;
	
	// метод золотого сечения
	const double goldenRatio = (1 + sqrt(5)) / 2; // "Золотое" число
	double x1, x2; // Точки, делящие текущий отрезок в отношении золотого сечения
	a=0.2;
	b=0.4;
	
	while (fabs(b - a) > sigma) {
		x1 = a + (b - a) / goldenRatio;
		x2 = a + (b - a) / (goldenRatio*goldenRatio);
		if (F(x1)*F(x2)<=0)// Условие для поиска максимума {
			b = x1;
		} else
			a = x2;
	} // Выполняем, пока не достигнем заданной точности
	cout << "по методу золотого сечения х = " << (a + b)/2 <<endl;
	
	// метод хорд
	//float c;
	do {
		c = a - F(a)/(F(b)-F(a))*(b-a);
		if(F(a)*F(c)<0)
			b = c;
		else
			a = c;
	} while(F(c) > sigma);
	cout << "по методу хорд х = " << c << endl;
	
	//метод Ньютона (касательных)
	double y, y1, h = 0.1,ffa;
	ffa = (F(a+h)-2*F(a)+F(a-h))/a*a;
	if(F(a)*ffa > 0) X = a;
		else X = b;
	do {
		y = F(X);
		y1 = (F(X + h) - F(X - h)) / (2 * h);
		X = X - y/y1;
	} while(fabs(y) > sigma);
	y = F(X);
	cout << "по методу ньютона х = " << X << endl;
	//fc = (F(x + h) - F(x - h)) / (2 * h); - нахождение производной
	
	//комбинированный метод
	double X0n, X0i, y0n, y0i, Xn, Xi;
	X0n = a;
	X0i = b;
	do {
		y0n = F(X0n);
		y0i = F(X0i);
		y1 = (F(X0i + h) - F(X0i - h)) / (2 * h);
		Xn = X0n - (X0i - X0n)*y0n/(y0i - y0n);
		Xi = X0i - y0i/y1;
		X0n = Xn;
		X0i = Xi;
	} while(Xi - Xn > sigma);
	X = 0.5 * (Xi + Xn);
	y = F(X);
	cout << "по методу комбинированному х = " << X << endl;
}

