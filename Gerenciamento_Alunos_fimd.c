#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 


int registro(){
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Cpf a cadastrar: \n");
    scanf("%s", &cpf);

    strcpy(arquivo, cpf);

    FILE *file; //Cria arquivo
    file = fopen(arquivo, "w"); //Escreve dentro
    fprintf(file,cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Nome: ");
    scanf("%s", &nome);

    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Sobrenome: ");
    scanf("%s", &sobrenome);

    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Cargo: ");
    scanf("%s", &cargo);

    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");
}

int consulta(){
    char cpf[40];
    char conteudo[200];

    printf("Qual CPF quer consultar? \n");
    scanf("%s", &cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL){
            printf("Nao foi possivel abrir");
        }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas sao as informacoes: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deleta(){
    char cpf[40];

    printf("Digite o CPF a deletar: ");
    scanf("%s",&cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL){
        printf("Nao existente!");
        system("pause");
    }


    system("pause");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    int laco = 1;

    for(laco=1;laco=1;){

        printf("\n### Cartorio da Ebac ###\n\n");
        printf("Escolha a opcao: \n\n");
        printf("\t1 - Registrar nomes: \n"); // \t = Tab
        printf("\t2 - Consultar nomes: \n");
        printf("\t3 - Deletar nomes: \n");
        printf("Opcao: \n");

        scanf("%d", &opcao);

        system("cls"); // Limpar Terminal

        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deleta();
            break;

            default:
            printf("Indisponivel");
            system("pause");
            break;
        }

    }

    return 0;
}