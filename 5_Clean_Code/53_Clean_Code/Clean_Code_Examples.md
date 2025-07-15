# Clean Code Beispiele

Dieses Dokument enthält Beispiele für typische Probleme orientiert an der Clean Code Philosophie.
Außerdem werden Beispiele gezeigt, wie diese Probleme behoben werden können.

## Kommentare

Beispiel für die Code smells C1 - C3 und C5.

```cpp
// Author: Max Mustermann
// Created: 2018-05-10
// Modified: 2021-09-14
int calculateArea(int width, int height) {
    // Berechnet die Fläche eines Quadrats mit der Seitenlänge 'length'
    // returnValue = width * height;
    return width * height; // Breite * Höhe
}
```

Clean Code:

```cpp
int calculateArea(int width, int height) {
    return width * height;
}
```

## Funktionen

Beispiel für die Code smells F1, F2 und F4.

```cpp
void logToConsole(const std::string& msg) {
    std::cout << "LOG: " << msg << std::endl;
}


void processUserData(
    const std::string& name,
    int age,
    const std::string& email,
    bool isAdmin,
    int& statusCode,          
    std::string& welcomeMsg
) {
    if (name.empty() || email.empty()) {
        statusCode = -1;
        welcomeMsg = "Invalid data.";
        return;
    }

    statusCode = 0;
    welcomeMsg = "Welcome, " + name + (isAdmin ? " (Admin)" : "");
}
```

Clean Code:

```cpp
struct User {
    std::string name;
    int age;
    std::string email;
    bool isAdmin;
};

struct ProcessResult {
    int statusCode;
    std::string welcomeMessage;
};

ProcessResult processUser(const User& user) {
    if (user.name.empty() || user.email.empty()) {
        return {-1, "Invalid data."};
    }

    std::string msg = "Welcome, " + user.name + (user.isAdmin ? " (Admin)" : "");
    return {0, msg};
}
```



