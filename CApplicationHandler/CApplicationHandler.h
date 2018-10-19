//
// Created by martkans on 12.10.18.
//

#ifndef LISTA1_APPLICATIONHANDLER_H
#define LISTA1_APPLICATIONHANDLER_H

#include "../CTable/CTable.h"

#include <vector>
#include <string>


class CApplicationHandler {
    private:
        vector <CTable*> CTable_objects;

    public:
        ~CApplicationHandler();

        int getVectorLastIndex();
        int getTableLastIndex(int position_of_object);

        void createDefaultObject();
        void createPersonalizedObject(int size_of_table, string name);
        void cloneObject(int position_of_existing_object);

        void changeNameOfObject(int position_of_object, string new_name);
        void changeSizeOfObject(int position_of_object, int new_size);

        string getInfoAboutObject(int position_of_object);
        string getShortInfoAboutAllObjects();

        void setValueOfObjectCell(int position_of_object, int cell_number, int value);

        void deleteSpecificObject(int position_of_object);
        void deleteAllObjects();

        void testObject(CTable other_object);

        CTable* getObject(int position);
};


#endif //LISTA1_APPLICATIONHANDLER_H
