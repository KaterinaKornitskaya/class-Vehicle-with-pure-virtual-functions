// class Vehicle with pure virtual functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
	Реализовать иерархию классов "Транспортное средство". В базовом классе
	реализовать набор чисто виртуальных методов (ввод-вывод, расход топлива,
	получение стоимости, установка стоимости, грузоподъёмность, 
	количество мест для пассажиров).
	Потомки переопределяют чисто виртуальные методы. Создать массив 
	указателей базового класса. Каждый элемент указывает на объект потомка.
	Поочерёдно вызывая методы в переборном цикле, освобождаем память.
*/

class Vehicle  // класс Транспортное стредство, базовый
{
protected:
	std::string name;   // название
	float consumption;  // расход топлива
	float price;        // стоимость
	float distance;     // пройденная дистанция
	float carry;        // грузоподъемность
	short seats_num;    // колличество мест
public:
	Vehicle() : consumption{ 0 }, price{ 0 }, distance { 0 },
		        carry{ 0 }, seats_num{ 0 } {}  // консруктор без параметров

	Vehicle(std::string n, float con, float dist, float c, short s) 
		    : name{ n }, consumption{ con }, distance {dist }, 
		      carry{ c }, seats_num{ s } {}    // конструктор с параметрами

	float virtual Consumption() = 0;       // чисто виртуальный метод Расход топлива
	float virtual SetPrice() = 0;          // чисто виртуальный метод Установка стоимости
	float virtual GetPrice() const = 0;    // чисто виртуальный метод Получение стоимости
	float virtual CarryingCapacity() = 0;  // чисто виртуальный метод Грузоподъемность
	short virtual SeatsNumber() = 0;       // чисто виртуальный метод Колличество мест
	void virtual Output() = 0;             // чисто виртуальный метод Вывод на экран

	virtual ~Vehicle()
	{
		std::cout << "Vehicle destructor\n";
	}
};

class Airplane : public Vehicle  // класс Самолет, дочерний от Транспортное средство  
{
public:
	Airplane() {}  // консруктор без параметров

	Airplane(std::string n, float con,  float dist, float c, short s)
		    : Vehicle(n, con, dist, c, s) {}  // консруктор c параметрами
	
	float virtual Consumption()       // чисто виртуальная ф-ия Расход топлива, переопределена
	{
		return (consumption * distance);
	}
	float virtual SetPrice()          // чисто виртуальная ф-ия Установка стоимости, переопределена
	{		
		std::cout << "Enter price: ";
		std::cin >> price;		
		return price;
	}
	float virtual GetPrice() const    // чисто виртуальная ф-ия Получение стоимости, переопределена
	{
		return price;
	}
	float virtual CarryingCapacity()  // чисто виртуальная ф-ия Грузоподъемность, переопределена
	{
		return carry;
	}
	short virtual SeatsNumber()       // чисто виртуальная ф-ия Колличество мест, переопределена
	{
		return seats_num;
	}
	void virtual Output()             // чисто виртуальная ф-ия Вывод на экран, переопределена
	{
		std::cout << "Name of vehicle: " << '\t' << name << std::endl;
		SetPrice();
		std::cout << "Price: " << "\t\t\t" << GetPrice() << std::endl;
		std::cout << "Fuel consumption: " << '\t' << Consumption() << std::endl;
		std::cout << "Carrying capacity: " << '\t' << CarryingCapacity() << std::endl;
		std::cout << "Number of seats: " << '\t' << SeatsNumber() << std::endl;
	}
	virtual ~Airplane()
	{
		std::cout << "Airplane destructor\n";
	}
};

class Ship : public Vehicle  // класс Судно, дочерний от Транспортное средство  
{
public:
	Ship() {}  // консруктор без параметров

	Ship(std::string n, float con, float dist, float c, short s)
		: Vehicle(n, con, dist, c, s) {}  // консруктор c параметрами

	float virtual Consumption()       // чисто виртуальная ф-ия Расход топлива, переопределена
	{
		return (consumption * distance);
	}
	float virtual SetPrice()          // чисто виртуальная ф-ия Установка стоимости, переопределена
	{
		std::cout << "Enter price: ";
		std::cin >> price;
		return price;
	}
	float virtual GetPrice() const    // чисто виртуальная ф-ия Получение стоимости, переопределена
	{
		return price;
	}
	float virtual CarryingCapacity()  // чисто виртуальная ф-ия Грузоподъемность, переопределена
	{
		return carry;
	}
	short virtual SeatsNumber()       // чисто виртуальная ф-ия Колличество мест, переопределена
	{
		return seats_num;
	}
	void virtual Output()             // чисто виртуальная ф-ия Вывод на экран, переопределена
	{
		std::cout << "Name of vehicle: " << '\t' << name << std::endl;
		SetPrice();
		std::cout << "Price: " << "\t\t\t" << GetPrice() << std::endl;
		std::cout << "Fuel consumption: " << '\t' << Consumption() << std::endl;
		std::cout << "Carrying capacity: " << '\t' << CarryingCapacity() << std::endl;
		std::cout << "Number of seats: " << '\t' << SeatsNumber() << std::endl;
	}
	virtual ~Ship()
	{
		std::cout << "Ship destructor\n";
	}
};

class Truck : public Vehicle  // класс Грузовик, дочерний от Транспортное средство  
{
public:
	Truck() {}  // консруктор без параметров

	Truck(std::string n, float con, float dist, float c, short s)
		: Vehicle(n, con, dist, c, s) {}  // консруктор c параметрами

	float virtual Consumption()       // чисто виртуальная ф-ия Расход топлива, переопределена
	{
		return (consumption * distance);
	}
	float virtual SetPrice()          // чисто виртуальная ф-ия Установка стоимости, переопределена
	{
		std::cout << "Enter price: ";
		std::cin >> price;
		return price;
	}
	float virtual GetPrice() const    // чисто виртуальная ф-ия Получение стоимости, переопределена
	{
		return price;
	}
	float virtual CarryingCapacity()  // чисто виртуальная ф-ия Грузоподъемность, переопределена
	{
		return carry;
	}
	short virtual SeatsNumber()       // чисто виртуальная ф-ия Колличество мест, переопределена
	{
		return seats_num;
	}
	void virtual Output()             // чисто виртуальная ф-ия Вывод на экран, переопределена
	{
		std::cout << "Name of vehicle: " << '\t' << name << std::endl;
		SetPrice();
		std::cout << "Price: " << "\t\t\t" << GetPrice() << std::endl;
		std::cout << "Fuel consumption: " << '\t' << Consumption() << std::endl;
		std::cout << "Carrying capacity: " << '\t' << CarryingCapacity() << std::endl;
		std::cout << "Number of seats: " << '\t' << SeatsNumber() << std::endl;
	}
	virtual ~Truck()
	{
		std::cout << "Truck destructor\n";
	}
};

class Bicycle : public Vehicle  // класс Велосипед, дочерний от Транспортное средство  
{
public:
	Bicycle() {}  // консруктор без параметров

	Bicycle(std::string n, float con, float dist, float c, short s)
		: Vehicle(n, con, dist, c, s) {}  // консруктор c параметрами

	float virtual Consumption()       // чисто виртуальная ф-ия Расход топлива, переопределена
	{
		return 0;  // возврашаем 0 - нет расхода у велосипеда
	}
	float virtual SetPrice()          // чисто виртуальная ф-ия Установка стоимости, переопределена
	{
		std::cout << "Enter price: ";
		std::cin >> price;
		return price;
	}
	float virtual GetPrice() const    // чисто виртуальная ф-ия Получение стоимости, переопределена
	{
		return price;
	}
	float virtual CarryingCapacity()  // чисто виртуальная ф-ия Грузоподъемность, переопределена
	{
		return carry;
	}
	short virtual SeatsNumber()       // чисто виртуальная ф-ия Колличество мест, переопределена
	{
		return 0;  // возврашаем 0 - нет пассажирских мест у велосипеда
	}
	void virtual Output()             // чисто виртуальная ф-ия Вывод на экран, переопределена
	{
		std::cout << "Name of vehicle: " << '\t' << name << std::endl;
		SetPrice();
		std::cout << "Price: " << "\t\t\t" << GetPrice() << std::endl;
		std::cout << "No fuel consumption for Bicycle"  << std::endl;
		std::cout << "Carrying capacity: " << '\t' << CarryingCapacity() << std::endl;
		std::cout << "No passenger seats for bicycle" << std::endl;
	}
	virtual ~Bicycle()
	{
		std::cout << "Bicycle destructor\n";
	}
};

class Car : public Vehicle  // класс Автомобиль, дочерний от Транспортное средство  
{
public:
	Car() {}  // консруктор без параметров

	Car(std::string n, float con, float dist, float c, short s)
		: Vehicle(n, con, dist, c, s) {}  // консруктор c параметрами

	float virtual Consumption()       // чисто виртуальная ф-ия Расход топлива, переопределена
	{
		return (consumption * distance);
	}
	float virtual SetPrice()          // чисто виртуальная ф-ия Установка стоимости, переопределена
	{
		std::cout << "Enter price: ";
		std::cin >> price;
		return price;
	}
	float virtual GetPrice() const    // чисто виртуальная ф-ия Получение стоимости, переопределена
	{
		return price;
	}
	float virtual CarryingCapacity()  // чисто виртуальная ф-ия Грузоподъемность, переопределена
	{
		return carry;
	}
	short virtual SeatsNumber()       // чисто виртуальная ф-ия Колличество мест, переопределена
	{
		return seats_num;
	}
	void virtual Output()             // чисто виртуальная ф-ия Вывод на экран, переопределена
	{
		std::cout << "Name of vehicle: " << '\t' << name << std::endl;
		SetPrice();
		std::cout << "Price: " << "\t\t\t" << GetPrice() << std::endl;
		std::cout << "Fuel consumption: " << '\t' << Consumption() << std::endl;
		std::cout << "Carrying capacity: " << '\t' << CarryingCapacity() << std::endl;
		std::cout << "Number of seats: " << '\t' << SeatsNumber() << std::endl;
	}
	virtual ~Car()
	{
		std::cout << "Car destructor\n";
	}
};

int main()
{
	// объявление массива указателей на базовый класс
	// заполнение его объктами дочерних класслв
	Vehicle* veh[5] =                            
	{ new Airplane{"Mriya", 100, 200, 300, 26},  
	  new Ship{"Titanic", 80,  150, 240, 8},
	  new Truck{"Volvo", 14, 75, 80, 1},
	  new Bicycle{"Ukraina", 0, 75, 7, 0},
	  new Car{"BMV", 50, 40, 150, 3} };
	
	for (int i = 0; i < 5; i++)
	{
		veh[i]->Output();  // вызов соответсвующей ф-ии Вывод
		std::cout << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		delete veh[i];  // очистка памяти
	}
	return 0;

}