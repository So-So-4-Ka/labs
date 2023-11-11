#include "good_password.h"

namespace My_Password {
    string PasswordGenerator::generatePassword(int length) {
        static mt19937 generator(time(0)); // Инициализация генератора случайных чисел
        string password;
        for (int i = 0; i < length; i++) {
            int choice = generator() % 4; // Выбор группы символов
            char symbol;

            if (choice == 0) { // Буквы верхнего регистра
                symbol = 'A' + generator() % 26;
            } else if (choice == 1) { // Буквы нижнего регистра
                symbol = 'a' + generator() % 26;
            } else if (choice == 2) { // Цифры
                symbol = '0' + generator() % 10;
            } else { // Специальные символы
                const string specialSymbols = "!@#$%^&*()";
                symbol = specialSymbols[generator() % specialSymbols.length()];
            }

            password += symbol;
        }

        return password;
    }

    long long PasswordGenerator::calculatePasswordAttempts(int V, int T, int periodChoice) {
        long long totalPasswordAttempts = 0;
        if (T > 0) {
            int minutesInPeriod;
            if (periodChoice == 1) {
                minutesInPeriod = T * 24 * 60; // В днях
            } else if (periodChoice == 2) {
                minutesInPeriod = T * 7 * 24 * 60; // В неделях
            } else if (periodChoice == 3) {
                minutesInPeriod = T * 30 * 24 * 60; // В месяцах
            }

            totalPasswordAttempts = static_cast<long long>(V) * minutesInPeriod;
        }

        return totalPasswordAttempts;
    }

    void PasswordGenerator::run() {
        string password;
        long long totalPasswordAttempts = 0;
        int choice;

        while (true) {
            cout << "Выберите задание (1 или 2), или введите 0 для выхода: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Задание 1: Генерация пароля
                    cout << "\n Задание 1: Генерация пароля \n" << endl;
                    int length;
                    cout << "Введите длину пароля: ";
                    cin >> length;

                    password = generatePassword(length);
                    cout << "Сгенерированный пароль: " << password << endl;
                    cout << "\n Задание 1 выполнено. \n" << endl;
                    break;
                case 2:
                    // Задание 2: Оценка стойкости парольной системы
                    cout << "\n Задание 2: Оценка стойкости парольной системы \n" << endl;
                    int V;
                    int T;
                    cout << "Введите скорость подбора паролей (количество паролей в минуту): ";
                    cin >> V;

                    int periodChoice;
                    cout << "Выберите период времени (1 - дни, 2 - недели, 3 - месяцы): ";
                    cin >> periodChoice;

                    switch (periodChoice) {
                        case 1:
                            cout << "Введите количество дней: ";
                            cin >> T;
                            break;
                        case 2:
                            cout << "Введите количество недель: ";
                            cin >> T;
                            break;
                        case 3:
                            cout << "Введите количество месяцев: ";
                            cin >> T;
                            break;
                        default:
                            cout << "Некорректный выбор периода времени." << endl;
                            continue; // Возврат к выбору задания
                    }

                    totalPasswordAttempts = calculatePasswordAttempts(V, T, periodChoice);
                    cout << "Общее количество паролей, которые могут быть попытаны: " << totalPasswordAttempts << endl;
                    cout << " \n Задание 2 выполнено. \n " << endl;
                    break;
                case 0:
                    cout << "\n Выход из программы. \n" << endl;
                    return;
                default:
                    cout << " \n Некорректный выбор. Пожалуйста, выберите 1, 2 или 0 для выхода. \n" << endl;
                    break;
            }
        }
    }
}