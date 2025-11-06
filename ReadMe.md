# Expense Tracker

Build a simple expense tracker to manage your finances. Start building, submit your solution, and get feedback from the community.

---

## Overview

The Expense Tracker application allows users to manage their finances by adding, updating, deleting, and viewing expenses. It also provides summaries of expenses overall or for a specific month.

---

## Requirements

The application should run from the command line and include the following features:

- Add an expense with a description and amount.
- Update an existing expense.
- Delete an expense.
- View all expenses.
- View a summary of all expenses.
- View a summary of expenses for a specific month (of the current year).

### Optional Additional Features

- Add expense categories and filter expenses by category.
- Set a monthly budget and display a warning when exceeded.
- Export expenses to a CSV file.

---

## Example Commands

```bash
$ expense-tracker add --description "Lunch" --amount 20
# Expense added successfully (ID: 1)

$ expense-tracker add --description "Dinner" --amount 10
# Expense added successfully (ID: 2)

$ expense-tracker list
# ID  Date        Description  Amount
# 1   2024-08-06  Lunch        $20
# 2   2024-08-06  Dinner       $10

$ expense-tracker summary
# Total expenses: $30

$ expense-tracker delete --id 2
# Expense deleted successfully

$ expense-tracker summary
# Total expenses: $20

$ expense-tracker summary --month 8
# Total expenses for August: $20
