#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cmath>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid
{
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
	virtual string message() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :public Solid
{
private:
	double width;
	double height;
	double depth;

public:
	Box(double width, double height, double depth)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetVolume() override
	{
		return width * height * depth;
	}
	double GetSurface() override
	{
		return (width * height + height * depth + depth * width) * 2;
	}
	string message()
	{
		return "四角";
	}
};
class Cylinder :public Solid
{
private:
	double radius;
	double height;

public:
	Cylinder(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
	}
	double GetVolume()override
	{
		return radius * radius * M_PI * height;
	}
	double GetSurface()override
	{
		return    2 * M_PI * radius * (height + radius);
	}
	string message()
	{
		return "円柱";
	}
};

class Cone :public Solid
{
private:
	double radius;
	double height;

public:
	Cone(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
	}
	double GetVolume()override
	{
		return radius * radius * M_PI * height * 1 / 3;
	}
	double GetSurface()override
	{
		return radius * radius * M_PI + sqrt(radius * radius + height * height) * radius * M_PI;
	}
	string message()
	{
		return "円錐";
	}
};

class Sphere : public Solid
{
private:
	double radius;
public:
	Sphere(double radius)
	{
		this->radius = radius;
	}
	double GetVolume()override
	{
		return 4.0 / 3 * radius * radius * radius * M_PI;
	}
	double GetSurface()override
	{
		return 4 * M_PI * radius * radius;
	}
	string message()
	{
		return "球";
	}
};
int main()
{
	Box box{ 2,2,2.2 };
	Cylinder cylinder{ 2.2,2.2 };
	Cone cone{ 2.2,2.2 };
	Sphere sphere{ 2.2 };
	Solid* solids[] = { &box, &cylinder, &cone, &sphere };
	for (Solid* s : solids)
	{
		cout << s->message() << ":体積=" << s->GetVolume() << ":表面積=" << s->GetSurface() << endl;
		cout << "\n" << endl;
	};
}