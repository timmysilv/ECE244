/* 
 * File:   RParser.cpp
 * Author: masil
 *
 * Created on October 2, 2016, 5:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Rparser.h"
using namespace std;

/*4 errors:
 * Error: no nodes have their voltage set -- when solve is called
 * Error: resistor 'name' not found -- modify/print/delete
 * Error: resistor 'name' already exists -- adding a resistor
 * Error: node 'id' not found // setting/unsetting
*/

Rparser::Rparser(){}

Rparser::~Rparser(){} //Destructor

void Rparser::parse(string in, NodeList& nodes){
    string cmd, name; //Function variable declarations
    double resistance;
    int nodeIn[2];
    double rOld; //Used in modifyR
    stringstream ss(in);
    ss >> cmd;
    
    if(cmd=="insertR"){ //Function to insert a resistor
        ss >> name;
        if(nodes.getR(name)!=NULL){
            cout << "Error: resistor " << name << " already exists" << endl;
            ss.clear();
            return;
        }
        ss >> resistance;
        ss >> nodeIn[0];
        ss >> nodeIn[1];
        Resistor* temp1 = new Resistor(name,resistance,nodeIn);
        Resistor* temp2 = new Resistor(name,resistance,nodeIn);
        Node* n1 = nodes.findAddNode(nodeIn[0]);
        Node* n2 = nodes.findAddNode(nodeIn[1]);
        n1->addResistor(temp1);
        n2->addResistor(temp2);
        
        cout<<"Inserted: resistor "<<name<<" "<<setprecision(2)<<fixed<<
                resistance<<" Ohms "<<nodeIn[0]<<" -> "<<nodeIn[1]<<endl;
    }
    else if(cmd=="modifyR"){ //Used to change an existing resistor's resistance
        ss >> name;
        int* points = nodes.getPoints(name);
        if(points==NULL){
            cout << "Error: resistor " << name <<  " not found" << endl;
            ss.clear();
            return;
        }
        
        Node* n1 = nodes.search(points[0]);
        Node* n2 = nodes.search(points[1]);
        
        ss >> resistance;
        
        rOld = n1->modifyR(name,resistance);
        n2->modifyR(name,resistance);
        
        cout<<"Modified: resistor "<<name<<" from "<<setprecision(2)<<fixed<<rOld
            << " Ohms to " <<setprecision(2)<<fixed<<resistance<< " Ohms" << endl;
    }
    else if(cmd=="printR"){
        ss >> name;
        Resistor* temp = nodes.getR(name);
        if(temp==NULL){
            cout << "Error: resistor " << name << " not found" << endl;
            ss.clear();
            return;
        }
        cout << "Print:" << endl;
        temp->print();
    }
    else if(cmd=="printNode"){ //Print a single node, or all nodes
        ss >> name;
        if(name=="all"){
            cout << "Print:" << endl;
            nodes.printAll();
            return;
        }
        
        istringstream caster(name); //cast the str input to an int
        caster >> nodeIn[0];
        
        Node* temp = nodes.search(nodeIn[0]);
        if(temp==NULL){
            cout << "Error: node " << nodeIn[0] << " not found" << endl;
            ss.clear();
            return;
        }
        
        cout << "Print:" << endl; //Print a single node
        temp->print();
    }
    
    else if(cmd=="deleteR"){
        ss >> name;
        if(name=="all"){
            cout<<"Deleted: all resistors"<<endl;
            nodes.clear();
            return;
        }
        
        int* points = nodes.getPoints(name);
        if(points==NULL){
            cout << "Error: resistor " << name <<  " not found" << endl;
            ss.clear();
            return;
        }
        
        Node* n1 = nodes.search(points[0]);
        Node* n2 = nodes.search(points[1]);
        
        n1->deleteR(name);
        n2->deleteR(name);
        
        cout << "Deleted: resistor " << name << endl;
    }
    else if(cmd=="setV"){ //Make set = true, update its voltage
        //Set: node 'id' to 'voltage' Volts
    }
    else if(cmd=="unsetV"){ //Make set = false, voltage is unknown
        //Unset: the solver will determine the voltage of node 'id'
    }
    else if(cmd=="solve"){ //Solve for all with set = false
        //Solve:
    }
    ss.clear();
}