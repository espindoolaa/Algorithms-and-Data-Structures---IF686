#include <stdio.h>

int main () {

    // initializing variables and counters
    char list[1000] = {};
    char answer[1000] = {};
    int max_count = 0, current_count, list_counting = 0; 
    int flag, permute;
    
    while (scanf("%s", list) != EOF){

        // counting the list 
        while (list[list_counting] != '\0'){
            list_counting++; 
        }
        
        // defining the max list in each input (updates or not?)
        flag = 1;
        current_count = 0;
        permute = 0; 
        for (int i = 0; i < list_counting && flag == 1; i++){
            if ((i == 1) && (list[i] != ' ')){
                current_count += 1;
            } 
            
            else if (list[i] == ','){
                current_count += 1;
            }
            
            else if (list[i] == ']'){
                flag = 0; 

                if (max_count < current_count){
                    max_count = current_count;
                    
                    // way that i found to transform the answer array without string.h functions
                    while (list[permute] != '\0'){
                        answer[permute] = list[permute];
                        permute++; 
                    }
                }
            }
        }
    }

    // print function returns the right string
    printf("%s\n", answer);
    return 0;
}