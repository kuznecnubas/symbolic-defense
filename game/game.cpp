#include <iostream>

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
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

using namespace std;

int main() {
    system("chcp 65001");
    system("clear");
    system("cls");
    string a;
    while(true) {
        cout << "Символьная оборона" << endl;
        cout<< "Сюжет: В мире, где символы обрели силу и стали живыми существами, зловещие коды угрожают всему цифровому королевству. Вы - последний защитник, контролирующий мощные символьные башни, способные отражать атаки зловредных кодов. Ваша миссия - предотвратить вторжение и спасти мир от цифрового хаоса."<< endl;
        cout<<"Главное меню";

        cout<<"Для выхода из игры введите - exit"<<endl;
        if(a=="exit") return 0;

        std::cout << RED << "Этот текст будет красным." << std::endl;
        std::cout << BG_GREEN << "Этот текст будет с зеленым фоном." << BG_RESET << std::endl;
        std::cin >> a;

    }
}
