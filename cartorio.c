 #include <stdio.h>   //biblioteca de comunicao com o usuario.
#include <stdlib.h>  //biblioteca de alocacao de espaço em memoria.
#include <locale.h>  //biblioteca de alocacoes de texto por regiao.
#include <string.h>  //biblioteca presponsavel por cuidar da string.

int registro()
{
	//inicio da criação de variaveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de string.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario.
	scanf("%s", cpf); //refere-se as string.
	
	strcpy(arquivo, cpf);  //responsavel por criar os valores do string.
	
	FILE *file;  //cria o arquivo.
	file = fopen(arquivo, "w");	//criar o arquivo. //"w" significa escrever.
	fprintf(file,cpf);  //salvo o valor da variavel.
	fclose(file);  //fechar o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //definir a linguagem.
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
{
    printf("Não foi possivel abrir o arquivo, não localizado! \n");
}
    
while(fgets(conteudo, 200, file) != NULL)
{
    printf("\nEssas são as informações do usuario");
    printf("%s", conteudo);
    printf("\n\n");
}
    
system ("pause");
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
       {
    	printf("O usuario nao se encontra do sistema! \n");
    	system("pause");
       }
	
} 



int main()
    {
	int opcao=0; //definir variaveis.
	int laco=1;	
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //responsavel por limpar as telas.
		
	    setlocale(LC_ALL, "Portuguese"); //definir a linguagem.	
	    
	    system("cls");
	    printf("### Cartorio da EBAC ###\n\n");  //inicio do menu.
	    printf("Escolha de opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nome \n");
	    printf("\t2 - Consutar nomes \n");
	    printf("\t3 - Deletar nomes \n");
	    printf("\t4 - sair do sistema. \n\n");	
		printf("opção: "); 	//fim do menu
		
	
	    scanf("%d", &opcao);  //Organizando a escolha do usuario.
	
	    system("cls");
	
	    switch(opcao)  //inicio da selecao.
	    {
		    case 1:
		    registro();
		    break;
		
		    case 2:
		    consulta();
		    break;
		
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema.\n");
		    return 0;
		    break;
				
		    default:
		    printf("Esse comando nao existe! \n\n");  
		    system("pause");
		    break;	     
	    }   //fim da selecao.

    }	
}
