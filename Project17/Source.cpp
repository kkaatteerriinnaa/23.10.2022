#include <iostream>
#include <cstring>
using namespace std;

class Transport
{
	char* type;
	string color;
	int speed;
	int fuelcons;
	int passenger;
public:
	Transport()
	{
		type = nullptr;
		color = "";
		speed = fuelcons = passenger = 0;
	}
	Transport(const char* t, string c, int s, int f, int p)
	{
		if (type != nullptr)
			delete[]type;
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
		color = c;
		speed = s;
		fuelcons = f;
		passenger = p;
	}
	virtual void Show()
	{
		cout << "Transport: " << type << endl;
		cout << "Color: " << color << endl;
		cout << "Speed: " << speed << " km\\h\n";
		cout << "Fuel consumption: " << fuelcons << " L\\100 km\n";
		cout << "Passengers: " << passenger << endl;
	}
	virtual void Init()
	{
		cout << "Transport: ";
		char* temp = new char[128];
		cin >> temp;
		if (type != nullptr)
			delete[]type;
		type = new char(strlen(temp) + 1);
		strcpy_s(type, strlen(temp) + 1, temp);
		delete[]temp;
		cout << "Color: ";
		cin >> color;
		cout << "Speed: ";
		cin >> speed;
		cout << "Fuel consumption: ";
		cin >> fuelcons;
		cout << "Passengers: ";
		cin >> passenger;
	}
	virtual int GetFuel()
	{
		return fuelcons;
	}
	virtual~Transport();
};

Transport::~Transport()
{
	cout << "Transport destruct\n";
	delete[]type;
}

class Plane :public Transport
{
	char* company;
public:
	Plane()
	{
		company = nullptr;
	}
	Plane(const char* t, string c, int s, int f, int p, const char* co) :Transport(t, c, s, f, p)
	{
		if (company != nullptr)
			delete[]company;
		company = new char[strlen(co) + 1];
		strcpy_s(company, strlen(co) + 1, co);
	}
	void Show()
	{
		Transport::Show();
		cout << "Company: " << company << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Company: ";
		char* temp = new char[128];
		cin >> temp;
		if (company != nullptr)
			delete[]company;
		company = new char(strlen(temp) + 1);
		strcpy_s(company, strlen(temp) + 1, temp);
		delete[]temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Plane()
	{
		cout << "Plane Destruct\n";
		delete[]company;
	}
};

class Cycle :public Transport
{
	double* tire_size;
public:
	Cycle()
	{
		tire_size = nullptr;
	}
	Cycle(const char* t, string c, int s, int f, int p, double ti) :Transport(t, c, s, 0, p)
	{
		if (tire_size != nullptr)
			delete tire_size;
		tire_size = new double;
		*tire_size = ti;
	}
	void Show()
	{
		Transport::Show();
		cout << "Tire Diameter: " << *tire_size << " sm\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Tire size: ";
		if (tire_size != nullptr)
			delete tire_size;
		tire_size = new double;
		double temp;
		cin >> temp;
		*tire_size = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Cycle()
	{
		cout << "Cycle Destruct\n";
		delete tire_size;
	}
};

class Jeep :public Transport
{
	bool* offroad;
public:
	Jeep()
	{
		offroad = nullptr;
	}
	Jeep(const char* t, string c, int s, int f, int p, bool off) :Transport(t, c, s, f, p)
	{
		if (offroad != nullptr)
			delete offroad;
		offroad = new bool;
		*offroad = off;
	}
	void Show()
	{
		Transport::Show();
		if (*offroad)
			cout << "Can drive on offroad\n";
		else
			cout << "Cant drive on offroad\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "For offroad?\t1.Yes\t0.No\n";
		if (offroad != nullptr)
			delete offroad;
		offroad = new bool;
		bool temp;
		cin >> temp;
		*offroad = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Jeep()
	{
		cout << "Jeep Destruct\n";
		delete offroad;
	}
};

class Ship :public Transport
{
	double* carr_cap;
public:
	Ship()
	{
		carr_cap = 0;
	}
	Ship(const char* t, string c, int s, int f, int p, double cc) :Transport(t, c, s, f, p)
	{
		if (carr_cap != nullptr)
			delete carr_cap;
		carr_cap = new double;
		*carr_cap = cc;
	}
	void Show()
	{
		Transport::Show();
		cout << "Carrying capacity: " << *carr_cap << " tones\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Carrying capacity: ";
		if (carr_cap != nullptr)
			delete carr_cap;
		carr_cap = new double;
		double temp;
		cin >> temp;
		*carr_cap = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Ship()
	{
		cout << "Ship Destruct\n";
		delete carr_cap;
	}
};

class Truck :public Transport
{
	int* HP;
public:
	Truck()
	{
		HP = nullptr;
	}
	Truck(const char* t, string c, int s, int f, int p, int hp) :Transport(t, c, s, f, p)
	{
		if (HP != nullptr)
			delete HP;
		HP = new int;
		*HP = hp;
	}
	void Show()
	{
		Transport::Show();
		cout << "Horse power: " << *HP << "\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Horse power: ";
		if (HP != nullptr)
			delete HP;
		HP = new int;
		double temp;
		cin >> temp;
		*HP = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Truck()
	{
		cout << "Truck Destruct\n";
		delete HP;
	}
};

int menu1()
{
	int choose;
	cout << "1.Plane\n2.Cycle\n3.Jeep\n4.Ship\n5.Truck\n";
	cin >> choose;
	return choose;
}

int menu2()
{
	int choose;
	cout << "1.Show\n2.Show fuel consumption per 100km\n";
	cin >> choose;
	return choose;
}

int main()
{
	int choose_1 = menu1();
	Transport* Tptr = nullptr;
	switch (choose_1)
	{
	case 1:
		Tptr = new Plane();
		Tptr->Init();
		break;
	case 2:
		Tptr = new Cycle();
		Tptr->Init();
		break;
	case 3:
		Tptr = new Jeep();
		Tptr->Init();
		break;
	case 4:
		Tptr = new Ship();
		Tptr->Init();
		break;
	case 5:
		Tptr = new Truck();
		Tptr->Init();
		break;
	default:
		break;
	}
	system("cls");
	int choose_2 = menu2();
	switch (choose_2)
	{
	case 1:
		Tptr->Show();
		break;
	case 2:
		cout << Tptr->GetFuel();
		break;
	default:
		break;
	}
	delete Tptr;
}