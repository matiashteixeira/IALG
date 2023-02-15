/*
void inserir(int& tamanho, string nome_arq){
    ofstream arquivo;
    arquivo.open(nome_arq, ios_base::binary | ios_base::out | ios_base::ate);
    
    dados add;
    int qtd;

    cout << "Informe a quantidade de medicamentos que voce deseja inserir: ";
    cin >> qtd;
    
}
*/


void excluir(int tamanho, dados* vet){
    int qtd;
    //bool existe = 0, sair = 0;
    char codigo[2];
    cout << "Informe a quantidade de medicamentos que voce deseja excluir: ";
    cin >> qtd;

    for (int i = 0; i < qtd; i++){
        cout << "Informe o codigo de barras do elemento que deseja excluir: ";
        cin >> codigo;

        //while(!existe && !sair){
            for (int i = 0; i < tamanho; i++){
                           
                if(strcmp(vet[i].codigo_barras, codigo) == 0){
                    cout << "oi";
                    existe = 1;
                    tamanho--;
                }
                //    existe = 0;
            }
            //if(!existe){
            //    cout << endl << "Codigo de barras nao encontrado" << endl;
            //    cout << "Digite (1) para sair do modo exclusao ou (0) para digitar um outro codigo de barras: " << endl;
            //    cin >> sair; 
            //}
            //cout << "Informe o codigo de barras do elemento que deseja excluir:";
            //cin >> medicamento;
        //}
    }
}

void excluir(int tamanho, dados* vet){
    int qtd;
    //bool existe = 0, sair = 0;
    char codigo[20];
    cout << "Informe a quantidade de medicamentos que voce deseja excluir: ";
    cin >> qtd;

    for (int i = 0; i < qtd; i++){
        cout << "Informe o codigo de barras do elemento que deseja excluir: ";
        cin >> codigo;

        cout << strcmp(vet[i].codigo_barras, codigo);
            for (int i = 0; i < tamanho; i++){
                           
                if(strcmp(vet[i].codigo_barras, codigo) == 0){
                    cout << "oi";
                    //existe = 1;
                    tamanho--;
                }
            }
    }
}