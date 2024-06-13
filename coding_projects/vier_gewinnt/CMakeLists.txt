######## CMakeLists.txt ########

### Allgemeine Festlegungen und Variablen ###
cmake_minimum_required(VERSION 3.8) # Angabe der minimalen CMake-Version, die benötigt wird
set(var01 Vier_gewinnt) # Setze eine Variable mit dem Namen des Projekts: var01 = Vier_gewinnt
set(Headers
   src/game_classes/board.hpp
   src/game_classes/game.hpp
   src/IO_classes/gameManager.hpp
   src/player_classes/horizontalBot.hpp
   src/player_classes/human.hpp
   src/player_classes/player.hpp
   src/player_classes/randomBot.hpp
   src/utility/playerType.hpp
   src/utility/parameter.hpp
) # Setze die Header-Dateien in die Variable Headers
set(Sources
   src/game_classes/board.cpp
   src/IO_classes/gameManager.cpp
   src/player_classes/horizontalBot.cpp
   src/player_classes/human.cpp
   src/player_classes/randomBot.cpp
   src/player_classes/player.cpp
   src/main.cpp
) # Setze die Quellcode-Dateien in die Variable Sources
project(${var01} VERSION 1.0.0 LANGUAGES CXX) # Angabe des Projektnamens, der Version und der Programmiersprachen
set(CMAKE_CXX_STANDARD 17) # Setze die C++-Standardversion auf 17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Setze die C++-Standardversion als erforderlich

### Externe Bibliotheken ###

### Definitionen für den Compiler ###
add_executable(${var01}_app src/main.cpp) # Erstelle ein ausführbares Programm mit dem Namen Vier_gewinnt_app aus der Datei main.cpp
add_library(${var01} STATIC ${Sources} ${Headers}) # Erstelle eine statische Bibliothek mit dem Namen Vier_gewinnt aus den Quellcode- und Header-Dateien
target_link_libraries(${var01}_app ${var01}) # Verlinke das ausführbare Programm mit der statischen Bibliothek
