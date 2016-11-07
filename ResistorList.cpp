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
}

ResistorList::~ResistorList() {
    delete head;
}

void ResistorList::addResistor(Resistor& r){
    if(head==NULL){
        head = r;
        tail = r;
        return head;
    }
    r->setPrev(tail);
    tail->setNext(r);
    tail = r;
    return head;
}

bool ResistorList::search(string name){
    for(Resistor *cur = head; cur!=NULL; cur = cur->getNext())
        if(cur->getName()==name) return true;
    return false;
}