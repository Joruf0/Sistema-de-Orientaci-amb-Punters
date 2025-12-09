#include <iostream>              // Permet usar cin, cout i funcionalitats bàsiques d'entrada/sortida
#include <cstdlib>               // Inclou rand(), srand()
#include <ctime>                 // Inclou time() per inicialitzar el generador aleatori
#include <limits>                // Necessari per a numeric_limits (netejar buffer cin)

using namespace std;             // Evita haver de posar std:: davant de cada cout/cin


// ==============================
// ESTRUCTURA ENEMY
// ==============================
struct Enemy {
    int id;                      // Identificador únic per a cada enemic
    float x, y;                  // Coordenades de l'enemic en un espai 2D
    int hp;                      // Punts de vida de l'enemic
};


// ==============================
// FUNCIO: trobarEnemic()
// ==============================
// Retorna un punter a l’enemic més proper a la posició (0,0)
Enemy* trobarEnemic(Enemy* enemies, int numEnemies) {

    Enemy* mésProper = &enemies[0];   // Suposem que el primer enemic és el més proper
    float distMin2 = enemies[0].x * enemies[0].x + enemies[0].y * enemies[0].y;
    // Distància al quadrat del primer enemic

// Recorrem tots els enemics
    for (int i = 1; i < numEnemies; i++) {

        float dist2 = enemies[i].x * enemies[i].x + enemies[i].y * enemies[i].y;
        // Distància al quadrat de l'enemic actual

        if (dist2 < distMin2) {        // Si aquest enemic és més proper...
            distMin2 = dist2;          // Actualitzem la distància mínima
            mésProper = &enemies[i];   // Actualitzem el punter a l'enemic més proper
        }
    }

    // Mostra per pantalla quin és l'enemic més proper
    cout << "Enemic més proper → ID " << mésProper->id << "\n";
    cout << "Distància al quadrat: " << distMin2 << "\n";

    return mésProper;                  // Retornem el punter a l’enemic objectiu
}



// ==============================
// FUNCIO: dany()
// ==============================
// Aplica dany a un enemic i actualitza els seus HP
void dany(Enemy* enemy, int damage) {

    cout << "Aplicat dany...\n";

    int hpAnterior = enemy->hp;       // Guardem els HP abans d'aplicar el dany

    enemy->hp -= damage;              // Restem els HP

    if (enemy->hp < 0) enemy->hp = 0; // Evita que quedin HP negatius

    cout << "Enemy " << enemy->id
        << " HP: " << hpAnterior << " → " << enemy->hp << "\n";

    if (enemy->hp == 0) {             // Si l'enemic queda amb 0 HP
        cout << "Enemy destroyed!\n"; // Missatge de destrucció
    }
}



// ==============================
// FUNCIO PRINCIPAL
// ==============================
int main() {

    srand(time(NULL));                // Inicialitza el generador de números aleatoris

    int totalEnemies = 0;             // Comptador total d'enemics
    int entrada;                      // Valor que l'usuari introdueix

    cout << "Cal generar com a mínim 3 enemics en total.\n";

    // ==============================
    // BUCLE PER ACUMULAR ENEMICS
    // ==============================
    while (totalEnemies < 3) {        // Repetir mentre no arribem a 3 enemics

        cout << "Quants enemics vols afegir? (Total actual: "
            << totalEnemies << "): ";

        cin >> entrada;               // Llegim el valor introduït per l’usuari

        // Validació d'entrada per evitar errors
        if (cin.fail() || entrada < 0) {
            cin.clear();              // Neteja l'error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Buida tot el que queda a l'entrada
            cout << "Entrada no vàlida.\n";
            continue;                 // Repetim
        }

        totalEnemies += entrada;      // Suma acumulada dels enemics
    }

    cout << "\nGenerant " << totalEnemies << " enemics...\n";


    // ==============================
    // CREACIÓ DELS ENEMICS
    // ==============================
    Enemy* enemies = new Enemy[totalEnemies];
    // Creem un array dinàmic d'enemics


// ==============================
// GENERACIÓ ALEATÒRIA D’ENEMICS
// ==============================
    for (int i = 0; i < totalEnemies; i++) {

        enemies[i].id = i + 1;        // Assignem un ID (1,2,3,...)

        enemies[i].x = (rand() % 201) - 100;  // Coordenada X aleatòria entre -100 i 100
        enemies[i].y = (rand() % 201) - 100;  // Coordenada Y aleatòria entre -100 i 100

        enemies[i].hp = rand() % 51 + 30;     // HP entre 30 i 80
    }


    cout << "\n[Targeting System Activated]\n";


    // ==============================
    // TROBAR L'ENEMIC MÉS PROPER
    // ==============================
    Enemy* enemicObjectiu = trobarEnemic(enemies, totalEnemies);


    // ==============================
    // APLICAR DANY FINS DESTRUIR
    // ==============================
    while (enemicObjectiu->hp > 0) {  // Mentres no estigui mort...
        dany(enemicObjectiu, 20);     // Apliquem 20 de dany
    }


    delete[] enemies;                 // Alliberem la memòria dinàmica

    return 0;                         // Final del programa
}
