#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char line[80];
    struct node *next;
};

void load(struct node *head, const char *filename);
int lines(struct node *head);
void insert(struct node *head, int n1);
void append(struct node *head);
void delete(struct node *head, int n1, int n2);
void move(struct node *head, int n1, int n2, int n3);
void copy(struct node *head, int n1, int n2, int n3);
void save(struct node *head, const char *filename);
void find(struct node *head, int n1, int n2);
void print(struct node *head);
void help();

int main(int argc, char *argv[])
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    if (argc > 1)
    {
        load(head, argv[1]);
        printf("Lines: %d\n", lines(head));
    }

    char str[80], c;
    int n1, n2, n3, n;

    while (1)
    {
        printf("\n$ ");
        fgets(str, 80, stdin);
        n = sscanf(str, "%c %d %d %d", &c, &n1, &n2, &n3);

        switch (c)
        {
        case 'p':
            print(head);
            break;
        case 'i':
            insert(head, n1);
            break;
        case 'a':
            append(head);
            break;
        case 'd':
            delete (head, n1, n2);
            break;
        case 'm':
            move(head, n1, n2, n3);
            break;
        case 'c':
            copy(head, n1, n2, n3);
            break;
        case 's':
            save(head, argv[1]);
            break;
        case 'f':
            find(head, n1, n2);
            break;
        case 'h':
            help();
            break;
        case 'q':
            exit(0);
        default:
            printf("Wrong command\n");
            break;
        }
    }
    return 0;
}

void load(struct node *head, const char *filename)
{
    FILE *fp;
    char str[80];
    struct node *last = head;

    if ((fp = fopen(filename, "r")) != NULL)
    {
        while (fgets(str, 80, fp))
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            strcpy(temp->line, str);
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }
}

int lines(struct node *head)
{
    int cnt = 0;
    struct node *temp = head->next;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insert(struct node *head, int n1)
{
    struct node *curr = head;
    int i;
    for (i = 1; i < n1 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    char str[80];
    printf("Enter line (end with .):\n");
    fgets(str, 80, stdin);

    struct node *newn = (struct node *)malloc(sizeof(struct node));
    strcpy(newn->line, str);
    newn->next = curr->next;
    curr->next = newn;
}

void append(struct node *head)
{
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    char str[80];
    printf("Enter line (end with .):\n");
    fgets(str, 80, stdin);

    struct node *newn = (struct node *)malloc(sizeof(struct node));
    strcpy(newn->line, str);
    newn->next = NULL;
    curr->next = newn;
}

void delete(struct node *head, int n1, int n2)
{
    struct node *curr1 = head, *curr2, *back1;
    int i;

    for (i = 1; i <= n1 && curr1 != NULL; i++)
    {
        back1 = curr1;
        curr1 = curr1->next;
    }

    if (curr1 == NULL)
    {
        printf("Start position out of bounds\n");
        return;
    }

    curr2 = curr1;
    for (i = n1; i <= n2 && curr2 != NULL; i++)
    {
        curr2 = curr2->next;
    }

    if (curr2 == NULL)
    {
        printf("End position out of bounds\n");
        return;
    }

    back1->next = curr2;

    while (curr1 != curr2)
    {
        struct node *temp = curr1;
        curr1 = curr1->next;
        free(temp);
    }
}

void move(struct node *head, int n1, int n2, int n3)
{
    struct node *back1, *back3, *curr1, *curr2, *curr3;
    int i;

    // Locate n1
    curr1 = head;
    for (i = 1; i <= n1 && curr1 != NULL; i++)
    {
        back1 = curr1;
        curr1 = curr1->next;
    }

    // Locate n2
    curr2 = curr1;
    for (i = n1; i < n2 && curr2 != NULL; i++)
    {
        curr2 = curr2->next;
    }

    // Detach the segment from n1 to n2
    back1->next = curr2->next;

    // Locate n3
    curr3 = head;
    for (i = 1; i <= n3 && curr3 != NULL; i++)
    {
        back3 = curr3;
        curr3 = curr3->next;
    }

    // Insert the segment before n3
    curr2->next = curr3;
    back3->next = curr1;
}

void copy(struct node *head, int n1, int n2, int n3)
{
    struct node *curr1, *curr2, *curr3, *newn, *first1 = NULL, *last1 = NULL;
    int i;

    // Locate n1
    curr1 = head;
    for (i = 1; i <= n1 && curr1 != NULL; i++)
    {
        curr1 = curr1->next;
    }

    // Copy the segment from n1 to n2
    curr2 = curr1;
    for (i = n1; i <= n2 && curr2 != NULL; i++, curr2 = curr2->next)
    {
        newn = (struct node *)malloc(sizeof(struct node));
        strcpy(newn->line, curr2->line);
        newn->next = NULL;
        if (first1 == NULL)
        {
            first1 = last1 = newn;
        }
        else
        {
            last1->next = newn;
            last1 = newn;
        }
    }

    // Locate n3
    curr3 = head;
    for (i = 1; i < n3 && curr3 != NULL; i++)
    {
        curr3 = curr3->next;
    }

    // Insert the copied segment before n3
    last1->next = curr3->next;
    curr3->next = first1;
}

void save(struct node *head, const char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "w")) != NULL)
    {
        struct node *temp = head->next;
        while (temp != NULL)
        {
            fputs(temp->line, fp);
            temp = temp->next;
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }
}

void find(struct node *head, int n1, int n2)
{
    char str[80];
    printf("Enter string to find:\n");
    // scanf("%s", str);
    gets(str);

    struct node *temp = head;
    int i;
    for (i = 1; i < n1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    for (i = 1; i <= n2 && temp != NULL; i++, temp = temp->next)
    {
        if (strstr(temp->line, str))
        {
            printf("Got it: ");
            printf("%s", temp->line);
        }
    }
}

void print(struct node *head)
{
    struct node *temp = head->next;
    while (temp != NULL)
    {
        printf("%s", temp->line);
        temp = temp->next;
    }
}

void help()
{
    printf("Commands:\n");
    printf("p - print all lines\n");
    printf("i <n> - insert line at position n\n");
    printf("a - append line at end\n");
    printf("d <n1> <n2> - delete lines from n1 to n2\n");
    printf("m <n1> <n2> <n3> - move lines from n1 to n2 to position n3\n");
    printf("c <n1> <n2> <n3> - copy lines from n1 to n2 to position n3\n");
    printf("s - save lines to file\n");
    printf("f <n1> <n2> - find string in lines from n1 to n2\n");
    printf("h - help\n");
    printf("q - quit\n");
}
