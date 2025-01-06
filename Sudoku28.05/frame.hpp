#pragma once
/**
* Sta³a przechowuj¹ca znak char 219 (wype³niony prostok¹t)
*/
const unsigned char K = 219;

/**
* Sta³a przechowuj¹ca znak char 201 (lewy górny róg)
*/
const unsigned char LGR = 201;

/**
* Sta³a przechowuj¹ca znak char 200 (lewy dony róg)
*/
const unsigned char LDR = 200;

/**
* Sta³a przechowuj¹ca znak char 187 (prawy górny róg)
*/
const unsigned char PGR = 187;

/**
* Sta³a przechowuj¹ca znak char 188 (prawy dolny róg)
*/
const unsigned char PDR = 188;

/**
* Sta³a przechowuj¹ca znak char 186 (podwójna pionowa linia)
*/
const unsigned char DP = 186;

/**
* Sta³a przechowuj¹ca znak char 179 (pojedyncza pionowa linia)
*/
const unsigned char SP = 179;

/**
* Sta³a przechowuj¹ca znak char 196 (pojedyncza pozioma linia)
*/
const unsigned char SH = 196;

/**
* Sta³a przechowuj¹ca znak char 205 (podwójna pozioma linia)
*/
const unsigned char DH = 205;
/**
* Funkcja wypisuj¹ca podwójn¹ poziom¹ liniê z naro¿nikami na jej koñcach (górna lub dolna czêœæ ramki)
* 
* \param[in] len - d³ugoœæ linii
* \param[in] x - numer kolumny konsoli, w której rozpocznie siê wypisywanie linii
* \param[in] y - numer wiersza konsoli, w którym rozpocznie siê wypisywanie linii
* \param[in] up - informacja, czy naro¿niki maj¹ byæ skierowane w do³, czy w górê: true - w górê, false - w dó³
*/
void horizontal_edge(int len, int x, int y, bool up);

/**
* Funkcja wypisuj¹ca podwójn¹ pionow¹ liniê.
*
* \param[in] len - d³ugoœæ linii
* \param[in] x - numer kolumny konsoli, w której rozpocznie siê wypisywanie linii
* \param[in] y - numer wiersza konsoli, w którym rozpocznie siê wypisywanie linii
*/
void vertical_edge(int len, int x, int y);

/**
* Funkcja wypisuj¹ca ramkê z podwójnych linii.
*
* \param[in] lenhor - szerokoœæ ramki
* \param[in] lenver - wysokoœæ ramki
* \param[in] x - numer kolumny konsoli, w której rozpocznie siê wypisywanie linii
* \param[in] y - numer wiersza konsoli, w którym rozpocznie siê wypisywanie linii
*/
void print_frame(int lenhor, int lenver, int x, int y);