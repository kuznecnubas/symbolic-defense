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
#define MAP_WIDTH 19
#define MAP_HEIGHT 19
int money;
int health;
int money_get;

int t1y, t1x, t2y, t2x, t3y, t3x, t4y, t4x, t5y, t5x;

int health_mob_f1 = 100;
int health_mob_f2 = 100;
int health_mob_f3 = 100;
int health_mob_f4 = 100;
int health_mob_f5 = 100;
int health_mob_f6 = 100;
int health_mob_f7 = 100;
int health_mob_f8 = 100;
int health_mob_w1 = 200;
int health_mob_w2 = 200;
int health_mob_w3 = 200;
int health_mob_w4 = 200;
int health_mob_w5 = 200;
int health_mob_w6 = 200;
int health_mob_w7 = 200;
int health_mob_w8 = 200;
void full_health (){
    health = 5;
    health_mob_f1 = 100;
    health_mob_f2 = 100;
    health_mob_f3 = 100;
    health_mob_f4 = 100;
    health_mob_f5 = 100;
    health_mob_f6 = 100;
    health_mob_f7 = 100;
    health_mob_f8 = 100;
    health_mob_w1 = 200;
    health_mob_w2 = 200;
    health_mob_w3 = 200;
    health_mob_w4 = 200;
    health_mob_w5 = 200;
    health_mob_w6 = 200;
    health_mob_w7 = 200;
    health_mob_w8 = 200;
}
std::string input;
int f =0,W=0,kdd=0;
string mobs_f[100]={"ƒ1", "ƒ2", "ƒ3", "ƒ4", "ƒ5", "ƒ6", "ƒ7", "ƒ8", "ƒ9", "ƒ10", "ƒ11", "ƒ12", "ƒ13", "ƒ14", "ƒ15", "ƒ16", "ƒ17", "ƒ18", "ƒ19", "ƒ20"};
string mobs_W[100]={"₩1", "₩2", "₩3", "₩4", "₩5", "₩6", "₩7", "₩8", "₩9", "₩10", "₩11", "₩12", "₩13", "₩14", "₩15", "₩16", "₩17", "₩18", "₩19", "₩20", "₩1"};
int kd[100]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int damage[MAP_HEIGHT][MAP_WIDTH]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
string map_mobs[MAP_HEIGHT][MAP_WIDTH] = {
        {"#", "#","#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
        {"#"," ","1"," ","3"," ","5"," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"†","|","." ,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","_"},
        {"#"," "," ","2"," ","4"," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#", "#","#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
};
void clearConsole(){
    system("clear");
    system("cls");
}
void towerDamage(int i, int j, string map_mobs[MAP_HEIGHT][MAP_WIDTH],string map[MAP_HEIGHT][MAP_WIDTH],int money_get) {
    int health0 = 0;
    if (damage[i][j] > 0) {
        // cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
        if ("ƒ1" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f1 -= damage[i][j];
                health0 = health_mob_f1;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f1 -= damage[i][j];
                health0 = health_mob_f1;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ2" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f2 -= damage[i][j];
                health0 = health_mob_f2;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f2 -= damage[i][j];
                health0 = health_mob_f2;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ3" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f3 -= damage[i][j];
                health0 = health_mob_f3;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f3 -= damage[i][j];
                health0 = health_mob_f3;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ4" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f4 -= damage[i][j];
                health0 = health_mob_f4;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f4 -= damage[i][j];
                health0 = health_mob_f4;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ5" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f5 -= damage[i][j];
                health0 = health_mob_f5;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f5 -= damage[i][j];
                health0 = health_mob_f5;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ6" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f6 -= damage[i][j];
                health0 = health_mob_f6;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f6 -= damage[i][j];
                health0 = health_mob_f6;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ7" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f7 -= damage[i][j];
                health0 = health_mob_f7;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f7 -= damage[i][j];
                health0 = health_mob_f7;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("ƒ8" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_f8 -= damage[i][j];
                health0 = health_mob_f8;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_f8 -= damage[i][j];
                health0 = health_mob_f8;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        }
        if ("₩1" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_w1 -= damage[i][j];
                health0 = health_mob_w1;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_w1 -= damage[i][j];
                health0 = health_mob_w1;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩2" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_w2 -= damage[i][j];
                health0 = health_mob_w2;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_w2 -= damage[i][j];
                health0 = health_mob_w2;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩3" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_w3 -= damage[i][j];
                health0 = health_mob_w3;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_w3 -= damage[i][j];
                health0 = health_mob_w3;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
            if(health0 == 0){
                map_mobs[i][j] = ".";
                map[i][j] = ".";
                money += money_get;
            }
        } else if ("₩4" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_w4 -= damage[i][j];
                health0 = health_mob_w4;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_w4 -= damage[i][j];
                health0 = health_mob_w4;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩5" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                kdd++;
                health_mob_w5 -= damage[i][j];
                health0 = health_mob_w5;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                cout << "Башня нанесла " << damage[i][j] << " урона мобу - " << map_mobs[i][j] << endl;
                health_mob_w5 -= damage[i][j];
                health0 = health_mob_w5;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩6" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                kdd++;
                health_mob_w6 -= damage[i][j];
                health0 = health_mob_w6;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                health_mob_w1 -= damage[i][j];
                health0 = health_mob_w6;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩7" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                kdd++;
                health_mob_w7 -= damage[i][j];
                health0 = health_mob_w7;
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                health_mob_w7 -= damage[i][j];
                health0 = health_mob_w7;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }
        } else if ("₩8" == map_mobs[i][j]) {
            if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2==0){
                kdd++;
                health_mob_w8 -= damage[i][j];
                health0 = health_mob_w8;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
            }else if((map[i+1][j]=="&") || (map[i-1][j]=="&") && kd[kdd]%2!=0){
                kdd++;
            }else{
                health_mob_w8 -= damage[i][j];
                health0 = health_mob_w8;
                if(health0 <= 0){
                    map_mobs[i][j] = ".";
                    map[i][j] = ".";
                    money += money_get;
                }
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

void spawnMob_f(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "_"){
                map[i][j-1] = "ƒ";
                map_mobs[i][j-1] =mobs_f[f];
                f++;
            }
        }
    }
}

void spawnMob_w(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "_"){
                map[i][j-1] = "₩";
                map_mobs[i][j-1] =mobs_W[W];
                W++;
            }
        }
    }
}

void moveMobs(string map[MAP_HEIGHT][MAP_WIDTH]){

    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if (map[i][j] == "ƒ"){
                int money_get = 25;
                if (map[i][j-1] == "."){
                    map[i][j-1] = "ƒ";
                    map_mobs[i][j-1] = map_mobs[i][j];
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    towerDamage(i,j-=1,map_mobs,map,money_get);
                }
                else if (map[i][j-1] == "|"){
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    ::health -= 1;
                }
            }
            if (map[i][j] == "₩"){
                int money_get = 75;
                if (map[i][j-1] == "."){
                    map[i][j-1] = "₩";
                    map_mobs[i][j-1] = map_mobs[i][j];
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    towerDamage(i,j-=1,map_mobs,map,money_get);
                }
                else if (map[i][j-1] == "|"){
                    map[i][j] = ".";
                    map_mobs[i][j] = ".";
                    ::health -= 2;
                }
            }
        }
    }
}

void findTowers(string map[MAP_HEIGHT][MAP_WIDTH]){
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            if(map[i][j] == "1"){
                t1y = i;
                t1x = j;
            }
            else if(map[i][j] == "2"){
                t2y = i;
                t2x = j;
            }
            else if(map[i][j] == "3"){
                t3y = i;
                t3x = j;
            }
            else if(map[i][j] == "4"){
                t4y = i;
                t4x = j;
            }
            else if(map[i][j] == "5"){
                t5y = i;
                t5x = j;
            }
        }
    }
}

void spawnTower(string map[MAP_HEIGHT][MAP_WIDTH], string place,string tower){
    if (place == "1" && map[t1y][t1x] == "1"){
        if (tower == "1"){
            map[t1y][t1x] = "@";
            damage[2][2]+=50;
            damage[2][3]+=50;
        }
        else if (tower == "2"){
            map[t1y][t1x] = "&";
            damage[2][2]+=150;
        }
    }
    else if (place == "2" && map[t2y][t2x] == "2"){
        if (tower == "1"){
            map[t2y][t2x] = "@";
            damage[2][2]+=50;
            damage[2][3]+=50;
            damage[2][4]+=50;
        }
        else if (tower == "2"){
            map[t2y][t2x] = "&";
            damage[2][3]+=150;
        }
    }
    else if (place == "3" && map[t3y][t3x] == "3"){
        if (tower == "1"){
            map[t3y][t3x] = "@";
            damage[2][3]+=50;
            damage[2][4]+=50;
            damage[2][5]+=50;
        }
        else if (tower == "2"){
            map[t3y][t3x] = "&";
            damage[2][4]+=150;
        }
    }
    else if (place == "4" && map[t4y][t4x] == "4"){
        if (tower == "1"){
            map[t4y][t4x] = "@";
            damage[2][4]+=50;
            damage[2][5]+=50;
            damage[2][6]+=50;
        }
        else if (tower == "2"){
            map[t4y][t4x] = "&";
            damage[2][5]+=150;
        }
    }
    else if (place == "5" && map[t5y][t5x] == "5"){
        if (tower == "1"){
            map[t5y][t5x] = "@";
            damage[2][5]+=50;
            damage[2][6]+=50;
            damage[2][7]+=50;
        }
        else if (tower == "2"){
            map[t5y][t5x] = "&";
            damage[2][6]+=150;
        }
    }
    else{
        cout << "Выбранное место занято или такого нету" << endl;
        if (tower == "1"){
            money += 100;
        }
        else if (tower == "2"){
            money += 250;
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

void game1_volna2(string map[MAP_HEIGHT][MAP_WIDTH]){
    string tower, towerPlace;
    for(int i =0; i<5;i++){
        clearConsole();
        moveMobs(map);
        printMap(map);
        spawnMob_w(map);

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
            cout << "2. Пушка = 200 монет" <<endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            if (tower == "1" && ::money >= 100){
                spawnTower(map,towerPlace, tower);
                money -= 100;
            }else if(tower == "2" && ::money >= 250) {
                spawnTower(map, towerPlace, tower);
                money -= 250;
            }else{
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
            cout << "2. Пушка = 200 монет" <<endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            if (tower == "1" && ::money >= 100){
                spawnTower(map,towerPlace, tower);
                money -= 100;
            }else if(tower == "2" && ::money >= 250) {
                spawnTower(map, towerPlace, tower);
                money -= 250;
            }else{
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

}

void runningGame(string map[MAP_HEIGHT][MAP_WIDTH]){
    full_health();
    string tower, towerPlace;
    ::money = 100;
    for(int i =0; i<5;i++){
        clearConsole();
        spawnMob_f(map);
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
            cout << "1. Огнемёт[@] = 100 монет" << endl;
            cout << "2. Пушка[&] = 200 монет" <<endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            if (tower == "1" && ::money >= 100){
                spawnTower(map,towerPlace, tower);
                money -= 100;
            }else if(tower == "2" && ::money >= 250) {
                spawnTower(map, towerPlace, tower);
                money -= 250;
            }else{
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
            cout << "1. Огнемёт[@] = 100 монет" << endl;
            cout << "2. Пушка[&] = 200 монет" <<endl;
            cout << endl << "Выберите башню:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            tower = ::input;
            cout << "Выберите номер места для башни:" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            towerPlace = ::input;
            if (tower == "1" && ::money >= 100){
                spawnTower(map,towerPlace, tower);
                money -= 100;
            }else if(tower == "2" && ::money >= 250) {
                spawnTower(map, towerPlace, tower);
                money -= 250;
            }else{
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
}

int main() {

    system("chcp 65001");
    string map[MAP_HEIGHT][MAP_WIDTH] = {
            {"#", "#","#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
            {"#"," ","1"," ","3"," ","5"," "," "," "," "," "," "," "," "," "," "," ","#"},
            {"†","|","." ,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","_"},
            {"#"," "," ","2"," ","4"," "," "," "," "," "," "," "," "," "," "," "," ","#"},
            {"#", "#","#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
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
            findTowers(map);
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