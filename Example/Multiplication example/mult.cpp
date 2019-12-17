#include <bits/stdc++.h>

using namespace std;

int A[6],B[6],C[6]; 

int main(){
	int i=0;
	while((C[i] = B[i] * A[i])!=0){
		i++;
	}
	return 0;
}