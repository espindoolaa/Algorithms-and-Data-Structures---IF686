#include <iostream>
#include <sstream>

struct Peca {
    int cor;
    Peca* cima;
    Peca* baixo;
};

struct Coluna {
    int numero;
    Coluna* anterior;
    Coluna* proximo; 
    Peca* topo;
};

void removePiece(){

}

void pushBack(Coluna** head, int coluna, int cor){
    Coluna* new_node = new Coluna{coluna, nullptr, nullptr, nullptr};
    
    if (*head = nullptr){
        *head = new_node;
        return;
    } 

    
    *tail = new_node;
}



void freeMemory(Coluna** head){


}

int main (){
    int casos;
    Coluna* head = nullptr;
    
    
    std::cin >> casos;
    while (casos--){
        

        std::string linha;
        while(getline(std::cin, linha)){
            if (linha == "END"){
                break;
            }

            std::istringstream iss(linha);
            int coluna, cor; 
            
            // recepção dos valores em cada uma das variáveis 
            iss >> coluna >> cor;
            
            // funções a serem executadas
            pushBack(&head, cor);
            freeMemory(&head);

        }




    }



    return 0;
}
