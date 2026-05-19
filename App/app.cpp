#include <iostream>
#include <random>
#include <algorithm>
#include "app.h"
using namespace std;

app::app()
{
    app::app_name = "";
    app::user_name = "";
    app::pass_w = "";
}
app::app(string app_name, string user_name, string pass_w)
{
    app::app_name = app_name;
    app::user_name = user_name;
    app::pass_w = pass_w;
}
void app::insert(string app_name, string user_name, string pass_w)
{
    app::app_name = app_name;
    app::user_name = user_name;
    app::pass_w = pass_w;
}

void app::insertAppName(string app_name)
{
    app::app_name = app_name;
}
void app::insertUserName(string user_name)
{
    app::user_name = user_name;
}
void app::insertPass(string pass_w)
{
    app::pass_w = pass_w;
}

void app::insertRandomPass(int _size)
{
    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string symbols = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    string all = lowerCase + upperCase + numbers + symbols;

    string password = "";
    password += lowerCase[rand() % lowerCase.length()];
    password += upperCase[rand() % upperCase.length()];
    password += numbers[rand() % numbers.length()];
    password += symbols[rand() % symbols.length()];

    for (size_t i = 4; i < _size; i++)
    {
        password += all[rand() % all.length()];
    }

    random_shuffle(password.begin(), password.end());

    pass_w = password;

    cout << "Your Password is: " << password << '\n';
}

string app::getAppName()
{
    return app::app_name;
}
string app::getUserName()
{
    return app::user_name;
}
string app::getPass()
{
    return app::pass_w;
}