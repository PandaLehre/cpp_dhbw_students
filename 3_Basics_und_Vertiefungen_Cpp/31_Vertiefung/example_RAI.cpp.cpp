#include <iostream>
#include <fstream>
#include <vector>

/*
 * Solide Einführung in die Thematik
 * https://en.cppreference.com/w/cpp/language/raii.html
 * https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#e6-use-raii-to-prevent-leaks
 * https://de.wikipedia.org/wiki/Ressourcenbelegung_ist_Initialisierung
*/

// Diese Implementierung zeigt, wie man ohne RAII arbeitet – also manuell Ressourcen verwaltet.
// Hier muss man explizit darauf achten, die Datei am Ende zu schließen.
void writeWithoutRAII(const std::string &filename) {
    std::ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei\n";
        return;
    }

    file << "Text ohne RAII\n";

    // Angenommen, hier passiert ein früher Rücksprung (z.B. durch Fehler oder return),
    // dann wird file.close() eventuell vergessen und es kommt zu Lecks!
    if (/*true*/ false) {
        std::cout << "Früher Rücksprung – Datei eventuell nicht geschlossen!\n";
        exit(1);
    }

    // Manuelles Schließen notwendig
    file.close();
}


// Diese Implementierung verwendet RAII: Das Dateiobjekt wird in einem Wrapper gekapselt,
// dessen Destruktor automatisch aufgerufen wird, wenn das Objekt den Gültigkeitsbereich verlässt.
class FileWriter {
public:
    FileWriter(const std::string &filename) {
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Fehler beim Öffnen der Datei\n";
        }
    }

    ~FileWriter() {
        // Automatisches Schließen beim Verlassen des Gültigkeitsbereichs
        if (file.is_open()) {
            file.close();
            std::cout << "Datei automatisch geschlossen (RAII).\n";
        }
    }

    void write(const std::string &text) {
        if (file.is_open()) {
            file << text;
        }
    }

private:
    std::ofstream file;
};

void writeWithRAII(const std::string &filename) {
    FileWriter writer(filename);
    writer.write("Text mit RAII\n");

    // Selbst bei einem frühen Return wird die Datei im Destruktor korrekt geschlossen.
    if (true) {
        std::cout << "Früher Rücksprung – kein Problem dank RAII.\n";
        throw std::runtime_error("Irgendein Fehler!");
    }
}

int main() {
    // OHNE RAII

    char* buffer = new char[3];
    buffer[0] = 'A';
    buffer[1] = 'B';
    buffer[2] = 'C';

    // Buffer verwenden
    buffer[0] += 5;

    // Wenn hier ein Fehler geschmissen wird, haben wir ein Memory Leak



    delete[] buffer;







    // MIT RAII

    std::vector<char> buf = {'A', 'B', 'C'};

    // Buffer verwenden

    // Wenn hier ein Fehler geschmissen wird, wird trotzdem der Speicher über den Destruktor bereinigt

    // KOMPLIZIERTERES BEISPIEL

    //writeWithoutRAII("ohne_raii.txt");
    try {
        writeWithRAII("mit_raii.txt");
    } catch (const std::exception& e) {
        std::cout << "Exception gefangen: " << e.what() << "\n";
    }

    return 0;
}
