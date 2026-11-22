
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct s_list t_list;

typedef struct s_list
{
    int data;
    t_list  *next;
}   t_list;



#endif