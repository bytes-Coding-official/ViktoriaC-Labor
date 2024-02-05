/* Die Funktion wird jedesmal mit neuem gemessenen Wert(value) aufgerufen,
d.h die Funktion muss erst die gemessene Werte 5 bis 10 aufbewahren */
int edgeDetect(double value)
{
#define MAX	10 //max Anzahl der Messwerte auf 10 festgelegt
	//#define MAX	5//max Anzahl der Messwerte auf 5 festgelegt

	int edge = -1; // Flankenerkennung ist ausgeschaltet
	static int counter = MAX;
	static double messWerte[MAX];
	int i = 0;

	counter++;//Aufrufe werden gezählt bis 10
	if (counter > MAX-1) {
		counter = 0;
		//fill((messWerte), (messWerte+10), 0.0);  //benötigt #include <algorithm>
		for (i = 0; i < MAX-1; i++) {  // oder fill((messWerte), (messWerte+10), 0.0);
			messWerte[i] = 0;
			counter = 0;//zum Erfassen bereit
		}
	}

	messWerte[counter] = value;// Messwert sichern

	if (counter == MAX-1) {

		if (messWerte[0] > messWerte[1]) {// test auf fallende Flanke
			for (i = 0; i < MAX-1; i++) {
				if (messWerte[i] > messWerte[i + 1]) {
					edge = 0;// edge = 0 ... fallende Flanke erkannt
				}
				else {
					edge = -1;
					return edge;// test nicht bestanden, abbruch
				}//end of else
			}//end of for
		}
		if (messWerte[0] < messWerte[1]) { //test auf steigende Flanke
			for (i = 0; i < MAX-1; i++) {
				if (messWerte[i] < messWerte[i + 1]) {
					edge = 1;// edge = 1 ... steigende Flanke erkannt
				}
				else {
					edge = -1;
					return edge;// test nicht bestanden, abbruch
				}//end of else
			}//end of for
		}
	}
	return edge;
}// end of func