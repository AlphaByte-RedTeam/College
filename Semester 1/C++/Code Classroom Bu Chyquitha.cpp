#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

const float PI = 3.14f;

float CircleArea(float radius);
float RectangleArea(float length, float width);
float RightTriangleArea(float base, float height);
float CylinderVolume(float height, float &radius);
float SphereVolume(float &radius);
int menu_choice = 0;
char next_menu_choice = 0;
int number = 0;
float length = 0;
float width = 0;
float base = 0;
float height = 0;
float radius = 0;
float volume = 0;
float area = 0;

int main()
{
	cout << "-- Main Menu --" << endl;
	cout << "1) Calculate Area\n"
		 << "2) Calculate Volume\n";

	cout << "Enter a menu choice: ";
	cin >> menu_choice;
	cout << '\n';

		switch ( menu_choice )
		{
			case 1:
		// Display the area menu
			cout << " -- Area Menu -- \n"
				 << "a) Rectangle\n"
				 << "b) Circle\n"
				 << "c) Right Triangle\n\n";

			cout << "Enter a menu choice: ";
			cin >> next_menu_choice;
			cout << endl;


				switch ( next_menu_choice )
				{
				case 'a':
				case 'A':
					cout << "Enter the length: ";
					cin >> length;
					cout << "\nEnter the width: ";
					cin >> width;
					RectangleArea(length, width);
					cout << endl;
					break;

				case 'b':
				case 'B':
					cout << "Enter the radius: ";
					cin >> radius;
					CircleArea(radius);
					cout << endl;
					break;

				case 'c':
				case 'C':
					cout << "Enter the base: ";
					cin >> base;
					cout << "Enter the height: ";
					cin >> height;
					RightTriangleArea(base, height);
					cout << endl;
					break;
				}

			case 2:
			// Display the volume menu
			cout << " -- Volume Menu -- \n"
				 << "a) Cylinder\n"
				 << "b) Sphere\n";

				switch (next_menu_choice)
				{
				case 'a':
				case 'A':
					cout << "Enter the height: ";
					cin >> height;
					cout << "Enter the radius: ";
					cin >> radius;
					CylinderVolume(height, radius);
					cout << endl;
					break;

				case 'b':
				case 'B':
					cout << "Enter the radius: ";
					cin >> radius;
					SphereVolume(radius);
					cout << endl;
					break;
				}

			default:
			cout << "You have entered an invalid menu choice.\n"
				 << "Please try again.\n\n";
			break;
			}

	//system("Pause");



		}
float CircleArea(float radius)
{
	float area = PI*(radius*radius);
	cout << "The area of a circle with radius " <<radius<< " is: " <<area<< endl;
	return (area);
}
float RectangleArea(float length, float width)
{
	float area = length * width;
	cout << "The area of a rectangle with a length of " <<length<< " and a width of " <<width<< " is: " <<area<< endl;
	return(area);
}
float RightTriangleArea(float base, float height)
{
	float area = (base * height)/2;
	cout << "The area of a right triangle with a base of "
		 << base
		 << " and a height of "
		 << height
		 << " is: "
		 << area << endl;
	return(area);
}
float CylinderVolume(float height, float &radius)
{
	float volume = (height * PI) * (radius*radius);
	cout << "The volume of a cylinder with a height of "
		 << height
		 << " and a radius of "
		 << radius
		 << " is: "
		 << volume << endl;
	return(volume);
}
float SphereVolume(float &radius)
{
	float volume = (4/3) * PI * (radius*radius*radius);
	cout << "The volume of a sphere with a radius of "
		 << radius
		 << " is: "
		 << volume << endl;
	return(volume);
}