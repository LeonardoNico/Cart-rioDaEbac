#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //repons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //repons�vel por pausar
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria arquivo
	 file = fopen(cpf,"r"); //abre o arquivo
	
	if(file == NULL) //compara��o do arquivo para caso n�o encontre 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{	//inicio da cria��o de vari�vel/string
	char cpf[40];
	//final da cria��o de vari�vel/string
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf); 
	
	FILE *file; //cria um arquivo
	file = fopen(cpf, "r"); //abre o arquivo e l� 
	
	if(file == NULL); //compara��o 
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //definindo linguagem 
	
		printf("### Cart�rio de us�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do menu?\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usu�rio 
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ter usado o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;	
		}
	
	
	}
}
