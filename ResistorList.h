/* 
 * File:   ResistorList.h
 * Author: Matthew
 *
 * Created on November 6, 2016, 5:50 PM
 */

#ifndef RESISTORLIST_H
#define RESISTORLIST_H

#include "Resistor.h"
#include <string>

class ResistorList {
private:
    Resistor *head, *tail;
public:
    ResistorList();
    virtual ~ResistorList();
    Resistor* addResistor(Resistor *r);
    bool search(string name);
};

#endif /* RESISTORLIST_H */

