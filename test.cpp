#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User
{
    private:
        string username, password;
    
    public:
        User(string name, string pass)
        {
            username = name;
            password = pass;
        }
        string getUsername(){
            return username;
        }
        string getPassword(){
            return password;
        }
};

class UserManager
{
    private:
        vector<User> users;
    
    public:
        void RegisterUser(){
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            User newUser(username, password);
            users.push_back(newUser);

            cout << "\t\t ---User Register done---" << endl;
        }
        bool LoginUser(string name, string pass){
            for(int i = 0; i < users.size(); i++)
                if(users[i].getUsername() == name && users[i].getPassword() == pass)
                {
                    cout << "---Login Successfully---" << endl;
                    return true;
                }
            cout << "invalid username or password..." << endl;
            return false;
        }
};


main(){
    UserManager usermanager;

    int op;
    char choice;
    do
    {
    cout << "(1) Register user" << endl;
    cout << "(2) Login" << endl;
    cout << "(3) Show user list" << endl;
    cout << "(4) Search user" << endl;
    cout << "(5) Delete user" << endl;
    cout << "(6) exit" << endl;
    cout << "Enter your choice: ";
    cin >> op;
    switch(op){
        case 1:
            usermanager.RegisterUser();
            break;
        case 2:
            string username, password;
            cout << "Enter user: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            usermanager.LoginUser(username, password);
            break;
    }
    cout << "Do you want to continue? (y / n): ";
    cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}