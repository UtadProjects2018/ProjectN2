//
//  main.cpp
//  ProjectN2
//
//  Created by pc-laptop on 10/28/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>

const void PrintBytes(unsigned int *pInt)
{
    const char *pBytes = reinterpret_cast<char *>(pInt);
    unsigned const int index = sizeof(*pInt);
    for (int i = 0; i < index; i++)
    {
        printf("%p", (pBytes + i));
        printf("\n");
    }
}

int GetHighestIntElement(const int *pTable, const int length)
{
    int highestElement = 0;
    for (int i = 0; i < length; i++)
    {
        int pValue = *(pTable + i);
        if (pValue > highestElement)
        {
            highestElement = pValue;
        }
    }
    return highestElement;
}

const char *GetHighestByteElement(const int *pTable)
{
    const char *pBytes = reinterpret_cast<const char *>(pTable);
    const char *pTableCopy = reinterpret_cast<const char *>(pTable);
    const int index = sizeof(*pTable);
    
    for (int i = 0; i < index; i++)
    {
        if (pTableCopy[i] > *pBytes)
        {
            pBytes = (pTableCopy + i);
        }
    }
    return pBytes;
}

void ReverseCharacters(char *&characters)
{
    const size_t length = strlen(characters);
    char *reversedCharacter = new char[length];
    
    for (size_t i = length; i > 0; i--)
    {
        reversedCharacter[length - i] = characters[i - 1];
    }

    //Reset Pointer
    characters = nullptr;
    delete [] characters;
    characters = new char[length];
    
    strncpy(characters, reversedCharacter, length);
    delete [] reversedCharacter;
}

int main(int argc, const char * argv[])
{
    //1.
    unsigned int number = 20;
    PrintBytes(&number);
    
    //2.
    int table[] = {1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2};
    printf("%d\n", GetHighestIntElement(table, 7));
    
    //3.
    printf("%p\n", GetHighestByteElement(table));
    
    //4.
    char *characters = "HOLA";
    ReverseCharacters(characters);
    printf("%s\n", characters);
    delete [] characters;
    
    return 0;
}
