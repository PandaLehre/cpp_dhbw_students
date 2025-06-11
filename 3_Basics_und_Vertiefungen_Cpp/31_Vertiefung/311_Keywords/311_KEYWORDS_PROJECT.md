# Berechnung der absoluten Luftfeuchtigkeit in C++

## 01_const - Implementierung: const Variablen

C++-Programm zur Berechnung der absoluten Luftfeuchtigkeit (in g/m³) basierend auf:

* **Temperatur in Grad Celsius**
* **relativer Luftfeuchtigkeit in Prozent**

---

### Verwendete Formel

Die absolute Luftfeuchtigkeit (AH) gibt an, wie viel Gramm Wasserdampf sich in einem Kubikmeter Luft befinden:

$$
\text{AH} = \frac{6.112 \cdot \exp\left(\frac{17.67 \cdot T}{T + 243.5}\right) \cdot RH \cdot 2.1674}{273.15 + T}
$$

Dabei gilt:

* **T** = Temperatur in °C
* **RH** = relative Luftfeuchtigkeit in %
* **AH** = absolute Luftfeuchtigkeit in g/L (wird mit $\cdot 1000$ zu g/m³ umgerechnet)

### Beispielausgabe

**Eingabe:**

```bash
Temperatur in °C: 20
Relative Luftfeuchtigkeit in %: 50
```

**Ausgabe:**

```bash
Absolute Luftfeuchtigkeit: 8.63909 g/m³
```

### Anwendung

Diese Berechnung ist nützlich z. B. für:

* **Klimaanlagensteuerung**
* **Wohnklimaregelung / Hausautomation (z. B. mit Home Assistant)**
* **Wetter- oder Umweltmesssysteme**

### Hinweis

Die Formel basiert auf einer vereinfachten Näherung zur Sättigungsdampfdruckberechnung (Magnusformel) und liefert praxisnahe Ergebnisse für Temperaturen von ca. 0–40 °C.

---

## 02_const_constexp_static - Implementierung: Verwendung von const in Methoden und Member-Variablen

Um die Verwendung von `const` in Methoden und Member-Variablen zu demonstrieren, wurde das Beispiel erweitert. Die neue Implementierung verwendet eine Klasse `HumidityCalculator`, die die absolute Luftfeuchtigkeit berechnet.

Die Klasse `HumidityCalculator` enthält:

* **`const` Member-Variablen**: `m_temperatureCelsius` und `m_relativeHumidity` sind konstant und können nach der Initialisierung nicht geändert werden.
* **`const` Methoden**: Methoden wie `calculateAbsoluteHumidity`, `getTemperature`, und `getRelativeHumidity` ändern keine Member-Variablen.

### Erweiterung: Verwendung von constexpr und static

Um die Effizienz und Sicherheit des Codes zu erhöhen, wurde die Verwendung von `constexpr` ergänzt. `constexpr` ermöglicht die Berechnung von Werten zur Compile-Zeit, wodurch Laufzeitkosten reduziert werden.
`static` sorgt dafür, dass der Wert einmalig zur Compile-Time im Speicher angelegt wird und nicht bei jeder Instanziierung der Klasse neu (eigener Speicherbereich für Static-Variablen). In der Klasse `HumidityCalculator` wird `constexpr` verwendet, um den konstanten Faktor `CONSTANT_FACTOR` zu definieren:

```cpp
constexpr static double M_CONSTANT_FACTOR{6.112 * 2.167};
```

Dieser Wert wird zur Compile-Zeit berechnet und ist während der Laufzeit verfügbar. Der Wert von `CONSTANT_FACTOR` ist 13.222064 und wird in der Methode `calculateAbsoluteHumidity` verwendet.

---

## 03_static - Implementierung: Verwendung von static in Member-Variablen

Die Implementierung `03_static` demonstriert die Verwendung von `static` Member-Variablen in der Klasse `HumidityCalculator`. Dies ermöglicht die Verfolgung der Anzahl der zur Laufzeit erstellten Instanzen.

Hauptmerkmale:

* **Statische Member-Variable**: `m_instanceCount` ist eine statische Variable, die die Gesamtzahl der Instanzen der Klasse `HumidityCalculator` verfolgt.
* **Instanzzählung**: Die Methode `getInstanceCount` bietet Zugriff auf die aktuelle Anzahl der Instanzen.
* **Destruktor-Protokollierung**: Der Destruktor protokolliert, wann eine Instanz zerstört wird, und bietet Einblicke in das Management des Objektlebenszyklus.

---

## 04_auto - Implementierung: Verwendung des Keywords auto

Die Implementierung `04_auto` demonstriert die Verwendung des Keywords `auto` in C++. Das Keyword `auto` ermöglicht es dem Compiler, den Typ einer Variablen automatisch basierend auf dem zugewiesenen Wert zu bestimmen. Dies kann den Code lesbarer und flexibler machen.

Hauptmerkmale:

* **Automatische Typbestimmung**: Mit `auto` kann der Compiler den Typ einer Variablen automatisch ableiten, was die Lesbarkeit verbessert und den Code flexibler macht.
* **Beispielverwendung**: In der Klasse `HumidityCalculator` wird `auto` verwendet, um den Rückgabetyp der Methode `calculateAbsoluteHumidity` zu bestimmen, was die Notwendigkeit verringert, den Typ explizit anzugeben.

Hinweis:

Die Verwendung von `auto` sollte mit Bedacht erfolgen, da sie die Lesbarkeit des Codes beeinträchtigen kann, wenn der Typ nicht sofort ersichtlich ist. Es ist ratsam, `auto` nur dann zu verwenden, wenn der Typ klar aus dem Kontext hervorgeht.

## 05_friend - Implementierung: Verwendung des Keywords friend

Die Implementierung `05_friend` demonstriert die Verwendung des Keywords `friend` in C++. Das Keyword `friend` ermöglicht es einer Funktion oder Klasse, auf private und geschützte Member einer anderen Klasse zuzugreifen, ohne dass diese Member öffentlich gemacht werden müssen. Dies kann nützlich sein, um den Zugriff auf bestimmte Daten zu ermöglichen, ohne die Kapselung zu verletzen.

---

## Zusammenfassung des Keywords-Projekts

### Vorteile der Verwendung von const in Methoden und Member-Variablen

* **Sicherheit**: `const` stellt sicher, dass Member-Variablen nicht versehentlich geändert werden.
* **Sicherheit**: `const` stellt sicher, dass Methoden keine unerwarteten Änderungen vornehmen.
* **Lesbarkeit**: Der Code ist klarer und zeigt die Absicht, dass bestimmte Werte unveränderlich sind.
* **Optimierung**: Der Compiler kann Optimierungen vornehmen, da er weiß, dass bestimmte Werte konstant sind.

### Vorteile von constexpr (Compile-Time Constants)

* **Compile-Zeit-Berechnung**: Werte, die mit `constexpr` deklariert sind, werden bereits zur Compile-Zeit berechnet, was die Effizienz erhöht.
* **Konstante Werte**: `constexpr` stellt sicher, dass die Werte unveränderlich sind und zur Laufzeit nicht geändert werden können.
* **Optimierung**: Der Compiler kann Optimierungen vornehmen, da er weiß, dass bestimmte Werte konstant sind.

### Vorteile der constexpr-static-Erweiterung für Member-Variablen

* Die Kombination von `constexpr` und `static` ermöglicht es, Konstanten zu definieren, die zur Compile-Zeit berechnet werden und nur einmal im Speicher abgelegt werden.

### Vorteile der statischen Zuweisung

* **Objektlose Member / Globale Verfolgung**: `static` Member-Variablen ermöglichen die Verfolgung von Daten über alle Instanzen einer Klasse hinweg.
* **Speichereffizienz**: `static` Variablen werden in einem gemeinsamen, speziellen Speicherbereich abgelegt. Das Betriebssystem verwaltet diesen Bereich, wodurch der Speicherverbrauch optimiert wird.
* **Objektlose Methoden**: `static` Methoden haben keinen `this` Zeiger und können ohne Instanz der Klasse aufgerufen werden. Das erhöht die Flexibilität und ermöglicht die Verwendung von Klassenmethoden ohne Instanziierung. Statische Methoden können daher nicht auch `const` sein.

### Vorteile der Verwendung von auto

* **Lesbarkeit**: `auto` verbessert die Lesbarkeit des Codes, da der Typ nicht explizit angegeben werden muss.
* **Flexibilität**: Der Compiler kann den Typ automatisch ableiten, was die Flexibilität erhöht und den Code anpassungsfähiger macht.

### Vorteile der Verwendung von friend

* **Zugriff auf private Member**: `friend` ermöglicht es einer Funktion oder Klasse, auf private und geschützte Member einer anderen Klasse zuzugreifen, ohne diese öffentlich machen zu müssen. Damit können beispielsweise Tests oder Hilfsklassen auf private Daten zugreifen, ohne die Kapselung zu verletzen.
