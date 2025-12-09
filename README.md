Sistema de Orientació 
amb Punters
0485 - Programació
Jordi Rubau Font
5/12/25 
• Descripció del projecte.
• Explicació del sistema de targeting.
• Com compilar-lo i provar-lo.
• Exemple de sortida.
• Captures de consola (opcional).
• Dificultats i resolució.
1. Descripció del projecte
En aquest projecte he fet un petit programa que genera enemics de manera aleatòria 
en un espai 2D. Després, el programa busca quin d’aquests enemics és el més proper 
al punt (0,0) i li aplica dany fins que queda destruït. L’objectiu és practicar conceptes 
com estructures, punters, arrays dinàmics i validació d'entrada.
2. Explicació del sistema de targeting
a) Entrada d'enemics
L’usuari ha d'introduir quants enemics vol afegir. El programa exigeix que n'hi hagi com 
a mínim 3, així que es van acumulant les entrades fins arribar-hi.
b) Generació d’enemics
Cada enemic té una posició aleatòria (x, y) entre -100 i 100, un ID i uns punts de vida 
(HP) també aleatoris entre 30 i 80.
c) Selecció de l’enemic més proper
Per trobar quin enemic és el més proper al punt (0,0), calculo la distància al quadrat: x² 
+ y². No faig arrels quadrades perquè no cal per comparar.
d) Aplicació de dany
Un cop trobat l’enemic objectiu, se li aplica dany de 20 en 20 fins que els seus punts de 
vida arriben a 0.
3. Com compilar i provar el programa
Quan l'executes, el programa et demanarà quants enemics vols afegir, els generarà i 
començarà el sistema de targeting automàtic.
4. Exemple de sortida
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
5. Captures de consola (exemple)
6. Dificultats i com les he resolt
• Validació de l’entrada: vaig aprendre a fer servir cin.fail(), cin.clear() i cin.ignore().
• Memòria dinàmica: vaig haver de recordar utilitzar delete[].
• Comparar distància sense fer arrels quadrades, que és més eficient.
• Necessitat de punters perquè la funció pogués modificar els HP reals.
• Seguir practicant crear funcions.
