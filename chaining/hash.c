#include "hash.h"

static int words_in_text = 0;
static int wrong_words = 0;

unsigned int Hash(char* word) {

    	int size = strlen(word);
	int i;
	unsigned int value = 5381;

	for(i = 0; i < size; ++i) {

	    value += (value << 5)  + word[i];

	}

	return value;
}

void InitHashTable(HashTable h) {

    unsigned int i;

    for (i = 0; i < length; ++i)
        h[i] = NULL;

}

void LoadDictionary(HashTable h) {

	FILE* f = fopen("ascii.txt", "r");
    	char teste[words];
	
	char* p1 = NULL;

	if(f == NULL) {

		fprintf(stderr, "failed to open input.\n");

	}else{
        
        	while(fscanf(f, "%s", teste) != EOF){

			int tam = strlen(teste) + 1;
				
			p1 = malloc(sizeof(char) * tam);

			strcpy(p1, teste);

           		ChainedInsert(h, p1);

		}
		
	}

	fclose(f);

	printf("=======================================================\n");

}

void ChainedInsert(HashTable h, char* word) {

	int index = (Hash(word) % length);

   	struct Sll* list = NULL;

    	if(h[index] == NULL) {

		list = CreateNode();

		h[index] = list;
		
		Prepend(list, word);

	}else {

		list = h[index];
		
		Prepend(list, word);

	}

}

int ChainedSearch(HashTable h, char* word) {
	
	int index = (Hash(word) % length);

	if(h[index] != NULL) {

		const struct Sll* list = h[index];

		const struct Node* aux = list->head;

		while (aux != NULL) {

			if((strcmp(aux->word, word)) == 0) {
				
				return 1;
			}
			
			aux = aux->next;

		}

	}

	return 0;

}

void DestroyHashTable(HashTable h) {

	FILE* f = fopen("ascii.txt", "r");
   	char teste[words];

	if(f == NULL) {

		fprintf(stderr, "failed to open input.\n");

	}else{

		char* p1 = NULL;
        
        	while(fscanf(f, "%s", teste) != EOF){

			int tam = strlen(teste) + 1;
				
			p1 = malloc(sizeof(char) * tam);

			strcpy(p1, teste);

            		EndProgram(h, p1);

			free(p1);

		}
	
	}

	fclose(f);

}

void EndProgram(HashTable h, char* word) {

	int index = (Hash(word) % length);

	if(h[index] != NULL) {

		struct Sll* list = h[index];

		DestroyList(list);
		h[index] = NULL;

	}

}

void PrintHashTable(HashTable h) {

	int i;

	for(i = 0; i < length; ++i) {

		struct Sll* list = h[i];

		if(list != NULL) {

			PrintList(list, i);
        	}
	}

}

void Searching(HashTable h, char* file) {

	char teste[words];
	char* results;
	char* token;

	struct Sll* list = CreateNode();

	double tempo;

	clock_t t0, tf;

	FILE* p = fopen(file, "r");

	if(p == NULL) {

		fprintf(stderr, "failed to open input.\n");

		fclose(p);

	}else {

		t0 = clock();
		
		while(!feof(p)) {

			results = fgets(teste, sizeof(teste), p);
			
			token = strtok(results," -,.!'\n'");

			while(token != NULL) {

				int flag = ChainedSearch(h, token);

				++words_in_text;

				if(flag == 0) {

					++wrong_words;
					
					WrongWords(list, token);
				}

				token = strtok(NULL," -,.!'\n'"); 
	
			}

		}

		tf = clock();

	}

	fclose(p);

	tempo = ((double) (tf - t0)) / (CLOCKS_PER_SEC/1000);

	FILE* resultado = fopen("resultado.txt", "w");

	fprintf(resultado, "Numero total de palavras do texto: %i\n", words_in_text);
	fprintf(resultado, "Tempo total de verificacao: %lf ms\n", tempo);
	fprintf(resultado, "Numero de palavras que falharam no spell checker: %i\n", wrong_words);
	fprintf(resultado, "lista de palavras que falharam\n");
	fprintf(resultado, "Num. Ocorrencia - Palavra\n");

	struct Node* aux = list->head;

	int k = 1;

	for(int i = 0; i < list->size; ++i) {

		while(aux != NULL) {
		
			fprintf(resultado, "%i. %s\n", k, aux->palavra);
			aux = aux->next;
			++k;
		}

	}

	DestroyList(list);

}
