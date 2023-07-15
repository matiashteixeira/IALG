/*
====================================================
||| SISTEMA DE CADASTRO EM ARQUIVOS COM ORDENAÇÃO|||
|||                                              |||
||| Dhiogo Vinicius Gonçalves - 202210591 - 22A  |||
||| Nycolas Purificação Assis - 202210162 - 22A  |||
||| Tiago Gualberto Bento - 202210169 - 22A      |||
====================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <cstring>

using namespace std; 

struct dados{
    bool apagado = 0; //marcador lógico que indica se o cliente foi apagado ou não
    char nome[200];  //Nome limitado a 200 caracteres
    char sexo;  //Letra que indica se o cliente é do sexo masculino(M) ou feminino(F)
    char cpf[15]; //CPF limitado a 15 caracteres, visto que o padrão brasileiro possui 11 dígitos, porém deixou-se uma margem para evitar falhas
    float dinheiro; 
    char conexao[10]; //Varia entre 3G, 4G e Wifi, porém deixou-se uma margem para evitar falhas e permitir outras informações
    int idade;
};

//Funcões Principais
void importaCsv(string entrada, string saida); //Responsável por importar a base de dados do trabalho
string leituraCelula(ifstream &arquivo); //Responsável por ler cada célula do arquivo csv
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

//Funções Secundárias
void menu(); //Imprime na tela as opções disponíveis para os usuários
void limpaTerminal(); //Limpa o terminal
int tamanhoArquivo(string nomeArquivo); //Informa o tamanho atual do arquivo binário
void apagaEscreve(string nomeArquivo, int tamanho, dados* vetor); //Apaga todo o arquivo para reescrevê-lo novamente com os dados desejados
void escreveFinal(string nomeArquivo, dados procura); //Escreve novos dados no final do arquivo
void editarCliente(string nomeArquivo);

void imprimeDados(dados cliente); //Imprime todos os dados de um cliente informado por parâmetro
bool repeteOpcao(); //Permite ao usuário a possibilidade de repetir a opção que foi executada
bool escolhaOpcao(string opcao1, string opcao2); //Coleta a opção digitada pelo usuário
bool verificaFloat(float &num);
bool verificaInt(int& num);
bool verificaSexo(string& sexo);
bool verificaConexao(string& conexao);
bool verificaCpf(string& cpf);
dados getCliente(string nomeArquivo, int& posicao);   
dados entradaDados(dados cliente); 

int main(){
    limpaTerminal();
    int opcao = 0;

    bool shell1 = 0, shell2 = 0; //Variáveis responsáveis por ordenar o cliente cadastrado, caso o arquivo já tenha sido ordenado anteriormente

    string arquivoCsv = "clientes.csv"; //Arquivo .csv usado no trabalho
    string arquivoBin = "clientes.bin"; //Arquivo binário para manipulação

    ifstream arquivo(arquivoCsv); //Abre para verificação
    if(!arquivo){ //Verifica se o arquivo está disponível
        cout << "\nO arquivo não foi aberto, verifique se o arquivo (" << arquivoCsv << ") existe!\n\n";
        return 0;
    }
    arquivo.close(); //Fecha após a verificação

    importaCsv(arquivoCsv, arquivoBin); //Importa o arquivo para o arquivo binário
    
    do{
        menu(); //Exibe o menu de opções
        
        verificaInt(opcao);
    
        limpaTerminal();

        switch (opcao){
        case 1:
            cadastrarCliente(arquivoBin, shell1, shell2);
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
            ordena(arquivoBin,shell1,shell2);
            break;

        case 6:
            editarCliente(arquivoBin);
            break;

        case 7:
            exportaCsv(arquivoBin);
            break;

        case 8:
            cout << "\n\n||-------------------------------Volte Sempre!-------------------------------||\n\n"; //Mensagem de saída do programa
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl; //Em caso de valores diferentes do esperado, o programa pede para o usuário tentar novamente
            break;
        }
    } while(opcao != 8);

    return 0;
}

void menu(){
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

void limpaTerminal(){
    #if defined _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void apagaEscreve(string nomeArquivo, int tamanho, dados* vet){
    ofstream arquivo(nomeArquivo,ios::binary | ios::out | ios::trunc); //Abre o arquivo .bin no modo escrita binário, apagando todos os dados do mesmo (ios::trunc)
    for(int k = 0; k < tamanho; k++)
        arquivo.write((const char *) &vet[k], sizeof(dados)); //Escreve no arquivo os dados do ponteiro recebido por parâmetro 
    arquivo.close();
}

void escreveFinal(string nomeArquivo, dados procura){
    ofstream arquivo(nomeArquivo,ios::binary | ios::app | ios::ate); //Abre o arquino para escrita binário e insere dados no final sem apagar dados
    arquivo.write((const char *) &procura, sizeof(dados)); //escreve no arquivo os dados do registro "procura"

    arquivo.close();
}

int tamanhoArquivo(string nomeArquivo){
    ifstream arquivo(nomeArquivo, ios::ate); //Abre o arquivo e posiciona no final para leitura
    long int tamanho_arquivo = arquivo.tellg(); //Define o tamanho do arquivo em bytes
    int qtd_dados = int (tamanho_arquivo/sizeof(dados)); //Define a quantidade de dados do arquivo (qtd bytes do arquivo/qtd bytes do registro)

    arquivo.close();
    return qtd_dados;
}

void importaCsv(string entrada, string saida){
    ifstream arquivo(entrada); //Entra no arquivo .csv para leitura
    dados clientes;
    ofstream arqvsaida(saida, ios::binary); //Abre o arquivo para escrita em binário

    while (!arquivo.eof()) { // Lê o arquivo até ele chegar ao fim
        string nome = leituraCelula(arquivo); //Define a informação do arquivo que será considerada descrição
        strcpy(clientes.nome, nome.c_str()); //Copia a string "nome" para o registro "clientes.nome"

        string sexo = leituraCelula(arquivo); //Define a informação do arquivo que será considerada sexo
        clientes.sexo = sexo[0]; //Copia o primeiro digito da string "sexo" para o registro "clientes.sexo"
    
        string cpf = leituraCelula(arquivo); //Define a informação do arquivo que será considerada cpf
        strcpy(clientes.cpf, cpf.c_str()); //Copia a string "cpf" para o registro "clientes.cpf"

        string dinheiro = leituraCelula(arquivo); //Define a informação do arquivo que será considerada dinheiro
        clientes.dinheiro = stof(dinheiro); //Copia a string "dinheiro" para o float "clientes.dinheiro" (stof)

        string conexao = leituraCelula(arquivo); //Define a informação do arquivo que será considerada conexão
        strcpy(clientes.conexao, conexao.c_str()); //Copia a string "conexao" para o registro "clientes.conexao"

        string idade = leituraCelula(arquivo); //Define a informação do arquivo que será considerada idade
        clientes.idade = stoi(idade); //Copia a string "idade" para o inteiro "clientes.idade" (stoi)
        
        arqvsaida.write((const char *)&clientes, sizeof(dados)); // Escreve os dados do registro no arquivo binário
    }
    arqvsaida.close();
}

string leituraCelula(ifstream &arquivo)
{
    string celula;
    char c;

    arquivo.read(&c, 1); //pula a vírgula (,) que separa as informações de uma linha do .csv
    if (c == '\"'){ // verifica se o caracter lido é uma aspas
        arquivo.read(&c, 1); //lê a aspas, sem armazená-la
        do{
            celula += c; //Adiciona todos os caracteres na string "celula"
            arquivo.read(&c, 1); //Lê cada caracter do arquivo
        } while (c != '\"');
        arquivo.read(&c, 1); // lê as aspas sem armazená-la
    }
    else { //Se não tiver aspas
        do{
            celula += c; //Adicona todos os caracteres na string "celula"
            arquivo.read(&c, 1); //Lê os caracteres do arquivo
        } while (c != ',' and c != '\n' and !arquivo.eof()); //Lê o arquivo até q o ponteiro de leitura encontre quebra de linha, "," ou o fim do arquivo
    }
    return celula; //retorna a celula lida
}

void exportaCsv(string nomeArquivo){
    string csv; 
    cout << "Digite o nome do arquivo para exportar a base de dados: ";
    getline(cin,csv); //Usuário informa o nome do arquivo .csv de exportação

    ifstream arq_entrada(nomeArquivo,ios::binary); //Abre o arquivo para leitura binária
    ofstream arquivo_csv(csv, ios::trunc | ios::out); //Abre o arquivo, excluindo seus dados, para escrita

    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo binário
    dados aux;

    for (int i = 0; i < tamanho; i++){
        arq_entrada.read((char *) &aux, sizeof(dados)); //Lê o arquivo binário e copia os dados para o registro "aux"
        arquivo_csv << aux.nome << "," << aux.sexo << "," << aux.cpf << ","
                    << aux.dinheiro << "," << aux.conexao << "," << aux.idade <<"\n"; //Escreve no arquivo csv os dados, sendo que o (,) = mudança de colunas e o (\n) = quebras de linha
    }

    cout << "\nBase de dados exportada com sucesso!";

    arq_entrada.close();
    arquivo_csv.close();

    if(repeteOpcao())
        exportaCsv(nomeArquivo);
}

void imprimirListaClientes(string nomeArquivo){
    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo binário

    dados cliente;

    int inicio, fim, deletados = 0;
    ifstream arquivo(nomeArquivo, ios_base::binary | ios_base::in);

    for (int i = 0; i < tamanho; i++){ //Define a quantidade de dados deletados
        arquivo.read((char *)&cliente,sizeof(dados));
        if(cliente.apagado)
            deletados++;
    }

    arquivo.seekg(ios::beg); //Posiciona o ponteiro de leitura no início
    
    cout << "Deseja imprimir o arquivo todo na tela: (1)Sim (2)Não\n";
     
    if(escolhaOpcao("(1)Sim","(2)Nao")){
        limpaTerminal();
        while(arquivo.read((char*) &cliente, sizeof(dados))){ //Lê o arquivo e armazena no registro "cliente"
            if(!cliente.apagado){ //Se o cliente não possuir o marcador lógico de exclusão, imprime na tela
                imprimeDados(cliente);
            }   
        }
    }else { //Permite ao usuário imprimir a quantidade de clientes desejada
    limpaTerminal();
        cout << "O arquivo tem " << tamanho << " clientes, sendo que desses, " << deletados << " foram deletados\n\n"; //Informa a quantidade de clientes no arquivo
        cout << "Deseja imprimir a partir de qual cliente? \n";
    
        while(!verificaInt(inicio)){
            cout << "Formato invalido, deseja imprimir a partir de qual cliente: ";
        }

        cout << "Deseja imprimir ate qual cliente? \n";

        if(!verificaInt(fim)){
            cout << "Formato invalido, sera impresso ate o ultimo cliente\n";
            fim = tamanho;
        }

        while(fim < inicio or fim > tamanho){ //Impede situações impossíveis, tais como clientes fora do limite do arquivo e valor final < valor inicial
            cout << "\nNao e permitido imprimir ate esse cliente!\n";
            cout << "OBS: Verifique o valor digitado e a quantidade de dados do arquivo\n\n";
            cout << "Digite novamente ate qual cliente deseja imprimir: ";

            if(!verificaInt(fim)){
            cout << "Formato invalido, sera impresso ate o ultimo cliente\n";
            fim = tamanho;
            }
        }

        limpaTerminal();
        arquivo.seekg((inicio-1)*sizeof(dados)); //Posiciona o arquivo na linha desejada
        
        for (int i = 0; i <= fim-inicio; i++){ //Percorre o arquivo e imprime até o cliente desejado
            arquivo.read((char*) &cliente, sizeof(dados));
            if(!cliente.apagado){ //Caso o cliente esteja com marcador lógico de apagado, ele não é impresso na tela
                imprimeDados(cliente);
            }
        }   
    }
    arquivo.close();

    if(repeteOpcao()){
        imprimirListaClientes(nomeArquivo);
    }
}

void ordena(string nomeArquivo, bool& shell1, bool& shell2){
    
    cout << "Deseja ordenar os clientes pela idade ou pelo nome?" <<   endl;
    cout << "(1) Idade" << endl;
    cout << "(2) Nome" << endl;
    
    if(escolhaOpcao("(1)Idade","(2)Nome")){
        shellSortIdade(nomeArquivo); //Ordena o arquivo pela Idade dos clientes
        shell1 = 1; //Determina se o arquivo foi ordenado pela idade
    }
    else{
        shellSortNome(nomeArquivo); //Ordena o arquivo pelo Nome dos clientes
        shell2 = 1; //Determina se o arquivo foi ordenado pelo nome
    }
    
    cout << endl << "Clientes ordenados com sucesso!";

    if(repeteOpcao()){ 
        ordena(nomeArquivo,shell1,shell2);
    }
}

void shellSortIdade(string nomeArquivo){
    ifstream arquivo(nomeArquivo,ios::binary | ios::in); //Abre o arquivo para leitura binária

    int tamanho = tamanhoArquivo(nomeArquivo), deletados = 0; //Informa o tamanho do arquivo

    dados aux;
    
    for (int i = 0; i < tamanho; i++){ //Define a quantidade de dados deletados
        arquivo.read((char *)&aux,sizeof(dados));
        if(aux.apagado)
        deletados++;
    }

    arquivo.seekg(ios::beg);
    tamanho -= deletados;
    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++){
        arquivo.read((char*)&aux, sizeof(dados)); //Armazena todos os dados do arquivo em um registro
        if(!aux.apagado)
            vet[i] = aux;
    }
    
    int gaps[7] = {1, 4, 13, 40, 121, 364, 1093}; //Sequência de Knuth
    int pos_gap = 6; //Posicão do último elemento da sequência de Knuth
    while (gaps[pos_gap] > tamanho) {
        pos_gap--; //Define o primeiro gap
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap]; //Define o tamanho dos gaps

        for (int k = gap; k < tamanho; k++) { //Insertion Sort tradicional porém com gaps entre as comparações
            valor = vet[k]; //Armazena o registro analisado em uma variável aux
            j = k;
            while ((j >= gap) and (valor.idade < vet[j - gap].idade)) { //Compara o campo da idade
                vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
    }
    arquivo.close();
    
    apagaEscreve(nomeArquivo,tamanho,vet); //Escreve no arquivo o vetor já ordenado
    delete[] vet;
}

void shellSortNome(string nomeArquivo){
    ifstream arquivo(nomeArquivo,ios::binary | ios::in); //Abre o arquivo para leitura binária

    int tamanho = tamanhoArquivo(nomeArquivo), deletados = 0; //Informa o tamanho do arquivo

    dados aux;
    
    for (int i = 0; i < tamanho; i++){ //Define a quantidade de dados deletados
        arquivo.read((char *)&aux,sizeof(dados));
        if(aux.apagado)
        deletados++;
    }

    arquivo.seekg(ios::beg);
    tamanho -= deletados;
    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++){
        arquivo.read((char*)&aux, sizeof(dados)); //Armazena todos os dados do arquivo em um vetor
        if(!aux.apagado)
            vet[i] = aux;
    }
    int gaps[7] = {1, 4, 13, 40, 121, 364, 1093}; //Sequência de Knuth
    int pos_gap = 6; //Posicão do último elemento da sequência de Knuth
    while (gaps[pos_gap] > tamanho) {
        pos_gap--; //Define o primeiro gap
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap]; //Define o tamanho dos gaps

        for (int k = gap; k < tamanho; k++) { //Insertion Sort tradicional porém com gaps entre as comparações
            valor = vet[k]; //Armazena o registro analisado em uma variável aux
            j = k;
            while ((j >= gap) and (strcmp(valor.nome,vet[j - gap].nome) <= 0)) { //Compara o campo do nome
                vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
    }
    arquivo.close();

    apagaEscreve(nomeArquivo,tamanho,vet); //Escreve no arquivo o vetor já ordenado
    delete[] vet;
}

void excluirCliente(string nomeArquivo){
    fstream arquivo(nomeArquivo); //Abre o arquivo para leitura e escrita

    int tamanho = tamanhoArquivo(nomeArquivo), cont = 0, posicao = -1;
    char escolha;
    dados procura;

    string cpf_buscado;
    cout << "Digite o CPF do cliente que deseja excluir (11 digitos): "; 

    getline(cin,cpf_buscado);

    while ((cont < tamanho) and (posicao ==-1)){ //Lê todo o arquivo ou para quando o cpf buscado for encontrado
        arquivo.seekg(cont*sizeof(dados)); //Posiciona o ponteiro de leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê o arquivo
        if ((strcmp(cpf_buscado.c_str(),procura.cpf)==0) && (!procura.apagado)){ //Verifica se os cpfs são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont;
            arquivo.seekp(-static_cast<int>(sizeof(dados)), ios::cur); //Posiciona o ponteiro de escrita dentro do registro com o código buscado
            procura.apagado = 1; //Altera o marcador "apagado" para true (1)
            arquivo.write((char *) &procura,sizeof(dados)); //Escreve o marcador alterado no arquivo
        }
        cont++;
    }

    if(posicao == -1) //Caso o cpf não exista no arquivo
        cout << "\nCPF nao encontrado!";
    else{ 
        cout << "\nCliente excluido com sucesso!";
    }

    arquivo.close();

    if(repeteOpcao()){ 
        excluirCliente(nomeArquivo);
    }
}

void buscarCliente(string nomeArquivo){
    cout << "\nDigite o campo do cliente que deseja fazer a busca:\n";
    cout << "(1) CPF;\n";
    cout << "(2) Nome;\n";
    
    if(escolhaOpcao("(1)CPF","(2)Nome")) 
        buscarCpf(nomeArquivo); //Busca um medicamento pelo código do mesmo
    else
        buscarNome(nomeArquivo); //Busca um medicamento pela descrição do mesmo

    if(repeteOpcao()){ 
        buscarCliente(nomeArquivo);
    }
}

void buscarCpf(string nomeArquivo){
    int posicao = -1;
    dados procura = getCliente(nomeArquivo,posicao);

    if(posicao == -1) //Se não for encontrado o CPF desejado
        cout << "\nCliente nao encontrado!";
    else{
        ifstream arquivo (nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição do CPF buscado
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao cliente do CPF informado
        
        //Exibe as informações do cliente buscado
        imprimeDados(procura);
        arquivo.close();
    }
}

void buscarNome(string nomeArquivo){
    ifstream arquivo (nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    string nome_buscado;
    cout << "Digite o nome buscado (maximo 200 caracteres): "; 
   
    getline(cin,nome_buscado); //Nome que se deseja buscar na base de dados
    
    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que o nome buscado seja encontrado
        arquivo.seekg(cont*sizeof(dados)); //Reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if ((strcmp(nome_buscado.c_str(),procura.nome)==0) && (!procura.apagado)) //Verifica se os nomes são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo do nome procurado
        cont++;
    }

    if(posicao == -1) //Se não for encontrada o nome desejado
        cout << endl << "Cliente nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição do nome procurado
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao cliente do nome informado
        
        //Exibe as informações do cliente buscado
        imprimeDados(procura);
        arquivo.close();
    }
}

void cadastrarCliente(string nomeArquivo, bool& sheel1, bool& sheel2){  
    int posicao = -1;
    dados procura = getCliente(nomeArquivo,posicao);

        if(posicao == -1){ //Caso o cliente não esteja cadastrado
            cout << "Cliente não esta no sistema, digite os dados: \n";
            escreveFinal(nomeArquivo,entradaDados(procura)); //Escreve no final do arquivo
            cout << "\nCliente registrado com sucesso!";

            if(sheel1)
                shellSortIdade(nomeArquivo);
            else if(sheel2)
                shellSortNome(nomeArquivo);  
        }
        else
            cout << "\ncliente ja esta no sistema, tente novamente!\n\n";

    if(repeteOpcao()){ 
        cadastrarCliente(nomeArquivo,sheel1,sheel2);
    }
}

dados entradaDados(dados cliente){
    string dado;

    cout << "\nInforme o nome do cliente: ";
    getline(cin,dado);
    strcpy(cliente.nome,dado.c_str());

    cout << "Informe o sexo (M)Masculino e (F)Feminino: ";
    while(!verificaSexo(dado)){
        cout << "Valor informado nao atende as possibilidades, digite novamente (M)Masculino (F)Feminino: ";
    }
    cliente.sexo = dado[0];

    cout << "Informe o dinheiro: ";
    float dinheiro;
    while(!verificaFloat(dinheiro)){
        cout << "Valor informado nao corresponde a um valor valido, digite novamente: ";
    } 
    cliente.dinheiro = dinheiro;

    cout << "Informe a conexao - 3G, 4G ou Wifi: ";   
    while(!verificaConexao(dado)){
        cout << "Valor informado nao atende as possibilidades, digite novamente (3G, 4G ou WIfi): ";
    }
    strcpy(cliente.conexao,dado.c_str());

    cout << "Informe a idade: ";
    int idade;
    while(!verificaInt(idade)){
        cout << "Valor informado nao corresponde a uma idade valida, digite novamente: ";
    } 
    cliente.idade = idade;
    
    return cliente;
}

bool verificaFloat(float &num){
    string numero;
    bool aux = true;

    getline(cin,numero);

    for (int i = 0; i < numero.size(); i++){
        
        if(numero[i] == ',')
            numero.replace(i,1,".");

        if (!isdigit(numero[i]) and numero[i] != '.'){
            aux = false;
            i = numero.size();
        }
    }
    
    if (aux == true){
        num = stof(numero);
    }

    return aux;
}

bool verificaInt(int& num){
    string numero;

    getline(cin,numero);

    bool aux = true;

    for (int i = 0; i < numero.size(); i++){
        if (!isdigit(numero[i])){
            aux = false;
            i = numero.size();
        }
    }

    if (aux == true){
        num = stoi(numero);
    } else{
        num = 0;
    }

    return aux;
}

bool verificaSexo(string& sexo){
    string dado;
    string possibilidades[] = {"F","M"};

    getline(cin,dado);

    for (int i = 0; i <= possibilidades->size(); i++){
        if(strcmp(dado.c_str(),possibilidades[i].c_str()) == 0){
            sexo = dado[0];
            return 1;
        }
    }
    return 0;
}

bool verificaConexao(string& conexao){
    string dado;
    string possibilidades[] = {"3G", "4G","Wifi"};

    getline(cin,dado);

    for (int i = 0; i <= possibilidades->size(); i++){
        if(strcmp(dado.c_str(),possibilidades[i].c_str()) == 0){
            strcpy((char*)conexao.c_str(),dado.c_str());
            return 1;
        }
    }
    return 0;
}

bool verificaCpf(string& cpf){
    string dado;

    getline(cin,dado);

    if(strlen(dado.c_str()) != 11){
        return 0;
    }

    for (int i = 0; i < dado.size(); i++){
        if(!isdigit(dado[i])){
            return 0;
        }
    }

    strcpy((char*)cpf.c_str(),dado.c_str());
    
    return 1;
}

dados getCliente(string nomeArquivo, int& posicao){
    ifstream arquivo (nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    string cpf; 
    cout << "Digite o CPF para verificar se existe no sistema (11 digitos numerico): "; 
    
    while(!verificaCpf(cpf)){
        cout << "O CPF informado nao esta de acordo com o padrao esperado (11 digitos numerico). Digite novamente: ";
    }

    limpaTerminal();

    int cont = 0;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que o CPF buscado seja encontrado
        arquivo.seekg(cont*sizeof(dados)); //Reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if ((strcmp(cpf.c_str(),procura.cpf)==0) && (!procura.apagado)) //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo do código de barras procurado
        cont++;
    }
    arquivo.close();

    if(posicao == -1){
        strcpy(procura.cpf,cpf.c_str());
    }

    return procura;
}

void editarCliente(string nomeArquivo){
    int posicao = -1;
    dados procura = getCliente(nomeArquivo,posicao);

    if(posicao == -1) //Caso o cpf não exista no arquivo
        cout << "\nCPF nao encontrado!";
    else{ 
        cout << endl << "Cliente encontrado, digite seus novos dados: ";
        fstream arquivo(nomeArquivo); //Abre o arquivo para leitura e escrita
        arquivo.seekp((posicao+1)*sizeof(dados)); //Posiciona o ponteiro de escrita
        arquivo.seekp(-static_cast<int>(sizeof(dados)), ios::cur); //Posiciona o ponteiro de escrita dentro do registro com o cpf buscado
        dados cliente = entradaDados(procura);
        arquivo.write((char *) &cliente,sizeof(dados)); //Escreve o marcador alterado no arquivo
        arquivo.close();
        cout << "\nCliente editado com sucesso!";
    }

    if(repeteOpcao()){ 
        editarCliente(nomeArquivo);
    }
}

bool repeteOpcao(){
    string escolha;
    cout << "\n\nDigite (1) para voltar ao menu ou (2) para repetir a opcao:";
    getline(cin,escolha); //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(!strcmp(escolha.c_str(),"1") == 0 && !strcmp(escolha.c_str(),"2") == 0){ //Impede que outros valores sejam inseridos
        limpaTerminal();
        cout << "\nOpcao nao disponivel, digite novamente: \n";
        cout << "(1)menu ou (2)repetir opcao\n";
        getline(cin,escolha);
    }

    limpaTerminal();

    if(strcmp(escolha.c_str(),"2") == 0){
        return true;
    }
    return false;
}

bool escolhaOpcao(string opcao1, string opcao2){
    string escolha; 
    getline(cin,escolha);

    while(!strcmp(escolha.c_str(),"1") == 0 && !strcmp(escolha.c_str(),"2") == 0){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: \n";
        cout << opcao1 + " ou " + opcao2 << endl;
        getline(cin,escolha);
    }

    if(strcmp(escolha.c_str(),"1") == 0 )
        return 1;
    return 0;
}

void imprimeDados(dados cliente){
    cout << cliente.nome <<" - ";
    cout << cliente.sexo << " - ";
    cout << cliente.cpf << " - ";
    cout << cliente.dinheiro << " - "; 
    cout << cliente.conexao << " - ";
    cout << cliente.idade << endl; //Imprime na tela todos os medicamentos do arquivo binário
}