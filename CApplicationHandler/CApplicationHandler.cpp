//
// Created by martkans on 12.10.18.
//

#include "CApplicationHandler.h"

CApplicationHandler::~CApplicationHandler() {
    deleteAllObjects();
}

int CApplicationHandler::getVectorLastIndex() {
    return static_cast<int>(CTable_objects.size() - 1);
}

int CApplicationHandler::getTableLastIndex(int position_of_object) {
    return CTable_objects.at(static_cast<unsigned long>(position_of_object))->getTableSize() - 1;
}

void CApplicationHandler::createDefaultObject() {
    CTable_objects.push_back(new CTable());
}

void CApplicationHandler::createPersonalizedObject(int size_of_table, string name) {
    CTable_objects.push_back(new CTable(size_of_table, name));
}

void CApplicationHandler::cloneObject(int position_of_existing_object) {
    CTable_objects.push_back(CTable_objects.at(static_cast<unsigned long>(position_of_existing_object))->cloneObject());
}

void CApplicationHandler::changeNameOfObject(int position_of_object, string new_name) {
    CTable_objects.at(static_cast<unsigned long>(position_of_object))->setName(new_name);
}

void CApplicationHandler::changeSizeOfObject(int position_of_object, int new_size) {
    CTable_objects.at(static_cast<unsigned long>(position_of_object))->changeSizeOfTable(new_size);
}

string CApplicationHandler::getInfoAboutObject(int position_of_object) {
    return CTable_objects.at(static_cast<unsigned long>(position_of_object))->toString();
}

string CApplicationHandler::getShortInfoAboutAllObjects() {
    string info;
    for(unsigned long i = 0; i != CTable_objects.size(); ++i) {
        info += "[" + convertIntToString(static_cast<int>(i)) + "] " + CTable_objects.at(i)->getName() + "\n";
    }
    return info;
}

void CApplicationHandler::setValueOfObjectCell(int position_of_object, int cell_number, int value) {
    CTable_objects.at(static_cast<unsigned long>(position_of_object))->setValueOfTableCell(cell_number, value);
}

void CApplicationHandler::deleteSpecificObject(int position_of_object) {
    delete CTable_objects.at(static_cast<unsigned long>(position_of_object));
    CTable_objects.erase(CTable_objects.begin()+position_of_object);
}

void CApplicationHandler::deleteAllObjects() {
    while (!CTable_objects.empty()){
        deleteSpecificObject(0);
    }
}
