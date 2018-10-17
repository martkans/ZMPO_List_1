//
// Created by martkans on 07.10.18.
//

#ifndef LISTA1_TABLECLASS_H
#define LISTA1_TABLECLASS_H

#include <string>
#include <iostream>

#include "../Tools/Tools.h"

using namespace std;

class CTable {
    private:
        string name;
        int *table;
        int table_size;

        const int DEFAULT_SIZE_OF_TABLE;
        const string DEFAULT_NAME_OF_OBJECT;

        void constructorHelper(int size, string name);

    public:
        CTable();
        CTable(int size_of_table, string name);
        CTable(CTable &object_to_copy);

        ~CTable();

        int getTableSize();
        string getName();
        void setName(string new_name);

        void changeSizeOfTable(int new_size);
        int getValueOfTableCell(int cell_number);
        void setValueOfTableCell(int cell_number, int value);
        CTable *cloneObject();
        void copyTableFromOtherObject(CTable &object_to_copy);
        string toString();
};


#endif //LISTA1_TABLECLASS_H
