//
// Created by martkans on 10.10.18.
//

#ifndef LISTA1_TOOLS_H
#define LISTA1_TOOLS_H


#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string convertIntToString(int number);
int convertStringToInt(string input);

int * copyTable(int * source_table, int source_table_size, int target_table_size);
void eraseTable(int *table, int table_length);

bool isInRange(int number, int lower_limit, int upper_limit);
bool isTOrN(string input);

int provideInt(int lower_limit, int upper_limit);
int chooseBetween1And10();

string provideYesOrNo();


#endif //LISTA1_TOOLS_H
