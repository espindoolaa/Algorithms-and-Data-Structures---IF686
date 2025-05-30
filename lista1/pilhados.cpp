#include <iostream>
/* abordagem definida é ineficiente, porque implementa uma lista duplamente ligada em vez de sempre começar pelo topo. (pior caso sempre será O(n))
*/ 
struct Node {
    int packages;
    Node* prev;
    Node* next;
};

void pushBack(Node** head, int packages){
    // if the head hasn't value
    if (*head == nullptr){
        Node* new_node = new Node{packages, nullptr, nullptr};
        *head = new_node;
    } 

    // there are a head
    else {  
        // found the last element of the list 
        Node* atual = *head;
        while (atual->next != nullptr){
            atual = atual->next;
        }
        
        // new node is pushed to the back of the stack 
        Node* new_node = new Node{packages, atual, nullptr};
        atual->next = new_node;
    }


}

void removeBack(Node** last){
    Node* toDel = *last;
    *last = (*last)->prev;
    if(*last != nullptr){
        (*last)->next = nullptr;
    }
    delete toDel;
}

int myAbs(int a, int b){
    int result;
    if (a - b < 0){
        result = (a - b) * (-1);
    } else {
        result = a - b;
    }

    return result;
}

void analyseParity(Node** head){
    // found the last element of the list
    Node* last = *head; // auxiliar node created
    while (last->next != nullptr){
        last = last->next;
    }

    // then analyse the parity between the last two values while exists this condition;
    while ((last->prev != nullptr) && ((last->packages % 2) == (last->prev->packages % 2))){ 
        last->prev->packages = myAbs(last->packages, last->prev->packages); // assumes his new value

        // now, it's necessary to the delet the last node, that won't exist anymore
        removeBack(&last);
    }
}


void printElementsAndTop(Node** head, int n_stack){
    int elements = 0, top_value = -1;
    Node* atual = *head;

    while(atual->next != nullptr){
        top_value = atual->packages;
        atual = atual->next;
        elements++;
    }


    std::cout << "Pilha " << n_stack << ": " << elements << " " << top_value << "\n"; 
}

void freeStack(Node** head){
    Node* atual = *head;

    while (atual != nullptr){
        Node* proximo = atual->next;
        delete atual;
        atual = proximo;
    }

    *head = nullptr;
}

int main(){
    int cases, packages, n_stack = 0;
    std::cin >> cases;

    while (cases--){
        Node* head = nullptr;
        n_stack++;
        bool run = true;

        while (run){          
            std::cin >> packages;
            if (packages != 0){
                pushBack(&head, packages);
                analyseParity(&head);

            } else {
                printElementsAndTop(&head, n_stack);
                freeStack(&head);
                run = false;
            }
        }
    }

    return 0;
}
