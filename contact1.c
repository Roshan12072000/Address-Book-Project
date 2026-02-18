#include <stdio.h>
#include <string.h>
#include "contact1.h"
// #include "dummy_contact.h"
void loadcontact(AddressBook *addressBook);
void validation_num(char *temp_num);
void validation_email(char *temp_gmail);
//void listContacts(AddressBook *addressBook);

void edit_by_name(AddressBook *addressBook);
void edit_by_number(AddressBook *addressBook);
void edit_by_email(AddressBook *addressBook);
void delete_by_name(AddressBook *addressBook);
void delete_by_number(AddressBook *addressBook);
void delete_by_email(AddressBook *addressBook);


//void populate(AddressBook *addressBook);
void  search_name(AddressBook *addressBook,int*);
int search_number(AddressBook *addressBook);
int search_email(AddressBook *addressBook);
void validation_email(char *temp_gmail);
void validation_num(char *temp_num);

void listContacts(AddressBook *addressBook)
{
  // printf all data from the adress book
  printf("Si.No\tName\t\tphone\t\tgmail\n");
  for (int i = 0; i < addressBook->contactCount; i++)
  {
    printf("%d\t%-14s\t%-10s\t%-20s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
}

void initialize(AddressBook *addressBook)
{
  // fetch data from dummyContacts and load into address book
  // addressBook->contactCount = 0;
  // populate(addressBook);
  loadcontact(addressBook);
  // listContacts(addressBook);
}
void loadcontact(AddressBook *addressBook)
{
  FILE *fptr = fopen("data.csv", "r");
  int i;
  if (fptr == NULL)
  {
    perror("ERROR");
    return;
  }
  fscanf(fptr, "#%d#\n", &addressBook->contactCount);
  for (i = 0; i < addressBook->contactCount; i++)
  {
    fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
  fclose(fptr);
}
void savecontact(AddressBook *addressBook)
{
  FILE *fptr = fopen("data.csv", "w");
  int i;
  if (fptr == NULL)
  {
    perror("ERROR");
    return;
  }
  fprintf(fptr, "#%d#\n", addressBook->contactCount);
  for (i = 0; i < addressBook->contactCount; i++)
  {
    fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
  fclose(fptr);
}
void createContact(AddressBook *addressBook)
{
  int i, flag = 0;
  char temp_num[10], temp_gmail[40];
  printf("Enter Your Name : ");
  scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
L1:
  validation_num(temp_num);
  for (i = 0; i < addressBook->contactCount; i++)
  {
    if (strstr(addressBook->contacts[i].phone, temp_num) != NULL)
    {
      printf("This number is already present in the list\n");
      goto L1;
    }
  }
  strcpy(addressBook->contacts[addressBook->contactCount].phone, temp_num);
L2:
  validation_email(temp_gmail);
  for (i = 0; i < addressBook->contactCount; i++)
  {
    if (strstr(addressBook->contacts[i].email, temp_gmail) != NULL)
    {
      printf("This email is already present in the list\n");
      goto L2;
    }
  }

  strcpy(addressBook->contacts[addressBook->contactCount].email, temp_gmail);
  addressBook->contactCount++;
}
void searchContact(AddressBook *addressBook)
{
  int choice = 0, i = 0;
  int count = 0;
  printf("Enter option to search by\n1. Name\n2. Contact\n3. Gmail\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    search_name(addressBook, &count);
    break;
  case 2:
  {
    i = search_number(addressBook);
    printf("Name : %s\nPh.No : %s\nemail : %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    break;
  }
  case 3:
  {
    i = search_email(addressBook);
    printf("Name : %s\nPh.No : %s\nemail : %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    break;
  }
  }
}

void editContact(AddressBook *addressBook)
{
  int choice = 0;
  printf("Enter choice to edit by :\n1. Name\n2. Phone\n3. Email\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    edit_by_name(addressBook);
    break;
  case 2:
    edit_by_number(addressBook);
    break;
  case 3:
    edit_by_email(addressBook);
    break;
  }
}

void deleteContact(AddressBook *addressBook)
{
  int choice = 0;
  printf("Enter choice to delete contact\n1. Name\n2. Number\n3. Email\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    delete_by_name(addressBook);
    break;
  case 2:
    delete_by_number(addressBook);
    break;
  case 3:
    delete_by_email(addressBook);
    break;
  }
}
void edit_by_name(AddressBook *addressBook)
{
  int i, count = 0;
  search_name(addressBook, &count);
  printf("Enter contact Si.No to edit the contact \n");
  scanf("%d", &i);
  if (count > 0)
  {
    int choice = 0;
    printf("Enter choice to edit by :\n1. Name\n2. Phone\n3. Email\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      printf("Enter New Name : ");
      scanf(" %[^\n]", addressBook->contacts[i - 1].name);

      break;
    }
    case 2:
    {
      char temp_num[15];
      validation_num(temp_num);
      strcpy(addressBook->contacts[i - 1].phone, temp_num);
      break;
    }
    case 3:
    {
      char temp_gmail[30];
      validation_email(temp_gmail);
      strcpy(addressBook->contacts[i - 1].email, temp_gmail);
      break;
    }
    }
  }
  else
  {printf("count = %d\n",count);
    printf("Enter New Name : ");
    scanf(" %[^\n]", addressBook->contacts[i - 1].name);
  }
  printf("Edit is successfully completed!!!\n");
}
void edit_by_number(AddressBook *addressBook)
{
  char temp_num[10];
  int i = search_number(addressBook);
  printf("Enter New Number below \n");
  validation_num(temp_num);
  strcpy(addressBook->contacts[i].phone, temp_num);
  printf("Edit is successfully completed!!!\n");
}
void edit_by_email(AddressBook *addressBook)
{
  char temp_email[30];
  int i = search_email(addressBook);
  printf("Enter New email below\n");
  validation_email(temp_email);
  strcpy(addressBook->contacts[i].email, temp_email);
  printf("Edit is successfully completed!!!\n");
}
void delete_by_name(AddressBook *addressBook)
{
  int index, count = 0;
  search_name(addressBook, &count);
  printf("Enter contact Si.No to delete the contact \n");
  scanf("%d", &index);
  
  for (int i = index - 1; i < addressBook->contactCount; i++)
  {
    addressBook->contacts[i] = addressBook->contacts[i + 1];
  }
  addressBook->contactCount--;
  printf("Successfully  contact deleted!!!\n");
}
void delete_by_number(AddressBook *addressBook)
{
  int index = search_number(addressBook);
  for (int i = index; i < addressBook->contactCount; i++)
  {
    addressBook->contacts[i] = addressBook->contacts[i + 1];
  }
  printf("Successfully deleted contact!!!\n");
  addressBook->contactCount--;
}
void delete_by_email(AddressBook *addressBook)
{
  int index = search_email(addressBook);
  for (int i = index; i < addressBook->contactCount; i++)
  {
    addressBook->contacts[i] = addressBook->contacts[i + 1];
  }
  printf("Successfully deleted contact!!!\n");
  addressBook->contactCount--;
}
void search_name(AddressBook *addressBook,int *count)
{
    char temp_name[20];
    int i, val,flag = 0;
again : printf("Enter Name : ");
    scanf(" %[^\n]", temp_name);
    for (i = 0; i < addressBook->contactCount; i++)
    {
        val = strcmp(addressBook->contacts[i].name, temp_name);
        if (val == 0)
        {for(int j = 0; j < 100; j++) printf("-");
        (*count)++;
           printf("\nSi.No : %d\nName : %s\nPh.No : %s\nemail : %s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        flag = 1;
        for(int j = 0; j < 100; j++) printf("-");
        printf("\n");
        }
    }
    if(flag == 0)
        {
        printf("The Name is not found!!!\n");
        goto again;
    }
}
int search_number(AddressBook *addressBook)
{
    char temp_num[15];
    int  i, res;
    again : validation_num(temp_num);

    for (i = 0; i < addressBook->contactCount; i++)
    {
        res = strcmp(addressBook->contacts[i].phone, temp_num);
        if (res == 0)
        {
            break;
        }
    }
    if (res == 0)
    {
        return i;
    }
    else
    {
        printf("The number is not found!!!\n");
        goto again;
    }
}
int search_email(AddressBook *addressBook)
{
    char temp_gmail[30];
    int i, res;
again : validation_email(temp_gmail);
    for (i = 0; i < addressBook->contactCount; i++)
    {
         res = strcmp(addressBook->contacts[i].email, temp_gmail);
        if (res == 0)
        {
            break;
        }
    }
    if (res == 0)
    {
        return i;
    }
    else
    {
        printf("The email is not found!!!\n");
        goto again;
    }
}
void validation_num(char *temp_num){
L1 : int i,flag = 0;
    printf("Enter Number : ");
    scanf(" %s", temp_num);
    for (i = 0; i < 10; i++)
    {
        if ((temp_num[i] >= 48 && temp_num[i] <= 57))
        {
            continue;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag || strlen(temp_num) < 10 || strlen(temp_num) > 10)
    {
        printf("Invalid Entry of Phone Number!\n");
        goto L1;
    }
}
void validation_email(char *temp_gmail){
     L2:printf("Enter Your email : ");
    scanf(" %[^\n]", temp_gmail);
    int len = strlen(temp_gmail); 
    if (strstr(temp_gmail, ".com") == NULL || strrchr(temp_gmail, '@') == NULL || strchr(temp_gmail, ' ') != NULL || temp_gmail[0] == '@' || strcmp(&temp_gmail[len - 4],".com") != 0)
    {
        printf("Invalid Entry of email!\n");
        goto L2;
    }
}