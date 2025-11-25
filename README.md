****Abstract****

The Event Budget Management System is a console-based C application designed to help users efficiently manage and track expenses for any event. The system allows users to set an initial budget and then record various expenses by providing a description, category, and amount. It automatically calculates the total spent amount, remaining balance, and displays a complete summary of all recorded expenses.

Additional features include editing and deleting expenses, generating category-wise totals, and saving a detailed summary to a text file for future reference. The program also alerts the user when the total spending exceeds the allocated budget. By using structured programming, arrays, and file handling, this system provides a simple yet effective solution for organizing event finances. It is especially useful for students, organizers, and anyone planning events who need a basic financial management tool.

****Project Features****

**1. Add Expense**

Users can add a new expense with:

Description

Category

Amount


The system updates the total spent amount automatically.


**2. View Budget Summary**

Displays:

Total Budget

Total Amount Spent

Remaining Balance


Lists all expenses with index numbers.


**3. Delete Expense**

Users can delete an expense by entering its index number.

Automatically adjusts the total spent amount.


**4. Edit Expense**

Allows modification of:

Description

Category

Amount


Recalculates the total spent.


**5. Category-wise Total**

Displays the sum of expenses for each category.

Helps users identify which area spent the most.


**6. Save Summary to File**

Saves:

Total Budget

Total Spent

Remaining

Complete expense list


File name: expense_summary.txt


**7. Budget Exceed Warning**

Shows a ⚠ warning when total expenses exceed the budget.


**8. User-Friendly Menu**

Easy navigation through a menu-driven interface.


**9. Exit Option**

Safely exit the program without losing any data.

🔹 METHOD 1: Run in Code::Blocks (Recommended)

Step 1: Open Code::Blocks

Launch Code::Blocks IDE.


Step 2: Create a New Project

Click File → New → Project

Select Console Application

Choose C language

Click Next → Next


Step 3: Replace the main.c Code

On the left side, open main.c

Delete the default code

Paste your entire program into the file.


Step 4: Build the Program

Click Build → Build and Run
or simply press F9


Step 5: Use the Menu

The console window will appear.

Enter the budget and then follow the menu options:

Add Expense

View Summary

Delete Expense

Edit Expense

Save to File

Exit






🔹 METHOD 2: Run Using GCC in Command Prompt (Windows)

Step 1: Install MinGW (if not installed)

Install MinGW from its official download page.

Add gcc to PATH.


Step 2: Save the Program

Save your code as:
budget.c


Step 3: Open Command Prompt

Press Win + R, type cmd, press Enter.


Step 4: Compile the Program

Go to the folder containing the file:

cd path\to\your\file

Compile:

gcc budget.c -o budget

Step 5: Run the Program

budget

Your menu will appear, and you can start using the program.




🔹 METHOD 3: Run Using GCC in Linux / macOS Terminal

Step 1: Save the File

Save as budget.c

Step 2: Open Terminal

Navigate to your file:

cd /path/to/file

Step 3: Compile

gcc budget.c -o budget

Step 4: Run

./budget




🔹 METHOD 4: Use an Online Compiler (Fastest)

You can run your code quickly using online C compilers such as:

OnlineGDB

Replit

Programiz C Compiler

JDoodle


Steps:

1. Open any online compiler.


2. Create a new C project.


3. Paste the code into the editor.


4. Click Run.




---
