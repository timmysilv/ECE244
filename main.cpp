#include <cstdlib>
#include <iostream>
#include "Rparser.h"
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"

using namespace std;

int main(int argc, char** argv) {
    Rparser parser;
    NodeList nodes;
    do{ //Loop the input request until EOF flag is sent
        string line;
        cout << "> ";
        getline(cin,line);
        parser.parse(line,nodes);
    }while(!cin.eof());
    nodes.clear();
}