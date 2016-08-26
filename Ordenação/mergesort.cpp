#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void merge(int *array, int tam1, int tam2) {
    int temp[tam1+tam2];
    int ptr1=0, ptr2=0;

    while (ptr1+ptr2 < tam1+tam2) {
        if (ptr1 < tam1 && array[ptr1] <= array[tam1+ptr2] || ptr1 < tam1 && ptr2 >= tam2)
            temp[ptr1+ptr2] = array[ptr1++];

        if (ptr2 < tam2 && array[tam1+ptr2] < array[ptr1] || ptr2 < tam2 && ptr1 >= tam1)
            temp[ptr1+ptr2] = array[tam1+ptr2++];
    }

    for (int i=0; i < tam1+tam2; i++)
        array[i] = temp[i];
}

void mergeSort(int *array, int tamanho) {
    if (tamanho == 1)
        return;

    int tam1 = tamanho/2, tam2 = tamanho-tam1;
    mergeSort(array, tam1);
    mergeSort(array+tam1, tam2);
    merge(array, tam1, tam2);
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

        mergeSort(&arr[0], arr.size());
        ostringstream n;
        string rep1("instancias/");
        size_t f = name.find(rep1.c_str());
        name.replace(f, rep1.length(), "");
        n << "result/mergeSort." << name;
        ofstream dumpFile(n.str());
        for(int i = 0; i < arr.size(); i++){
            //cout << arr[i] << endl;
            dumpFile << arr[i] << endl;
        }
    }
    return 0;
}
    /*
    int num;
    cout << "Qual sera o tamanho do seu Array? ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cout << (i + 1) << " - posicao: "; //vai adicionando os valores individualmente
        cin >> arr[i];
    }

    mergeSort(arr, num); //chamada de funçao

    cout << endl;
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}*/
