Sistema de Orientació amb Punters

Projecte de C++ – 0485 Programació
Autor: Jordi Rubau Font
Data: 05/12/25

 Descripció del projecte

Aquest projecte implementa un petit sistema de targeting (orientació d’objectiu) utilitzant C++.
El programa genera diversos enemics amb posicions aleatòries en un espai 2D i, després, busca quin és el més proper al punt (0,0).
Un cop trobat l’enemic objectiu, el sistema li aplica dany repetidament fins que és destruït.

A nivell educatiu, el projecte em serveix per practicar:

Estructures (struct)

Punters i pas per referència

Arrays dinàmics

Generació aleatòria

Validació d'entrada amb cin

Separació de funcionalitats en funcions

 Explicació del sistema de targeting
a) Entrada d’enemics

L’usuari introdueix quants enemics vol generar.
El programa obliga a tenir mínim 3 enemics, així que va acumulant entrades fins arribar-hi.

b) Generació d’enemics

Cada enemic disposa de:

ID (1,2,3...)

Posició aleatòria x i y entre -100 i 100

HP (vida) entre 30 i 80

c) Selecció de l’enemic més proper

Per determinar l’enemic més proper al punt (0,0), es calcula:

distància² = x² + y²


No cal calcular l’arrel quadrada: comparar les distàncies al quadrat és suficient i més eficient.

d) Aplicació de dany

Quan l’enemic objectiu és identificat, el programa li aplica dany de 20 en 20 fins que el seu HP arriba a 0, moment en què l’enemic és destruït.

 Com compilar i executar

Quan s'executa:

Demana quants enemics vols afegir

Els genera aleatòriament

Activa el sistema de targeting automàtic

Mostra quin enemic és el més proper i el va destruïnt

 Exemple de sortida
Cal generar com a mínim 3 enemics en total.
Quants enemics vols afegir? (Total actual: 0): 2
Quants enemics vols afegir? (Total actual: 2): 1

Generant 3 enemics...

[Targeting System Activated]
Enemic més proper → ID 2
Distància al quadrat: 450

Aplicat dany...
Enemy 2 HP: 72 → 52
Aplicat dany...
Enemy 2 HP: 52 → 32
Aplicat dany...
Enemy 2 HP: 32 → 12
Aplicat dany...
Enemy 2 HP: 12 → 0
Enemy destroyed!

 Captures de consola (opcional)

<img width="940" height="527" alt="image" src="https://github.com/user-attachments/assets/5ce6bc31-e486-4945-8b39-412cb4ce59be" />


 Dificultats i com les he resolt

Validació de l’entrada:
Vaig aprendre a fer servir cin.fail(), cin.clear() i cin.ignore() per evitar errors quan l’usuari escriu coses incorrectes.

Arrays i memòria dinàmica:
Vaig utilitzar new[] per crear els enemics i delete[] per alliberar la memòria.

Eficiencia en el càlcul de distància:
Comparar la distància al quadrat és més ràpid que fer servir sqrt().

Punters:
Vaig utilitzar punters per modificar els HP directament des de la funció dany().

Organització en funcions:
He continuat practicant dividir el programa per funcionalitats.
