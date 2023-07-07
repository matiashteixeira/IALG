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
#include <iomanip> //Formatação
#include <fstream>
#include <string.h>
using namespace std; 

struct dados{
    bool apagado = 0;
    char nome[200];
    char sexo[10];
    char cep[10];
    float dinheiro;
    char conexao[10];
    int idade;
};

void importaCsv(string entrada, string saida);
string leituraCelula(ifstream &arquivo); //Elimina ; e lê cada coluna do arquivo csv
void exportaCsv(string nomeArquivo); //Exporta para um arquino .csv
//Ordena--------------------------------------------------------
void ordena(string nomeArquivo, bool& shell1, bool& shell2); //Chama as funções de ordenação
void shellSortIdade(string nomeArquivo); //Ordena pelo preço da farmácia 1
void shellSortNome(string nomeArquivo); //Ordena pelo preço da Farmácia 2
//Imprime-------------------------------------------------------
void imprimirListaClientes(string nomeArquivo); //Imprime na tela os medicamentos desejados
//Busca---------------------------------------------------------
void buscarCliente(string nomeArquivo); //Chama as funções de busca
void buscarCep(string nomeArquivo); 
void buscarNome(string nomeArquivo); 
//Exclui--------------------------------------------------------
void excluirCliente(string nomeArquivo); //Exlui o medicamento desejado a partir do código de barras
//Insere--------------------------------------------------------
void cadastrarCliente(string nomeArquivo, bool& sheel1, bool& sheel2); //Insere novos medicamentos no arquivo
//Auxiliares----------------------------------------------------
void menu(); //Imprime na tela as opções disponíveis para os usuários
void limpaTerminal(); //Limpa o terminal
int tamanhoArquivo(string nomeArquivo); //Informa o tamanho atual do arquivo binário
void apagaEscreve(string nomeArquivo, int tamanho, dados* vetor); //Apaga todo o arquivo para reescrevê-lo novamente com os dados desejados
void escreveFinal(string nomeArquivo, dados procura); //Escreve novos dados no final do arquivo
void editar(string nomeArquivo);

int main(){
    char opcao; 
    bool shell1 = 0, shell2 = 0;
    string arquivo_csv = "clientes.csv"; 
    string arquivo_bin = "clientes.bin"; 

    ifstream arquivo(arquivo_csv);
    if(!arquivo){
        cout << "\nO arquivo não foi aberto, verifique se o arquivo (clientes.csv) existe!\n\n";
        return 0;
    }
    arquivo.close();

    importaCsv(arquivo_csv, arquivo_bin); 
    
    do{
        menu();
        cin >> opcao;
        limpaTerminal();

        switch (opcao){
        case '1':
            cadastrarCliente(arquivo_bin, shell1, shell2);
            break;

        case '2':
            buscarCliente(arquivo_bin);
            break;

        case '3':
            imprimirListaClientes(arquivo_bin);
            break;

        case '4':
            excluirCliente(arquivo_bin);
            break;

        case '5':
            ordena(arquivo_bin,shell1,shell2);
            break;

        case '6':
            editar(arquivo_bin);
            break;

        case '7':
            exportaCsv(arquivo_bin);
            break;

        case '8':
            cout << "\n\n||-------------------------------Volte Sempre!-------------------------------||\n\n";
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl; //Em caso de valores diferentes do esperado, o programa pede para o usuário tentar novamente
            break;
        }
    } while(opcao != '8');

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
        arquivo.write((const char *) &vet[k], sizeof(dados)); //Escreve no arquivo os dados desejados
        
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

//Importa-Exporta------------------------------------------------
void importaCsv(string entrada, string saida){
    ifstream arquivo(entrada); //Entra no arquivo .csv para leitura
    dados clientes;
    ofstream arqvsaida(saida, ios::binary); //Abre o arquivo para escrita em binário

    while (!arquivo.eof()) { // Lê o arquivo até ele chegar ao fim
        string nome = leituraCelula(arquivo); //Define a informação do arquivo que será considerada descrição
        strcpy(clientes.nome, nome.c_str()); //Copia a string "descricao" para o registro "base10.descricao"

        string sexo = leituraCelula(arquivo); //Define a informação do arquivo que será considerada código de barras
        strcpy(clientes.sexo, sexo.c_str());
    
        string cep = leituraCelula(arquivo);
        strcpy(clientes.cep, cep.c_str());

        string dinheiro = leituraCelula(arquivo); //Define a informação do arquivo que será considerada preço
        clientes.dinheiro = stof(dinheiro); //Copia a string "preco1" para o float "base10.preco1" (stof)

        string conexao = leituraCelula(arquivo); //Define a informação do arquivo que será considerada descrição
        strcpy(clientes.conexao, conexao.c_str()); //Copia a string "descricao" para o registro "base10.descricao"

        string idade = leituraCelula(arquivo); //Define a informação do arquivo que será considerada preço
        clientes.idade = stoi(idade); //Copia a string "preco2" para o float "base10.preco2" (stof)
        
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
    cout << "Digite o nome do arquivo .csv para exportar a base de dados: ";
    cin >> csv; //Usuário informa o nome do arquivo .csv de exportação

    ifstream arq_entrada(nomeArquivo,ios::binary); //Abre o arquivo para leitura binária
    ofstream arquivo_csv(csv, ios::trunc | ios::out); //Abre o arquivo, excluindo seus dados, para escrita

    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo binário
    dados aux;

    for (int i = 0; i < tamanho; i++){
        arq_entrada.read((char *) &aux, sizeof(dados)); //Lê o arquivo binário e copia os dados para o registro "aux"
        arquivo_csv << aux.nome << "," << aux.sexo << "," << aux.cep << ","
                    << aux.dinheiro << "," << aux.conexao << "," << aux.idade <<"\n"; //Escreve no arquivo csv os dados, sendo que o (;) = mudança de colunas e o (\n) = quebras de linha
    }

    cout << endl << "Base de dados exportada com sucesso!";
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para exportar novamente:";
    char escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada
    cin >> escolha; 

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)exportar novamente" << endl;
        cin >> escolha;
    }
    limpaTerminal();

    arq_entrada.close();
    arquivo_csv.close();

    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        exportaCsv(nomeArquivo);
}

//Imprime--------------------------------------------------------
void imprimirListaClientes(string nomeArquivo){

    int tamanho = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo binário

    dados cliente;
    char escolha;
    int inicio, fim, cont = 0, deletados = 0;
    ifstream arquivo(nomeArquivo, ios_base::binary | ios_base::in);

    for (int i = 0; i < tamanho; i++){ //Define a quantidade de dados deletados
        arquivo.read((char *)&cliente,sizeof(dados));
        if(cliente.apagado)
            deletados++;
    }

    arquivo.seekg(ios::beg); //Posiciona o ponteiro de leitura no início

    cout << "Deseja imprimir o arquivo todo na tela?" << endl;
    cout << "(1)sim ou (2)nao" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)sim ou (2)nao" << endl;
        cin >> escolha;
    }
     
    if(escolha == '1'){
        while(arquivo.read((char*) &cliente, sizeof(dados))){ //Lê o arquivo e armazena no registro "med"
            if(!cliente.apagado){
                cout << cliente.nome << "  " << cliente.sexo << "  " << cliente.cep << "  "; 
                cout << cliente.dinheiro << "  " << cliente.conexao << " " << cliente.idade << endl; //Imprime na tela todos os medicamentos do arquivo binário
            }   
        }
    }else if(escolha == '2'){
        cout << "O arquivo tem " << tamanho << " clientes, sendo que desses, " << deletados << " foram deletados" << endl << endl; //Informa a quantidade de medicamentos no arquivo
        cout << "Deseja imprimir a partir de qual cliente? " << endl;
        cin >> inicio; //Variável que determina a partir de qual medicamento será impresso na tela
        cout << "Deseja imprimir ate qual cliente? " << endl;
        cin >> fim; //Variável que determina o último medicamento que será impresso na tela

        while(fim < inicio or fim > tamanho){ //Impede situações impossíveis, tais como medicamentos fora do limite do arquivo e valor final < valor inicial
            cout << endl << "Nao e permitido imprimir ate esse medicamento!" << endl;
            cout << "OBS: Verifique o valor digitado e a quantidade de dados do arquivo" << endl << endl;
            cout << "Digite novamente ate qual medicamento deseja imprimir: ";
            cin >> fim;
        }
        limpaTerminal();

        arquivo.seekg((inicio-1)*sizeof(dados)); //Posiciona o arquivo na linha desejada
        while(arquivo.read((char*) &cliente, sizeof(dados)) && fim-inicio >= cont){ //Lê o arquivo até que todos os medicamentos desejados sejam impressos
            if(!cliente.apagado){
                cout << cliente.nome << "  " << cliente.sexo << "  " << cliente.cep << "  "; 
                cout << cliente.dinheiro << "  " << cliente.conexao << " " << cliente.idade << endl; //Imprime na tela todos os medicamentos do arquivo binário
                cont++; //Variável de contagem auxiliar
            }
        }
    }
    arquivo.close();

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para imprimir outros medicamentos:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)imprimir outros clientes" << endl;
        cin >> escolha; 
    }
    limpaTerminal();
    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        imprimirListaClientes(nomeArquivo);
}

//Ordena---------------------------------------------------------
void ordena(string nomeArquivo, bool& shell1, bool& shell2){
    char escolha; 
    cout << "Deseja ordenar os clientes pela idade ou pelo nome?" <<   endl;
    cout << "(1) Idade" << endl;
    cout << "(2) Nome" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)Idade ou (2)Nome" << endl;
        cin >> escolha;
    }
    
    if(escolha == '1'){
        shellSortIdade(nomeArquivo); //Ordena o arquivo pelo preço da farmácia 1
        shell1 = 1; //Determina se o arquivo foi ordenado pelo preço 1
    }
    else{
        shellSortNome(nomeArquivo); //Ordena o arquivo pelo preço da farmácia 2
        shell2 = 1; //Determina se o arquivo foi ordenado pelo preço 2
    }
    
    cout << endl << "Clientes ordenados com sucesso!";

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para ordenar novamente os clientes:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)ordenar novamente os clientes" << endl;
        cin >> escolha; 
    }
    limpaTerminal();
    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        ordena(nomeArquivo,shell1,shell2);
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
            while ((j >= gap) and (valor.idade < vet[j - gap].idade)) { //Compara o campo do preço 1
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
            while ((j >= gap) and (strcmp(valor.nome,vet[j - gap].nome) <= 0)) { //Compara o campo do preço 2
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

//Exclui---------------------------------------------------------
void excluirCliente(string nomeArquivo){
    fstream arquivo(nomeArquivo); //Abre o arquivo para leitura e escrita

    int tamanho = tamanhoArquivo(nomeArquivo), cont = 0, posicao = -1;
    char escolha;
    dados procura;

    char nome_buscado[200];
    cout << "Digite o nome que deseja excluir: "; 
    cin >> nome_buscado;

    while ((cont < tamanho) and (posicao ==-1)){ //Lê todo o arquivo ou para quando o código buscado for encontrado
        arquivo.seekg(cont*sizeof(dados)); //Posiciona o ponteiro de leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê o arquivo
        if ((strcmp(nome_buscado,procura.nome)==0) && (!procura.apagado)){ //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont;
            arquivo.seekp(-static_cast<int>(sizeof(dados)), ios::cur); //Posiciona o ponteiro de escrita dentro do registro com o código buscado
            procura.apagado = 1; //Altera o marcador "apagado" para true (1)
            arquivo.write((char *) &procura,sizeof(dados)); //Escreve o marcador alterado no arquivo
        }
        cont++;
    }

    if(posicao == -1) //Caso o código não exista no arquivo
        cout << endl << "Nome nao encontrado!";
    else{ 
        cout << endl << "Cliente excluido com sucesso!";
    }
    
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para excluir outros clientes:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)excluir outros clientes" << endl;
        cin >> escolha; 
    }
    limpaTerminal();
    arquivo.close();

    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        excluirCliente(nomeArquivo);
}

//Busca----------------------------------------------------------
void buscarCliente(string nomeArquivo){
    char escolha;
    cout << endl << "Digite o campo do cliente que deseja fazer a busca:" << endl;
    cout << "(1) CEP;" << endl;
    cout << "(2) Nome;" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)CEP ou (2)Nome" << endl;
        cin >> escolha;
    }
    
    if(escolha == '1') 
        buscarCep(nomeArquivo); //Busca um medicamento pelo código do mesmo
    else
        buscarNome(nomeArquivo); //Busca um medicamento pela descrição do mesmo

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para buscar outros clientes:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)buscar outros clientes" << endl;
        cin >> escolha;
    }
    limpaTerminal();
    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        buscarCliente(nomeArquivo);
}

void buscarCep(string nomeArquivo){
    ifstream arquivo (nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    char cep[10]; 
    cout << "Digite o codigo de barras buscado: "; 
    cin >> cep; //Código que se deseja busca na base de dados

    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que o código buscado seja encontrado
        arquivo.seekg(cont*sizeof(dados)); //Reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if ((strcmp(cep,procura.cep)==0) && (!procura.apagado)) //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo do código de barras procurado
        cont++;
    }

    if(posicao == -1) //Se não for encontrado o código de barras desejado
        cout << endl << "Medicamento nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição do código de barras buscado
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao medicamento do código de barras informado
        
        //Exibe as informações do medicamento buscado
        cout << endl << "Nome: " << procura.nome << endl; 
        cout << "Sexo: " << procura.sexo << endl;
        cout << "CEP: " << procura.cep << endl;
        cout << "Dinheiro: " << procura.dinheiro << endl;
        cout << "Conexao: " << procura.conexao << endl;
        cout << "Idade: " << procura.idade << endl;
        arquivo.close();
    }
}

void buscarNome(string nomeArquivo){
    ifstream arquivo (nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo

    char nome_buscado[200];
    cout << "Digite o nome buscado: "; 
    cin.ignore();
    cin.getline(nome_buscado, sizeof(char[200])); //Descrição que se deseja busca na base de dados
    
    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que a descrição buscada seja encontrada
        arquivo.seekg(cont*sizeof(dados)); //Reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if ((strcmp(nome_buscado,procura.nome)==0) && (!procura.apagado)) //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
            posicao = cont; //Define a posição no arquivo da descrição procurada
        cont++;
    }

    if(posicao == -1) //Se não for encontrada a descrição desejada
        cout << endl << "Cliente nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição da descrição procurada
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao medicamento da descrição informada
        
        //Exibe as informações do medicamento buscado
        cout << endl << "Nome: " << procura.nome << endl; 
        cout << "Sexo: " << procura.sexo << endl;
        cout << "CEP: " << procura.cep << endl;
        cout << "Dinheiro: " << procura.dinheiro << endl;
        cout << "Conexao: " << procura.conexao << endl;
        cout << "Idade: " << procura.idade << endl;
        arquivo.close();
    }
}

//Inserir-------------------------------------------------------
void cadastrarCliente(string nomeArquivo, bool& sheel1, bool& sheel2){  
    ifstream arquivo(nomeArquivo, ios::in | ios::binary); //Abre o arquivo para leitura binária
     
    int qtd_dados = tamanhoArquivo(nomeArquivo); //Informa o tamanho do arquivo
    
        char nome_inserir[200];
        cout << "Digite o nome que deseja inserir: "; 
        cin.ignore();
        cin.getline(nome_inserir, sizeof(char[200])); //Descrição que se deseja busca na base de dados

        int cont = 0, posicao = -1;
        
        dados procura;
        
        while ((cont < qtd_dados) and (posicao ==-1)){ //Lê todo o arquivo ou para quando o código buscado for encontrado
            arquivo.seekg(cont*sizeof(dados)); //Posiciona o ponteiro de leitura
            arquivo.read((char*) &procura, sizeof(dados)); //Lê o arquivo
            if (strcmp(nome_inserir,procura.nome)==0 and !procura.apagado) //Verifica se os códigos são iguais e se o arquivo não está com o marcador de apagado
                posicao = cont; //Define a posição no arquivo do código de barras que se deseja inserir
            cont++;
        }

        if(posicao == -1){ //Caso o medicamento não esteja cadastrado
            strcpy(procura.nome,nome_inserir); //Copia o código digitado para o registro "procura"
            cout << endl << "Informe o sexo: ";
            cin >> procura.sexo;
            cout << endl << "Informe o CEP (So escreva os digitos): ";
            cin >> procura.cep;
            cout << endl << "Informe o dinheiro (Utilize ponto (.) em vez de virgula (,)!): ";
            cin >> procura.dinheiro;
            cout << endl << "Informe a conexao - Positiva ou Negativa: "; 
            cin.ignore();
            cin.getline(procura.conexao,sizeof(char[10]));
            cout << endl << "Informe a idade: ";
            cin >> procura.idade;

            escreveFinal(nomeArquivo,procura); //Escreve no final do arquivo
            cout << endl << "Cliente registrado com sucesso!";

            if(sheel1)
                shellSortIdade(nomeArquivo);
            else if(sheel2)
                shellSortNome(nomeArquivo);
                
        }
        else
            cout << endl << "Medicamento ja esta no sistema, tente novamente!" << endl << endl;
    

    char escolha;
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para inserir outro medicamento:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != '1' && escolha != '2'){ //Impede que outros valores sejam inseridos
        cout << endl << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)inserir outro medicamento" << endl;
        cin >> escolha;
    }
    limpaTerminal();
    arquivo.close();
    if(escolha == '2') //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        cadastrarCliente(nomeArquivo,sheel1,sheel2);
}

void editar(string nomeArquivo){
    cout << "oi";
}