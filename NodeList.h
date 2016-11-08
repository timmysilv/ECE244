/* 
 * File:   NodeList.h
 * Author: Matthew
 *
 * Created on November 6, 2016, 5:50 PM
 */

#ifndef NODELIST_H
#define NODELIST_H

#include "Node.h"
#include "Resistor.h"

class NodeList {
private:
    Node *head,*tail;
public:
    NodeList();
    virtual ~NodeList();
    void clear();
    void setHead(Node* n);
    void setTail(Node* n);
    Node* findAddNode(int id);
    Node* search(int id);
    Resistor* getR(string name);
    int* getPoints(string rName);
    void printAll();
};

#endif /* NODELIST_H */

