#include <stdio.h>
#include <stdlib.h>
#include "addressbook.h"
int main()
{
    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    FILE *fp;
    fp = fopen("database.csv", "r");
    if (fp == NULL)
    {
        fp = fopen("database.csv", "w");
        if (fp != NULL)
            fclose(fp);
    }
    else
    {
        while (fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n",
                      addressBook.contacts[addressBook.contactCount].name,
                      addressBook.contacts[addressBook.contactCount].phone,
                      addressBook.contacts[addressBook.contactCount].email,
                      addressBook.contacts[addressBook.contactCount].location) == 4)
        {
            addressBook.contactCount++;
        }
        fclose(fp);
    }
    int opt;
    while (1)
    {
        printf("\n===== ADDRESS BOOK MENU =====\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                add_contact(&addressBook);
                break;
            case 2:
                search_contact(&addressBook);
                break;
            case 3:
                edit_contact(&addressBook);
                break;
            case 4:
                delete_contact(&addressBook);
                break;
            case 5:
                list_contacts(&addressBook);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}