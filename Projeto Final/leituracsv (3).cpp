#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std; 

string le_celula(ifstream &arquivo)
{
    string celula;
    char c;
    arquivo.read(&c, 1);
    if (c == '\"')
    {
        arquivo.read(&c, 1); // elimina a aspas
        do
        {
            celula += c;
            arquivo.read(&c, 1);
        } while (c != '\"');
        arquivo.read(&c, 1); // elimina o ";"
    }
    else
    {
        do
        {
            celula += c;
            arquivo.read(&c, 1);
        } while (c != ';' and c != '\n' and !arquivo.eof());
    }
    return celula;
}

struct dados
{
    bool apagado = false;
    float preco;
    char codigo_barras[20];
    char descricao[50];
    char status[10];
    char tarja[40];
};

void importarcsv(string entrada, string saida)
{
    ifstream arquivo(entrada.c_str());
    dados base10;
    ofstream arqvsaida(saida.c_str(), ios::binary);
    while (!arquivo.eof()) // Lê o arquivo até o ; e faz o tratamento dos dados
    {
        string preco = le_celula(arquivo);
        int posicao = preco.find(',');
        if (posicao < preco.length())
            preco.replace(preco.find(','), 1, ".");
        base10.preco = stof(preco);
        string codigo_barras = le_celula(arquivo);
        strcpy(base10.codigo_barras, codigo_barras.c_str());
        string descricao = le_celula(arquivo);
        strcpy(base10.descricao, descricao.c_str());
        string status = le_celula(arquivo);
        strcpy(base10.status, status.c_str());
        string tarja = le_celula(arquivo);
        strcpy(base10.tarja, tarja.c_str());

        arqvsaida.write((const char *)&base10, sizeof(dados)); // Convertendo para arquivo binário
    }
}

void selectionSort(dados vetor[], int tamanho)
// Método de Ordenação
// Do lado esquerdo do vetor, a partir de uma posição de referência, vai-se montando um conjunto ordenado
// A cada passo, o menor elemento do lado direito é trazido para o final do conjunto ordenado do lado esquerdo.
{

    for (int i = 0; i < tamanho - 1; i++)
    {
        int anterior = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (vetor[j].preco < vetor[anterior].preco)
                anterior = j;
        }
        dados aux = vetor[anterior];
        vetor[anterior] = vetor[i];
        vetor[i] = aux;
    }
}

int buscabinaria(dados vetor[], int pos_inicial, int pos_final, int K)
// Método de Busca
// A estrutura apresentada vai“quebrando” o vetor ao meio, a cada iteração, e verifica-se em qual metade pode estar o valor procurado.
// Repete-se o processo até que o vetor de busca tenha tamanho 1, sendo encontrado ou não o elemento de interesse.
// Esse subprogama requer que o vetor tenha pelo menos 1 item.
{
    int meio = (pos_inicial + pos_final)/2;

    if (K == vetor[meio].preco)   //caso base: elemento encontrado
    {
        return meio;
    }
    else if (pos_inicial < pos_final)   //caso geral: processo de busca
    {
        if (vetor[meio].preco < K) return buscabinaria(vetor, meio+1, pos_final, K);
        else return buscabinaria(vetor, pos_inicial, meio-1, K);
    }
    else     //caso base: elemento não encontrado
    {
        return -1;

    }
}

bool existe(int id, dados vetor[], int tamanho)
//Ordena o vetor e verifica se um item existe no vetor, fazendo busca no campo "preço" nos registros. ´

{
    if (tamanho != 0)
    {
        selectionSort(vetor,tamanho);
        int posicao = buscabinaria(vetor,0,tamanho-1,id);
        if (posicao != -1)
            return true;
        else
            return false;
    }
    return false;

}

void incluir (dados vetor[], int &tamanho, int qtd)
// Procedimento responsável pela inserção de dados
{

    cout << "Informe a quantidade de medicamentos que voce deseja inserir: ";
    cin >> qtd;
    cout << "Os preços devem ser diferentes para cada medicamento" <<endl;

    int aux = tamanho + qtd;
    for (int i=tamanho; i<aux; i++)
    {
        cout << endl;
        cout << "Informe o preço: ";
        cin >> vetor[i].preco;
        while (existe(vetor[i].preco, vetor, tamanho))
        {
            cout << "O preço informado já existe, insira outro: ";
            cin >> vetor[i].preco;
        }
        cout << "Informe o código de barras do medicamento: ";
        getline(cin,vetor[i].codigo_barras);
        cout << "Informe a descrição do medicamento: ";
        cin >> vetor[i].descricao;
        cout << "Informe o status do medicamento: ";
        cin.ignore();
        getline(cin,vetor[i].status);
        cout << "Informe a tarja do medicamento: ";
        getline(cin,vetor[i].tarja);
        cout << endl;
        cout << "Registro do novo medicamento concluído com Sucesso" << endl;
        tamanho++;
    }
    if (tamanho == 300)
    {
        cout << "Não é possível inserir novo medicamento" << endl;
    }
}

void excluir(dados vetor[], int &tamanho, int posicao)
// Procedimento para exclusão de um registro
// A estrutura busca o valor do campo identificador igual ao informado pelo usuário
// Em seguida desloca os elementos do vetor à sua direita para ocupar sua posição.
{
    for(int j=posicao; j<tamanho; j++)
    {
        vetor[j] = vetor[j+1];
    }
    tamanho--;
    cout << "Medicamento Excluido com Sucesso" <<endl;
}
void listar (dados vetor[], int tamanho)
// Procedimento para listar os registros
// É feito a ordenação através do selection sort
// Em seguida é feita a impressão do número de registros e de cada campo
{
    cout << endl << "Numero de dados:" << tamanho << endl;
    selectionSort(vetor,tamanho);
    for(int i=0; i < tamanho; i++)
    {
        cout << endl << "Preço:" << vetor[i].preco << endl;
        cout << "Códgio de barras:" << vetor[i].codigo_barras << endl;
        cout << "Descrição:" << vetor[i].descricao << endl;
        cout << "Status:" << vetor[i].status << endl;
        cout << "Tarja:" << vetor[i].tarja << endl;
    }
}
void  alterar (dados vetor[], int tamanho)
// Procedimento para alterar um campo do registro (com exceção do Identificador)
// É realizada a busca binária com o identificador do registro a ser alterado , que é armazenada na variável "Posição"
// Se o identificador existir(for diferente de -1) é feito a alteração, através de uma subscrição do campo escolhido.
{
    int id;
    cout << "Informe o preço do medicamento que deseja alterar: ";
    cin >> id;
    cout <<endl;
    selectionSort(vetor,tamanho);
    int posicao = buscabinaria(vetor,0,tamanho-1,id);
    if (posicao == -1)
    {
        cout << "Medicamento nâo encontrado" <<endl;
    }
    if (posicao != -1)
    {

        int buscaCampo;
        cout << "Qual campo voce deseja alterar? ((1) Preço, (2) Código de barras, (3) Descrição ou (4) Status)"
             << endl << "Digite o numero equivalente ao campo escolhido: ";
        cin >> buscaCampo;

        if (buscaCampo == 1)
        {
            cout << "Escolha um novo preço: ";
            cin.ignore();
            getline(cin,vetor[posicao].preco);

        }
        if (buscaCampo == 2)
        {
            cout << "Escolha o novo código de barras: ";
            cin >> vetor[posicao].codigo_barras;
        }
        if (buscaCampo == 3)
        {
            cout << "Escolha a nova descrição: ";
            cin.ignore();
            getline(cin,vetor[posicao].descricao);


        }
        if (buscaCampo == 4)
        {
            cout << "Escolha o novo status: ";
            cin.ignore();
            getline(cin,vetor[posicao].status);

        }

        cout << "Os dados do medicamento foram alterados com sucesso" << endl;
    }
}

void gravardados (dados vetor[],int tamanho)
// Procedimento de gravação Texto
// Se o arquivo não existir, o mesmo será criado;
// É realizada a ordenação pelo selection sort, ordenando os registros por ordem do identificador
// Em seguida é feita a escrita/gravação no arquivo em formado txt
{
    ofstream arquivo("gravacao.txt");
    selectionSort(vetor,tamanho);
    for (int i = 0; i < tamanho; i++)
    {

        arquivo << "Preço:" << vetor[i].preco << endl << "Código de barras:" << vetor[i].codigo_barras
                << endl << "Descrição:" << vetor[i].descricao << endl << "Status:" << vetor[i].status
                << endl << "Tarja: " << vetor[i].tarja <<endl <<endl;
    }
    arquivo.close();
    cout << "Gravacao Realizada com Sucesso" <<endl;
}


int main()
{
    importarcsv("base10.csv", "arqvsaida");

    cout << "Arquivo de dados da farmácia" << endl;
    cout << endl;
    cout << " ****MENU**** " << endl << endl;
    cout << "Escolha uma das opções" << endl;
    cout << "(1)Incluir - Insere dados referentes a um ou mais medicamentos" << endl;
    cout << "(2)Excluir - Exclui algum registro" << endl;
    cout << "(3)Listar - Para visualizar os dados existentes no registro e seus respectivos campos" << endl;
    cout << "(4)Alterar - Altera algum campo de um registro" << endl;
    cout << "(5)Gravar dados - Grava os dados no arquivo" << endl;
    cout << "(6)Buscar - Busca os dados existentes a partir de um filtro" << endl;
    cout << "(7)Sair - Encerra o programa" << endl;

    dados *medicamentos = new dados[100];  //??????quantidade ordenar por pelo menos dois campos 
    int opcao;
    cout << endl;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;

    int qtd = 0, tamanho =0;

    while (opcao != 6)
    {

        if (opcao == 1)
        {
            incluir(medicamentos,tamanho,qtd);   // falta criar a função para incluir dados, assim como as outras classes do menu

        }

        if (opcao == 2)
        {
            int excluiId;
            cout << "Digite o preço equivalente ao registro que deseja excluir: ";
            cin >> excluiId;
            selectionSort(medicamentos,tamanho);
            int posicao = buscabinaria(medicamentos,0, tamanho-1,excluiId);
            if (posicao != -1)
                excluir(medicamentos,tamanho,posicao);               //aaaaaaaaaaaa
            else if (posicao == -1)
            {
                cout << "Registro nao encontrado" <<endl;
            }

        }

        if (opcao == 3)
        {
            listar(medicamentos,tamanho);                         //aaaaaaaaaaaaaaaa
        }

        if (opcao == 4)
        {
            alterar(medicamentos,tamanho);                      //aaaaaaaaaaaaaaaaa
        }

        if (opcao == 5)
        {
            gravardados(medicamentos,tamanho);               //aaaaaaaaaaaaaaa
        }
        cout <<endl;

        cout << "O que deseja fazer?" << endl;
        cout << "(1)Incluir - Para inserir dados referentes a um ou mais medicamentos" << endl;
        cout << "(2)Excluir - Exclui algum registro" << endl;
        cout << "(3)Listar - Visualizar os dados existentes e seus respectivos campos" << endl;  
        cout << "(4)Alterar - Altera algum campo de um registro" << endl;
        cout << "(5)Gravar dados - Grava os dados no arquivo" << endl;
        cout << "(6)Buscar - Busca os dados existentes a partir de um filtro" << endl;
        cout << "(7)Sair - Finalizar o programa" << endl;
        cout << "Opcao: ";
        cin >> opcao;
    }

    if (opcao == 6)
    {
        string sim_ou_nao;
        cout << "Caso ainda nao tenha gravado, deseja gravar seus dados antes de encerrar o progama? Se sim, digite 'SIM', se nao, digite 'NAO': ";
        cin >> sim_ou_nao;
        if (sim_ou_nao == "SIM")
        {
            gravardados(medicamentos,tamanho);
        }
        else
            cout << "Obrigado por usar nosso programa!";
        delete [] medicamentos;
        return 0;

    }

    delete[] medicamentos;



    return 0;
}