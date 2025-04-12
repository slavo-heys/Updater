#include "fun.h"
#include <iostream>
#include <string>

#define yellow "\033[1;33m"
#define green "\033[1;32m"
#define red "\033[1;31m"
#define blue "\033[1;34m"
#define reset "\033[0m"

using namespace std;

int main()
{
    int choice;
    do {
        // wyczysc konsole
        system("clear");
        // wyswietl naglowek
        printf(yellow "\nWitaj w programie Aktualizator w wersji 2.0\n" reset);
        printf(blue "\n %s\n", "Wybierz jedną z opcji:" reset);
        printf(blue "\t %s \t\t | \t %s\n", "1. apt update", "10. apt autoremove" reset);
        printf(blue "\t %s \t | \t %s\n", "2. apt upgrade", "11. apt clean" reset);
        printf(blue "\t %s \t | \t %s\n", "3. apt full-upgrade", "12. none" reset);
        printf(blue "\t %s \t | \t %s\n", "4. apt dist-upgrade", "13. none" reset);
        printf(blue "-----------------------------------------------------------\n" reset);

        printf(yellow "\nWybierz jedną z opcji: " reset);

        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                updateSystem();
                break;

            case 2:
                upgradeSystem();
                break;

            case 3:
                fullUpgradeSystem();
                break;

            case 4:
                distUpgradeSystem();
                break;

            case 10:
                autoremoveSystem();
                break;

            case 11:
                cleanSystem();
                break;

            default:
                printf(red "\nKoniec programu!" reset);
                printf(red "--------------------\n" reset);
                break;
            }
        }while(choice != 0);

        printf(green "\nNacisnij ENTER aby zakończyć...\n" reset);
        while (getchar() != '\n'); // czekaj na ENTER
        getchar(); // czekaj na ENTER
        system("clear");


    /* string str;
    cout << "Enter a string: ";
    getline(cin, str); */

    

    return 0;
}

void updateSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt update...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt update");
    // jesli polecenie wykonane z bledem
    if (system("sudo apt update") != 0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }

    // nacisnij klawisz aby kontynuawac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}

void upgradeSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt upgrade...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt upgrade");
    // jesli polecenie wykonane z bledem
    if (system("sudo apt upgrade") != 0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }

    // nacisnij klawisz aby kontynuawac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}

void fullUpgradeSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt full-upgrade...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt full-upgrade");
    // jesli polecenie wykonane z bledem
    if (system("sudo apt full-upgrade -y") !=
        0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }
    // nacisnij klawisz aby kontynuawac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}

void distUpgradeSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt dist-upgrade...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt dist-upgrade");
    // jesli polecenie wykonane z bledem
    if (system("sudo apt dist-upgrade -y") != 0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }
    // nacisnij klawisz aby kontynuowac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}

void autoremoveSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt autoremove...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt autoremove");
    // jesli polecenie wykonane z bledem            
    if (system("sudo apt autoremove -y") != 0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }
    // nacisnij klawisz aby kontynuowac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}

void cleanSystem()
{
    system("clear");
    printf(yellow "\n\tRozpoczynam polecenie sudo apt clean...\n" reset);
    printf(yellow "\t-----------------------------------------------------\n\n" reset);
    system("sudo apt clean");
    // jesli polecenie wykonane z bledem
    if (system("sudo apt autoclean -y") != 0)
    {
        printf(red "Niestety, wystapil blad podczas aktualizacji systemu!\n" reset);
        printf(red "-----------------------------------------------------\n" reset);
        exit(1);
    }
    else
    {
        printf(green "\nSukces!\n" reset);
        printf(green "-----------------------------------------------------\n" reset);
    }

    // nacisnij klawisz aby kontynuowac
    printf(green "\nNacisnij ENTER aby kontynuowac...\n" reset);
    while (getchar() != '\n'); // czekaj na ENTER
    getchar(); // czekaj na ENTER
    system("clear");
}


// koniec pliku main.cpp