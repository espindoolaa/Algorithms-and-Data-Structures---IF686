#include <stdio.h>

int main () {

    char expression[1001] = {};
    scanf("%s", expression);
    int verified = 0, wellConstructExpression = 1, run = 1;
    int value = 1;

    // here i know that's possible to use string.h library. therefore, different from the previous question, i will use this function to resolve the problem easily.
    for (int i = 0; i < strlen(expression) && run == 1; i++){
        for (int j = value; j < strlen(expression) && run == 1; j++){
            if (expression[i] == '{'){
                // verifying if the pair exists
                if (!verified){
                    if (expression[j] == '}'){
                        verified = 1;
                        value = j;
                    }
                }

                else {
                    if ((j == strlen(expression) - 1) && (verified == 0)){
                        // the expression isn't well constructed
                        wellConstructExpression = 0;
                        run = 0;
                    }
 
                }
            }
        }
    }

    if (wellConstructExpression){
        printf("S");
    }
    
    else {
        printf("N");
    }

    return 0;
}