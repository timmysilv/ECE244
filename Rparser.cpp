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

void Rparser::parse(string in, NodeList nodes){
    string cmd, name; //Function variable declarations
    double resistance;
    int nodeIn[2];
    double rOld; //Used in modifyR
    stringstream ss(in);
    ss >> cmd;
    
    if(cmd=="insertR"){ //Function to insert a resistor
        ss >> name;
        if(nodes.findR(name)){
            cout << "Error: resistor " << name << " already exists" << endl;
            ss.clear();
            return;
        }
        ss >> resistance;
        ss >> nodeIn[0];
        ss >> nodeIn[1];
        
        //Add the values to both the resistor and node arrays
        addR(name, resistance, nodeIn);
        nodes[nodeIn[0]].addResistor(rTotal); //Start node
        nodes[nodeIn[1]].addResistor(rTotal); //End node
        rTotal++; //Used frequently in Rparser
        
        cout<<"Inserted: resistor "<<name<<" "<<setprecision(2)<<fixed<<
                resistance<<" Ohms "<<nodeIn[0]<<" -> "<<nodeIn[1]<<endl;
    }
    else if(cmd=="modifyR"){ //Used to change an existing resistor's resistance
        ss >> name;
        for(int i=0;i<rTotal;i++) //Store the requested resistor's index
            if(resistors[i].getName()==name)
                index = i;
        
        //If the resistor was not found, index will still be default value, -1
        if(index==-1){
            cout << "Error: resistor " << name <<  " not found" << endl;
            ss.clear();
            return;
        }
        
        rOld = resistors[index].getResistance(); //Store for the output message
        ss >> resistance;
        resistors[index].setResistance(resistance);
        cout<<"Modified: resistor "<<name<<" from "<<setprecision(2)<<fixed<<rOld
            << " Ohms to " <<setprecision(2)<<fixed<<resistance<< " Ohms" << endl;
    }
    else if(cmd=="printR"){ //Print a single resistor, or all resistors
        ss >> name;
        if(name=="all"){ //Print all resistors
            cout << "Print:" << endl;
            for(int i=0; i<rTotal; i++)
                resistors[i].print();
        }
        else{
            for(int i=0;i<rTotal;i++) //Check that the resistor exists
                if(resistors[i].getName()==name)
                    index = i;
        
            //If the resistor was not found, index will still be default value, -1
            if(index==-1){
                cout << "Error: resistor " << name <<  " not found" << endl;
                ss.clear();
                return;
            }
            cout << "Print:" << endl;
            resistors[index].print();
        }
    }
    else if(cmd=="printNode"){ //Print a single node, or all nodes
        ss >> name;
        if(name=="all"){ //Loop through all nodes, print all connected resistors
            cout << "Print:" << endl;
            for(int i=0; i<=maxN; i++){
                //Need to pass the resistor array to each node
                //Important for Node::print(index);
                nodes[i].getArray(resistors);
                nodes[i].print(i);
            }
            return;
        }
        
        istringstream caster(name); //cast the str input to an int
        caster >> nodeIn[0];
        
        if((nodeIn[0]<0)||(nodeIn[0]>maxN)){ //Nodes must be in this range
            cout << "Error: node " << nodeIn[0] << OOR;
            ss.clear();
            return;
        }
        
        cout << "Print:" << endl; //Print a single node
        nodes[nodeIn[0]].getArray(resistors);
        nodes[nodeIn[0]].print(nodeIn[0]);
    }
    
    else if(cmd=="deleteR"){
        cout<<"Deleted: all resistors"<<endl;
        
        //Delete the old arrays
        delete [] resistors;
        delete [] nodes;
        
        //Rebuild the arrays with stored maximum values
        nodes = new Node[maxN+1];
        resistors = new Resistor[maxR];
        
        //Reset the resistor total (current index)
        rTotal=0;
    }
}