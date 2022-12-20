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
							r =  (x - particles[c][d][0].back()) * (x - particles[c][d][0].back()) + (y - particles[c][d][1].back()) * (y - particles[c][d][1].back()) + (z - particles[c][d][2].back()) * (z - particles[c][d][2].back());
							if (abs(r) > 0 && abs(r) <= pow(10,-6)) {
								E = 8.988 * 1.6021766208 / r;
								Ex = E * (x - particles[c][d][0].back()) / sqrt(r);
								Ey = E * (y - particles[c][d][1].back()) / sqrt(r);
								Ez = E * (z - particles[c][d][2].back()) / sqrt(r);
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
