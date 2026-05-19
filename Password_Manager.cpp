#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "BSTree/BSTree.h"
#include "App/app.h"
#include "User/user.h"
#include "Sort_Search_algo/sort_search_algo.h"
using namespace std;

class Password_Manager
{
private:
    BSTree userTree;
    user user1;
    app app1;

public:
    Password_Manager()
    {

        string realAppNames[100] = {
            "YouTube", "Facebook", "Instagram", "WhatsApp", "TikTok", "Snapchat", "Twitter", "LinkedIn", "Pinterest", "Reddit",
            "Spotify", "Netflix", "Hulu", "AmazonPrime", "DisneyPlus", "Twitch", "Discord", "Slack", "Zoom", "MicrosoftTeams",
            "GoogleDrive", "Dropbox", "OneDrive", "ICloud", "Gmail", "Outlook", "YahooMail", "ProtonMail", "Uber", "Lyft",
            "Airbnb", "BookingCom", "TripAdvisor", "Expedia", "GoogleMaps", "AppleMaps", "Waze", "Yelp", "Shazam", "SoundCloud",
            "Pandora", "Tidal", "Deezer", "Audible", "Kindle", "Wattpad", "Goodreads", "Duolingo", "Coursera", "Udemy",
            "KhanAcademy", "Quizlet", "Evernote", "Notion", "Trello", "Asana", "MondayCom", "Todoist", "TickTick", "GoogleKeep",
            "AdobePhotoshop", "Lightroom", "Canva", "PicsArt", "Figma", "Sketch", "Procreate", "CapCut", "IMovie", "TikTokStudio",
            "PayPal", "Venmo", "CashApp", "Zelle", "Revolut", "Wise", "Robinhood", "Coinbase", "Binance", "Webull",
            "Steam", "EpicGames", "DiscordApp", "PlayStationApp", "XboxApp", "NintendoSwitch", "TwitchTv", "Minecraft", "Roblox", "PokemonGo",
            "Tinder", "Bumble", "Hinge", "Grindr", "OkCupid", "Strava", "Fitbit", "MyFitnessPal", "Headspace", "Calm"};

        userTree.insert(user("george ashraf", "123456"));
        userTree.insert(user("dr.ahmed magdy hassan", "654321"));
        userTree.insert(user("eng.abdallah aboghaly", "112233"));
        userTree.insert(user("mr.ahmed magdy amen", "000000"));
        userTree.insert(user("abdo ismail", "111111"));

        for (size_t i = 0; i < 100; i++)
        {
            user1.insertApp(app(realAppNames[i], "", ""));
        }
    }

    string handleUserInput()
    {
        string input;
        getline(cin, input);
        return input;
    }

    int handleMenuSelection()
    {
        int input;
        while (!(std::cin >> input))
        {
            cout << "Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n');
        return input;
    }

    void login()
    {
        cout << "\t\t Password Manager \t\t\n\n";
        cout << "Username: ";
        user1.insertName(handleUserInput());
        cout << '\n';
        cout << "password: ";
        user1.insertPass(handleUserInput());
        cout << '\n';
        bool found = userTree.search(user1);
        if (!found)
        {
            userTree.insert(user1);
            cout << "New user is added...\n";
        }
        else if (userTree.validate(user1))
        {
            cout << "Login successful!\n";
        }
        else
        {
            cout << "Incorrect password. Retry...\n\n";
            login();
        }

        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
    }

    void showPasswords()
    {
        user1.displayApps();
        cout << "type \"return\" to return back to main menu: ";
        string input = handleUserInput();
        for (char &c : input)
        {
            c = tolower(c);
        }

        while (input != "return")
        {
            cout << "PLEASE TYPE \"RETURN\": ";
            input = handleUserInput();
            for (char &c : input)
            {
                c = tolower(c);
            }
        }
    }

    void addPassword()
    {
        system("cls");
        string randompass;

        cout << "\t\t Password Manager \t\t\n\n";
        cout << "App Name: ";
        app1.insertAppName(handleUserInput());
        cout << '\n';
        cout << "Username: ";
        app1.insertUserName(handleUserInput());
        cout << '\n';
        cout << "Do you want to generate a strong password?\nChoose Yes or No: ";
        getline(cin, randompass);

        for (char &c : randompass)
        {
            c = tolower(c);
        }

        while (randompass != "yes" && randompass != "no")
        {
            cout << "Please choose YES or NO!\n";
            cout << "Do you want to generate a strong password?\nChoose Yes or No: ";
            getline(cin, randompass);

            for (char &c : randompass)
            {
                c = tolower(c);
            }
        }

        if (randompass == "yes")
        {
            int size;
            cout << "Choose the size of your password NOT LESS THAN 8\n";
            cout << "Size: ";
            cin >> size;
            cin.ignore(1000, '\n');
            while (size < 8)
            {
                cout << "password NOT LESS THAN 8\n";
                cout << "Size: ";
                cin >> size;
                cin.ignore(1000, '\n');
            }

            app1.insertRandomPass(size);
        }
        else
        {
            cout << "Write your password manual\n";
            cout << "Password: ";
            app1.insertPass(handleUserInput());
            cout << '\n';
        }
        cout << "Data is saved...\n";
        user1.insertApp(app1);
    }

    void homeMenu()
    {
        cout << "\t\t Password Manager \t\t\n\n";
        cout << "1- show Password\n";
        cout << "2- Add Password\n";
        cout << "3- Edit Password\n";
        cout << "4- Delete Password\n";
        cout << "5- Sort Apps\n";
        cout << "6- Search App\n";
        cout << "7- Which sorting algorithm is better?\n";
        cout << "8- Which searching algorithm is better?\n";
        cout << "9- Sign out\n";
        cout << "0- Exit\n\n";
    }

    void home()
    {
        homeMenu();
        cout << "Choose an index: ";
        int input = handleMenuSelection();
        string target;
        switch (input)
        {
        case 1:
            showPasswords();
            system("cls");
            return home();
        case 2:
            addPassword();
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return home();
        case 3:
            user1.editApp();
            system("cls");
            return home();
        case 4:
            user1.deleteApp();
            system("cls");
            return home();
        case 5:
            user1.Sort();
            cout << "Sorting is done..\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return home();
        case 6:
            cout << "What do you want to search for?\nEnter a App name: ";
            target = handleUserInput();
            user1.Search(target);
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return home();
        case 7:
            user1.whichSortBetter();
            this_thread::sleep_for(chrono::seconds(5));
            system("cls");
            return home();
        case 8:
            cout << "What do you want to search for?\nEnter a App name: ";
            target = handleUserInput();
            user1.whichSearchBetter(target);
            this_thread::sleep_for(chrono::seconds(5));
            system("cls");
            return home();
        case 9:
            login();
            system("cls");
            return home();
        case 0:
            cout << "\nExiting program. Goodbye!\n";
            this_thread::sleep_for(chrono::seconds(2));
            exit(0);
        default:
            cout << "Please choose from 0 to 5\n\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return home();
        }
    }

    void run()
    {
        login();
        home();
    }
};

int main()
{
    Password_Manager().run();

    return 0;
}