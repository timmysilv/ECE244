#ifndef NODE_H
#define NODE_H
#include "Resistor.h"
#include "ResistorList.h"

class Node
{
private:
   int id,voltage,set;
   ResistorList rl;
   Node *prev,*next;
public:
   Node(int id_);
   Node(int id_, int voltage_, int set_, Node *prev_, Node *next_);
   ~Node();
   void addResistor(Resistor *r);
   int getID();
   Node* getNext();
   Node* getPrev();
   
   void setPrev(Node *prev_);
   void setNext(Node *next_);
   bool findR(string name);
   void print(int nodeIndex); 
};

#endif	/* NODE_H */