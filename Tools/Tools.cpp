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

int provideInt(int lower_limit, int upper_limit, bool * error) {
    string inputData;
    cin >> inputData;
    if (isInRange(convertStringToInt(inputData), lower_limit, upper_limit)){
        *error = false;
        return convertStringToInt(inputData);
    } else {
        *error = true;
        return 0;
    }

}

int chooseBetween1And10(bool * error) {
    string inputData;
    cin >> inputData;
    if (inputData == "1" || inputData == "10"){
        *error = false;
        return convertStringToInt(inputData);
    } else {
        *error = true;
        return 0;
    }
}

bool isTOrN(string input){
    if (input == "T" || input == "t" || input == "N" || input == "n"){
        return true;
    } else {
        return false;
    }
}

string provideYesOrNo(bool * error) {
    string confirm;
    cin >> confirm;
    if (isTOrN(confirm)){
        *error = false;
        return confirm;
    } else {
        *error = true;
        return "0";
    }
}
