#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void siftDown( int *arr, int chave, int tam);

void swap(int *q, int *p)
{
	int tmp;
	tmp = *q;
	*q = *p;
	*p = tmp;
}

void heapsort( int arr[], int tam){

	for (int chave = tam/2; chave >= 0; chave--) {
		siftDown( arr, chave, tam);
	}

	while (tam-1 > 0) {
		swap(arr[tam-1], arr[0]);
		siftDown(arr, 0, tam-1);
		tam--;
	}
}

void siftDown( int *arr, int chave, int tam){
	while ( chave*2 + 1 < tam ) {
		/* filho da esqueda: 2*i+1 // filho da direita: 2*i+2 */
 		int filho = 2*chave + 1;

		/* se tiver dois filhos, pega o filho maior */
		if ((filho + 1 < tam) && (arr[filho] < arr[filho+1])) filho++;

		if (arr[chave] < arr[filho]) {
			swap( arr[filho], arr[chave] );
			chave = filho;
		}
		else
			return;
	}
}

int main(int argc, char** argv){
/*
int num,i;
   printf ("Qual sera o tamanho do seu Array? ");
   scanf("%d", &num) ;
int arr[num];
num = sizeof(arr)/sizeof(arr[0]);

   for(i = 0; i < num; i++){
      cout << (i + 1) << " - posicao: "; //vai adicionando os valores individualmente
      cin >> arr[i];
   }
	
   heapsort(arr,num);

   cout << endl;
    for(int i=0; i<num; i++)
       cout << arr[i] << " ";

    cout << endl;
    */
    if (argc>1){

    	cout << argv[0] << " " << argv[1]<< endl;;
    	string name(argv[1]);
    	ifstream file(argv[1]);
    	vector<int> arr;
    	string line;
    	while(!file.eof()){
    		getline(file,line);
    		arr.push_back(atoi(line.c_str()));
    	}

    	heapsort(&arr[0], arr.size());
    	ostringstream n;
    	string rep1("instancias/");
    	size_t f = name.find(rep1.c_str());
    	name.replace(f, rep1.length(), "");
    	n << "result/heapsort." << name;
    	ofstream dumpFile(n.str());
    	for(int i = 0; i < arr.size(); i++){
    		//cout << arr[i] << endl;
    		dumpFile << arr[i] << endl;
    	}
    }

    return 0;
}


