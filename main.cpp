#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 5
#define USU 20

struct Empresa{
	char nome [50];
	char responsavel[50];
	char cnpj [50];
	char tel [50];
};

struct Usuario{
	char usuario [50];
	char senha [50];
	char email [50];
	char cpf [50];
};

struct Empresa empresa[TAM];
struct Usuario usuario[USU];

int verificacao(int entrada, int tamanhoEsperado, char *nome){  //verifica se determinada variavel tem um numero expecifico
	if (entrada < tamanhoEsperado){ 
		printf("%s Inválido!!!\n",nome);
		return 0;
	} 
	return 1;
}

int somenteNumeros(char str[]) {  //função que força usuario digitar apenas numeros mesmo sendo uma string
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
	}
	return 1;
}


void cadastroUsuario(struct Usuario usuario[], int *cadastro){
	int tamanhoSenha, tamanhoCpf;
	int index = *cadastro;
	
	system("cls");
	getchar();
	
	printf("\nBem-Vindo!!!\n");
	
	printf("\nEmail: ");
	fgets(usuario[index].email, 50, stdin);
	usuario[index].email[strcspn(usuario[index].email, "\n")] = '\0'; //Para tirar espaço após resposta
	
	do{
	printf("\nInforme CPF: ");
	fgets(usuario[index].cpf, 50, stdin);
	usuario[index].cpf[strcspn(usuario[index].cpf, "\n")] = '\0';
	tamanhoCpf = strlen(usuario[index].cpf);
	}while(!verificacao(tamanhoCpf, 11, "CPF") || !somenteNumeros(usuario[index].cpf));
	  
	printf("\nInforme Nome de usuário: ");
 fgets(usuario[index].usuario, 50, stdin);
 usuario[index].usuario[strcspn(usuario[index].usuario, "\n")] = '\0';
 
 do {
	  printf("\nInforme uma senha com no mínimo 8 caractéres: ");
	  fgets(usuario[index].senha, 50, stdin);
	  usuario[index].senha[strcspn(usuario[index].senha, "\n")] = '\0';
	  tamanhoSenha = strlen(usuario[index].senha);
	} while(!verificacao(tamanhoSenha, 8, "Senha"));
	
	printf("\n\nUsuario cadastrado!!!\n");
	system("pause");
	(*cadastro)++;
}

void cadastroEmpresa(struct Empresa empresa[], int *cadastros){
	if (*cadastros >= TAM){
		system("cls");
		printf("\nLimite de cadastros Atingido!!");
		printf("\nSeu limite de CNPJ atual é %i \n",TAM);
		system("pause");
 }
	int tamanhoCnpj, tamanhoTel;
  int index = *cadastros;
 
  system("cls");
	getchar();
 
 printf("\nInforme o nome da sua empresa: ");
 fgets(empresa[index].nome, 50, stdin);
 empresa[index].nome[strcspn(empresa[index].nome, "\n")] = '\0'; 
 
 printf("\nInforme Nome do Responsavel: ");
 fgets(empresa[index].responsavel, 50, stdin);
 empresa[index].responsavel[strcspn(empresa[index].responsavel, "\n")] = '\0';
 
 do{
	 printf("\nInforme o CNPJ: ");
	 fgets(empresa[index].cnpj, 50, stdin);
	 empresa[index].cnpj[strcspn(empresa[index].cnpj, "\n")] = '\0';
	 tamanhoCnpj = strlen(empresa[index].cnpj);
 } while(!verificacao(tamanhoCnpj, 14, "CNPJ") || !somenteNumeros(empresa[index].cnpj));
 
 do{
	 printf("\nInforme Numero de Telefone/Celular: ");
	 fgets(empresa[index].tel, 50, stdin);
	 empresa[index].tel[strcspn(empresa[index].tel, "\n")] = '\0';
	 tamanhoTel = strlen(empresa[index].tel);
} while(!verificacao(tamanhoTel, 11, "Telefone") || !somenteNumeros(empresa[index].tel));
	
	printf("Cadastro Feito com sucesso!!!");
  (*cadastros)++;
  system("pause");
}

void login(struct Usuario usuario[], int totalUsuarios) {
	char nomeUsuario[50];
	char senhaUsuario[50];
	int encontrado = 0;

	system("cls");
	getchar();

	printf("\n----- LOGIN -----\n");
	printf("Usuário: ");
	fgets(nomeUsuario, 50, stdin);
	nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';

	printf("Senha: ");
	fgets(senhaUsuario, 50, stdin);
	senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';

	for (int i = 0; i < totalUsuarios; i++) {
		if (strcmp(usuario[i].usuario, nomeUsuario) == 0 &&
			strcmp(usuario[i].senha, senhaUsuario) == 0) {
			encontrado = 1;
			break;
		}
	}

	if (encontrado) {
		printf("\nLogin bem-sucedido!\n");
	} else {
		printf("\nUsuário ou senha incorretos!\n");
	}
	system("pause");
}

void menu (){
	system("cls");
	printf(" Bem-Vindo ao Menu!!! \n\n\n");

	printf(" ------------------ \n");
	printf("| 1- Cadastrar-se  |\n");
	printf("| 2- Login         |\n");
	printf("| 3- Sair          |\n");
	printf(" ------------------ \n");
	printf("\nSua escolha: ");	
}

int main (){
	setlocale(LC_ALL,"portuguese");
	int escolha;
	int cadastrosEmpresa = 0;
	int cadastrosUsuario = 0;
	
	while(1){
		menu();
		scanf("%i", &escolha);
		
		switch(escolha){
			case 1:
				cadastroUsuario(usuario, &cadastrosUsuario);
			break;
				
			case 2:
				login(usuario, cadastrosUsuario);
			break;
				
			case 3:
				system("cls");
				printf(" ): \n");
				printf("Saindo....bip...bip...bop..");
				exit(0);
			break;
				
			default:
				system("cls");
				printf("Número inválido, Tente novamente!!  \n\n");
				system("pause");
			break;
		}
	}
}
