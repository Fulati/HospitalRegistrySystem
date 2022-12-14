#include <iostream>
#include <string>
using namespace std;

#include "patient.h"

int main()
{
  string input, name, reason;
  int age, priority;
  long long phoneNumber;
  patientQueue pq(20);

  //The Menu
  cout << "-----------Menu-----------" << endl;
  cout << "1. Register Patient" << endl;
  cout << "2. Remove Treated Patient" << endl;
  cout << "3. Number of Patients" << endl;
  cout << "4. Highest Priority Patient info" << endl;
  cout << "5. Change Patient's Priority" << endl;
  cout << "6. Display Patients Queue" << endl;
  cout << "0. Exit" << endl;
  cout << endl;

  while (input != "0") {
    cout << endl;
    cout << "Select an option from the MENU!  ";
    cin >> input;
    cout << endl;

    //Register Patient
    if (input == "1") {
      cout << "Patient age:  ";
      cin >> age;
      cin.ignore(1000, '\n');

      cout << "Patient name:  ";
      getline(cin, name);

      cout << "Patient phone number:  ";
      cin >> phoneNumber;
      cin.ignore(1000, '\n');

      cout << "Patient reason:  ";
      getline(cin, reason);

      cout << "Patient priority:  ";
      cin >> priority;
      cin.ignore(1000, '\n');

      patient* p = new patient(age, name, phoneNumber, reason, priority);
      pq.registerPatient(p);
    }

    //Remove Patient after done
    else if (input == "2") {
      pq.removePatient();
    }

    //Number of Patients in Queue
    else if (input == "3") {
      pq.queueLength();
    }

    //Highest Priority Patient info
    else if (input == "4") {
      pq.highestPriorityPatient();
    }

    //Change Patient's Priority
    else if (input == "5") {

      cout << "Patient phone number: ";
      cin >> phoneNumber;
      cin.ignore(1000, '\n');

      cout << "Patient new priority:  ";
      cin >> priority;
      cin.ignore(1000, '\n');

      pq.updatePriority(phoneNumber, priority);
    }

    //Display Patient's Queue
    else if (input == "6") {
      pq.displayQueue();
    }

    //Wrong input
    else if (input != "0") {
      cout << "Please select options 1-6 from the MENU" << endl;
    }
  }
}

