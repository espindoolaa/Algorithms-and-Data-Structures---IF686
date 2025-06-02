#include <iostream>

struct Node {
    int packages;
    Node* prev;
    Node* next;
};

// function thats pushes back a new node
void pushBack(Node** head, Node** tail, int packages){
    Node* new_node = new Node{packages, *tail, nullptr};
    // if the head hasn't value
    if (*head == nullptr){
        *head = new_node;
    } else {          
        // new node is pushed to the back of the stack 
        (*tail)->next = new_node;   
    }

    *tail = new_node;
}

// function thats removes back a new node
void removeBack(Node** head, Node** tail){
    Node* toDel = *tail;
    *tail = (*tail)->prev;
    if(*tail != nullptr){
        (*tail)->next = nullptr;
    } else {
        // stack is empty
        *head = nullptr;
    }

    delete toDel;
}

// finds the difference between the packages of two nodes
int myAbs(int a, int b){
    int result;
    if (a - b < 0){
        result = (a - b) * (-1);
    } else {
        result = a - b;
    }

    return result;
}

// analyses the parity between the last node and previous of the last node (recursive)
void analyseParity(Node** head, Node** tail){
    // first check
    if (*tail == nullptr || (*tail)->prev == nullptr) return;

    // last element of the list
    Node* last = *tail; 

    // then analyse the parity between the last two values while exists this condition
    while (last != nullptr && last->prev != nullptr && (last->packages % 2 == last->prev->packages % 2)){ 
        int diff = myAbs(last->packages, last->prev->packages); // assumes his new value

        Node* prevNode = last->prev; // auxiliar node to carry the previous
        removeBack(head, tail); // this function updates the tail

        if (diff == 0){
            removeBack(head, tail); 
            last = *tail;
        } else {
            prevNode->packages = diff;
            last = prevNode;
        }
        
    }
}

// print number of elements and top of stack
void printElementsAndTop(Node** head, int n_stack){
    int elements = 0;

    if (*head == nullptr){
        std::cout << "Pilha " << n_stack << ": 0 -1\n"; 
        return;
    }


    Node* atual = *head;
    Node* last = nullptr;

    while(atual != nullptr){
        // always updates the last node until reaches the end of the doubly-linked-list
        last = atual;
        atual = atual->next;
        elements++;
    }

    std::cout << "Pilha " << n_stack << ": " << elements << " " << last->packages << "\n"; 
}

// free the memory alocated
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
        Node* tail = nullptr; // pointer thats points to the last element of the list 
        n_stack++;

        while (std::cin >> packages && packages != 0){          
            pushBack(&head, &tail, packages);
            analyseParity(&head, &tail);
        }

        printElementsAndTop(&head, n_stack);
        freeStack(&head);  
    }

    return 0;
}
