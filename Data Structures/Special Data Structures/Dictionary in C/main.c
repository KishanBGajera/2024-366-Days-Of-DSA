#include "dictionary.h"

int main()
{
    Dictionary* dict = getDictionary(10);
    addDictEntry(dict, 1, 2);
    addDictEntry(dict, 2, 3);
    addDictEntry(dict, 3, 2);
    addDictEntry(dict, 11, 3);
    addDictEntry(dict, 21, 4);

    removeEntry(dict, 2);

    addDictEntry(dict, 2, 4);

    printf("Entry(21): %d\n", getValue(dict, 21));

    printDictionary(dict);
    return 0;
}