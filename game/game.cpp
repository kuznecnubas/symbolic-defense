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

using namespace std;
#define MAP_WIDTH 9
#define MAP_HEIGHT 9
int money;
int health;
int health_mob1 = 100;
int health_mob2 = 100;
int health_mob3 = 100;
int health_mob4 = 100;
int health_mob5 = 100;
int health_mob6 = 100;
int health_mob7 = 100;
int health_mob8 = 100;
std::string input;
int f =0;
string mobs[100]={"ƒ1","ƒ2","ƒ3","ƒ4","ƒ5","ƒ6","ƒ7","ƒ8","ƒ9","ƒ10","ƒ11"};
int damage[MAP_HEIGHT][MAP_WIDTH]={
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
};
string map_mobs[MAP_HEIGHT][MAP_WIDTH] = {
        {"#", "#","#", "#", "#","#","#","#","#"},
        {"#"," ","1"," ","3"," ","5"," ","#"},
        {"†","|","." ,".",".",".",".",".","_"},
        {"#"," "," ","2"," ","4"," "," ","#"},
        {"#", "#","#", "#", "#","#","#","#","#"},
};
void clearConsole(){
    system("clear");
    system("cls");
}
void towerDamage(int i, int j, string map_mobs[MAP_HEIGHT][MAP_WIDTH],string map[MAP_HEIGHT][MAP_WIDTH]) {
    int health0 = 0;
    if (damage[i][j] > 0) {
        cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
        if ("ƒ1" == map_mobs[i][j]) {
            health_mob1 -= damage[i][j];
            health0 = health_mob1;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ2" == map_mobs[i][j]) {
            health_mob2 -= damage[i][j];
            health0 = health_mob2;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ3" == map_mobs[i][j]) {
            health_mob3 -= damage[i][j];
            health0 = health_mob3;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ4" == map_mobs[i][j]) {
            health_mob4 -= damage[i][j];
            health0 = health_mob4;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ5" == map_mobs[i][j]) {
            health_mob5 -= damage[i][j];
            health0 = health_mob5;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ6" == map_mobs[i][j]) {
            health_mob6 -= damage[i][j];
            health0 = health_mob6;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ7" == map_mobs[i][j]) {
            health_mob7 -= damage[i][j];
            health0 = health_mob7;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        } else if ("ƒ8" == map_mobs[i][j]) {
            health_mob8 -= damage[i][j];
            health0 = health_mob8;
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
            }
        }
    }
}

void printMap(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            cout << "     "<<map[i][j];
        }
        cout << endl;
    }
}

void printMap1(string map_mobs[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            cout << "     "<<map_mobs[i][j];
        }
        cout << endl;
    }
}

void spawnMob(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "_"){
                map[i][j-1] = "ƒ";
                map_mobs[i][j-1] =mobs[f];
                f++;
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
                    map_mobs[i][j-1] = map_mobs[i][j];
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    towerDamage(i,j-=1,map_mobs,map);
                }
                else if (map[i][j-1] == "|"){
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    ::health -= 1;
                }
            }
        }
    }
}

void spawnTower(string map[MAP_HEIGHT][MAP_WIDTH], string place){
    string placen = place;
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == place){
                map[i][j] = "@";
            }
            if(placen=="1"){
                damage[2][3]+=50;
                damage[2][2]+=50;
                placen="0";
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

void runningGame(string map[MAP_HEIGHT][MAP_WIDTH]){
    string tower, towerPlace;
    ::health = 5; ::money = 100;
    for(int i =0; i<5;i++){
        clearConsole();
        spawnMob(map);
        moveMobs(map);
        printMap(map);

        cout<<"Ваши монеты: "<<money<<endl;
        cout<<"Жизнь церкви: "<<health<<" hp"<<endl;
        cout<<endl;
        cout << "Выберите действие" << endl;
        cout<<"1. Купить башню"<<endl;
        cout<<"2. Улучшить башню"<<endl;
        if(::input == "1"){
            ::input = "/";

            clearConsole();
            printMap(map);
            cout << "Покупка башни" << endl;
            cout << "Ваши монеты: " << ::money << endl << endl;
            cout << "1. Огнемёт = 100 монет" << endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            if (::money >= 100){
                spawnTower(map, ::input);
                money -= 100;
            }
            else{
                cout << "Недостаточно монет" << endl;
            }
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
        else if(::input == "0"){
            ::health = 0;
        }
        this_thread::sleep_for(std::chrono::seconds(2));
    }
    while (!endCheck()) {
        clearConsole();
        moveMobs(map);
        printMap(map);

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
            cout << "Покупка башни" << endl;
            cout << "Ваши монеты: " << ::money << endl << endl;
            cout << "1. Огнемёт = 100 монет" << endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            spawnTower(map, ::input);
            money -= 100;
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
        else if(::input == "0"){
            ::health = 0;
        }
        this_thread::sleep_for(std::chrono::seconds(2));
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
        input = "/";
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
            runningGame(map);
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
                runningGame(map);
                secondThread.join();
            }
        }
        else if(input == "0"){
            return 0;
        }
    }
}
