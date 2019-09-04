#include "hashtable.h"

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

    Hashtable h = Hashtable();

    vector<string> wrong_words;

    int words_in_text = 0;
    double tempo;
    clock_t t0, tf;

    h.LoadDictionary("ascii.txt");

    ofstream result("result.txt");

    t0 = clock();

    string word;

    ifstream text("constituicao.txt");

    if(text.is_open()) {

        while(text >> word) {

            ++words_in_text;

            if(h.table.find(word) == h.table.end()) {

                // printf("nao achou\n");
                wrong_words.push_back(word);

            }
            
        }

    }

    tf = clock();

    tempo = ( (double) (tf - t0) ) / (CLOCKS_PER_SEC/1000);

    result<<"Número total de palavras do texto:"<< words_in_text <<"\n";
    result<<"Tempo total da verificação:"<< tempo <<"ms"<<"\n";
    result<<"Número de palavras que falharam no spell check:"<< wrong_words.size() << "\n";
    result<<"Lista de palavras que falharam no spell check:\n";
    result<<"Num. Ocorrencia - Palavra\n";

for(int i = 0; i < wrong_words.size();i++)
    result<< i+1<<" - "<< wrong_words[i]<<"\n";

    return 0;
}
