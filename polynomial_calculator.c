#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct poly
{
    float coeff;
    int expo;
    struct poly *next;
} node;
//To check float or int 
bool checkDT(float num)
{
    int temp = num;
    if (temp == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

node traversal(node *head)
{
    if (head == NULL)
    {
        printf("0");
    }
    else
    {
        node *staticHead = head;
        while (head != NULL)
        {
            if (checkDT(head->coeff) == false)
            {
                if (head->expo == 0)
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %.2f + ", -(head->coeff));
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %.2f + ", -(head->coeff));
                    }
                    else
                    {
                        printf("%.2f + ", head->coeff);
                    }
                }
                else if (head->expo == 1 && head->coeff != 1)
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %.2fx + ", -(head->coeff));
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %.2fx + ", -(head->coeff));
                    }
                    else
                    {
                        printf("%.2fx + ", head->coeff);
                    }
                }
                else if (head->coeff == 1 && head->expo != 0 && head->expo != 1)
                {
                    printf("x^%d + ", head->expo);
                }
                else if (head->coeff == -1 && head->expo != 0 && head->expo != 1)
                {
                    if (head == staticHead)
                    {
                        printf("- x^%d + ", head->expo);
                    }
                    else
                    {
                        printf("\b\b- x^%d + ", head->expo);
                    }
                }
                else if (head->coeff == 1 && head->expo == 1)
                {
                    printf("x + ");
                }
                else if (head->coeff == -1 && head->expo == 1)
                {
                    if (head == staticHead)
                    {
                        printf("- x + ");
                    }
                    else
                    {
                        printf("\b\b- x + ");
                    }
                }
                else
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %.2fx^%d + ", -head->coeff, head->expo);
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %.2fx^%d + ", -head->coeff, head->expo);
                    }
                    else
                    {
                        printf("%.2fx^%d + ", head->coeff, head->expo);
                    }
                }
            }
            else
            {
                if (head->expo == 0)
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %d + ", -(int)(head->coeff));
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %d + ", -(int)(head->coeff));
                    }
                    else
                    {
                        printf("%d + ", (int)head->coeff);
                    }
                }
                else if (head->expo == 1 && head->coeff != 1)
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %dx + ", -(int)(head->coeff));
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %dx + ", -(int)(head->coeff));
                    }
                    else
                    {
                        printf("%dx + ", (int)head->coeff);
                    }
                }
                else if (head->coeff == 1 && head->expo != 0 && head->expo != 1)
                {
                    printf("x^%d + ", head->expo);
                }
                else if (head->coeff == -1 && head->expo != 0 && head->expo != 1)
                {
                    if (head == staticHead)
                    {
                        printf("- x^%d + ", head->expo);
                    }
                    else
                    {
                        printf("\b\b- x^%d + ", head->expo);
                    }
                }
                else if (head->coeff == 1 && head->expo == 1)
                {
                    printf("x + ");
                }
                else if (head->coeff == -1 && head->expo == 1)
                {
                    if (head == staticHead)
                    {
                        printf("- x + ");
                    }
                    else
                    {
                        printf("\b\b- x + ");
                    }
                }
                else
                {
                    if (head->coeff < 0 && head != staticHead)
                    {
                        printf("\b\b- %dx^%d + ", -(int)head->coeff, head->expo);
                    }
                    else if (head->coeff < 0 && head == staticHead)
                    {
                        printf("- %dx^%d + ", -(int)head->coeff, head->expo);
                    }
                    else
                    {
                        printf("%dx^%d + ", (int)head->coeff, head->expo);
                    }
                }
            }
            head = head->next;
        }
        printf("\b\b ");
    }
    printf("\n");
}
//This will return a pointer that points towards the terms of quotient that gets multiplied with the divisor in succesive steps
node *map(node *p1, node *p2)
{
    if (p1 == NULL)
    {
        return NULL;
    }
    node *tmp = NULL;
    tmp = malloc(sizeof(node));

    tmp->coeff = -(p1->coeff / p2->coeff);
    tmp->expo = p1->expo - p2->expo;

    tmp->next = NULL;

    return tmp;
}
//This will copy a linked list
node *cpy(node *p)
{
    node *cpHead = NULL;
    node *cpTrav = NULL;
    node *cpClone = NULL;

    int i = 0;

    while (p != NULL)
    {
        cpClone = malloc(sizeof(node));
        cpClone->coeff = p->coeff;
        cpClone->expo = p->expo;
        if (i == 0)
        {
            cpHead = cpClone;
            cpTrav = cpClone;
            i++;
        }
        else
        {
            cpTrav->next = cpClone;
            cpTrav = cpTrav->next;
        }
        p = p->next;
    }
    return cpHead;
}
//This will merge all same exponent terms
node *rmDuplicate(node *head)
{
    node *p = NULL;
    p = head;
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    while (p->next != NULL)
    {
        if (p->expo == p->next->expo)
        {
            p->coeff = p->coeff + p->next->coeff;
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }
    p->next = NULL;
    return head;
}
//This will remove all zero coefficient terms
node *rmZeroCf(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        if (head->coeff == 0)
        {
            return NULL;
        }
        else
        {
            return head;
        }
    }
    node *p = head;
    while (p->next != NULL)
    {
        if (p->coeff == 0)
        {
            p->coeff = p->next->coeff;
            p->expo = p->next->expo;
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }
    if (p->coeff == 0 && p == head)
    {
        return NULL;
    }
    if (p->coeff == 0)
    {
        p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = NULL;
    }
    return head;
}

node *addpoly(node *head1, node *head2)
{
    node *p1 = NULL;
    node *p2 = NULL;
    node *fhead = NULL;
    node *temp = NULL;
    node *trav = NULL;

    int time = 0;

    if ((head1 == NULL) && (head2 == NULL))
    {
        return NULL;
    }
    else if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    head1 = rmDuplicate(head1);
    head2 = rmDuplicate(head2);

    p1 = head1;
    p2 = head2;

    while (p1 != NULL || p2 != NULL)
    {
        if ((p1 == NULL) && (p2 == NULL))
        {
            trav->next = NULL;
            break;
        }
        if (p2 == NULL)
        {
            trav->next = p1;
            // p2 = malloc(sizeof(node));
            // p2->coeff = 0;
            // p2->expo = -1;
            break;
        }
        if (p1 == NULL)
        {
            trav->next = p2;
            // p1 = malloc(sizeof(node));
            // p1->coeff = 0;
            // p1->expo = -1;
            break;
        }
        temp = malloc(sizeof(node));

        if (p1->expo > p2->expo)
        {
            if (time == 0)
            {
                temp->expo = p1->expo;
                temp->coeff = p1->coeff;
                trav = temp;
                fhead = trav;
                p1 = p1->next;
                time++;
            }
            else
            {
                temp->expo = p1->expo;
                temp->coeff = p1->coeff;
                trav->next = temp;
                trav = trav->next;
                p1 = p1->next;
            }
        }
        else if (p1->expo < p2->expo)
        {
            if (time == 0)
            {
                temp->expo = p2->expo;
                temp->coeff = p2->coeff;
                trav = temp;
                fhead = trav;
                p2 = p2->next;
                time++;
            }
            else
            {
                temp->expo = p2->expo;
                temp->coeff = p2->coeff;
                trav->next = temp;
                trav = trav->next;
                p2 = p2->next;
            }
        }
        else if (p1->expo == p2->expo)
        {
            if (time == 0)
            {
                temp->expo = p2->expo;
                temp->coeff = p2->coeff + p1->coeff;
                trav = temp;
                fhead = trav;
                p2 = p2->next;
                p1 = p1->next;
                time++;
            }
            else
            {
                temp->expo = p2->expo;
                temp->coeff = p2->coeff + p1->coeff;
                trav->next = temp;
                trav = trav->next;
                p2 = p2->next;
                p1 = p1->next;
            }
        }
    }
    fhead = rmDuplicate(fhead);
    return fhead;
}

node *insertSort(node *p)
{
    // node *head = NULL;
    node *p1 = NULL;
    node *p2 = NULL;
    node *trav = NULL;
    node *ip = NULL;

    if (p == NULL)
    {
        return NULL;
    }

    p1 = p;
    p2 = p;

    int count, num, i, index;
    // printf("\nNo of INPUT: ");
    // scanf("%d", &num);
    printf("\n");
    ip = malloc(sizeof(node));
    // printf("\nEMPLOYEE \n\n");
    printf("\tCOEFFICIENT: ");
    scanf("%f", &ip->coeff);
    printf("\tEXPONENT: ");
    scanf("%d", &ip->expo);
    // printf("\t\t%d\t\t", i);
    if (ip->expo > p->expo)
    {
        ip->next = p;
        p = ip;
    }
    else
    {
        if (p->next == NULL)
        {
            p->next = ip;
            ip->next = NULL;
        }
        else
        {
            p1 = p1->next;
            // p2 = p2->next;
            while (p1 != NULL)
            {
                if (ip->expo > p2->next->expo)
                {
                    ip->next = p2->next;
                    p2->next = ip;
                    break;
                }
                else
                {
                    p2 = p2->next;
                }
                p1 = p1->next;
            }
            if (p1 == NULL)
            {
                p2->next = ip;
                ip->next = NULL;
            }
        }
    }
    return p;
}

void retQuotient(node *p)
{
    while (p != NULL)
    {
        p->coeff = -p->coeff;
        p = p->next;
    }
}

node *divi(node *divdnt, node *divsr)
{
    node *p1 = NULL;
    node *p2 = NULL;
    node *p2i = NULL;
    node *tmp = NULL;
    node *tmp1 = NULL;
    node *tmp2 = NULL;
    node *sum = NULL;

    p1 = divdnt;

    int time = 0, time2 = 0;

    // printf("\n___DEBUG 1___\n");

    // int zee = 2;
    // while(zee--)
    while (p1->expo >= divsr->expo)
    {
        // printf("\n___DEBUG 2___\n");

        p2 = cpy(divsr);
        p2i = p2;
        while (p2 != NULL && p1 != NULL)
        {
            // printf("\n___DEBUG 3___\n");

            if (time2 == 0)
            {
                tmp = map(p1, p2);
                // traversal(tmp);
                time2++;
            }
            p2->coeff = (tmp->coeff) * (p2->coeff);
            // printf("\n___DEBUG 3 A___\n");
            p2->expo = tmp->expo + p2->expo;
            // printf("\n___DEBUG 3 B___\n");
            p2 = p2->next;
            // printf("\n___DEBUG 3 C___\n");
        }
        // printf("\n___DEBUG 3 D___\n");
        // traversal(p2i);
        // printf("\n___DEBUG 3 E___\n");
        if (time == 0)
        {
            tmp2 = tmp;
            time++;
        }
        else
        {
            tmp2 = addpoly(tmp2, tmp);
        }
        // tmp1 = divsr;
        // traversal(p1);
        p1 = addpoly(p2i, p1);
        // printf("\n___DEBUG 3 F___\n");
        // traversal(p1);
        time2 = 0;
        // if(p1 == NULL)
        // {
        //     break;
        // }
        // printf("\n\t%d\n",p1->expo);
        // printf("\n\t%d\n",divsr->expo);
        p1 = rmZeroCf(p1);
        // printf("\n___DEBUG 3 G___\n");
        // traversal(p1);
        // traversal(divsr);
        // printf("\n___DEBUG 3 H___\n");
        if (p1 == NULL)
        {
            break;
        }
    }
    printf("\n\tQUOTIENT  : ");
    retQuotient(tmp2);
    tmp2 = rmZeroCf(tmp2);
    tmp2 = rmDuplicate(tmp2);
    traversal(tmp2);
    printf("\n");

    p1 = rmZeroCf(p1);
    p1 = rmDuplicate(p1);

    return p1;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *tmp = NULL;
    node *fhead = NULL;
    // node *trav = NULL;
    node *ip = NULL;
    int count, num1, num2, i = 1;
    char choice = 'Y';

    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------");
    printf("\n\t\t\t             WELCOME");
    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------\n");

    printf("\n\tEnter the number of terms your Dividend have: ");
    scanf("%d", &num1);
    printf("\n");

    if (num1 != 0)
    {
        ip = malloc(sizeof(node));
        printf("\n\tPOLYNOMIAL TERM %d\n\n", i);
        printf("\tCOEFFICIENT: ");
        scanf("%f", &ip->coeff);
        printf("\tEXPONENT: ");
        scanf("%d", &ip->expo);
        // printf("\t\t%d\t\t", i);

        head1 = ip;
        // trav = ip;
        ip->next = NULL;
        num1--;
        while (num1--)
        {
            i++;
            printf("\n\tPOLYNOMIAL TERM %d\n", i);
            // insertSort function will insert the nodes one by one in the descending order of exponents
            head1 = insertSort(head1);
        }
    }

    printf("\n");
    i = 1;
    printf("\n\tEnter the number of terms your Divisor have: ");
    scanf("%d", &num2);
    printf("\n");

    if (num2 != 0)
    {
        ip = malloc(sizeof(node));
        printf("\n\tPOLYNOMIAL TERM %d\n\n", i);
        printf("\tCOEFFICIENT: ");
        scanf("%f", &ip->coeff);
        printf("\tEXPONENT: ");
        scanf("%d", &ip->expo);
        // printf("\t\t%d\t\t", i);

        head2 = ip;
        // trav = ip;
        ip->next = NULL;
        num2--;
        while (num2--)
        {
            i++;
            printf("\n\tPOLYNOMIAL TERM %d\n", i);
            // insertSort function will insert the nodes one by one in the descending order of exponents
            head2 = insertSort(head2);
        }
    }

    if (num1 == 0 || num2 == 0)
    {
        printf("\n\n\t>> TRY AGAIN !!");
        printf("\n\t>> INVALID DIVIDENT OR DIVISOR\n");
        goto end;
    }

    head1 = rmDuplicate(head1);
    head2 = rmDuplicate(head2);
    head1 = rmZeroCf(head1);
    head2 = rmZeroCf(head2);

    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------");
    printf("\n\t\t               POLYNOMIAL DIVISION");
    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------\n");

    printf("\n\tDIVIDEND  : ");
    traversal(head1);
    printf("\n");
    printf("\n\tDIVISOR   : ");
    traversal(head2);
    printf("\n");
    fhead = divi(head1, head2);
    printf("\n\tREMAINDER : ");
    traversal(fhead);
    printf("\n");

    printf("\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------");
    printf("\n");

end:

    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------");
    printf("\n\t\t\t            THANK YOU");
    printf("\n\t_____________________________________________________________________");
    printf("\n\t---------------------------------------------------------------------\n");

    return 0;
}