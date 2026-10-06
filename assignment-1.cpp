#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function Declarations

void getInput(double *ptrEntry, double *ptrExit, string *ptrVehicle, char *ptrMember);
void displayOutput(double parkingDuration, double basicCharge, double discount, double finalCharge);

double calculateDuration(double entry, double exit);

double getRate(string vehicle);
double getDiscount(double basicCharge, char memberStatus);

double calculateBasicCharge(double parkingDuration, double hourlyRate);
double calculateFinalCharge(double basicCharge, double discount);

// Main Function

int main(){
    double entryTime, exitTime, parkingDuration, hourlyRate, basicCharge, discount, finalCharge;
    string vehicleType;
    char membershipStatus;

    getInput(&entryTime, &exitTime, &vehicleType, &membershipStatus);

    parkingDuration = calculateDuration(entryTime, exitTime);
    hourlyRate = getRate(vehicleType);
    basicCharge = calculateBasicCharge(parkingDuration, hourlyRate);
    discount = getDiscount(basicCharge, membershipStatus);
    finalCharge = calculateFinalCharge(basicCharge, discount);

    displayOutput(parkingDuration, basicCharge, discount, finalCharge);

    return 0;
}

// Gets input and stores in the corresponding variables.
void getInput(double *ptrEntry, double *ptrExit, string *ptrVehicle, char *ptrMember){
    // Enter Timing
    cout << "Enter Time (Ex: 8 for 8:00/9.5 for 9:30 in 24H clock)" << endl << endl;

    cout << "Enter Entry Time: ";
    cin >> *ptrEntry;

    cout << "Enter Exit Time: ";
    cin >> *ptrExit;

	cout << endl;

    // Enter Vehicle Type
    cout << "Enter Vehicle Type (Car/Motorcycle/Van): ";
    cin >> *ptrVehicle;
    
    while ((*ptrVehicle != "Car") && (*ptrVehicle != "Motorcycle") && (*ptrVehicle != "Van")){
    	cout << endl << "Invalid Input Type!" << endl;
    	
    	cout << "Enter Vehicle Type (Car/Motorcycle/Van): ";
    	cin >> *ptrVehicle;
	}

    // Enter Membership Status
    cout << "Enter Membership Status (T/F): ";
    cin >> *ptrMember;

    while ((*ptrMember != 'T') && (*ptrMember != 'F')){
        cout << endl << "Invalid Membership Status!" << endl;

    	cout << "Enter Membership Status (T/F): ";
    	cin >> *ptrMember;
	}
}

// Displays Outputs
void displayOutput(double parkingDuration, double basicCharge, double discount, double finalCharge){
    cout << endl << "Parking Duration: " << parkingDuration << " Hours"
         << endl << "Basic Charge: RM" << basicCharge
         << endl << "Discount: RM" << discount
         << endl << "Final Charge: RM" << finalCharge;
}

// Calculates Parking Duration in Hours
double calculateDuration(double entry, double exit){
    double parkingDuration;

    parkingDuration = exit - entry;

    if (parkingDuration < 0){
        parkingDuration += 24;
    }

    return ceil(parkingDuration);
}

// Gets Rate Based on Vehicle Type
double getRate(string vehicle){
	double rate;

    double carRate = 3.0;
	double motorcycleRate = 1.5;
	double vanRate = 5.0;
	
	if (vehicle == "Car") {
		rate = carRate;
	} else if (vehicle == "Motorcycle") {
		rate = motorcycleRate;
	} else {
		rate = vanRate; 
	}
	
	return rate;
}

// Gets Discount Bsaed on Membership Status
double getDiscount(double basicCharge, char memberStatus){
	double discount, memberDiscountRate;
	
	memberDiscountRate = 0.05;
	
	if (memberStatus == 'T'){
		discount = basicCharge * memberDiscountRate;
	} else {
		discount = 0;
	}
	
	return discount;
}

// Calculates Basic Charge Amount
double calculateBasicCharge(double parkingDuration, double hourlyRate){
	double basicCharge;
	
	basicCharge = parkingDuration * hourlyRate;
	
	return basicCharge;
}

// Calculates Final Charge Amount
double calculateFinalCharge(double basicCharge, double discount){
    double finalCharge;

    finalCharge = basicCharge - discount;

    return finalCharge;
}
