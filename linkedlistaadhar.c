#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Thing {
    char x[13];
    struct Thing* y;
};

void addAtBack(struct Thing** z, char* p) {
    struct Thing* q = (struct Thing*)malloc(sizeof(struct Thing));
    struct Thing* r = *z;

    strcpy(q->x, p);
    q->y = NULL;

    if (*z == NULL) {
        *z = q;
        return;
    }

    while (r->y != NULL) {
        r = r->y;
    }

    r->y = q;
}

void addInMiddle(struct Thing** z, char* p) {
    struct Thing* q = (struct Thing*)malloc(sizeof(struct Thing));
    struct Thing* t1 = *z;
    struct Thing* t2 = *z;

    strcpy(q->x, p);

    if (*z == NULL || (*z)->y == NULL) {
        q->y = *z;
        *z = q;
        return;
    }

    while (t2 != NULL && t2->y != NULL && t2->y->y != NULL) {
        t1 = t1->y;
        t2 = t2->y->y;
    }

    q->y = t1->y;
    t1->y = q;
}

void displayThings(struct Thing* z) {
    while (z != NULL) {
        printf("%s -> ", z->x);
        z = z->y;
    }
    printf("NULL\n");
}

void deleteThings(struct Thing* z) {
    struct Thing* s;

    while (z != NULL) {
        s = z;
        z = z->y;
        free(s);
    }
}

int main() {
    struct Thing* z = NULL;

    addAtBack(&z, "123412341234");
    addAtBack(&z, "567856785678");
    addAtBack(&z, "910191019101");
    addAtBack(&z, "234523452345");

    printf("List before adding the 5th thing:\n");
    displayThings(z);

    addInMiddle(&z, "345634563456");

    printf("\nList after adding the 5th thing in the middle:\n");
    displayThings(z);

    deleteThings(z);

    return 0;
}
