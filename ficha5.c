#include <stdio.h>
#include <math.h>

typedef struct{
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno;


//1
int nota(Aluno a){
	int r=1;
	float mediaminit = (10*a.miniT[0]+10*a.miniT[1]+10*a.miniT[2]+10*a.miniT[3]+10*a.miniT[4]+10*a.miniT[5])/6;
	float minit =(10*a.miniT[0]+10*a.miniT[1]+10*a.miniT[2]+10*a.miniT[3]+10*a.miniT[4]+10*a.miniT[5]);
	while(r==1){
		if(minit<5) r=0;
		float notafinal = (mediaminit*0.2)+(0.80*a.teste);
		if(notafinal>=9.5) {
			round(notafinal);
			r=notafinal;
		}
		else r=0;
	}
	return r;
}

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}
//2
int procuraNum(int num, Aluno t[], int N){
	int r;
	for(int i=0;i<N;i++){
		if (t[i].numero==num) r=i;
	}
	return r;
}

void swapAluno(Aluno *x, Aluno *y){
	Aluno tmp = *x;
	*x=*y;
	*y=tmp; 
}

//3
void ordenaPorNum(Aluno t[], int N){
	int i,j;
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1-i;j++){
			if(t[j].numero>t[j+1].numero)
				swapAluno(&t[j],&t[j+1]);
		}
	}
}

int main(){
	Aluno Turma1 [7] = {
		{2222, "Joana", {2,0,2,1,0,2},  3.5}
        ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
        ,{4444, "André", {2,1,0,2,2,2}, 10.5}
        ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
        ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
        ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
        ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
    };
    printf("%d", nota(Turma1[0]));
	return 0;
}