#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getText();
int options();
void option1(char *user_text, int length);
void option2(char *text, int length);
void option3(char *text, int length);

int main(int argc, char **argv){
    char *user_text = getText();

    int option = options();
    int length = strlen(user_text);

    if(option == 1){
        option1(user_text, length);
    }else if(option == 2){
        option2(user_text, length);
    }else{
        option3(user_text, length);
    }

    return 0;
}

//prompt and store the text to be encrypted.
char* getText(){
    printf("Please enter the text you want to be encrypted: ");

    char *text = malloc(256 * sizeof(char));
    fgets(text, 256, stdin);
    printf("\n");

    return text;
}

//print out the options and record user choice.
int options(){
    printf("We provide 3 encrypting method, choose one by entering the number.\n");
    printf("(1) Rotate the characters by the specified key.\n");
    printf("(2) Transform the characters into hexadecimal number.\n");
    printf("(3) Reverse Alphabet Cipher.\n");
    printf("Your choice is: ");

    int option;
    scanf("%d", &option);
    printf("\n");

    return option;
}

//Caesar Cipher
void option1(char *text, int length){
    printf("Please enter the key(between 1 - 25): ");
    int key;
    scanf("%d", &key);
    printf("\n");

    char *newText = malloc(256 * sizeof(char));//store the text after being rotated.

    for(int i = 0; i < length; i++){
        char temp = text[i];
        if(temp >= 'A' && temp <= 'Z'){//handle uppercase
            newText[i] = 'A' + (temp - 'A' + key) % 26;
        }else if(temp >= 'a' && temp <= 'z'){//handle lowercase
            newText[i] = 'a' + (temp - 'a' + key) % 26;
        }else{
            newText[i] = text[i];
        }
    }
 
        printf("The encrypted text is: ");
        for(int i = 0; i < length; i++){
            printf("%c", newText[i]);
        }
        printf("\n");

}

//hexadecimal cipher
void option2(char *text, int length){
    printf("For this option, we will reprensent each character in its hexadecimal value separated by white space.\n");
    
    char* newText = malloc(length * sizeof(char));

    for(int i = 0; i < length; i++){
        int ASCII = text[i];
        newText[i] = ASCII;
    }

    printf("The encrypted text is: ");
    for(int i = 0; i < length; i++){
        printf("%x ", newText[i]);
    }
    printf("\n");
}

//Reverse Alphabet Cipher
void option3(char *text, int length){
    printf("For this option,we will write the alphabet backwards from Z to A.");
    printf(" Then, swap each letter in your message with its opposite. So, 'A' becomes 'Z', 'B' becomes 'Y', and so on.\n");
    char* newText = malloc(length * sizeof(char));

    for(int i = 0; i < length; i++){
        char temp = text[i];
        if(temp >= 'A' && temp <= 'Z'){//handle uppercase
            newText[i] = 'A' + 'Z' - temp;
        }else if(temp >= 'a' && temp <= 'z'){
            newText[i] = 'a' + 'z' - temp;
        }else{
            newText[i] = text[i];
        }
    }

    printf("The encrypted text is: ");
    for(int i = 0; i < length; i++){
        printf("%c", newText[i]);
    }
    printf("\n");
}