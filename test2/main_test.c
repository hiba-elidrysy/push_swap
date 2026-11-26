#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int g_pass = 0;
static int g_fail = 0;

static void print_list(const char *name, t_list *head)
{
    printf("   %s: ", name);
    if (!head)
        printf("(empty)");
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/* Compares the list with an expected array. size == 0 means expected empty. */
static void check(const char *test, t_list *head, int *exp, int size)
{
    int     i;
    int     ok;
    t_list  *tmp;

    ok = 1;
    i = 0;
    tmp = head;
    while (tmp && i < size)
    {
        if (tmp->data != exp[i])
            ok = 0;
        tmp = tmp->next;
        i++;
    }
    if (tmp || i != size)   /* list longer or shorter than expected */
        ok = 0;
    if (ok)
    {
        printf("[PASS] %s\n", test);
        g_pass++;
    }
    else
    {
        printf("[FAIL] %s\n", test);
        print_list("got", head);
        printf("   expected: ");
        if (size == 0)
            printf("(empty)");
        i = 0;
        while (i < size)
        {
            printf("%d%s", exp[i], i < size - 1 ? " -> " : "");
            i++;
        }
        printf("\n");
        g_fail++;
    }
}

int main(void)
{
    t_list  *a;
    t_list  *b;
    t_list  *n;

    /* ---------- new_node ---------- */
    printf("=== new_node ===\n");
    n = new_node(42);
    if (n && n->data == 42 && n->next == NULL)
        { printf("[PASS] new_node(42)\n"); g_pass++; }
    else
        { printf("[FAIL] new_node(42)\n"); g_fail++; }
    free(n);

    /* ---------- add_front ---------- */
    printf("\n=== add_front ===\n");
    a = NULL;
    add_front(&a, new_node(1));
    check("add_front on empty list", a, (int[]){1}, 1);
    add_front(&a, new_node(2));
    add_front(&a, new_node(3));
    check("add_front x3", a, (int[]){3, 2, 1}, 3);
    add_front(&a, NULL);
    check("add_front NULL node (no change)", a, (int[]){3, 2, 1}, 3);
    delete_list(a);

    /* ---------- add_back ---------- */
    printf("\n=== add_back ===\n");
    a = NULL;
    add_back(&a, new_node(1));
    check("add_back on empty list", a, (int[]){1}, 1);
    add_back(&a, new_node(2));
    add_back(&a, new_node(3));
    check("add_back x3", a, (int[]){1, 2, 3}, 3);
    add_back(&a, NULL);
    check("add_back NULL node (no change)", a, (int[]){1, 2, 3}, 3);
    delete_list(a);

    /* ---------- new_list ---------- */
    printf("\n=== new_list ===\n");
    a = new_list((int[]){5, 4, 3, 2, 1}, 5);
    check("new_list 5 elements", a, (int[]){5, 4, 3, 2, 1}, 5);
    delete_list(a);
    a = new_list(NULL, 3);
    check("new_list NULL tab", a, NULL, 0);
    a = new_list((int[]){1}, 0);
    check("new_list size 0", a, NULL, 0);
    a = new_list((int[]){1}, -1);
    check("new_list negative size", a, NULL, 0);
    a = new_list((int[]){7}, 1);
    check("new_list 1 element", a, (int[]){7}, 1);
    delete_list(a);

    /* ---------- ft_swap ---------- */
    printf("\n=== ft_swap ===\n");
    a = NULL;
    ft_swap(&a);
    check("swap empty", a, NULL, 0);
    a = new_list((int[]){1}, 1);
    ft_swap(&a);
    check("swap 1 element", a, (int[]){1}, 1);
    delete_list(a);
    a = new_list((int[]){1, 2}, 2);
    ft_swap(&a);
    check("swap 2 elements", a, (int[]){2, 1}, 2);
    delete_list(a);
    a = new_list((int[]){1, 2, 3, 4}, 4);
    ft_swap(&a);
    check("swap 4 elements", a, (int[]){2, 1, 3, 4}, 4);
    delete_list(a);

    /* ---------- ft_rotate ---------- */
    printf("\n=== ft_rotate ===\n");
    a = NULL;
    ft_rotate(&a);
    check("rotate empty", a, NULL, 0);
    a = new_list((int[]){1}, 1);
    ft_rotate(&a);
    check("rotate 1 element", a, (int[]){1}, 1);
    delete_list(a);
    a = new_list((int[]){1, 2}, 2);
    ft_rotate(&a);
    check("rotate 2 elements", a, (int[]){2, 1}, 2);
    delete_list(a);
    a = new_list((int[]){1, 2, 3, 4}, 4);
    ft_rotate(&a);
    check("rotate 4 elements", a, (int[]){2, 3, 4, 1}, 4);
    ft_rotate(&a);
    check("rotate again", a, (int[]){3, 4, 1, 2}, 4);
    delete_list(a);

    /* ---------- ft_reverse_rotate ---------- */
    printf("\n=== ft_reverse_rotate ===\n");
    a = NULL;
    ft_reverse_rotate(&a);
    check("reverse rotate empty", a, NULL, 0);
    a = new_list((int[]){1}, 1);
    ft_reverse_rotate(&a);
    check("reverse rotate 1 element", a, (int[]){1}, 1);
    delete_list(a);
    a = new_list((int[]){1, 2}, 2);
    ft_reverse_rotate(&a);
    check("reverse rotate 2 elements", a, (int[]){2, 1}, 2);
    delete_list(a);
    a = new_list((int[]){1, 2, 3, 4}, 4);
    ft_reverse_rotate(&a);
    check("reverse rotate 4 elements", a, (int[]){4, 1, 2, 3}, 4);
    ft_reverse_rotate(&a);
    check("reverse rotate again", a, (int[]){3, 4, 1, 2}, 4);
    delete_list(a);

    /* rotate then reverse rotate must give the original list */
    a = new_list((int[]){1, 2, 3, 4, 5}, 5);
    ft_rotate(&a);
    ft_reverse_rotate(&a);
    check("rotate + reverse_rotate = identity", a, (int[]){1, 2, 3, 4, 5}, 5);
    delete_list(a);

    /* ---------- delete_front ---------- */
    printf("\n=== delete_front ===\n");
    a = NULL;
    delete_front(&a);
    check("delete_front empty", a, NULL, 0);
    a = new_list((int[]){1, 2, 3}, 3);
    delete_front(&a);
    check("delete_front 3 -> 2 elements", a, (int[]){2, 3}, 2);
    delete_front(&a);
    delete_front(&a);
    check("delete_front until empty", a, NULL, 0);

    /* ---------- ft_push ---------- */
    printf("\n=== ft_push (push from h2 onto h1) ===\n");
    a = new_list((int[]){1, 2, 3}, 3);
    b = NULL;
    ft_push(&b, &a);    /* pb */
    check("push a->b : a", a, (int[]){2, 3}, 2);
    check("push a->b : b", b, (int[]){1}, 1);
    ft_push(&b, &a);
    check("push a->b again : a", a, (int[]){3}, 1);
    check("push a->b again : b", b, (int[]){2, 1}, 2);
    ft_push(&a, &b);    /* pa */
    check("push b->a : a", a, (int[]){2, 3}, 2);
    check("push b->a : b", b, (int[]){1}, 1);
    delete_list(a);
    delete_list(b);

    a = new_list((int[]){1, 2}, 2);
    b = NULL;
    ft_push(&a, &b);    /* source empty: nothing should change */
    check("push from empty source : a", a, (int[]){1, 2}, 2);
    check("push from empty source : b", b, NULL, 0);
    delete_list(a);

    /* ---------- delete_list ---------- */
    printf("\n=== delete_list ===\n");
    a = new_list((int[]){1, 2, 3, 4, 5}, 5);
    delete_list(a);
    delete_list(NULL);
    printf("[PASS] delete_list (no crash; use valgrind/ASan to check leaks)\n");
    g_pass++;

    /* ---------- summary ---------- */
    printf("\n==============================\n");
    printf("PASSED: %d   FAILED: %d\n", g_pass, g_fail);
    printf("==============================\n");
    return (g_fail != 0);
}