#ifndef NODE_H
#define NODE_H
#include "Resistor.h"
#include "ResistorList.h"

class Node
{
private:
   int id;
   double voltage;
   bool set;
   ResistorList rl;
   Node *prev,*next;
public:
   Node(int id_);
   Node(int id_, double voltage_, bool set_, Node *prev_, Node *next_);
   ~Node();
   void addResistor(Resistor* r);
   int getID();
   Node* getNext();
   Node* getPrev();
   
   void setPrev(Node *prev_);
   void setNext(Node *next_);
   void setV(double voltage_);
   void forceSet();
   void unsetV();
   bool isSet();
   int* getOtherNodes();
   double* getResistors();
   double inverseSum();
   double getV();
   double modifyR(string name, double r);
   void deleteR(string name);
   Resistor* getR(string name);
   void print(); 
};

#endif	/* NODE_H */