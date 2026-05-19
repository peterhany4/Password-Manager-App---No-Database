#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "../App/app.h"
using namespace std;

class user
{
private:
    string user_name;
    string pass_w;
    vector<app> apps;

public:
    user();
    user(string user_name, string pass_w);
    void insert(string user_name, string pass_w);
    void insertName(string user_name);
    void insertPass(string pass_w);
    void insertApp(app app1);
    void editApp();
    void deleteApp();
    void displayApps();
    void whichSortBetter();
    void whichSearchBetter(string _target);
    void Sort();
    void Search(string _target);
    string getUser();
    string getPass();
};

#endif
