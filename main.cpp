#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
protected:
	int sizeNum;
	std::string name;
public:
	Figure()
	{
		sizeNum = 0;
		name = "Фигура";
	}
	int get_sizeNum() {
		return sizeNum;
	}
	std::string get_name() {
		return name;
	}

	virtual void print_info(){}

	virtual bool checking()
	{
		if (sizeNum == 0) {
			return true;
		}
		else { return false; }
	}
};

class Triangle : public Figure
{
protected:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) :Triangle(a, b, c, A, B, C, "Треугольник") {}

	Triangle(int a, int b, int c, int A, int B, int C, std::string name)
	{
		sizeNum = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->name = name;
	}
	bool checking() override
	{
		if (A + B + C == 180 && sizeNum == 3) {
			return true;
		}
		else return false;
	}

	void print_info() override
	{
		std::cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	}
};

class Right_triangle : public Triangle
{
public:
	Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник")
	{
	}
	bool checking() override
	{
		if (C == 90 && Triangle::checking() == true) {
			return true;
		}
		else return false;
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, b, A, B, B, "Равнобедренный треугольник")
	{
	}
	bool checking() override
	{
		if (a == c && A == C && Triangle::checking() == true) {
			return true;
		}
		else return false;
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(int a) :Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник")
	{}
	bool checking() override
	{
		if (a == b == c && A == B == C && Triangle::checking() == true) {
			return true;
		}
		else return false;
	}
};


class Quadrilateral : public Figure
{
protected:
	int a, b, c, d, A, B, C, D;
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrilateral(a, b, c, d, A, B, C, D, "Четырехугольник") {}
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name)
	{
		sizeNum = 4;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->name = name;
	}

	bool checking() override
	{
		if (A + B + C + D == 360 && sizeNum == 4) {
			return true;
		}
		else return false;
	}

	void print_info() override
	{
		std::cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
	}
};

class Rectangl : public Quadrilateral
{
public:
	Rectangl(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {}

	bool checking() override
	{
		if (a == c && b == d && A == B == C == D == 90 && Quadrilateral::checking() == true) {
			return true;
		}
		else return false;
	}
};

class Square : public Quadrilateral
{
public:
	Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90, "Квадрат") {}

	bool checking() override
	{
		if (a == b == c == d && A == B == C == D == 90 && Quadrilateral::checking() == true) {
			return true;
		}
		else return false;
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrilateral(a, b, a, b, A, B, A, B, "Параллелограмм") {}

	bool checking() override
	{
		if (a == c && b == d && A == C && B == D && Quadrilateral::checking() == true) {
			return true;
		}
		else return false;
	}
};

class Rhombus : public Quadrilateral
{
public:
	Rhombus(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B, "Ромб") {}

	bool checking() override
	{
		if (a == b == c == d && A == C && B == D && Quadrilateral::checking() == true) {
			return true;
		}
		else return false;
	}
};

void printInfo(Figure* figure)
{
	std::cout << figure->get_name() << ':' << std::endl;
	if (figure->checking() == true)
	{
		std::cout << "Правильная" << std::endl;
	}
	else {
		std::cout << "Неправильная" << std::endl;
	}
	figure->print_info();
	std::cout << std::endl;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle triangle(1, 2, 3, 4, 5, 6);
	printInfo(&triangle);

	Right_triangle rTriangle(3, 2, 4, 60, 30);
	printInfo(&rTriangle);

	Isosceles_triangle iTriangle(2, 3, 60, 30);
	printInfo(&iTriangle);

	Equilateral_triangle eTriangle(4);
	printInfo(&eTriangle);

	Quadrilateral quadrilateral(2, 4, 5, 3, 30, 20, 180, 130);
	printInfo(&quadrilateral);

	Rectangl rectangle(1, 2);
	printInfo(&rectangle);

	Square square(10);
	printInfo(&square);

	Parallelogram parallelogram(2, 4, 50, 65);
	printInfo(&parallelogram);

	Rhombus rhombus(2, 50, 60);
	printInfo(&rhombus);

	return 0;
}