#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>

#define TABS 4
#define spaces(n) std::string(n, ' ')

void print_json(int, std::string);
void tokenizer(std::string);
void parse_file(std::string);
void read_file(std::string);

int main(int argc, char **argv)
{
    read_file(argv[1]);
}

void print_json(int blanks, std::string json)
{
    int quoted = 0;
    for (std::string::iterator it = json.begin(); it != json.end(); it++)
    {
        if (!quoted)
        {
            if (*it == '\n')
                continue;
            if (*it == '{' || *it == '[' || *it == '(')
            {
                blanks += TABS;
                std::cout << *it << "\n"
                          << spaces(blanks);
            }
            else if (*it == '}' || *it == ']' || *it == ')')
            {
                blanks -= TABS;
                std::cout << "\n"
                          << spaces(blanks) << *it;
                std::cout << "\n"
                          << spaces(blanks);
            }
            else if (*it == ',')
            {
                std::cout << *it << "\n"
                          << spaces(blanks);
                while (it != json.end() && *it == ' ')
                {
                    it++;
                }
            }
            else if (*it == '"')
            {
                quoted = 1 - quoted;
                std::cout << *it;
            }
            else
            {
                std::cout << *it;
            }
        }
        else
        {
            if (*it == '"')
            {
                quoted = 1 - quoted;
            }
            std::cout << *it;
        }
    }
}

void read_file(std::string filename)
{
    int blanks = 0;
    std::ifstream is;
    is.open(filename, std::ifstream::in);
    if (is.is_open())
    {
        while (!is.eof())
        {
            std::cout<<"WTh";
            std::string json_line;
            getline(is, json_line);
            print_json(blanks, json_line);
        }
    }
    else
    {
        std::cout << "Unable to read file...exitiing...\n";
    }
}