//
// Created by martkans on 12.10.18.
//

#ifndef LISTA1_USERINTERFACE_H
#define LISTA1_USERINTERFACE_H

#define BAD_VALUE_ALERT_MESSAGE                 "Podano błędną wartość.\n"
#define NO_OBJECTS_ALERT_MESSAGE                "Nie masz żadnych obiektów! Stwórz je lub zakończ program!\n"
#define CONFIRMATION_ERROR_ALERT_MESSAGE        "Wprowadź 't' aby potwierdzić lub 'n', aby zaprzeczyć!\n"

#define CREATE_OBJECTS_MENU_VALUE       1
#define CHANGE_TABLE_SIZE_MENU_VALUE    2
#define DELETE_OBJECT_MENU_VALUE        3
#define DELETE_OBJECTS_MENU_VALUE       4
#define CHANGE_OBJECT_NAME_MENU_VALUE   5
#define CLONE_OBJECT_MENU_VALUE         6
#define SHOW_OBJECT_INFO_MENU_VALUE     7
#define SET_TABLE_CELL_MENU_VALUE       8
#define SHOW_ALL_OBJECTS_MENU_VALUE     9
#define TEST_MENU_VALUE                 10
#define EXIT_MENU_VALUE                 11

#include <iostream>
#include <string>
#include <climits>

#include "../Tools/Tools.h"
#include "../CApplicationHandler/CApplicationHandler.h"

using namespace std;

class CUserInterface{
    public:
        CUserInterface();
        ~CUserInterface();

        void start();

    private:
        CApplicationHandler *application_handler;
        bool *error;


        void createObjectUserService();
        void changeTableSizeUserService();
        void deleteSpecificObjectUserService();
        void deleteAllObjectsUserService();
        void changeObjectNameUserService();
        void cloneObjectUserService();
        void showObjectInfoUserService();
        void setTableCellValueUserService();
        void showAllCTableObjectsUserService();
        void testUserService();
        void exitUserService();

        void showMenu();
        void alert(string message);

};



#endif //LISTA1_USERINTERFACE_H
