#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>  // for reading files
#include <sstream>  // for splitting strings

using namespace std;

int main() 
{
    string serverPath = "server.jar"; //Used if the config file is missing

    int ram = 2; //set RAM to 2G if the config file is missing
    int minRam = 1; //set min RAM to 1G if the config file is missing

    ifstream configFile("config.txt"); //Reads the config file
    string line;

    while (getline(configFile, line))
    {
        stringstream ss(line);
        string key, value;

        getline(ss, key, '='); //read up to the =
        getline(ss, value); //read the rest

        if (key == "ram") ram = stoi(value);
        if (key == "min_ram") minRam = stoi(value);
        if (key == "server_path") serverPath = value;
    }

    configFile.close();

    int choice;

    while (true) 
    {
        cout << "=== Minecraft Server Manager ===" << endl << endl;

        cout << "1. Start Server" << endl;
        cout << "2. Stop Server" << endl;
        cout << "3. Backup Server" << endl;
        cout << "4. View Player Count" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Starting server..." << endl;
    
            string command = "java -Xmx" + to_string(ram) + "G -Xms" + to_string(minRam) + "G -jar " + serverPath + " nogui";
            system(command.c_str());
    
            cout << "Server stopped." << endl;
        }
        else if (choice == 2)
        {

        }
        else if (choice == 3)
        {

        }
        else if (choice == 4)
        {

        }
        else if (choice == 5)
        {
            cout << "Goodbye!" << endl;
            
            break;
        }  
        else
        {
            cout << "Selection invalid. Please make a valid selection.";
        }
    }
    return 0;
}