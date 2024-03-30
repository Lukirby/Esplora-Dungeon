#Progetto di Programmazione
Giulia Torsani    
Luca Panariello   
Federica Santisi 

Legenda dei simboli:

@ = Player

X = Porta chiusa

Artefatti:

A = Artefatto (aumenta la vita massima di 10) (+40 a score)

H = Cuori (riprestina la vita, ogni cuore sono 10pv, si arriva al massimo 100pv) (+10 a score)

B = Proiettili (ogni B raccolta sono 10 proiettili) (+20 a score)

K = Chiave (apre le porte [cumulabili]) (+10 a score)

C = Mantello (permette di attraversare muri speciali) (+20 a score)

S = Scudo (invincibilità [solo un colpo]) (+30 a score)

G = Monete (semplice punteggio) (+50 a score)

Nemici:
'#' = Nemico che non attacca (mobile oppure fermo)

'%' = Nemico con attacco ravvicinato (mobile oppure fermo)

'&' = Nemico che spara (mobile oppure fermo)

Proiettili:
'-' = proiettili orizzontali

'|' = proiettili verticali

Gestione del livello del giocatore in base allo score:

 dal l1 al l3 si aumenta di 150pt (si arriva a 450)
 dal l3 al l8 si aumenta di 200pt (si arriva a 1450)
 dal l8 a l13 si aumenta di 250pt (si arriva a 2700)
 dal 13 in poi si aumenta di 300pt

  
Istruzioni:
ci si potrà muovere nel Menubar premendo le arrowkeys e selezionare la scelta con il tasto invio.
Il gioco si mette in pausa con la barra spaziatrice.

Giocatore
 Il player si muove nelle quattro direzioni usando le arrowkeys e può sparare ai nemici con i tasti A, S, D, W
 se si trova a distanza e possiede dei proiettili, altrimenti potrà attaccare solo ravvicinato
 l'attacco ravvicinato da più danno dello sparo con i proiettili.

 Le porte si aprono prendendo le chiavi. Alcuni artefatti appariranno dentro ai muri "speciali", il giocatore potrà 
 entrarvi se solo se in possesso del mantello, che si disattiverà una volta uscito (esso si disabilita comunque, come 
 lo scudo, quando la condizione diventa falsa).

 Tutti gli artefatti fanno guadagnare score, i cuori H aumentano anche i punti vita.


Nemici

-Punti (score) guadagnati dal giocatore sconfiggendo i nemici in base alla categoria
 F = fermo
 M = si muove
 A = toglie pv con attacco ravvicinato
 S = spara
 N = non attacca

 FN = +10    MN = +20
 FA = +30    MA = +40
 FS = +40    MS = +50

-Danno che infligge ogni tipo di nemico al giocatore togliendo pv
 FN = 0    MN = 0
 FA = -10    MA = -10
 FS = -05    MS = -05

Stanze

sono generate casualmente (muri, uscite, posizione di nemici e artefatti)

entrare in una stanza tramite una porta (XXX) assicura di trovare un 
Artefatto A (che aumenta la vita massima)
