#include <iostream>
#include <cmath>
using namespace std;

	double F(double x){
		return (x * x - cos(5*x)); //любая функция
	}
int main(){ 
	setlocale(LC_ALL, "Russian");
	double a, b, sigma = 0.001, max = 1000000, k, so, f_a = 0, f_b, f_so, X;
	cout << "Введите границы интервала a и b";
	cin >> a;
	cin >> b;
	f_a = F(a);
	f_b = F(b);
	//метод дихотомии
	while(b - a > sigma and k < max){
		so = (a + b)/2; // находим середину отрезка (so)
		f_so = F(so);
		if(f_a * f_so <= 0){
			b = so;
			f_b = f_so;
		} else {
			a = so;
			f_a = f_so;
		}
	}
	X = (a + b)/2;
	cout << "Корень равен " << X;
	// метод хорд
	float c;
	do{
		c = a - F(a)/(F(b)-F(a))*(b-a);
		if(F(a)*F(c)<0){
			b = c;
		} else {
			a = c;
		}
	}while(F(c) > sigma);
	cout << endl << "Корень равен " << c;
	//метод Ньютона (касательных)
	double fc, y, y1, h = 0.1, ffa;
//	cout << endl << "Введите x0 " << endl;
//	cin >> X;
//	X = 0.4;
	ffa = (F(a+h)-2*F(a)+F(a-h))/a*a;
	if(F(a)*ffa > 0) X = a;
	else X = b;
	do{
		y = F(X);
		y1 = (F(X + h) - F(X - h)) / (2 * h);
		X = X - y/y1;
		
	} while(abs(y) > sigma);
	y = F(X);
	cout << endl << "Корень равен " << X;
	//fc = (F(x + h) - F(x - h)) / (2 * h); - нахождение производной
	//комбинированный метод
	double X0n, X0i, y0n, y0i, Xn, Xi;

	X0n = a;
	X0i = b;
	do{
		y0n = F(X0n);
		y0i = F(X0i);
		y1 = (F(X0i + h) - F(X0i - h)) / (2 * h);
		Xn = X0n - (X0i - X0n)*y0n/(y0i - y0n);
		Xi = X0i - y0i/y1;
		X0n = Xn;
		X0i = Xi;
	}while(Xi - Xn > sigma);
		X = 0.5 * (Xi + Xn);
		y = F(X);
	cout << endl << "Корень равен " << X << endl;
	//метод итераций 
	cout << "Введите X0 ";
	double x0 = 0.4, x1;
	//cin >> x0;
	double rez, iter = 0;
	while(true)
	{
		x1 = exp(1.0/(4.0*(1+sqrt(x0))));
		if(abs(x1-x0)<sigma)
			break;
		x0 = x1;
	}
	cout << "Корень равен" << x1;
}

