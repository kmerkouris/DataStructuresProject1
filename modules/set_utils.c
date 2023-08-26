#include <common_types.h>
#include <raylib.h>
#include <state.h>
#include <ADTSet.h>
#include <acutest.h>
#include "set_utils.h"




Pointer set_find_eq_or_greater(Set set, Pointer value)
{
    Pointer k,l;
    SetNode node = set_first(set);
    k=set_find(set,value);
    if (k == NULL)
    {
        set_insert(set,k);
        l=set_next(set,node);
        set_remove(set,k);
        return l;
    }
    else
    {
        return value;
    }
}




Pointer set_find_eq_or_smaller(Set set, Pointer value)
{
    Pointer k,l;
    SetNode node = set_first(set);
    k=set_find(set,value);
    if (k == NULL)
    {
        set_insert(set,k);
        l=set_previous(set,node);
        set_remove(set,k);
        return l;
    }
    else
    {
        return value;
    }
}

int compare_int(Pointer a , Pointer b)
{
    return *(int*)a-*(int*)b;
}

int* create_int(int value)
{
    int* pointer = malloc(sizeof(int*));
    *pointer=value;
    return pointer;
}