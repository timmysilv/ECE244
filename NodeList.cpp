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
    delete head;
}

void NodeList::clear(){
    delete head;
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

Resistor* NodeList::getR(string name){
    for(Node* cur = head; cur!=NULL; cur=cur->getNext()){
        if(cur->getR(name)!=NULL) 
            return (cur->getR(name));
    }
    return NULL;
}

int* NodeList::getPoints(string rName){
    Resistor* temp = getR(rName);
    if(temp==NULL) return NULL;
    else return temp->getPoints();
}

void NodeList::printAll(){
    cout << "Print: " << endl;
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        cur->print();
}