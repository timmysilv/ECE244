/* 
 * File:   ResistorList.cpp
 * Author: Matthew
 * 
 * Created on November 6, 2016, 5:50 PM
 */

#include "ResistorList.h"

ResistorList::ResistorList() {
    setHead(NULL);
    setTail(NULL);
    total = 0;
}

ResistorList::~ResistorList() {
    clear();
}

void ResistorList::clear(){
    delete head;
    setHead(NULL);
    setTail(NULL);
    total = 0;
}

void ResistorList::setHead(Resistor* r){
    head = r;
}

void ResistorList::setTail(Resistor* r){
    tail = r;
}

void ResistorList::addResistor(Resistor* r){
    if(head==NULL){
        setHead(r);
        setTail(r);
        total++;
        return;
    }
    r->setPrev(tail);
    tail->setNext(r);
    setTail(r);
    total++;
    return;
}

Resistor* ResistorList::getR(string name){
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext())
        if(cur->getName()==name) return cur;
    return NULL;
}

int ResistorList::getSize(){
    return total;
}

double ResistorList::inverseSum(){
    double sum;
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext())
        sum += (1/(cur->getResistance()));
    return (1/sum);
}

int* ResistorList::getOtherNodes(int id){
    if(head==NULL) return NULL;
    int* otherNodes;
    int count = 0;
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext()){
        if(id==cur->getP1())
            otherNodes[count] = cur->getP2();
        else
            otherNodes[count] = cur->getP1();
        count++;
    }
    otherNodes[count] = -1; //To stop at higher level
    return otherNodes;
}

double* ResistorList::getResistors(){
    if(head==NULL) return NULL;
    int count=0;
    double* resVals;
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext()){
        resVals[count] = cur->getResistance();
        count++;
    }
    return resVals;
}

void ResistorList::deleteR(string name){
    Resistor* temp = getR(name);
    if(temp==NULL) return; //Shouldn't happen, already checked
    total--;
    if(temp==head){
        setHead(temp->getNext()); //Second is head
        head->setPrev(NULL);
        temp->setNext(NULL); //Don't want to delete the rest of the list
        delete temp;
        return;
    }
    if(temp==tail){
        setTail(temp->getPrev());
        delete temp; //next is NULL, no problem
        tail->setNext(NULL);
        return;
    }
    (temp->getPrev())->setNext(temp->getNext());
    (temp->getNext())->setPrev(temp->getPrev());
    temp->setNext(NULL);
    delete temp;
}

void ResistorList::printAll(){
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext())
        cur->print();
}