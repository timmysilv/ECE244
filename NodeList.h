/* 
 * File:   NodeList.h
 * Author: Matthew
 *
 * Created on November 6, 2016, 5:50 PM
 */

#ifndef NODELIST_H
#define NODELIST_H

#include "Node.h"

class NodeList {
private:
    Node *head,*tail;
public:
    NodeList();
    virtual ~NodeList();
    Node* addNode(Node *n);
    Node* search(int id);
    bool findR(string name);
};

#endif /* NODELIST_H */

