#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50
#define MAX_CAT_LEN 20

typedef struct {
    char description[MAX_DESC_LEN];
    char category[MAX_CAT_LEN];
    float amount;
} Expense;

void saveToFile(Expense expenses[], int count, float budget, float spent) {
    FILE *fp = fopen("expense_summary.txt", "w");
    if (!fp) {
        printf("Error saving file.\n");
        return;
    }

    fprintf(fp, "Event Budget Summary\n");
    fprintf(fp, "Total Budget: %.2f\n", budget);
    fprintf(fp, "Total Spent: %.2f\n", spent);
    fprintf(fp, "Remaining: %.2f\n\n", budget - spent);

    fprintf(fp, "Expenses:\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "- %s (%s): %.2f\n", expenses[i].description, expenses[i].category, expenses[i].amount);
    }

    fclose(fp);
    printf("Summary saved to 'expense_summary.txt'\n");
}

void categoryTotals(Expense expenses[], int count) {
    printf("\nCategory-wise totals:\n");
    int visited[MAX_EXPENSES] = {0};

    for (int i = 0; i < count; i++) {
        if (visited[i]) continue;

        float total = expenses[i].amount;
        visited[i] = 1;

        for (int j = i + 1; j < count; j++) {
            if (!visited[j] && strcmp(expenses[i].category, expenses[j].category) == 0) {
                total += expenses[j].amount;
                visited[j] = 1;
            }
        }

        printf("%s: %.2f\n", expenses[i].category, total);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    float totalBudget = 0.0;
    float totalSpent = 0.0;
    int choice;

    printf("Event Budget Management System\n");
    printf("Enter initial budget: ");
    scanf("%f", &totalBudget);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Delete Expense\n");
        printf("4. Edit Expense\n");
        printf("5. Category-wise Total\n");
        printf("6. Save Summary to File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (expenseCount >= MAX_EXPENSES) {
                printf("Maximum expenses reached.\n");
                continue;
            }
            printf("Enter description: ");
            scanf(" %[^\n]", expenses[expenseCount].description);
            printf("Enter category: ");
            scanf(" %[^\n]", expenses[expenseCount].category);
            printf("Enter amount: ");
            scanf("%f", &expenses[expenseCount].amount);

            totalSpent += expenses[expenseCount].amount;
            expenseCount++;

            printf("Expense added.\n");

            if (totalSpent > totalBudget) {
                printf("⚠ WARNING: Budget exceeded by %.2f!\n", totalSpent - totalBudget);
            }

        } else if (choice == 2) {
            printf("\nBudget Summary:\n");
            printf("Total Budget: %.2f\n", totalBudget);
            printf("Total Spent: %.2f\n", totalSpent);
            printf("Remaining: %.2f\n", totalBudget - totalSpent);

            printf("\nExpenses:\n");
            for (int i = 0; i < expenseCount; i++) {
                printf("%d. %s (%s): %.2f\n", i + 1, expenses[i].description, expenses[i].category, expenses[i].amount);
            }

        } else if (choice == 3) {
            int index;
            printf("Enter expense number to delete: ");
            scanf("%d", &index);
            index--;

            if (index < 0 || index >= expenseCount) {
                printf("Invalid index.\n");
                continue;
            }

            totalSpent -= expenses[index].amount;

            for (int i = index; i < expenseCount - 1; i++) {
                expenses[i] = expenses[i + 1];
            }
            expenseCount--;

            printf("Expense deleted.\n");

        } else if (choice == 4) {
            int index;
            printf("Enter expense number to edit: ");
            scanf("%d", &index);
            index--;

            if (index < 0 || index >= expenseCount) {
                printf("Invalid index.\n");
                continue;
            }

            totalSpent -= expenses[index].amount;
            printf("Enter new description: ");
            scanf(" %[^\n]", expenses[index].description);
            printf("Enter new category: ");
            scanf(" %[^\n]", expenses[index].category);
            printf("Enter new amount: ");
            scanf("%f", &expenses[index].amount);
            totalSpent += expenses[index].amount;

            printf("Expense updated.\n");

        } else if (choice == 5) {
            categoryTotals(expenses, expenseCount);

        } else if (choice == 6) {
            saveToFile(expenses, expenseCount, totalBudget, totalSpent);

        } else if (choice == 7) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}