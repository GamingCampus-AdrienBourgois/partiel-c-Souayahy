#include "Solution2.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

    float Solution2::GetBalance(const std::string & accountName)
    {
        std::string folderPath = "../../ConsoleApplication/BankAccount";

        if (!fs::exists(folderPath)) {
            throw std::runtime_error("Le dossier des comptes bancaires n'existe pas.");
        }

        float balance = 0.0f;

        for (const auto& entry : fs::directory_iterator(folderPath)) {
            std::string filePath = entry.path().string();

            std::ifstream inputFile(filePath);

            if (!inputFile.is_open()) {
                throw std::runtime_error("Impossible d'ouvrir le fichier du compte bancaire : " + filePath);
            }

            std::string line;

            while (std::getline(inputFile, line))
            {
                std::istringstream iss(line);
                std::string operation;
                float amount;

                if (!(iss >> operation >> amount)) {
                    throw std::runtime_error("Erreur de lecture dans le fichier du compte bancaire.");
            }

                if (operation == "DEPOSIT") {
                    balance += amount;
                }
                else if (operation == "WITHDRAW") {
                    balance -= amount;
                }
                else {
                    throw std::runtime_error("Opération non valide dans le fichier du compte bancaire.");
                }
        }

            inputFile.close();
    }

        return balance;
}



#endif
