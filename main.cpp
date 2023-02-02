#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Header.h"
#include "functions.cpp"

using namespace std;

vector <vector <vector <vector<long double>>>> particles = { { {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } },
															{ {  {}, {}, {}, {}, {}, {}, {}, {}, {}, {}  } } }; //электроны-0 протоны-1 нейтроны-2 дейтроны-3 тритии-4 гелии3-5 гелии4-6
// это четырёхмерный массив, штука достаточно сложная для понимания
// 0   1   2   3   4   5   6   7   8   9
// строки соответстуют изменению во вермени
// 9 столбиков это 9 свойств каждой частицы, а именно, по порядку:три координаты местонахождения 
//самой частицы (в порядке: x, y, z)(три координаты(0,1,2)),вектор скорости (три координаты(3,4,5)),три координаты ускорения(6,7,8), время


vector < vector <long double>> pusb =  { {}, {}, {}, {}, {}, {}, {}, {}, {}, {} } ; // образец массива для добавления новой частицы

vector <vector<long double>> wire = { {    },     // двумерный массив координат векторочков обмотке(начальные координаты, конечные)
							  {    },
							  {    },
							  {    },
							  {    },
							  {    } };
vector <vector<long double>> wire_vector = { {    },    // двумерный маасив векторочко обмотки с вычетом координат( конечные минус начальные)
												 {    },
												 {    } };
vector <vector<long double>> wire_sol = { {    },     // двумерный массив координат векторочков обмотке(начальные координаты, конечные)
							  {    },
							  {    },
							  {    },
							  {    },
							  {    } };
vector <vector<long double>> wire_vector_sol = { {    },    // двумерный маасив векторочко обмотки с вычетом координат( конечные минус начальные)
												 {    },
												 {    } };
vector <long double> otvet;
vector <long double> otvet2;
int main() {
	ofstream fout;
	fout.open("tor.txt");
	long double x, y, z, j;  // x, y, z - координаты;  j -  координата когда мы строи маленткую окружность, она нужна потому что, в зависимости от положения на кольце
	long double R = 0.5, r = 0.528*R; // r  радиус внутритора(маленький радиус)  ; R  - большой радиус от центра тора к центру кольца 
	int a, v = 0;
	int sol = 0;
	int u = 0;
	long double RR;
	while (u < 12) {
		double corner3 = 0;
		while (corner3 <= 360) {
			long double x0 = 0;
			long double z0 = 0;
			x0 = cos(corner3 * PI / 180);
			z0 = sin(corner3 * PI / 180);
			if (u == 0) {
				sol = 1;
				RR = R*0.48;
				x = RR * x0;
				z = RR * z0;
				y = 7/6.6 * r;
			}
			else if (u == 1) {
				sol = 1;
				RR = R*1.28;
				x = RR * x0;
				z = RR * z0;
				y = 6/6.6 * r;
			}
			else if (u == 2) {
				sol = 1;
				RR = R*1.68;
				x = RR * x0;
				z = RR * z0;
				y = 2.5/6.6 * r;
			}
			else if (u == 3) {
				sol = 1;
				RR = R*1.68;
				x = RR * x0;
				z = RR * z0;
				y = -2.5/6.6 * r;
			}
			else if (u == 4) {
				sol = 1;
				RR = R*1.28;
				x = RR * x0;
				z = RR * z0;
				y = -6/6.6 * r;
			}
			else if (u == 5) {
				sol = 1;
				RR = R*0.48;
				x = RR * x0;
				z = RR * z0;
				y = -7/6.6 * r;
			}
			else if (u == 6) {
				sol = 0;
				RR = R * 0.16;
				x = RR * x0;
				z = RR * z0;
				y = -6.5/6.6 *r;
			}
			else if (u == 7) {
				sol = 0;
				RR = R*0.16;
				x = RR * x0;
				z = RR * z0;
				y = -3.5 / 6.6 * r;
			}
			else if (u == 8) {
				sol = 0;
				RR = R * 0.16;
				x = RR * x0;
				z = RR * z0;
				y = -1 / 6.6 * r;
			}
			else if (u == 9) {
				sol = 0;
				RR = R * 0.16;
				x = RR * x0;
				z = RR * z0;
				y = 1 / 6.6 * r;
			}
			else if (u == 10) {
				sol = 0;
				RR = R * 0.16;
				x = RR * x0;
				z = RR * z0;
				y = 3.5 / 6.6 * r;
			}
			else {
				sol = 0;
				RR = R * 0.16;
				x = RR * x0;
				z = RR * z0;
				y = 6.5 / 6.6 * r;
			}
			fout << x << " " << y << " " << z << endl;
			if (sol == 0) {
				if (corner3 == 0) {
					wire_sol[0].push_back(x);
					wire_sol[1].push_back(y);
					wire_sol[2].push_back(z);
				}
				else if (corner3 == 360) {
					wire_sol[3].push_back(x);
					wire_sol[4].push_back(y);
					wire_sol[5].push_back(z);
				}
				else {
					wire_sol[3].push_back(x);
					wire_sol[4].push_back(y);
					wire_sol[5].push_back(z);
					wire_sol[0].push_back(x);
					wire_sol[1].push_back(y);
					wire_sol[2].push_back(z);
				}
			}
			else {
				if (corner3 == 0) {
					wire[0].push_back(x);
					wire[1].push_back(y);
					wire[2].push_back(z);
				}
				else if (corner3 == 360) {
					wire[3].push_back(x);
					wire[4].push_back(y);
					wire[5].push_back(z);
				}
				else {
					wire[3].push_back(x);
					wire[4].push_back(y);
					wire[5].push_back(z);
					wire[0].push_back(x);
					wire[1].push_back(y);
					wire[2].push_back(z);
				}
			}
			corner3 = corner3 + 36;
		}
		u = u + 1;
	}
	
	double corner = 0; // угол  от 0 до 360(угол большого кольца)
	while (corner <= 360) {  // цикл котрый перебирает угол с шаго по 1
		long double x0 = 0;   //служебые переменные тоже самое что x и y
		long double z0 = 0;
		x0 = cos(corner * PI / 180) * R; //высчитываю координаты большой окружности 
		z0 = sin(corner * PI / 180) * R;
		double corner2 = 0;
		while (corner2 <= 360) {  // второй цикл на каждом отрезке окружности по 1 градус мы строим одно маленькое кольцо
			long double x1 = 0; // служебные переменные
			long double z1 = 0;
			y = sin(corner2 * PI / 180) * r; // высчитываем координаты
			j = cos(corner2 * PI / 180) * r;
			x1 = cos(corner * PI / 180) * j; // переводиv j d x и y, потому что t было с учотом угла, стороны которого, это ось x и луч проведённый ищ центра тора к куску окружности,
			z1 = sin(corner * PI / 180) * j; // на котром мы сейчас строим маленькую окружность
			x = x1 + x0; //складываем служебные переменные получаем координаты получаем координаты из центра тора
			z = z1 + z0;
			fout << x << " " << y << " " << z << endl; //всё выводим
			if (corner2 == 0) {                     // с 69 строчки по 119 махинации по записи координат векторочков обмотки(так много надо, чтобы ничё не сломалось, 
				a = 0;								//и чтобы конкретно нчала векторов и концы записывались в нужные места)
				while (a < 3) {
					if (a == 0) {
						wire[a].push_back(x);
					}
					if (a == 1) {
						wire[a].push_back(y);
					}
					if (a == 2) {
						wire[a].push_back(z);
					}
					a++;
				}
			}
			else if (corner2 == 360) {
				a = 3;
				while (a < 6) {
					if (a == 3) {
						wire[a].push_back(x);
					}
					if (a == 4) {
						wire[a].push_back(y);
					}
					if (a == 5) {
						wire[a].push_back(z);
					}
					a++;
				}
			}
			else {
				a = 3;
				while (a < 9) {
					if (a == 3) {
						wire[a].push_back(x);
					}
					if (a == 4) {
						wire[a].push_back(y);
					}
					if (a == 5) {
						wire[a].push_back(z);
					}
					if (a == 6) {
						wire[a - 6].push_back(x);
					}
					if (a == 7) {
						wire[a - 6].push_back(y);
					}
					if (a == 8) {
						wire[a - 6].push_back(z);
					}
					a++;
				}
			}
			corner2 = corner2 + 20;
		}
		corner = corner + 20;
		/*
		if (v <= 118) {                                         
			corner = corner + 0.05085;                          //0.05085
			v++;
		}
		else {
			corner = corner + 14;                                //14
			v = 0;
		}
		*/
	}

	for (int c = 0; c < wire[0].size(); c++) {                    // этот цикл записывает вычеты координат маленьких вектрочков обмотки
		a = 0;
		while (a <= 2) {
			wire_vector[a].push_back(wire[a + 3][c] - wire[a][c]);
			a++;
		}
	}
	for (int c = 0; c < wire_sol[0].size(); c++) {                    // этот цикл записывает вычеты координат маленьких вектрочков обмотки
		a = 0;
		while (a <= 2) {
			wire_vector_sol[a].push_back(wire_sol[a + 3][c] - wire_sol[a][c]);
			a++;
		}
	}
	/*
	long double corner4 = 0;
	ofstream ffout;
	ffout.open("tor2.txt");
	while (corner4 <= 360) {
		ffout << 0 << " " << 12.5 + sin(corner4 * PI / 180) * r << " " << 12.5 + cos(corner4 * PI / 180) * r << endl;
		corner4++;
	}
	ffout.close();

	long double z4 = 5.9, y4 = 5.9;
	while (z4 <= 19.1) {
		y4 = 5.9;
		while (y4 <= 19.1) {
			otvet = mfc(0, y4, z4, wire, wire_vector, wire_sol, wire_vector_sol,0);
			if (abs(otvet[1]) <= 20) {
				fout << otvet[1] << " " << y4 << " " << z4 << endl;
			}
			y4 = y4 + 0.1;
		}
		cout << z4 << endl;
		z4 = z4 + 0.1;
	}
	*/
	long double t = 0;
	int counter_of_particles = 0, counter_of_particles2 = 0;
	long double v0xz = 1000000;
	long double dt = 1 * pow(10, -13);											// 1 * pow(10, -22)
	long double dt2 = 10 * pow(10, -11);
	long double con2 = 1.6021766208 * pow(10, 2);
	long double con = 0;
	int tcount = 0, i = 0;
	int qua = 2;
	int por = 0;
	particles[3].resize(qua, pusb);
	particles[4].resize(qua, pusb);
	particles[0].resize(2*qua, pusb);
	while (t <  10* pow(10, -10)) {
		i++;
		if (i == dt2/dt) {
			if (por == 0) {
				if (counter_of_particles < qua) {
					i = 0;
					con = con2 * charge[3] / mass[3];
					particles[3][counter_of_particles][0].push_back(0);
					particles[3][counter_of_particles][0].push_back(0);
					particles[3][counter_of_particles][1].push_back(0);
					particles[3][counter_of_particles][1].push_back(0);
					particles[3][counter_of_particles][2].push_back(R);
					particles[3][counter_of_particles][2].push_back(0);
					particles[3][counter_of_particles][3].push_back(-v0xz * 0.3);
					particles[3][counter_of_particles][3].push_back(0);
					particles[3][counter_of_particles][4].push_back(0);
					particles[3][counter_of_particles][4].push_back(0);
					particles[3][counter_of_particles][5].push_back(-v0xz * 0.9);
					particles[3][counter_of_particles][5].push_back(0.10101010101);
					otvet = mfc(particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
					//otvet2 = kfc(particles, particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), 3, counter_of_particles);
					particles[3][counter_of_particles][6].push_back(((particles[3][counter_of_particles][4][0] * otvet[2] - particles[3][counter_of_particles][5][0] * otvet[1]) * 1000000 /* + otvet2[0]*/) * con);
					particles[3][counter_of_particles][6].push_back(0);
					particles[3][counter_of_particles][7].push_back(((particles[3][counter_of_particles][5][0] * otvet[0] - particles[3][counter_of_particles][3][0] * otvet[2]) * 1000000 /* + otvet2[1]*/) * con);
					particles[3][counter_of_particles][7].push_back(0);
					particles[3][counter_of_particles][8].push_back(((particles[3][counter_of_particles][3][0] * otvet[1] - particles[3][counter_of_particles][4][0] * otvet[0]) * 1000000 /* + otvet2[2]*/) * con);
					particles[3][counter_of_particles][8].push_back(0);
					particles[3][counter_of_particles][9].push_back(t);
					particles[3][counter_of_particles][9].push_back(0);
					con = con2 * charge[0] / mass[0];
					particles[0][counter_of_particles + counter_of_particles2][0].push_back(0.000001);
					particles[0][counter_of_particles + counter_of_particles2][0].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][1].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][1].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][2].push_back(R);
					particles[0][counter_of_particles + counter_of_particles2][2].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][3].push_back(-v0xz * 0.3);
					particles[0][counter_of_particles + counter_of_particles2][3].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][4].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][4].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][5].push_back(-v0xz * 0.9);
					particles[0][counter_of_particles + counter_of_particles2][5].push_back(0.10101010101);
					otvet = mfc(particles[3][counter_of_particles + counter_of_particles2][0].back(), particles[3][counter_of_particles + counter_of_particles2][1].back(), particles[3][counter_of_particles + counter_of_particles2][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
					//otvet2 = kfc(particles, particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), 3, counter_of_particles);
					particles[0][counter_of_particles + counter_of_particles2][6].push_back(((particles[0][counter_of_particles + counter_of_particles2][4][0] * otvet[2] - particles[0][counter_of_particles + counter_of_particles2][5][0] * otvet[1]) * 1000000 /* + otvet2[0]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][6].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][7].push_back(((particles[0][counter_of_particles + counter_of_particles2][5][0] * otvet[0] - particles[0][counter_of_particles + counter_of_particles2][3][0] * otvet[2]) * 1000000 /* + otvet2[1]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][7].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][8].push_back(((particles[0][counter_of_particles + counter_of_particles2][3][0] * otvet[1] - particles[0][counter_of_particles + counter_of_particles2][4][0] * otvet[0]) * 1000000 /* + otvet2[2]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][8].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][9].push_back(t);
					particles[0][counter_of_particles + counter_of_particles2][9].push_back(0);
					counter_of_particles++;
				}
				por = 1;
			}
			else if (por == 1) {
				if (counter_of_particles2 < qua) {
					i = 0;
					con = con2 * charge[4] / mass[4];
					particles[4][counter_of_particles2][0].push_back(0);
					particles[4][counter_of_particles2][0].push_back(0);
					particles[4][counter_of_particles2][1].push_back(0);
					particles[4][counter_of_particles2][1].push_back(0);
					particles[4][counter_of_particles2][2].push_back(R);
					particles[4][counter_of_particles2][2].push_back(0);
					particles[4][counter_of_particles2][3].push_back(-v0xz * 0.3);
					particles[4][counter_of_particles2][3].push_back(0);
					particles[4][counter_of_particles2][4].push_back(0);
					particles[4][counter_of_particles2][4].push_back(0);
					particles[4][counter_of_particles2][5].push_back(-v0xz * 0.9);
					particles[4][counter_of_particles2][5].push_back(0.10101010101);
					otvet = mfc(particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
					//otvet2 = kfc(particles, particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), 3, counter_of_particles);
					particles[4][counter_of_particles2][6].push_back(((particles[4][counter_of_particles2][4][0] * otvet[2] - particles[4][counter_of_particles2][5][0] * otvet[1]) * 1000000 /* + otvet2[0]*/) * con);
					particles[4][counter_of_particles2][6].push_back(0);
					particles[4][counter_of_particles2][7].push_back(((particles[4][counter_of_particles2][5][0] * otvet[0] - particles[4][counter_of_particles2][3][0] * otvet[2]) * 1000000 /* + otvet2[1]*/) * con);
					particles[4][counter_of_particles2][7].push_back(0);
					particles[4][counter_of_particles2][8].push_back(((particles[4][counter_of_particles2][3][0] * otvet[1] - particles[4][counter_of_particles2][4][0] * otvet[0]) * 1000000 /* + otvet2[2]*/) * con);
					particles[4][counter_of_particles2][8].push_back(0);
					particles[4][counter_of_particles2][9].push_back(t);
					particles[4][counter_of_particles2][9].push_back(0);
					con = con2 * charge[0] / mass[0];
					particles[0][counter_of_particles + counter_of_particles2][0].push_back(0.000001);
					particles[0][counter_of_particles + counter_of_particles2][0].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][1].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][1].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][2].push_back(R);
					particles[0][counter_of_particles + counter_of_particles2][2].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][3].push_back(-v0xz * 0.3);
					particles[0][counter_of_particles + counter_of_particles2][3].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][4].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][4].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][5].push_back(-v0xz * 0.9);
					particles[0][counter_of_particles + counter_of_particles2][5].push_back(0.10101010101);
					otvet = mfc(particles[3][counter_of_particles + counter_of_particles2][0].back(), particles[3][counter_of_particles + counter_of_particles2][1].back(), particles[3][counter_of_particles + counter_of_particles2][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
					//otvet2 = kfc(particles, particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), 3, counter_of_particles);
					particles[0][counter_of_particles + counter_of_particles2][6].push_back(((particles[0][counter_of_particles + counter_of_particles2][4][0] * otvet[2] - particles[0][counter_of_particles + counter_of_particles2][5][0] * otvet[1]) * 1000000 /* + otvet2[0]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][6].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][7].push_back(((particles[0][counter_of_particles + counter_of_particles2][5][0] * otvet[0] - particles[0][counter_of_particles + counter_of_particles2][3][0] * otvet[2]) * 1000000 /* + otvet2[1]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][7].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][8].push_back(((particles[0][counter_of_particles + counter_of_particles2][3][0] * otvet[1] - particles[0][counter_of_particles + counter_of_particles2][4][0] * otvet[0]) * 1000000 /* + otvet2[2]*/) * con);
					particles[0][counter_of_particles + counter_of_particles2][8].push_back(0);
					particles[0][counter_of_particles + counter_of_particles2][9].push_back(t);
					particles[0][counter_of_particles + counter_of_particles2][9].push_back(0);
					counter_of_particles2++;
				}
				por = 0;
			}
		}
		int type = 0;
		while (particles.size() > type) {
			int o = 0;
			if (particles[type][0][0][0] != 0) {
				while (particles[type].size() > o) {
					con = con2 * charge[type] / mass[type];
					if (particles[type][o][5][1] == 0.10101010101) {
						particles[type][o][0][1] = particles[type][o][0][0] + particles[type][o][3][0] * dt + particles[type][o][6][0] * dt * dt / 2;
						particles[type][o][1][1] = particles[type][o][1][0] + particles[type][o][4][0] * dt + particles[type][o][7][0] * dt * dt / 2;
						particles[type][o][2][1] = particles[type][o][2][0] + particles[type][o][5][0] * dt + particles[type][o][8][0] * dt * dt / 2;
						particles[type][o][3][1] = particles[type][o][3][0] + particles[type][o][6][0] * dt;
						particles[type][o][4][1] = particles[type][o][4][0] + particles[type][o][7][0] * dt;
						particles[type][o][5][1] = particles[type][o][5][0] + particles[type][o][8][0] * dt;
						otvet = mfc(particles[type][o][0][1], particles[type][o][1][1], particles[type][o][2][1], wire, wire_vector, wire_sol, wire_vector_sol, t);
						otvet2 = kfc(particles, particles[type][o][0][1], particles[type][o][1][1], particles[type][o][2][1], type, o);
						particles[type][o][6][1] = ((particles[type][o][4][1] * otvet[2] - particles[type][o][5][1] * otvet[1]) * 1000000 + otvet2[0]) * con;
						particles[type][o][7][1] = ((particles[type][o][5][1] * otvet[0] - particles[type][o][3][1] * otvet[2]) * 1000000 + otvet2[1]) * con;
						particles[type][o][8][1] = ((particles[type][o][3][1] * otvet[1] - particles[type][o][4][1] * otvet[0]) * 1000000 + otvet2[2]) * con;
						particles[type][o][9][1] = t;
						o++;
					}
					else {
						particles[type][o][0][0] = particles[type][o][0][1];
						particles[type][o][1][0] = particles[type][o][1][1];
						particles[type][o][2][0] = particles[type][o][2][1];
						particles[type][o][3][0] = particles[type][o][3][1];
						particles[type][o][4][0] = particles[type][o][4][1];
						particles[type][o][5][0] = particles[type][o][5][1];
						particles[type][o][6][0] = particles[type][o][6][1];
						particles[type][o][7][0] = particles[type][o][7][1];
						particles[type][o][8][0] = particles[type][o][8][1];
						particles[type][o][9][0] = particles[type][o][9][1];

						//здесь будет вызов  nf
						particles[type][o][0][1] = particles[type][o][0][0] + particles[type][o][3][0] * dt + particles[type][o][6][0] * dt * dt / 2;
						particles[type][o][1][1] = particles[type][o][1][0] + particles[type][o][4][0] * dt + particles[type][o][7][0] * dt * dt / 2;
						particles[type][o][2][1] = particles[type][o][2][0] + particles[type][o][5][0] * dt + particles[type][o][8][0] * dt * dt / 2;
						particles[type][o][3][1] = particles[type][o][3][0] + particles[type][o][6][0] * dt;
						particles[type][o][4][1] = particles[type][o][4][0] + particles[type][o][7][0] * dt;
						particles[type][o][5][1] = particles[type][o][5][0] + particles[type][o][8][0] * dt;
						otvet = mfc(particles[type][o][0][1], particles[type][o][1][1], particles[type][o][2][1], wire, wire_vector, wire_sol, wire_vector_sol, t);
						otvet2 = kfc(particles, particles[type][o][0][1], particles[type][o][1][1], particles[type][o][2][1], type, o);
						particles[type][o][6][1] = ((particles[type][o][4][1] * otvet[2] - particles[type][o][5][1] * otvet[1]) * 1000000 + otvet2[0]) * con;
						particles[type][o][7][1] = ((particles[type][o][5][1] * otvet[0] - particles[type][o][3][1] * otvet[2]) * 1000000 + otvet2[1]) * con;
						particles[type][o][8][1] = ((particles[type][o][3][1] * otvet[1] - particles[type][o][4][1] * otvet[0]) * 1000000 + otvet2[2]) * con;
						particles[type][o][9][1] = t;
						o++;
					}
				}
				type++;
			}
		}
		t = t + dt;
		tcount++;
		if (tcount % 100 == 0) {
			cout << t << endl;
		}
	}
	fout.close();
	return 0;
}