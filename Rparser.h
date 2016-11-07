/* 
 * File:   RParser.h
 * Author: masil
 *
 * Created on October 13, 2016, 8:04 PM
 */

#ifndef RPARSER_H
#define RPARSER_H
#include <string>
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"
#include "ResistorList.h"

using namespace std;

class Rparser{
private:  
public:
    Rparser();
    ~Rparser();
    void parse(string in, NodeList& nodes);
};

#endif /* RPARSER_H */

