#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    printf("-------------------------------------------------------\n");
    printf("               ENTERED INTO LIST CONTACT               \n");
    printf("-------------------------------------------------------\n");   
    // Sort contacts based on the chosen criteria
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

/*void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}*/

//for validation of name which has been created
int isValidName(char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int isValidPhone(char *phone) {
    if (strlen(phone) != 10) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}

int isValidEmail(char *email) {
    int atFound = 0;
    int dotFound = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            if (atFound || i == 0 || i == strlen(email) - 1) {
                return 0;
            }
            atFound = 1;
        } else if(email[i] == '.'){
            if(i == 0 || i == strlen(email) - 1 || !atFound){
                return 0;
            }
            dotFound = 1;
        } 
        else if (!islower(email[i]) && !isalpha(email[i])) {
            return 0;
        }
    }
    return atFound && dotFound;
}

void createContact(AddressBook *addressBook) {
    printf("-------------------------------------------------------\n");
    printf("               ENTERED INTO CREATE CONTACT             \n");
    printf("-------------------------------------------------------\n");
    if (addressBook->contactCount >= 100) {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    char name[100], phone[100], email[100];
    do {
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
        if (!isValidName(name)) {
        printf("Invalid name. Name should only contain alphabets.\n");
     }
    } while (!isValidName(name));
    
    do {
       printf("Enter the phone number: ");
       scanf(" %[^\n]", phone);
       if (!isValidPhone(phone)) {
       printf("Invalid phone number. Phone number must contain exactly 10 digits.\n");
     }
    } while (!isValidPhone(phone));
    
    do{
      printf("Enter the email: ");
      scanf(" %[^\n]", email);
      if (!isValidEmail(email)) {
      printf("Invalid email. Email should only contain alphabets in lower case and one '@'.\n");
     }
    } while (!isValidEmail(email));
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    addressBook->contactCount++;
    printf("Contact added successfully.\n");
}


void searchContact(AddressBook *addressBook) 
{
    printf("-------------------------------------------------------\n");
    printf("               ENTERED INTO SEARCH CONTACT             \n");
    printf("-------------------------------------------------------\n");
    /* Define the logic for search */
    int sch;
    char str[100];
    int flag = 0;
    printf("Enter the input:\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
    scanf("%d", &sch);

    switch(sch)
    {
        case 1:
         {
            printf("Enter the name: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].name, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
    
          case 2:
         {
            printf("Enter the Phone_no: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].phone, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
         
          case 3:
         {
            printf("Enter the Email: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].email, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
         default:
          printf("Invalid Input\n");
    }
}

void editContact(AddressBook *addressBook)
{
    printf("-------------------------------------------------------\n");
    printf("               ENTERED INTO EDIT CONTACT               \n");
    printf("-------------------------------------------------------\n");
	/* Define the logic for Editcontact */
     int sch;
    char str[100];
    int flag = 0;
    printf("Enter the input:\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
    scanf("%d", &sch);

    switch(sch)
    {
        case 1:
         {
            printf("Enter the name: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].name, str) == 0)
                {
                    printf("%s\t%s\t%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    printf("Want to edit\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
                    int ech;
                    scanf("%d", &ech);
                    getchar();
                    switch(ech)
                    {
                        case 1:
                        {
                            char estr[100];
                            printf("Enter the name you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].name, estr);
                            break;
                        }
                        case 2:
                        {
                            char estr[100];
                            printf("Enter the phone_no you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].phone, estr);
                            break;
                        } 
                        case 3:
                        {
                            char estr[100];
                            printf("Enter the email you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].email, estr);
                            break;
                        } 
                        default: 
                        printf("Invalid option\n"); 
                        break;  
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
    
          case 2:
         {
            printf("Enter the Phone_no: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].phone, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    printf("Want to edit\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
                    int ech;
                    scanf("%d", &ech);
                    getchar();
                    switch(ech)
                    {
                        case 1:
                        {
                            char estr[100];
                            printf("Enter the name you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].name, estr);
                            break;
                        }
                        case 2:
                        {
                            char estr[100];
                            printf("Enter the phone_no you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].phone, estr);
                            break;
                        } 
                        case 3:
                        {
                            char estr[100];
                            printf("Enter the email you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].email, estr);
                            break;
                        }
                        default: 
                        printf("Invalid option\n"); 
                        break;   
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
         
          case 3:
         {
            printf("Enter the Email: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].email, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    printf("Want to edit\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
                    int ech;
                    scanf("%d", &ech);
                    getchar();
                    switch(ech)
                    {
                        case 1:
                        {
                            char estr[100];
                            printf("Enter the name you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].name, estr);
                            break;
                        }
                        case 2:
                        {
                            char estr[100];
                            printf("Enter the phone_no you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].phone, estr);
                            break;
                        } 
                        case 3:
                        {
                            char estr[100];
                            printf("Enter the email you want to display: ");
                            scanf("%[^\n]", estr);
                            strcpy(addressBook->contacts[i].email, estr);
                            break;
                        }
                        default: 
                        printf("Invalid option\n"); 
                        break;   
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
         default:
          printf("Invalid Input\n");
    }
    
}

void deleteContact(AddressBook *addressBook)
{
    printf("-------------------------------------------------------\n");
    printf("               ENTERED INTO DELETE CONTACT             \n");
    printf("-------------------------------------------------------\n");
	/* Define the logic for deletecontact */
    int sch;
    char str[100];
    char ch;
    int flag = 0;
    printf("Enter the input:\n1. Name\n2. Phone_no\n3. Email\nEnter the choice : ");
    scanf("%d", &sch);

    switch(sch)
    {
        case 1:
         {
            printf("Enter the name: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].name, str) == 0)
                {
                    printf("%s\t%s\t%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    
                    printf("Do you want to delete it(y/n)?\nEnter the choice : ");
                    getchar();
                    scanf("%c", &ch);
                    if(ch  == 'y' || ch == 'Y')
                    {
                        for(int j = i; j < addressBook-> contactCount - 1; j++)
                        {
                              strcpy(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
                              strcpy(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone); 
                              strcpy(addressBook->contacts[j].email, addressBook->contacts[j + 1].email); 
                        }
                        addressBook->contactCount--;
                        printf("Contact deleted successfully.\n");
                    }
                    flag = 1;
                    break;
                        
                }
                    
            }
             if(flag == 0)
             {
                printf("Contact not found\n");
             }
             break;
         }
          case 2:
         {
            printf("Enter the Phone_no: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].phone, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    printf("Do you want to delete it(y/n)?\nEnter the choice : ");
                    getchar();
                    scanf("%c", &ch);
                    if(ch  == 'y' || ch == 'Y')
                    {
                        for(int j = i; j < addressBook-> contactCount - 1; j++)
                        {
                              strcpy(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
                              strcpy(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone);
                              strcpy(addressBook->contacts[j].email, addressBook->contacts[j + 1].email);
                        }
                        addressBook->contactCount--;
                        printf("Contact deleted successfully.\n");
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
         }
         
          case 3:
         {
            printf("Enter the Email: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook-> contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].email, str) == 0)
                {
                    printf("%s\t%s\t%s",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    printf("Do you want to delete it(y/n)?\nEnter the choice : ");
                    getchar();
                    scanf("%c", &ch);
                    if(ch  == 'y' || ch == 'Y')
                    {
                        for(int j = i; j < addressBook-> contactCount - 1; j++)
                        {
                            strcpy(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
                            strcpy(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone);
                            strcpy(addressBook->contacts[j].email, addressBook->contacts[j + 1].email);
                        }
                        addressBook->contactCount--;
                        printf("Contact deleted successfully.\n");
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Contact not found\n");
            }
            break;
        }
          default:
           printf("Invalid Input\n");
   }
}

