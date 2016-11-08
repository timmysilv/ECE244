#include "Resistor.h"
#include <string>
#include <iomanip>

Resistor::Resistor(){}

Resistor::Resistor(string name_, double resistance_, int endpoints_[]){
    name = name_;
    resistance = resistance_;
    endpointNodeIDs[0] = endpoints_[0];
    endpointNodeIDs[1] = endpoints_[1];
}

Resistor::~Resistor(){
    delete next;
}

string Resistor::getName() const{
    return name;
}

double Resistor::getResistance() const{
    return resistance;
}

int* Resistor::getPoints(){
    return endpointNodeIDs;
}

Resistor* Resistor::getNext(){
    return next;
}

Resistor* Resistor::getPrev(){
    return prev;
}

void Resistor::setResistance(double resistance_){
    resistance = resistance_;
}

void Resistor::setName(string n){
    name = n;
}

void Resistor::setEndPoints(int ep[2]){
    endpointNodeIDs[0] = ep[0];
    endpointNodeIDs[1] = ep[1];
}

void Resistor::setPrev(Resistor* prev_){
    prev = prev_;
}

void Resistor::setNext(Resistor* next_){
    next = next_;
}

void Resistor::print(){ //Proper formatting for printing a resistor
    cout << left << setw(20) << name << " " << right << setw(8) << resistance <<
        " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;
}