#include <stdio.h>
#include <string.h>

//struct definida com typedef, permite criar estruturas de forma mais fácil
typedef struct{
  int ano;
  int mes;
  int dia;
} Data; //tipo de dados da estrutura criado por nós

//struct definida com typedef, permite criar estruturas de forma mais fácil
typedef struct{
  char nome[50];
  char morada[50];
  long int contacto;
  Data dataNascimento;
} Pessoa; //tipo de dados da estrutura criado por nós

//ler uma data NÃO VALIDADA!!!
void lerData(Data *dn){
  printf("Ano: ");
  scanf("%d", &dn->ano);
  printf("Mês: ");
  scanf("%d", &dn->mes);
  printf("Dia: ");
  scanf("%d", &dn->dia);
}

void mostrarData(Data dn){
  printf("%d-%d-%d", dn.ano, dn.mes, dn.dia);
}

//ler cada pessoa
void lerLista(int n, Pessoa lista[]){
  int i;
  for(i=0; i<n; i++){
    printf("\nDados da pessoa %d:\n", (i+1));
    printf("Nome: ");
    fgets(lista[i].nome, 50, stdin);

    printf("Morada: ");
    fgets(lista[i].morada, 50, stdin);

    printf("Contacto: ");
    scanf("%ld", &lista[i].contacto);
    getchar();

    printf("Data de Nascimento: \n");
    lerData(&lista[i].dataNascimento);
    getchar();
  }
}

//mostra o vector de pessoas
void mostrarLista(int n, Pessoa lista[]){
  int i;
  for(i=0; i<n; i++){
    printf("\nPessoa %d:\nNome: %s", (i+1), lista[i].nome);
    printf("Morada: %s", lista[i].morada);
    printf("Contacto: %ld\n", lista[i].contacto);
    printf("Data de Nascimento: ");
    mostrarData(lista[i].dataNascimento);
    printf("\n");
  }
}

int main() {
  int n=2;

  //Criar vector de Pessoas
  Pessoa listaPessoas[n];

  //ler cada pessoa
  lerLista(n, listaPessoas);

  //mostra o vector de pessoas
  mostrarLista(n, listaPessoas);

  return 0;
}