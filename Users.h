#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Users {
public:
    string userName, password;
    int numberIdUser;

    vector<Users> allUsers;
    vector <Users> transferUsersFromFile (vector <Users> &allUsers);
    void transferUsersFromVectorToFile(vector <Users> &allUsers);

    vector <Users> addUser (vector<Users> &allUsers);
    int singIn (vector<Users> &allUsers);
    vector <Users> changePassword (vector <Users> &allUsers, int numberIdUser);
};
