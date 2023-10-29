#pragma once
#include <iostream>
using namespace std;
namespace Records {
	class Car {
		int CarNumber;
		int FabricNumber;
		string RegistrarionCode;
		string VinCode;
		char EngineCode;
		int Year;
		int mileage;
		int DriverNumber;
		int MaintenanceYear;
		int MaintenanceMonth;
		int MaintenanceDay;
		int MechanicsCode;
		string SpecialSigns;
	public:
		Car();
		Car(string inVinCode, string inRegCode);
		void AddInfoToCar();
		string GetCarRegistrationCode();
		string GetCarVinCode();
		int GetCarNumber();
		void ShowAllInfo();
		int displayCarMenu();
	};
}
