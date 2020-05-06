#include <stdio.h>
#include <string.h>

typedef struct tagNode 
{
    char* key;
    char* value;

    struct tagNode* next;
} Node;

typedef struct tagHashTable
{
    int table_size;
    Node** table;
} HashTable;

int hash(char* key, int key_length, int table_size)
{
    int i = 0;
    int hash_value = 0;

    for(i=0; i<key_length; i++)
        hash_value = (hash_value << 3) + key[i];

    hash_value = hash_value % table_size;

    return hash_value;
}

HashTable* createHashTable(int table_size)
{
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->table = (Node**)malloc(sizeof(Node*) * table_size);

    memset(newTable->table, 0, sizeof(Node*) * table_size);
    newTable->table_size = table_size;

    return newTable;
}

Node* createNode(char* key, char* value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(new_node->key, key);

    new_node->value = (char*)malloc(sizeof(char) * (strlen(value) +1));
    strcpy(new_node->value, value);

    new_node->next = NULL;

    return new_node;
}

void hashSet(HashTable* HT, char* key, char* value)
{
    int addr = hash(key, strlen(key), HT->table_size);
    Node* new_node = createNode(key, value);

    if(HT->table[addr] == NULL)
    {
        HT->table[addr] = new_node;
    }
    else
    {
        Node* list = HT->table[addr];
        new_node->next = list;
        HT->table[addr] = new_node;

        printf("Collision occured : key(%s), addr(%d)\n", key, addr);
    }
}


char* hashGet(HashTable* HT, char* key)
{
    int addr = hash(key, strlen(key), HT->table_size);

    Node* list = HT->table[addr];
    Node* target = NULL;

    if(list == NULL)
        return NULL;

    while(1)
    {
        if(strcmp(list->key, key) == 0)
        {
            target = list;
            break;
        }

        if(list->next == NULL)
            break;
        else
            list = list->next;
    }
    return target->value;
}

int main()
{
	HashTable* my_hash = createHashTable(12289);

	hashSet(my_hash, "MSFT", "Microsoft Coporation");
	hashSet(my_hash, "JAVA", "Sun Microsystems");
	hashSet(my_hash, "REDH", "RegHat Linux");
	hashSet(my_hash, "APAC", "Apache Org");
	hashSet(my_hash, "ZYMZZ", "Unisys Ops Check");
	hashSet(my_hash, "CSCO", "Cisco Systems");

	printf("\n");
	printf("key:%s, value:%s\n", "MSFT", hashGet(my_hash, "MSFT"));
	printf("key:%s, value:%s\n", "JAVA", hashGet(my_hash, "JAVA"));
	printf("key:%s, value:%s\n", "REDH", hashGet(my_hash, "REDH"));
	printf("key:%s, value:%s\n", "APAC", hashGet(my_hash, "APAC"));
	printf("key:%s, value:%s\n", "ZYMZZ", hashGet(my_hash, "ZYMZZ"));
	printf("key:%s, value:%s\n", "CSCO", hashGet(my_hash, "CSCO"));
	printf("key:%s, value:%s\n", "KASA", hashGet(my_hash, "KASA"));
}
