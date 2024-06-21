#include <iostream>

#pragma warnings(disable: 4996)

using namespace std;

class String
{
private:
    char* container;
    int size;
public:
    String()
    {
        size = 0;
        container = nullptr;
    }

    void operator = (const char* content)
    {
        int arraysize = strlen(content) + 1;
        size = strlen(content);

        if (container == nullptr)
        {
            container = new char[arraysize];

            for (int i = 0; i < arraysize; i++)
            {
                container[i] = content[i];
            }
        }
        else
        {
            char* newcontainer = new char[arraysize];

            for (int i = 0; i < arraysize; i++)
            {
                newcontainer[i] = content[i];
            }

            delete container;

            container = newcontainer;
        }
    }

    char operator [] (int index)
    {
        return container[index];
    }

    int& Size()
    {
        return size;
    }

    int Compare(const char* content)
    {

        int count = 0;



        for (int i = 0; i < strlen(content); i++)
        {
            if (container[i] != content[i])
            {
                break;
            }
            else
            {
                count++;
            }
        }

        if (strlen(content) == count)
        {
            return 0;
        }

        int classstring = 0;
        int otherstring = 0;

        for (int i = 0; i < strlen(container); i++)
        {
            classstring += container[i];
        }

        for (int i = 0; i < strlen(content); i++)
        {
            otherstring += content[i];
        }

        if (classstring > otherstring)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }

    void Append(const char* content)
    {
        int newsize = strlen(container) + strlen(content);

        char* newcontainer = new char[newsize];

        for (int i = 0; i < strlen(container); i++)
        {
            newcontainer[i] = container[i];
        }

        for (int i = 0; i < strlen(content); i++)
        {
            newcontainer[strlen(container) + i] = content[i];
        }

        size = newsize;

        delete[] container;

        container = newcontainer;

    }

    ~String()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }

};

int main()
{

    String string;
    string = "league";
    string.Append("of");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    return 0;
}
