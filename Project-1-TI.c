#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

				//Int e uma funcao

int registro() //responsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao de variaveis/string=conjunto de vaiaveis
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criacao de variaveis/string=conjunto de vaiaveis
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" significa digitar um novo arquivo
	fprintf(file,"\n CPF: ");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo !importante!
	
	file = fopen(arquivo,"a"); //edita o arquivo ja criado "a"
	fprintf(file,"\n NOME: ");
	fclose(file);
	
	printf("\nDigite o primeiro nome: \n");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n SOBRENOME: ");
	fclose(file);
	
	printf("\nDigite o sobrenome: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n CARGO: ");
	fclose(file);

	printf("\nDigite o cargo: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("CPF de consulta: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //"r" serve para ler as informacoes
	
	if(file == NULL) //Null = que nao existe ou n foi criado
	{
		printf("\n N�o foi poss�vel abrir arquivo, n�o localizado! \n\n");
	}
	
		printf("\n Informa��es do cadastro: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{
    char cpf[40];
	
    printf("Digite o CPF do cadastro a ser excluido: ");
    scanf("%s", cpf);
	
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("CPF nao encontrado!\n");
        system("pause");
        return 0;
    }
    
    fclose(file);
	
    if (remove(cpf) == 0) 
	{
        printf("CPF REMOVIDO COM SUCESSO!\n");
    } else {
        printf("Erro ao remover o arquivo.\n");
    }

    system("pause");
    return 0;
}


int main ()
{
	int opcao=0; //"op��o" foi indicada como vari�vel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Localizacao/Linguagem
	
		printf("\t\t\t\t\t\t*** Cart�rio da EBAC ***\n\n"); //Topo - Inicio
		printf("\t\t\t\t\tMuito bem-vindo! Como posso servir hoje? \n\n");
		printf("Selecione uma das seguintes op��es\n\n");
		printf("\t1 - Registrar novo aluno \n ");
		printf("\t2 - Consultar aluno \n");
		printf("\t3 - Excluir aluno \n\n\n"); 
		printf("Digite a op��o: ");//Fim menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls"); //limpar
	
		switch(opcao) // inicio da selecao de menu
		{
			case 1:
				registro(); //chamada de funcao
				break;
			
			case 2:
				consulta(); //chamada de funcao
				break;
			
			case 3:
				deletar(); //chamada de funcao
				break;
				
			default:
				printf("Essa op��o n�o est� dispon�vel no momento!\n");
				system("pause");
				break;
			
			//fim da selecao	
		}
	}
}



