#include <stdio.h>
//6
//a
int fibi(int n){
	int r;
	if (n==0) r=n;
	if (n<=2) r=1;
	else r = fibi(n-1) + fibi(n-2);
	return r;
}
//b
int fibiup(int n){
	int r=1, ultimo=0, penultimo;
	if (n==0) r=0;
	for(int i=1; i<=n;i++){
		penultimo = ultimo;
		ultimo = r;
		r= ultimo + penultimo;
	}
	return r;
}

int main(){
	printf("%d\n", fibiup(1));
	return 0;
}