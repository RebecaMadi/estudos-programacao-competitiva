#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * Aplicação de DP
 * Relação de recorrência da solução ótima:
 *  se  caractere Xm == Ym:
 *      Xm está na subsequencia
 *      soma o tamanho e armazena o caractere
 * senão:
 *      verifica quem é maior, andando uma casa para trás em X ou Y
 *      maior(msc[Xm-1, Ym], msc(Xm, Ym-1))
 * 
 * Pode haver mais de uma subsequencia
 * Uma subsequencia não necessariamente é uma sequencia
 * DP funciona de forma bottom-up, calculando cada parte até chegar no todo, ou seja, para cada valor que eu for calcular os valores antes dele já foram calculados
 * A "recursão" da programação dinâmica é pelo acesso direto do valor na matriz
*/

int main()
{
    string cepe, guidi;
    cin>>guidi;
    cin>>cepe;
    int m = guidi.size();
    int n = cepe.size();
    //soma nas diagonais, por isso m+1
    int mt[m+1][n+1];

    //preenche com zero
    for(int i=0; i<(m+1); i++){
        for(int j=0; j<n+1; j++){
            mt[i][j] = 0;
        }
    }

    for(int i=1; i<(m+1); i++){
        for(int j=1; j<n+1; j++){
            if(guidi[i-1]==cepe[j-1]){
                mt[i][j] = mt[i-1][j-1] + 1;
            }else{
                mt[i][j] = max(mt[i-1][j], mt[i][j-1]);
            }
        }
    }

    cout<<mt[m][n]<<endl;
    return 0;
}