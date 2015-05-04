#include <string>
using namespace std;


class Hash
{
private:
    struct Pokes{
        int number;
        string name, type1, type2;
        Pokes *next;
    };
    
    Pokes* hashTable[18][18];
    
public:
    Hash();
    int hashFunc(string key);
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2);
    void get(string);
    void display(Pokes*);
};
