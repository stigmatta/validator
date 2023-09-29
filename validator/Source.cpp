#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool html_validator(const char* path, int& errors) {
    ifstream in(path, ios::in);
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (line.empty()) {
                continue;
            }
            else
            {
                char open = ' ', closed = ' ';
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] == '<' && open != '<')
                        open = line[i];
                    else if (line[i] == '>' && closed != '>')
                        closed = line[i];
                    else if (line[i] == '<' && open == '<' || line[i] == '>' && closed == '>')
                        errors++;
                    if (open == '<' && closed == '>')
                        open = closed = ' ';
                   
                }
                if (open != ' ' && closed == ' '||open==' '&&closed!=' ')
                    errors++;
                open = closed = ' ';
            }
        }
        in.close();
    }
    else 
        cout << "Error" <<endl;
    if (!errors)
        return true;
    return false;
}


int main() {
    int errors = 0;
    if (html_validator("index.html", errors)) {
        cout << "HTML is valid" << endl;
    }
    else {
        cout << "HTML is not valid" << endl;
    }
    cout << "Errors count: " << errors << endl;

    return 0;
}
