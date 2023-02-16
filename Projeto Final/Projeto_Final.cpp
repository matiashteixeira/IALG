#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std; 

struct dados{
    bool apagado = 0;
    float preco1, preco2;
    char codigo_barras[20];
    char descricao[200];
    char status[10];
};

//Importa-Exporta-----------------------------------------------
void importarcsv(string entrada, string saida);
string le_celula(ifstream &arquivo); //Elimina ; e lê cada coluna do arquivo csv
void exportarcsv(string nome_arq); //Exporta para um arquino .csv
//Ordena--------------------------------------------------------
void ordenar(string nome_arq, bool& shell1, bool& shell2); //Chama as funções de ordenação
void shell_sort_preco1(string nome_arq); //Ordena pelo preço da farmácia 1
void shell_sort_preco2(string nome_arq); //Ordena pelo preço da Farmácia 2
//Imprime-------------------------------------------------------
void imprimir(string nome_arq); //Imprime na tela os medicamentos desejados
//Busca---------------------------------------------------------
void buscar(string nome_arq); //Chama as funções de busca
void buscar_codigo(string nome_arq); //Busca pelo código do medicamento
void buscar_descricao(string nome_arq); //Busca pela descrição do medicamento
//Exclui--------------------------------------------------------
void excluir(string nome_arq); 
void excluir1(string nome_arq); //Exlui o medicamento desejado a partir do código de barras
//Insere--------------------------------------------------------
void inserir(string nome_arq, bool& sheel1, bool& sheel2); //Insere novos medicamentos no arquivo
//Auxiliares----------------------------------------------------
void menu(); //Imprime na tela as opções disponíveis para os usuários
void clear_terminal(); //Limpa o terminal
int tamanho_arq(string nome_arq); //Informa o tamanho atual do arquivo binário
void apaga_escreve(string nome_arq, int tamanho, dados* vet); //Apaga todo o arquivo para reescrevê-lo novamente com os dados desejados
void escreve_final(string nome_arq, dados procura); //Escreve novos dados no final do arquivo

int main(){
    int opcao; //Variável que o usuário insere para decidir qual função irá utilizar
    bool shell1 = 0, shell2 = 0; //Variáveis que verificam se o arquivo já foi ordenado (tanto pelo preço da farmácia 1 e farmácia 2)
    string arquivo_csv = "base10K.csv"; //Nome do arquivo .csv
    string arquivo_bin = "arqvsaida.bin"; //Nome do arquivo .bin
    importarcsv(arquivo_csv, arquivo_bin); 
    
    menu();
    cin >> opcao;
    clear_terminal();

    while(opcao != 7){ //Permite que o programa seja executado enquanto o usuário não inserir a opção (7) referente a sair do programa
        switch (opcao){ //Define qual função o programa irá rodar conforme o digitado pelo usuário
        case 1:
            inserir(arquivo_bin, shell1, shell2);
            break;

        case 2:
            excluir1(arquivo_bin);
            break;

        case 3:
            ordenar(arquivo_bin,shell1,shell2);
            break;

        case 4:
            imprimir(arquivo_bin);
            break;

        case 5:
            buscar(arquivo_bin);
            break;

        case 6:
            exportarcsv(arquivo_bin);
            break;
        
        default:
            cout << "Opcao invalida, tente novamente!" << endl; //Em caso de valores diferentes do esperado, o programa pede para o usuário tentar novamente
            break;
        }
        menu();
        cin >> opcao;
        clear_terminal();
    }
    cout << endl << endl << "---------------------Obrigado por usar nosso programa!---------------------" << endl << endl; //Mensagem de fim
    return 0;
}

//Auxiliares-----------------------------------------------------
void menu(){
    cout << endl << endl;
    cout << "Arquivo de dados da farmacia" << endl << endl;
    cout << " ************************************MENU************************************ " << endl << endl;
    cout << "Escolha uma das opcoes: " << endl << endl;
    cout << "(1) Inserir - Insere dados referentes a um ou mais medicamentos" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(2) Excluir - Exclui algum medicamento" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(3) Ordenar - Ordena os medicamentos existentes no arquivo" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(4) Imprimir - Exibe as informacoes dos arquivos desejados na tela" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(5) Buscar - Busca os dados de um medicamento existente a partir de um filtro" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(6) Exportar - Exporta os dados para um arquivo csv" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(7) Sair - Encerra o programa" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl << endl;
    cout << "Digite a opcao desejada: ";
}

void clear_terminal(){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
}

void apaga_escreve(string nome_arq, int tamanho, dados* vet){
    ofstream arquivo(nome_arq,ios::binary | ios::out | ios::trunc); //Abre o arquivo .bin no modo escrita binário, apagando todos os dados do mesmo (ios::trunc)
    for(int k = 0; k < tamanho; k++)
        arquivo.write((const char *) &vet[k], sizeof(dados)); //Escreve no arquivo os dados desejados
        
    arquivo.close();
}

void escreve_final(string nome_arq, dados procura){
    ofstream arquivo(nome_arq,ios::binary | ios::app | ios::ate); //Abre o arquino para escrita binário e insere dados no final sem apagar dados
    arquivo.write((const char *) &procura, sizeof(dados)); //escreve no arquivo os dados do registro "procura"

    arquivo.close();
}

int tamanho_arq(string nome_arq){
    ifstream arquivo(nome_arq, ios::ate); //Abre o arquivo e posiciona no final para leitura
    long int tamanho_arquivo = arquivo.tellg(); //Define o tamanho do arquivo em bytes
    int qtd_dados = int (tamanho_arquivo/sizeof(dados)); //Define a quantidade de dados do arquivo (qtd bytes do arquivo/qtd bytes do registro)

    arquivo.close();
    return qtd_dados;
}

//Importa-Exporta------------------------------------------------
void importarcsv(string entrada, string saida){
    ifstream arquivo(entrada); //Abre o arquivo .csv para leitura
    dados base10;
    ofstream arqvsaida(saida, ios::binary); //Abre o arquivo para escrita em binário

    while (!arquivo.eof()) // Lê o arquivo até o final do mesmo
    {
        string descricao = le_celula(arquivo); //Define a informação do arquivo que será considerada descrição
        strcpy(base10.descricao, descricao.c_str()); //Copia a string "descricao" para o registro "base10.descricao"

        string codigo_barras = le_celula(arquivo); //Define a informação do arquivo que será considerada código de barras
        strcpy(base10.codigo_barras, codigo_barras.c_str()); //Copia a string "codigo_barras" para o registro "base10.codigo_barras"
    
        string preco1 = le_celula(arquivo); //Define a informação do arquivo que será considerada preço
        int posicao1 = preco1.find(','); //Procura a vírgula no preço e define sua posicação na string "preco1"
        if (posicao1 < preco1.length()) //Se a vírgula estiver dentro do tamanho de preço
            preco1.replace(preco1.find(','), 1, "."); //Substitui a vírgula pelo ponto (.)
        base10.preco1 = stof(preco1); //Copia a string "preco1" para o float "base10.preco1" (stof)

        string preco2 = le_celula(arquivo); //Define a informação do arquivo que será considerada preço
        int posicao2 = preco2.find(','); //Procura a vírgula no preço e define sua posicação na string "preco2"
        if (posicao2 < preco2.length()) //Se a vírgula estiver dentro do tamanho de preço
            preco2.replace(preco2.find(','), 1, "."); //Substitui a vírgula pelo ponto (.)
        base10.preco2 = stof(preco2); //Copia a string "preco2" para o float "base10.preco2" (stof)
        
        string status = le_celula(arquivo); //Define a informação do arquivo que será considerada status
        strcpy(base10.status, status.c_str()); //Copia a string "status" para o registro "base10.status"
        
        arqvsaida.write((const char *)&base10, sizeof(dados)); // Escreve os dados do registro no arquivo binário
    }
    arqvsaida.close();
}

string le_celula(ifstream &arquivo)
{
    string celula;
    char c;
    arquivo.read(&c, 1); //pula o ponto e vírgula (;) que separa as informações de uma linha do csv
    if (c == '\"'){
        arquivo.read(&c, 1); // elimina a aspas
        do{
            celula += c;
            arquivo.read(&c, 1);
        } while (c != '\"');
        arquivo.read(&c, 1); // elimina o ";"
    }
    else
    {
        do{
            celula += c;
            arquivo.read(&c, 1);
        } while (c != ';' and c != '\n' and !arquivo.eof());
    }
    return celula;
}

void exportarcsv(string nome_arq){
    string csv; //Nome do arquivo .csv para exportação
    cout << "Digite o nome do arquivo .csv para exportar a base de dados: ";
    cin >> csv; //Usuário informa o nome do arquivo .csv de exportação

    ifstream arq_entrada(nome_arq,ios::binary); //Abre o arquivo para leitura binária
    ofstream arquivo_csv(csv, ios::trunc | ios::out); //Abre o arquivo, excluindo seus dados, para escrita

    int tamanho = tamanho_arq(nome_arq); //Informa o tamanho do arquivo binário
    dados aux;

    for (int i = 0; i < tamanho; i++){
        arq_entrada.read((char *) &aux, sizeof(dados)); //Lê o arquivo binário e copia os dados para o registro "aux"
        arquivo_csv << aux.descricao << ";" << aux.codigo_barras << ";" << aux.preco1 << ";"
                    << aux.preco2 << ";" << aux.status << "\n"; //Escreve no arquivo csv os dados, sendo que o (;) = mudança de colunas e o (\n) = linhas
    }

    cout << endl << "Base de dados exportada com sucesso!";
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para exportar novamente:";
    int escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada
    cin >> escolha; 

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)exportar novamente" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2) //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        exportarcsv(nome_arq);
}

//Imprime--------------------------------------------------------
void imprimir(string nome_arq){

    int tamanho = tamanho_arq(nome_arq); //Informa o tamanho do arquivo binário

    dados med;
    int escolha, inicio, fim, cont = 0;
    ifstream arquivo;
    arquivo.open(nome_arq, ios_base::binary | ios_base::in);

    cout << "Deseja imprimir o arquivo todo na tela?" << endl;
    cout << "(1)sim ou (2)nao" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)sim ou (2)nao" << endl;
        cin >> escolha;
    }
     
    if(escolha == 1){
        while(arquivo.read((char*) &med, sizeof(dados))){ //Lê o arquivo e armazena no registro "med"
        cout << med.descricao << "  " << med.codigo_barras << "  " << med.preco1 << "  "; 
        cout << med.preco2 << "  " << med.status << endl; //Imprime na tela todos os medicamentos do arquivo binário
        }
    }else if(escolha == 2){
        cout << "O vetor tem " << tamanho << " medicamentos" << endl << endl; //Informa a quantidade de medicamentos no arquivo
        cout << "Deseja imprimir a partir de qual medicamento? " << endl;
        cin >> inicio; //Variável que determina a partir de qual medicamento será impresso na tela
        cout << "Deseja imprimir ate qual medicamento? " << endl;
        cin >> fim; //Variável que determina o último medicamento que será impresso na tela

        while(fim < inicio or fim > tamanho){ //Impede situações impossíveis, tais como medicamentos fora do limite do arquivo e valor final < valor inicial
            cout << "Nao e permitido imprimir ate esse medicamento!" << endl;
            cout << "OBS: Verifique o valor digitado e a quantidade de dados do arquivo" << endl << endl;
            cout << "Digite novamente ate qual medicamento deseja imprimir: ";
            cin >> fim;
        }
        clear_terminal();

        arquivo.seekg((inicio-1)*sizeof(dados)); //Posiciona o arquivo na linha desejada
        while(arquivo.read((char*) &med, sizeof(dados)) && fim-inicio >= cont){ //Lê o arquivo até que todos os medicamentos desejados sejam impressos
            cout << med.descricao << " " << med.codigo_barras << " " << med.preco1 << " "; 
            cout << med.preco2 << " " << med.status << endl;
            cont++; //Variável de contagem auxiliar
        }
    }
    arquivo.close();

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para imprimir outros medicamentos:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)imprimir outros medicamentos" << endl;
        cin >> escolha; 
    }
    clear_terminal();
    if(escolha == 2) //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        imprimir(nome_arq);
}

//Ordena---------------------------------------------------------
void ordenar(string nome_arq, bool& shell1, bool& shell2){
    int escolha; 
    cout << "Deseja ordenar os medicamentos pelo preco crescente de venda da farmacia 1 ou da farmacia 2?" <<   endl;
    cout << "(1)Farmacia 1" << endl;
    cout << "(2)Farmacia 2" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)Preco de venda ou (2)Codigo de barras" << endl;
        cin >> escolha;
    }
    
    if(escolha == 1){
        shell_sort_preco1(nome_arq); //Ordena o arquivo pelo preço da farmácia 1
        shell1 = 1; //Determina se o arquivo foi ordenado pelo preço 1
    }
    else{
        shell_sort_preco2(nome_arq); //Ordena o arquivo pelo preço da farmácia 2
        shell2 = 1; //Determina se o arquivo foi ordenado pelo preço 2
    }
    
    cout << endl << "Medicamentos ordenados com sucesso!";

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para ordenar novamente os medicamentos:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)ordenar novamente os medicamentos" << endl;
        cin >> escolha; 
    }
    clear_terminal();
    if(escolha == 2) //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        ordenar(nome_arq,shell1,shell2);
}

void shell_sort_preco1(string nome_arq){
    ifstream arquivo(nome_arq,ios::binary | ios::in); //Abre o arquivo para leitura binária

    int tamanho = tamanho_arq(nome_arq); //Informa o tamanho do arquivo

    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++)
        arquivo.read((char*)&vet[i], sizeof(dados)); //Armazena todos os dados do arquivo em um vetor 
    
    
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
            while ((j >= gap) and (valor.preco1 < vet[j - gap].preco1)) { //Compara o campo do preço 1
                vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
    }
    arquivo.close();
    
    apaga_escreve(nome_arq,tamanho,vet); //Escreve no arquivo o vetor já ordenado
    delete[] vet;
}

void shell_sort_preco2(string nome_arq){
    ifstream arquivo(nome_arq,ios::binary | ios::in); //Abre o arquivo para leitura binária

    int tamanho = tamanho_arq(nome_arq); //Informa o tamanho do arquivo

    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++)
        arquivo.read((char*)&vet[i], sizeof(dados)); //Armazena todos os dados do arquivo em um vetor

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
            while ((j >= gap) and (valor.preco2 < vet[j - gap].preco2)) { //Compara o campo do preço 2
                vet[j] = vet[j - gap]; //Posiciona o elemento na sua posição correta em comparação com o outro registro analisado
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--; //Muda a posição do elemento de Knuth que será utilizado
    }
    arquivo.close();

    apaga_escreve(nome_arq,tamanho,vet); //Escreve no arquivo o vetor já ordenado
    delete[] vet;
}

//Exclui---------------------------------------------------------
void excluir(string nome_arq){
    ifstream arquivo (nome_arq, ios::in | ios::binary);
    int tamanho = tamanho_arq(nome_arq), escolha;
    tamanho--;

    char codigo_buscado[20];
    cout << "Digite o codigo de barras que deseja excluir: "; 
    cin >> codigo_buscado;

    int cont = 0, posicao = -1, aux = 0;
    dados procura;
    dados* vet;
    vet = new dados[tamanho];
    
    while ((cont < tamanho)){
        arquivo.seekg(cont*sizeof(dados));
        arquivo.read((char*) &procura, sizeof(dados));
        if (strcmp(codigo_buscado,procura.codigo_barras)==0)
            posicao = cont;
        else{
            vet[aux] = procura;
            aux++;
        }
        cont++;
    }

    arquivo.close();

    if(posicao == -1)
        cout << endl << "Codigo de barras nao encontrado!";
    else{
        apaga_escreve(nome_arq,tamanho,vet);
        cout << endl << "Medicamento excluido com sucesso!";
    }
    delete[] vet;

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para excluir outros medicamentos:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)excluir outros medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        excluir(nome_arq);
}

//Busca----------------------------------------------------------
void buscar(string nome_arq){
    int escolha;
    cout << endl << "Digite o campo do medicamento que deseja fazer a busca:" << endl;
    cout << "(1) Codigo de barras;" << endl;
    cout << "(2) Descricao;" << endl;
    cin >> escolha; //Permite o usuário escolher dentre as opções

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)Codigo de barras ou (2)Descricao" << endl;
        cin >> escolha;
    }
    
    if(escolha == 1) 
        buscar_codigo(nome_arq); //Busca um medicamento pelo código do mesmo
    else
        buscar_descricao(nome_arq); //Busca um medicamento pela descrição do mesmo

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para buscar outros medicamentos:";
    cin >> escolha; //Variável que permite o usuário voltar para o menu ou repitir a função executada

    while(escolha != 1 && escolha != 2){ //Impede que outros valores sejam inseridos
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)buscar outros medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2) //Executa a funcão novamente no caso do usuário digitar escolha = "2"
        buscar(nome_arq);
}

void buscar_codigo(string nome_arq){
    ifstream arquivo (nome_arq, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanho_arq(nome_arq); //Informa o tamanho do arquivo

    char codigo_buscado[20]; 
    cout << "Digite o codigo de barras buscado: "; 
    cin >> codigo_buscado; //Código que se deseja busca na base de dados

    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que o código buscado seja encontrado
        arquivo.seekg(cont*sizeof(dados)); //reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if (strcmp(codigo_buscado,procura.codigo_barras)==0) //Faz a comparação entre vetores (char) para verificar a igualdade entre os cógigos de barra 
            posicao = cont; //Define a posição no arquivo do código de barras procurado
        cont++;
    }

    if(posicao == -1) //Se não for encontrado o código de barras desejado
        cout << endl << "Medicamento nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição do código de barras buscado
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao medicamento do código de barras informado
        
        //Exibe as informações do medicamento buscado
        cout << endl << "Descricao: " << procura.descricao << endl; 
        cout << "Codigo de barras: " << procura.codigo_barras << endl;
        cout << "Preco farmacia 1: " << procura.preco1 << endl;
        cout << "Preco farmacia 2: " << procura.preco2 << endl;
        cout << "Status: " << procura.status << endl;
    }
}

void buscar_descricao(string nome_arq){
    ifstream arquivo (nome_arq, ios::in | ios::binary); //Abre o arquivo para leitura binária
    int qtd_dados = tamanho_arq(nome_arq); //Informa o tamanho do arquivo

    char descricao_buscada[200];
    cout << "Digite a descricao buscada: "; 
    cin.ignore();
    cin.getline(descricao_buscada, sizeof(char[200])); //Descrição que se deseja busca na base de dados
    
    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){ //Percorre todo o arquivo até que a descrição buscada seja encontrada
        arquivo.seekg(cont*sizeof(dados)); //reposiciona o ponteiro de leitura a cada leitura
        arquivo.read((char*) &procura, sizeof(dados)); //Lê os dados do arquivo
        if (strcmp(descricao_buscada,procura.descricao)==0) //Faz a comparação entre vetores (char) para verificar a igualdade entre as descrições 
            posicao = cont; //Define a posição no arquivo da descrição procurada
        cont++;
    }

    if(posicao == -1) //Se não for encontrada a descrição desejada
        cout << endl << "Medicamento nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados))); //Posiciona o ponteiro de leitura na posição da descrição procurada
        arquivo.read((char *) &procura, sizeof(dados)); //Lê as informações referentes ao medicamento da descrição informada
        
        //Exibe as informações do medicamento buscado
        cout << endl << "Descricao: " << procura.descricao << endl;
        cout << "Codigo de barras: " << procura.codigo_barras << endl;
        cout << "Preco farmacia 1: " << procura.preco1 << endl;
        cout << "Preco farmacia 2: " << procura.preco2 << endl;
        cout << "Status: " << procura.status << endl;
    }
}

//Inserir-------------------------------------------------------
void inserir(string nome_arq, bool& sheel1, bool& sheel2){  
    ifstream arquivo(nome_arq, ios::in | ios::binary); //Abre o arquivo para leitura binária
     
    int qtd_dados = tamanho_arq(nome_arq); //Informa o tamanho do arquivo

    bool digitou = 0; //V

    while(!digitou){
        char codigo_inserir[20];
        cout << "Digite o codigo de barras que deseja inserir: "; 
        cin >> codigo_inserir;

        int cont = 0, posicao = -1;
        
        dados procura;
        
        while ((cont < qtd_dados) and (posicao ==-1)){
            arquivo.seekg(cont*sizeof(dados));
            arquivo.read((char*) &procura, sizeof(dados));
            if (strcmp(codigo_inserir,procura.codigo_barras)==0)
                posicao = cont;
            cont++;
        }

        if(posicao == -1){
            digitou = 1;
            strcpy(procura.codigo_barras,codigo_inserir);
            cout << endl << "Informe a descricao: ";
            cin.ignore();
            cin.getline(procura.descricao,sizeof(char[200]));
            cout << endl << "Informe o preco na farmacia 1: ";
            cin >> procura.preco1;
            cout << endl << "Informe o preco na farmacia 2: ";
            cin >> procura.preco2;
            cout << endl << "Informe o status - Positiva ou Negativa: "; 
            cin >> procura.status;
            escreve_final(nome_arq,procura);
            cout << endl << "Medicamento registrado com sucesso!";

            if(sheel1)
                shell_sort_preco1(nome_arq);
            else if(sheel2)
                shell_sort_preco2(nome_arq);
                
        }
        else
            cout << endl << "Medicamento ja esta no sistema, tente novamente!" << endl << endl;
    }

    int escolha;
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para inserir outro medicamento:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)inserir outro medicamento" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        inserir(nome_arq,sheel1,sheel2);
}


void excluir1(string nome_arq){
    fstream arquivo(nome_arq);

    int tamanho = tamanho_arq(nome_arq), escolha, cont = 0, posicao = -1;
    dados procura;

    char codigo_buscado[20];
    cout << "Digite o codigo de barras que deseja excluir: "; 
    cin >> codigo_buscado;

    
    while ((cont < tamanho+1) and (posicao ==-1)){
        arquivo.seekg(cont*sizeof(dados));
        arquivo.read((char*) &procura, sizeof(dados));
        if (strcmp(codigo_buscado,procura.codigo_barras)==0)
            posicao = cont;
        cont++;
    }

    if (posicao !=-1){ //Verifica se o elemento está no arquivo
        for (int i=posicao+1; i<tamanho; i++){
        arquivo.seekp(i*sizeof(dados));
        arquivo.read((char*) &procura, sizeof(dados));
        arquivo.seekp((i-1)*sizeof(dados));
        arquivo.write((char*) &procura, sizeof(dados));
        }
    }else
        cout << endl << "Codigo de barras nao encontrado!";
    
    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para excluir outros medicamentos:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)excluir outros medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        excluir1(nome_arq);
}
