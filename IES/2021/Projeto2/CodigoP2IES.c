#include <stdio.h>

#define maxchar 100
#define maxvet 1000

typedef struct {
  int id; // ID único.
  char nomCom[maxchar]; // Nome completo.
  int numVia; // Número de viagens.
  int hisCom[maxvet];// Histórico completo de pedidos de alimentos. IDs pedidos pelo cliente.
  int hisAtu[maxvet];// Histórico atual de pedidos de alimentos.ID dos alimentos pedidos que ainda estão cadastrados no sistema, que não foram removidos do cadastro de alimentos.
} cliente;

typedef struct {
  int id; // ID único.
  char nom[maxchar]; // Nome do alimento.
  int preco; // Preço do alimento.
  char marca[maxchar]; // Marca do alimento.
} alimento;


// criarLogErro;
// testeRegrasDeAplicacao;

// Nada
void showListaCliente(){
  printf(" Carregando lista de clientes registrados...\n");
  FILE * pFile;
  pFile = fopen ("dados","rb");
  if (pFile==NULL) printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
  else
  {

  }
}

// Nada
void inserirCliente(){
  showListaCliente();

  cliente novCli; // novo cliente a ser inserido.

  printf(" Digite as seguintes informacoes.\n", );

}

// Nada
void removerCliente(){}

// Nada
void alterarCliente(){}

// Nada
void consultarCliente(){}

// Documentacao
void interfaceCliente(){
  int x;
  printf(" Bem vindo a interface de cadastro de clientes. Escolha uma opcao.\n");
  printf(" 1 - Inserir novo cliente.\n");
  printf(" 2 - Remover cliente.\n");
  printf(" 3 - Alterar cliente.\n");
  printf(" 4 - Consultar cliente.\n");
  printf(" 0 - Retomar a interface principal.\n - ");
  scanf("%d", &x);
  while (x<0||x>4){
    printf("Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  switch(x) {
    case 0: break;
    case 1: inserirCliente(); break;
    case 2: removerCliente(); break;
    case 3: alterarCliente(); break;
    case 4: consultarCliente(); break;
  }
}

// Nada
void showListaAlimento(){}

// Nada
void inserirAlimento(){}

// Nada
void removerAlimento(){}

// Nada
void alterarAlimento(){}

// Nada
void consultarAlimento(){}

// Documentacao
void interfaceAlimento(){
  int x;
  printf(" Bem vindo a interface de cadastro de alimentos. Escolha uma opcao.\n");
  printf(" 1 - Inserir novo alimento.\n");
  printf(" 2 - Remover alimento.\n");
  printf(" 3 - Alterar alimento.\n");
  printf(" 4 - Consultar alimento.\n");
  printf(" 0 - Retomar a interface principal.\n - ");
  scanf("%d", &x);
  while (x<0||x>4){
    printf("Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  switch(x) {
    case 0: break;
    case 1: inserirAlimento(); break;
    case 2: removerAlimento(); break;
    case 3: alterarAlimento(); break;
    case 4: consultarAlimento(); break;
  }
}

// Nada
void gerarRelatorio(){}

// Interface principal
// Documentacao
int interfacePrincipal(){
  int x;
  printf(" Bem vindo a interface principal. Escolha uma opcao.\n");
  printf(" 1 - Cadastro de clientes. (inserir/remover/alterar/consultar)\n");
  printf(" 2 - Cadastro de alimentos. (inserir/remover/alterar/consultar)\n");
  printf(" 3 - Gerar relatorio de informacoes.\n");
  printf(" 0 - Finalizar programa.\n - ");
  scanf("%d", &x);
  while (x<0||x>3){
    printf("Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  switch(x) {
    case 0: return 0; break;
    case 1: interfaceCliente(); break;
    case 2: interfaceAlimento(); break;
    case 3: gerarRelatorio(); break;
  }
  return 1;
}

// finalizado
int main() {
  while (interfacePrincipal());
  printf("Programa finalizado.\n");
  return 0;
}
