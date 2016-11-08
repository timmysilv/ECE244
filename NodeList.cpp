/* 
 * File:   NodeList.cpp
 * Author: Matthew
 * 
 * Created on November 6, 2016, 5:50 PM
 */

#include "NodeList.h"
#define MIN_ITERATION_CHANGE 0.0001

NodeList::NodeList() {
    setHead(NULL);
    setTail(NULL);
}

NodeList::~NodeList(){
    clear();
}

void NodeList::clear(){
    delete head;
    setHead(NULL);
    setTail(NULL);
}

void NodeList::setHead(Node* n){
    head = n;
}

void NodeList::setTail(Node* n){
    tail = n;
}

Node* NodeList::findAddNode(int id){
    if(head==NULL){
        Node* n = new Node(id);
        setHead(n);
        setTail(n);
        return head;
    }
    for(Node* cur = head; cur!=NULL; cur=cur->getNext()){
        if(cur->getID()==id) return cur;
        if(cur->getID()>id){ //n location is found
            Node* n = new Node(id);
            n->setPrev(cur->getPrev());
            //cur->getPrev() would be NULL if cur is head
            if(cur==head) head = n;
            else (n->getPrev())->setNext(n);
            n->setNext(cur);
            cur->setPrev(n);
            return n;
        }
        else if(cur==tail){ //n is the largest in the list
            Node* n = new Node(id);
            cur->setNext(n);
            n->setPrev(cur);
            setTail(n);
            return n;
        }
    }
}

Node* NodeList::search(int id){
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        if(cur->getID()==id) return cur;
    return NULL;
}

double* NodeList::getOthersV(Node* cur){ //Returns voltage array
    int* others = cur->getOtherNodes(); //List of nodes linked to cur
    double* othersV;
    int count = 0;
    while(others[count]!=-1){
        othersV[count] = search(others[count])->getV();
        count++;
    }
    othersV[count] = -1;
    return othersV;
}

void NodeList::solve(){
    double minChange = 1;
    double vi,vTemp;
    double* othersV, *othersR;
    double iSum,rSum; // V/R sum term, 1/(1/Ri) sum term
    int count = 0;
    
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        if(!cur->isSet()) cur->setV(0);
    
    while((minChange>MIN_ITERATION_CHANGE)){
        for(Node* cur = head; cur!=NULL; cur=cur->getNext()){
            if(!cur->isSet()){
                othersV = getOthersV(cur);
                othersR = cur->getResistors();
                rSum = cur->inverseSum();
                vi = cur->getV();
                iSum=0;
                for(count = 0; othersV[count]!=-1; count++)
                    iSum+=(othersV[count]/othersR[count]);
                vTemp = iSum*rSum;
                cur->setV(vTemp);
                vTemp-=vi;
                if(vTemp<0) vTemp*=-1;
                if(vTemp<minChange) minChange = vTemp;
            }
        }
    }
    
    cout << "Solve:" << endl;
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        cout<<"  Node "<<cur->getID()<<": "<<cur->getV()<<" V"<<endl;
}

bool NodeList::unknown(){
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        if(cur->isSet()) return false;
    return true;
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
    for(Node* cur = head; cur!=NULL; cur=cur->getNext())
        cur->print();
}