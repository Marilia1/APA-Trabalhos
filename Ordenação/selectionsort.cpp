#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void selectSort(int arr[], int n)
{
//contem menor numero
	int posicao_min,temp;

	for (int i=0; i < n-1; i++)
	{
      posicao_min = i;//coloca a posicao minima como indice do array

		for (int j=i+1; j < n; j++)
		{
		if (arr[j] < arr[posicao_min])
                   posicao_min=j;
	//posicao_min acompanhará o índice que é min, necessário quando acontece a troca
		}

	            if (posicao_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[posicao_min];
                 arr[posicao_min] = temp;
            }
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

      selectSort(&arr[0], arr.size());
      ostringstream n;
      string rep1("instancias/");
      size_t f = name.find(rep1.c_str());
      name.replace(f, rep1.length(), "");
      n << "result/selectsort." << name;
      ofstream dumpFile(n.str());
      for(int i = 0; i < arr.size(); i++){
        //cout << arr[i] << endl;
        dumpFile << arr[i] << endl;
      }
    }

    return 0;
}/*
    int num;
    std::cout << "Qual sera o tamanho do seu Array? ";
    std::cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        std::cout << (i + 1) << " - posicao: "; //vai adicionando os valores individualmente
        std::cin >> arr[i];
    }

    selectSort(arr, num); //chamada de funçao

    std::cout << endl;
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";

    std::cout << endl;

    return 0;
}*/
