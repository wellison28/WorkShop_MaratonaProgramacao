#include <iostream>
#include <string>
using namespace std;


int convert(char c){
	return c - 48;
}

int main(){
	string numero;
	int soma = 0;
	int ultimo;
	int tam;

	cin >> numero;

	tam = numero.size();

	for(int i = 0; i < tam; i++){
		soma += convert(numero[i]);
	}

	ultimo = convert(numero[tam - 1]);

	cout << soma % 3 << endl;

	return 0;
}