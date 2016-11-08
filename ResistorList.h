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
    int total;
public:
    ResistorList();
    virtual ~ResistorList();
    void clear();
    void setHead(Resistor* r);
    void setTail(Resistor* r);
    void addResistor(Resistor* r);
    Resistor* getR(string name);
    int getSize();
    double inverseSum();
    int* getOtherNodes(int id);
    double* getResistors();
    void deleteR(string name);
    void printAll();
};

#endif /* RESISTORLIST_H */

