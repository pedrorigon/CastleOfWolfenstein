/*
Escreva um programa que l� os dados de estudantes do ensino m�dio que prestaram ENEM. O seu
programa deve armazenar numa struct os dados: nome do aluno (arranjo com 60 caracteres), a
idade do aluno e a m�dia final que o aluno obteve (inteiro entre 0 e 100, n�o precisa fazer
consist�ncia). Leia os dados e armazene num arquivo bin�rio cujo nome ser� lido do usu�rio. O
programa deve parar de ler dados quando o usu�rio digitar a string �sair� para o nome do aluno.
Ap�s a leitura e armazenamento dos dados no arquivo, o programa deve solicitar ao usu�rio uma
m�dia qualquer e o programa deve listar o nome e m�dia de todos os alunos que tiveram m�dia
maior ou igual � m�dia informada. Ainda deve informar a idade m�dia de todos os alunos que
prestaram ENEM. Estas informa��es devem ser obtidas a partir da leitura do arquivo salvo.
Abaixo exemplo de execu��o:

Entradas:op��es do menu, codigo de compara��o e dados da struct
saidas:Dados sobre os veiculos, avisos de erro e menu.

C:\Users\pedro\Desktop\1SEMESTREUFRGS\Algoritmos_e_programa�ao\programas_Algoritmos\pratica13

*/
//Pedro henrique Casarotto Rigon
//07.05.2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define NUM 60

typedef struct
{
    int score;
    char name[NUM+1];
} Player;

void procura_media(FILE *arq, int comp_media);

//void calcula_idade_media(FILE *arq);

int main(void)
{
    Player a;
    FILE *arq;
    char arq_name[NUM+1], teste_name[NUM+1];
    int i=0, comp_media=0;


    if(!(arq = fopen("Highscore.bin","ab+")))
    {
        printf("Erro na criacao do arquivo");
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("Nome: ");
            fgets(teste_name, NUM+1, stdin);
            teste_name[strlen(teste_name)-1]='\0';
            i = (strcmp(teste_name, "sair"));
            if(i!=0)
            {
                for(i=0;i<strlen(teste_name-1);i++){
                    a.name[i]=teste_name[i];
                }
                printf("Score: ");
                scanf("%d",&a.score);
                printf("\n");
                if(fwrite(&a, sizeof(Player), 1, arq) != 1)
            {
                printf("Erro de escrita\n");
            }
            }
        }
        while(i != 0);

        fclose(arq);

    }

    if(!(arq = fopen("Highscore.bin","rb")))
    printf("Erro abertura");
    else{

    printf("\n");
    printf("Entre com a media para busca: ");
    scanf("%d", &comp_media);

    printf("Alunos com media maior ou igual a %d:\n", comp_media);
    procura_media(arq, comp_media);

    //calcula_idade_media(arq);

    fclose(arq); //fecha

    }

    return 0;
}

void procura_media(FILE *arq, int comp_media)
{
    Player a;

    rewind(arq); // retorna ao inicio do arquivo
    while(!feof(arq))
    {
        if(fread(&a, sizeof(Player), 1, arq) == 1)
        if(a.score >= comp_media)
            {
                printf("Nome: %s   Score: %d \n", a.name, a.score);
            }
    }

}

/*void calcula_idade_media(FILE *arq)
{
    ALUNO a;
    float idade_temp = 0, media_idade=0;
    int cont = 0;

    rewind(arq); // retorna ao inicio do arquivo
    while(!feof(arq))
    {
        if(fread(&a, sizeof(Player), 1, arq) == 1)
        {
            idade_temp += a.idade;
            cont++;
        }
    }

    media_idade = idade_temp / (cont);
    printf("Idade media de todos alunos %.2f", media_idade);
}

*/
