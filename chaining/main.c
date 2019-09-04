#include "hash.h"

/*
    Universidade Federal da Paraíba

    Trabalho da disciplina de Estrutura de Dados

    Tema: SpellChecker

    Linguagens Utilizadas: C e C++.

    Desenvolvido por:
    
        Danilo Henrique, 20170140478
        ítalo Nicácio, 20170118996
        Vinicius dos Santos, 20180046756 

*/

int main(void) {

    HashTable h;

    InitHashTable(h);

    LoadDictionary(h);

    Searching(h, "constituicao.txt");

    DestroyHashTable(h);
    
    return 0;
}
