#include <iostream>
using namespace std;


/*
*Creare in C++ una classe TIME  per gestire un tempo in ore, minuti e secondi all'interno dello stesso giorno
esempio : 16:30:30

Richieste minime:
    costruttore senza parametri :        time t1,t2;
    costruttore con parametri :            time t1(16,30,30);
    costruttore copia:                             time t1(t2);   // novità!!

     metodo show(parametro) : serve per visualizzare il time in due formati, il formato 24h (16:30:30) il formato 12h (4PM:30:30)
     metodo set(...)  : serve per impostare un orario nell'oggetto
    metodo get_o(): serve per estrarre l'ora
    metodo get_m(): serve per estrarre i minuti
    metodo get_s(): serve per estrarre i secondi


    operator > : serve per sapere se un orario è successivo ad un altro 16:30:30 > 12:30:30  -> true
    operator < : idem sopra
    operator == : serve per sapere se due orari coincidono (banale!)
    operator- : serve per calcolare in secondi la differenza fra due orari ex: 16:30:30 - 15:30:30 = 3600
    operator+ : serve per sommare ad un orario un valore in secondi ex: 16:30:00+ 1800 = 17:00:00 (friend!!)
 *
 */


int main() {


    return 0;
}