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

void start();

void createObjectUserService(CApplicationHandler &applicationHandler);
void changeTableSizeUserService(CApplicationHandler &applicationHandler);
void deleteSpecificObjectUserService(CApplicationHandler &applicationHandler);
void deleteAllObjectsUserService(CApplicationHandler &applicationHandler);
void changeObjectNameUserService(CApplicationHandler &applicationHandler);
void cloneObjectUserService(CApplicationHandler &applicationHandler);
void showObjectInfoUserService(CApplicationHandler &applicationHandler);
void setTableCellValueUserService(CApplicationHandler &applicationHandler);
void showAllCTableObjectsUserService(CApplicationHandler &applicationHandler);

void showMenu();
void alert(string message);


#endif //LISTA1_USERINTERFACE_H
