//
// Created by martkans on 12.10.18.
//

#ifndef LISTA1_USERINTERFACE_H
#define LISTA1_USERINTERFACE_H

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
        CApplicationHandler *applicationHandler;
        bool *error;

        const string BAD_VALUE_ALERT_MESSAGE;
        const string NO_OBJECTS_ALERT_MESSAGE;
        const string CONFIRMATION_ERROR_ALERT_MESSAGE;

        enum SWITCH_CONSTANTS{
            CREATE_OBJECTS_MENU_VALUE = 1,
            CHANGE_TABLE_SIZE_MENU_VALUE = 2,
            DELETE_OBJECT_MENU_VALUE = 3,
            DELETE_OBJECTS_MENU_VALUE = 4,
            CHANGE_OBJECT_NAME_MENU_VALUE = 5,
            CLONE_OBJECT_MENU_VALUE = 6,
            SHOW_OBJECT_INFO_MENU_VALUE = 7,
            SET_TABLE_CELL_MENU_VALUE = 8,
            SHOW_ALL_OBJECTS_MENU_VALUE = 9,
            EXIT_MENU_VALUE = 10
        };


        void createObjectUserService();
        void changeTableSizeUserService();
        void deleteSpecificObjectUserService();
        void deleteAllObjectsUserService();
        void changeObjectNameUserService();
        void cloneObjectUserService();
        void showObjectInfoUserService();
        void setTableCellValueUserService();
        void showAllCTableObjectsUserService();
        void exitUserService();

        void showMenu();
        void alert(string message);

};



#endif //LISTA1_USERINTERFACE_H
