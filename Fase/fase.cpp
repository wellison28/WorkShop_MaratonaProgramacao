#include <iostream>
using namespace std;
#define max 1010

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a);
}

int main(){
	// N : Competidores
	// K : Classificados
	int N, K, count = 0, corte, atual;
	int vetor[max];

	cin >> N >> K;

	for(int i = 0; i < N; i++)
		cin >> vetor[i];
	
	qsort (vetor, N, sizeof(int), compare);

	corte = vetor[K - 1];
	
	for(int i = K; i < N; i++){
		//cout << "corte: " << corte << " - pos: " << vetor[i] << i << endl;
		if (corte == vetor[i])
				count++;
	}

	// for(int i = 0; i < N; i++)
	// 	cout << vetor[i];
	// cout << endl;
	
	cout << K + count << endl;

	return 0;
}

