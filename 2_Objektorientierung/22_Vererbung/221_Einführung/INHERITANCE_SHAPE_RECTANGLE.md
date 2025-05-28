# Grundlagen C++: Vererbung am Beispiel Shape und Rectangle

Dieses Beispiel demonstriert die Grundlagen der Vererbung in C++ anhand einer einfachen Klassenhierarchie mit einer Basisklasse `Shape` und einer abgeleiteten Klasse `Rectangle`.

---

## Code-Übersicht

### Der Code

```cpp
#include <iostream>

class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   ~Shape()
   {
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

protected:
   double m_width;
   double m_height;
};

class Rectangle : public Shape
{
public:
   Rectangle(double width, double height)
       : Shape(width, height)
   {
   }

   ~Rectangle()
   {
   }

   double getArea()
   {
      return m_width * m_height;
   }
};

int main()
{
   Rectangle rect(10, 20);

   std::cout << "--- Call getArea() from Rectangle class ---" << std::endl;
   std::cout << "Area: " << rect.getArea() << std::endl;

   Shape shape(10, 20);
   std::cout << "--- Call setWidth() from Shape class ---" << std::endl;
   shape.setWidth(30);

   return 0;
}
```

---

## Aufbau des Programms

### 1. Basisklasse `Shape`

- Stellt die gemeinsamen Eigenschaften `m_width` und `m_height` bereit (geschützt, also für abgeleitete Klassen sichtbar).
- Konstruktor initialisiert Breite und Höhe.
- Methoden `setWidth` und `setHeight` erlauben das Setzen der Werte.
- Destruktor vorhanden (hier leer, aber für spätere Erweiterungen nützlich).

### 2. Abgeleitete Klasse `Rectangle`

- Erbt öffentlich von `Shape`.
- Konstruktor ruft den Basisklassen-Konstruktor auf.
- Methode `getArea()` berechnet die Fläche des Rechtecks.
- Eigener Destruktor (hier leer).

### 3. `main()`

- Erstellt ein `Rectangle`-Objekt und gibt dessen Fläche aus.
- Erstellt ein `Shape`-Objekt und demonstriert das Setzen der Breite.
- Der Zugriff auf die geschützten Member-Variablen ist außerhalb der Klasse nicht möglich (siehe auskommentierte Zeilen).

---

## Die Ausgabe

### Beispielausgabe

```bash
--- Call getArea() from Rectangle class ---
Area: 200
--- Call setWidth() from Shape class ---
```

- Die Fläche des Rechtecks wird berechnet und ausgegeben.
- Die Methode `setWidth()` wird aufgerufen, aber die Member-Variablen sind außerhalb der Klasse nicht direkt zugreifbar.

---

## Hinweise

- **Vererbung** ermöglicht es, gemeinsame Funktionalität in einer Basisklasse zu definieren und in abgeleiteten Klassen zu erweitern oder zu nutzen.
- `protected`-Member sind in abgeleiteten Klassen sichtbar, aber nicht außerhalb der Klassenhierarchie.
- Würde man `setWidth()` als `private` deklarieren, könnten abgeleitete Klassen und externe Nutzer diese Methode nicht mehr aufrufen.
- Würde man die `protected`-Sektion als `private` deklarieren, könnten abgeleitete Klassen nicht mehr direkt auf `m_width` und `m_height` zugreifen.
- Weitere Informationen zur Vererbung in C++ finden sich in der [C++ Referenz zu Vererbung](https://en.cppreference.com/w/cpp/language/derived_class).
