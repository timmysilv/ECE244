
#include "Node.h"
#include "Resistor.h"

Node::Node(int id_){
    id = id_;
    voltage=0;
    set=false;
    next = NULL;
    prev = NULL;
}

Node::Node(int id_, int voltage_, bool set_, Node *prev_, Node *next_){
    id = id_;
    voltage = voltage_;
    set = set_;
    prev = prev_;
    next = next_;
}

Node::~Node(){
    rl.clear();
    delete next;
}

void Node::addResistor(Resistor* r){
    rl.addResistor(r);
}

int Node::getID(){
    return id;
}

Node* Node::getNext(){
    return next;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setNext(Node* next_){
    next = next_;
}

void Node::setPrev(Node* prev_){
    prev = prev_;
}

Resistor* Node::getR(string name){
    return rl.getR(name);
}

double Node::modifyR(string name, double r){
    Resistor* mod = getR(name);
    mod->setResistance(r);
}

void Node::deleteR(string name){
    rl.deleteR(name);
}

void Node::print(){
    cout << "Connections at node " << id << ": " 
        << rl.getSize() << " resistor(s)" << endl;
    rl.printAll();
}
