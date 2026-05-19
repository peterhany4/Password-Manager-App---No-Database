#ifndef APP_H
#define APP_H
#include <string>
using namespace std;

class app
{
private:
    string app_name;
    string user_name;
    string pass_w;

public:
    app();
    app(string app_name, string user_name, string pass_w);
    void insert(string app_name, string user_name, string pass_w);
    void insertAppName(string app_name);
    void insertUserName(string user_name);
    void insertPass(string pass_w);
    void insertRandomPass(int _size);
    std::string getAppName();
    std::string getUserName();
    std::string getPass();
};

#endif
