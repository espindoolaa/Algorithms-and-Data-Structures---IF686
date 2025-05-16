#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main () {

    string expression;
    stack<char> pilha; 
    getline(cin, expression); // using this method because has the possibility of exists spaces in the string recieved
    int wellConstructExpression = 1, run = 1;

    for (int i = 0; i < expression.length() && run == 1; i++){
        if (expression[i] == '{'){
            pilha.push('{');
        } 

        else if (expression[i] != ' '){
            if (!pilha.empty()){
                pilha.pop();
            } 

            else {
                wellConstructExpression = 0;
                run = 0;
            }
        }
    }

    if (wellConstructExpression){
        printf("S\n");
    }
    
    else {
        printf("N\n");
    }

    return 0;
}