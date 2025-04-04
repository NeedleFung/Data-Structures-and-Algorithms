#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);
    int check = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            Bracket bracket(next, position);
            opening_brackets_stack.push(bracket);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            if (opening_brackets_stack.empty() ||
                opening_brackets_stack.top().type == '(' && next != ')' ||
                opening_brackets_stack.top().type == '[' && next != ']' ||
                opening_brackets_stack.top().type == '{' && next != '}' )
            {
                std::cout<<position + 1;
                check = 1;
                break;
            }
            opening_brackets_stack.pop();
        }
    }
    if (opening_brackets_stack.empty() && check == 0)
        std::cout<<"Success";
    else if (!opening_brackets_stack.empty() && check == 0)
        std::cout<<opening_brackets_stack.top().position + 1;

    return 0;
}
