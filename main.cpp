#include <fstream>
#include <iostream>
#include <regex>
using namespace std;

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
// TODO: If your Windows machine runs Python in CLI with "python" instead of "py", update this line.
const string python = "python";
#else
// TODO: If your Mac/Linux machine runs Python in CLI with "python3" instead of "python", update this line.
const string python = "python";
#endif

/*
 * Prompts the user for a filename.
 * Allows the user to enter nothing to use the default pic (autumn.jpg).
 * If the file has extension jpg, jpeg, jpe, or png
 * and it exists in the project folder, return it.
 * Otherwise, return the default pic filename.
 */
string get_filename();

/*
 * Prints the main menu of options:
 * (a) flip, (b) mirror, (c) invert, or (d) exit
 */
void print_menu();

/*
 * Prompts the user for one of the options from the menu.
 * Validates input: makes sure the user enters exactly one character
 * and that it is one of the four valid options.
 * If it isn't valid, keep prompting for input until a valid option
 * is entered.
 */
char get_manip_choice();

int main() {
    cout << "Welcome to the image manipulator!" << endl;
    string filename = get_filename();
    cout << "Using file " << filename << "." << endl;
    print_menu();
    char choice = get_manip_choice();
    cout << "Processing. Go to Python program when it opens. May take a few seconds." << endl;
    string command;
    switch (choice) {
        // Use command-line arguments to pass the filename and manip to the Python file
        case 'a': command = python + " render.py " + filename + " flip";
            break;
        case 'b': command = python + " render.py " + filename + " mirror";
            break;
        case 'c': command = python + " render.py " + filename + " invert";
            break;
    }
    system(command.c_str());
    return 0;
}

string get_filename() {
    cout << "Enter a valid jpeg filename in your current folder: " << endl;
    string userInput;
    cin >> userInput;
    const regex pattern("[^\\s]+(.*?)\\.(jpg|jpeg|jpe|png|JPG|JPEG|PNG)$");

    ifstream inputFile(userInput);

    if(regex_match(userInput, pattern) && inputFile.is_open()) {
        inputFile.close();
        return userInput;
    }
    else {
        return "autumn.jpg";
    }
}

void print_menu() {
    cout << "(a) flip" << endl;
    cout << "(b) mirror" << endl;
    cout << "(c) invert" << endl;
    cout << "(d) exit" << endl;
}

char get_manip_choice() {
    string input;
    char output;
    stringstream ss;
    cout << "please enter an option (a, b, c, d): " << endl;
    while(true) {
        getline(cin, input);
        ss << input;
        // Check to see if input length is 1, i.e. only a character.
        if(input.length() == 1) {
            ss >> output;
            output = (char)tolower(output);
            // check to see if input is a,b,c,d
            if(output == 'a' || output == 'b' || output == 'c' || output == 'd'){
                return output;
                break;
            } 
            else {
                cout << "you entered a character, just not the right one, try again: " << endl;
            }
        }
        // Check to see if there is no input.
        else if(input.length() < 1){
            cout << "No input, please enter a character: " << endl;
        }
        // If neither of these are true keep the loop going.
        else {
            cout << "Invalid input, please enter a character: " << endl;
        }
        ss.str("");
    }
    return output;

} 
