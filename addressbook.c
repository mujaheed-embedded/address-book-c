#include<stdio.h>
#include<string.h>
#include "addressbook.h"
void add_contact(struct AddressBook *addressBook)
{
    char phone[15];
    char email[50];
    while (1)
    {
        int validName = 1;
        int spaceCount = 0;
        printf("Enter Name: ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
        char *name = addressBook->contacts[addressBook->contactCount].name;
        int len = strlen(name);
        if (len == 0)
        {
            printf("Name cannot be empty\n");
            continue;
        }
        if (name[0] == ' ' || name[len - 1] == ' ')
        {
            printf("Name should not start or end with space\n");
            continue;
        }
        for (int i = 0; name[i] != '\0'; i++)
        {
            char ch = name[i];
            if (ch == ' ')
            {
                spaceCount++;
                if (spaceCount > 1)
                {
                    validName = 0;
                    break;
                }
            }
            else if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            {
                validName = 0;
                break;
            }
        }
        if (!validName)
        {
            printf("Name should contain only alphabets and not more than one space\n");
            continue;
        }
        break;
    }
    while (1)
    {
        int valid = 1;
        printf("Enter Phone: ");
        scanf("%s", phone);
        if (!(phone[0] == '6' || phone[0] == '7' || phone[0] == '8' || phone[0] == '9'))
        {
            printf("Phone must start with 6, 7, 8, or 9\n");
            valid = 0;
        }
        if (strlen(phone) != 10)
        {
            printf("Phone number must be exactly 10 digits\n");
            valid = 0;
        }
        for (int i = 0; phone[i] != '\0'; i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                printf("Phone must contain only digits\n");
                valid = 0;
                break;
            }
        }
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, phone) == 0)
            {
                printf("Phone number already exists\n");
                valid = 0;
            }
        }
        if (valid)
            break;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    while (1)
    {
        int valid = 1;
        printf("Enter Email: ");
        scanf("%s", email);
        int len = strlen(email);
        if (len < 10 || strcmp(email + len - 10, "@gmail.com") != 0)
        {
            printf("Email must contain @gmail.com\n");
            valid = 0;
        }
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, email) == 0)
            {
                printf("Email already exists\n");
                valid = 0;
            }
        }
        if (valid)
            break;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    printf("Enter Location: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].location);
    addressBook->contactCount++;
    printf("\nContact added successfully!\n");
    printf("Total contacts: %d\n", addressBook->contactCount);
    save_contacts(addressBook);
    printf(".........Contact Saving........\n");
}
void search_contact(struct AddressBook *addressBook)
{
    char phone[15];
    int found = -1;
    printf("Enter phone number to search: ");
    scanf("%s", phone);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Contact not found\n");
        return;
    }
    printf("\nContact Found:\n");
    printf("Name  : %s\n", addressBook->contacts[found].name);
    printf("Phone : %s\n", addressBook->contacts[found].phone);
    printf("Email : %s\n", addressBook->contacts[found].email);
    printf("Location : %s\n", addressBook->contacts[found].location);
}
void edit_contact(struct AddressBook *addressBook)
{
    char phone[15];
    int found = -1;
    printf("Enter phone number to edit: ");
    scanf("%s", phone);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Contact not found\n");
        return;
    }
    printf("\nCurrent Details:\n");
    printf("Name  : %s\n", addressBook->contacts[found].name);
    printf("Phone : %s\n", addressBook->contacts[found].phone);
    printf("Email : %s\n", addressBook->contacts[found].email);
    printf("Location : %s\n", addressBook->contacts[found].location);
    int opt;
    printf("\nWhich detail do you want to edit?\n");
    printf("1. Name\n2. Phone\n3. Email\n4. Location\n5. All Details\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", addressBook->contacts[found].name);
            break;
        case 2:
            printf("Enter new phone: ");
            scanf("%s", addressBook->contacts[found].phone);
            break;
        case 3:
            printf("Enter new email: ");
            scanf("%s", addressBook->contacts[found].email);
            break;
        case 4:
            printf("Enter new Location: ");
            scanf(" %[^\n]", addressBook->contacts[found].location);
            break;
        case 5:
            scanf(" %[^\n]", addressBook->contacts[found].name);
            scanf("%s", addressBook->contacts[found].phone);
            scanf("%s", addressBook->contacts[found].email);
            printf("Enter Location: ");
            scanf(" %[^\n]", addressBook->contacts[found].location);
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    printf("Contact updated successfully!\n");
    save_contacts(addressBook);
    printf(".........Contact Saving........\n");
}
void delete_contact(struct AddressBook *addressBook)
{
    char phone[15];
    int found = -1;
    char confirm;
    printf("Enter phone number to delete: ");
    scanf("%s", phone);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Contact not found\n");
        return;
    }
    printf("\nContact Found:\n");
    printf("Name  : %s\n", addressBook->contacts[found].name);
    printf("Phone : %s\n", addressBook->contacts[found].phone);
    printf("Email : %s\n", addressBook->contacts[found].email);
    printf("Location : %s\n", addressBook->contacts[found].location);
    printf("\nAre you sure you want to delete? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm != 'y' && confirm != 'Y')
    {
        printf("Deletion cancelled\n");
        return;
    }
    for (int i = found; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact deleted successfully!\n");
    printf("Total contacts: %d\n", addressBook->contactCount);
    save_contacts(addressBook);
    printf(".........Contact Saving........\n");
}
void list_contacts(struct AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("No contacts available\n");
        return;
    }
    struct Contact temp[100];
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        temp[i] = addressBook->contacts[i];
    }
    for (int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0)
            {
                struct Contact t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    printf("\n----- Contact List (Sorted by Name) -----\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", temp[i].name);
        printf("Phone : %s\n", temp[i].phone);
        printf("Email : %s\n", temp[i].email);
        printf("Location : %s\n", temp[i].location);
    }
}
void save_contacts(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv", "w");
    if (fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email,
                addressBook->contacts[i].location);
    }
    fclose(fp);
}