#pragma once
/**
* Sta�a przechowuj�ca znak char 219 (wype�niony prostok�t)
*/
const unsigned char K = 219;

/**
* Sta�a przechowuj�ca znak char 201 (lewy g�rny r�g)
*/
const unsigned char LGR = 201;

/**
* Sta�a przechowuj�ca znak char 200 (lewy dony r�g)
*/
const unsigned char LDR = 200;

/**
* Sta�a przechowuj�ca znak char 187 (prawy g�rny r�g)
*/
const unsigned char PGR = 187;

/**
* Sta�a przechowuj�ca znak char 188 (prawy dolny r�g)
*/
const unsigned char PDR = 188;

/**
* Sta�a przechowuj�ca znak char 186 (podw�jna pionowa linia)
*/
const unsigned char DP = 186;

/**
* Sta�a przechowuj�ca znak char 179 (pojedyncza pionowa linia)
*/
const unsigned char SP = 179;

/**
* Sta�a przechowuj�ca znak char 196 (pojedyncza pozioma linia)
*/
const unsigned char SH = 196;

/**
* Sta�a przechowuj�ca znak char 205 (podw�jna pozioma linia)
*/
const unsigned char DH = 205;
/**
* Funkcja wypisuj�ca podw�jn� poziom� lini� z naro�nikami na jej ko�cach (g�rna lub dolna cz�� ramki)
* 
* \param[in] len - d�ugo�� linii
* \param[in] x - numer kolumny konsoli, w kt�rej rozpocznie si� wypisywanie linii
* \param[in] y - numer wiersza konsoli, w kt�rym rozpocznie si� wypisywanie linii
* \param[in] up - informacja, czy naro�niki maj� by� skierowane w do�, czy w g�r�: true - w g�r�, false - w d�
*/
void horizontal_edge(int len, int x, int y, bool up);

/**
* Funkcja wypisuj�ca podw�jn� pionow� lini�.
*
* \param[in] len - d�ugo�� linii
* \param[in] x - numer kolumny konsoli, w kt�rej rozpocznie si� wypisywanie linii
* \param[in] y - numer wiersza konsoli, w kt�rym rozpocznie si� wypisywanie linii
*/
void vertical_edge(int len, int x, int y);

/**
* Funkcja wypisuj�ca ramk� z podw�jnych linii.
*
* \param[in] lenhor - szeroko�� ramki
* \param[in] lenver - wysoko�� ramki
* \param[in] x - numer kolumny konsoli, w kt�rej rozpocznie si� wypisywanie linii
* \param[in] y - numer wiersza konsoli, w kt�rym rozpocznie si� wypisywanie linii
*/
void print_frame(int lenhor, int lenver, int x, int y);