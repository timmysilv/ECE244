/* 
 * File:   NodeList.cpp
 * Author: Matthew
 * 
 * Created on November 6, 2016, 5:50 PM
 */

#include "NodeList.h"

NodeList::NodeList() {
    head = NULL, tail = NULL;
}

NodeList::~NodeList() {
}

Node* NodeList::addNode(Node* n){
    if(head==NULL){
        head = n;
        tail = n;
        return head;
    }
    for(Node* cur = head; cur!=NULL; cur=cur->getNext()){
        if(cur->getID()==n->getID()) return ;
        if(cur->getID()>n->getID()){ //n location is found
            n->setPrev(cur->getPrev());
            (n->getPrev())->setNext(n);
            n->setNext(cur);
            cur->setPrev(n);
        }
        else if(cur==tail){ //n is the largest in the list
            cur->setNext(n);
            n->setPrev(cur);
            n->setNext(NULL);
            tail = n;
        }
    }
}

Node* NodeList::search(int id){
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        if(cur->getID()==id) return cur;
    return NULL;
}

bool NodeList::findR(string name){
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        if(cur->findR(name)) return true;
    return false;
}