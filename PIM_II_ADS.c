//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DEFININDO REDUÇÕES DE COMANDOS DE ARQUIVOS
//MÉTODOS
// Função -> ABRIR ARQUIVO 
FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo)
    {
        case 'g'://ABRIR E GRAVAR
            arquivo = fopen(caminho,"wt");
            break;
        case 'l'://ABRIR E LER
            arquivo = fopen(caminho,"rt");
            break;
        case 'a'://ABRIR E ADICIONAR
            arquivo = fopen(caminho,"a");
            break;
    }
    if(arquivo==NULL)
    {
        //Se houver algum erro, o ponteiro aponta para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

//Função -> FECHAR ARQUIVO

void FecharArquivo(FILE *arquivo)
{
    fclose(arquivo);
}

//Função -> CADASTRAR CLIENTE

void CadastrarCliente(char nome[30], char sobrenome[30], char funcionario[30], int telefone, int verba){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "clientes.txt");
    fprintf(arquivo, "%s %s %s %d %d\n", nome, sobrenome, funcionario, telefone, verba);
    FecharArquivo(arquivo);
}

//Função -> LISTAR CLIENTE

void ListarCliente(){
    FILE *arquivo;
    char nome[30];
    char sobrenome[30];
    char funcionario[30];
    int telefone;
    int verba;

    arquivo = AbreArquivo('l',"clientes.txt");

    while(!feof(arquivo)){
        fscanf(arquivo,"%s %s %s %d %d ", &nome, &sobrenome, &funcionario, &telefone, &verba);
        printf("\nNome: %s  -  Segundo Nome: %s  -  Funcionario: %s  -  Telefone: %d  -  Verba: %d\n", nome, sobrenome, funcionario, telefone, verba);
    }
    FecharArquivo(arquivo);
}

//Função -> CADASTRAR RECEITA

void CadastrarReceita(char descricao[30], int valor){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "receitas.txt");
    fprintf(arquivo, "%s %d\n", descricao, valor);
    FecharArquivo(arquivo);
}

//Função -> LISTAR RECEITAS

void ListarReceitas(){
    FILE *arquivo;
    char descricao[150];
    int valor;

    arquivo = AbreArquivo('l',"receitas.txt");

    while(!feof(arquivo)){
        fscanf(arquivo,"%s %d ", &descricao, &valor);
        printf("Descricao: %s  -  Valor: %d\n", descricao, valor);
    }
    FecharArquivo(arquivo);
}

//Função -> CADASTRAR DESPESA

void CadastrarDespesa(char descricaoD[30], int valorD){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "despesas.txt");
    fprintf(arquivo, "%s %d\n", descricaoD, valorD);
    FecharArquivo(arquivo);
}

//Função -> LISTAR DESPESAS

void ListarDespesas(){
   
    FILE *arquivo;
    char descricaoD[150];
    int valorD;

    arquivo = AbreArquivo('l',"despesas.txt");

    while(!feof(arquivo)){
        fscanf(arquivo,"%s %d ", &descricaoD, &valorD);
        printf("Descricao: %s  -  Valor: %d\n", descricaoD, valorD);
    }
    FecharArquivo(arquivo);
}

//Função -> CADASTRAR FUNCIONARIO

void CadastrarFuncionario(char nomeF[30], char cpF[15], int telefoneF, int salarioF){
    
    FILE *arquivo;
    arquivo = AbreArquivo('a', "funcionarios.txt");
    fprintf(arquivo, "%s %s %d %d\n", nomeF, cpF, telefoneF, salarioF);
    FecharArquivo(arquivo);
}

//Função -> LISTAR FUNCIONARIOS

void ListarFuncionario(){
   
    FILE *arquivo;
    char nomeF[30];
    char cpf[11];
    int telefoneF;
    int salario;

    arquivo = AbreArquivo('l',"funcionarios.txt");

    while(!feof(arquivo)){
        fscanf(arquivo,"%s %s %d %d ", &nomeF, &cpf, &telefoneF, &salario);
        printf("Nome: %s  -  CPF: %s  -  Telefone: %d  -  Salario: %d\n", nomeF, cpf, telefoneF, salario);
    }
    FecharArquivo(arquivo);
}


//INICIO DO PROGRAMA-------------------------------------------------------------------------------------------------


int main (){
	
//MECANISMO DE LOGIN

    char id[50];  //Definição de variável login      

    Login: 

    printf("\nLogin:");

    scanf("%s", &id);

    if (strcmp(id,"admin")==0)

    {

    printf("\nLogin esta correto!\n");

    }

    else

    {

    printf("\nLogin incorreto, por favor tente novamente.\n");

    goto Login;

    }

    char password[50]; //Definição de váriavel Password

    password:

    printf("\nSenha: ");
    scanf("%s", &password);

    if(strcmp(password,"admin123")==0)

    {
        system("cls");
        printf("\n\n Voce logou no sistema da SQUID SOCIAL AGENCY\n");
        system("cls");
    }

    else

    {

        printf("\nLogin incorreto, por favor tente novamente.\n");
        goto password;
    }

    //MENU PRINCIPAL

Menu:
	
	int x;
	system("cls");
	printf("\n\nMENU PRINCIPAL - SQUID SOCIAL AGENCY");
	printf("\n\n1-> Administrativo");
	printf("\n\n2-> Financeiro");
	printf("\n\n3-> RH");
	printf("\n\n\nDigite o numero correspondente a opcao desejada: ");
	scanf("%d", &x);
	
	switch(x){
		//MENU ADMINISTRATIVO
		case 1:
		int adm;
		system("cls");
		printf("\n\nMENU ADMINISTRATIVO - SQUID SOCIAL AGENCY");
		printf("\n\n1-> Cadastro de Clientes");
		printf("\n\n2-> Lançamento de Receitas");
		printf("\n\n3-> Declaração de Despesas");
		printf("\n\nDigite o numero correspondente a opcao desejada: ");
		scanf("%d", &adm);
			
	switch(adm){
				
		case 1://CADASTRO DE CLIENTES
		    int opcao;
    	    char nome[30];
    	    char sobrenome[30];
   		    char funcionario[30];
  		    int telefone;
 		    int verba;		
			do{
        		system("cls");
        	    printf("\n\n\Bem Vindo ao programa CADASTRO DE CLIENTES\n");
       			printf("\nMENU\n");
        		printf("\n 1 - Cadastrar novo cliente\n");
        		printf("\n 2 - Listar todos os clientes\n");
        		printf("\n 3 - Voltar\n");
                printf("\nDigite uma opcao: ");
        		scanf("%d", &opcao);
       			system("cls");

    switch(opcao){
        				
        case 1:
               	printf("\nDigite o nome: ");
                setbuf(stdin,NULL);
                gets(nome);
                printf("\nDigite o segundo nome: ");
                setbuf(stdin,NULL);
                gets(sobrenome);
                printf("\nDigite o nome do funcionario: ");
                setbuf(stdin,NULL);
               	gets(funcionario);
                printf("\nDigite o telefone: ");
                scanf("%d", &telefone);
                printf("\nDigite o valor da verba: ");
              	scanf("%d", &verba);
                CadastrarCliente(nome, sobrenome, funcionario, telefone, verba);
               	system("pause");
              	break;
              			 
        case 2:
               	ListarCliente();
              	system("pause");
                break;
                		 
        case 3:
                printf("\n\nVoltando...\n\n");
                goto Menu;
                break;
                default:
               	printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                system("pause");
                                    }
   														
			}while(opcao!=3);
            return 0;
			break;
											
		case 2://LANCAMENTO DE RECEITAS
			int opcaoR;
    		char descricao[30];
  			int valor;
    					
				do{
				    system("cls");
					printf("\n\nBem Vindo ao LANCAMENTO DE RECEITAS\n");
				    printf("\nMENU\n");
					printf("\n 1 - Lancar Receitas\n");
					printf("\n 2 - Relacao das Receitas\n");
					printf("\n 3 - Voltar\n");
					printf("\nDigite uma opcao: ");
					scanf("%d", &opcaoR);
					system("cls");

	switch(opcaoR){
								        	
		case 1:
			printf("\nDigite a descricao: ");
			setbuf(stdin,NULL);
			gets(descricao);
		    printf("\nDigite o valor: ");
			scanf("%d", &valor);
			CadastrarReceita(descricao, valor);
			system("pause");
			break;

		case 2:
			ListarReceitas();
		    system("pause");
			break;
		
        case 3:
			printf("\n\nVoltando...\n\n");
			goto Menu;
			break;
											
		default:

		printf("\n\nOpcao invalida! Tente Novamente!\n\n");
		system("pause");

				}
													        
					}while(opcaoR!=3);
													
		return 0;
		break;		
									
		case 3://DECLARACAO DE DESPESAS
			
            int opcaoD;
    		char descricaoD[30];
  			int valorD;
    					
		do{
			system("cls");
			printf("\n\nBem Vindo ao DECLARACAO DE DESPESAS\n");
			printf("\nMENU\n");
			printf("\n 1 - Lancar Despesas\n");
			printf("\n 2 - Relacao das Despesas\n");
			printf("\n 3 - Voltar\n");
							
		    printf("\nDigite uma opcao: ");
			scanf("%d", &opcaoD);
		    system("cls");

		switch(opcaoD){
								        	
			case 1:
				printf("\nDigite a descricao: ");
				setbuf(stdin,NULL);
				gets(descricaoD);
				printf("\nDigite o valor: ");
				scanf("%d", &valorD);
				CadastrarDespesa(descricaoD, valorD);
				system("pause");
			    break;
			
            case 2:
			    ListarDespesas();
				system("pause");
				break;
			
            case 3:
			printf("\n\nVoltando...\n\n");
			goto Menu;
		    break;				
		    default:
			printf("\n\nOpcao invalida! Tente Novamente!\n\n");
			system("pause");
			}
													        
		}while(opcaoD!=3);
													
		return 0;						
		break;					
		default:
		printf("\n\nAté Mais!");
		system("pause");
		break;					
		}
		break;
			
			
					
			case 2://MENU FINANCEIRO
			system("cls");
			int fin;			
			printf("\n\nMENU FINANCEIRO - SQUID SOCIAL AGENCY");
			printf("\n\n1-> Relacao de Receitas");
			printf("\n\n2-> Relacao de Desepesas");
			printf("\n\n3-> Balanco Financeiro");
			printf("\n\nDigite o numero correspondente a opcao desejada: ");
			scanf("%d", &fin);
						
		switch(fin){
									
				case 1://RELACAO DE RECEITAS
				system("cls");
				ListarReceitas();
				system("pause");
				break;
				
                case 2:
				system("cls");
				ListarDespesas();
				system("pause");
				break;					
				
                case 3:
				system("cls");
				ListarCliente();
				system("pause");
				break;					
			    default:
				printf("\n\nOpcao Invalida");
				break;					
				}
break;
		
//MENU RH
		
case 3:
	int opcaoF;
    char nomeF[30];
    char cpf[15];
    int telefoneF;
    int salario;
    
    do{
        system("cls");
        printf("\n\n\ Bem Vindo ao programa RECURSOS HUMANOS\n");
        printf("\nMENU\n");
        printf("\n 1 - Cadastrar Funcionario\n");
        printf("\n 2 - Listar todos os Funcionarios\n");
        printf("\n 3 - Voltar\n");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opcaoF);
        system("cls");
			
        switch(opcaoF){
            
            case 1:
                printf("\nDigite o nome: ");
                setbuf(stdin,NULL);
                gets(nomeF);
                printf("\nDigite o CPF: ");
                scanf("%s", &cpf);
                printf("\nDigite o telefone: ");
                scanf("%d", &telefoneF);
                printf("\nDigite o salario: ");
                scanf("%d", &salario);
                CadastrarFuncionario(nomeF, cpf, telefoneF, salario);
                system("pause");
                break;
           
            case 2:
                ListarFuncionario();
                system("pause");
                break;
            
            case 3:
                printf("\n\nVoltando...\n\n");
                system("pause");
                goto Menu;
                break;

            default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                system("pause");

        }
    }while(opcaoF!=3);
}
		
//REDIRECIONAMENTO PRO MENU INICIAL		

		{
			goto Menu;
		}
		
			return 0;
}
