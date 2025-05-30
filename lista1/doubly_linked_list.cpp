// code base construct for doubly linked resolutions
#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* prev;
    Node* next;
};

void pushFront(Node** head){
    int valor;
    cout << "Digite o valor do nó: " << endl;  cin >> valor;
    Node* new_node = new Node{valor, nullptr, *head};

    if (*head != nullptr){
        (*head)->prev = new_node;
    }

    *head = new_node;

};

void pushBack(Node** head){
    int valor;
    cout << "Digite o valor do nó: " << endl;  cin >> valor;

    Node* new_node = new Node{valor, nullptr, nullptr};

    if (*head == nullptr){
        *head = new_node;
    } else{
        Node* atual = *head;
        
        while (atual->next != nullptr){
            atual = atual->next;
        }
        
        atual->next = new_node;
        new_node->prev = atual;
    }

}

void printListDirect(Node* head){
    cout << "Lista: ";
    while (head != nullptr){
        cout << head->valor << " <-> ";
        head = head->next;
    }

    cout << "null" << endl;
}

void printListReverse(Node* head){
    cout << "Lista: ";

    if (head == nullptr) return;

    while (head->next != nullptr){
        head = head->next;
    }

    while (head != nullptr){
        cout << head->valor << " <-> ";
        head = head->prev;

    }

    cout << "null" << endl;
}

void removeValue(Node** head){
    cout << "Insira valor do nó a ser removido: "; 
    int valor; 
    cin >> valor;

    Node* atual = *head;

    while (atual != nullptr){
        if (atual->valor == valor){
            if (atual->prev != nullptr){
                atual->prev->next = atual->next;
            } else{
                *head = atual->next;
            }

            if (atual->next != nullptr){
                atual->next->prev = atual->prev;
            }

            delete atual;   
            cout << "Valor: " << valor << " removido!" << endl;
            return;
        }

        atual = atual->next;
    }

    cout << "O valor não foi encontrado para ser removido" << endl;
}

void insertInIndex(Node** head){
    int valor, pos; 
    cout << "Insira valor do nó a ser inserido: "; 
    cin >> valor;
    cout << "Agora insira a posição que deseja inserir: "; 
    cin >> pos;

    if ((pos <= 0) || (*head == nullptr)){
        pushFront(head);
        return;
    }

    Node* atual = *head;
    int index = 0;

    while (atual->next != nullptr && index < pos - 1){
        atual = atual->next;
        index++;
    }

    Node* new_node = new Node{valor, atual,atual->next};

    if (atual->next != nullptr){
        atual->next->prev = new_node;
    }

    atual->next = new_node;
}

void freeMemory(Node** head){
    Node* atual = *head;

    while (atual != nullptr){
        Node* proximo = atual->next;
        delete atual;
        atual = proximo;
    }

    *head = nullptr;
    cout << "Memória da lista encadeada liberada!" << endl;
}

int main(){
    
    Node* head = nullptr;
    int opcao;
    bool run = true;
    while(run){
        cout << "\n1 - Inserir no início\n2 - Inserir no fim\n3 - Remover nó\n4 - Inserir nó numa posição\n5 - Mostrar direta\n6 - Mostrar reversa\n7 - Sair\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: pushFront(&head); break;
            case 2: pushBack(&head); break;
            case 3: removeValue(&head); break;
            case 4: insertInIndex(&head); break;
            case 5: printListDirect(head); break;
            case 6: printListReverse(head); break;
            case 7: freeMemory(&head); run = false; break;
        }

    }
    return 0;
}
