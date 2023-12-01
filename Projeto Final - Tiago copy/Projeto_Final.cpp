/*
====================================================
||| SISTEMA DE CADASTRO EM ARQUIVOS COM ORDENAÇÃO|||
|||                                              |||
||| Dhiogo Vinicius Gonçalves - 202220328        |||
||| Nycolas Purificação Assis - 202220344        |||
||| Tiago Gualberto Bento - 202220338            |||
====================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <cstring>
#include <cmath>

using namespace std;

struct dados {
    bool apagado = 0; //marcador lógico que indica se o cliente foi apagado ou não
    string nome;  //Nome limitado a 200 caracteres
    char sexo;  //Letra que indica se o cliente é do sexo masculino(M) ou feminino(F)
    char cpf[15]; //CPF limitado a 15 caracteres, visto que o padrão brasileiro possui 11 dígitos, porém deixou-se uma margem para evitar falhas
    float dinheiro;
    char conexao[10]; //Varia entre 3G, 4G e Wifi, porém deixou-se uma margem para evitar falhas e permitir outras informações
    int idade;
};

//Funcões Principais
void importaCsv(string entrada, string saida); //Responsável por importar a base de dados do trabalho
void exportaCsv(string nomeArquivo); //Exporta o arquivo binário criado para um arquivo .csv com o nome desejado
void ordena(string nomeArquivo, bool& shell1, bool& shell2); //Responsável por permitir que o usuário escolha entre as duas possibilidades de ordenação
void shellSortIdade(string nomeArquivo); //Ordena pela Idade
void shellSortNome(string nomeArquivo); //Ordena pelo Nome
void imprimirListaClientes(string nomeArquivo); //Imprime na tela os clientes desejados
void buscarCliente(string nomeArquivo); //Responsável por permitir que o usuário escolha entre as duas possibilidades de busca
void buscarCpf(string nomeArquivo); //Busca pelo campo CPF
void buscarNome(string nomeArquivo); //Busca pelo campo Nome
void excluirCliente(string nomeArquivo); //Exlui o cliente desejado a partir do cpf
void cadastrarCliente(string nomeArquivo, bool& sheel1, bool& sheel2); //Insere novos clientes no arquivo
void editarCliente(string nomeArquivo); //Edita um cliente já cadastrado

//Funções Secundárias
void menu(); //Imprime na tela as opções disponíveis para os usuários
void limpaTerminal(); //Limpa o terminal
int tamanhoArquivo(string nomearquivo); //Informa o tamanho atual do arquivo binário
int tamanhoArquivo(string nomeArquivo, int& deletados);
void apagaEscreve(string nomeArquivo, int tamanho, dados* vetor); //Apaga todo o arquivo para reescrevê-lo novamente com os dados desejados
void escreveFinal(string nomeArquivo, dados procura); //Escreve novos dados no final do arquivo
void imprimeDados(dados cliente); //Imprime todos os dados de um cliente informado por parâmetro
bool repeteOpcao(); //Permite ao usuário a possibilidade de repetir a opção que foi executada
bool escolhaOpcao(string opcao1, string opcao2); //Coleta a opção digitada pelo usuário
bool verificaFloat(float& num); //Verifica se os caracteres digitados podem ser float
bool verificaInt(int& num); //Verifica se os caracteres digitados podem ser int
bool verificaSexo(string& sexo); //Verifica o sexo digitado
bool verificaConexao(string& conexao); //Verifica a conexão digitada
bool verificaCpf(string& cpf); //Verifica o cpf digitado
dados getCliente(fstream& aquivo); //Entra com o cpf de um novo cliente e verifica sua existência no sistema
dados getCliente(fstream& arquivo, string& linha);
dados entradaDados(dados cliente);  //entra com os dados do cliente, exceto o CPF
void percorreArquivo(fstream& arquivo, int fim, int inicio);

int main() {
    limpaTerminal();
    int opcao = 0;

    bool shell1 = 0, shell2 = 0; //Variáveis responsáveis por ordenar o cliente cadastrado, caso o arquivo já tenha sido ordenado anteriormente

    string arquivoCsv = "clientes.csv"; //Arquivo .csv usado no trabalho
    string arquivoBin = "clientes.bin"; //Arquivo binário para manipulação

    fstream arquivo(arquivoCsv, ios::in); //Abre para verificação
    if (!arquivo) { //Verifica se o arquivo está disponível
        cout << "\nO arquivo nao foi aberto, verifique se o arquivo (" << arquivoCsv << ") existe!\n\n";
        return 0;
    }
    arquivo.close(); //Fecha após a verificação

    importaCsv(arquivoCsv, arquivoBin); //Importa o arquivo para o arquivo binário

    do {
        menu(); //Exibe o menu de opções

        verificaInt(opcao);

        limpaTerminal();

        switch (opcao) {
        case 1:
            // cadastrarCliente(arquivoBin, shell1, shell2);
            break;

        case 2:
            buscarCliente(arquivoBin);
            break;

        case 3:
            imprimirListaClientes(arquivoBin);
            break;

        case 4:
            excluirCliente(arquivoBin);
            break;

        case 5:
            // ordena(arquivoBin, shell1, shell2);
            break;

        case 6:
            // editarCliente(arquivoBin);
            break;

        case 7:
            // exportaCsv(arquivoBin);
            break;

        case 8:
            cout << "\n\n||-------------------------------Volte Sempre!-------------------------------||\n\n"; //Mensagem de saída do programa
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl; //Em caso de valores diferentes do esperado, o programa pede para o usuário tentar novamente
            break;
        }
    } while (opcao != 8);

    return 0;
}

void menu() {
    cout << "\n\nBase de clientes para Gestão de trafego de pessoas para e-commerce\n\n";
    cout << "||================================================================================||\n";
    cout << "||                                     MENU                                       ||\n";
    cout << "||================================================================================||\n";
    cout << "||         ||                ||                                                   ||\n";
    cout << "||   ( )   ||     Opcoes     ||                     Descricao                     ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (1)   ||    Cadastrar   || Cadastrar dados de um novo cliente                ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (2)   ||     Buscar     || Busca os dados de um cliente                      ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (3)   ||    Imprimir    || Exibe as informacoes dos clientes na tela         ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (4)   ||     Excluir    || Exclui o cliente desejado                         ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (5)   ||     Ordenar    || Ordena os cliente no arquivo                      ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (6)   ||     Editar     || Editar os dados de um cliente cadastrado          ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (7)   ||    Exportar    || Exporta os dados para um arquivo csv              ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n";
    cout << "||   (8)   ||      Sair      || Encerra o programa                                ||\n";
    cout << "||---------||----------------||---------------------------------------------------||\n\n";
    cout << "Informe a opcao desejada: ";
}

void limpaTerminal() {
#if defined _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void apagaEscreve(string nomeArquivo, int tamanho, dados* vet) {
    ofstream arquivo(nomeArquivo, ios::binary | ios::out | ios::trunc); //Abre o arquivo .bin no modo escrita binário, apagando todos os dados do mesmo (ios::trunc)
    for (int k = 0; k < tamanho; k++)
        arquivo.write((const char*)&vet[k], sizeof(dados)); //Escreve no arquivo os dados do ponteiro recebido por parâmetro 
    arquivo.close();
}

void escreveFinal(string nomeArquivo, dados procura) {
    ofstream arquivo(nomeArquivo, ios::binary | ios::app | ios::ate); //Abre o arquino para escrita binário e insere dados no final sem apagar dados
    arquivo.write((const char*)&procura, sizeof(dados)); //escreve no arquivo os dados do registro "procura"

    arquivo.close();
}

int tamanhoArquivo(string nomeArquivo) {
    fstream arquivo(nomeArquivo, ios_base::binary | ios_base::in);
    int tamanho = 0;
    string verificaTamanho;

    while (getline(arquivo, verificaTamanho)) {
        tamanho++;
    }

    return tamanho;
}

int tamanhoArquivo(string nomeArquivo, int& deletados) {
    fstream arquivo(nomeArquivo, ios_base::binary | ios_base::in);
    int tamanho = 0;
    dados cliente;
    string verificaDeletados;

    while (getline(arquivo, verificaDeletados))
    {

        tamanho++;
        istringstream ss(verificaDeletados);

        getline(ss, cliente.nome, ',');

        string sexo;
        getline(ss, sexo, ',');
        cliente.sexo = sexo[0];

        string cpf;
        getline(ss, cpf, ',');
        strcpy(cliente.cpf, cpf.c_str());

        string dinheiro;
        getline(ss, dinheiro, ',');
        cliente.dinheiro = stof(dinheiro);

        string conexao;
        getline(ss, conexao, ',');
        strcpy(cliente.conexao, conexao.c_str());

        string idade;
        getline(ss, idade, ',');
        cliente.idade = stoi(idade);

        string apagado;
        getline(ss, apagado, ',');

        if (cliente.apagado) {
            deletados++;
        }
    }
    return tamanho;
}

void percorreArquivo(fstream& arquivo, int fim, int inicio) {
    dados cliente;

    string linha;
    for (int i = 0; i < fim - inicio; i++)
    {
        getline(arquivo, linha);
        istringstream ss(linha);

        getline(ss, cliente.nome, ',');

        string sexo;
        getline(ss, sexo, ',');
        cliente.sexo = sexo[0];

        string cpf;
        getline(ss, cpf, ',');
        strcpy(cliente.cpf, cpf.c_str());

        string dinheiro;
        getline(ss, dinheiro, ',');
        cliente.dinheiro = stof(dinheiro);

        string conexao;
        getline(ss, conexao, ',');
        strcpy(cliente.conexao, conexao.c_str());


        string idade;
        getline(ss, idade, ',');
        cliente.idade = stoi(idade);

        string apagado;
        getline(ss, apagado, ',');

        if (!cliente.apagado) {
            imprimeDados(cliente);
        }
    }
}

void importaCsv(string entrada, string saida) {
    fstream arquivo(entrada, ios::in); //Entra no arquivo .csv para leitura
    dados clientes;
    ofstream arqvsaida(saida, ios::binary); //Abre o arquivo para escrita em binário

    string linha;
    while (getline(arquivo, linha))
    {
        istringstream ss(linha);

        string nome;
        getline(ss, nome, ',');
        clientes.nome = nome;

        string sexo;
        getline(ss, sexo, ',');
        clientes.sexo = sexo[0];

        string cpf;
        getline(ss, cpf, ',');
        strcpy(clientes.cpf, cpf.c_str()); //Copia a string "cpf" para o registro "clientes.cpf"

        string dinheiro;
        getline(ss, dinheiro, ',');
        clientes.dinheiro = stof(dinheiro); //Copia a string "dinheiro" para o float "clientes.dinheiro" (stof)

        string conexao;
        getline(ss, conexao, ',');
        strcpy(clientes.conexao, conexao.c_str());

        string idade;
        getline(ss, idade, ',');
        clientes.idade = stoi(idade);

        arqvsaida.write(clientes.nome.c_str(), clientes.nome.size()); // Escreve os dados do registro no arquivo binário
        arqvsaida.write(",", 1);

        arqvsaida.write(&clientes.sexo, sizeof(clientes.sexo));
        arqvsaida.write(",", 1);

        arqvsaida.write(clientes.cpf, sizeof(clientes.cpf));
        arqvsaida.write(",", 1);

        arqvsaida.write(to_string(round(clientes.dinheiro * 100.0) / 100.0).c_str(), to_string(clientes.dinheiro).size());
        arqvsaida.write(",", 1);

        string conex = clientes.conexao;
        arqvsaida.write(conex.c_str(), conex.size());
        arqvsaida.write(",", 1);

        arqvsaida.write(to_string(clientes.idade).c_str(), sizeof(int));
        arqvsaida.write(",", 1);

        string apagado = to_string(clientes.apagado);
        arqvsaida.write(apagado.c_str(), apagado.size());
        arqvsaida.write("\n", 1);
    }

    arqvsaida.close();
}


// void exportaCsv(string nomeArquivo) {
//     string csv;
//     cout << "Digite o nome do arquivo para exportar a base de dados: ";
//     getline(cin, csv); //Usuário informa o nome do arquivo .csv de exportação

//     fstream arq_entrada(nomeArquivo, ios::binary, ios::in); //Abre o arquivo para leitura binária
//     ofstream arquivo_csv(csv, ios::trunc | ios::out); //Abre o arquivo, excluindo seus dados, para escrita

//     int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo binário
//     dados aux;

//     for (int i = 0; i < tamanho; i++) {
//         arq_entrada.read((char*)&aux, sizeof(dados)); //Lê o arquivo binário e copia os dados para o registro "aux"
//         arquivo_csv << aux.nome << "," << aux.sexo << "," << aux.cpf << ","
//             << aux.dinheiro << "," << aux.conexao << "," << aux.idade << "\n"; //Escreve no arquivo csv os dados, sendo que o (,) = mudança de colunas e o (\n) = quebras de linha
//     }

//     cout << "\nBase de dados exportada com sucesso!";

//     arq_entrada.close();
//     arquivo_csv.close();

//     if (repeteOpcao())
//         exportaCsv(nomeArquivo);
// }

void imprimirListaClientes(string nomeArquivo) {
    int inicio, fim, deletados = 0, tamanho = 0;
    fstream arquivo(nomeArquivo, ios_base::binary | ios_base::in);

    tamanho = tamanhoArquivo(nomeArquivo, deletados);

    arquivo.close(); // Fecha o arquivo antes de reabrir
    arquivo.open(nomeArquivo, ios_base::binary | ios_base::in); // Reabre o arquivo
    arquivo.seekg(0, ios::beg); //Posiciona o ponteiro de leitura no início

    cout << "Deseja imprimir o arquivo todo na tela: (1)Sim (2)Nao\n";

    if (escolhaOpcao("(1)Sim", "(2)Nao")) {
        limpaTerminal();
        percorreArquivo(arquivo, tamanho, 0);
    }
    else { //Permite ao usuário imprimir a quantidade de clientes desejada
        limpaTerminal();
        cout << "O arquivo tem " << tamanho << " clientes, sendo que desses, " << deletados << " foram deletados\n\n"; //Informa a quantidade de clientes no arquivo
        cout << "Deseja imprimir a partir de qual cliente? \n";

        while (!verificaInt(inicio) || inicio == 0) {
            cout << "Formato invalido, deseja imprimir a partir de qual cliente (1 a " << tamanho << "): ";
        }

        cout << "Deseja imprimir ate qual cliente? \n";

        if (!verificaInt(fim)) {
            cout << "Formato invalido, sera impresso ate o ultimo cliente\n";
            fim = tamanho;
        }

        while (fim < inicio or fim > tamanho) { //Impede situações impossíveis, tais como clientes fora do limite do arquivo e valor final < valor inicial
            cout << "\nNao e permitido imprimir ate esse cliente!\n";
            cout << "OBS: Verifique o valor digitado e a quantidade de dados do arquivo\n\n";
            cout << "Digite novamente ate qual cliente deseja imprimir: ";

            if (!verificaInt(fim)) {
                cout << "Formato invalido, sera impresso ate o ultimo cliente\n";
                fim = tamanho;
            }
        }

        limpaTerminal();
        for (int i = 0; i < inicio - 1; ++i) {
            arquivo.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        percorreArquivo(arquivo, fim + 1, inicio);

    }
    arquivo.close();

    if (repeteOpcao()) {
        imprimirListaClientes(nomeArquivo);
    }
}

// void ordena(string nomeArquivo, bool& shell1, bool& shell2) {

//     cout << "Deseja ordenar os clientes pela idade ou pelo nome?\n";
//     cout << "(1) Idade\n";
//     cout << "(2) Nome\n";

//     if (escolhaOpcao("(1)Idade", "(2)Nome")) {
//         shellSortIdade(nomeArquivo); //Ordena o arquivo pela Idade dos clientes
//         shell1 = 1; //Determina se o arquivo foi ordenado pela idade
//     }
//     else {
//         shellSortNome(nomeArquivo); //Ordena o arquivo pelo Nome dos clientes
//         shell2 = 1; //Determina se o arquivo foi ordenado pelo nome
//     }

//     cout << "\nClientes ordenados com sucesso!";

//     if (repeteOpcao()) {
//         ordena(nomeArquivo, shell1, shell2);
//     }
// }

// void shellSortIdade(string nomeArquivo) {
//     fstream arquivo(nomeArquivo, ios::binary | ios::in); //Abre o arquivo para leitura binária

//     int tamanho = tamanhoArquivo(nomeArquivo), deletados = 0; //Informa o tamanho do arquivo

//     dados aux;

//     for (int i = 0; i < tamanho; i++) { //Define a quantidade de dados deletados
//         arquivo.read((char*)&aux, sizeof(dados));
//         if (aux.apagado)
//             deletados++;
//     }

//     arquivo.seekg(ios::beg);
//     tamanho -= deletados;
//     dados* vet;
//     vet = new dados[tamanho];

//     for (int i = 0; i < tamanho; i++) {
//         arquivo.read((char*)&aux, sizeof(dados)); //Armazena todos os dados do arquivo em um registro
//         if (!aux.apagado)
//             vet[i] = aux;
//     }

//     int gaps[7] = {1, 4, 13, 40, 121, 364, 1093}; //Sequência de Knuth
//     int pos_gap = 6; //Posicão do último elemento da sequência de Knuth
//     while (gaps[pos_gap] > tamanho) {
//         pos_gap--; //Define o primeiro gap
//     }
//     dados valor;
//     int j;
//     while (pos_gap >= 0) {
//         int gap = gaps[pos_gap]; //Define o tamanho dos gaps

//         for (int k = gap; k < tamanho; k++) { //Insertion Sort tradicional porém com gaps entre as comparações
//             valor = vet[k]; //Armazena o registro analisado em uma variável aux
//             j = k;
//             while ((j >= gap) and (valor.idade < vet[j - gap].idade)) { //Compara o campo da idade
//                 vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
//                 j = j - gap;
//             }
//             vet[j] = valor;
//         }
//         pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
//     }
//     arquivo.close();

//     apagaEscreve(nomeArquivo, tamanho, vet); //Escreve no arquivo o vetor já ordenado
//     delete[] vet;
// }

// void shellSortNome(string nomeArquivo) {
//     fstream arquivo(nomeArquivo, ios::binary | ios::in); //Abre o arquivo para leitura binária

//     int tamanho = tamanhoArquivo(nomeArquivo), deletados = 0; //Informa o tamanho do arquivo

//     dados aux;

//     for (int i = 0; i < tamanho; i++) { //Define a quantidade de dados deletados
//         arquivo.read((char*)&aux, sizeof(dados));
//         if (aux.apagado)
//             deletados++;
//     }

//     arquivo.seekg(ios::beg);
//     tamanho -= deletados;
//     dados* vet;
//     vet = new dados[tamanho];

//     for (int i = 0; i < tamanho; i++) {
//         arquivo.read((char*)&aux, sizeof(dados)); //Armazena todos os dados do arquivo em um vetor
//         if (!aux.apagado)
//             vet[i] = aux;
//     }
//     int gaps[7] = {1, 4, 13, 40, 121, 364, 1093}; //Sequência de Knuth
//     int pos_gap = 6; //Posicão do último elemento da sequência de Knuth
//     while (gaps[pos_gap] > tamanho) {
//         pos_gap--; //Define o primeiro gap
//     }
//     dados valor;
//     int j;
//     while (pos_gap >= 0) {
//         int gap = gaps[pos_gap]; //Define o tamanho dos gaps

//         for (int k = gap; k < tamanho; k++) { //Insertion Sort tradicional porém com gaps entre as comparações
//             valor = vet[k]; //Armazena o registro analisado em uma variável aux
//             j = k;
//             while ((j >= gap) and (strcmp(valor.nome, vet[j - gap].nome) <= 0)) { //Compara o campo do nome
//                 vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
//                 j = j - gap;
//             }
//             vet[j] = valor;
//         }
//         pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
//     }
//     arquivo.close();

//     apagaEscreve(nomeArquivo, tamanho, vet); //Escreve no arquivo o vetor já ordenado
//     delete[] vet;
// }

void excluirCliente(string nomeArquivo) {
    fstream arquivo(nomeArquivo); //Abre o arquivo para leitura e escrita

    int tamanho = tamanhoArquivo(nomeArquivo), cont = 0, posicao = -1;
    char escolha;
    dados procura;

    string cpf_buscado;
    cout << "Digite o CPF para verificar se existe no sistema (11 digitos numerico): ";

    while (!verificaCpf(cpf_buscado)) {
        cout << "O CPF informado nao esta de acordo com o padrao esperado (11 digitos numerico). Digite novamente: ";
    }

    while ((cont < tamanho) and (posicao == -1)) { //Lê todo o arquivo ou para quando o cpf buscado for encontrado
        string linha;
        procura = getCliente(arquivo, linha);

        if ((strcmp(cpf_buscado.c_str(), procura.cpf) == 0) && (!procura.apagado)) { //Verifica se os cpfs são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont;
            procura.apagado = 1;

            streampos pos = static_cast<streampos>(arquivo.tellg()) - static_cast<streampos>(linha.size()) - static_cast<streampos>(2);
            arquivo.seekp(pos, ios::beg);

            arquivo << procura.nome << ',' << procura.sexo << ',' << procura.cpf << ',' << procura.dinheiro << ',' << procura.conexao << ',' << procura.idade << ',' << procura.apagado;
        }
        cont++;
    }

    if (posicao == -1) //Caso o cpf não exista no arquivo
        cout << "\nCPF nao encontrado!";
    else {
        cout << "\nCliente excluido com sucesso!";
    }

    arquivo.close();

    if (repeteOpcao()) {
        excluirCliente(nomeArquivo);
    }
}

void buscarCliente(string nomeArquivo) {
    cout << "\nDigite o campo do cliente que deseja fazer a busca:\n";
    cout << "(1) CPF;\n";
    cout << "(2) Nome;\n";
    if (escolhaOpcao("(1)CPF", "(2)Nome"))
        buscarCpf(nomeArquivo); //Busca o cliente pelo cpf
    else
        buscarNome(nomeArquivo); //Busca o cliente pelo nome

    if (repeteOpcao()) {
        buscarCliente(nomeArquivo);
    }
}

void buscarCpf(string nomeArquivo) {
    fstream arquivo(nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    string cpfProcurado;
    cout << "Digite o CPF para verificar se existe no sistema (11 digitos numerico): ";

    while (!verificaCpf(cpfProcurado)) {
        cout << "O CPF informado nao esta de acordo com o padrao esperado (11 digitos numerico). Digite novamente: ";
    }

    limpaTerminal();

    int cont = 0, posicao = -1;;
    dados procura;


    while ((cont < tamanho) and (posicao == -1)) { //Lê todo o arquivo ou para quando o cpf buscado for encontrado
        procura = getCliente(arquivo);

        if ((strcmp(cpfProcurado.c_str(), procura.cpf) == 0) && (!procura.apagado)) { //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo do código de barras procurado
        }
        cont++;
    }
    arquivo.close();

    if (posicao == -1) //Se não for encontrado o CPF desejado
        cout << "\nCliente nao encontrado!";
    else {
        imprimeDados(procura);
    }
}

void buscarNome(string nomeArquivo) {
    fstream arquivo(nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    string nome_buscado;
    cout << "Digite o nome buscado: ";

    getline(cin, nome_buscado); //Nome que se deseja buscar na base de dados

    int cont = 0, posicao = -1;
    dados procura;

    while ((cont < tamanho) and (posicao == -1)) { //Percorre todo o arquivo até que o nome buscado seja encontrado

        procura = getCliente(arquivo);

        if ((strcmp(nome_buscado.c_str(), procura.nome.c_str()) == 0) && (!procura.apagado)) //Verifica se os nomes são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo do nome procurado
        cont++;
    }

    if (posicao == -1) //Se não for encontrada o nome desejado
        cout << endl << "Cliente nao encontrado!";
    else {
        //Exibe as informações do cliente buscado
        limpaTerminal();
        imprimeDados(procura);
    }
}

// void cadastrarCliente(string nomeArquivo, bool& sheel1, bool& sheel2) {
//     int posicao = -1;
//     dados procura = getCliente(nomeArquivo, posicao);

//     if (posicao == -1) { //Caso o cliente não esteja cadastrado
//         cout << "Cliente nao esta no sistema, digite os dados: \n";
//         escreveFinal(nomeArquivo, entradaDados(procura)); //Escreve no final do arquivo
//         cout << "\nCliente registrado com sucesso!";

//         if (sheel1) //Verifica se o arquivo já havia sido ordenado anteriormente
//             shellSortIdade(nomeArquivo);
//         else if (sheel2)
//             shellSortNome(nomeArquivo);
//     }
//     else
//         cout << "\ncliente ja esta no sistema, tente novamente!\n\n";

//     if (repeteOpcao()) {
//         cadastrarCliente(nomeArquivo, sheel1, sheel2);
//     }
// }

// dados entradaDados(dados cliente) {
//     string dado;

//     cout << "\nInforme o nome do cliente: ";
//     getline(cin, dado);
//     strcpy(cliente.nome, dado.c_str());

//     cout << "Informe o sexo (M)Masculino e (F)Feminino: ";
//     while (!verificaSexo(dado)) {
//         cout << "Valor informado nao atende as possibilidades, digite novamente (M)Masculino (F)Feminino: ";
//     }
//     cliente.sexo = dado[0];

//     cout << "Informe o dinheiro: ";
//     float dinheiro;
//     while (!verificaFloat(dinheiro)) {
//         cout << "Valor informado nao corresponde a um valor valido, digite novamente: ";
//     }
//     cliente.dinheiro = dinheiro;

//     cout << "Informe a conexao - 3G, 4G ou Wifi: ";
//     while (!verificaConexao(dado)) {
//         cout << "Valor informado nao atende as possibilidades, digite novamente (3G, 4G ou WIfi): ";
//     }
//     strcpy(cliente.conexao, dado.c_str());

//     cout << "Informe a idade: ";
//     int idade;
//     while (!verificaInt(idade)) {
//         cout << "Valor informado nao corresponde a uma idade valida, digite novamente: ";
//     }
//     cliente.idade = idade;

//     return cliente;
// }

bool verificaFloat(float& num) {
    string numero;
    bool aux = true;

    getline(cin, numero);

    for (int i = 0; i < numero.size(); i++) {

        if (numero[i] == ',') //Se o valor digitado apresetnar (,), ela é substituida pelo (.)
            numero.replace(i, 1, ".");

        if (!isdigit(numero[i]) and numero[i] != '.') { //Se o valor digitado apresetnar letras, o valor é inválido
            aux = false;
            i = numero.size();
        }
    }

    if (aux == true) {
        num = stof(numero);
    }

    return aux;
}

bool verificaInt(int& num) {
    string numero;

    getline(cin, numero);

    bool aux = true;

    for (int i = 0; i < numero.size(); i++) {
        if (!isdigit(numero[i])) { //Se o valor digitado apresetnar letras, o valor é inválido
            aux = false;
            i = numero.size();
        }
    }

    if (aux == true) {
        num = stoi(numero);
    }

    return aux;
}

bool verificaSexo(string& sexo) {
    string dado;
    string possibilidades[] = {"F","M"};

    getline(cin, dado);

    for (int i = 0; i <= possibilidades->size(); i++) {
        if (strcmp(dado.c_str(), possibilidades[i].c_str()) == 0) { //Se o valor digitado for uma das opcões, ele é copiado para a string passada por referência
            sexo = dado[0];
            return 1;
        }
    }
    return 0;
}

bool verificaConexao(string& conexao) {
    string dado;
    string possibilidades[] = {"3G", "4G","Wifi"};

    getline(cin, dado);

    for (int i = 0; i <= possibilidades->size(); i++) {
        if (strcmp(dado.c_str(), possibilidades[i].c_str()) == 0) { //Se o valor digitado for uma das opcões, ele é copiado para a string passada por referência
            strcpy((char*)conexao.c_str(), dado.c_str());
            return 1;
        }
    }
    return 0;
}

bool verificaCpf(string& cpf) {
    string dado;

    getline(cin, dado);

    if (strlen(dado.c_str()) != 11) { //Verifica se o CPF digitado possui 11 dígitos
        return 0;
    }

    for (int i = 0; i < dado.size(); i++) {
        if (!isdigit(dado[i])) { //Verifica se o CPF digitado possui letras
            return 0;
        }
    }

    strcpy((char*)cpf.c_str(), dado.c_str());

    return 1;
}

dados getCliente(fstream& arquivo) {
    dados cliente;
    string linha;

    getline(arquivo, linha);
    istringstream ss(linha);

    getline(ss, cliente.nome, ',');

    string sexo;
    getline(ss, sexo, ',');
    cliente.sexo = sexo[0];

    string cpf;
    getline(ss, cpf, ',');
    strcpy(cliente.cpf, cpf.c_str());

    string dinheiro;
    getline(ss, dinheiro, ',');
    cliente.dinheiro = stof(dinheiro);

    string conexao;
    getline(ss, conexao, ',');
    strcpy(cliente.conexao, conexao.c_str());


    string idade;
    getline(ss, idade, ',');
    cliente.idade = stoi(idade);

    string apagado;
    getline(ss, apagado, ',');
    if (apagado == "0") {
        cliente.apagado = 0;
    }
    else {
        cliente.apagado = 1;
    }

    return cliente;
}

dados getCliente(fstream& arquivo, string& linha) {
    dados cliente;

    getline(arquivo, linha);
    istringstream ss(linha);

    getline(ss, cliente.nome, ',');

    string sexo;
    getline(ss, sexo, ',');
    cliente.sexo = sexo[0];

    string cpf;
    getline(ss, cpf, ',');
    strcpy(cliente.cpf, cpf.c_str());

    string dinheiro;
    getline(ss, dinheiro, ',');
    cliente.dinheiro = stof(dinheiro);

    string conexao;
    getline(ss, conexao, ',');
    strcpy(cliente.conexao, conexao.c_str());


    string idade;
    getline(ss, idade, ',');
    cliente.idade = stoi(idade);

    string apagado;
    getline(ss, apagado, ',');
    if (apagado == "0") {
        cliente.apagado = 0;
    }
    else {
        cliente.apagado = 1;
    }

    return cliente;
}

// void editarCliente(string nomeArquivo) {
//     int posicao = -1;
//     dados procura = getCliente(nomeArquivo, posicao);

//     if (posicao == -1) //Caso o cpf não exista no arquivo
//         cout << "\nCPF nao encontrado!";
//     else {
//         cout << endl << "Cliente encontrado, digite seus novos dados: ";
//         fstream arquivo(nomeArquivo); //Abre o arquivo para leitura e escrita
//         arquivo.seekp((posicao + 1) * sizeof(dados)); //Posiciona o ponteiro de escrita
//         arquivo.seekp(-static_cast<int>(sizeof(dados)), ios::cur); //Posiciona o ponteiro de escrita dentro do registro com o cpf buscado
//         dados cliente = entradaDados(procura);
//         arquivo.write((char*)&cliente, sizeof(dados)); //Escreve o marcador alterado no arquivo
//         arquivo.close();
//         cout << "\nCliente editado com sucesso!";
//     }

//     if (repeteOpcao()) {
//         editarCliente(nomeArquivo);
//     }
// }

bool repeteOpcao() {
    string escolha;
    cout << "\n\nDigite (1) para voltar ao menu ou (2) para repetir a opcao:";
    getline(cin, escolha); //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while (!strcmp(escolha.c_str(), "1") == 0 && !strcmp(escolha.c_str(), "2") == 0) { //Impede que outros valores sejam inseridos
        limpaTerminal();
        cout << "\nOpcao nao disponivel, digite novamente: \n";
        cout << "(1)menu ou (2)repetir opcao\n";
        getline(cin, escolha);
    }

    limpaTerminal();

    if (strcmp(escolha.c_str(), "2") == 0) {
        return true;
    }
    return false;
}

bool escolhaOpcao(string opcao1, string opcao2) {
    string escolha;
    getline(cin, escolha);

    while (!strcmp(escolha.c_str(), "1") == 0 && !strcmp(escolha.c_str(), "2") == 0) { //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: \n";
        cout << opcao1 + " ou " + opcao2 << endl;
        getline(cin, escolha);
    }

    if (strcmp(escolha.c_str(), "1") == 0)
        return 1;
    return 0;
}

void imprimeDados(dados cliente) {
    cout << cliente.nome << " - ";
    cout << cliente.sexo << " - ";
    cout << cliente.cpf << " - ";
    cout << cliente.dinheiro << " - ";
    cout << cliente.conexao << " - ";
    cout << cliente.apagado << " - ";
    cout << cliente.idade << endl; //Imprime na tela todos os clientes do arquivo binário
}