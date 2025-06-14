#include <iostream>
#include <string> // Dla std::string
#include <thread> // Dla std::this_thread::sleep_for
#include <chrono> // Dla std::chrono::seconds

// definiowanie kolorów dla konsoli
// Te definicje kolorów to kody ucieczki ANSI dla kolorów tekstu w terminalu.
// Użycie static constexpr const char* jest bardziej w stylu nowoczesnego C++ niż #define dla stałych stringów.
static constexpr const char *C_RED = "\033[31m";
static constexpr const char *C_GREEN = "\033[32m";
static constexpr const char *C_YELLOW = "\033[33m";
static constexpr const char *C_BLUE = "\033[34m";
static constexpr const char *C_MAGENTA = "\033[35m";
static constexpr const char *C_CYAN = "\033[36m";
static constexpr const char *C_RESET = "\033[0m";

bool isLinuxSystem = false; // Ta flaga służy do wskazania, czy system operacyjny to Linux.
// Lepiej użyć constexpr dla stałych wartości.
static constexpr int TIMER_PAUSE_SECONDS = 3; // Ta zmienna służy do ustawienia czasu trwania pauzy timera (zmniejszono dla szybszych testów, można przywrócić 5).

void timerPause(); // Deklaracja wyprzedzająca funkcji timerPause
void infoSystem(); // Deklaracja funkcji infoSystem
void clearConsole();
bool executeSystemCommand(const std::string& command, const std::string& operationMessage); // Funkcja pomocnicza
bool sysUpdate(); // Deklaracja funkcji sysUpdate, zwraca bool
bool sysUpgrade(); // Deklaracja funkcji sysUpgrade, zwraca bool
bool sysAutoremove(); // Deklaracja funkcji sysAutoremove, zwraca bool
bool sysAutoclean();  // Deklaracja funkcji sysAutoclean, zwraca bool

int main()
{
    clearConsole(); // Wyczyść konsolę na początku programu
    infoSystem();   // Wywołaj infoSystem, aby ustawić flagę isLinuxSystem

    int exitCode = 0; // Domyślnie sukces

    if (isLinuxSystem)
    {
        std::cout << C_BLUE << "System operacyjny: Linux" << C_RESET << std::endl;
        std::cout << C_BLUE << "-------------------------------------------------" << C_RESET << std::endl;
        std::cout << C_GREEN << "Uruchomienie programu... za " << TIMER_PAUSE_SECONDS << " sekund!" << C_RESET << std::endl;
        timerPause();                                                                                                  // Wywołaj timerPause, aby poczekać 5 sekund
        clearConsole();

        bool allOperationsSuccessful = sysUpdate() &&
                                     sysUpgrade() &&
                                     sysAutoremove() &&
                                     sysAutoclean();

        if (allOperationsSuccessful) {
            std::cout << "\n" << C_GREEN << "Wszystkie operacje konserwacji systemu zakończone pomyślnie!" << C_RESET << std::endl;
        } else {
            std::cout << "\n" << C_RED << "Nie wszystkie operacje konserwacji systemu zakończyły się pomyślnie. Sprawdź komunikaty powyżej." << C_RESET << std::endl;
            exitCode = 1; // Ustaw kod wyjścia na błąd
        }
    }
    else
    {
        std::cout << C_RED << "System operacyjny: Inny niż Linux (np. Windows)" << C_RESET << std::endl;
        std::cout << C_RED << "Ten program jest przeznaczony do automatycznej aktualizacji systemów Linux (bazujących na APT)." << C_RESET << std::endl;
        std::cout << C_RED << "Nie można kontynuować na bieżącym systemie operacyjnym.\n" << C_RESET << std::endl;
        exitCode = 1; // Ustaw kod wyjścia na błąd
    }
    // Poczekaj na dane wejściowe od użytkownika przed zamknięciem okna konsoli
    std::cout << "Naciśnij Enter, aby zakończyć..." << std::endl;
    std::cin.get(); // Pozostaje bez zmian, służy do pauzy
    return exitCode;
}

//+----------------------------------------------------------------------+
//| Funkcja pomocnicza do wykonywania poleceń systemowych                |
//+----------------------------------------------------------------------+
bool executeSystemCommand(const std::string& command, const std::string& operationMessage) {
    clearConsole();
    std::cout << C_YELLOW << operationMessage << C_RESET << std::endl;
    int result = std::system(command.c_str());
    clearConsole();
    if (result == 0) {
        std::cout << C_GREEN << "Operacja zakończona pomyślnie!" << C_RESET << std::endl;
    } else {
        std::cout << C_RED << "Wystąpił błąd podczas operacji." << C_RESET << std::endl;
        std::cout << C_RED << "Kod błędu: " << result << C_RESET << std::endl;
    }
    std::cout << C_GREEN << "-------------------------------------------------" << C_RESET << std::endl;
    timerPause(); // Pauza, aby użytkownik mógł przeczytać wiadomość
    clearConsole();
    return result == 0;
}

//+----------------------------------------------------------------------+
//| pauza z timerem 5s                                                   |
//+----------------------------------------------------------------------+
void timerPause()
{
    // Użycie std::this_thread::sleep_for jest przenośne i bezpieczniejsze niż system("sleep ...")
    // system("sleep " + timerPauseTime) jest niepoprawne, ponieważ próbujesz dodać int do const char* (uwaga: timerPauseTime nie jest już używane)
    std::this_thread::sleep_for(std::chrono::seconds(TIMER_PAUSE_SECONDS));
}

//+----------------------------------------------------------------------+
//| czyszczenie konsoli                                                  |
//+----------------------------------------------------------------------+
void clearConsole()
{
#ifdef __linux__
    std::system("clear"); // Dla systemów Linux
#else
    std::system("cls"); // Dla systemów Windows
#endif // __linux__ // Koniec dyrektywy dla __linux__
}

//+----------------------------------------------------------------------+
//| sprawdzanie systemu operacyjnego                                     |
//+----------------------------------------------------------------------+
void infoSystem()
{
// sprawdź, czy system to Linux, jeśli tak, ustaw flag = true, jeśli nie, ustaw flag = false
#ifdef __linux__
    isLinuxSystem = true; // Wykryto system Linux
#else
    isLinuxSystem = false; // Wykryto system inny niż Linux
#endif // __linux__
}

//+----------------------------------------------------------------------+
//| update systemu operacyjnego Linux                                    |
//+----------------------------------------------------------------------+
bool sysUpdate()
{
    // Nie ma potrzeby sprawdzania 'isLinuxSystem' tutaj, main() już to zrobił.
    return executeSystemCommand("sudo apt update", "Aktualizacja listy pakietów (apt update)...\n\n");
}

//+----------------------------------------------------------------------+
//| updgrade systemu operacyjnego Linux                                  |
//+----------------------------------------------------------------------+
bool sysUpgrade()
{
    // Nie ma potrzeby sprawdzania 'isLinuxSystem' tutaj, main() już to zrobił.
    return executeSystemCommand("sudo apt upgrade -y", "Aktualizacja zainstalowanych pakietów (apt upgrade -y)...\n\n");
}

//+----------------------------------------------------------------------+
//| usuwanie niepotrzebnych pakietów (autoremove)                        |
//+----------------------------------------------------------------------+
bool sysAutoremove()
{
    // Nie ma potrzeby sprawdzania 'isLinuxSystem' tutaj, main() już to zrobił.
    return executeSystemCommand("sudo apt autoremove -y", "Usuwanie niepotrzebnych pakietów (apt autoremove -y)...\n\n");
}

//+----------------------------------------------------------------------+
//| czyszczenie lokalnego repozytorium (autoclean)                       |
//+----------------------------------------------------------------------+
bool sysAutoclean()
{
    // Nie ma potrzeby sprawdzania 'isLinuxSystem' tutaj, main() już to zrobił.
    return executeSystemCommand("sudo apt autoclean -y", "Czyszczenie lokalnego repozytorium pobranych plików pakietów (apt autoclean -y)...\n\n");
}

// koniec pliku main.cpp
// kompilacja poleceniem: g++ -std=c++17 updater_2.cpp -o updater_2 -pthread
