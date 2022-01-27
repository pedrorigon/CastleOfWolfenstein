/*
Escreva um programa que lê os dados de estudantes do ensino médio que prestaram ENEM. O seu
programa deve armazenar numa struct os dados: nome do aluno (arranjo com 60 caracteres), a
idade do aluno e a média final que o aluno obteve (inteiro entre 0 e 100, não precisa fazer
consistência). Leia os dados e armazene num arquivo binário cujo nome será lido do usuário. O
programa deve parar de ler dados quando o usuário digitar a string “sair” para o nome do aluno.
Após a leitura e armazenamento dos dados no arquivo, o programa deve solicitar ao usuário uma
média qualquer e o programa deve listar o nome e média de todos os alunos que tiveram média
maior ou igual à média informada. Ainda deve informar a idade média de todos os alunos que
prestaram ENEM. Estas informações devem ser obtidas a partir da leitura do arquivo salvo.
Abaixo exemplo de execução:

Entradas:opções do menu, codigo de comparação e dados da struct
saidas:Dados sobre os veiculos, avisos de erro e menu.

C:\Users\pedro\Desktop\1SEMESTREUFRGS\Algoritmos_e_programaçao\programas_Algoritmos\pratica13

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
