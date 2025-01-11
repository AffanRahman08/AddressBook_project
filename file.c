#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  //Opening the contact.txt file
  FILE *fp = fopen("contacts.txt", "w");

  //print the contactcount to the file
  fprintf(fp, "%d\n", addressBook->contactCount);

  //print all the contacts
  for(int i = 0; i < addressBook->contactCount; i++)
  {
    fprintf(fp,"%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
  //close the file
  fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
   FILE *fp = fopen("contacts.txt", "r");

   //store the addresses from the file to the structure
   fscanf(fp, "%d\n", &addressBook->contactCount);
   for(int i = 0; i < addressBook->contactCount; i++)
   {
    fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
   } 
   //close the file
   fclose(fp);
}

