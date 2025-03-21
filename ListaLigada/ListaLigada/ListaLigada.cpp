
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
		int excluir;
		cout << "Digite o numero que deseja excluir: ";
		cin >> excluir; // Lê o número que o usuário deseja excluir

		NO* anterior = NULL;
		NO* atual = primeiro; // Inicializa o ponteiro 'atual' com o primeiro nó da lista

		// Procura o elemento a ser deletado
		while (atual != NULL && atual->valor != excluir) {
			anterior = atual; // Atualiza o ponteiro 'anterior' para o nó atual
			atual = atual->prox; // Avança para o próximo nó na lista
		}

		// Verifica se o elemento foi encontrado
		if (atual == NULL) {
			cout << "O valor digitado nao existe." << endl;
			return; // Sai da função se o elemento não foi encontrado
		}

		// Remove o elemento da lista
		if (anterior == NULL) {
			// Se o elemento a ser deletado for o primeiro
			primeiro = atual->prox; // Atualiza o ponteiro 'primeiro' para o próximo nó
		}
		else {
			anterior->prox = atual->prox; // Faz o nó anterior apontar para o próximo nó, pulando o nó atual
		}

		// Libera a memória ocupada pelo elemento excluído
		free(atual);

		cout << "Elemento " << excluir << " removido com sucesso." << endl;
}



void buscarElemento()
{
	int buscar;
	cout << "Digite o numero que deseja buscar: ";
	cin >> buscar; // Lê o número que o usuário deseja buscar

	NO* valorBuscar = posicaoElemento(buscar); // Chama a função para encontrar o nó com o valor buscado

	// Verifica se o elemento foi encontrado
	if (valorBuscar != NULL)
	{
		cout << valorBuscar->valor << endl; // Exibe o valor do nó encontrado
	}
	else
	{
		cout << "O valor digitado nao existe." << endl; // Informa que o valor não foi encontrado
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro; // Inicializa o ponteiro 'aux' com o primeiro nó da lista

	// Percorre a lista procurando o valor
	while (aux != NULL) {
		if (aux->valor == numero) // Verifica se o valor do nó atual é igual ao valor buscado
		{
			break; // Sai do loop se o valor for encontrado
		}
		aux = aux->prox; // Avança para o próximo nó na lista
	}
	return aux; // Retorna o ponteiro para o nó encontrado ou NULL se não encontrado
}
