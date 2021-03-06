#include "CUserInterface.h"

CUserInterface::CUserInterface() {
    application_handler = new CApplicationHandler();
    error = new bool();
}

CUserInterface::~CUserInterface() {
    delete application_handler;
    delete error;
}

void CUserInterface::start() {

    int choice = 0;
    string name;


    while(choice != EXIT_MENU_VALUE) {

        showMenu();

        if(application_handler->getVectorLastIndex() == -1){
            choice = chooseBetweenTwoNumbers(CREATE_OBJECTS_MENU_VALUE, EXIT_MENU_VALUE, error);
            if(*error){
                alert(NO_OBJECTS_ALERT_MESSAGE);
            }
        } else {
            choice = provideInt(CREATE_OBJECTS_MENU_VALUE, EXIT_MENU_VALUE, error);
            if(*error){
                alert(BAD_VALUE_ALERT_MESSAGE);
            }
        }

        if (!*error){
            switch (choice) {
                case CREATE_OBJECTS_MENU_VALUE:
                    createObjectUserService();
                    break;

                case CHANGE_TABLE_SIZE_MENU_VALUE:
                    changeTableSizeUserService();
                    break;

                case DELETE_OBJECT_MENU_VALUE:
                    deleteSpecificObjectUserService();
                    break;

                case DELETE_OBJECTS_MENU_VALUE:
                    deleteAllObjectsUserService();
                    break;

                case CHANGE_OBJECT_NAME_MENU_VALUE:
                    changeObjectNameUserService();
                    break;

                case CLONE_OBJECT_MENU_VALUE:
                    cloneObjectUserService();
                    break;

                case SHOW_OBJECT_INFO_MENU_VALUE:
                    showObjectInfoUserService();
                    break;

                case SET_TABLE_CELL_MENU_VALUE:
                    setTableCellValueUserService();
                    break;

                case SHOW_ALL_OBJECTS_MENU_VALUE:
                    showAllCTableObjectsUserService();
                    break;

                case TEST_MENU_VALUE:
                    testUserService();
                    break;

                case EXIT_MENU_VALUE:
                    exitUserService();
                    break;

                default:
                    alert(BAD_VALUE_ALERT_MESSAGE);
            }
        }

    }

}

void CUserInterface::createObjectUserService(){
    int number_of_objects;
    bool answer;

    cout << "\nIle chcesz utworzyć obiektów?\n";
    number_of_objects = provideInt(1, INT_MAX, error);

    if (*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        for (int i = 0; i < number_of_objects; ++i) {
            cout << "\nObiekt nr " << i+1 << "\n";
            cout << "\nCzy chcesz utworzyć domyślny obiekt? (t/n)\n";
            answer = provideYesOrNo(error);

            if (*error){
                alert(CONFIRMATION_ERROR_ALERT_MESSAGE);
                --i;
            } else {
                if (answer){
                    application_handler->createDefaultObject();
                } else {
                    string name;
                    int table_length;

                    cout << "\nPodaj nazwę obiektu: ";
                    getline(cin, name);

                    cout << "\nPodaj długość tablicy obiektu: ";
                    table_length = provideInt(1, INT_MAX, error);

                    if (*error){
                        alert(BAD_VALUE_ALERT_MESSAGE);
                        --i;
                    } else {
                        application_handler->createPersonalizedObject(table_length, name);
                    }
                }
            }

        }
    }
}

void CUserInterface::changeTableSizeUserService(){
    int position_of_object;
    int table_length;

    cout << "\nPodaj nr obiektu, którego chcesz zmienić rozmiar (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if (*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        cout << "\nPodaj nowy rozmiar tablicy obiektu (1 - " << INT_MAX
             << ")\n";

        table_length = provideInt(1, INT_MAX, error);

        if (*error){
            alert(BAD_VALUE_ALERT_MESSAGE);
        } else {
            application_handler->changeSizeOfObject(position_of_object, table_length);
        }
    }
}

void CUserInterface::deleteSpecificObjectUserService() {
    int position_of_object;

    cout << "\nPodaj nr obiektu, który chcesz usunąć (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);
    if (*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else if(!*error){
        application_handler->deleteSpecificObject(position_of_object);
    }
}

void CUserInterface::deleteAllObjectsUserService() {
    bool answer;

    cout << "\nCzy na pewno chcesz usunąć wszystkie obiekty? (t/n)\n";
    answer = provideYesOrNo(error);

    if(*error){
        alert(CONFIRMATION_ERROR_ALERT_MESSAGE);
    } else{
        if (answer) {
            application_handler->deleteAllObjects();
        }
    }
}

void CUserInterface::changeObjectNameUserService() {
    int position_of_object;
    string name;

    cout << "\nPodaj nr obiektu, którego chcesz zmienić nazwę (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if (*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        cout << "\nPodaj nową nazwę obiektu: ";
        getline(cin, name);

        application_handler->changeNameOfObject(position_of_object, name);
    }
}

void CUserInterface::cloneObjectUserService() {
    int position_of_object;

    cout << "\nPodaj nr obiektu, który chcesz sklonować (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if(*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        application_handler->cloneObject(position_of_object);
    }
}

void CUserInterface::showObjectInfoUserService() {
    int position_of_object;

    cout << "\nPodaj nr obiektu, o którym informacje chcesz otrzymać (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if(*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        cout << "\n" << application_handler->getInfoAboutObject(position_of_object) << "\n";
    }
}

void CUserInterface::setTableCellValueUserService() {
    int position_of_object, cell_number, cell_value;

    cout << "\nPodaj nr obiektu, którego wartość komórki chcesz zmienić (0 - " << application_handler->getVectorLastIndex()
         << ")\n";
    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if(*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        cout << "\nPodaj nr komórki, której chcesz zmienić (0 - " << application_handler->getTableLastIndex(position_of_object)
             << ")\n";
        cell_number = provideInt(0, application_handler->getTableLastIndex(position_of_object), error);

        if(*error){
            alert(BAD_VALUE_ALERT_MESSAGE);
        } else {
            cout << "\nPodaj nową wartość komórki.\n";
            cell_value = provideInt(INT_MIN, INT_MAX, error);

            if(*error){
                alert(BAD_VALUE_ALERT_MESSAGE);
            } else {
                application_handler->setValueOfObjectCell(position_of_object, cell_number, cell_value);
            }
        }
    }
}

void CUserInterface::showAllCTableObjectsUserService(){
    cout << "\n" << application_handler->getShortInfoAboutAllObjects() << "\n";
}

void CUserInterface::testUserService() {
    int position_of_object;
    cout << "\nPodaj nr obiektu, którego rozmiar chcesz zmienić (0 - " << application_handler->getVectorLastIndex()
         << ")\n";

    position_of_object = provideInt(0, application_handler->getVectorLastIndex(), error);

    if(*error){
        alert(BAD_VALUE_ALERT_MESSAGE);
    } else {
        application_handler->testObject(*application_handler->getObject(position_of_object));
    }
}

void CUserInterface::exitUserService() {
    cout << "\nŻegnaj!";
}

void CUserInterface::showMenu() {

    cout << "\n\nZadanie 1. - Alokacja i dealokacja \n"
         << "---------------------------------------------------\n"
         << "1. Utwórz obiekty CTable\n"
         << "2. Zmień długość tablicy określonego obiektu CTable\n"
         << "3. Skasuj wybrany obiekt CTable\n"
         << "4. Skasuj wszystkie obiekty CTable\n"
         << "5. Zmień nazwę wybranego obiektu CTable\n"
         << "6. Klonuj wybrany obiekt CTable\n"
         << "7. Wypisz informacje o danym obiekcie\n"
         << "8. Ustaw wartość komórki wybranego obiektu CTable\n"
         << "9. Wyświetl listę dostępnych obiektów CTable\n"
         << "10. Test\n"
         << "11. Koniec programu\n";
}

void CUserInterface::alert(string message) {
    cout << "\nOperacja zakończona niepowodzeniem!\n"
         << message << "\n";
}

