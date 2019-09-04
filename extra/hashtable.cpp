#include "hashtable.h"

Hashtable::Hashtable() {

}

Hashtable::~Hashtable() {

}

void Hashtable::LoadDictionary(char* text) {
   
    string lines;
    
    ifstream myfile(text);

    if (myfile.is_open()){

        while ( myfile>>lines ) {

            int tam = lines.length() + 1 ;

            char *char_array = new char[tam];	
            strcpy(char_array,&lines[0]);
            
            this->table.insert(make_pair(char_array, char_array));

        }
        
        myfile.close();
        
    }
}

