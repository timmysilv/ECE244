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

Node* NodeList::findAddNode(int id){
    if(head==NULL){
        Node* n = new Node(id);
        head = n;
        tail = n;
        return head;
    }
    for(Node* cur = head; cur!=NULL; cur=cur->getNext()){
        if(cur->getID()==id) return cur;
        if(cur->getID()>id){ //n location is found
            Node* n = new Node(id);
            n->setPrev(cur->getPrev());
            (n->getPrev())->setNext(n);
            n->setNext(cur);
            cur->setPrev(n);
            return n;
        }
        else if(cur==tail){ //n is the largest in the list
            Node* n = new Node(id);
            cur->setNext(n);
            n->setPrev(cur);
            tail = n;
            return n;
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