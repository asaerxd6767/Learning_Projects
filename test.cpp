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
                    cout << "\t\t---Login Successfully---" << endl;
                    return true;
                }
            cout << "\t\t---invalid username or password---" << endl;
            return false;
        }
        void ShowUser(){
            cout << "---Users List---" << endl;
            for(int i = 0; i < users.size(); i++)
                cout << i + 1 << ". " << users[i].getUsername() << endl;
        }
        void SearchUser(string username){
            for(int i = 0; i < users.size(); i++)
                if(users[i].getUsername() == username)
                {
                    cout << "\t\t---User Found---" << endl;
                    return;
                }
                else if(i == users.size() - 1)
                    cout << "\t\t---User is not found---" << endl;
        }
        void DeleteUser(string username){
            for(int i = 0; i < users.size(); i++)
                if(users[i].getUsername() == username)
                {
                    users.erase(users.begin() + i);
                    cout << "\t\t---User is deleted---" << endl;
                    return;
                }
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
        {
            usermanager.RegisterUser();
            break;
        }
        case 2:
        {
            string username, password;
            cout << "Enter user: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            usermanager.LoginUser(username, password);
            break;
        }
        case 3:
        {
            usermanager.ShowUser();
            break;
        }
        case 4:
        {
            string username;
            cout << "Enter User: ";
            cin >> username;
            usermanager.SearchUser(username);
            break;
        }
        case 5:
        {
            string username;
            cout << "Enter User: ";
            cin >> username;
            usermanager.DeleteUser(username);
            break;
        }
        case 6:
            exit(1);
    }
    cout << "Do you want to continue? (y / n): ";
    cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}