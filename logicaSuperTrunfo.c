#include <stdio.h>

// Variáveis declaradas globalmente
typedef struct
{
    char estado;
    char codigoDaCarta[4];
    char nomeCidade[20];
    double populacao;
    int numeroPontosTuristicos;
    double area;
    double pib;
    double densidadePopulacional;
    double pibPerCapita;
    double superPoder;
} dadosCidade;

dadosCidade cidade[2];

// Calcula soma densidade
double somaDensidade(double populacaoValue, double areaValue)
{
    return populacaoValue / areaValue;
}

// Calcula soma pib per capita
double somaPibPerCapita(double pibValue, double populacaoValue)
{
    return (pibValue * 1000000000.0) / (float)populacaoValue;
}

int separador()
{
    printf("----------------------------\n");
    return 0;
}

int main()
{
    // loop com variáveis globais
    for (int i = 0; i < 2; i++)
    {
        // impressão de texto no terminal
        printf("Digite a inicial do Estado: ");
        // leitura de entrada do valor do usuário e alocação do valor na variável
        scanf(" %c", &cidade[i].estado);

        printf("Digite o código do Estado: ");
        scanf("%3s", cidade[i].codigoDaCarta);

        printf("Digite o nome do Estado: ");
        scanf("%s", cidade[i].nomeCidade);

        printf("Digite o valor da população do Estado: ");
        scanf("%lf", &cidade[i].populacao);

        printf("Digite a quantidade de pontos turisticos do Estado: ");
        scanf("%i", &cidade[i].numeroPontosTuristicos);

        printf("Digite a área do Estado: ");
        scanf("%lf", &cidade[i].area);

        printf("Digite o PIB do Estado: ");
        scanf("%lf", &cidade[i].pib);
        separador();
    }

    //loop para pegar valores de Densidade e PIBPerCapita
    for (int i = 0; i < 2; i++)
    {
        cidade[i].densidadePopulacional = somaDensidade(cidade[i].populacao, cidade[i].area);
        cidade[i].pibPerCapita = somaPibPerCapita(cidade[i].pib, cidade[i].populacao);
    }

    // Soma superPoder
    for (int i = 0; i < 2; i++)
    {
        cidade[i].superPoder = (cidade[i].populacao + cidade[i].area + cidade[i].pib + (double) cidade[i].numeroPontosTuristicos + cidade[i].pibPerCapita) - cidade[i].densidadePopulacional;
    }

    separador();

    // Impressão dos resultados
    for (int i = 0; i < 2; i++)
    {
        printf("Carta %d \n", i + 1);
        printf("Estado: %c \n", cidade[i].estado);
        printf("Código: %s \n", cidade[i].codigoDaCarta);
        printf("NomeDaCidade: %s \n", cidade[i].nomeCidade);
        printf("População: %lf \n", cidade[i].populacao);
        printf("Área: %.2lf KM² \n", cidade[i].area);
        printf("PIB: %.2lf bilhões de reais \n", cidade[i].pib);
        printf("NumeroDePontosTuristicos: %d \n", cidade[i].numeroPontosTuristicos);
        printf("DensidadePopulacional: %.2lf hab/km² \n", cidade[i].densidadePopulacional);
        printf("PibPerCapita: %.2lf reais \n", cidade[i].pibPerCapita);
        printf("SuperPoder: %.2lf \n", cidade[i].superPoder);

        separador();
    }

    int opcao;

    printf("Escolha uma valor para comparar as cartas: \n");
    printf("1 - População \n");
    printf("2 - Área \n");
    printf("3 - PIB \n");
    printf("4 - NumeroDePontosTuristicos \n");
    printf("5 - DensidadePopulacional \n");
    printf("6 - PibPerCapita \n");
    printf("7 - SuperPoder \n");
    printf("Opção escolhida: \n");
    scanf("%d", &opcao);
    
    separador();

    switch (opcao) {
    case 1:
        if(cidade[0].populacao == cidade[1].populacao) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].populacao, cidade[1].nomeCidade, cidade[1].populacao);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].populacao > cidade[1].populacao) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].populacao, cidade[1].nomeCidade, cidade[1].populacao);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].populacao, cidade[1].nomeCidade, cidade[1].populacao);
            printf("Carta 2 Venceu");
        }
        break;
    case 2:
        if(cidade[0].area == cidade[1].area) {
            printf("Atributo escolhido: Área \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].area, cidade[1].nomeCidade, cidade[1].area);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].area > cidade[1].area) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].area, cidade[1].nomeCidade, cidade[1].area);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].area, cidade[1].nomeCidade, cidade[1].area);
            printf("Carta 2 Venceu");
        }
        break;
    case 3:
        if(cidade[0].pib == cidade[1].pib) {
            printf("Atributo escolhido: PIB \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pib, cidade[1].nomeCidade, cidade[1].pib);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].pib > cidade[1].pib) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pib, cidade[1].nomeCidade, cidade[1].pib);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pib, cidade[1].nomeCidade, cidade[1].pib);
            printf("Carta 2 Venceu");
        }
        break;
    case 4:
        if(cidade[0].numeroPontosTuristicos == cidade[1].numeroPontosTuristicos) {
            printf("Atributo escolhido: NumeroPontosTuristicos \n");
            printf("%s : %d - %s : %d \n", cidade[0].nomeCidade, cidade[0].numeroPontosTuristicos, cidade[1].nomeCidade, cidade[1].numeroPontosTuristicos);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].numeroPontosTuristicos > cidade[1].numeroPontosTuristicos) {
            printf("Atributo escolhido: População \n");
            printf("%s : %d - %s : %d \n", cidade[0].nomeCidade, cidade[0].numeroPontosTuristicos, cidade[1].nomeCidade, cidade[1].numeroPontosTuristicos);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %d - %s : %d \n", cidade[0].nomeCidade, cidade[0].numeroPontosTuristicos, cidade[1].nomeCidade, cidade[1].numeroPontosTuristicos);
            printf("Carta 2 Venceu");
        }
        break;
    case 5:
        if(cidade[0].densidadePopulacional == cidade[1].densidadePopulacional) {
            printf("Atributo escolhido: DensidadePopulacional \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].densidadePopulacional, cidade[1].nomeCidade, cidade[1].densidadePopulacional);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].densidadePopulacional < cidade[1].densidadePopulacional) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].densidadePopulacional, cidade[1].nomeCidade, cidade[1].densidadePopulacional);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].densidadePopulacional, cidade[1].nomeCidade, cidade[1].densidadePopulacional);
            printf("Carta 2 Venceu");
        }
        break;
    case 6:
        if(cidade[0].pibPerCapita == cidade[1].pibPerCapita) {
            printf("Atributo escolhido: PibPerCapita \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pibPerCapita, cidade[1].nomeCidade, cidade[1].pibPerCapita);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].pibPerCapita > cidade[1].pibPerCapita) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pibPerCapita, cidade[1].nomeCidade, cidade[1].pibPerCapita);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].pibPerCapita, cidade[1].nomeCidade, cidade[1].pibPerCapita);
            printf("Carta 2 Venceu");
        }
        break;
    case 7:
        if(cidade[0].superPoder == cidade[1].superPoder) {
            printf("Atributo escolhido: SuperPoder \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].superPoder, cidade[1].nomeCidade, cidade[1].superPoder);
            printf("Valores iguais tentem novamente!\n");
        } else if(cidade[0].superPoder > cidade[1].superPoder) {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].superPoder, cidade[1].nomeCidade, cidade[1].superPoder);
            printf("Carta 1 Venceu");
        } else {
            printf("Atributo escolhido: População \n");
            printf("%s : %lf - %s : %lf \n", cidade[0].nomeCidade, cidade[0].superPoder, cidade[1].nomeCidade, cidade[1].superPoder);
            printf("Carta 2 Venceu");
        }
        break;    
    default:
        printf("Essa opção não existe, tente novamente!");
        break;
    }
    
    return 0;
}