#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lmath.h"

typedef struct
{
    int tam;
    float numbers[1000];
} structNumber;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    char cont;
    int function = 0;
    float result = 0;

    char name[100];

    system("clear");

    printf("\nCalculadora lMath");
    printf("\n\nGuardamos todos os seus calculos em um arquivo de texto para você não esquecer.");
    printf("\n\nDigite seu nome: ");
    scanf("%s", name);

    FILE *file = fopen(strcat(name, "-lmath.txt"), "a");

    if (file == NULL)
    {
        printf("Um erro foi encontrado durante a abertura do arquivo.");
    }
    else
    {

        if (ftell(file) == 0)
        {
            fprintf(file, "Usúario: %s", name);
            fprintf(file, "\n\nCalculos efetuados:");
        }

        do
        {

            system("clear");

            printf("\nCalculadora: ");
            printf("\nFunções disponíveis para calculo: ");
            printf("\n 1 - Soma");
            printf("\n 2 - Subtração");
            printf("\n 3 - Multiplicação");
            printf("\n 4 - Divisão");
            printf("\n 5 - Potenciação");
            printf("\n 6 - Porcentagem");
            printf("\n 7 - Moda");
            printf("\n 8 - Mediana");
            printf("\n 9 - Media");
            printf("\n 10 - Fatorial");
            printf("\n 11 - Combinação");
            printf("\n 12 - Fibonacci");
            printf("\n 0 - Para sair do programa");

            printf("\nDigite uma das opções acima: ");
            scanf("%d", &function);

            if (getFunction(function, file, &result) != -1)
            {

                printf("\nResultado da operação: %g", result);
                printf("\nPressione alguma tecla + Enter para continuar\n");

                scanf("%c", &cont);
                getchar();
            }

        } while (function != 0);
    }

    return 0;
}

int getFunction(int function, FILE *file, float *result)
{

    system("clear");

    structNumber sNum;

    switch (function)
    {
    case 1:

        printf("Digite o primeiro número para efetuar a soma: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite o segundo número para efetuar a soma: ");
        scanf("%f", &sNum.numbers[1]);

        *result = sum(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nSoma entre (%g + %g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 2:

        printf("Digite o primeiro número para efetuar a subtração: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite o segundo número para efetuar a subtração: ");
        scanf("%f", &sNum.numbers[1]);

        *result = subtract(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nSubtração entre (%g - %g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 3:

        printf("Digite o primeiro número para efetuar a multiplicação: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite o segundo número para efetuar a multiplicação: ");
        scanf("%f", &sNum.numbers[1]);

        *result = multiplier(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nMultiplicação entre (%g x %g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 4:

        printf("Digite o primeiro número para efetuar a divisão: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite o segundo número para efetuar a divisão: ");
        scanf("%f", &sNum.numbers[1]);

        *result = division(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nDivisão entre (%g / %g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 5:

        printf("Digite a base para efetuar a potenciação: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite o expoente para efetuar a potenciação: ");
        scanf("%f", &sNum.numbers[1]);

        *result = pow(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nPotenciação entre (%g^%g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 6:

        printf("Digite um número para efetuar a porcentagem: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite quantos '%' você quer desse número: ");
        scanf("%f", &sNum.numbers[1]);

        *result = percent(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\n%g% de %g resultou em: %g;", sNum.numbers[1], sNum.numbers[0], *result);

        break;

    case 7:

        structList(&sNum, "Moda");
        *result = mode(sNum.numbers, sNum.tam);

        structListResult(sNum, file, "Moda", result);

        break;

    case 8:

        structList(&sNum, "Mediana");
        *result = mediana(&sNum.numbers, sNum.tam);

        structListResult(sNum, file, "Mediana", result);

        break;

    case 9:

        structList(&sNum, "Média");
        *result = average(sNum.numbers, sNum.tam);

        structListResult(sNum, file, "Média", result);

        break;

    case 10:

        printf("Digite um número para calcular o fatorial: ");
        scanf("%f", &sNum.numbers[0]);

        *result = fatorial(sNum.numbers[0]);

        fprintf(file, "\nFatorial de %g resultou em: %g;", sNum.numbers[0], *result);

        break;

    case 11:

        printf("Digite um número de elementos totais: ");
        scanf("%f", &sNum.numbers[0]);

        printf("Digite um número para os elementos serem combinados: ");
        scanf("%f", &sNum.numbers[1]);

        *result = combination(sNum.numbers[0], sNum.numbers[1]);

        fprintf(file, "\nPossibilidades de combinação de (%g em %g) resultou em: %g;", sNum.numbers[0], sNum.numbers[1], *result);

        break;

    case 12:

        printf("Digite uma posição para ver o número em fibonacci: ");
        scanf("%f", &sNum.numbers[0]);

        *result = fibonacci(sNum.numbers[0]);

        fprintf(file, "\nO resultado na posição %d na sequencia de fibonacci resultou em: %g;", sNum.numbers[0], *result);

        break;

    default:
        return -1;
    }

    fcloseall();

    return 1;
}

void structList(structNumber *sNum, char name[])
{

    do
    {

        printf("Digite quantos números você deseja alocar para efetuar o calculo da %s: ", name);
        scanf("%d", &sNum->tam);

    } while (sNum->tam < 1 || sNum->tam > 1000);

    for (int i = 0; i < sNum->tam; i++)
    {
        printf("Digite o número %d para encontrar a %s: ", i + 1, name);
        scanf("%f", &sNum->numbers[i]);
        system("clear");
    }

    printf("Lista de números: ");

    ascList(sNum->numbers, sNum->tam);

    for (int i = 0; i < sNum->tam; i++)
        printf("%g,", sNum->numbers[i]);
}

void structListResult(structNumber sNum, FILE *file, char name[], float *result)
{

    fprintf(file, "\nA %s dos números ", name);

    for (int i = 0; i < sNum.tam; i++)
    {

        if (i == (sNum.tam - 1))
        {
            fprintf(file, "%g", sNum.numbers[i]);
        }
        else
        {
            fprintf(file, "%g, ", sNum.numbers[i]);
        }
    }

    fprintf(file, " é: %g;", *result);
}