#ifndef TEXT_H
#define TEXT_H

//~~~~~~~
//Structs
//~~~~~~~
typedef struct CapitalTextInfo
{
    int x;                                  
    int y;                                  
    int size;                                        //Higher number, smaller size

}CapitalTextInfo;


typedef struct LowercaseTextInfo
{
    int spacing;
    int yOffset;
    int size;                                        //Higher number, smaller size
}LowercaseTextInfo;

#endif /* TEXT_H */
