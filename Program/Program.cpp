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
        Node *creatnode = new Node();
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

};

int main()
{
    HashTable<std::string, int> hashtable;

    hashtable.Insert("Sword", 100);
    hashtable.Insert("Gun", 500);

    return 0;
}
