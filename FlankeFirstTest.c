/* Die Funktion wird jedesmal mit neuem gemessenen Wert(value) aufgerufen,
d.h die Funktion muss erst die gemessene Werte 5 bis 10 aufbewahren */
int edgeDetect(double value)
{
	int edge = -1; // Flankenerkennung ist ausgeschaltet

	counter++;//Aufrufe werden gezählt bis 10
	if (counter > MAX) {
	}

	messWerte[counter] = value;// Messwert sichern

	if (counter == MAX) {

		}
		if (messWerte[0] < messWerte[1]) { //test auf steigende Flanke
		}
	}
	return edge;
}// end of func