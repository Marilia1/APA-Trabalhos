#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void quicksort(int arr[], int esquerda, int direita){
    int pivo = esquerda, i, chave, j;
    for(i = esquerda + 1; i <= direita; i++){
        j = i;
        if(arr[j] < arr[pivo]){
         chave = arr[j];
         while(j > pivo){
            arr[j] = arr[j-1];
            j--;
         }
         arr[j] = chave;
         pivo++;
        }
    }
    if(pivo-1 >= esquerda){
        quicksort(arr,esquerda,pivo-1);
    }
    if(pivo+1 <= direita){
        quicksort(arr,pivo+1,direita);
    }
 }

int main(int argc, char** argv) {
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

        quicksort(&arr[0],0, arr.size()-1);
        ostringstream n;
        string rep1("instancias/");
        size_t f = name.find(rep1.c_str());
        name.replace(f, rep1.length(), "");
        n << "result/quicksort." << name;
        ofstream dumpFile(n.str());
        for(int i = 0; i < arr.size(); i++){
            //cout << arr[i] << endl;
            dumpFile << arr[i] << endl;
        }
    }

    return 0;
}/*
    int num,i;
    printf ("Qual sera o tamanho do seu Array? ");
    scanf("%d", &num) ;
    int arr[num];

    for(i = 0; i < num; i++){
      cout << (i + 1) << " - posicao: "; //vai adicionando os valores individualmente
      cin >> arr[i];
   }

   quicksort(arr,0,num-1);

   cout << endl;
    for(int i=0; i<num; i++)
       cout << arr[i] << " ";

    cout << endl;
    return 0;
}*/
