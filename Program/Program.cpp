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

    int Compare(const char * content)
    {
        
    }

};

int main()
{
    
    String string;
    string = "Janna";
    cout << "string의 크기는 : " << string.Size() << endl;
    string = "Ailstar";
    string.Compare("Ailstar");

    return 0;
}
