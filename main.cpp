#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;
int displayMenu();
void doAdd(Database& inDB);
void doDelete(Database& inDB);
void doEdit(Database& inDB);
void ShowAll(Database& inDB);

int main(int argc, char** argv)
{
	Database employeeDB;
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doAdd(employeeDB);
			break;
		case 2:
			doEdit(employeeDB);
			break;
		case 3:
			doDelete(employeeDB);
			break;
		case 4:
			ShowAll(employeeDB);
			break;
		case 0:
			done = true;
			break;
		default:
			cout << "Unknown command." << endl;
		}
	}
}
int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Cars Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Add new Car" << endl;
	cout << "2) Edit a Car" << endl;
	cout << "3) Delete a Car" << endl;
	cout << "4) List all Cars" << endl;
	cout << "0) Quit" << endl;
	cout << endl;

	cout << "---> ";
	cin >> selection;
	return selection;
}
void ShowAll(Database& inDB) {
	inDB.displayAll();
}
void doAdd(Database& inDB)
{
	string vincode, registration;
	cout << "Vincode? ";
	cin >> vincode;
	cout << "Registration number? ";
	cin >> registration;
	try {
		inDB.addCar(vincode, registration);
	}
	catch (std::exception ex) {
		cerr << "Unable to add new car!" << endl;
	}
}
void doDelete(Database& inDB)
{
	string CarRegNumber;
	cout << "Car registration number? ";
	cin >> CarRegNumber;
	try {
		inDB.deleteCar(CarRegNumber);
		cout << "Car " << CarRegNumber << " has been deleted." << endl;
	}
	catch (std::exception ex) {
		cerr << "Unable to delete the car!" << endl;
	}
}
void doEdit(Database& inDB) {
	string inRegCode;
	cout << "Car registration number? ";
	cin >> inRegCode;
	Car& myCar = inDB.getCar(inRegCode);
	myCar.AddInfoToCar();
}
