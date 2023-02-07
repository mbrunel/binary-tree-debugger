#ifndef BINARY_TREE_DEBUGGER_H
#define BINARY_TREE_DEBUGGER_H

typedef struct noeud *Arbre;

void btd_console_print(Arbre a);

#endif

#ifdef BINARY_TREE_DEBUGGER_IMPL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** console_print implementation
*/

typedef struct __btd_trunk {
    char *str;
    struct __btd_trunk *prev;
} _btd_trunk_node, *_btd_trunk;

_btd_trunk _btd_create_trunk(_btd_trunk prev, const char *str) {
    _btd_trunk t = malloc(sizeof(_btd_trunk_node));
    if (!t)
        return NULL;
    t->prev = prev;
    if (!(t->str = strdup(str))) {
        free(t);
        return NULL;
    }
    return t;
}

void _btd_destroy_trunk(_btd_trunk *trunk) {
    free((*trunk)->str);
    free(*trunk);
    *trunk = NULL;
}

void _btd_show_trunk(_btd_trunk trunk) {
    if (trunk->prev) {
        _btd_show_trunk(trunk->prev);
    }
    printf("%s", trunk->str);
}

void _btd_console_print_internal(Arbre a, _btd_trunk prev, int is_left) {
    if (!a)
        return ;
    const char *prev_str = "    ";
    _btd_trunk trunk = _btd_create_trunk(prev, prev_str);
    _btd_console_print_internal(a->fd, trunk, 1);
    free(trunk->str);
    if (!prev)
        trunk->str = strdup("———");
    else if (is_left) {
        trunk->str = strdup(".———");
        prev_str = "   |";
    }
    else {
        trunk->str = strdup("`———");
        free(prev->str);
        prev->str = strdup(prev_str);
    }
    _btd_show_trunk(trunk);
    printf("(%d)\n", a->valeur);
    if (prev) {
        free(prev->str);
        prev->str = strdup(prev_str);
    }
    free(trunk->str);
    trunk->str = strdup("   |");
    _btd_console_print_internal(a->fg, trunk, 0);
    _btd_destroy_trunk(&trunk);
}

void btd_console_print(Arbre a) {
    _btd_console_print_internal(a, NULL, 0);
}

/*
** End of console_print implementation
*/

#endif
