#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LER_ESPACO setbuf(stdin, NULL)
#define PULA_LINHA printf("\n")

#define MAXCHAR 100
#define MAXVET 1000

typedef struct {
  int id; // ID único.
  char nomCom[MAXCHAR]; // Nome completo.
  int numVia; // Número de viagens
  int numHis; // Número de pedidos no histórico completo.
  int hisCom[MAXVET];// Histórico completo de pedidos de alimentos. IDs pedidos pelo cliente.
  int hisAtu[MAXVET];// Histórico atual de pedidos de alimentos.ID dos alimentos pedidos que ainda estão cadastrados no sistema, que não foram removidos do cadastro de alimentos.
} cliente;

typedef struct {
  int id; // ID único.
  char nom[MAXCHAR]; // Nome do alimento.
  float preco; // Preço do alimento.
  char marca[MAXCHAR]; // Marca do alimento. Opcional.
} alimento;


// criarLogErro;
// testeRegrasDeAplicacao;

//  finalizado?
// Descrição: Lê todos os dados em "dados.txt".
void lerDados(int *numCli, int *numAli, cliente cli[], alimento ali[]){
  int i, j;
  FILE* arq;

  arq = fopen ("dados.txt","r");

  if (arq==NULL)
    printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
  else
  {

    fscanf(arq, "%d%*c%d%*c", numCli, numAli);

    for ( i = 0 ; i < *numCli ; i++ ) {
      fscanf(arq, "%d%*c", &cli[i].id);
      fscanf(arq, "%[^\n]s%*c", &cli[i].nomCom);
      fscanf(arq, "%d%*c", &cli[i].numVia);
      fscanf(arq, "%d%*c", &cli[i].numHis);
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        fscanf(arq, "%d%*c", &cli[i].hisCom[j]);
    }
    for ( i = 0 ; i < *numAli ; i++ ) {
      fscanf(arq, "%d%*c", &ali[i].id);
      fscanf(arq, "%[^\n]s%*c", &ali[i].nom);
      fscanf(arq, "%f%*c", &ali[i].preco);
      fscanf(arq, "%[^\n]s%*c", &ali[i].marca);
    }

    fclose(arq);
  }
}

//
// Descrição:
void showHistoricoAtual (int numCli, int numAli, cliente cli, alimento ali[]){
  int i, j;
  printf(" Historico atual:");
  for ( i = 0 ; i < cli.numHis ; i++ )
    for ( j = 0 ; j < numAli ; j++ )
      if ( ali[j].id == cli.hisCom[i] )
        printf(" [%d] ", cli.hisCom[i] );
  PULA_LINHA;
}

// Finalizado.
// Descrição.
void showListaCliente(){
  printf("\n Carregando lista de clientes registrados...\n\n");
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int i, j, numCli, numAli;

  if (arq==NULL)
    printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
  else
  {
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);

    cliente cli[numCli];
    alimento ali[numAli];

    lerDados(&numCli, &numAli, cli, ali);

    for ( i = 0 ; i < numCli ; i++ ) {
      printf(" Id: %d\n", cli[i].id);
      printf(" Nome: %s\n", cli[i].nomCom);
      printf(" Numero de viagens: %d\n", cli[i].numVia);
      printf(" Historico completo:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        printf(" [%d] ", cli[i].hisCom[j]);
      PULA_LINHA;
      showHistoricoAtual (numCli, numAli, cli[i], ali);

    }

  }
  fclose(arq);
  PULA_LINHA;
}

// Nada
void inserirCliente(){
  showListaCliente();

  cliente novCli; // novo cliente a ser inserido.

  printf(" Digite as seguintes informacoes.\n");

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

// Finalizado.
//
void showListaAlimento(){
  printf("\n Carregando lista de alimentos registrados...\n\n");
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int i, j, numCli, numAli;

  cliente cli[numCli];
  alimento ali[numAli];

  if (arq==NULL)
    printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
  else
  {
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);

    lerDados(&numCli, &numAli, cli, ali);

    for ( i = 0 ; i < numAli ; i++ ) {
      printf(" Id: %d\n", ali[i].id);
      printf(" Nome: %s\n", ali[i].nom);
      printf(" Preco: %.2f\n", ali[i].preco);
      printf(" Marca: %s\n", ali[i].marca);
      PULA_LINHA;

    }

  }
  fclose(arq);
  PULA_LINHA;
}

// Nada
void inserirAlimento(){
  showListaAlimento();

  cliente novAli; // novo cliente a ser inserido.

  printf(" Digite as seguintes informacoes.\n");
}

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
void gerarRelatorio(){

    srand(time(NULL));
    int i, j, k , numCli, numAli, ran;
    char nomRel[MAXCHAR];
    FILE *arqRel, *arqTem;

    cliente cli[numCli];
    alimento ali[numAli];

    lerDados(&numCli, &numAli, cli, ali);

    ran = rand();
    arqTem = fopen("arqTem.txt","w");
    fprintf(arqTem,"relatorio%4d.txt", ran);
    fclose (arqTem);
    arqTem = fopen("arqTem.txt","r");
    fscanf(arqTem,"%s", &nomRel);
    fclose (arqTem);
    remove("arqTem.txt");

    arqRel = fopen (nomRel,"w");

    fprintf(arqRel, "Informacoes a respeitos dos clientes:\n");
    for ( i = 0 ; i < numCli ; i++ ) {
      fprintf(arqRel, " Id: %d\n", cli[i].id);
      fprintf(arqRel, " Nome: %s\n", cli[i].nomCom);
      fprintf(arqRel, " Numero de viagens: %d\n", cli[i].numVia);
      fprintf(arqRel, " Historico completo:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        fprintf(arqRel, " [%d] ", cli[i].hisCom[j]);
      printf(" Historico atual:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        for ( k = 0 ; k < numAli ; k++ )
          if ( ali[k].id == cli[i].hisCom[j] )
            printf(" [%d] ", cli[i].hisCom[j]);
    }
    fprintf(arqRel, "\n\nInformacoes a respeitos dos videos:\n");
    for ( i = 0 ; i < numAli ; i++ ) {
      fprintf(arqRel, " Id: %d\n", ali[i].id);
      fprintf(arqRel, " Nome: %s\n", ali[i].nom);
      fprintf(arqRel, " Preco: %.2f\n", ali[i].preco);
      fprintf(arqRel, " Marca: %s\n", ali[i].marca);
    }

    printf("Arquivo criado com o nome '%s'\n", nomRel);

    fclose(arqRel);

}

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
  printf(" Programa finalizado.\n");
  return 0;
}
