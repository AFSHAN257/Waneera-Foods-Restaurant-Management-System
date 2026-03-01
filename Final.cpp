#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

void processing(string text)
{
    cout << "\033[31m" << text;
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        usleep(100000);
    }
    cout << "\033[0m\n";
}

void type(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i];
        cout.flush();
        usleep(23000);
    }
    cout << endl;
}

void clear()
{
    cout << "\033[2J\033[1;1H";
}

int main()
{
    ofstream customer("customers.txt");
    customer << "Afshan 1234\n Areeba 5678 \n Ismail 9090\n";
    customer.close();
    int tables[10] = {0};
    int status;
    do
    {
        clear();
        type("\n\n\t\t\t\t\033[35m=================================\033[0m");
        type("\n\t\t\t\t\033[33m    Welcome to Waneera Foods     \033[0m");
        type("\t\t\t\t\033[35m=================================\033[0m");

        type("\n\t\t\t\t\033[36m1. Customer\n");
        type("\t\t\t\t2. Admin\n");
        type("\t\t\t\t3. Employee\n");
        type("\t\t\t\t4. Exit\n\033[0m");
        cout << "\t\t\t\t\033[35mEnter your choice: ";
        cin >> status;

        if (status == 2)
        {
            clear();
            processing("\n\t\t\t\tOpening Admin Portal");
            int admin;
            char decide = 'y';
            do
            {
                type("\n\t\t\t\t\033[34m=================================\033[0m\n");
                type("\t\t\t\t\033[1;35m\t   ADMIN PORTAL\t  \n");
                type("\t\t\t\t\033[34m=================================\033[0m\n");
                type("\n\t\t\t\t\033[32m1. View Products\n");
                type("\t\t\t\t2. View Invoice History\n");
                type("\t\t\t\t3. Sold Quantities\n");
                type("\t\t\t\t4. Back\n\033[0m");
                cout << "\t\t\t\t\033[31mEnter your Choice(1-4): ";
                cin >> admin;

                if (admin == 1)
                {
                    clear();
                    processing("\n\t\t\t\tLoading Products");
                    type("\n\t\t\t\t\033[34m=================================\033[0m\n");
                    type("\t\t\t\t\033[1;35m\t   Products\n\t   ");
                    type("\t\t\t\t\033[34m=================================\033[0m\n");
                    ifstream productsin("Products.txt");
                    string line;
                    while (getline(productsin, line))
                        cout << "\t\t\t\t" << line << endl;
                    productsin.close();
                }

                else if (admin == 2)
                {
                    clear();
                    processing("\n\t\t\t\tFetching Invoice History");
                    type("\n\t\t\t\t\033[34m=================================\033[0m\n");
                    type("\t\t\t\t\033[1;35m\t   Invoices\n");
                    type("\t\t\t\t\033[34m=================================\033[0m\n");
                    ifstream abcin("invoice.txt");

                    if (!abcin)
                    {
                        cout << "\t\t\t\tNo invoices found!\n";
                    }
                    else
                    {
                        string line;
                        while (getline(abcin, line))
                        {
                            cout << "\t\t\t\t\033[33m" << line << endl;
                        }
                    }

                    abcin.close();
                }
                else if (admin == 3)
                {
                    clear();
                    processing("\n\t\t\t\tCalculating Sales");
                    type("\n\t\t\t\t\033[34m=================================\033[0m\n");
                    type("\t\t\t\t\033[1;35m\t   Total Sales\n");
                    type("\t\t\t\t\033[34m=================================\033[0m\n");
                    int Qt[4][5] = {0};
                    ifstream abcin("invoice.txt");
                    string label;
                    int c, ch, q;
                    while (abcin >> label)
                    {
                        if (label == "Item:")
                        {
                            abcin >> c >> ch >> q;
                            Qt[c - 1][ch - 1] += q;
                        }
                    }
                    abcin.close();
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 5; j++)
                            if (Qt[i][j] > 0)
                                cout << "\033[32m\t\t\t\tCategory " << i + 1 << " Item " << j + 1 << " Qty " << Qt[i][j] << endl;
                }

                cout << "\n\t\t\t\t\033[35mDo you want to Continue as Admin? (y/n): \033[0m";
                cin >> decide;
            } while (decide == 'y' || decide == 'Y');
        }

        else if (status == 1)
        {
            clear();
            processing("\n\t\t\t\tLoading Customer Section");

            string user, pass, fuser, fpass;
            bool login = false;

            type("\n\t\t\t\t\033[34m=================================\033[0m\n");
            type("\t\t\t\t\033[1;35m\t CUSTOMER LOGIN\n");
            type("\t\t\t\t\033[34m=================================\033[0m\n");
            cout << "\t\t\t\t\033[32mUsername (or press 0 to skip login): ";
            cin >> user;

            if (user != "0")
            {
                cout << "\t\t\t\tPassword: ";
                cin >> pass;
                ifstream customerin("customers.txt");
                while (customerin >> fuser >> fpass)
                    if (user == fuser && pass == fpass)
                    {
                        login = true;
                        break;
                    }
                customerin.close();
            }

            if (login)
                cout << "\t\t\t\t\033[32mLogin Successful!\033[0m\n";
            else
                cout << "\t\t\t\t\033[31mGuest Mode Activated\033[0m\n";

            clear();
            processing("\n\t\t\t\tPreparing Menu");

            type("\033[31m\033[1m\n\t\t\t\t\t Welcome to Waneera Foods!\033[0m\n");
            type("\033[32m\t\t\t\t\t(*)====== Menu =====(*)\033[0m\n");
            cout << "\033[93m\t|==========================================================================================|" << endl;
            type("\t|                   Specialites               |                    Drinks                  |\n");
            cout << "\t|==========================================================================================|" << endl;
            cout << "\t|     Items              |        Price       |      Items            |       Price        |" << endl;
            cout << "\t|==========================================================================================|" << endl;
            cout << "\t|   1. Spicy Chicken     |        $12.0       |   1. Mineral Water    |        $1.0        |" << endl;
            cout << "\t|   2. Beef Steak        |        $18.0       |   2. Mint Margarita   |        $2.0        |" << endl;
            cout << "\t|   3. Fried Rice        |        $14.0       |   3. Lemonade         |        $3.0        |" << endl;
            cout << "\t|   4. Mutton Biryani    |        $20.0       |   4. Fresh Lime       |        $3.0        |" << endl;
            cout << "\t|   5. Grilled Fish      |        $16.0       |   5. Pina Colada      |        $4.0        |" << endl;
            cout << "\t|==========================================================================================|" << endl;
            type("\t|                   Appetizers                |                    Deserts                 |\n");
            cout << "\t|==========================================================================================|" << endl;
            cout << "\t|     Items              |  Price per Serving |      Items            |  Price per Serving |" << endl;
            cout << "\t|==========================================================================================|" << endl;
            cout << "\t|   1. Garlic Bread      |        $6.0        |   1. Cookie Dough     |        $4.0        |" << endl;
            cout << "\t|   2. Vegetable Salad   |        $8.0        |   2. Vanilla Bean     |        $5.0        |" << endl;
            cout << "\t|   3. French Fries      |        $4.0        |   3. Peanut Butter    |        $6.0        |" << endl;
            cout << "\t|   4. Nuggets           |        $5.0        |   4. Salted Caramel   |        $5.0        |" << endl;
            cout << "\t|   5. Spaghetti Pasta   |        $4.0        |   5. Chocolate cake   |        $7.0        |" << endl;
            cout << "\t|==========================================================================================|\033[0m" << endl;
            processing("\t\t\t\tProceeding...");
            type("\n\t\t\t\t\033[31m=================================\033[0m\n");
            type("\t\t\t\t\033[1;32m\t   PLACE ORDER\t  ");
            type("\n\t\t\t\t\033[31m=================================\033[0m\n");
            float prices[4][5] = {{12, 18, 14, 20, 16}, {1, 2, 3, 3, 4}, {6, 8, 4, 5, 4}, {4, 5, 6, 5, 7}};
            string items[4][5] = {{"Spicy Chicken", "Beef Steak", "Fried Rice", "Mutton Biryani", "Grilled Fish"}, {"Mineral Water", "Mint Margarita", "Lemonade", "Fresh Lime", "Pina Colada"}, {"Garlic Bread", "Vegetable Salad", "French Fries", "Nuggets", "Spaghetti Pasta"}, {"Cookie Dough", "Vanilla Bean", "Peanut Butter", "Salted Caramel", "Chocolate Cake"}};
            int cat, choice, serv, num;
            float total = 0;
            int order[4][5] = {0};
            char more = 'y';
            int table;
            float discount = 0;
            float ser = 0;

            do
            {
                cout << "\n\t\t\t\t\033[31mEnter Category (1-4): ";
                cin >> cat;

                cout << "\t\t\t\tHow many different items? ";
                cin >> num;

                for (int i = 1; i <= num; i++)
                {
                    cout << "\t\t\t\tEnter item choice (1-5): ";
                    cin >> choice;
                    cout << "\t\t\t\tEnter servings: ";
                    cin >> serv;

                    order[cat - 1][choice - 1] += serv;
                    total = total + prices[cat - 1][choice - 1] * serv;
                }

                cout << "\t\t\t\t\033[36mOrder from another category? (y/n): \033[0m";
                cin >> more;

            } while (more == 'y' || more == 'Y');
            clear();
            type("\n\t\t\t\t\033[32m=================================\033[0m\n");
            type("\t\t\t\t\033[1;31m\t     ORDER\t  \n");
            type("\t\t\t\t\033[32m=================================\033[0m\n");
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (order[i][j] > 0)
                    {
                        cout << "\t\t\t\tCategory " << i + 1 << " Item " << j + 1 << " - Qty: " << order[i][j] << " - Subtotal: $" << prices[i][j] * order[i][j] << endl;
                    }
                }
            }

            type("\n\t\t\t\t\033[34m=================================\033[0m\n");
            type("\t\t\t\t\033[1;35m\t  ORDER CONFIRMATION\t  \n");
            type("\t\t\t\t\033[34m=================================\033[0m\n");
            char confirm;
            cout << "\n\t\t\t\tDo you want to continue with this order? (y/n): ";
            cin >> confirm;
            if (confirm != 'y' && confirm != 'Y')
            {
                cout << "\t\t\t\tOrder cancelled!\n";
                total = 0;
            }
            else
            {
                cout << "\t\t\t\t\033[32mOrder confirmed. Proceeding to billing...\n\033[0m";

                char coupon;
                float discount = 0;
                clear();
                processing("\n\t\t\t\tLoading Coupon Service...");
                type("\n\t\t\t\t\033[31m=================================\033[0m\n");
                type("\t\t\t\t\033[1;32m\t   COUPON\t  \n");
                type("\t\t\t\t\033[31m=================================\033[0m\n");
                cout << "\t\t\t\tDo you have a 10% coupon? (y/n): ";
                cin >> coupon;
                if (coupon == 'y' || coupon == 'Y')
                {
                    discount = total * 0.10;
                    total = total - discount;
                }

                int choose;
                clear();
                processing("\n\t\t\t\tOpening Services Portal...");
                type("\n\t\t\t\t\033[36m=================================\033[0m\n");
                type("\t\t\t\t\033[1;33m\t   SERVICES\t  \n");
                type("\t\t\t\t\033[36m=================================\033[0m\n");
                cout << "\t\t\t\t\033[35mServices Available" << endl;
                cout << " \n\t\t\t\t\033[32m1. Dine In" << endl;
                cout << " \t\t\t\t2. Take Away" << endl;
                cout << " \t\t\t\t3. Home Delivery" << endl;
                cout << "\t\t\t\tChoose you Service(1-3):\033[0m";
                cin >> choose;
                if (choose == 1)
                {
                    cout << "\n\t\t\t\t\033[32mYou have choosen Dine In Service!" << endl;
                    cout << "\t\t\t\tService Charges (3$) added to your bill!" << endl;
                    total = total + 3;
                    ser = 3;
                    clear();
                    processing("\n\t\t\t\tOpening Table Booking...");
                    type("\n\t\t\t\t\033[35m=================================\033[0m\n");
                    type("\t\t\t\t\033[1;32m\t   TABLE BOOKING\t  \n");
                    type("\t\t\t\t\033[35m=================================\033[0m\n");
                    cout << "\t\t\t\tSelect Table (1-10): ";
                    cin >> table;
                    if (table < 1 || table > 10)
                    {
                        cout << "\t\t\t\tInvalid table number!\n";
                        continue;
                    }

                    if (tables[table - 1] == 1)
                    {
                        cout << "\t\t\t\tTable already occupied! Order cancelled.\n";
                        continue;
                    }
                    else
                    {
                        tables[table - 1] = 1;
                        cout << "\t\t\t\tTable " << table << " booked successfully.\n";
                    }
                }
                else if (choose == 2)
                {
                    cout << "\t\t\t\t\033[31mYou have choosen Take Away Service!" << endl;
                    cout << "\t\t\t\tPacking charges (1$) added to your bill!" << endl;
                    total = total + 1;
                    ser = 1;
                }
                else if (choose == 3)
                {
                    cout << "\t\t\t\t\033[33mYou have choosen Home Delivery Service!" << endl;
                    if (login)
                    {
                        cout << "\t\t\t\tAs a logged in Customer , Delivery Charges are free!" << endl;
                    }
                    else
                    {
                        cout << "\t\t\tDelivery Charges (4$) added to your bill!\033[0m" << endl;
                        total = total + 4;
                        ser = 4;
                    }
                }
                clear();
                processing("\n\t\t\t\tOpening Billing Portal...");
                type("\n\t\t\t\t\033[32m=================================\033[0m\n");
                type("\t\t\t\t\033[1;31m\t   BILLING SECTION \t  \n");
                type("\t\t\t\t\033[32m=================================\033[0m\n");
                cout << "\t\t\t\tItem Name\tQty\tPrice\tSubtotal\n";
                cout << "\t\t\t\t-----------------------------------------\n";

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (order[i][j] > 0)
                        {
                            cout << "\t\t\t\t" << items[i][j] << "\t" << order[i][j] << "\t$" << prices[i][j] << "\t$" << prices[i][j] * order[i][j] << endl;
                        }
                    }
                }

                if (discount > 0)
                    cout << "\t\t\t\tDiscount:\t\t-$" << discount << endl;
                cout << "\t\t\t\tService Charges:\t$" << ser << endl;
                cout << "\t\t\t\tTOTAL BILL:\t\t$" << total << endl;

                ofstream abcin("invoice.txt", ios::app);
                abcin << "Customer: " << user << endl;
                abcin << "Item Name\tQty\tPrice\tSubtotal\n";

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (order[i][j] > 0)
                        {
                            abcin << items[i][j] << "\t"
                                  << order[i][j] << "\t"
                                  << prices[i][j] << "\t"
                                  << prices[i][j] * order[i][j] << endl;
                            abcin << "Item: " << i + 1 << " " << j + 1 << " " << order[i][j] << endl;
                        }
                    }
                }

                if (discount > 0)
                    abcin << "\t\t\t\tDiscount:\t-" << discount << endl;

                abcin << "\t\t\t\tService Charges:\t" << ser << endl;
                abcin << "\t\t\t\tTOTAL BILL:\t" << total << endl;
                abcin << "\t\t\t\t===============================\n";

                abcin.close();
                char paid;
                clear();

                char pstatus;
                bool payments = false;

                do
                {
                    processing("\n\t\t\t\tOpening Payment Portal...");
                    type("\n\t\t\t\t\033[34m=================================\033[0m\n");
                    type("\t\t\t\t\033[1;35m\t  BILL PAYMENT\t  \n");
                    type("\t\t\t\t\033[34m=================================\033[0m\n");

                    cout << "\t\t\t\tHave you paid the bill? (y/n): ";
                    cin >> pstatus;

                    if (pstatus == 'y' || pstatus == 'Y')
                    {
                        payments = true;
                        cout << "\t\t\t\t\033[32mThank you! Enjoy your meal.\033[0m\n";

                        if (choose == 1)
                        {
                            tables[table - 1] = 0;
                            cout << "\t\t\t\tTable " << table << " is now FREE\n";
                        }
                    }
                    else if (pstatus == 'n' || pstatus == 'N')
                    {
                        char choice;
                        do
                        {
                            cout << "\n\t\t\t\tYour bill is: $" << total << endl;
                            cout << "\t\t\t\tYou need to settle the bill. Choose any option:\n";
                            cout << "\t\t\t\t1. Pay Bill\n";
                            cout << "\t\t\t\t2. Wash Dishes😅 \n";
                            cout << "\t\t\t\tEnter choice (1-2): ";
                            cin >> choice;

                            if (choice == '1')
                            {
                                payments = true;

                                ofstream abcin("invoice.txt", ios::app);
                                abcin << "Customer: " << user << endl;
                                abcin << "Bill: " << total << endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    for (int j = 0; j < 5; j++)
                                    {
                                        if (order[i][j] > 0)
                                            abcin << "Item: " << i + 1 << " " << j + 1 << " " << order[i][j] << endl;
                                    }
                                }
                                abcin << "---------------------\n";
                                abcin.close();

                                cout << "\t\t\t\t\033[32mPayment successful. Invoice saved.\033[0m\n";

                                if (choose == 1)
                                {
                                    tables[table - 1] = 0;
                                    cout << "\t\t\t\tTable " << table << " is now FREE\n";
                                }
                            }
                            else if (choice == '2')
                            {
                                payments = true;
                                cout << "\t\t\t\t\033[33mYou chose to wash dishes! Thank you for helping😅 \033[0m\n";

                                if (choose == 1)
                                {
                                    tables[table - 1] = 0;
                                    cout << "\t\t\t\tTable " << table << " is now FREE\n";
                                }
                            }
                            else
                            {
                                cout << "\t\t\t\t\033[31mInvalid choice! Please select 1 or 2.\033[0m\n";
                            }

                        } while (!payments);
                    }
                    else
                    {
                        cout << "\t\t\t\t\033[31mInvalid input! Enter 'y' or 'n'.\033[0m\n";
                    }

                } while (!payments);

                processing("\n\t\t\t\t\033[31mOpening Feedback Portal\033[0m");
                type("\n\t\t\t\t\033[36m=================================\033[0m\n");
                type("\t\t\t\t\033[1;35m\t   FEEDBACK\t  \n");
                type("\t\t\t\t\033[36m=================================\033[0m\n");
                string fb;
                cout << "\t\t\t\tEnter feedback: ";
                cin.ignore();
                getline(cin, fb);
                ofstream fbfile("feedback.txt", ios::app);
                fbfile << fb << endl;
                fbfile.close();
            }
        }
        else if (status == 3)
        {
            clear();
            processing("\n\t\t\t\tOpening Employee Portal...");
            type("\n\t\t\t\t\033[34m=================================\033[0m\n");
            type("\t\t\t\t\033[1;35m\t  EMPLOYEE PORTAL\t  \n");
            type("\t\t\t\t\033[34m=================================\033[0m\n");
            char name[50];
            int emp;
            cout << "\t\t\t\tEnter Name: ";
            cin >> name;
            cout << "\t\t\t\tEmployee Number: ";
            cin >> emp;
            ofstream att("attendance.txt", ios::app);
            att << name << " " << emp << endl;
            att.close();
            cout << "\t\t\t\t\033[32mAttendance Marked!\033[0m\n";
        }

    } while (status != 4);

    clear();

    processing("\n\t\t\t\tExiting Waneera Foods");

    type("\n\t\t\t\t\033[35m╔═════════════════════════════════════════╗\033[0m");
    type("\t\t\t\t\033[36m║                                         ║\033[0m");
    type("\t\t\t\t\033[32m║        Thanks for visiting Us           ║\033[0m");
    type("\t\t\t\t\033[33m║            Come Back Soon!              ║\033[0m");
    type("\t\t\t\t\033[36m║                                         ║\033[0m");
    type("\t\t\t\t\033[35m╚═════════════════════════════════════════╝\033[0m\n");

    type("\t\t\t\t\033[32mHave a Nice Day! \033[0m\n");

    return 0;
}
