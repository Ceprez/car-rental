#include <iostream>
#include <fstream>

void registration();
void login();
void inApp();
void addCar();
void menu();

void menu(){
    int userInput;

    std::cout << "==============================" << std::endl;
    std::cout << "Welcome to David's car rental!" << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Add car(for employees)" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Your Choice: ";
    std::cin >> userInput;

    switch(userInput) {
        case 1:{
            login();
            break;
        }

        case 2:{
            registration();
            break;
        }

        case 3:{
            addCar();
            break;
        }

        case 4:{
            return;
        }

        default:{
            std::cout << "Enter number 1-4!" << std::endl;
            break;
        }
    }
}

void registration(){
    std::string name, surname, username, password;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your surname: ";
    std::cin >> surname;
    std::cout << "Enter your age:";
    std::cin >> age;

    if (age < 18){
        std::cout << "You must be over 18!" << std::endl;
        return;
    }

    std::ofstream openFile;

    openFile.open("accounts.txt", std::ios::app);

    std::cout << "Create a username: ";
    std::cin >> username;
    std::cout << "Create a password: ";
    std::cin >> password;

    openFile << name << ' ' << username << ' ' << password << std::endl;
    system("clear");
    std::cout << std::endl;
    std::cout << "You were registered successfully!" << std::endl;
    std::cout << std::endl;
    return;
}



void login() {
    int check = 0;
    std::string name, username, password, checkUsername, checkPassword;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ifstream checkFile;

    checkFile.open("accounts.txt");

    while (!checkFile.eof()){
        checkFile >> name >> checkUsername >> checkPassword;

        if (username == checkUsername && password == checkPassword){
            std::cout << std::endl;
            std::cout << "Welcome " << name << '!' << std::endl;
            check = 1;
            inApp();
        }

    }
    if(check != 1){
        std::cout << "Incorrect username!" << std::endl;
    }
    checkFile.close();
}

void inApp() {

    std::string userMake, userModel;

    std::ifstream openFile;

    openFile.open("cars.txt");

    while(!openFile.eof()){
        std::string make, model;
        int year;
        double price;

        openFile >> make >> model >> year >> price;

        std::cout << std::endl;
        std::cout << make << ' ' << model << ' ' << year << ". Price: " << price << '$' << std::endl;

    }
    openFile.close();
    openFile.open("cars.txt");

    std::cout << std::endl;
    std::cout << "Enter make ('exit' to exit): ";
    std::cin >> userMake;
    std::cout << "Enter model ('exit' to exit): ";
    std::cin >> userModel;
    std::cout << std::endl;

    while (!openFile.eof()){
        std::string make, model;
        int year;
        double price;

        openFile >> make >> model >> year >> price;

        if(userMake == make && userModel == model){
            std::cout << "=========================" << std::endl;
            std::cout << "Total: " << price << '$' << std::endl;
            std::cout << "=========================" << std::endl;
            break;
        }

        if (userMake == "exit" || userModel == "exit"){
            break;
        }
    }
    exit(0);
}

void addCar() {
    std::string addPassword = "rental123";
    std::string passwordCheck;
    std::cout << "Enter password: ";
    std::cin >> passwordCheck;

    if (passwordCheck == addPassword){
        std::string make, model;
        int year;
        double price;

        std::ofstream addCar;

        addCar.open("cars.txt", std::ios::app);

        std::cout << "Enter car make: ";
        std::cin >> make;
        std::cout << "Enter car model: ";
        std::cin >> model;
        std::cout << "Enter year: ";
        std::cin >> year;
        std::cout << "Add a price: ";
        std::cin >> price;

        addCar << std::endl << make << ' ' << model << ' ' << year << ' ' << price;
        addCar.close();
    }
    else {
        std::cout << "Incorrect password!" << std::endl;
        return;
    }

}
