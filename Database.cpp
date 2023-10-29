#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
#include "car.h"
using namespace std;
namespace Records {
	Database::Database()
	{
		mNextSlot = 0;
	}
	Database::~Database()
	{
		for (int i = 0; i < mNextSlot; i++)
				delete mCars[i];
	}
	Car& Database::addCar(std::string CarVincode, std::string RegistrationCode)
	{
		if (mNextSlot >= kMaxCars) {
			cerr << "There is no more room to add the new employee!" << endl;
			throw exception();

		}
		Car* theCar = new Car(CarVincode, RegistrationCode);
		mCars[mNextSlot++] = theCar;
		return *theCar;
	}
	void Database::deleteCar(std::string RegistrationCode) {
		string code;
		for (int i = 0; i < mNextSlot; i++) {
			code=mCars[i]->GetCarRegistrationCode();
			if (code == RegistrationCode) {
				delete mCars[i];
				for (int j = i + 1; j < mNextSlot; j++) {
					mCars[j - 1] = mCars[j];
				}
				mNextSlot--;
				break;
			}
		}

	}
	Car& Database::getCar(std::string RegistrationCode)
	{
		string code;
		for (int i = 0; i < mNextSlot; i++) {
			code = mCars[i]->GetCarRegistrationCode();
			if (code == RegistrationCode) {
				return *mCars[i];
			}
		}
		cout << "No match with code " << RegistrationCode << endl;
	}
	void Database::displayAll()
	{
		for (int i = 0; i < mNextSlot; i++) {
			mCars[i]->ShowAllInfo();
		}
	}
}
