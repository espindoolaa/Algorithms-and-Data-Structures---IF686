#include <stdio.h>

int main () {

    char list[1000];
    char answer[1000];
    int max_count = 0, current_count = 0, flag = 1; 

    while (scanf("%s", list) != EOF) {
        for (int i = 0; i < strlen(list) && flag == 1; i++){
            if ((i == 1) && ((strcmp(list[i]), " ") == 0)){
                current_count += 1;
            } 
            
            else if (strcmp(list[i], ",") == 0){
                current_count += 1;
            }
            
            else if (strcmp(list[i], "]") == 0){
                flag = 0; 

                if (max_count < current_count){
                    max_count = current_count;
                    // need to atualize the current max list 
                    strcpy(answer, list);
                }
            }
        }
    }

    return 0;
}