#include "push_swap.h"

int main(int argc, char **argv)
{
    char **str = NULL;
    int i;
    int count;
    char *total;
    int *num;
    t_list *heada;
    t_list *headb;
    int ops = 0;
    t_mode flags;
    
    if (argc < 2)
        return (0);

    heada = NULL;
    headb = NULL;
    flags = is_flag(argv[1]);
    if(flags)
        total = ft_strjoin((const char**)argv, argc, 2);
    else
        total = ft_strjoin((const char**)argv, argc, 1);

    if(!total)
        return (0);
    if (total)
        str = ft_split(total);
    if (!str)
        return (0);
    count = count_char_numbers(total);
    num = malloc(count * sizeof(int));
    i = 0;
    while(str[i])
    {
        num[i] = ft_atoi(str[i]);
        i++;
    }
    heada = new_list(num, count);
    printf("-----Before sorting------\n");
    show_list(heada);
    

    printf("flag %d\n", flags);
    printf("-----After sorting------\n");
    ops = ft_sorting(&heada, &headb, flags);
    show_list(heada);

    printf("number of ops : %d\n", ops);
    printf("size of stack a : %d\n", list_size(heada));


    delete_list(heada);
    delete_list(headb);
    return (0);
}



// int main(int argc, char **argv)
// {
//     char **str = NULL;
//     int i;
//     int count;
//     char *total;
//     int *num;
    
//     total = ft_strjoin((const char**)argv, argc);
//     count = count_nbr(total);
//     if (total)
//         str = ft_split(total);
//     num = malloc(count * sizeof(int));
//     i = 0;
//     while(str[i])
//     {
//         num[i] = ft_atoi(str[i]);
//         i++;
//     }
//     i = 0;
//     while(i < count)
//         printf("num %d\n", num[i++]);
    
//     return (0);
// }






// int main(int argc, char **argv)
// {
//     char **str = NULL;
//     int i;
//     int count;
//     char *total;
    
//     total = ft_strjoin((const char**)argv, argc);
//     count = count_nbr(total);
//     // printf("main total : %s\n", total);
//     if (total)
//         str = ft_split(total);
//     // printf("test : %s\n", *(str + 1));
//     // (void)argc;
//     // (void)argv;
//     i = 0;
//     if (!str)
//         return (0);
//     while(str[i])
//     {
//         printf("%s\n", str[i]);
//         i++;
//     }
    
//     return (0);
// }







// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *n;
//     int num = 0;
//     int tab1[] = {2, 0, 5, -1};
//     // int tab1[] = {5, -1, 0, 2};
//     // int tab1[] = {-1, -8, 5, 6, 1};
//     // int tab1[] = {5, 4, 3, 2, 1 , 0};
//     // int tab1[] = {12, 9, 1, 0, 3 , -4, 100};
//     // int tab1[] = {5, 4, 3, 2, 1};
//     // int tab1[] = {1, 2, 3, 4, 5};


//     int size1 = sizeof(tab1) / sizeof(int);

//     heada = new_list(tab1, size1);
//     headb = NULL;
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));

//     printf("----------insert sort---------\n");
//     num = insert_sort(&heada, &headb);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));

//     printf("ops number : %d\n", num);
//     delete_list(heada);
//     delete_list(headb);
//     return (0);
// }






// int main()
// {
//     int tab[] = {5, -1, 0, 2, 10, -8, 4};
    
//     insertion_sort(tab, 7);
//     int i;

//     i = 0;

//     while (i < 7)
//     {
//         printf("num : %d\n", tab[i]);
//         i++;
//     }
//     return (0);
// }













// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *n;
//     int tab1[] = {5, -1, 0, 2};
//     // int tab2[] = {2, 7 , -8, 1, 20};
//     int size1 = sizeof(tab1) / sizeof(int);

//     heada = new_list(tab1, size1);
//     headb = NULL;
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));

//     printf("----------pb---------\n");
//     pb;
//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));
//     delete_list(heada);
//     delete_list(headb);
//     return (0);
// }


// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *n;
//     int tab1[] = {9, 5 , 7, 0, -1};
//     int tab2[] = {2, 7 , -8, 1, 20};
//     int size1 = sizeof(tab1) / sizeof(int);
//     int size2 = sizeof(tab2) / sizeof(int);

//     heada = new_list(tab1, 5);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");

//     headb = new_list(tab2, 5);
//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");

//     printf("----------sa---------\n");
//     sa;
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     delete_list(heada);
//     delete_list(headb);


//     return (0);
// }

// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *a1;
//     t_list  *a2;
//     t_list  *a3;
//     t_list  *b1;
//     t_list  *b2;
//     t_list  *b3;
//     t_list *n;

//     heada = new_node(11);
//     a1 = new_node(22);
//     a2 = new_node(33);
//     a3 = new_node(44);
//     headb = new_node(55);
//     b1 = new_node(66);
//     b2 = new_node(77);
//     b3 = new_node(88);
    
//     //stack a
//     add_back(&heada, a1);
//     add_back(&heada, a2);
//     add_back(&heada, a3);

//     //stack b
//     add_back(&headb, b1);
//     add_back(&headb, b2);
//     add_back(&headb, b3);

//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");

//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");



//     printf("-----after push a-----\n");
//     ft_push(&heada, &headb);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     printf("-----after rotate a-----\n");
//     ft_rotate(&heada);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     printf("-----after reverse rotate a-----\n");
//     ft_reverse_rotate(&heada);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     delete_list(heada);
//     delete_list(headb);

//     return (0);
// }