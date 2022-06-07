#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int comp(const void* a, const void* b);

char** read_text(char **text, int *num_sentences){
    *num_sentences=0;
    int num = 0;
    char symbol;
    printf("Введите текст:\n");
    text[*num_sentences] = (char *) malloc(sizeof(char));
    symbol = getchar();
    while (symbol != '\n'){
        while (symbol != '.'){
            text[*num_sentences] = (char *)realloc(text[*num_sentences], (num + 1)*sizeof(char));
            text[*num_sentences][num] = symbol;
            num++;
            symbol = getchar();
        }
        symbol = getchar();
        if (symbol==' '){
            symbol = getchar();
        }
        text[*num_sentences] = (char*)realloc(text[*num_sentences], (num + 2) * sizeof(char));
        text[*num_sentences][num] = '.';
        text[*num_sentences][num + 1] = '\0';
        (*num_sentences)++;
        text = (char**)realloc(text, (*num_sentences + 1) * sizeof(char*));
        text[*num_sentences] = (char*)malloc(sizeof(char*));
        num = 0;
    }
    return text;
}

char** delete_same_sent(char** text, int *num_sentences){
    bool same = true;
    for(int i=0; i<(*num_sentences)-1; i++){
        for(int j=i+1; j<*num_sentences; j++){
            if(strlen(text[i]) == strlen(text[j])){
                for(int k=0; k<strlen(text[i]); k++){
                    if(toupper(text[i][k]) != toupper(text[j][k])){
                        same = false;
                        break;
                    }
                }
                if(same){
                    for(int k=j; k<(*num_sentences); k++){
                        text[k]=text[k+1];
                    }
                    (*num_sentences)--;
                    text = (char**)realloc(text, (*num_sentences)*sizeof(char*));
                    j--;
                }
            }
        }
    }
    return text;
}

void time(char **text, int num_sentences){
	int time = 0;
    char strsec[2];
    int sec;
    int min;
    int hour;
    int ten = 1;
	for(int i = 0; i<num_sentences; i++){
		for(int j = 1; j<strlen(text[i])-3; j++){
            if((text[i][j] == 's') && (text[i][j+1] == 'e') && (text[i][j+2] == 'c')){
                j--;
                while(isdigit(text[i][j])){
                    strsec[0] = text[i][j];
                    strsec[1] = '\0';
                    time += atoi(strsec) * ten;
                    ten *= 10;
                    j--;
                }
                while(ten != 1){
                    j++;
                    ten = ten / 10;
                }
                j++;
            }
        }
	}
    sec = time % 60;
    hour = time / 3600;
    min = (time / 60) % 60;
    printf("%d:%d:%d\n", hour, min, sec);
}

char **delete_first_word(char **text, int *num_sentences){
    for(int i=0; i<*num_sentences; i++){
        int j = 0;
        int word = 1;
        while((text[i][j] != ' ') && (text[i][j] != ',') && (text[i][j] !='.')){
            word++;
            j++;
        }
        if(text[i][j] == '.'){
            for(int k=i; k<*num_sentences; k++){
                    text[k]=text[k+1];
                }
            (*num_sentences)--;
            text = (char**)realloc(text, (*num_sentences)*sizeof(char*));
            i--;
        }    
        else{
            int len = strlen(text[i]);
            for(int j=0; j<=len-word; j++){
                text[i][j]=text[i][j+word];
            }
            text[i] = (char*)realloc(text[i], (len - word)*sizeof(char*));
        }
    }
    return text;
}

char **delete_same_lenght(char **text, int *num_sentences){
    for(int i=0; i<*num_sentences; i++){
        bool first = true;
        int len1 = 0;
        int len2 = 0;
        for(int j = 0; j<strlen(text[i]); j++){
            while((text[i][j] != ' ') && (text[i][j] != ',') && (text[i][j] != '.') && (first)){
                j++;
                len1++;
            }
            first = false;
            if(text[i][len1] == '.'){
                for(int k=i; k<(*num_sentences)-1; k++){
                    text[k]=text[k+1];
                }
                (*num_sentences)--;
                text = (char**)realloc(text, (*num_sentences)*sizeof(char*));
                i--;
                break;
            }
            if(text[i][j] == ','){
                continue;
            }
            if(text[i][j] == ' '){
                continue;
            }
            while((text[i][j] != ' ') && (text[i][j] != ',') && (text[i][j] != '.')){
                j++;
                len2++;
            }
            if(len1 != len2){
                break;
            }
            else if(text[i][j] == '.'){
                for(int k=i; k<(*num_sentences)-1; k++){
                    text[k]=text[k+1];
                }
                (*num_sentences)--;
                text = (char**)realloc(text, (*num_sentences)*sizeof(char*));
                i--;
                break;
            }
            else{
                len2 = 0;
            }
        }
    }
    return text;
}

int comp(const void* a, const void* b){
    const char *first_str = *( const char * const *) a;
    int count_first = 0;
    const char *second_str = *( const char * const *) b;
    int count_second = 0;
    for(int i = 0; i < strlen(first_str); i++){
        if(islower(first_str[i])){
            count_first++;
        }
    }
    for(int i = 0; i < strlen(second_str); i++){
        if(islower(second_str[i])){
            count_second++;
        }
    }
    if(count_first > count_second){
        return -1;
    }
    else if(count_first == count_second){
        return 0;
    }
    else{
        return 1;
    }
}

void print_text(char **text, int num_sentences){
    for(int i; i<num_sentences; i++){
        printf("%s ", text[i]);
    }
    printf("\n");
}

int main(){
    char **text;
    int num_sentences;
    text = (char**)malloc(1 * sizeof(char));
    text = read_text(text, &num_sentences);
    text = delete_same_sent(text, &num_sentences);
    int control;
    printf("Введите номер команды (1 - найти время в тексте и вывести сумму в формате часы:минуты:секунды;\n2 - в каждом предложении удалить первое слово, если предложение является односложным удалить его;\n3 - удалить все предложения в которых у каждого слова совпадает кол-во букв;\n4 - отсортировать все предложения по уменьшению длины кол-ва строчныйх букв в нем;\n0 - вывести текст): ");
    scanf("%d", &control);
    switch(control){
        case 0:{ 
            print_text(text, num_sentences); 
            free(text);
            break;
        }
		case 1:{ 
            time(text, num_sentences); 
            free(text);
            break;
        }
        case 2:{
            text = delete_first_word(text, &num_sentences);
            print_text(text, num_sentences);
            free(text);
            break;
        }
        case 3:{ 
            text = delete_same_lenght(text, &num_sentences);
            print_text(text,num_sentences);
            free(text);
            break;
        }
        case 4:{
            qsort(text, num_sentences, sizeof(char*), comp);
            print_text(text,num_sentences);
            free(text);
            break;
        }
        default:{
            break;
             printf("Данные некорректны\n");
        }
    }
}