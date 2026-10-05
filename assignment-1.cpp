#include<iostream>
#include<string>
using namespace std;
#define SIZE 3

// Function Declarations

void getInput(int *ptrEntry, int *ptrExit, string *ptrVehicle, char *ptrMember);
void displayOutput();

int calculateDuration(int entry, int exit);
int calculateHours(int minutes);

double getRate(string vehicle, string vehicleType[], double rate[]);
double calculateDiscount(double charge, char member);

// Main Function

int main(){
    int entryTime, exitTime;
    string vehicleType;
    char membershipStatus;

    getInput(&entryTime, &exitTime, &vehicleType, &membershipStatus);

    cout << entryTime << exitTime << vehicleType << membershipStatus;

    return 0;
}

void getInput(int *ptrEntry, int *ptrExit, string *ptrVehicle, char *ptrMember){
    cout << "Enter Entry Time: ";
    cin >> *ptrEntry;

    cout << "Enter Exit Time: ";
    cin >> *ptrExit;

    cout << "Enter Vehicle Type (Car/Motorcycle/Van): ";
    cin >> *ptrVehicle;

    cout << "Enter Membership Status (T/F): ";
    cin >> *ptrMember;
}

int calculateDuration(int entry, int exit){

}


