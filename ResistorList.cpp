/* 
 * File:   ResistorList.cpp
 * Author: Matthew
 * 
 * Created on November 6, 2016, 5:50 PM
 */

#include "ResistorList.h"

ResistorList::ResistorList() {
    head = NULL;
    tail = NULL;
    total = 0;
}

ResistorList::~ResistorList() {
    delete head;
}

void ResistorList::clear(){
    delete head;
}

void ResistorList::addResistor(Resistor* r){
    if(head==NULL){
        head = r;
        tail = r;
        return;
    }
    r->setPrev(tail);
    tail->setNext(r);
    tail = r;
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

void ResistorList::deleteR(string name){
    Resistor* temp = getR(name);
    if(temp==NULL) return; //Shouldn't happen, already checked
    if(temp==head){
        head = temp->getNext(); //Second is head
        head->setPrev(NULL);
        temp->setNext(NULL); //Don't want to delete the rest of the list
        delete temp;
        return;
    }
    if(temp==tail){
        tail = temp->getPrev();
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