# Address Book Application in C

A modular command-line interface (CLI) Address Book application developed in pure C. This project demonstrates core low-level programming fundamentals essential for embedded systems development.

## 🚀 Key Technical Concepts Demonstrated
- **Data Structures:** Utilized custom `struct` definitions to model contact records efficiently.
- **File I/O Handling:** Implemented persistent storage mechanisms using `fopen`, `fwrite`, `fread`, and `fclose` to stream and save active data blocks directly to a `.csv` file.
- **String Filtering & Parsing:** Used robust string manipulation functions (`strcmp`, `strncmp`) to query, filter, and match user inputs against storage records.
- **Memory Management:** Handled structured arrays and buffers with careful pointer manipulation.
- **Modular Code Design:** Divided software architecture into separate header files (`.h`) and source code implementation files (`.c`).

## 🛠️ Features
- **Print Specific Contact:** Search and print detailed records for a particular person.
- **Print All Contacts:** Formatted command-line view of the complete database stored in system memory.
- **Save Contacts:** Manual and automatic persistent file-saving features to secure contact logs.
- Add new contacts with input validations.
- Search contacts by name, email, or phone number.
- Edit and update existing contact details.
- Delete contact entries safely from the system.
