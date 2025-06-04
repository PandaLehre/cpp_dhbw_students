# Warum wird Garbage Collection in C++ kaum verwendet?

Übersicht:

- [Warum wird Garbage Collection in C++ kaum verwendet?](#warum-wird-garbage-collection-in-c-kaum-verwendet)
  - [Einleitung](#einleitung)
  - [Allgemeine Vorteile von Garbage Collection](#allgemeine-vorteile-von-garbage-collection)
  - [Daher ist Garbage Collection in C++ ungewöhnlich](#daher-ist-garbage-collection-in-c-ungewöhnlich)
    - [1. "You don't pay for what you don't use" – Das C++ Prinzip](#1-you-dont-pay-for-what-you-dont-use--das-c-prinzip)
    - [2. RAII – Resource Acquisition Is Initialization](#2-raii--resource-acquisition-is-initialization)
    - [3. Leistung und Echtzeitfähigkeit](#3-leistung-und-echtzeitfähigkeit)
    - [4. Manuelle Kontrolle ist ein Feature, kein Bug](#4-manuelle-kontrolle-ist-ein-feature-kein-bug)
  - [Fazit: C++ braucht keine klassische Garbage Collection](#fazit-c-braucht-keine-klassische-garbage-collection)
  - [Ergänzende Hinweise / Alternativen zur GC in C++](#ergänzende-hinweise--alternativen-zur-gc-in-c)
    - [Beispiel: Speicherleck und Smart Pointer](#beispiel-speicherleck-und-smart-pointer)
  - [Stack vs. Heap Speicher](#stack-vs-heap-speicher)

## Einleitung

Garbage Collection (GC) ist in vielen modernen Programmiersprachen wie Java oder C# ein selbstverständlicher Bestandteil. In C++ hingegen ist sie bewusst **nicht standardmäßig integriert**. Warum?

---

## Allgemeine Vorteile von Garbage Collection

- Speicher wird automatisch freigegeben
- Reduziert die Gefahr von Speicherlecks
- Entwickler müssen sich nicht um Speicherfreigabe kümmern

Aber: Diese Vorteile kommen **nicht ohne Kosten**.

---

## Daher ist Garbage Collection in C++ ungewöhnlich

### 1. "You don't pay for what you don't use" – Das C++ Prinzip

C++ gibt dem Entwickler maximale Kontrolle und vermeidet unnötige Kosten:

- Garbage Collection kostet **Rechenzeit und Speicher**, selbst wenn nichts bereinigt werden muss
- C++ will genau das **vermeiden**, wenn die Funktion nicht benötigt wird

**Fazit:** GC widerspricht einem Grundprinzip von C++

---

### 2. RAII – Resource Acquisition Is Initialization

C++ löst Speicher- und Ressourcenmanagement durch RAII:

- Ressourcen werden mit Objektlebensdauer verwaltet
- Destruktoren werden **deterministisch** (zu einem klar definierten Zeitpunkt) aufgerufen

Beispiel:

```cpp
void f() {
    std::string s = "Hello"; // Speicher wird automatisch freigegeben sobald wir den Scope verlassen
} // <- Hier wird der Speicher freigegeben
```

**Fazit:** GC ist nicht notwendig, wenn RAII korrekt eingesetzt wird

---

### 3. Leistung und Echtzeitfähigkeit

- GC kann nicht garantieren, **wann** Speicher freigegeben wir
- In Echtzeitsystemen (z. B. Automotive, Robotik) ist das ein Problem

**Fazit:** GC ist in Echtzeitsystemen mit **zeitkritischen Anforderungen ungeeignet**

---

### 4. Manuelle Kontrolle ist ein Feature, kein Bug

C++ bietet gezielte Werkzeuge für Speicherverwaltung:

- `new` / `delete`
- `std::unique_ptr`, `std::shared_ptr` (Smart Pointer)

Wenn ein Entwickler mehr Komfort will, kann er diese Werkzeuge **gezielt** nutzen – ohne globale GC.

**Fazit:** C++ erlaubt feingranulare Kontrolle über Ressourcen – gewollt!

---

## Fazit: C++ braucht keine klassische Garbage Collection


| Vorteil von GC          | Warum in C++ nicht gebraucht             |
| ----------------------- | ---------------------------------------- |
| Kein manuelles `delete` | RAII + Smart Pointer regeln das          |
| Weniger Speicherlecks   | Tools wie Valgrind, AddressSanitizer, LeakSanitizer + Designmuster |
| Einfachere Entwicklung  | Auf Kosten von Performance und Kontrolle |

C++ setzt auf **Effizienz, Kontrolle und Vorhersagbarkeit** – klassische GC ist damit **nicht kompatibel**.

---

## Ergänzende Hinweise / Alternativen zur GC in C++

- **Smart Pointer** (`std::unique_ptr`, `std::shared_ptr`):
  - `std::unique_ptr` besitzt alleinigen Besitz und gibt Speicher beim Verlassen des Gültigkeitsbereichs frei.
  - `std::shared_ptr` erlaubt geteilten Besitz und zählt Referenzen automatisch.
- **RAII** für alle Ressourcen (nicht nur Speicher!)
- **Tools gegen Speicherlecks:** Neben Valgrind gibt es AddressSanitizer und LeakSanitizer.
- **GC ist optional verfügbar:** Es existieren Garbage Collector-Bibliotheken für C++ (z. B. Boehm GC), werden aber selten eingesetzt.
- **Embedded/Low-Level:** In eingebetteten Systemen ist deterministische Speicherfreigabe besonders wichtig.

### Beispiel: Speicherleck und Smart Pointer

Speicherleck mit `new`/`delete`:

```cpp
void leak() {
    int* p = new int(42);
    // kein delete -> Speicherleck!
}
```

Korrekt mit Smart Pointer:

```cpp
#include <memory>
void no_leak() {
    auto p = std::make_unique<int>(42); // Speicher wird automatisch freigegeben
}
```

---

## Stack vs. Heap Speicher

In C++ gibt es zwei wichtige Speicherbereiche:

- **Stack:**
  - Automatische Speicherverwaltung.
  - Variablen werden beim Verlassen des Gültigkeitsbereichs (Scope) automatisch freigegeben.
  - Sehr schnell, aber begrenzt in der Größe.

- **Heap:**
  - Speicher wird explizit mit `new` (bzw. `malloc`) angefordert und muss manuell mit `delete` (bzw. `free`) freigegeben werden.
  - Ermöglicht dynamische Speicherverwaltung und große Datenmengen.
  - Fehler wie Speicherlecks oder „Dangling Pointers“ entstehen fast ausschließlich im Heap.

**Bezug zu RAII und Smart Pointern:**

RAII und Smart Pointer helfen, Heap-Speicher sicher und automatisch zu verwalten, sodass Speicherlecks vermieden werden.

---
