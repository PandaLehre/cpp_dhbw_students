# SOLID Design Principles
Overview of the five SOLID design principles.
---

## 1. **Single Responsibility Principle (SRP)**

**One class should have just one responsibility.**

### Bad (multiple Responsibilities):

```cpp
class Bericht {
public:
    void berechnen();          // Logic
    void alsPDFExportieren();  // Export
};
```

### Better (SRP used):

```cpp
class BerichtBerechner {
public:
    void berechnen();
};

class BerichtExporter {
public:
    void alsPDFExportieren();
};
```

---

## 2. **Open/Closed Principle (OCP)**

**Software entities should be open for extension, but closed for modification**

### Good Example using Inheritance:
New shapes can be added without changing existing code --> good maintainability and expandability

```cpp
class Zeichnung {
public:
    virtual void zeichne() const = 0;
};

class Kreis : public Zeichnung {
public:
    void zeichne() const override {
        std::cout << "Kreis zeichnen\n";
    }
};

class Quadrat : public Zeichnung {
public:
    void zeichne() const override {
        std::cout << "Quadrat zeichnen\n";
    }
};

void zeichneAlles(const std::vector<Zeichnung*>& bilder) const {
    for (auto b : bilder) {
        b->zeichne();  // automatically works for new shapes
    } 
}
```


---

## 3. **Liskov Substitution Principle (LSP)**

**Derived classes should behave like the base class.**
Example with birds that move differently. Base class and derived classes should have **Common Interface**.

### Bad example:

```cpp
class Vogel {
public:
    virtual void fliegen() = 0;
};

class Pinguin : public Vogel {
public:
    void fliegen() override {
        throw std::logic_error("Kann nicht fliegen!");
    }
};
```
A penguin is a bird, **but not a valid substitute**, because `fliegen()` is not allowed.

### Besser example:

```cpp
class Vogel {
public:
    virtual void bewegung() = 0;
};

class Spatz : public Vogel {
public:
    void bewegung() override {
        std::cout << "Spatz fliegt\n";
    }
};

class Pinguin : public Vogel {
public:
    void bewegung() override {
        std::cout << "Pinguin watschelt\n";
    }
};
```

Both classes now have **common interface**, without incorrect behavior

---

## 4. **Interface Segregation Principle (ISP)**

**Use multiple small specialized interfaces instead of one big general interface.**

Interfaces should be specialized to the needs and capabilities of a class.
Example with Interface for Vehicles.

### Bad example:

```cpp
class Fahrzeug {
public:
    virtual void fahren() = 0;
    virtual void fliegen() = 0;
    virtual void tauchen() = 0;
};
```

Not each vehicle is able to fly. A derived `Car` class now needs to implement `fliegen()` and `tauchen()`, even if it is pointless

### Better example:

```cpp
class Fahrbar {
public:
    virtual void fahren() = 0;
};

class Flugfähig {
public:
    virtual void fliegen() = 0;
};

class Tauchfähig {
public:
    virtual void tauchen() = 0;
};
```

Now, a Vehicle just needs to implement the actually **required Interfaces**.

---

## 5. **Dependency Inversion Principle (DIP)**

**Dependence on abstractions, not on concrete classes.**

When creating dependencies between classes, it is better to create them with interfaces or abstract classes instead of concrete implementations. This allows an easier exchange of code parts and functionalities.

Example of a text editor with input device.

### Bad example:

```cpp
class Tastatur {
public:
    std::string leseEingabe() { 
        return "Benutzereingabe";
    }
};

class Texteditor {
    Tastatur tastatur; // feste Kopplung!
public:
    void start() {
        std::cout << "Eingabe: " << tastatur.leseEingabe() << "\n";
    }
};
```

Problem: `Texteditor` is hard-coupled to `Tastatur`. A replacement (e.g. speech recognition) is only possible by changing the code.

### Better Example:

```cpp
class Eingabequelle {
public:
    virtual std::string leseEingabe() = 0;
    virtual ~Eingabequelle() = default;
};

class Tastatur : public Eingabequelle {
public:
    std::string leseEingabe() override {
        return "Benutzereingabe von Tastatur";
    }
};

class Sprachsteuerung : public Eingabequelle {
public:
    std::string leseEingabe() override {
        return "gesprochene Eingabe";
    }
};

class Texteditor {
    Eingabequelle& quelle;
public:
    Texteditor(Eingabequelle& eingabe) : quelle(eingabe) {}

    void start() {
        std::cout << "Eingabe: " << quelle.leseEingabe() << "\n";
    }
};
```

`Texteditor` is only dependent on input source. Details (keyboard, voice control) depend on the abstraction, not vice versa.

---