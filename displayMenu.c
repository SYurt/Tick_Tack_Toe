#include <stdio.h>
#include "displayMenu.h"

//to test
int displayMenu(char** menuItems, int len){

    int answer;
    printf ("%s", "\nEnter your choice\n\n");

    for (int i = 0; i < len; i++){

        printf ("%d - %s\n", i, menuItems[i]);
    }
    scanf("%d",&answer);

    return answer;
}

//to test
void displayLogo(){
    printf("I am logo\n");
}
