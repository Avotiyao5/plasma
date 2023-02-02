#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Header.h"

using namespace std;

inline vector <long double > mfc(long double x2, long double y2, long double z2, vector <vector<long double>> wir, vector <vector<long double>> wire_vector, vector <vector<long double>> wir_sol, vector <vector<long double>> wire_vector_sol, long double t) {

	vector <vector<long double>> radius_vector = { {    },    // двумерный массив векторов радиус векторов от обмотки до точки расчёта поля сразу с вычетом координат(конечные минус начальные)
												   {    },
												   {    } };

	vector <vector<long double>> radius_vector_sol = { {    },    // двумерный массив векторов радиус векторов от обмотки до точки расчёта поля сразу с вычетом координат(конечные минус начальные)
												   {    },
												   {    } };

	vector <vector<long double>> magnetic_field = { {    },   // двумерный массив векторов векторного произведения векторов кусочков обмотки и радиус векторов
													{    },
													{    } };
	vector <vector<long double>> magnetic_field_sol = { {    },   // двумерный массив векторов векторного произведения векторов кусочков обмотки и радиус векторов
													{    },
													{    } };

	vector <vector<long double>> magnetic_field2 = { {    },   // двумерный масссив векторов магнитного поля
													 {    },
													 {    } };
	vector < vector<long double>> onepar = { {}, {}, {}, {}, {}, {}, {}, {}, {}, {} };

	vector <long double> radius_vector_length;  //одномерный массив длин радиус векторов
	vector <long double> radius_vector_length_sol;
	vector <long double> otvet;
	int b=0;
	// x2, y2, z2координаты точки, в которой надо посчитать магнитное поле, то есть по сути координата частицы
	long double B=0; //значение магнитного поля в заданной точке
	long double I= 48144000, I2max = 151200000, I2; //значение силы тока в обмотке     48144000
	long double j, rr, f, a1=0, b1=0, c1=0; //служебные переменные
		for (int c = 0; c < wir[0].size(); c++) {						// этот цикл записывает вычеты координат радиус векторов
			radius_vector[0].push_back(x2 - wir[0][c]);
			radius_vector[1].push_back(y2 - wir[1][c]);
			radius_vector[2].push_back(z2 - wir[2][c]);
			
		}
		for (int c = 0; c < wir_sol[0].size(); c++) {						// этот цикл записывает вычеты координат радиус векторов
			radius_vector_sol[0].push_back(x2 - wir_sol[0][c]);
			radius_vector_sol[1].push_back(y2 - wir_sol[1][c]);
			radius_vector_sol[2].push_back(z2 - wir_sol[2][c]);
		}
		for (int c = 0; c < wire_vector[0].size(); c++) {               // этот цикл записывает вычеты координат векторного произведения маленьких векторочков обмотки на радиус вектора
			magnetic_field[0].push_back(wire_vector[1][c] * radius_vector[2][c] - wire_vector[2][c] * radius_vector[1][c]); // формула для векторного произведения черерз координаты
			magnetic_field[1].push_back(wire_vector[2][c] * radius_vector[0][c] - wire_vector[0][c] * radius_vector[2][c]);
			magnetic_field[2].push_back(wire_vector[0][c] * radius_vector[1][c] - wire_vector[1][c] * radius_vector[0][c]);
		}
		for (int c = 0; c < wire_vector_sol[0].size(); c++) {               // этот цикл записывает вычеты координат векторного произведения маленьких векторочков обмотки на радиус вектора
			magnetic_field_sol[0].push_back(wire_vector_sol[1][c] * radius_vector_sol[2][c] - wire_vector_sol[2][c] * radius_vector_sol[1][c]); // формула для векторного произведения черерз координаты
			magnetic_field_sol[1].push_back(wire_vector_sol[2][c] * radius_vector_sol[0][c] - wire_vector[0][c] * radius_vector_sol[2][c]);
			magnetic_field_sol[2].push_back(wire_vector[0][c] * radius_vector_sol[1][c] - wire_vector_sol[1][c] * radius_vector_sol[0][c]);
		}
		for (int c = 0; c < radius_vector[0].size(); c++) {              // этот цикл записывает длины радиус векторов
			radius_vector_length.push_back(sqrt(radius_vector[0][c] * radius_vector[0][c] + radius_vector[1][c] * radius_vector[1][c] + radius_vector[2][c] * radius_vector[2][c]));
		}
		for (int c = 0; c < radius_vector_sol[0].size(); c++) {              // этот цикл записывает длины радиус векторов
			radius_vector_length_sol.push_back(sqrt(radius_vector_sol[0][c] * radius_vector_sol[0][c] + radius_vector_sol[1][c] * radius_vector_sol[1][c] + radius_vector_sol[2][c] * radius_vector_sol[2][c]));
		}
		for (int c = 0; c < magnetic_field[0].size(); c++) {			// этот цикл записывает магнитные поля от каждого маленького кусочка обмотки
			b = 0;
			j = sqrt(magnetic_field[0][c] * magnetic_field[0][c] + magnetic_field[1][c] * magnetic_field[1][c] + magnetic_field[2][c] * magnetic_field[2][c]);
			rr = pow(radius_vector_length[c], 3);
			while (b <= 2) {
				f = magnetic_field[b][c] * I * mm0 / 4 / PI / rr;
				magnetic_field2[b].push_back(f);
				b++;
			}
		}
		//I2 = I2max * sin((t * pow(10, 8) + 1) * PI / 180) / 2;
		for (int c = 0; c < magnetic_field_sol[0].size(); c++) {			// этот цикл записывает магнитные поля от каждого маленького кусочка обмотки
			b = 0;
			j = sqrt(magnetic_field_sol[0][c] * magnetic_field_sol[0][c] + magnetic_field_sol[1][c] * magnetic_field_sol[1][c] + magnetic_field_sol[2][c] * magnetic_field_sol[2][c]);
			rr = pow(radius_vector_length_sol[c], 3);
			while (b <= 2) {
				f = magnetic_field_sol[b][c] * I2max * mm0 / 4 / PI / rr;
				magnetic_field2[b].push_back(f);
				b++;
			}
		}
		for (int c = 0; c < magnetic_field2[0].size(); c++) {        // этот цикл векторно суммирует все маленькие поля в результирующее поле 
			a1 = a1 + magnetic_field2[0][c];
			b1 = b1 + magnetic_field2[1][c];
			c1 = c1 + magnetic_field2[2][c];
		}
		B = sqrt(a1 * a1 + b1 * b1 + c1 * c1);               // ищем длину вектора магнитного поля
		otvet.push_back(a1);
		otvet.push_back(b1);
		otvet.push_back(c1);

		return otvet;
}


inline vector <long double> kfc( vector <vector <vector <vector <long double>>>> particles, long double x, long double y, long double z,int b, int a) {
	vector <long double> otvet;
	int c = 0;
	long double E, Ex, Ey, Ez;
	long double r;
	otvet.push_back(0);
	otvet.push_back(0);
	otvet.push_back(0);
	while (c < particles.size()) {
		if (particles[c].size() > 0) {                                                 //
			int d = 0;
			while (d < particles[c].size()) {
				if (particles[c][d].size() > 0) {
					if (c == a && d == b) {
						d++;
					}
					else {
						if (particles[c][d][0].size() > 0) {
							r =  (x - particles[c][d][0][0]) * (x - particles[c][d][0][0]) + (y - particles[c][d][1][0]) * (y - particles[c][d][1][0]) + (z - particles[c][d][2][0]) * (z - particles[c][d][2][0]);
							if (abs(r) > 0 && abs(r) <= pow(10,-6)) {
								E = 8.988 * charge[c] * 1.6021766208 / r;
								Ex = E * (x - particles[c][d][0][0]) / sqrt(r);
								Ey = E * (y - particles[c][d][1][0]) / sqrt(r);
								Ez = E * (z - particles[c][d][2][0]) / sqrt(r);
								otvet[0] = otvet[0] + Ex;
								otvet[1] = otvet[1] + Ey;
								otvet[2] = otvet[2] + Ez;
							}
						}
						d++;
					}
				}
				else {
					d++;
				}
			}
			c++;
		}
		else {
			c++;
		}
	}
	return otvet;
}
inline vector < vector <long double>> rr(int a, int b) {
	vector < vector <long double>> otvet;
	if (a == 3 && b == 3) {
		int v = rand() % 2;
		if (v == 0) {
			otvet.resize(2);
			otvet[0].push_back(4);
			otvet[1].push_back(2);
			otvet[0].push_back(sqrt(0.000000000000162 * 2 / mass[4]));
			otvet[1].push_back(sqrt(0.000000000000484 * 2 / mass[2]));
		}
		else {
			otvet.resize(2);
			otvet[0].push_back(5);
			otvet[1].push_back(1);
			otvet[0].push_back(sqrt(0.000000000000131 * 2 / mass[5]));
			otvet[1].push_back(sqrt(0.000000000000393 * 2 / mass[2]));
		}
	}
	if ((a == 3 && b == 4) || (a == 4 && b == 3)) {
		otvet.resize(2);
		otvet[0].push_back(6);
		otvet[1].push_back(1);
		otvet[0].push_back(sqrt(0.000000000000561 * 2 / mass[6]));
		otvet[1].push_back(sqrt(0.00000000000226 * 2 / mass[1]));
	}
	if ((a == 3 && b == 5) || (a == 3 && b == 5)) {
		otvet.resize(2);
		otvet[0].push_back(6);
		otvet[1].push_back(2);
		otvet[0].push_back(sqrt(0.000000000000577 * 2 / mass[6]));
		otvet[1].push_back(sqrt(0.00000000000236 * 2 / mass[2]));
	}
	if (a == 4 && b == 4) {
		otvet.resize(3);
		otvet[0].push_back(6);
		otvet[1].push_back(1);
		otvet[2].push_back(1);
		otvet[0].push_back(0);
		otvet[1].push_back(sqrt(0.000000000000905 * 2 / mass[1]));
		otvet[2].push_back(sqrt(0.000000000000905 * 2 / mass[1]));
	}
	if (a == 5 && b == 5) {
		otvet.resize(3);
		otvet[0].push_back(6);
		otvet[1].push_back(2);
		otvet[2].push_back(2);
		otvet[0].push_back(0);
		otvet[1].push_back(sqrt(0.000000000001029 * 2 / mass[2]));
		otvet[2].push_back(sqrt(0.000000000001029 * 2 / mass[2]));
	}
	if ((a == 4 && b == 5) || (a == 4 && b == 5)) {
		int v = rand() % 100;
		if (v > 48) {
			otvet.resize(3);
			otvet[0].push_back(6);
			otvet[1].push_back(2);
			otvet[2].push_back(1);
			otvet[0].push_back(0);
			otvet[1].push_back(sqrt(0.000000000000969 * 2 / mass[2]));
			otvet[2].push_back(sqrt(0.000000000000969 * 2 / mass[1]));
		}
		else if (v < 6) {
			otvet.resize(3);
			otvet[0].push_back(6);
			otvet[1].push_back(2);
			otvet[2].push_back(1);
			otvet[0].push_back(sqrt(0.00000000000008 * 2 / mass[6]));
			otvet[1].push_back(sqrt(0.0000000000019 * 2 / mass[2]));
			otvet[2].push_back(sqrt(0.000000000000304 * 2 / mass[1]));
		}
		else {
			otvet.resize(2);
			otvet[0].push_back(6);
			otvet[1].push_back(3);
			otvet[0].push_back(sqrt(0.000000000000769 * 2 / mass[6]));
			otvet[1].push_back(sqrt(0.000000000001522 * 2 / mass[3]));
		}
		return otvet;
	}
}
inline vector < vector <long double>> nf(vector <vector <vector <vector <long double>>>> particles) {
	vector < vector <long double>> otvet;
	int c = 0; 
	long double r = 0;
	int co = particles.size();
	vector < vector <long double>> re;
	long double E1, E2, E;
	long double cos = 0, ch = 0, zn = 0, cos2 = 0, ch2 = 0, zn2 = 0;												// служебные переменные
	while (co > c) {
		int d = 0;
		while (particles[c].size() > d) {
			int a = c;
			while (co > a) {
				re = rr(c, a);
				if (re.size() != 0) {
					int b = 0;
					while (particles[c].size() > b) {
						if ((c != a) && (d != b)) {
							r = (particles[a][b][0][0] - particles[c][d][0][0]) * (particles[a][b][0][0] - particles[c][d][0][0]) + (particles[a][b][1][0] - particles[c][d][1][0]) * (particles[a][b][1][0] - particles[c][d][1][0]) + (particles[a][b][2][0] - particles[c][d][2][0]) * (particles[a][b][2][0] - particles[c][d][2][0]);
							if (sqrt(r) <= 0.000000000001) {
								if (sqrt(r) <= 0.000000000000001) {
									//particles[re[0][0]].push_back({});
								}
								else {
									ch = (particles[c][d][0][0] - particles[a][b][0][0]) * (particles[a][b][3][0] - particles[a][b][0][0]) + (particles[c][d][1][0] - particles[a][b][1][0]) * (particles[a][b][4][0] - particles[a][b][1][0]) + (particles[c][d][2][0] - particles[a][b][2][0]) * (particles[a][b][5][0] - particles[a][b][2][0]);
									zn = sqrt(r) * sqrt((particles[a][b][3][0] - particles[a][b][0][0]) * (particles[a][b][3][0] - particles[a][b][0][0]) + (particles[a][b][4][0] - particles[a][b][1][0]) * (particles[a][b][4][0] - particles[a][b][1][0]) + (particles[a][b][5][0] - particles[a][b][2][0]) * (particles[a][b][5][0] - particles[a][b][2][0]));
									cos = ch / zn;
									ch2 = (particles[a][b][0][0] - particles[c][d][0][0]) * (particles[c][d][3][0] - particles[c][d][0][0]) + (particles[a][b][1][0] - particles[c][d][1][0]) * (particles[c][d][4][0] - particles[c][d][1][0]) + (particles[a][b][2][0] - particles[c][d][2][0]) * (particles[c][d][5][0] - particles[c][d][2][0]);
									zn2 = sqrt(r) * sqrt((particles[c][d][3][0] - particles[c][d][0][0]) * (particles[c][d][3][0] - particles[c][d][0][0]) + (particles[c][d][4][0] - particles[c][d][1][0]) * (particles[c][d][4][0] - particles[c][d][1][0]) + (particles[c][d][5][0] - particles[c][d][2][0]) * (particles[c][d][5][0] - particles[c][d][2][0]));
									cos2 = ch2 / zn2;
									E1 = mass[c] * (particles[c][d][3][0] * particles[c][d][3][0] + particles[c][d][4][0] * particles[c][d][4][0] + particles[c][d][5][0] * particles[c][d][5][0]) * cos * cos / 2;
									E2 = mass[a] * (particles[a][b][3][0] * particles[a][b][3][0] + particles[a][b][4][0] * particles[a][b][4][0] + particles[a][b][5][0] * particles[a][b][5][0]) * cos2 * cos2 / 2;
									E = E1 + E2;
								}
							}
						}
						b++;
					}
				}
				a++;
			}
			d++;
		}
		c++;
	}
	return otvet;
}