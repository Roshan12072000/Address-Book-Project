#include<stdio.h>
#include "contact1.h"
// #include "dummy_contact.h"

int main()
{
    //all function calls should be inside the main 

    // creating structure variable
    AddressBook addressBook;
    int choice,flag = 0;
    // initializing the address book
    initialize(&addressBook);
  
    
  L1 :  printf("Menu:\n");choice = 0;
    printf("1. Add Contact\n2. Delete Contact\n3. Search Contact\n4. Edit Contact\n5. List Contact\n6. Save contact\n7. Exit\n");
     printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: createContact(&addressBook);
        break;
        case 2: deleteContact(&addressBook);
        break;
        case 3: searchContact(&addressBook);
        break;
        case 4: editContact(&addressBook);
        break;
        case 5: listContacts(&addressBook); 
        break;
        case 6: savecontact(&addressBook);
        break;
        case 7: goto exit;
        break;
        default : 
        printf("You have entered invalid option!!!\nPlease enter a valid option.\n");
    }
    getchar();
    goto L1;
    exit:
   return 0;

}


