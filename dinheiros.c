#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



void L(){
    printf("\n\n");
}


int main(){

    L();

    printf("Para todas as perguntas:\nResponda apenas com '1' se a resposta for sim ou '2' se a resposta for nao");

    L();

    printf("Pressione qualquer tecla para continuar.");

    getch();

    system("cls");


    printf("*******************************************\n");
    printf("*   Para salvar o progresso voce devera   *\n");
    printf("* encerrar o programa pelo menu principal *\n");
    printf("*      Caso contrario,  voce perdera      *\n");
    printf("*        tudo que fez nesta sessao        *\n");
    printf("*******************************************\n");

    L();

    printf("Pressione qualquer tecla para continuar.");

    getch();

    system("cls");

    printf("Voce esta prestes a iniciar o programa.\n\n");
    printf("Isto implica que os dados atuais serao atualizados tal como os anteriores.\n\n");
    printf("Deseja iniciar o programa?\nResposta: ");

    int R1;

    scanf(" %i", &R1);

    L();

    while(R1!=1 && R1!=2){
        printf("Voce digitou algo diferente de '1' ou '2'.\nPor favor digite '1' para sim ou '2' para nao.");
        printf("Deseja iniciar o programa?\nResposta: ");
        scanf(" %i", &R1);
        L();
    }

    if(R1==1){
        printf("Voce tem certeza que deseja continuar?\nResposta: ");
        scanf(" %i", &R1);
    }

    while(R1!=1 && R1!=2){
        printf("Voce digitou algo diferente de '1' ou '2'.\nPor favor digite '1' para sim ou '2' para nao.");
        printf("Voce tem certeza que deseja continuar?\nResposta: ");
        scanf(" %i", &R1);
        L();
    }

    if (R1==2){
        printf("OK. Finalizando o programa.");
        L();
        exit(1);
    }



    //variaveis do arquivo
    int execucoes;
    float saldo = 0;
    float D1 = 0, D2 = 0, D3 = 0, D4 = 0, D5 = 0, D6 = 0, D7 = 0, D8 = 0, D9 = 0, D10 = 0;
    float E1 = 0, E2 = 0, E3 = 0, E4 = 0, E5 = 0, E6 = 0, E7 = 0, E8 = 0, E9 = 0, E10 = 0;
    //variaveis comecadas em D ou E e seguidas de numero sao, respectivamente, despesas e entradas



    //abertura do arquivo anterior_1 para armazenamento no anterior_2
    FILE* copia_1 = fopen("anterior_1.txt", "r");

    if(copia_1 == NULL){
        printf("Houve um erro ao executar o arquivo.\nEh inexistente ou esta corrompido.\nEncerrando o programa.");
        exit(1);
    }

    //scan dos dados do arquivo anterior_1
    fscanf(copia_1, " %i %f", &execucoes, &saldo);
    fscanf(copia_1, " %f %f %f %f %f %f %f %f %f %f", &D1, &D2, &D3, &D4, &D5, &D6, &D7, &D8, &D9, &D10);
    fscanf(copia_1, " %f %f %f %f %f %f %f %f %f %f", &E1, &E2, &E3, &E4, &E5, &E6, &E7, &E8, &E9, &E10);

    fclose(copia_1);

    FILE* cola_1 = fopen("anterior_2.txt", "w");

    fprintf(cola_1, " %i %f", execucoes, saldo);
    fprintf(cola_1, " %f %f %f %f %f %f %f %f %f %f", D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
    fprintf(cola_1, " %f %f %f %f %f %f %f %f %f %f", E1, E2, E3, E4, E5, E6, E7, E8, E9, E10);

    fclose(cola_1);



    //abertura do arquivo gastos para armazenamento no anterior_1
    FILE* copia_2 = fopen("gastos.txt", "r");

    if(copia_2 == NULL){
        printf("Houve um erro ao executar o arquivo.\nEh inexistente ou esta corrompido.\nEncerrando o programa.");
        exit(1);
    }

    //scan dos dados do arquivo gastos
    fscanf(copia_2, " %i %f", &execucoes, &saldo);
    fscanf(copia_2, " %f %f %f %f %f %f %f %f %f %f", &D1, &D2, &D3, &D4, &D5, &D6, &D7, &D8, &D9, &D10);
    fscanf(copia_2, " %f %f %f %f %f %f %f %f %f %f", &E1, &E2, &E3, &E4, &E5, &E6, &E7, &E8, &E9, &E10);

    fclose(copia_2);

    FILE* cola_2 = fopen("anterior_1.txt", "w");

    fprintf(cola_2, " %i %f", execucoes, saldo);
    fprintf(cola_2, " %f %f %f %f %f %f %f %f %f %f", D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
    fprintf(cola_2, " %f %f %f %f %f %f %f %f %f %f", E1, E2, E3, E4, E5, E6, E7, E8, E9, E10);

    fclose(cola_2);



    //armazenamento dos dados da ultima sessao para o programa
    FILE* dinheiro = fopen("gastos.txt", "r");

    if(dinheiro == NULL){
        printf("Houve um erro ao executar o arquivo.\nEh inexistente ou esta corrompido.\nEncerrando o programa.");
        exit(1);
    }

    //scan dos dados do arquivo gastos
    fscanf(dinheiro, " %i %f", &execucoes, &saldo);
    fscanf(dinheiro, " %f %f %f %f %f %f %f %f %f %f", &D1, &D2, &D3, &D4, &D5, &D6, &D7, &D8, &D9, &D10);
    fscanf(dinheiro, " %f %f %f %f %f %f %f %f %f %f", &E1, &E2, &E3, &E4, &E5, &E6, &E7, &E8, &E9, &E10);

    fclose(dinheiro);



    //onde a magica acontece
    int novo = 1;
    int i = 0;
    float entrada;
    float saida;

    execucoes++;

    while(novo==1){
        system("cls");
        L();
        printf("Se deseja verificar o seu saldo, digite 1.\n");
        printf("Se deseja adicionar dinheiro ao seu saldo, digite 2.\n");
        printf("Se deseja retirar dinheiro do seu saldo, digite 3.\n");
        printf("Se deseja verificar as ultimas 10 entradas do seu saldo, digite 4.\n");
        printf("Se deseja verificar as ultimas 10 despesas em seu saldo, digite 5.\n");
        printf("Se deseja ver o numero de vezes que o programa foi executado, digite 8.\n");
        printf("Se deseja sair do programa, digite 9.");
        L();
        printf("Resposta: ");
        scanf(" %i", &R1);
        L();

        while(R1!=1 && R1!=2 && R1!=3 && R1!=4 && R1!=5 && R1!=8 && R1!=9){

            system("cls");

            L();
            printf("Se deseja verificar o seu saldo, digite 1.\n");
            printf("Se deseja adicionar dinheiro ao seu saldo, digite 2.\n");
            printf("Se deseja retirar dinheiro do seu saldo, digite 3.\n");
            printf("Se deseja verificar as ultimas 10 entradas do seu saldo, digite 4.\n");
            printf("Se deseja verificar as ultimas 10 despesas em seu saldo, digite 5.\n");
            printf("Se deseja ver o numero de vezes que o programa foi executado, digite 8.\n");
            printf("Se deseja sair do programa, digite 9.");
            L();
            printf("Voce digitou algo diferente dos numeros listados.\nPor favor digite um dos numeros da lista.");
            printf("Resposta: ");
            scanf(" %i", &R1);
        }

        if(R1==1){
            system("cls");

            L();
            printf("Seu saldo atual eh de: %.2f unidades!", saldo);
            L();
            printf("Pressione qualquer tecla para voltar ao menu principal.");
            getch();
        }

        if(R1==2){
            system("cls");
            i=0;

            L();
            printf("Quanto deseja adicionar a seu saldo?\nResposta: ");
            scanf(" %f", &entrada);
            while(entrada<0 && i<3){
                i++;
                L();
                printf("Voce inseriu um numero menor que 0.\n");
                printf("\nSe deseja retirar dinheiro de seu saldo: insira 0 e proceda para o menu de retirada, indice 3.\n\n");
                printf("Por favor, insira o valor que deseja adicionar a seu saldo.\nResposta: ");
                scanf(" %f", &entrada);
            }
            if(i==3){
                system("cls");
                L();
                printf("Voce digitou 4 vezes um numero menor que 0.\nCancelei a operacao e voce voltara para o menu principal.");
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
            if(entrada==0){
                system("cls");
                printf("Voce digitou 0, portanto cancelei a operacao e voce voltara para o menu principal");
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
            if(entrada>0){
                E10=E9;
                E9=E8;
                E8=E7;
                E7=E6;
                E6=E5;
                E5=E4;
                E4=E3;
                E3=E2;
                E2=E1;
                E1=entrada;
                saldo+=entrada;
                system("cls");
                printf("O valor de %.2f unidades foi adicionado ao seu saldo!", entrada);
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
        }

        if(R1==3){
            system("cls");
            i=0;

            L();
            printf("Quanto deseja retirar do seu saldo?\nResposta: ");
            scanf(" %f", &saida);
            while(saida<0 && i<3){
                i++;
                L();
                printf("Voce inseriu um numero menor que 0.\n");
                printf("\nSe deseja adicionar dinheiro de seu saldo: insira 0 e proceda para o menu de adicionar, indice 2.\n\n");
                printf("Por favor, insira o valor que deseja retirar de seu saldo.\nResposta: ");
                scanf(" %f", &saida);
            }
            if(i==3){
                system("cls");
                L();
                printf("Voce digitou 4 vezes um numero menor que 0.\nCancelei a operacao e voce voltara para o menu principal.");
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
            if(entrada==0){
                system("cls");
                printf("Voce digitou 0, portanto cancelei a operacao e voce voltara para o menu principal");
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
            if(saida>0){
                D10=D9;
                D9=D8;
                D8=D7;
                D7=D6;
                D6=D5;
                D5=D4;
                D4=D3;
                D3=D2;
                D2=D1;
                D1=saida;
                saldo-=saida;
                system("cls");
                printf("O valor de %.2f unidades foi retirado do seu saldo!", saida);
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
        }

        if(R1==4){
            system("cls");
            L();
            printf("Suas ultimas 10 entradas de dinheiro foram:\n");
            printf("(mais novo)\n");
            printf(" 1 - %.2f\n", E1);
            printf(" 2 - %.2f\n", E2);
            printf(" 3 - %.2f\n", E3);
            printf(" 4 - %.2f\n", E4);
            printf(" 5 - %.2f\n", E5);
            printf(" 6 - %.2f\n", E6);
            printf(" 7 - %.2f\n", E7);
            printf(" 8 - %.2f\n", E8);
            printf(" 9 - %.2f\n", E9);
            printf("10 - %.2f\n", E10);
            printf("(mais antigo)");
            L();
            printf("Pressione qualquer tecla para voltar ao menu principal.");
            getch();
        }

        if(R1==5){
            system("cls");
            L();
            printf("Suas ultimas 10 despesas de dinheiro foram:\n");
            printf("(mais novo)\n");
            printf(" 1 - %.2f\n", D1);
            printf(" 2 - %.2f\n", D2);
            printf(" 3 - %.2f\n", D3);
            printf(" 4 - %.2f\n", D4);
            printf(" 5 - %.2f\n", D5);
            printf(" 6 - %.2f\n", D6);
            printf(" 7 - %.2f\n", D7);
            printf(" 8 - %.2f\n", D8);
            printf(" 9 - %.2f\n", D9);
            printf("10 - %.2f\n", D10);
            printf("(mais antigo)");
            L();
            printf("Pressione qualquer tecla para continuar.");
            getch();
        }

        if(R1==8){
            system("cls");
            L();
            printf("O programa ja foi executado %i vezes.", execucoes);
            L();
            printf("Pressione qualquer tecla para voltar ao menu principal.");
            getch();
        }

        if(R1==9){
            system("cls");
            printf("Responda apenas com '1' se a resposta for sim ou '2' se a resposta for nao.");
            L();
            printf("Deseja mesmo finalizar o programa?\nResposta: ");
            scanf(" %i", &R1);
            while(R1!=1 && R1!=2){
                system("cls");
                printf("Voce digitou algo diferente de '1' ou '2'.\nPor favor digite '1' para sim ou '2' para nao.");
                printf("Deseja mesmo finalizar o programa?\nResposta: ");
                scanf(" %i", &R1);
                L();
            }

            if(R1==1){
                system("cls");
                novo=0;
            }
            if(R1==2){
                system("cls");
                printf("Finalizacao do programa cancelada pelo usuario.");
                L();
                printf("Pressione qualquer tecla para voltar ao menu principal.");
                getch();
            }
        }

    }

    FILE* final = fopen("gastos.txt", "w");

    fprintf(final, " %i %f", execucoes, saldo);
    fprintf(final, " %f %f %f %f %f %f %f %f %f %f", D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
    fprintf(final, " %f %f %f %f %f %f %f %f %f %f", E1, E2, E3, E4, E5, E6, E7, E8, E9, E10);

    fclose(final);



    system("cls");
    printf("Obrigado por utilizar nosso programa!\nAte a proxima!\n");
    L();
    L();
    printf("\n:3  :3  :3  :3  :3  :3\n\n");
    L();
    L();
    printf("By: MontebellerZ");
    L();
    L();
    L();

    return 0;
}
