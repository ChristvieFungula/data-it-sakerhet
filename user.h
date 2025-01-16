#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User{
    string userName;
    string userPassword;

public:
    // Konstruktor
    User(string &username, string &password)
        : userName(username), userPassword(password){}

    // Getter för username
    string getUserName(){
        return userName;

    }

    // Kontrollerar ifall lösenordet stämemer
    bool controllPassword(string &password){
        return userPassword == password;
    }
    
};
#endif