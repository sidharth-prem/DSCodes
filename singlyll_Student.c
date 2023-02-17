#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
struct Node {
    int roll_no;
    char name[50];
    int total_mark;
    struct Node *next;
};

// Define a linked list structure
struct LinkedList {
    struct Node *head;
};

// Function to create a new node
struct Node *create_node(int roll_no, char name[], int total_mark) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->roll_no = roll_no;
    strcpy(new_node->name, name);
    new_node->total_mark = total_mark;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the list
void insert_node(struct LinkedList *list, int roll_no, char name[], int total_mark) {
    struct Node *new_node = create_node(roll_no, name, total_mark);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Student data inserted successfully.\n");
}

// Function to delete a node with a given roll no
void delete_node(struct LinkedList *list, int roll_no) {
    struct Node *current = list->head;
    struct Node *prev = NULL;
    while (current != NULL && current->roll_no != roll_no) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Roll no not found in list.\n");
    } else if (prev == NULL) {
        list->head = current->next;
        free(current);
        printf("Student data deleted successfully.\n");
    } else {
        prev->next = current->next;
        free(current);
        printf("Student data deleted successfully.\n");
    }
}

// Function to sort the list by roll no
void sort_list(struct LinkedList *list) {
    struct Node *i, *j;
    int temp_roll_no, temp_total_mark;
    char temp_name[50];
    for (i = list->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->roll_no > j->roll_no) {
                temp_roll_no = i->roll_no;
                i->roll_no = j->roll_no;
                j->roll_no = temp_roll_no;
                temp_total_mark = i->total_mark;
                i->total_mark = j->total_mark;
                j->total_mark = temp_total_mark;
                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);
            }
        }
    }
    printf("List sorted successfully.\n");
}

// Function to display the list
void display_list(struct LinkedList *list) {
    struct Node *current = list->head;
    if (current == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Roll No\tName\t\tTotal Marks\n");
        while (current != NULL) {
            printf("%d\t%s\t\t%d\n", current->roll_no, current->name, current->total_mark);
           
