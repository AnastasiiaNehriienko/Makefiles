#include "car.h"
#include <iostream>
using namespace std;
namespace Records {
	int NextCarNum = 1;;
	Car::Car(){
		CarNumber = NextCarNum;
		NextCarNum++;
		FabricNumber=0;
		RegistrarionCode="XXXXXXXX";
		VinCode= "XXXXXXXXXXXXXXXXX";
		EngineCode='X';
		Year=0;
		mileage=0;
		DriverNumber=0;
		MaintenanceYear=0;
		MaintenanceMonth=0;
		MaintenanceDay=0;
		MechanicsCode=0;
		SpecialSigns="";
	}
	Car::Car(string inVinCode, string inRegCode){
		CarNumber = NextCarNum;
		NextCarNum++;
		FabricNumber = 0;
		RegistrarionCode=inRegCode;
		VinCode = inVinCode;
		EngineCode = 'X';
		Year = 0;
		mileage = 0;
		DriverNumber = 0;
		MaintenanceYear = 0;
		MaintenanceMonth = 0;
		MaintenanceDay = 0;
		MechanicsCode = 0;
		SpecialSigns = "";
	}
	void Car::AddInfoToCar(){
		bool done = false;
		while (!done) {
			int selection = displayCarMenu();
			switch (selection) {
			case 1:
				cout << "What is Fabric Number(int)? ";
				cin >> FabricNumber;
				break;
			case 2:
				cout << "What is Engine Code(char)? ";
				cin >> EngineCode;
				break;
			case 3:
				cout << "What is Year? ";
				cin >> Year;
				break;
			case 4:
				cout << "What is mileage(int)? ";
				cin >> mileage;
				break;
			case 5:
				cout << "What is Driver Number(int)? ";
				cin >> DriverNumber;
				break;
			case 6:
				cout << "What is Maintenance Year? ";
				cin >> MaintenanceYear;
				cout << "What is Maintenance Month? ";
				cin >> MaintenanceMonth;
				cout << "What is Maintenance Day? ";
				cin >> MaintenanceDay;
				break;
			case 7:
				cout << "What is Mechanics Code(int)? ";
				cin >> MechanicsCode;
				break;
			case 8:
				cout << "Any special signs(string)? ";
				cin >> SpecialSigns;
				break;
			case 9:
				cout << "Change registration number? ";
				cin >> RegistrarionCode;
				break;
			case 10:
				cout << "Change vin code? ";
				cin >> VinCode;
				break;
			case 0:
				done = true;
				break;
			default:
				cerr << "Unknown command." << endl;
			}
		}
	}
	string Car::GetCarRegistrationCode() {
		return RegistrarionCode;
	}
	string Car::GetCarVinCode() {
		return VinCode;
	}
	int Car::GetCarNumber() {
		return CarNumber;
	}
	void Car::ShowAllInfo(){
		cout << "----All info about car number " << CarNumber << "----"<<endl;
		cout << "Registration code: " << RegistrarionCode << endl;
		cout << "Vincode: " << VinCode << endl;
		if(FabricNumber != 0)
			cout << "Fabric Number: " << FabricNumber << endl;
		if (EngineCode != 'X')
			cout << "Engine Code: " << EngineCode << endl;
		if (Year != 0)
			cout << "Year: " << Year << endl;
		cout << "Mileage: " << mileage << endl;
		if (DriverNumber != 0)
			cout << "Driver Number: " << DriverNumber << endl;
		if (MaintenanceYear != 0 && MaintenanceMonth != 0 && MaintenanceDay != 0)
			cout << "Maintenance Date: " << MaintenanceDay<<"."<< MaintenanceMonth<<"."<< MaintenanceYear << endl;
		if (MechanicsCode != 0)
			cout << "Mechanics Code: " << MechanicsCode << endl;
		if (SpecialSigns != "")
			cout << "Special Signs: " << SpecialSigns << endl;
	}

	int Car::
		displayCarMenu()
	{


		int selection;
		cout << endl;
		cout << "Car edit" << endl;
		cout << "-----------------" << endl;
		cout << "1) Fabric Number" << endl;
		cout << "2) Engine Code" << endl;
		cout << "3) Year" << endl;
		cout << "4) mileage" << endl;
		cout << "5) Driver Number" << endl;
		cout << "6) Maintenance date" << endl;
		cout << "7) Mechanics Code" << endl;
		cout << "8) Special Signs" << endl;
		cout << "9) Registration code" << endl;
		cout << "8) Vincode" << endl;
		cout << "0) Quit" << endl;
		cout << endl;

		cout << "---> ";
		cin >> selection;
		return selection;
	}
}
