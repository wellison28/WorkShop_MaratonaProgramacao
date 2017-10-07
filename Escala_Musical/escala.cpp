#include <iostream>
#include <set>
#include <iterator>
using namespace std;
#define max 100000

int escalas[12][7];

// bool contem(int nota, int escala){
// 	for(int i = 0; i < 7; i++){
// 		cout << "Comparando " << nota << " " << escalas[escala][i] << endl;
// 		if(escalas[escala][i] == nota){	
// 			cout << "Nota: " << nota << " esta na escala Escala: " << escala << endl;		
// 			return true;
// 		}
// 	}
// 	cout << "Nota: " << nota << " não esta na escala Escala: " << escala << endl;
// 	return false;
//}

bool contem(int nota, int escala){
	for(int i = 0; i < 7; i++){
		if(escalas[escala][i] == nota){	
			return true;
		}
	}
	return false;
}


int main(){
	string tons[]{"do", "do#", "re", "re#", "mi", "fa", "fa#","sol", "sol#", "la", "la#", "si"};
	int escalaDo[]{1, 3, 5, 6, 8, 10, 0};	
	int N, aux, nota;
	int achei = -1;

	set<int> cj;
	set<int>::iterator it;

	//preenche primeira linha com do maior
	for(int i = 0; i < 7; i++)
		escalas[0][i] = escalaDo[i];

	//preenche resto da matriz
	for(int i = 0; i < 7; i++){
		for(int j = 1; j < 12; j++)
			escalas[j][i] = (escalas[j - 1][i] + 1) % 12;
	}

//	exibe matriz
	// for(int i = 0; i < 12; i++){
	// 	for(int j = 0; j < 7; j++)
	// 		cout << escalas[i][j] << " ";
	// 	cout << endl;
	// }

	cin >> N;

	//recebo a entrada e armazeno no set lembrando si = 0
	for(int i = 0; i < N; i++){
		cin >> aux;
		cj.insert(aux % 12);
	}

//	percorro set
	// for (it = cj.begin(); it != cj.end(); ++it){
	//  	cout << *it << " ";   
	// }cout << endl;

	// for(int i = 0; i < 12; i++){
	// 	for(int j = 0; j < 7; j++)
	// 		escalas[j][i] = escalas[j - 1][i] + 1;
	// }


	for(int escala = 0; escala < 12; escala++){
		for (it = cj.begin(); it != cj.end(); ++it){
		 	nota = *it;
		 	if (!contem(nota, escala)){	 		
		 		break;
		 	}
		}
		if(it == cj.end()){
			achei = escala;
			break;
		}
	}

	if (achei != -1)
		cout << tons[achei] << endl;
	else
		cout << "desafinado" << endl;

	//cout << cj.size() << endl;

	// cout << 60 % 12 << endl;
	// cout << 9 % 12 << endl;
	// cout << 29 % 12 << endl;
		
	return 0;
}