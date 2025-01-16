#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class User{
    string userName;
    string userPassword;

public:
    // Konstruktor
    User(const string &username, const string &password)
        : userName(username), userPassword(password){}

    // Getter för username
    string getUserName(){
        return userName;
    }

    
};

void showMenu(){
    cout << "Välkommen!\n";
    cout << "Välj följande alternativ: \n";
    cout << "1. Skapa användare\n";
    cout << "2. Test login in\n";
}





int main(){
showMenu();





return 0;

}

