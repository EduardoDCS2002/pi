#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define TAM_TURMA 40

typedef struct estudante {
    char nome[50];
    int nota;
} Estudante;

int calcula_nota(char nome[]){
    int i,r=0;
    for(i=1;nome[i]!='\0' && nome[i]!=' ';i++){
        int c = nome[i] - 96;
        r+=c;
    }
    r=r%18;
    return r;
}

void preenche_notas(Estudante turma[], int N){
    for(int i=0;i<N;i++){
        turma[i].nota = calcula_nota(turma[i].nome);
    }
}
void swapturma(Estudante x[], int i, int j){
    Estudante tmp;
    tmp = x[i];
    x[i] = x[j];
    x[j] = x[i];

}
void ordena_turma(Estudante turma[], int N){
    int i,j;
    for (i = 0; i < N - 1; i++){
        for (j = 0; j < N - i - 1; j++){
            if(strcmp(turma[j].nome, turma[j+1].nome)>0) swapturma(turma, j, j+1);  
        }
    }
}



int main(){

    Estudante turma[TAM_TURMA] = {
        { "Hooty", 0 }, { "Mabel Pines", 0 },
        { "Craig Pelton", 0 }, { "Wanda Maximoff", 0 },
        { "Naomi Nagata", 0 }, { "Bruce Wayne", 0 },
        { "Moff Gideon", 0 }, { "Patrick Bateman", 0 },
        { "Sun Bak", 0 }, { "Nomi Marks", 0 },
        { "Willow", 0 }, { "Han Solo", 0 },
        { "Kala Dandekar", 0 }, { "Charlie Spring", 0 },
        { "Legolas", 0 }, { "Diane Nguyen", 0 },
        { "Bobbie Draper", 0 }, { "Britta Perry", 0 },
        { "Lito Rodriguez", 0 }, { "Nebula", 0 },
        { "Annie Edison", 0 }, { "Anakin Skywalker", 0 },
        { "Rocket Raccoon", 0 }, { "Hope Van Dyne", 0 },
        { "Tony Stark", 0 }, { "Ciri", 0 },
        { "Jeff Winger", 0 }, { "Troy Barnes", 0 },
        { "Capheus Onyango", 0 }, { "Evelyn Wang", 0 },
        { "Joel Miller", 0 }, { "Amos Burton", 0 },
        { "Wolfgang Bogdanow", 0 }, { "Tao Xu", 0 },
        { "Abed Nadir", 0 }, { "Loki", 0 },
        { "Luz Noceda", 0 }, { "Boba Fett", 0 },
        { "Drax", 0 }, { "Walter White", 0 }
    };
    preenche_notas(turma, TAM_TURMA);
    printf("Nota numero 35: %d\n", turma[35].nota);
    ordena_turma(turma, TAM_TURMA);
    int r;
    for(int i=39-26;i<40;i++){
        r+=turma[i].nota;
    }
    printf("%d\n", r);
    return 0;
}