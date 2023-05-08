#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct aluno {
  char nome[100];
  int nr;
  int nota;
} Aluno;

typedef struct cel {
  Aluno *aluno;
  struct cel *prox;
} *Turma;

//afinal não foi preciso testar.