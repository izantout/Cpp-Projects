#include <iostream>
#include <string>

using namespace std;

// Prototypes
string choosing();
void RegorLog(string choice);

int main() {
  RegorLog(choosing());
}

void RegorLog(string choice){
  string firstName, lastName, Username, Password;
  if(choice == "REGISTER"){
    cout << "Please enter your first name: ";
    cin >> firstName;
    cout << "Please enter your last name: ";
    cin >> lastName;
    cout << "Please enter your desired username: ";
    cin >> Username;
    cout << "Please enter your desired password: ";
    cin >> Password;
    cout << "WELCOME " << Username << "!" << endl;
  }
  else if(choice == "LOGIN"){
    string regUsername = "Zantout18", regPassword = "HelloReader";
    bool flag = false;
    cout << "Please enter your username: ";
    cin >> Username;
    cout << "Please enter your password: ";
    cin >> Password;
    while(!flag){
      if(Username == regUsername && Password == regPassword){
        cout << "WELCOME " << Username << "!" << endl;
        flag = true;
      }
      else if(Username != regUsername || Password != regPassword){
        cout << "Username or Password do not match. Please try again! " << endl;
        cout << "Please enter your username: ";
        cin >> Username;
        cout << "Please enter your password: ";
        cin >> Password;
      }
      else{
        cout << "ERROR 404 PAGE NOT FOUND" << endl;
        flag = true;
      }
    }
  }
  else{
    cout << "ERROR 404 PAGE NOT FOUND" << endl;
  }
}

string choosing(){
  bool flag = false;
  string final = "";
  char choice;
  cout << "Would you like to Register or Login? (R for register or L for login): ";
  cin >> choice;
  while(!flag){  
    if(toupper(choice) == 'R'){
      final = "REGISTER";
      cout << final << endl;
      flag = true;
    }
    else if (toupper(choice) == 'L'){
      final = "LOGIN";
      cout << final << endl;
      flag = true;
    }
    else{
      cout << "Invalid selection, please try again! ";
      cin >> choice;
    }
  }
  return final;
}
