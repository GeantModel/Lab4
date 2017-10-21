#include <iostream>
#include <bitset>

const unsigned short int size = 60;
using namespace std;

void NewM1(int *a, int *b){
    for (int i = 0; i < size; i++) {
        a[i] = 0 + rand() % 10000;
        cout << "a[" << i << "] = " << a[i] << "\n";
    }
    cout << '\n';

    int j=0;
    for (int i = 0; i < size; i+=2) {
        b[j]=a[i];
        cout << "b[" << j << "] = " << a[i] << "\n";
        j++;}
    cout<<endl;
}
void CheckBit(int *b){
    for(int i = 0; i<size/2; i++){
        if ( (((*(b+i))&88)==88) && (((*(b+i))&6)==0) ){
            cout<<"b["<< i <<"] = "<<*(b+i) <<" true"<<endl;
        }
        else{
            cout<<"b["<< i <<"] = "<<*(b+i) <<" false"<<endl;
        }
    }
    cout<<endl;
}
unsigned int Num(int num) {
    unsigned int k = 0;
    while (num) {
        num/= 10;
        k++;
    }
    return k;
}
int Pow(int x, int y){
    int res = 1;
    for(;y>0;y--){
        res*=x;
    }
    return res;
}

void NewM2(int *a, int **b){
    for (int i = 0; i < size/2; i++) {
        unsigned int R = Num(*(a+i));
        cout<<"A["<<i<<"]: ";
        for (int j = 0, j1 = Pow(10,R); j<R; j++, j1/=10) {
            b[i][j] = ((*(a+i))%j1)/(j1/10);
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void ArrSub(int **A, int *arr2){
    for(int i=0; i<size/2;i++){
        cout<<"B["<<i<<"]: ";
        for(int j=0; j<Num(*(arr2 + i)); j++){
            if(A[i][j]==0){
                A[i][j] = 9;
                cout << A[i][j] << " ";
                continue;
            }
            A[i][j] = A[i][j] - 1;
            cout << A[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
}
void NewM3(int **a,int *b, int *c){
    for(int i=0; i<size/2; i++){
        int sum = 0;
        int dig = Num(*(b + i));
        for(int j=0, j1 = Pow(10,dig-1); j<dig; j++,j1/=10){
            sum=sum+a[i][j]*j1;
        }
        *(c+i) = sum;
        cout << "c["<< i <<"] = "<< *(c+i)<<endl;
    }
    cout<<endl;
}
int main() {
    int *a = new int[size];
    int *b = new int [size/2];
    NewM1(a,b);
    delete[] a;
    CheckBit(b);
    int **A = new int *[size/2];
    for (int i = 0; i < size/2; i++) {
        unsigned int dig = Num(*(b + i));
        A[i] = new int[dig];
    }
    NewM2(b,A);
    ArrSub(A,b);
    int *c = new int[size/2];
    NewM3(A,b,c);
    delete[]b;
    delete[]c;
    for(int i=0; i<size/2; i++){
        delete[]A[i];
    }
    delete[]A;

}