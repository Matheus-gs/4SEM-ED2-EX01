// Exercício parte 1)
// Escreva um algoritmo que solicite a idade de n alunos ao usuário e ao final
// apresente O maior e o menor dos valores informados, a soma e a média
// aritmética Parte 2) 2.1) Tratar idades inválidas (espectro deve compreender
// 1-120 2.2) Solicitar também o gênero e ao final apresentar:
//      2.2.1) percentual de alunos por sexo (86% Feminino 14% Masculino)
//      2.2.2) Média de idade dos homens e média de idade das mulheres
//      2.2.3) Mulher mais nova/mais velha (idem para homem)
// Parte 3)
// Ao final, gerar um relatório das idades ordenado de forma crescente
// Parte 4)
// Refazer o item 3 anterior para imprimir também o nome considerando o gênero:
// Aluna 1: Maria - idade: 16
// Aluno 2: Antonio - idade: 17
// Aluno 3: Carlos - idade: 17
// Aluna 4: Ana - idade: 19

#include <stdio.h>
int idade, vlrMaior, vlrMenor, Qtd, alunos[100];
float Soma;
char Genero, Nome, NomeAlunos[100];
int counterMasc, counterFem, somaTotalGen;
void imprimirOrdenado();

int main() {
  int resposta;
  Qtd = 0;
  Soma = 0;

  float percentualMasc, percentualFem;

  do {
    Qtd = Qtd + 1;

    do {
      fflush(stdin);
      printf("\nInforme a idade do %i. aluno [1-120]: ", Qtd);
      scanf("%i", &idade);
    } while (idade > 120 | idade < 1);

    fflush(stdin);
    printf("\nInforme o nome do(a) %i. aluno(a): ", Qtd);
    scanf("%s", &Nome);

    fflush(stdin);
    printf("\nInforme o sexo do %i. aluno: ", Qtd);
    scanf("%s", &Genero);

    // Comparação de idades
    if (Qtd == 1) {
      vlrMenor = idade;
      vlrMaior = idade;
    } else if (vlrMaior < idade) {
      vlrMaior = idade;
    } else if (vlrMenor > idade) {
      vlrMenor = idade;
    }

    // Distinção + Contagem de gênero
    if (Genero == 'M' || Genero == 'm') {
      counterMasc++;
    } else if (Genero == 'F' || Genero == 'f') {
      counterFem++;
    }

    NomeAlunos[Qtd] = Nome;
    alunos[Qtd] = idade;
    Soma = Soma + idade;
    somaTotalGen += (counterFem + counterMasc);
    percentualMasc = (float)counterMasc / somaTotalGen;
    percentualFem = (float)counterFem / somaTotalGen;

    fflush(stdin);
    printf("\n\nDeseja informar os dados do proximo (1/Sim 2/Nao)? ");
    scanf("%i", &resposta);

  } while (resposta == 1);

  if (resposta != 1) {
    printf("\n\n A soma das %i idades igual a %0.0f", Qtd, Soma);
    printf("\n A media das %i idades igual a %0.0f", Qtd, (Soma / Qtd));
    printf("\n\n O aluno com menor idade tem %i anos", vlrMenor);
    printf("\n O aluno com maior idade tem %i anos", vlrMaior);
    printf("\n\n Percentual de homens: %0.0f porcento", (percentualMasc * 100));
    printf("\n Percentual de mulheres: %0.0f porcento", (percentualFem * 100));
  }

  imprimirOrdenado();
}

void imprimirOrdenado() {
  int aux;
  int auxNome;

  for (int j = 1; j < Qtd; j++)
    for (int i = 0; i < Qtd - 1; i++)
      if (alunos[i] > alunos[i + 1]) {
        // Ordenando idades
        aux = alunos[i];
        alunos[i] = alunos[i + 1];
        alunos[i + 1] = aux;

        // Ordenando nomes
        auxNome = NomeAlunos[i];
        NomeAlunos[i] = NomeAlunos[i + 1];
        NomeAlunos[i + 1] = auxNome;
      }
  printf("\n\n Relatorio de Alunos por idade");
  for (int i = 1; i <= Qtd; i++) {
    printf("\n  Aluno(a) %i: %c - Idade: %i", i, NomeAlunos[i], alunos[i]);
  }

  printf("\n Fim do Relatorio...");
}
