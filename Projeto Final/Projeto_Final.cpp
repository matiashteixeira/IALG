#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std; 

struct dados{
    float preco1, preco2;
    char codigo_barras[20];
    char descricao[200];
    char status[10];
};

//Importa-------------------------------------------------------
void importarcsv(string entrada, string saida);
string le_celula(ifstream &arquivo);
//Ordena--------------------------------------------------------
void ordenar(string nome_arq, bool& shell1, bool& shell2);
void shell_sort_preco1(string nome_arq);
void shell_sort_preco2(string nome_arq);
//Imprime-------------------------------------------------------
void imprimir(string nome_arq);
//Busca---------------------------------------------------------
void buscar(string nome_arq);
void buscar_codigo(string nome_arq);
void buscar_descricao(string nome_arq);
//Exclui--------------------------------------------------------
void excluir(string nome_arq);
//Insere--------------------------------------------------------
void inserir(string nome_arq, bool& sheel1, bool& sheel2);
//Auxiliares----------------------------------------------------
void menu();
void clear_terminal();
int tamanho_arq(string nome_arq);
void apaga_escreve(string nome_arq, int tamanho, dados* vet);
void escreve_final(string nome_arq, dados procura);

int main(){
    int opcao;
    bool shell1 = 0, shell2 = 0;
    string arquivo_csv = "base10K.csv";
    string arquivo_bin = "arqvsaida.bin";
    importarcsv(arquivo_csv, arquivo_bin);
    
    menu();
    cin >> opcao;
    clear_terminal();

    while(opcao != 7){
        switch (opcao){
        case 1:
            inserir(arquivo_bin, shell1, shell2);
            break;

        case 2:
            excluir(arquivo_bin);
            break;

        case 3:
            ordenar(arquivo_bin,shell1,shell2);
            break;

        case 4:
            inserir(arquivo_bin,shell1,shell2);
            break;

        case 5:
            imprimir(arquivo_bin);
            break;

        case 6:
            buscar(arquivo_bin);
            break;
        
        default:
            cout << "Opcao invalida, tente novamente!" << endl;
            break;
        }
        menu();
        cin >> opcao;
        clear_terminal();
    }
    cout << endl << endl << "---------------------Obrigado por usar nosso programa!---------------------" << endl << endl;
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
    cout << "(4) Alterar - Altera algum campo de um registro" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(5) Imprimir - Exibe as informacoes dos arquivos desejados na tela" << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "(6) Buscar - Busca os dados de um medicamento existente a partir de um filtro" << endl;
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
    ofstream arquivo(nome_arq,ios::binary | ios::out | ios::trunc);
    for(int k = 0; k < tamanho; k++)
        arquivo.write((const char *) &vet[k], sizeof(dados));
        
    arquivo.close();
}

void escreve_final(string nome_arq, dados procura){
    ofstream arquivo(nome_arq,ios::binary | ios::app | ios::ate);
    arquivo.write((const char *) &procura, sizeof(dados));
    arquivo.close();
}

int tamanho_arq(string nome_arq){
    ifstream arquivo(nome_arq, ios::ate);
    long int tamanho_arquivo = arquivo.tellg();
    int qtd_dados = int (tamanho_arquivo/sizeof(dados));
    arquivo.close();

    return qtd_dados;
}

//Importa--------------------------------------------------------
void importarcsv(string entrada, string saida){
    ifstream arquivo(entrada.c_str());
    dados base10;
    ofstream arqvsaida(saida.c_str(), ios::binary);
    while (!arquivo.eof()) // Lê o arquivo até o final do mesmo
    {
        string descricao = le_celula(arquivo);
        strcpy(base10.descricao, descricao.c_str());

        string codigo_barras = le_celula(arquivo);
        strcpy(base10.codigo_barras, codigo_barras.c_str());
    
        string preco1 = le_celula(arquivo); 
        int posicao1 = preco1.find(',');
        if (posicao1 < preco1.length())
            preco1.replace(preco1.find(','), 1, ".");
        base10.preco1 = stof(preco1);

        string preco2 = le_celula(arquivo); 
        int posicao2 = preco2.find(',');
        if (posicao2 < preco2.length())
            preco2.replace(preco2.find(','), 1, ".");
        base10.preco2 = stof(preco2);
        
        string status = le_celula(arquivo);
        strcpy(base10.status, status.c_str());
        
        arqvsaida.write((const char *)&base10, sizeof(dados)); // Convertendo para arquivo binário
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

//Imprime--------------------------------------------------------
void imprimir(string nome_arq){

    int tamanho = tamanho_arq(nome_arq);

    dados med;
    int escolha, inicio, fim, cont = 0;
    ifstream arquivo;
    arquivo.open(nome_arq, ios_base::binary | ios_base::in);

    cout << "Deseja imprimir o arquivo todo na tela?" << endl;
    cout << "(1)sim ou (2)nao" << endl;
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)sim ou (2)nao" << endl;
        cin >> escolha;
    }
     
    if(escolha == 1){
        while(arquivo.read((char*) &med, sizeof(dados))){
        cout << med.descricao << " " << med.codigo_barras << " " << med.preco1 << " "; 
        cout << med.preco2 << " " << med.status << endl;
        }
    }else if(escolha == 2){
        cout << "O vetor tem " << tamanho << " medicamentos" << endl << endl;
        cout << "Deseja imprimir a partir de qual medicamento? " << endl;
        cin >> inicio;
        cout << "Deseja imprimir ate qual medicamento? " << endl;
        cin >> fim;

        while(fim < inicio or fim > tamanho){
            cout << "Nao e permitido imprimir ate esse medicamento!" << endl;
            cout << "OBS: Verifique o valor digitado e a quantidade de dados do arquivo" << endl << endl;
            cout << "Digite novamente ate qual medicamento deseja imprimir: ";
            cin >> fim;
        }
        clear_terminal();

        arquivo.seekg((inicio-1)*sizeof(dados));
        while(arquivo.read((char*) &med, sizeof(dados)) && fim-inicio >= cont){
            cout << med.descricao << " " << med.codigo_barras << " " << med.preco1 << " "; 
            cout << med.preco2 << " " << med.status << endl;
            cont++;
        }
    }
    arquivo.close();

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para imprimir outros medicamentos:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)imprimir outros medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        imprimir(nome_arq);
}

//Ordena---------------------------------------------------------
void ordenar(string nome_arq, bool& shell1, bool& shell2){
    int escolha;
    cout << "Deseja ordenar os medicamentos pelo preco crescente de venda da farmacia 1 ou da farmacia 2?" <<   endl;
    cout << "(1)Farmacia 1" << endl;
    cout << "(2)Farmacia 2" << endl;
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)Preco de venda ou (2)Codigo de barras" << endl;
        cin >> escolha;
    }
    
    if(escolha == 1){
        shell_sort_preco1(nome_arq);
        shell1 = 1;
    }
    else{
        shell_sort_preco2(nome_arq);
        shell2 = 1;
    }
    
    cout << endl << "Medicamentos ordenados com sucesso!";

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para ordenar novamente os medicamentos:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)ordenar novamente os medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        ordenar(nome_arq,shell1,shell2);
}

void shell_sort_preco1(string nome_arq){
    ifstream arquivo(nome_arq,ios::binary | ios::in);

    int tamanho = tamanho_arq(nome_arq);

    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++)
        arquivo.read((char*)&vet[i], sizeof(dados));
    
    
    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    while (gaps[pos_gap] > tamanho) {
        pos_gap--;
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];

        for (int k = gap; k < tamanho; k++) {
            valor = vet[k];
            j = k;
            while ((j >= gap) and (valor.preco1 < vet[j - gap].preco1)) {
                vet[j] = vet[j - gap];
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--;
    }
    arquivo.close();
    
    apaga_escreve(nome_arq,tamanho,vet);
    delete[] vet;
}

void shell_sort_preco2(string nome_arq){
    ifstream arquivo(nome_arq,ios::binary | ios::in);

    int tamanho = tamanho_arq(nome_arq);

    dados* vet;
    vet = new dados[tamanho];

    for (int i = 0; i < tamanho; i++)
        arquivo.read((char*)&vet[i], sizeof(dados));

    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    while (gaps[pos_gap] > tamanho) {
        pos_gap--;
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];

        for (int k = gap; k < tamanho; k++) {
            valor = vet[k];
            j = k;
            while ((j >= gap) and (valor.preco2 < vet[j - gap].preco2)) {
                vet[j] = vet[j - gap];
                j = j - gap;
            }
            vet[j] = valor;
        }
        pos_gap--;
    }
    arquivo.close();

    apaga_escreve(nome_arq,tamanho,vet);
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
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)Codigo de barras ou (2)Descricao" << endl;
        cin >> escolha;
    }
    
    if(escolha == 1)
        buscar_codigo(nome_arq);
    else
        buscar_descricao(nome_arq);

    cout << endl << endl <<"Digite (1) para voltar ao menu ou (2) para buscar outros medicamentos:";
    cin >> escolha;

    while(escolha != 1 && escolha != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)menu ou (2)buscar outros medicamentos" << endl;
        cin >> escolha;
    }
    clear_terminal();
    if(escolha == 2)
        buscar(nome_arq);
}

void buscar_codigo(string nome_arq){
    ifstream arquivo (nome_arq, ios::in | ios::binary);
    int qtd_dados = tamanho_arq(nome_arq);

    char codigo_buscado[20];
    cout << "Digite o codigo de barras buscado: "; 
    cin >> codigo_buscado;

    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){
        arquivo.seekg(cont*sizeof(dados));
        arquivo.read((char*) &procura, sizeof(dados));
        if (strcmp(codigo_buscado,procura.codigo_barras)==0)
            posicao = cont;
        cont++;
    }

    if(posicao == -1)
        cout << endl << "Medicamento nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados)));
        arquivo.read((char *) &procura, sizeof(dados));
        
        cout << endl << "Descricao: " << procura.descricao << endl;
        cout << "Codigo de barras: " << procura.codigo_barras << endl;
        cout << "Preco farmacia 1: " << procura.preco1 << endl;
        cout << "Preco farmacia 2: " << procura.preco2 << endl;
        cout << "Status: " << procura.status << endl;
    }
}

void buscar_descricao(string nome_arq){
    ifstream arquivo (nome_arq, ios::in | ios::binary);
    int qtd_dados = tamanho_arq(nome_arq);

    char descricao_buscada[200];
    cout << "Digite a descricao buscada: "; 
    cin.ignore();
    cin.getline(descricao_buscada, sizeof(char[200]));
    
    int cont = 0, posicao = -1;
    dados procura;
    
    while ((cont < qtd_dados) and (posicao ==-1)){
        arquivo.seekg(cont*sizeof(dados));
        arquivo.read((char*) &procura, sizeof(dados));
        if (strcmp(descricao_buscada,procura.descricao)==0)
            posicao = cont;
        cont++;
    }

    if(posicao == -1)
        cout << endl << "Medicamento nao encontrado!";
    else{
        arquivo.seekg((posicao*sizeof(dados)));
        arquivo.read((char *) &procura, sizeof(dados));
        
        cout << endl << "Descricao: " << procura.descricao << endl;
        cout << "Codigo de barras: " << procura.codigo_barras << endl;
        cout << "Preco farmacia 1: " << procura.preco1 << endl;
        cout << "Preco farmacia 2: " << procura.preco2 << endl;
        cout << "Status: " << procura.status << endl;
    }
}

//Inserir-------------------------------------------------------
void inserir(string nome_arq, bool& sheel1, bool& sheel2){
    ifstream arquivo(nome_arq, ios::in | ios::binary);
    int escolha, qtd_dados = tamanho_arq(nome_arq);

    bool digitou = 0;

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
        else{
            cout << endl << "Medicamento ja esta no sistema, tente novamente!" << endl;
            clear_terminal();
        }
    }

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

