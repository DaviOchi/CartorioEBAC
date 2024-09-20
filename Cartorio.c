#include <stdio.h> //biblioteca de comunicacao com usuario 
#include <stdlib.h>//biblioteca de alocacao de espaco em memoria 
#include <locale.h>//biblioteca de alocacao de texto por regiao 
#include <string.h>//biblioteca responsavel por cuidar das strings

int registro()//funcao responsavel por cadastrar usuarios no sistema
{
	//inicio criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:");//coletando informacao do usuario
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	                                                                                                          
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file, "Seu CPF e:" );
	fprintf(file,cpf);//salva o valor da variavel  
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo arquivo ja existente
	fprintf(file,", ");//colocando uma virgula para que os dados fiquem separados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Seu nome e:");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file, "seu Sobrenome e:");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	 
	file = fopen (arquivo, "a");
	fprintf(file, "Seu cargo e:");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Cadastro realizado com sucesso!.\n");
	 
	system("pause");
	 
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem para manter acentuacao
	//definindo e redefinindo as variaveis/strings
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//solicitando elemento de consulta
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");//Ler o arquivo existente
	
	if(file == NULL)//validando se o arquivo e valido/existente
	{
		printf("Nao foi possivel abrir o arquivo, Usuario nao se encontra no sistema!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//busca o conteudo utilizando while= enquanto o resultado nao for nulo ele nao saira da funcao 
	{
		printf("\n Essas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	//redefinindo variavel/string
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");//solicitando conteudo a ser excluido
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)//verificando se o conteudo e valido/existente
	{
		printf("o usuario nao se encontra no sistema!.\n");
		system("pause");
	}
	
	else if (file != NULL)//notificando exclusao de usuario
	{
		fclose(file);
		printf("O usuario foi deletado.\n");
		system("pause");
		remove (cpf);
	}
}
		
int main()
	{
		int opcao=0; // definindo as variaveis
		
		int laco=1; // definindo a variavel de repeticao
		
		char senha[10]="a";//definido variavel senha
		
		int comparacao;//definindo variavel para cpnfirmacao de senha 
		
		printf("### Cartorio da EBAC###\n\n");// Inicio login
		printf("Login de administrador!\n\nDigite sua senha: ");
		scanf("%s", senha);
		
		comparacao = strcmp(senha, "admin");//usando comando de comparacao
		
		if (comparacao == 0)//comparando senha 
		{
			for(laco=1;laco=1;) // iniciando repeticao do menu
			{
				
				system("cls");//responsavel por limpar a tela
							
				setlocale(LC_ALL, "portuguese"); // definindo a linguagem para manter a acentuacao
				
				printf("### Cartorio da EBAC###\n\n"); // inicio do menu
				printf("Escolha a opcao desejada no menu:\n\n");
				printf("\t1 - Registrar CPF\n");
				printf("\t2 - Consultar CPF\n");
				printf("\t3 - Deletar CPF\n");
				printf("\t4 - Sair do sistema\n\n");
				printf("Opcao desejada: "); // fim do menu
				
				scanf("%d", &opcao); // armazenando a escolha do usuario
				
				system("cls");//responsavel por limpar a tela
				
				switch(opcao) // inicio da selecao do menu
				{
					case 1:
						registro();//chamada de funcoes
					break;
					
					case 2:
						consulta();
					break;
					
					case 3:
						deletar();
					break;
					
					case 4:
						printf("Obrigado por utilizar o sistema!.\n");
						return 0;
					break;
						
					default:
						printf("Essa opcao nao esta disponivel!\n");
						system("pause");
					break; // fim da selecao
				}
			} // fim da repeticao do menu
		}	
		else
		printf("Senha incorreta!");
	
	}
