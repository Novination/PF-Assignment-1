#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function Declarations

void getInput(double *ptrEntry, double *ptrExit, string *ptrVehicle, char *ptrMember);
void displayOutput();

double calculateHours(double entry, double exit);

double getRate(string vehicle);
double getDiscount(double basicCharge, char memberStatus);

double calculateBasicCharge(double parkingHours, double hourlyRate);
double calculateFinalCharge(double basicCharge, double discount);

// Main Function

int main(){
    double entryTime, exitTime, parkingHours, hourlyRate, basicCharge, discount;
    string vehicleType;
    char membershipStatus;

    getInput(&entryTime, &exitTime, &vehicleType, &membershipStatus);

    parkingHours = calculateHours(entryTime, exitTime);
    
    hourlyRate = getRate(vehicleType);
    
    basicCharge = calculateBasicCharge(parkingHours, hourlyRate);
    
    discount = getDiscount(basicCharge, membershipStatus);

    cout << endl << entryTime << endl << exitTime << endl << vehicleType << endl << membershipStatus;
    cout << endl << parkingHours << endl << basicCharge << endl << discount << endl;

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
        cout << "Invalid Membership Status!";

    	cout << "Enter Membership Status (T/F): ";
    	cin >> *ptrMember;
	}
}

double calculateHours(double entry, double exit){
    double parkingDuration;

    parkingDuration = exit - entry;

    if (parkingDuration < 0){
        parkingDuration += 24;
    }

    return parkingDuration;
}

double getRate(string vehicle){
	double rate;
	
	if (vehicle == "Car") {
		rate = 3;
	} else if (vehicle == "Motorcycle") {
		rate = 1.5;
	} else {
		rate = 5; 
	}
	
	return rate;
}

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

double calculateBasicCharge(double parkingHours, double hourlyRate){
	double basicCharge;
	
	basicCharge = parkingHours * hourlyRate;
	
	return basicCharge;
}
