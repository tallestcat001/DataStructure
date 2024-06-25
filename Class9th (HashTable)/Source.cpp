#include <iostream>

#define SIZE 6

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* next;
    };

    struct Bucket
    {
        Node* head;
        int count;
    };

    Bucket bucket[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }

    template<typename T>
    int HashFunction(T key)
    {
        int hashindex = (int)key % SIZE;

        return hashindex;
    }

    template<>
    int HashFunction(std::string key)
    {
        int result = 0;

        for (const char& element : key)
        {
            result += element;
        }

        int hashindex = (int)result % SIZE;

        return hashindex;
    }

    Node* CreatNode(KEY key, VALUE value)
    {
        Node* creatnode = new Node();
        creatnode->key = key;
        creatnode->value = value;
        creatnode->next = nullptr;

        return creatnode;
    }

    void Insert(KEY key, VALUE value)
    {
        int hashindex = HashFunction(key);

        Node* newnode = CreatNode(key, value);

        if (bucket[hashindex].count == 0)
        {
            bucket[hashindex].head = newnode;
        }
        else
        {
            newnode->next = bucket[hashindex].head;
            bucket[hashindex].head = newnode;
        }

        bucket[hashindex].count++;

    }

    void Remove(KEY key)
    {
        int hashindex = HashFunction(key);
        Node* currentNode = bucket[hashindex].head;
        Node* previousNode = nullptr;

        if (currentNode == nullptr)
        {
            cout << "Not key Found" << endl;
            return;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                {
                    if (currentNode == bucket[hashindex].head)
                    {
                        bucket[hashindex].head = currentNode->next;
                    }
                    else
                    {
                        previousNode->next = currentNode->next;
                    }

                    bucket[hashindex].count--;
                    delete currentNode;
                    return;
                }
                else
                {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }

            cout << "Not key Found" << endl;
        }
    }

    void Show()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* currentNode = bucket[i].head;

            while (currentNode != nullptr)
            {
                cout << "[" << i << "]" << "KEY : " << currentNode->key << "VALUE : " << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* deleteNode = bucket[i].head;
            Node* nextNode = bucket[i].head;

            if (bucket[i].head == nullptr)
            {
                continue;
            }
            else
            {
                while (nextNode != nullptr)
                {
                    nextNode = deleteNode->next;
                    delete deleteNode;
                    deleteNode = nextNode;
                }
            }
        }
    }

};

int main()
{
    HashTable<std::string, int> hashtable;

    hashtable.Insert("Sword", 100);
    hashtable.Insert("Gun", 500);
    hashtable.Remove("Sword");
    hashtable.Remove("Gun");
    hashtable.Remove("shelid");
    hashtable.Show();

    return 0;
}
