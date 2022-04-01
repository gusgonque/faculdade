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
  //int hisAtu[MAXVET];// Histórico atual de pedidos de alimentos.ID dos alimentos pedidos que ainda estão cadastrados no sistema, que não foram removidos do cadastro de alimentos.
} cliente;

typedef struct {
  int id; // ID único.
  char nome[MAXCHAR]; // Nome do alimento.
  float preco; // Preço do alimento.
  char marca[MAXCHAR]; // Marca do alimento. Opcional.
} alimento;

/*
  Descrição: Verifica a string nome, se ele tem o número mínimo de caracteres (2), se ele não é vazio.
  1 - certo
  0 - errado
*/
int verificarNome (char nome[])
{
  int i, j, p;
  for ( i = j = p = 0 ; nome[i] ; i++, j++ )
    if ( nome[i]==' ')
      p++;
  if (j<2 || p == i)
    return 0;
  return 1;
}


/*
  Descrição: cria o arquivo LogErro, de acordo com o erro e id do alimento/cliente.
  e = (-) alimento / (+) cliente
  1 - nome
  2 - preco / numero de viagens
  3 - (cliente) historico
  4 - ID incorreto
*/
void criarLogErro(int e, int id){
  FILE *arqLog;

  arqLog = fopen("LogErro.txt","a+");

  if ( e == -1 )
    fprintf(arqLog, "ERRO 1: Alimento com ID = [%d], nome incorreto.\n", id);
  if ( e == -2 )
    fprintf(arqLog, "ERRO 2: Alimento com ID = [%d], preco foi colocado de forma incorreta, por exemplo numeros negativos.\n", id);
  if ( e == -4 )
    fprintf(arqLog, "ERRO 4: Alimento com ID = [%d], ID colocado ja existente.\n", id);

  if ( e == 1 )
    fprintf(arqLog, "ERRO 1: Cliente com ID = [%d], nome incorreto.\n", id);
  if ( e == 2 )
    fprintf(arqLog, "ERRO 2: Cliente com ID = [%d], numero de viagens foi colocado de forma incorreta, por exemplo numeros negativos.\n", id);
  if ( e == 3 )
    fprintf(arqLog, "ERRO 3: Cliente com ID = [%d], Algum numero no historico foi colocado de  forma incorreta, por exemplo numeros negativos.\n", id);
  if ( e == 4 )
    fprintf(arqLog, "ERRO 4: Cliente com ID = [%d], ID colocado ja existente.\n", id);

  fclose(arqLog);
}


/*
  Descrição: Testa o cliente para criar os logs de erro, e retorna um inteiro de acordo com o teste.
  1 - Algo errado
  0 - Tudo certo
*/
int testeRegrasDeValidacaoCliente(cliente cli){
  int i=0, j;
  if (!verificarNome(cli.nomCom)) {
    criarLogErro(1, cli.id);
    i++;
  }
  if (cli.numVia<0){
    criarLogErro(2, cli.id);
    i++;
  }
  for (j = 0; j < cli.numHis; j++)
    if(cli.hisCom[j]<1){
      criarLogErro(3, cli.id);
      i++;
      break;
    }

  return i!=0;
}

/*
  Descrição: Testa o alimento para criar os logs de erro, e retorna um inteiro de acordo com o teste.
  1 - Algo errado
  0 - Tudo certo
*/
int testeRegrasDeValidacaoAlimento(alimento ali){
  int i=0, j;
  if (!verificarNome(ali.nome)) {
    criarLogErro(-1, ali.id);
    i++;
  }
  if (ali.preco<0.0){
    criarLogErro(-2, ali.id);
    i++;
  }
  return i!=0;
}

// Descrição: Lê todos os dados em "dados.txt", e salva os dados nas variaveis.
void lerDados(int *numCli, int *numAli, cliente cli[], alimento ali[]){
  int i, j;
  FILE* arq;

  arq = fopen ("dados.txt","r");

  if (arq==NULL)
    printf(" Arquivo de dados nao encontrado.\n");
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
      fscanf(arq, "%*c");
    }
    for ( i = 0 ; i < *numAli ; i++ ) {
      fscanf(arq, "%d%*c", &ali[i].id);
      fscanf(arq, "%[^\n]s%*c", &ali[i].nome);
      fscanf(arq, "%f%*c", &ali[i].preco);
      fscanf(arq, "%[^\n]s%*c", &ali[i].marca);
    }

    fclose(arq);
  }
}

// Descrição: Salva todos os dados em "dados.txt", a partir das variaveis.
void salvaDados(int numCli, int numAli, cliente cli[], alimento ali[]) {
  int i, j;
  FILE* arq;

  arq = fopen ("dados.txt","w");

  if (arq==NULL)
    printf(" Nao foi possivel criar novo arquivo.\n Retornando ao menu anterior.");
  else
  {
    printf(" Salvando novos dados...");
    fprintf(arq, "%d;%d\n", numCli, numAli);

    for ( i = 0 ; i < numCli ; i++ ) {
      fprintf(arq, "%d\n", cli[i].id);
      fprintf(arq, "%s\n", cli[i].nomCom);
      fprintf(arq, "%d\n", cli[i].numVia);
      fprintf(arq, "%d;", cli[i].numHis);
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        fprintf(arq, "%d,", cli[i].hisCom[j]);
      fprintf(arq, "\n");
    }
    for ( i = 0 ; i < numAli ; i++ ) {
      fprintf(arq, "%d\n", ali[i].id);
      fprintf(arq, "%s\n", ali[i].nome);
      fprintf(arq, "%.2f\n", ali[i].preco);
      fprintf(arq, "%s\n", ali[i].marca);
    }
  }
  fclose(arq);
  PULA_LINHA;
}

// Descrição: printa na tela o historico atual do cliente cli.
void showHistoricoAtual (int numCli, int numAli, cliente cli, alimento ali[]){
  int i, j;
  printf(" Historico atual:");
  for ( i = 0 ; i < cli.numHis ; i++ )
    for ( j = 0 ; j < numAli ; j++ )
      if ( ali[j].id == cli.hisCom[i] )
        printf(" [%d] ", cli.hisCom[i] );
  PULA_LINHA;
}

// Descrição: Mostra ID e nome de todos os clientes.
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
      printf(" Id: %d;", cli[i].id);
      printf(" Nome: %s\n", cli[i].nomCom);
    }

  }
  fclose(arq);
  PULA_LINHA;
}

// Descrição: Insere um novo cliente em "dados.txt"
void inserirCliente(){

  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli=0, numAli=0, x, f, fe=0, i, j;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
  }
  cliente cli[numCli+1];
  alimento ali[numAli];
  lerDados(&numCli, &numAli, cli, ali);
  numCli++;
  printf(" Para criar um novo cliente, informacoes serao pedidas. Siga de acordo.\n");

  printf(" Deseja inserir um ID manualmente?\n");
  printf(" 1 - Inserir ID manualmente.\n");
  printf(" 0 - Deixar o sistema decidir o ID.\n - ");
  scanf("%d", &x);
  while (x!=0&&x!=1){
    printf(" Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  if (x) {
    printf(" Digite o ID do novo cliente.\n - ");
    scanf("%d", &cli[numCli-1].id);
    for ( i=0 ; i<numCli ; i++) {
      if (cli[i].id == cli[numCli-1].id)
        fe=1;
    }
    if (fe)
      criarLogErro(4, cli[numCli-1].id);
  }
  else{
    cli[numCli-1].id = 0;
    for ( i = f = 1 ; cli[numCli-1].id == 0 ; i++, f=1 ){
      for ( j = 0 ; j < numCli-1 ; j++ )
        if (cli[j].id == i)
          f = 0;
      if (f == 1)
        cli[numCli-1].id = i;
    }
  }

  printf(" Digite o nome do cliente. (Tamanho minimo de 2 caracteres)\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &cli[numCli-1].nomCom);

  printf(" Deseja inserir o numero de viagens?\n");
  printf(" 1 - Sim.\n");
  printf(" 0 - Nao.\n - ");
  scanf("%d", &x);
  while (x!=0&&x!=1){
    printf(" Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  if (x) {
    printf(" Digite o numero de viagens do novo cliente.\n - ");
    scanf("%d", &cli[numCli-1].numVia);
  }

  printf(" Digite os pedidos do cliente. Para finalizar, digite 0.\n - ");
  scanf("%d", &cli[numCli-1].hisCom[0]);
  printf(" - ");
  for ( i=1 ; cli[numCli-1].hisCom[i-1]!=0 ; i++ ) {
    scanf("%d", &cli[numCli-1].hisCom[i]);
    if (cli[numCli-1].hisCom[i-1]!=0)
      printf(" - ");
  }
  PULA_LINHA;
  cli[numCli-1].numHis = i-1;

  if (testeRegrasDeValidacaoCliente(cli[numCli-1])||fe)
      printf(" Nao foi possivel criar novo cliente. Favor consultar o arquivo 'LogErro.txt' para mais informacoes\n");
  else
    salvaDados(numCli, numAli, cli, ali);
  showListaCliente();
}

// Descrição: Remove um cliente de "dados.txt"
void removerCliente(){
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli, numAli, x, f, i, j;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
    if(numCli==0)
      printf(" Nenhum cliente registrado.\n Retornando ao menu anterior.");
    else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaCliente();

      printf(" Digite o ID do cliente que deseja remover.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numCli ; i++ )
      if(cli[i].id == x){
        f=1;
        break;
      } else
      f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numCli ; i++ )
        if(cli[i].id == x){
          f=1;
          break;
        }
      }

      for (  ; i<numCli-1 ; i++ ) {
        cli[i].id = cli[i+1].id;
        strcpy(cli[i].nomCom, cli[i+1].nomCom);
        cli[i].numVia = cli[i+1].numVia;
        cli[i].numHis = cli[i+1].numHis;
        for ( j=0 ; j<cli[i].numHis ; j++ ) {
          cli[i].hisCom[j] = cli[i+1].hisCom[j];
        }
      }
      numCli--;
      salvaDados(numCli, numAli, cli, ali);
      PULA_LINHA;
      showListaCliente();
    }
  }
}

// Descrição: Altera um cliente em "dados.txt"
void alterarCliente(){

  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli, numAli, x, f, fe=0, i, j;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);

    if(numCli==0)
      printf(" Nenhum cliente registrado.\n Retornando ao menu anterior.");
    else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaCliente();

      printf(" Digite o ID do cliente que deseja alterar.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numCli ; i++ )
      if(cli[i].id == x){
        f=1;
        break;
      } else
      f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numCli ; i++ )
        if(cli[i].id == x){
          f=1;
          break;
        }
      }

      printf(" Digite o nome do cliente. (Tamanho minimo de 2 caracteres)\n - ");
      LER_ESPACO;
      scanf("%[^\n]s", &cli[i].nomCom);

      printf(" Deseja inserir o numero de viagens?\n");
      printf(" 1 - Sim.\n");
      printf(" 0 - Nao.\n - ");
      scanf("%d", &x);
      while (x!=0&&x!=1){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
      }
      if (x) {
        printf(" Digite o numero de viagens do novo cliente.\n - ");
        scanf("%d", &cli[i].numVia);
      }
      else
        cli[i].numVia=0;

      printf(" Digite os pedidos do cliente. Para finalizar, digite 0.\n - ");
      scanf("%d", &cli[i].hisCom[0]);
      printf(" - ");
      for ( j=1 ; cli[i].hisCom[j-1]!=0 ; j++ ) {
        scanf("%d", &cli[i].hisCom[j]);
        if (cli[i].hisCom[j-1]!=0)
          printf(" - ");
      }
      PULA_LINHA;
      cli[i].numHis = j-1;

      if (testeRegrasDeValidacaoCliente(cli[i])||fe)
      printf(" Nao foi possivel editar o cliente. Favor consultar o arquivo 'LogErro.txt' para mais informacoes\n");
      else
      salvaDados(numCli, numAli, cli, ali);
      PULA_LINHA;
      showListaCliente();
    }
  }
}

// Descrição: Printa na tela todas as informacoes de um cliente em especifico.
void consultarCliente(){
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli, numAli, x, f, i, j, k;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
    if(numCli==0)
      printf(" Nenhum cliente registrado.\n Retornando ao menu anterior.");
    else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaCliente();

      printf(" Digite o ID do cliente que deseja alterar.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numCli ; i++ )
      if(cli[i].id == x){
        f=1;
        break;
      } else
      f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numCli ; i++ )
        if(cli[i].id == x){
          f=1;
          break;
        }
      }

      printf("\n Id: %d\n", cli[i].id);
      printf(" Nome: %s\n", cli[i].nomCom);
      printf(" Numero de viagens: %d\n", cli[i].numVia);
      printf(" Historico completo:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
      printf(" [%d] ", cli[i].hisCom[j]);
      printf("\n Historico atual:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
      for ( k = 0 ; k < numAli ; k++ )
      if ( ali[k].id == cli[i].hisCom[j] )
      printf(" [%d] ", cli[i].hisCom[j]);
      PULA_LINHA;
    }
  }
  PULA_LINHA;
}

// Descrição: Interface com menu para cadastro de clientes.
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
    printf(" Comando invalido. digite novamente.\n - ");
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

// Descrição: Mostra ID e nome de todos os alimentos.
void showListaAlimento(){
  printf("\n Carregando lista de alimentos registrados...\n\n");
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int i, j, numCli, numAli;


  if (arq==NULL)
    printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
  else
  {
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    cliente cli[numCli];
    alimento ali[numAli];
    fclose(arq);

    lerDados(&numCli, &numAli, cli, ali);

    for ( i = 0 ; i < numAli ; i++ ) {
      printf(" Id: %d;", ali[i].id);
      printf(" Nome: %s\n", ali[i].nome);

    }

  }
  fclose(arq);
  PULA_LINHA;
}

// Descrição: Insere um novo alimento em "dados.txt"
void inserirAlimento(){

  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli=0, numAli=0, x, f, fe=0, i, j;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
  }

  cliente cli[numCli];
  alimento ali[numAli+1];
  lerDados(&numCli, &numAli, cli, ali);

  numAli++;
  printf(" Para criar um novo alimento, informacoes serao pedidas. Siga de acordo.\n");

  printf(" Deseja inserir um ID manualmente?\n");
  printf(" 1 - Inserir ID manualmente.\n");
  printf(" 0 - Deixar o sistema decidir o ID.\n - ");
  scanf("%d", &x);
  while (x!=0&&x!=1){
    printf(" Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  if (x) {
    printf(" Digite o ID do novo alimento.\n - ");
    scanf("%d", &ali[numAli-1].id);
    for ( i=0 ; i<numAli ; i++) {
      if (ali[i].id == ali[numAli-1].id)
        fe=1;
    }
    if (fe)
      criarLogErro(4, cli[numAli-1].id);
  }
  else{
    ali[numAli-1].id = 0;
    for ( i = f = 1 ; ali[numAli-1].id == 0 ; i++, f=1 ){
      for ( j = 0 ; j < numAli-1 ; j++ )
        if (ali[j].id == i)
          f = 0;
      if (f == 1)
        ali[numAli-1].id = i;
    }
  }

  printf(" Digite o nome do alimento. (Tamanho minimo de 2 caracteres)\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &ali[numAli-1].nome);

  printf(" Digite o preco do alimento.\n - ");
  scanf("%f", &ali[numAli-1].preco);

  printf(" Deseja inserir a marca do alimento?\n");
  printf(" 1 - Sim.\n");
  printf(" 0 - Nao.\n - ");
  scanf("%d", &x);
  while (x!=0&&x!=1){
    printf(" Comando invalido. digite novamente.\n - ");
    scanf("%d", &x);
  }
  if (x) {
    printf(" Digite a marca do novo alimento.\n - ");
    LER_ESPACO;
    scanf("%[^\n]s", &ali[numAli-1].marca);
  }
  else
    strcpy(ali[numAli-1].marca,"-");

  if (testeRegrasDeValidacaoAlimento(ali[numAli-1])||fe)
      printf(" Nao foi possivel criar novo alimento. Favor consultar o arquivo 'LogErro.txt' para mais informacoes\n");
  else
    salvaDados(numCli, numAli, cli, ali);
  showListaAlimento();
}

// Descrição: Remove um alimento de "dados.txt"
void removerAlimento(){
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli, numAli, x, f, i, j;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
    if(numAli==0)
      printf(" Nenhum alimento registrado.\n Retornando ao menu anterior.");
    else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaAlimento();

      printf(" Digite o ID do alimento que deseja remover.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numAli ; i++ )
      if(ali[i].id == x){
        f=1;
        break;
      } else
      f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numAli ; i++ )
          if(ali[i].id == x){
            f=1;
            break;
          }
      }
      for (  ; i<numAli-1 ; i++ ) {
        ali[i].id = ali[i+1].id;
        strcpy(ali[i].nome, ali[i+1].nome);
        ali[i].preco = ali[i+1].preco;
        strcpy(ali[i].marca, ali[i+1].marca);
      }
      numAli--;
      salvaDados(numCli, numAli, cli, ali);
    }
  }
  PULA_LINHA;
  showListaAlimento();
}

// Descrição: Altera um cliente em "dados.txt"
void alterarAlimento(){

    FILE* arq;
    arq = fopen ("dados.txt","r");

    int numCli, numAli, x, f, fe=0, i, j;

    if (arq==NULL)
      fclose(arq);
    else{
      fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
      fclose(arq);
      if(numAli==0)
        printf(" Nenhum alimento registrado.\n Retornando ao menu anterior.");
      else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaAlimento();

      printf(" Digite o ID do alimento que deseja alterar.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numAli ; i++ )
        if(ali[i].id == x){
          f=1;
          break;
        } else
          f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numAli ; i++ )
          if(ali[i].id == x){
            f=1;
            break;
          }
      }

      printf(" Digite o nome do alimento. (Tamanho minimo de 2 caracteres)\n - ");
      LER_ESPACO;
      scanf("%[^\n]s", &ali[i].nome);

      printf(" Digite o preco do alimento.\n - ");
      scanf("%f", &ali[i].preco);

      printf(" Deseja inserir a marca do alimento?\n");
      printf(" 1 - Sim.\n");
      printf(" 0 - Nao.\n - ");
      scanf("%d", &x);
      while (x!=0&&x!=1){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
      }
      if (x) {
        printf(" Digite a marca do novo alimento.\n - ");
        LER_ESPACO;
        scanf("%[^\n]s", &ali[i].marca);
      }
      else
        strcpy(ali[i].marca,"-");

      if (testeRegrasDeValidacaoAlimento(ali[i])||fe)
          printf(" Nao foi possivel editar o alimento. Favor consultar o arquivo 'LogErro.txt' para mais informacoes\n");
      else
        salvaDados(numCli, numAli, cli, ali);
    }
  }
  PULA_LINHA;
  showListaCliente();
}

// Descrição: Printa na tela todas as informacoes de um alimento em especifico.
void consultarAlimento(){
  FILE* arq;
  arq = fopen ("dados.txt","r");

  int numCli, numAli, x, f, i, j, k;

  if (arq==NULL)
    fclose(arq);
  else{
    fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
    fclose(arq);
    if(numAli==0)
      printf(" Nenhum alimento registrado.\n Retornando ao menu anterior.");
    else{
      cliente cli[numCli];
      alimento ali[numAli];

      lerDados(&numCli, &numAli, cli, ali);

      showListaAlimento();

      printf(" Digite o ID do alimento que deseja alterar.\n - ");
      scanf("%d", &x);
      for ( i=0 ; i<numAli ; i++ )
        if(ali[i].id == x){
          f=1;
          break;
        } else
          f=0;

      while (f==0){
        printf(" Comando invalido. digite novamente.\n - ");
        scanf("%d", &x);
        for ( i=0 ; i<numAli ; i++ )
          if(ali[i].id == x){
            f=1;
            break;
          }
      }
      PULA_LINHA;

      printf(" Id: %d\n", ali[i].id);
      printf(" Nome: %s\n", ali[i].nome);
      printf(" Preco: %.2f\n", ali[i].preco);
      printf(" Marca: %s\n", ali[i].marca);
    }
  }
  PULA_LINHA;
}

// Descrição: Interface com menu para cadastro de alimentos.
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
    printf(" Comando invalido. digite novamente.\n - ");
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

// Descrição: Gera o arquivo "Relatorio%4d.txt" com todos os dados organizados de "dados.txt".
int gerarRelatorio(){

    int i, j, k , numCli, numAli, ran;
    char nomRel[MAXCHAR];
    FILE *arqRel, *arqTem;

    FILE* arq;
    arq = fopen ("dados.txt","r");

    if (arq==NULL){
      printf(" Arquivo de dados nao encontrado.\n Retornando ao menu anterior.");
      return 0;
    }
    else
    {
      fscanf(arq, "%d%*c%d%*c", &numCli, &numAli);
      fclose(arq);
    }
    cliente cli[numCli];
    alimento ali[numAli];

    lerDados(&numCli, &numAli, cli, ali);

    srand(time(NULL));
    ran = rand();
    arqTem = fopen("arqTem.txt","w");
    fprintf(arqTem,"Relatorio%4d.txt", ran);
    fclose (arqTem);
    arqTem = fopen("arqTem.txt","r");
    fscanf(arqTem,"%s", &nomRel);
    fclose (arqTem);
    remove("arqTem.txt");

    arqRel = fopen (nomRel,"w");

    fprintf(arqRel, "Informacoes a respeitos dos clientes:");
    for ( i = 0 ; i < numCli ; i++ ) {
      fprintf(arqRel, "\n Id: %d\n", cli[i].id);
      fprintf(arqRel, " Nome: %s\n", cli[i].nomCom);
      fprintf(arqRel, " Numero de viagens: %d\n", cli[i].numVia);
      fprintf(arqRel, " Historico completo:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        fprintf(arqRel, " [%d] ", cli[i].hisCom[j]);
      fprintf(arqRel,"\n Historico atual:");
      for ( j = 0 ; j < cli[i].numHis ; j++ )
        for ( k = 0 ; k < numAli ; k++ )
          if ( ali[k].id == cli[i].hisCom[j] )
            fprintf(arqRel," [%d] ", cli[i].hisCom[j]);
    }
    fprintf(arqRel, "\n\nInformacoes a respeitos dos alimentos:\n");
    for ( i = 0 ; i < numAli ; i++ ) {
      fprintf(arqRel, " Id: %d\n", ali[i].id);
      fprintf(arqRel, " Nome: %s\n", ali[i].nome);
      fprintf(arqRel, " Preco: %.2f\n", ali[i].preco);
      fprintf(arqRel, " Marca: %s\n", ali[i].marca);
    }

    printf(" Arquivo criado com o nome '%s'. Retornando ao menu principal\n\n", nomRel);

    fclose(arqRel);
    return 1;

}

// Descrição: Interface principal. Decide se vai para a interface de cliente, de alimentos, ou gera um relatorio.
int interfacePrincipal(){
  int x;
  printf(" Bem vindo a interface principal. Escolha uma opcao.\n");
  printf(" 1 - Cadastro de clientes. (inserir/remover/alterar/consultar)\n");
  printf(" 2 - Cadastro de alimentos. (inserir/remover/alterar/consultar)\n");
  printf(" 3 - Gerar relatorio de informacoes.\n");
  printf(" 0 - Finalizar programa.\n - ");
  scanf("%d", &x);
  while (x<0||x>3){
    printf(" Comando invalido. digite novamente.\n - ");
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

int main(){
  while (interfacePrincipal());
  printf(" Programa finalizado.\n");
  return 0;
}
