#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <stdlib.h>
#include <regex>


using namespace std;

class User{
    string userName;
    string userPassword;

public:
    User(string &name, string &password)
        : userName(name), userPassword(password){}

    string getUserName(){
        return userName;

    }

    bool controllPassword(string &password){
        return userPassword == password;

        
    }
    
};

vector<User> users;

string md5(const string &str){
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  stringstream ss;

  for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
    ss << hex << setw(2) << setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}


void showMenu(){
  cout << "Välkommen!\n";
  cout << "Vänligen välj ett alternativ\n";
  cout << "1. Skapa användare\n";
  cout << "2. Test login\n"; 
  cout << "Action: ";

}
void saveToUserFile(const string &username, const string &hashPassword){
  ofstream file("user.txt", ios::app);
    if(file){
      file << username << " : " << hashPassword << "\n";
      file.close();
    }
  
}

bool usernameExists(const string &username) {
    ifstream file("user.txt");
    string line;

    if (!file) return false;

    while (getline(file, line)) {
        if (line.find(username + " : ") == 0) {
            return true;
        }
    }
    return false;
}

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
    if(find_if(username.begin(), username.end(), snabelA) ==username.end()){
      cout << "Ogiltigt användarnamnet: Måste innehålla @!\n";
      continue;
    }
    
    if(usernameExists(username)){
      cout << "Användarnamnet är redan upptaget. Vänligen välj ett annat.\n";
    }else{
      break;
    }
  }
  

  while(true){

     cout << "Skriv in ditt lösenord\n";
     cin >> password;

          regex upperCase{ "[A-Z]+" }; //here is the very simple expression for upper_case search
          regex lowerCase{ "[a-z]+" }; //for lower-case
          regex number{ "[0-9]+" }; //...
          regex specialChar{ "[@!?]+"};

        if(password.length() >= 8 &&
            regex_search(password, upperCase) &&
            regex_search(password, lowerCase) &&
            regex_search(password, number) &&
            regex_search(password, specialChar)){
            break;

        }else{
          cout << "Lösenordet måste inne hålla:\nMinst 8 karaktärer.\nMinst 1 stor bokstav.\nMinst 1 liten bokstav.\nMinst 1 siffra. \nMinst 1 specialtecken. \n";
        }
  }

      string hashPassword = md5(password);
      saveToUserFile(username, hashPassword);
      cout << "Användare skapad!\n\n"
} 

void testLogin(){
  cout << "****************************\n";
  cout << "         TEST LOGIN         \n";

  string username, password, line;

  cout << "Användarnamn: ";
  cin >> username;
  cout << "Lösenord: ";
  cin >> password;

  string hashedPassword = md5(password);
  ifstream file("user.txt");

  bool loginSucces = false;
   while(getline(file, line)){
    if(line == username + " : " + hashedPassword){
      loginSucces = true;
      break;
    }
   }

  file.close();
    if(loginSucces){
      cout << "Inloggningen lyckades\n\n";
    }else{
      cout << "Fel användarnamn eller lösenord\n\n";
    }


}





int main(int, char**){

    int option;
  
    
    while(true){
     showMenu();
     cin >> option;
     // Rensar terminalen
    //  system("clear");
     switch (option){
     case 1:
       createUser();
       break;
     case 2:
      testLogin();
      break;

     default:
      cout << "Ogiltigt val! \n"
       break;
     
     }
    }
    //  string theHash = md5("");
    //  cout << theHash << endl;



return 0;

}

