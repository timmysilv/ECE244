#ifndef RESISTOR_H
#define RESISTOR_H

#include <string>
#include <iostream>
using namespace std;

class Resistor
{
private:
   double resistance;
   string name;
   int endpointNodeIDs[2]; // IDs of nodes it attaches to
   Resistor *prev,*next;
   
public:
   Resistor();
   Resistor(string name_,double resistance_,int endpoints_[2]);
   ~Resistor();
   
   string getName() const;
   double getResistance() const;
   Resistor* getNext();
   
   void setResistance (double resistance_);
   void setName(string n);
   void setEndPoints(int *ep);
   void setPrev(Resistor *prev_);
   void setNext(Resistor *next_);
   void print ();
};

#endif	/* RESISTOR_H */