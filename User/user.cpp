#include <iostream>
#include <iomanip>
#include "user.h"
#include "../App/app.h"
#include "../Sort_Search_algo/sort_search_algo.h"
using namespace std;

user::user()
{
    user::user_name = "";
    user::pass_w = "";
}
user::user(string user_name, string pass_w)
{
    user::user_name = user_name;
    user::pass_w = pass_w;
}
void user::insert(string user_name, string pass_w)
{
    user::user_name = user_name;
    user::pass_w = pass_w;
}

void user::insertName(string user_name)
{
    user::user_name = user_name;
}
void user::insertPass(string pass_w)
{
    user::pass_w = pass_w;
}

void user::insertApp(app app1)
{
    user::apps.push_back(app1);
}

void user::displayApps()
{
    if (user::apps.size() == 0)
    {
        cout << "No passwords are found...\n\n";
    }

    int i = 0;

    for (app &a : user::apps)
    {
        cout << "-" << i++ << " " << "App: " << a.getAppName() << "| User Name: " << a.getUserName() << " | Password: " << a.getPass() << "\n\n";
    }
}

void user::editApp()
{
    int i = 0;

    for (app a : apps)
    {
        cout << "-" << i++ << " " << a.getAppName() << '\n';
    }

    int choice = 0;
    string newpass;

    cout << "Choose from 0 to " << i - 1 << " : ";
    cin >> choice;
    cin.ignore(1000, '\n');

    cout << "Change the password for: " << apps[choice].getAppName() << '\n';
    cout << "Do you want to generate a strong password?\nChoose Yes or No: ";
    getline(cin, newpass);

    for (char &c : newpass)
    {
        c = tolower(c);
    }

    while (newpass != "yes" && newpass != "no")
    {
        cout << "Please choose YES or NO!\n";
        cout << "Do you want to generate a strong password?\nChoose Yes or No: ";
        getline(cin, newpass);

        for (char &c : newpass)
        {
            c = tolower(c);
        }
    }

    if (newpass == "yes")
    {
        int size;
        cout << "Choose the size of your password NOT LESS THAN 8\n";
        cout << "Size: ";
        cin >> size;
        cin.ignore(1000, '\n');
        apps[choice].insertRandomPass(size);
    }
    else
    {
        cout << "Write your password manual\n";
        cout << "new password: ";
        getline(cin, newpass);

        apps[choice].insertPass(newpass);

        cout << "Password has been updated!\n\n";
    }
}

void user::deleteApp()
{
    int i = 0;

    for (app a : apps)
    {
        cout << "-" << i++ << " " << a.getAppName() << '\n';
    }

    int choice = 0;
    cout << "Choose from 0 to " << i << " : ";
    cin >> choice;
    cin.ignore(1000, '\n');

    apps.erase(apps.begin() + choice);

    cout << "Password has been Removed!\n\n";
}

void user::whichSortBetter()
{

    if (apps.size() == 0)
    {
        cout << "no Apps are found\n";
        return;
    }

    double start_time_1 = get_cpu_time_ms();

    for (size_t i = 0; i < 1000; i++)
    {
        vector<app> a = apps;
        mergeSort(a, 0, a.size() - 1);
    }

    double end_time_1 = get_cpu_time_ms();
    double cpu_time_ms_1 = end_time_1 - start_time_1;

    cout << "\t\t Merge Sort \t\t\n";
    cout << fixed << setprecision(8);
    cout << "CPU Time: " << cpu_time_ms_1 << " ms\n";

    double start_time_2 = get_cpu_time_ms();

    for (size_t i = 0; i < 1000; i++)
    {
        vector<app> b = apps;
        quickSort(b, 0, b.size() - 1);
    }

    double end_time_2 = get_cpu_time_ms();
    double cpu_time_ms_2 = end_time_2 - start_time_2;

    cout << "\t\t Quick Sort \t\t\n";
    cout << "CPU Time: " << cpu_time_ms_2 << " ms\n";

    if (cpu_time_ms_1 < cpu_time_ms_2)
    {
        cout << "Merge sort is FASTER!!!\n";
    }
    else
    {
        cout << "Quick sort is FASTER!!!\n";
    }
}

void user::whichSearchBetter(string _target)
{
    if (apps.empty())
        return;

    const int RUNS = 10000;

    vector<app> b = apps;
    quickSort(b, 0, b.size() - 1);

    // LINEAR SEARCH
    double start_time_1 = get_cpu_time_ms();

    for (int i = 0; i < RUNS; i++)
    {
        linearSearch(apps, _target);
    }

    double end_time_1 = get_cpu_time_ms();
    double cpu_time_ms_1 = end_time_1 - start_time_1;

    // BINARY SEARCH
    double start_time_2 = get_cpu_time_ms();

    for (int i = 0; i < RUNS; i++)
    {
        binarySearch(b, _target);
    }

    double end_time_2 = get_cpu_time_ms();
    double cpu_time_ms_2 = end_time_2 - start_time_2;

    // SENTINEL SEARCH
    double start_time_3 = get_cpu_time_ms();

    for (int i = 0; i < RUNS; i++)
    {
        sentinelLinearSearch(apps, apps.size(), _target);
    }

    double end_time_3 = get_cpu_time_ms();
    double cpu_time_ms_3 = end_time_3 - start_time_3;

    cout << fixed << setprecision(8);

    cout << "\n\t\t Linear Search\n";
    cout << "CPU Time: " << cpu_time_ms_1 << " ms\n";

    cout << "\n\t\t Binary Search\n";
    cout << "CPU Time: " << cpu_time_ms_2 << " ms\n";

    cout << "\n\t\t Sentinel Linear Search\n";
    cout << "CPU Time: " << cpu_time_ms_3 << " ms\n";

    double fastest = min(min(cpu_time_ms_1, cpu_time_ms_2), cpu_time_ms_3);

    if (fastest == cpu_time_ms_1)
    {
        cout << "\nLinear search is the fastest\n";
    }
    else if (fastest == cpu_time_ms_2)
    {
        cout << "\nBinary search is the fastest\n";
    }
    else
    {
        cout << "\nSentinel linear search is the fastest\n";
    }

    if (binarySearch(b, _target) != -1)
    {
        cout << "\nFound: " << _target << '\n';
    }
    else
    {
        cout << "\n"
             << _target << " Not Found\n";
    }
}

void user::Sort()
{
    if (apps.empty())
        return;

    quickSort(apps, 0, apps.size() - 1);
}

void user::Search(string _target)
{
    if (apps.empty())
    {
        cout << "no Apps found to search\n";
        return;
    }

    Sort();

    int found = binarySearch(apps, _target);
    if (found == -1)
    {
        cout << _target << " Does not exist\n";
    }
    else
    {
        cout << _target << "is at index: " << found << '\n';
    }
}

string user::getUser()
{
    return user::user_name;
}
string user::getPass()
{
    return user::pass_w;
}