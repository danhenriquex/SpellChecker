#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Hashtable {
         
    public:
        void LoadDictionary(char* text);
	unordered_map<string, string> table;
        Hashtable();
        ~Hashtable();
};

#endif
