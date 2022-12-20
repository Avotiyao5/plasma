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
// это трёхмерный массив, штука достаточно сложная для понимания
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
				sol = 0;
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
			//fout << x << " " << y << " " << z << endl;
			if (sol == 0) {
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
			//fout << x << " " << y << " " << z << endl; //всё выводим
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
	/*
	for (double t = 0; t < 30; t = t + 0.01) {
		otvet = mfc(0, 0, t, wire, wire_vector);
		fout << otvet[0] << " " << t << endl;
	}

	for (int c = 0; c < wire[0].size(); c++) {          // Это проверка что координаты кусочков провода правильно записываются...
		b = 0;
		while (b <= 5) {
			if (b == 2) {
				cout << wire[b][c] << "    ";
			}
			else if (b == 5) {
				cout << wire[b][c] << endl;
			}
			else {
				cout << wire[b][c] << " ,";
			}
			b++;
		}
	}
	*/
	long double t = 0;
	int counter_of_particles = 0;
	long double v0xz = 1000000;
	long double dt = 1 * pow(10, -13);											// 1 * pow(10, -22)
	long double dt2 = 5 * pow(10, -10);
	long double con = 1.6021766208 * pow(10, 2) / 3.343583772441013523817;
	int tcount = 0, i = 0;
	particles[3].resize(2, pusb);
	while (t <  10* pow(10, -8)) {
			i++;
			if (i == dt2/dt) {
				if (counter_of_particles < 2) {
					i = 0;
					particles[3][counter_of_particles][0].push_back(0);
					particles[3][counter_of_particles][1].push_back(0);
					particles[3][counter_of_particles][2].push_back(R);
					particles[3][counter_of_particles][3].push_back(-v0xz * 0.3);
					particles[3][counter_of_particles][4].push_back(0);
					particles[3][counter_of_particles][5].push_back(-v0xz * 0.9);
					otvet = mfc(particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
					//otvet2 = kfc(particles, particles[3][counter_of_particles][0].back(), particles[3][counter_of_particles][1].back(), particles[3][counter_of_particles][2].back(), 3, counter_of_particles);
					particles[3][counter_of_particles][6].push_back(((particles[3][counter_of_particles][4].back() * otvet[2] - particles[3][counter_of_particles][5].back() * otvet[1]) * 1000000 /* + otvet2[0]*/) * con);
					particles[3][counter_of_particles][7].push_back(((particles[3][counter_of_particles][5].back() * otvet[0] - particles[3][counter_of_particles][3].back() * otvet[2]) * 1000000 /* + otvet2[1]*/) * con);
					particles[3][counter_of_particles][8].push_back(((particles[3][counter_of_particles][3].back() * otvet[1] - particles[3][counter_of_particles][4].back() * otvet[0]) * 1000000 /*+ otvet2[2]*/) * con);
					particles[3][counter_of_particles][9].push_back(t);
					counter_of_particles++;
				}
			}
		/*
		else if (counter_of_particles < 0) {
			i = 0;
			tritium.resize(0);
			tritium[counter_of_particles - 20][0].push_back(0);
			tritium[counter_of_particles - 20][0].push_back(0);
			tritium[counter_of_particles - 20][0].push_back(18.9);
			tritium[counter_of_particles - 20][3].push_back(-v0xz);
			tritium[counter_of_particles - 20][4].push_back(0);
			tritium[counter_of_particles - 20][5].push_back(-v0xz);
			otvet = mfc(tritium[counter_of_particles -20][0].back(), tritium[counter_of_particles][1].back(), tritium[counter_of_particles-20][2].back(), wire);
			tritium[counter_of_particles - 20][6].push_back((tritium[counter_of_particles-20][4].back()* otvet[2] - tritium[counter_of_particles-20][5].back() * otvet[1]) * 1 / 5.008271070802 / pow(10, -27));
			tritium[counter_of_particles - 20][7].push_back((tritium[counter_of_particles-20][5].back()* otvet[0] - tritium[counter_of_particles-20][3].back() * otvet[2]) * 1 / 5.008271070802 / pow(10, -27));
			tritium[counter_of_particles - 20][8].push_back((tritium[counter_of_particles-20][3].back()* otvet[1] - tritium[counter_of_particles-20][4].back() * otvet[0]) * 1 / 5.008271070802 / pow(10, -27));
			tritium[counter_of_particles - 20][9].push_back(t);
			counter_of_particles++;
		}
		*/
		if (particles[3][0][0].size() > 0) {
			int o = 0;
			while (counter_of_particles > o) {
				particles[3][o][0].push_back(particles[3][o][0].back() + particles[3][o][3].back() * dt + particles[3][o][6].back() * dt * dt / 2);
				particles[3][o][1].push_back(particles[3][o][1].back() + particles[3][o][4].back() * dt + particles[3][o][7].back() * dt * dt / 2);
				particles[3][o][2].push_back(particles[3][o][2].back() + particles[3][o][5].back() * dt + particles[3][o][8].back() * dt * dt / 2);
				particles[3][o][3].push_back(particles[3][o][3].back() + particles[3][o][6].back() * dt);
				particles[3][o][4].push_back(particles[3][o][4].back() + particles[3][o][7].back() * dt);
				particles[3][o][5].push_back(particles[3][o][5].back() + particles[3][o][8].back() * dt);
				otvet = mfc(particles[3][o][0].back(), particles[3][o][1].back(), particles[3][o][2].back(), wire, wire_vector, wire_sol, wire_vector_sol, t);
				//otvet2 = kfc(particles, particles[3][o][0].back(), particles[3][o][1].back(), particles[3][o][2].back(), 3, o);
				particles[3][o][6].push_back((particles[3][o][4].back() * otvet[2] - particles[3][o][5].back() * otvet[1]) * 1000000 /* + otvet2[0])*/ * con);
				particles[3][o][7].push_back((particles[3][o][5].back() * otvet[0] - particles[3][o][3].back() * otvet[2]) * 1000000 /*+ otvet2[1])*/ * con);
				particles[3][o][8].push_back((particles[3][o][3].back() * otvet[1] - particles[3][o][4].back() * otvet[0]) * 1000000 /*+ otvet2[2])*/ * con);
				particles[3][o][9].push_back(t);
				o++;
			}
		}
		/*
		if (tritium[0][0].size() > 0) {
			for (int o = 0; o < tritium.size(); o++) {
				tritium[o][0].push_back(tritium[o][0].back() + tritium[o][3].back() * dt + tritium[o][6].back() * dt * dt / 2);
				tritium[o][1].push_back(tritium[o][1].back() + tritium[o][4].back() * dt + tritium[o][7].back() * dt * dt / 2);
				tritium[o][2].push_back(tritium[o][2].back() + tritium[o][5].back() * dt + tritium[o][8].back() * dt * dt / 2);
				tritium[o][3].push_back(tritium[o][3].back() + tritium[o][6].back() * dt);
				tritium[o][4].push_back(tritium[o][4].back() + tritium[o][7].back() * dt);
				tritium[o][5].push_back(tritium[o][5].back() + tritium[o][8].back() * dt);
				otvet = mfc(tritium[o][0].back(), tritium[o][1].back(), tritium[o][2].back(), wire);
				tritium[o][6].push_back((tritium[o][4].back() * otvet[2] - tritium[o][5].back() * otvet[1]) * 1 / 5.008271070802 / pow(10, -27));
				tritium[o][7].push_back((tritium[o][5].back() * otvet[0] - tritium[o][3].back() * otvet[2]) * 1 / 5.008271070802 / pow(10, -27));
				tritium[o][8].push_back((tritium[o][3].back() * otvet[1] - tritium[o][4].back() * otvet[0]) * 1 / 5.008271070802 / pow(10, -27));
				tritium[o][9].push_back(t);
			}
		}
		*/

		t = t + dt;
		tcount++;
		if (tcount % 100 == 0) {
			cout << t << endl;
		}
	}
	for (int a = 0; a < particles[3].size(); a++) {
		for (int b = 0; b < particles[3][a][0].size(); b++) {
			if (b > 0) {
				if (abs(particles[3][a][0][b]) > 19.1 || (abs(particles[3][a][1][b])) > 6.5 || (abs(particles[3][a][2][b])) > 19.1) {
					//cout << deuterium[a][0][b - 1] << " " << deuterium[a][1][b - 1] << " " << deuterium[a][2][b - 1] << " " << deuterium[a][3][b - 1] << " " << deuterium[a][4][b - 1] << " " << deuterium[a][5][b - 1] << " " << deuterium[a][6][b - 1] << " " << deuterium[a][7][b - 1] << " " << deuterium[a][8][b - 1] << " " << deuterium[a][9][b - 1] << endl;
				}
			}
				//cout << deuterium[a][0][b] << " " << deuterium[a][1][b] << " " << deuterium[a][2][b] << " " << deuterium[a][3][b] << " " << deuterium[a][4][b] << " " << deuterium[a][5][b] << " " << deuterium[a][6][b] << " " << deuterium[a][7][b] << " " << deuterium[a][8][b] << " " << deuterium[a][9][b] << endl;
				fout << particles[3][a][0][b] << " " << particles[3][a][1][b] << " " << particles[3][a][2][b] << endl;
		}
		fout << endl << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	fout.close();
	return 0;
}