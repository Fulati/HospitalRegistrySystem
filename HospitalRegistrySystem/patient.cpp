#include <iostream>
#include <string>
using namespace std;

#include "patient.h"

//patientQueue Constructor
patientQueue::patientQueue(int capacity) {
  this->capacity = capacity;
  this->heap_size = 0;
  elem = new patient * [capacity];
}

//Min Heap
void patientQueue::minHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;

  if (l < heap_size && elem[l]->priority < elem[i]->priority) {
    smallest = l;
  }
  if (r < heap_size && elem[r]->priority < elem[smallest]->priority) {
    smallest = r;
  }
  if (smallest != i) {
    swap(elem[i], elem[smallest]);
    minHeapify(smallest);
  }
}

//Register Patient
void patientQueue::registerPatient(patient* patient) {
  if (heap_size == capacity) {
    cout << "\nOverflow: Couldn't register the patient\n";
    return;
  }

  this->elem[heap_size] = patient;
  heap_size++;
  int i = heap_size - 1;

  while (i != 0 && elem[parent(i)]->priority > elem[i]->priority) {
    swap(elem[i], elem[parent(i)]);
    i = parent(i);
  }
  cout << "Patient registered!!!" << endl;
}

//Remove Patient
void patientQueue::removePatient() {
  if (heap_size == 0) {
    cout << "There are no patient in queue!" << endl;
    return;
  }
  if (heap_size == 1) {
    heap_size--;
    patient* tmp = elem[heap_size];
    cout << tmp->name << " has been treated" << endl;
    return;
  }

  patient* tmp = elem[0];
  elem[0] = elem[heap_size - 1];
  heap_size--;
  minHeapify(0);

  cout << tmp->name << " has been treated" << endl;
}

//Queue Length
void patientQueue::queueLength() {
  if (heap_size == 0) {
    cout << "There are no patient in queue!" << endl;
  }
  else {
    cout << "There are " << heap_size << " patients in queue!" << endl;
  }
}

//Highest Priority Patient
void patientQueue::highestPriorityPatient() {
  if (heap_size == 0) {
    cout << "There are no patient in queue!" << endl;
  }
  else {
    cout << elem[0]->name << ", age " << elem[0]->age << ", phone number: " << elem[0]->phoneNumber << ", is the highest priority patient with priority #" << elem[0]->priority << endl;
  }
}

//Update Priority of Patient
void patientQueue::updatePriority(int phoneNum, int newPriority) {
  if (heap_size == 0) {
    cout << "There are no patients in queue!" << endl;
  }
  else {
    for (int i = 0;i < heap_size;i++) {
      if (elem[i]->phoneNumber == phoneNum) {
        elem[i]->priority = newPriority;
        cout << "Patient priority updated!" << endl;
        while (i != 0 && elem[parent(i)]->priority > elem[i]->priority) {
          swap(elem[i], elem[parent(i)]);
          i = parent(i);
        }
        return;
      }
    }
    cout << "There are no patient with such phone number!" << endl;
  }
}

//Display the Queue
void patientQueue::displayQueue() {
  if (heap_size == 0) {
    cout << "There are no patient in queue!" << endl;
  }
  else {
    cout << "Patient Queue: " << endl;
    for (int i = 0;i < heap_size;i++) {
      cout << elem[i]->name << ", age " << elem[i]->age << ", phone number: " << elem[i]->phoneNumber << " has priority " << elem[i]->priority << " due to " << elem[i]->reason << endl;
    }
  }
}
