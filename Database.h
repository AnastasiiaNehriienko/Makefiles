#pragma once
#include <iostream>
#include "car.h"
namespace Records {
	const int kMaxCars = 10;
	class Database
	{
	public:
		Database();
		~Database();
		Car& addCar(std::string CarVincode, std::string RegistrationCode);
		void deleteCar(std::string RegistrationCode);
		Car& getCar(std::string RegistrationCode);
		void displayAll();
	protected:
		Car* mCars[kMaxCars];
		int mNextSlot;
	};
}
