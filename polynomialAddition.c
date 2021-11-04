#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

void insertAtEnd(int coeff, int power, struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addPolynomial(struct Node** head1, struct Node** head2, struct Node** head3) {
    struct Node* t1 = *head1, *t2 = *head2;

    while (t1 != NULL && t2 != NULL) {
        if (t1->power > t2->power) {
            insertAtEnd(t1->coeff, t1->power, head3);
            t1 = t1->next;
        } else if (t2->power > t1->power) {
            insertAtEnd(t2->coeff, t2->power, head3);
            t2 = t2->next;
        } else {
            insertAtEnd(t2->coeff + t1->coeff, t1->power, head3);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL) {
        insertAtEnd(t1->coeff, t1->power, head3);
        t1 = t1->next;
    }

    while (t2 != NULL) {
        insertAtEnd(t2->coeff, t2->power, head3);
        t2 = t2->next;
    }
}

int main() {
    int n, coeff, power;
    struct Node* head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Enter the number of elements in first linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coeff: ");
        scanf("%d", &coeff);

        printf("Enter the power: ");
        scanf("%d", &power);

        insertAtEnd(coeff, power, &head1);
    }

    printf("Enter the number of elements in second linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coeff: ");
        scanf("%d", &coeff);

        printf("Enter the power: ");
        scanf("%d", &power);

        insertAtEnd(coeff, power, &head2);
    }

    printf("Elements in first linked list: ");
    struct Node* temp = head1;
    while (temp != NULL) {
        printf("%d^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");

    printf("Elements in second linked list: ");
    temp = head2;
    while (temp != NULL) {
        printf("%d^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");

    addPolynomial(&head1, &head2, &head3);

    printf("Result: ");
    temp = head3;
    while (temp != NULL) {
        printf("%d^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}