#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// Цвета текста
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Цвета фона
#define BG_RESET   "\033[0m"
#define BG_BROWN   "\033[48;5;94m"
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_DARK_GREEN   "\033[48;5;22m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

#define MAP_WIDTH 9
#define MAP_HEIGHT 9
int money = 0;
int health = 5;
std::string input;

using namespace std;

void clearConsole(){
    system("clear");
    system("cls");
}

void printMap(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void spawnMob(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "_"){
                map[i][j-1] = "ƒ";
            }
        }
    }
}

void moveMobs(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "ƒ"){
                if (map[i][j-1] == "."){
                    map[i][j-1] = "ƒ";
                    map[i][j] = ".";
                }
                else if (map[i][j-1] == "|"){
                    map[i][j] = ".";
                    ::health -= 1;
                }
            }
        }
    }
}

void spawnTower(string map[MAP_HEIGHT][MAP_WIDTH], string place){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == place){
                map[i][j] = "@";
            }
        }
    }
}

bool endCheck(){
    if (::health <= 0) {
        return true;
    }
    else{
        return false;
    }
}

void checkingInput() {
    while(!endCheck()){
        cin>>::input;
    }
}
int main() {

    system("chcp 65001");
    string map[MAP_HEIGHT][MAP_WIDTH] = {
            {"#", "#","#", "#", "#","#","#","#","#"},
            {"#"," ","1"," ","3"," ","5"," ","#"},
            {"†","|","." ,".",".",".",".",".","_"},
            {"#"," "," ","2"," ","4"," "," ","#"},
            {"#", "#","#", "#", "#","#","#","#","#"},
    };
    clearConsole();
    while(true) {
        clearConsole();
        cout << "Символьная оборона" << endl;
        cout << endl;
        cout << "1. Играть"<<endl;
        cout << "2. Выбор уровня"<<endl;
        cout << "0. Выход"<<endl;
        cout << endl;
        cout << "Выберите пункт меню: "; cin >> input;
        if(input == "1") {
            clearConsole();
            cout << "Приятной игры" << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            clearConsole();
            cout
                    << "В мире, где символы обрели силу и стали живыми существами, зловещие коды угрожают всему цифровому королевству. Вы - последний защитник, контролирующий мощные символьные башни, способные отражать атаки зловредных кодов. Ваша миссия - предотвратить вторжение и спасти мир от цифрового хаоса."
                    << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            cout << "Введите любой символ чтобы продолжить: "; cin >> input;
            thread secondThread(checkingInput);
            ::input = " ";
            for(int i =0; i<5;i++){
                clearConsole();
                printMap(map);
                spawnMob(map);
                moveMobs(map);

                cout<<"Ваши деньги: "<<money<<endl;
                cout<<"Жизнь церкви: "<<health<<" hp"<<endl;
                cout<<endl;
                cout << "Выберите действие" << endl;
                cout<<"1. Купить башню"<<endl;
                cout<<"2. Улучшить башню"<<endl;
                if(::input == "1"){
                    ::input = "/";

                    clearConsole();
                    printMap(map);
                    cout<<"Покупка башни"<<endl;
                    cout << "Выберите номер башни:" << endl;
                    this_thread::sleep_for(std::chrono::seconds(2));
                    spawnTower(map, ::input);
                    ::input = " ";
                }
                else if(::input == "2") {
                    ::input = "/";

                    clearConsole();
                    printMap(map);
                    cout<<"Улучшение башни"<<endl;
                    cout << "Функция пока не доступна" << endl;
                    this_thread::sleep_for(std::chrono::seconds(2));
                    ::input = " ";
                }
                this_thread::sleep_for(std::chrono::seconds(2));
            }
            while (!endCheck()) {
                clearConsole();
                printMap(map);
                moveMobs(map);

                cout<<"Ваши деньги: "<<money<<endl;
                cout<<"Жизнь церкви: "<<health<<" hp"<<endl;
                cout<<endl;
                cout << "Выберите действие" << endl;
                cout<<"1. Купить башню"<<endl;
                cout<<"2. Улучшить башню"<<endl;
                if(::input == "1"){
                    ::input = "/";

                    clearConsole();
                    printMap(map);
                    cout<<"Покупка башни"<<endl;
                    cout << "Выберите номер башни:" << endl;
                    this_thread::sleep_for(std::chrono::seconds(2));
                    spawnTower(map, ::input);
                    ::input = " ";
                }
                else if(::input == "2") {
                    ::input = "/";

                    clearConsole();
                    printMap(map);
                    cout<<"Улучшение башни"<<endl;
                    cout << "Функция пока не доступна" << endl;
                    this_thread::sleep_for(std::chrono::seconds(2));
                    ::input = " ";
                }
                this_thread::sleep_for(std::chrono::seconds(2));
            }
            secondThread.join();
        }
        else if(input == "2"){
            clearConsole();
            cout << "Выбор уровня" << endl;
            cout << endl << "1. Первый уровень" << endl;
            cout << "0. Выход в главное меню" << endl;
            cout << endl << "Выберите пункт меню: "; cin >> input;

            if (input == "1"){
                thread secondThread(checkingInput);
                input = "/";
                while (!endCheck()) {
                    clearConsole();
                    printMap(map);
                    moveMobs(map);

                    cout<<"Ваши деньги: "<<money<<endl;
                    cout<<"Жизнь церкви: "<<health<<" hp"<<endl;
                    cout<<endl;
                    cout << "Выберите действие" << endl;
                    cout<<"1. Купить башню"<<endl;
                    cout<<"2. Улучшить башню"<<endl;
                    if(::input == "1"){
                        ::input = "/";

                        clearConsole();
                        printMap(map);
                        cout<<"Покупка башни"<<endl;
                        cout << "Выберите номер башни:" << endl;
                        this_thread::sleep_for(std::chrono::seconds(2));
                        spawnTower(map, ::input);
                        ::input = " ";
                    }
                    else if(::input == "2") {
                        ::input = "/";

                        clearConsole();
                        printMap(map);
                        cout<<"Улучшение башни"<<endl;
                        cout << "Функция пока не доступна" << endl;
                        this_thread::sleep_for(std::chrono::seconds(2));
                        ::input = " ";
                    }
                    this_thread::sleep_for(std::chrono::seconds(2));
                }
                secondThread.join();
            }
        }
        else if(input == "0"){
            return 0;
        }
    }
}