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

void importarcsv(string entrada, string saida, int& tamanho);
string le_celula(ifstream &arquivo);
void imprimir(int tamanho, string nome_arq);
void shell_sort_preco1(dados* vet, int tamanho, string nome_arq);
void shell_sort_preco2(dados* vet,int tamanho,string nome_arq);
void ordena_arquivo(string nome_arq, int tamanho, dados* vet);

int main(){
    int tamanho = 0;
    string arquivo_csv = "base10K.csv";
    string arquivo_bin = "arqvsaida.bin";
    importarcsv(arquivo_csv, arquivo_bin, tamanho);
    dados* vet;
    vet = new dados[tamanho];
    

//Menu do sistema--------------------------------------------------------
    cout << "Arquivo de dados da farmacia" << endl << endl;
    cout << " ****MENU**** " << endl << endl;
    cout << "Escolha uma das opcoes: " << endl;
    cout << "(1)Inserir - Insere dados referentes a um ou mais medicamentos" << endl;
    cout << "(2)Excluir - Exclui algum medicamento" << endl;
    cout << "(3)Ordenar - Ordena os medicamentos existentes no arquivo" << endl;
    cout << "(4)Alterar - Altera algum campo de um registro" << endl;
    cout << "(5)Imprimir - Exibe as informacoes dos arquivos desejados na tela" << endl;
    cout << "(6)Buscar - Busca os dados de um medicamento existente a partir de um filtro" << endl;
    cout << "(7)Sair - Encerra o programa" << endl;

    int opcao;
    cout << endl;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;

    while(opcao != 7){
    
        if(opcao == 5)
            imprimir(tamanho,arquivo_bin);
    
        else if(opcao == 3){
            int escolha;
            cout << endl << endl;
            cout << "Deseja ordenar os medicamentos pelo preco crescente de venda da farmacia 1 ou da farmacia 2?" <<   endl;
            cout << "(1)Farmacia 1" << endl;
            cout << "(2)Farmacia 2" << endl;
            cin >> escolha;

            while(escolha != 1 && escolha != 2){
                cout << "Opcao nao disponivel, digite novamente: " << endl;
                cout << "(1)Preco de venda ou (2)Codigo de barras" << endl;
                cin >> escolha;
            }
            if(escolha == 1)
                shell_sort_preco1(vet,tamanho,arquivo_bin);
            else if(escolha == 2)
                shell_sort_preco2(vet,tamanho,arquivo_bin);
        }
        
        else if(opcao == 8){
            for (int i = 0; i < tamanho; i++)
                cout << vet[i].preco2 << endl; 
        }
    
        

    cout << endl << "Digite uma nova opcao: " << endl;
    cin >> opcao;
    }

    return 0;
}


void importarcsv(string entrada, string saida, int& tamanho){
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
        tamanho++;
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

void imprimir(int tamanho, string nome_arq){
    dados med;
    int sim_nao, inicio, fim, cont = 0;
    ifstream arquivo;
    arquivo.open(nome_arq, ios_base::binary | ios_base::in);

    cout << "Deseja imprimir o arquivo todo na tela?" << endl;
    cout << "(1)sim ou (2)nao" << endl;
    cin >> sim_nao;

    while(sim_nao != 1 && sim_nao != 2){
        cout << "Opcao nao disponivel, digite novamente: " << endl;
        cout << "(1)sim ou (2)nao" << endl;
        cin >> sim_nao;
    }
     
    if(sim_nao == 1){
        while(arquivo.read((char*) &med, sizeof(dados))){
        cout << med.descricao << " " << med.codigo_barras << " " << med.preco1 << " "; 
        cout << med.preco2 << " " << med.status << endl;
        }
    }else if(sim_nao == 2){
        cout << "O vetor tem " << tamanho << " medicamentos" << endl << endl;
        cout << "Deseja imprimir a partir de qual medicamento? " << endl;
        cin >> inicio;
        cout << "Deseja imprimir ate qual medicamento? " << endl;
        cin >> fim;

        arquivo.seekg((inicio-1)*sizeof(dados));
        while(arquivo.read((char*) &med, sizeof(dados)) && fim-inicio >= cont){
            cout << med.descricao << " " << med.codigo_barras << " " << med.preco1 << " "; 
            cout << med.preco2 << " " << med.status << endl;
            cont++;
        }
    }
    arquivo.close();
}
/*
void inserir(int& tamanho){
    ofstream arquivo;
    arquivo.open("arqvsaida.bin", ios_base::binary | ios_base::out | ios_base::ate);
    
    dados add;
    int qtd;
    cout << "Informe a quantidade de medicamentos que voce deseja inserir: ";
    cin >> qtd;
    cout << "Os precos devem ser diferentes para cada medicamento" <<endl;

    for (int i = 0; i < qtd; i++){
        cout << endl;
        cout << "Informe o preço: ";
        cin >> add.preco;
        while (existe(add.preco, vetor, tamanho))
        {
            cout << "O preço informado já existe, insira outro: ";
            cin >> add.preco;
        }
        cout << "Informe o código de barras do medicamento: ";
        cin.ignore();
        cin.getline(add.codigo_barras, tamanho);
        cout << "Informe a descrição do medicamento: ";
        cin >> add.descricao;
        cout << "Informe o status do medicamento: ";
        cin.ignore();
        cin.getline(add.status, tamanho);
        cout << "Informe a tarja do medicamento: ";
        cin.getline(add.tarja, tamanho);
        cout << endl;
        cout << "Registro do novo medicamento concluído com Sucesso" << endl;
        tamanho++;
        arquivo.write((char*)&add, sizeof(dados)*qtd);
    }
    
}
*/

void shell_sort_preco1(dados* vet, int tamanho, string nome_arq){
    ifstream arquivo;
    arquivo.open(nome_arq,ios::binary | ios::in);

    int i = 0;

    while(!arquivo.eof()){
        arquivo.read((char*)&vet[i], sizeof(dados));
        i++;
    }

    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    while (gaps[pos_gap] > tamanho) {
        pos_gap--;
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];

        for (int i = gap; i < tamanho; i++) {
            valor.preco1 = vet[i].preco1;
            j = i;
            while ((j >= gap) and (valor.preco1 < vet[j - gap].preco1)) {
                vet[j] = vet[j - gap];
                j = j - gap;
            }
            vet[j].preco1 = valor.preco1;
        }
        pos_gap--;
    }
    arquivo.close();

    ordena_arquivo(nome_arq,tamanho,vet);
}

void shell_sort_preco2(dados* vet,int tamanho,string nome_arq){
    fstream arquivo;
    arquivo.open(nome_arq,ios::binary | ios::in);

    int i = 0;

    while(!arquivo.eof()){
        arquivo.read((char*)&vet[i], sizeof(dados));
        i++;
    }

    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    while (gaps[pos_gap] > tamanho) {
        pos_gap--;
    }    
    dados valor;
    int j;
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];

        for (int i = gap; i < tamanho; i++) {
            valor.preco2 = vet[i].preco2;
            j = i;
            while ((j >= gap) and (valor.preco2 < vet[j - gap].preco2)) {
                vet[j] = vet[j - gap];
                j = j - gap;
            }
            vet[j].preco2 = valor.preco2;
        }
        pos_gap--;
    }
    arquivo.close();

    ordena_arquivo(nome_arq,tamanho,vet);
}

void ordena_arquivo(string nome_arq, int tamanho, dados* vet){
    ofstream arquivo(nome_arq,ios::binary | ios::out | ios::trunc);
    for(int k = 0; k < tamanho; k++)
    
        arquivo.write((const char *) &vet[k], sizeof(dados));
    
    arquivo.close();
}