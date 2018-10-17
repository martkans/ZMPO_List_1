//
// Created by martkans on 10.10.18.
//

#include "Tools.h"
#include "../CUserInterface/CUserInterface.h"

string convertIntToString(int number){
    stringstream ss;
    ss << number;
    return ss.str();
}

int convertStringToInt(string input, bool *error){
    const int ASCII_ZERO_VALUE = 47;
    const int ASCII_NINE_VALUE = 58;

    int number;

    istringstream is(input);
    is >> number;
    *error = false;
    for (unsigned long i = 0; i < input.length(); ++i) {
        if(!isInRange(input.at(i), ASCII_ZERO_VALUE, ASCII_NINE_VALUE)){
            *error = true;
        }
    }
    return number;
}

int *copyTable(int *source_table, int source_table_size, int target_table_size) {
    int *target_table = new int[target_table_size];

    for(int i = 0; i < target_table_size && i < source_table_size; ++i) {
        target_table[i] = source_table[i];
    }

    return target_table;
}

void eraseTable(int *table, int first_index, int last_index) {
    for (int i = first_index; i < last_index; ++i){
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

int provideInt(int lower_limit, int upper_limit, bool *error) {
    string input_data;
    bool *conversion_error = new bool();
    int number;

    getline(cin, input_data);
    number = convertStringToInt(input_data, conversion_error);

    if(*conversion_error || !isInRange(number, lower_limit, upper_limit)){
        *error = true;
    } else{
        *error = false;
    }
    return number;
}

int chooseBetweenTwoNumbers(int first, int second, bool *error) {
    string input_data;
    bool *conversion_error = new bool();
    int number;

    getline(cin, input_data);
    number = convertStringToInt(input_data, conversion_error);

    if (*conversion_error || (number != first && number != second)){
        *error = true;
    } else {
        *error = false;
    }
    return number;
}

bool provideYesOrNo(bool *error) {
    string confirm;

    getline(cin, confirm);

    *error = false;
    if (confirm == "T" || confirm == "t"){
        return true;
    } else if (confirm != "N" && confirm != "n"){
        *error = true;
    }
    return false;
}
