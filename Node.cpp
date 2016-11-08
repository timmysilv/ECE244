
#include "Node.h"
#include "Resistor.h"

Node::Node(int id_){
    id = id_;
    voltage=0;
    set=false;
    next = NULL;
    prev = NULL;
}

Node::Node(int id_, double voltage_, bool set_, Node *prev_, Node *next_){
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

void Node::setV(double voltage_){
    voltage = voltage_;
}

void Node::forceSet(){
    set = true;
}

void Node::unsetV(){
    set = false;
    voltage = 0;
}

bool Node::isSet(){
    return set;
}

int* Node::getOtherNodes(){
    return rl.getOtherNodes(id);
}

double* Node::getResistors(){
    return rl.getResistors();
}

double Node::inverseSum(){
    return rl.inverseSum();
}

double Node::getV(){
    return voltage;
}

Resistor* Node::getR(string name){
    return rl.getR(name);
}

double Node::modifyR(string name, double r){
    Resistor* mod = getR(name);
    double val = mod->getResistance();
    mod->setResistance(r);
    return val;
}

void Node::deleteR(string name){
    rl.deleteR(name);
}

void Node::print(){
    cout << "Connections at node " << id << ": " 
        << rl.getSize() << " resistor(s)" << endl;
    rl.printAll();
}
