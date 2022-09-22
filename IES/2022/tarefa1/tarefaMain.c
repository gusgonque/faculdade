#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Estrutura de dados para datas.
typedef struct{
    int dia;
    int mes;
    int ano;
} data;

//Estrutura de dados para celulares.
typedef struct{
    char marca[MAX];
    char modelo[MAX];
    char servico[MAX];
    float custo;
} celular;

//Estrutura de dados para clientes.
typedef struct{
    char nome[MAX];
    char numTel[MAX];   //  Num de telefone do cliente.
} cliente;

//Estrutura de dados para as ordens de serviço.
typedef struct{
    data datSol;    // Data solicitação
    data datEnt;    // Data entrega
    cliente cli;    // Dono do telefone
    int numCel;     // Núm de telefones
    celular cel[MAX];//Telefones
} ordem_servico;

//apresenta a interface ao usuário.
int interfacePrincipal(){
    int x;
    printf("Bem vindo ao sistema de controle de ordem de servico.\nPara continuar, selecione uma opcao.\n");
    printf("1 - Adicionar novo servico.\n");
    printf("2 - Custo total em um mes.\n");
    printf("3 - Custo total em um ano.\n");
    printf("0 - Finalizar programa.\n");
    printf(" - ");
    scanf("%d", &x);
    while(x>3 || x<0){
        printf("Opcao invalida, digite novamente.\n");
        printf(" - ");
        scanf("%d", &x);
    }
    return x;
}

//adiciona o cliente e a data da ordem
void addClienteData(int *numOrdens, ordem_servico *ordens) {
    printf("Bem vindo a tela de registro de uma ordem de servico, sua ordem de servico tem o codigo [%d].\nEscreva o nome do cliente.\n - ", *numOrdens);
    scanf("%s", ordens[*numOrdens].cli.nome);
    printf("Escreva o número de telefone do cliente.\n - ");
    scanf("%s", ordens[*numOrdens].cli.numTel);
    printf("Cliente registrado como: %s.\n", ordens[*numOrdens].cli.nome);
    printf("Digite a data de solicitacao do servico, no formato 'dd mm aaaa'.\n");
    scanf("%d %d %d", &ordens[*numOrdens].datSol.dia, &ordens[*numOrdens].datSol.mes, &ordens[*numOrdens].datSol.ano);
    printf("Digite a data de entrega do servico, no formato 'dd mm aaaa'.\n");
    scanf("%d %d %d", &ordens[*numOrdens].datEnt.dia, &ordens[*numOrdens].datEnt.mes, &ordens[*numOrdens].datEnt.ano);
}

void addCelular(int numOrdem, int numCel, ordem_servico *ordens){
    printf("Digite a marca do telefone.\n");
    scanf("%s", ordens[numOrdem].cel[numCel].marca);
    printf("Digite o modelo do telefone.\n");
    scanf("%s", ordens[numOrdem].cel[numCel].modelo);
    printf("Digite o servico do telefone.\n");
    scanf("%s", ordens[numOrdem].cel[numCel].servico); // Só escaneia uma linha, sem tempo pra resolver
    printf("Digite o custo do servico.\n");
    scanf("%f", &ordens[numOrdem].cel[numCel].custo);
    printf("Telefone adicionado com sucesso!\n");
}

int interfaceRegistro(){
    int x;
    printf("Para continuar, selecione uma opcao.\n");
    printf("1 - Adicionar novo celular.\n");
    printf("0 - Retornar ao menu anterior.\n - ");
    printf(" - ");
    scanf("%d", &x);
    while(x>2 || x<0){
        printf("Opcao invalida, digite novamente.\n");
        printf(" - ");
        scanf("%d", &x);
    }
    return x;
}

void addServico(int * numOrdens, ordem_servico * ordens){
    addClienteData(numOrdens, ordens);
    ordens[*numOrdens].numCel = 0;
    int x = interfaceRegistro();
    while (x != 0) {

        addCelular(*numOrdens, ordens[*numOrdens].numCel, ordens);
        ordens[*numOrdens].numCel ++;

        x = interfaceRegistro();
    }
}

//Imprime o custo total naquele mes
void consultarMes(int numOrdens, ordem_servico * ordens) {
    float custoTotal = 0;
    int i, j, x;
    printf("Digite o mes que deseja consultar o custo total das solicitacoes.\n");
    scanf("%d", &x);
    for (i = 0; i < numOrdens; ++i)
        if(ordens[i].datSol.mes == x)
            for (j = 0; j < ordens[i].numCel; ++j)
                custoTotal += ordens[i].cel[j].custo;
    printf("O custo total nesse mes foi de %f\n", custoTotal);
}

//Imprime o custo total naquele ano
void consultarAno(int numOrdens, ordem_servico * ordens) {
    float custoTotal = 0;
    int i, j, x;
    printf("Digite o ano que deseja consultar o custo total das solicitacoes.\n");
    scanf("%d", &x);
    for (i = 0; i < numOrdens; ++i)
        if(ordens[i].datSol.ano == x)
            for (j = 0; j < ordens[i].numCel; ++j)
                custoTotal += ordens[i].cel[j].custo;
    printf("O custo total nesse ano foi de %f\n", custoTotal);
}

// Chama as funções.
int main(){
    
    ordem_servico *ordens = (ordem_servico *) malloc(MAX * sizeof(ordem_servico));
    int numOrdens = 0;
    int x;
    
    x = interfacePrincipal();
    while (x != 0)
        switch (x) {
            case 1:
                addServico(&numOrdens, ordens);
                x = interfacePrincipal();
                break;
            case 2:
                consultarMes(numOrdens, ordens);
                x = interfacePrincipal();
                break;
            case 3:
                consultarAno(numOrdens, ordens);
                x = interfacePrincipal();
                break;
        }
    

    return 0;
}
