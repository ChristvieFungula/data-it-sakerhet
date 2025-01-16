#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "user.h"
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>

using namespace std;

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
}

// Skapar användaren
void createUser(){

}





int main(int, char**){
    //showMenu();
    string theHash = md5("hejsan123");
    cout << theHash << endl;



return 0;

}

