//
// Created by martkans on 10.10.18.
//

#include "Tools.h"
#include "../UserInterface/UserInterface.h"

string convertIntToString(int number){
    stringstream ss;
    ss << number;
    return ss.str();
}

int convertStringToInt(string input){
    int number;

    istringstream is(input);
    is >> number;

    return number;
}

int *copyTable(int *source_table, int source_table_size, int target_table_size) {
    int * target_table = new int[target_table_size];

    for (int i = 0; i < target_table_size && i < source_table_size; ++i) {
        target_table[i] = source_table[i];
    }

    return target_table;
}

void eraseTable(int * table, int table_length) {
    for (int i = 0; i < table_length; ++i){
        table[i] = 0;
    }
}

bool isInRange(int number, int lower_limit, int upper_limit) {
    if(number >= lower_limit && number <= upper_limit){
        return true;
    } else {
        return false;
    }
}

int provideInt(int lower_limit, int upper_limit) {
    string inputData;
    cin >> inputData;
    if (isInRange(convertStringToInt(inputData), lower_limit, upper_limit)){
        return convertStringToInt(inputData);
    } else {
        do{
            string alertMessage;
            if (lower_limit != upper_limit){
                alertMessage = "Podaj wartość całkowitą z zakresu (" + convertIntToString(lower_limit) + "-" + convertIntToString(upper_limit) + ")";
            } else {
                alertMessage = "Masz do wyboru tylko jedną wartość: " + convertIntToString(lower_limit);
            }
            alert(alertMessage);
            cin >> inputData;
        }while (!isInRange(convertStringToInt(inputData), lower_limit, upper_limit));
    }

    return  convertStringToInt(inputData);
}

int chooseBetween1And10() {
    string inputData;
    cin >> inputData;
    if (inputData == "1" || inputData == "10"){
        return convertStringToInt(inputData);
    } else {
        do{
            alert("Nie masz żadnych obiektów! Stwórz je lub zakończ program!\n");
            cin >> inputData;
        }while (inputData != "1" && inputData != "10");
    }
    return convertStringToInt(inputData);
}

bool isTOrN(string input){
    if (input == "T" || input == "t" || input == "N" || input == "n"){
        return true;
    } else {
        return false;
    }
}

string provideYesOrNo() {
    string confirm;
    cin >> confirm;
    if (isTOrN(confirm)){
        return confirm;
    } else {
        do{
            alert("Wprowadź 't' aby potwierdzić lub 'n', aby zaprzeczyć!\n");
            cin >> confirm;
        }while(!isTOrN(confirm));
    }

    return confirm;
}
