#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void inserionSort (int array[], int tamanho){//função que ordena vetor
   int i, j, aux;
   for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                  aux = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = aux;
                  j--;
            }
      }
}
int main(int argc, char** argv) {
  /*
    int num;
    std::cout << "Qual sera o tamanho do seu Array? ";
    std::cin >> num;
    int array[num];
    for (int i = 0; i < num; i++) {
        std::cout << (i + 1) << " - posicao: "; //vai adicionando os valores individualmente
        std::cin >> array[i];
    }

    inserionSort(array, num); //chamada de funçao

    std::cout << endl;
    for (int i = 0; i < num; i++)
        cout << array[i] << " ";

    std::cout << endl;

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

      inserionSort(&arr[0], arr.size());
      ostringstream n;
      string rep1("instancias/");
      size_t f = name.find(rep1.c_str());
      name.replace(f, rep1.length(), "");
      n << "result/inserionsort." << name;
      ofstream dumpFile(n.str());
      for(int i = 0; i < arr.size(); i++){
        //cout << arr[i] << endl;
        dumpFile << arr[i] << endl;
      }
    }

    return 0;
}
