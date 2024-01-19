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
        // Construire le chemin du dossier contenant les fichiers des comptes bancaires
        std::string folderPath = "../../ConsoleApplication/BankAccount";

        // Vérifier l'existence du dossier
        if (!fs::exists(folderPath)) {
            throw std::runtime_error("Le dossier des comptes bancaires n'existe pas.");
        }

        float balance = 0.0f;

        // Parcourir tous les fichiers du dossier
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            // Extraire le chemin du fichier
            std::string filePath = entry.path().string();

            // Ouvrir le fichier en lecture
            std::ifstream inputFile(filePath);

            // Vérifier si le fichier est ouvert avec succès
            if (!inputFile.is_open()) {
                throw std::runtime_error("Impossible d'ouvrir le fichier du compte bancaire : " + filePath);
            }

            std::string line;

            // Lire chaque ligne du fichier
            while (std::getline(inputFile, line))
            {
                // Utiliser un stringstream pour extraire le type d'opération et le montant
                std::istringstream iss(line);
                std::string operation;
                float amount;

                // Lire l'opération (WITHDRAW ou DEPOSIT) et le montant
                if (!(iss >> operation >> amount)) {
                    throw std::runtime_error("Erreur de lecture dans le fichier du compte bancaire.");
            }

                // Mettre à jour le solde en fonction de l'opération
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

            // Fermer le fichier
            inputFile.close();
    }

        return balance;
}



#endif
