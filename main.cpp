#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <stdlib.h>


using namespace std;

class User{
    string userName;
    string userPassword;

public:
    // Konstruktor
    User(string &name, string &password)
        : userName(name), userPassword(password){}

    // Getter för username
    string getUserName(){
        return userName;

    }

    // Kontrollerar ifall lösenordet stämemer
    bool controllPassword(string &password){
        return userPassword == password;

        
    }
    
};

string md5(const std::string &str){
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  stringstream ss;

  for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}


// Välkomnar usern och visar menyn
void showMenu(){
  cout << "Välkommen!\n";
  cout << "Vänligen välj ett alternativ\n";
  cout << "1. Skapa användare\n";
  cout << "2. Test login\n"; 
  cout << "Action: ";

}

// Funktionen skapar användaren
void createUser(){
  cout << "****************************\n";
  cout << "      SKAPA ANVÄNDARE       \n";


string username, password;
// Lamba bestämmer @ som en char
  auto snabelA = [](char c){
    return c == '@';
  };

  while(true){
  cout << "Skriv in din mailadress: \n";
  cin >> username;

    // Letar efter om username har lagt till @ annars ge felmeddalen
    if(find_if(username.begin(), username.end(), snabelA) !=username.end()){
      break;
    } else{
      
      cout << "Ogiltigt användarnamn: Måste innehålla @!\n";
    }
  }

  while(true){

    // Fixa lösenordet 
     cout << "Skriv in ditt lösenord\n";
     cin >> password;

      
     int charCount = count_if(password.begin(), password.end(),
                             [](char c){
                              return true;
                              });
        if(charCount >= 8 ){
          break;
        }else{
          cout << "ogilitg\n";
        }
  }


  
} 





int main(int, char**){

    int option;
    string username, password;
    
    while(true){
    showMenu();
    cin >> option;

    // Rensar terminalen
    system("clear");
      switch (option){
      case 1:
        createUser();
        break;
      
      default:
        break;
      }

      }

    // string theHash = md5("Google");
    // cout << theHash << endl;



return 0;

}

