#include <iostream>
#include <fstream>
using namespace std;

struct Manager
{

    string website;
    string username;
    string password;
    string Category;
    string search_name;
    string new_password;
};

void add_password(Manager a)
{

    cout << "============== Add New Password ===============" << endl;

    cout << endl;
    cout << "Enter your website = ";
    cin >> a.website;
    cout << endl;
    cout << "Enter your username = ";
    cin >> a.username;
    cout << endl;
    cout << "Enter your password = ";
    cin >> a.password;
    cout << endl;
    cout << "Enter your Category = ";
    cin >> a.Category;
    cout << endl;

    fstream file;

    file.open("file.txt", ios::app);
    file << a.website << endl;
    file << a.username << endl;
    file << a.password << endl;
    file << a.Category << endl;
    file.close();
    cout << "password saved successfully" << endl;
    cout << endl;
}

void all_password(Manager b)
{

    cout << "============== View All Password ===============" << endl;
    cout << endl;
    fstream file;
    file.open("file.txt");
    while (getline(file, b.website))
    {
        cout << "website :" << b.website << endl;
        getline(file, b.username);
        cout << "username :" << b.username << endl;
        getline(file, b.password);
        cout << "Password :" << b.password << endl;
        getline(file, b.Category);
        cout << "Category :" << b.Category;
        cout << endl;
        cout << "-------------------------";
        cout << endl;
    }

    file.close();
}

void search_password(Manager c)
{

    cout << endl;
    cout << "============== Search Password ===============" << endl;

    fstream file;
    file.open("file.txt");

    cout << "Enter your website name: ";
    cin >> c.search_name;

    while (file >> c.website)
    {
        file >> c.username;
        file >> c.password;
        file >> c.Category;

        if (c.search_name == c.website)
        {

            cout << "website :" << c.website << endl;
            cout << "username:" << c.username << endl;
            cout << "password :" << c.password << endl;
            cout << "category :" << c.Category << endl;
        }
    }

    file.close();
}

void update_password(Manager d)
{
    cout << "===================== Update Password ========================" << endl;
    cout << "search_name = ";
    cin >> d.search_name;

    fstream file("file.txt");
    ofstream temp("temp.txt");

    while (file >> d.website)
    {
        file >> d.username;
        file >> d.password;
        file >> d.Category;

        if (d.search_name == d.website)
        {
            cout << "new password = ";
            cin >> d.new_password;

            d.password = d.new_password;
        }

        temp << d.website << endl;
        temp << d.username << endl;
        temp << d.password << endl;
        temp << d.Category << endl;
    }

    file.close();
    temp.close();

    remove("file.txt");
    rename("temp.txt", "file.txt");

    cout << "Password updated successfully" << endl;
}

void delete_password(Manager e)
{

    string permission;
    cout << "Are you sure you want to delete this password?";
    cin >> permission;

    if (permission == "yes")
    {

        cout << "===================== Delete Password ========================" << endl;

        cout << "search_name: ";
        cin >> e.search_name;

        fstream file("file.txt");

        ofstream temp("temp.txt");

        while (file >> e.website)
        {
            file >> e.username;
            file >> e.password;
            file >> e.Category;

            if (e.search_name == e.website)
            {

                e.password = "";

                e.new_password = e.password;
            }

            temp << e.website << endl;
            temp << e.username << endl;
            temp << e.password << endl;
            temp << e.Category << endl;
        }

        file.close();
        temp.close();

        remove("file.txt");
        rename("temp.txt", "file.txt");
        cout << "Password delete successfully" << endl;
    }
}

void exit()
{
    cout << endl;
    cout << "Thank you for using Password Manager!";
}

int main()
{
    int choice;
    Manager a;

    while (1)
    {
        cout << "===================================================" << endl;
        cout << "----------------Password Manager------------------" << endl;
        cout << "===================================================" << endl;
        cout << endl;

        cout << "1. Add New Password" << endl;
        cout << "2. View All Passwords" << endl;
        cout << "3. Search Password" << endl;
        cout << "4. Update Password" << endl;
        cout << "5. Delete Password " << endl;
        cout << "6.Exit " << endl;

        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                add_password(a);
                break;
            case 2:
                all_password(a);
                break;
            case 3:
                search_password(a);
                break;
            case 4:
                update_password(a);
                break;
            case 5:
                delete_password(a);
                break;

            case 6:
                exit();
                return 0;
            default:
                break;
        }
    }
    return 0;
}