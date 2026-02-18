# 📒 Address Book Management System in C

## 📌 About the Project

This project is a console-based **Address Book Management System** developed using the C programming language.
It is designed to store and manage contact details such as name, phone number, and email address in an organized way.

The application performs operations like adding new contacts, searching existing records, editing details, and deleting contacts.
All the information is stored in files, so the data remains saved even after the program is closed.

This project mainly focuses on implementing file handling concepts, structured data storage, and modular programming in C.

---

## ⚙️ How the System Works

The program runs using a simple **menu-driven interface**.

Users can choose different operations by entering the corresponding menu number.

### Basic Working Flow:

1. The user selects an option from the menu.
2. Based on the choice, the program performs the required operation.
3. Contact data is read from or written into a file.
4. Any changes made are saved permanently.

The system supports handling multiple contacts and allows searching or editing using different fields like name, phone number, or email.

---

## 🚀 Features

* Add new contacts
* Search contacts by:

  * Name
  * Phone number
  * Email
* Edit contact information
* Delete contact records
* Display all saved contacts
* Phone number validation
* File-based data storage
* User-friendly menu interface

---

## 🛠️ Technologies Used

* C Programming Language
* File Handling Concepts
* Structures
* Modular Programming
* CSV / Text File Storage

---

## 📂 Project Structure

```
Address_book/
│
├── main.c
├── contact.c
├── contact.h
├── data.csv
├── README.md
```

---

## ▶️ How to Compile and Run

### On Linux / Mac

```
gcc *.c -o addressbook
./addressbook
```

### On Windows

```
gcc *.c -o addressbook.exe
addressbook.exe
```

---

## 🖥️ Sample Functionalities

* Adding a new contact with input validation
* Searching multiple contacts with the same name
* Editing contact details using serial number
* Deleting a contact permanently
* Saving updated records into file storage

roshan@LAPTOP-M5TSS0P7:/mnt/c/Users/User/Documents/Emertxe_notes/Address_book$ ./a.out
Menu:
1. Add Contact
2. Delete Contact
3. Search Contact
4. Edit Contact
5. List Contact
6. Save contact
7. Exit
Enter the choice
5 
Si.No   Name            phone           gmail
1       Roshan Jameer   8431616748      roshan@gmail.com
2       Rohit           4545454545      hitman@45.com
3       Rohit           5412541251      qwer@45.com
4       jaffer sadiq    9012210978      sadiq@gmail.com
5       Rohit           7353420768      abcd@gmail.com
6       Raghu Patel     7353420024      raghu@gmail.com
Menu:
1. Add Contact
2. Delete Contact
3. Search Contact
4. Edit Contact
5. List Contact
6. Save contact
7. Exit
Enter the choice
1
Enter Your Name : Ramanujan 
Enter Number : 85213647610                  
Invalid Entry of Phone Number!
Enter Number : 8521364761
Enter Your email : ramanujan@gmail.com
Menu:
1. Add Contact
2. Delete Contact
3. Search Contact
4. Edit Contact
5. List Contact
6. Save contact
7. Exit
Enter the choice
5
Si.No   Name            phone           gmail
1       Roshan Jameer   8431616748      roshan@gmail.com
2       Rohit           4545454545      hitman@45.com
3       Rohit           5412541251      qwer@45.com
4       jaffer sadiq    9012210978      sadiq@gmail.com
5       Rohit           7353420768      abcd@gmail.com
6       Raghu Patel     7353420024      raghu@gmail.com
7       Ramanujan       8521364761      ramanujan@gmail.com
Menu:
1. Add Contact
2. Delete Contact
3. Search Contact
4. Edit Contact
5. List Contact
6. Save contact
7. Exit
Enter the choice
6
Menu:
1. Add Contact
2. Delete Contact
3. Search Contact
4. Edit Contact
5. List Contact
6. Save contact
7. Exit
Enter the choice
7
roshan@LAPTOP-M5TSS0P7:/mnt/c/Users/User/Documents/Emertxe_notes/Address_book$

---

## 🎯 Applications / Use Cases

* Personal contact management
* Employee directory systems
* Student record storage
* Small office contact tracking
* Learning project for file handling in C

This project can also be extended into a database-driven system in the future.

---

## 📚 Key Learning Outcomes

While working on this project, the following concepts were practiced:

* File handling in C
* Data persistence techniques
* Record management
* CRUD operations
* Menu-driven program design
* Input validation

---

## 👨‍💻 Author

**Roshan Jameer**
GitHub: https://github.com/Roshan12072000

---

## 📜 Note

This project was developed for educational and learning purposes as part of C programming practice.
