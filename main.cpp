#include<stdio.h>
#include<string.h>
struct customer
{
    int account_no;
    char name[80];
    int balance;
};

int accept(struct customer[], int);
int display(struct customer[], int);
int search(struct customer[], int, int);
int deposit(struct customer[], int, int, int);
int withdraw(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;

    printf("\n\nWelcome to the Banking System\n\n");
    printf("How many records you want to enter/check? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {

        printf("\n\t* * * * * * Banking System Menu * * * * * *  :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nPlease enter any options (0/1/2/3/4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 2:
                printf("Enter the account number to search : ");
                scanf("%d", &account_no);
                index = search(data, n, account_no);
                if (index ==  0)
                {
                    printf("RECORD NOT FOUND : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter your account number : ");
                scanf("%d", &account_no);
                printf("Enter the amount you want to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 4:
                printf("Enter the account number : ");
                scanf("%d", &account_no);
                printf("Enter the amount you want to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

int accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter the account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter the Name : ");
        gets(list[i].name);
        list[i].balance = 0;
    }
    return 0;
}

int display(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\t Name\t Balance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,list[i].balance);
    }
    return 0;
}

int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        }
    }
}

int deposit(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("RECORD NOT FOUND");
    }
    else
    {
        list[i].balance += amt;
    }
    return 0;
}

int withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("RECORD NOT FOUND\n");
    }
    else if (list[i].balance < amt)
    {
        printf("! ! !Insufficient balance ! ! ! \n");
    }
    else
    {
        list[i].balance -= amt;
    }
    return 0;
}
