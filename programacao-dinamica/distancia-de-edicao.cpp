#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
Distancia de edição: numero minimo de edições para transformar uma string A em uma string B
Se Am==Bn:
    d(Am-1, Bn-1)
Se Am!=Bn:
    1 + min(d(Am-1, Bn), d(Am, Bn-1), d(Am-1, Bn-1))
*/


int main(){
    string A = "rebeca";
    string B = "receba";

    const int m = A.size();
    const int n = B.size();
    int mt[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            mt[i][j] = 0;
        }
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(A[i-1]==B[j-1]){
                mt[i][j] = mt[i-1][j-1];
            }else{
                mt[i][j] = 1 + min({mt[i-1][j], mt[i][j-1], mt[i-1][j-1]});
            }      
        }
    }

    cout<<mt[m][n]<<endl;    

    return 0;
}