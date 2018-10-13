//
// Created by martkans on 12.10.18.
//

#include "UserInterface.h"

void start() {
    const int EXIT_VALUE = 10;

    CApplicationHandler * applicationHandler = new CApplicationHandler();
    int choice = 0;
    string name;

    while(choice != EXIT_VALUE) {

        showMenu();

        if(applicationHandler->getVectorSize() == 0){
            choice = chooseBetween1And10();
        } else {
            choice = provideInt(1, 10);
        }


        switch (choice) {
            case 1:
                createObjectUserService(*applicationHandler);
                break;

            case 2:
                changeTableSizeUserService(*applicationHandler);
                break;

            case 3:
                deleteSpecificObjectUserService(*applicationHandler);
                break;

            case 4:
                deleteAllObjectsUserService(*applicationHandler);
                break;

            case 5:
                changeObjectNameUserService(*applicationHandler);
                break;
            case 6:
                cloneObjectUserService(*applicationHandler);
                break;

            case 7:
                showObjectInfoUserService(*applicationHandler);
                break;

            case 8:
                setTableCellValueUserService(*applicationHandler);
                break;

            case 9:
                showAllCTableObjectsUserService(*applicationHandler);
                break;

            case EXIT_VALUE:
                delete applicationHandler;
                cout << "\nŻegnaj!";
                break;

            default:
                cout << "\nWprowadź poprawną wartość!";
        }
    }

}

void createObjectUserService(CApplicationHandler &applicationHandler){
    int number_of_objects;
    string answer;

    cout << "\nIle chcesz utworzyć obiektów?\n";
    number_of_objects = provideInt(1, INT_MAX);
    for (int i = 0; i < number_of_objects; ++i) {
        cout << "\nObiekt nr " << i+1 << "\n";
        cout << "\nCzy chcesz utworzyć domyślny obiekt? (t/n)\n";
        answer = provideYesOrNo();

        if (answer == "t" || answer == "T"){
            applicationHandler.createDefaultObject();
        } else {
            string name;
            int table_length;

            cout << "\nPodaj nazwę obiektu: ";
            cin >> name;

            cout << "\nPodaj długość tablicy obiektu: ";
            table_length = provideInt(1, INT_MAX);

            applicationHandler.createPersonalizedObject(table_length, name);
        }
    }
}

void changeTableSizeUserService(CApplicationHandler &applicationHandler){
    int position_of_object;
    int table_length;

    cout << "\nPodaj nr obiektu, którego chcesz zmienić rozmiar (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    cout << "\nPodaj nowy rozmiar tablicy obiektu (1 - " << INT_MAX
         << ")\n";

    table_length = provideInt(1, INT_MAX);

    applicationHandler.changeSizeOfObject(position_of_object, table_length);
}

void deleteSpecificObjectUserService(CApplicationHandler &applicationHandler) {
    int position_of_object;

    cout << "\nPodaj nr obiektu, który chcesz usunąć (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    applicationHandler.deleteSpecificObject(position_of_object);
}

void deleteAllObjectsUserService(CApplicationHandler &applicationHandler) {
    string answer;

    cout << "\nCzy na pewno chcesz usunąć wszystkie obiekty? (t/n)\n";
    answer = provideYesOrNo();

    if (answer == "t" || answer == "T") {
        applicationHandler.deleteAllObjects();
    }
}

void changeObjectNameUserService(CApplicationHandler &applicationHandler) {
    int position_of_object;
    string name;

    cout << "\nPodaj nr obiektu, którego chcesz zmienić nazwę (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    cout << "\nPodaj nową nazwę obiektu: ";
    cin >> name;

    applicationHandler.changeNameOfObject(position_of_object, name);
}

void cloneObjectUserService(CApplicationHandler &applicationHandler) {
    int position_of_object;

    cout << "\nPodaj nr obiektu, który chcesz sklonować (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    applicationHandler.cloneObject(position_of_object);
}

void showObjectInfoUserService(CApplicationHandler &applicationHandler) {
    int position_of_object;

    cout << "\nPodaj nr obiektu, o którym informacje chcesz otrzymać (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    cout << "\n" << applicationHandler.getInfoAboutObject(position_of_object) << "\n";
}

void setTableCellValueUserService(CApplicationHandler &applicationHandler) {
    int position_of_object, cell_number, cell_value;

    cout << "\nPodaj nr obiektu, którego wartość komórki chcesz zmienić (0 - " << applicationHandler.getVectorSize() - 1
         << ")\n";
    position_of_object = provideInt(0, applicationHandler.getVectorSize() - 1);

    cout << "\nPodaj nr komórki, której chcesz zmienić (0 - " << applicationHandler.getTableSize(position_of_object) - 1
         << ")\n";
    cell_number = provideInt(0, applicationHandler.getTableSize(position_of_object) - 1);

    cout << "\nPodaj nową wartość komórki.\n";
    cell_value = provideInt(INT_MIN, INT_MAX);

    applicationHandler.setValueOfObjectCell(position_of_object, cell_number, cell_value);
}

void showAllCTableObjectsUserService(CApplicationHandler &applicationHandler){
    cout << "\n" << applicationHandler.getShortInfoAboutAllObjects() << "\n";
}

void showMenu() {

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
         << "10. Koniec programu\n";
}

void alert(string message) {
    cout << "\nOperacja zakończona niepowodzeniem!\n"
         << message << "\n";
}

