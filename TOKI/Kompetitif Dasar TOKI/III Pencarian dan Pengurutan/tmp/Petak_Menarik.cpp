#include <iostream>
using namespace std;
int petak[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin>>petak[i][j];
        }
    }
    bool menarik=false;
    int i, j;
    for(j=0; j<m; j++) {
        for(i=0; i<n; i++){
            int kemenarikan;
            // Mencari kemenarikan sesuai ketentuan soal
            if(m==1 && n==1) {
                kemenarikan=0;
            } else if(m==1) {
                kemenarikan=((i==0) ? 0:petak[i-1][0]) * ((i==n-1) ? 0:petak[i+1][0]);
            } else if(n==1) {
                kemenarikan=((j==0) ? 0:petak[0][j-1]) * ((j==m-1) ? 0:petak[0][j+1]);
            } else if(i==0 && j==0) {
                kemenarikan=petak[1][0]*petak[0][1];
            } else if(i==n-1 && j==0) {
                kemenarikan=petak[i-1][0]*petak[i][1];
            } else if(i==0 && j==m-1) {
                kemenarikan=petak[0][j-1]*petak[1][j];
            } else if(i==n-1 && j==m-1) {
                kemenarikan=petak[i][j-1]*petak[i-1][j];
            } else if(i==0) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i+1][j];
            } else if(i==n-1) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j];
            } else if(j==0) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j+1];
            } else if(j==m-1) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j-1];
            } else {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j]*petak[i+1][j];
            }
            if(kemenarikan==k) {
                menarik=true;
                break;
            }
        }
        if(menarik) break;
    }
    if(menarik) {
        cout<<i+1<<" "<<j+1<<endl;
    } else {
        cout<<"0 0"<<endl;
    }
    return 0;
}