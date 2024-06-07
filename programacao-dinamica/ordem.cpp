#include <iostream>
#define inf 100000000
using namespace std;

/*
Encontrar a melhor ordem de multiplicação de matrizes

Encontrar a sequencia otima de multiplicação de matrizes
Encontar a solução ótima para M[i,j] que é a solução ótima de:
M(i,k] + M[k+1,j] + di-1.dk.dj
*/

//int d[5] = {10, 20, 3, 4, 30};

/*
Como por os ()?

Quebre em ki = C[1, n]

e ai para cada lado vá quebrando em C[ki+1, n] e C[1, ki]

Ex: 6 matrizes

1 1 2 3 4
  2 2 4 2
    3 3 4
      4 4
        5

        (A1A2A3A4)(A5A6)
        (A1A2A3A4)((A5)(A6))
        (((A1)(A2))((A3)(A4)))((A5)(A6))
*/
int d[5] = {30, 1, 40, 10, 25};
#define tam 5
int m[tam][tam];
int c[tam][tam];

int main()
{
    for(int i=1; i<tam; i++) m[i][i] = 0; //zera a diagonal principal

    for(int l=2; l<tam; l++){
        for(int i=1; i<(tam-l+1); i++){//Calcula a diagonal corrente
        //1 4
            int j = i+l-1;
            //cout<<"i: "<<i<<" j: "<<j<<endl;
            m[i][j] = inf;
            for(int k=i; k<j; k++){
                //cout<<"k: "<<k<<endl;
                int q = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j];
                if(q<m[i][j]){
                    //cout<<q<<endl;
                    m[i][j] = q;
                    c[i][j] = k;
                }
            }
        }
    }

    //Print
    cout<<"M: "<<endl;
    for(int i=1; i<tam; i++){
        for(int j=1; j<tam; j++){
            if(j>=i){
                cout<<m[i][j]<<" ";
            }else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }

    cout<<"\n\n";

    //Print
    cout<<"C: "<<endl;
    for(int i=1; i<tam; i++){
        for(int j=1; j<tam; j++){
            if(j>=i){
                cout<<c[i][j]<<" ";
            }else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
    return 0;
}