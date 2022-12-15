#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef patient_h
#define patient_h

//Patient Class
class patient {
public:
  int age;
  string name;
  long long phoneNumber;
  string reason;
  int priority;

  patient(int age, string name, long long phoneNumber, string reason, int priority) {
    this->age = age;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->reason = reason;
    this->priority = priority;
  }
};

//Patient Queue Class
class patientQueue {
  patient** elem;
  int capacity;
  int heap_size;
public:
  patientQueue(int capacity);
  int parent(int i) { return(i - 1) / 2; }
  int left(int i) { return (2 * i + 1); }
  int right(int i) { return (2 * i + 2); }

  void minHeapify(int i);
  void registerPatient(patient* patient);
  void removePatient();
  void queueLength();
  void highestPriorityPatient();
  void updatePriority(int phoneNum, int newPriority);
  void displayQueue();
};

#endif
