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

using namespace std;

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
                if (map[i][j-1] == BG_BROWN && map[i][j-1] == " "){
                    map[i][j-1] = "ƒ";
                    map[i][j] = " ";
                }
                else if (map[i+1][j] == BG_BROWN && map[i+1][j] == " "){
                    map[i+1][j] = "ƒ";
                    map[i][j] = " ";
                }
                else if (map[i-1][j] == BG_BROWN && map[i-1][j] == " "){
                    map[i-1][j] = "ƒ";
                    map[i][j] = " ";
                }
            }
        }
    }
}

int main() {
    system("chcp 65001");
    string map[MAP_HEIGHT][MAP_WIDTH] = {
            {"#", "###","#", "#", "#","#","#","#","#"},
            {"#","   ","1"," ","3"," ","5"," ","#"},
            {"#"," † "," " ,".",".",".",".",".","_"},
            {"#","   "," ","2"," ","4"," "," ","#"},
            {"#", "###","#", "#", "#","#","#","#","#"},
    };

    system("clear");
    system("cls");
    char input;
    while(true) {
        cout << "Символьная оборона" << endl;
        cout<<endl;
        cout<<"Главное меню"<<endl;
        cout<<"1. Играть"<<endl;
        cout<<"2. Выбор уровня"<<endl;
        cout<<"0. Выход"<<endl;
        cin>>input;
        switch (input) {
            case '0':
                return 0;
            case '1':
                cout<<"Приятной игры"<<endl;
                cout << "\x1B[2J\x1B[H";
                cout<< "Сюжет: В мире, где символы обрели силу и стали живыми существами, зловещие коды угрожают всему цифровому королевству. Вы - последний защитник, контролирующий мощные символьные башни, способные отражать атаки зловредных кодов. Ваша миссия - предотвратить вторжение и спасти мир от цифрового хаоса."<< endl;
                printMap(map);
                cin >> input;
            case '2':
                cout << "\x1B[2J\x1B[H";
                cout<<"Выберите желаемый уровень:"<<endl;
                cout<<"1. Уровень"<<endl;
                cin >> input;
                switch (input) {
                    case '1':
                        cout<<"1. Уровень"<<endl;
                        break;
                }
        }
    }
}