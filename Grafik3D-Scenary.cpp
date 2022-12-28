#include <glut.h>  //deklarasi library freeglut
#include <math.h> //deklarasi fungsi matematika seperti cos, sin, sqrt, dll.

float xp = 0, yp = 0, r = 10, n = 1000, a, x, y; //deklarasi variabel bertipe data float
// xp dan yp = koordinat pusat x dan y
// r = jari-jari lingkaran
// n = banyak segi
// a = nilai 6.28 dibagi banyak segi
int g, h, p, q, k, l = 0; //deklarasi variabel untuk menggeser objek dengan tipe data integer

void init() { //fungsi awal
	glClearColor(0, 50, 50, 0); //membersihkan layar background menjadi warna biru
	gluOrtho2D(-100, 100, -150, 100); //ukuran kuadran yang digunakan (-x, x, -y, y)
}

void lingkaran() { //fungsi lingkaran
	glBegin(GL_POLYGON); //membuat titik dengan segibanyak 
	a = 6.28 / n; 
	for (int i = 0; i < n; i++) {
		x = xp + r * cos(i * a);
		y = yp + r * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();
}

void roda() { //fungsi roda atau ban pada kendaraan yang digunakan
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = xp + r / 5 * cos(i * a);
		y = yp + r / 5 * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();
}

void awan() { //fungsi menggambar awan 
	glColor3ub(245, 245, 245); 
	glPushMatrix(); //mengembalikan titik tengah posisi koordinat
	glTranslatef(-88, 75, 0); //mentranslasikan atau menggeser posisi objek sebanyak koordinat yang diminta
	lingkaran(); //memanggil fungsi lingkaran
	glPopMatrix(); //penutup dari glPushMatrix();

	glPushMatrix();
	glTranslatef(-78, 83, 0);
	lingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-76, 68, 0);
	lingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-67, 75, 0);
	lingkaran();
	glPopMatrix();
}

void pohon() { //fungsi menggambar pohon
	//batang dari pohon
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(13, 20);
	glVertex2i(17, 20);
	glVertex2i(17, 10);
	glVertex2i(13, 10);
	glEnd();
	//daun bawah
	glBegin(GL_POLYGON);
	glColor3ub(19, 100, 0);
	glVertex2i(5, 20);
	glVertex2i(25, 20);
	glVertex2i(15, 45);
	glEnd();
	//daun atas
	glBegin(GL_POLYGON);
	glColor3ub(19, 100, 0);
	glVertex2i(7, 35);
	glVertex2i(23, 35);
	glColor3ub(107, 142, 35);
	glVertex2i(15, 60);
	glEnd();
}

void sun() { //fungsi menggambar matahari
	glColor3ub(255, 255, 0);
	//lingkaran matahari
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = xp+80 + r * cos(i * a);
		y = yp+80 + r * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();

	//membuat garis disekitaran matahari
	glLineWidth(2); 
	glBegin(GL_LINES);
	glVertex2i(80, 99);
	glVertex2i(80, 92);
	glVertex2i(66, 98);
	glVertex2i(70, 92);
	glVertex2i(94, 98);
	glVertex2i(90, 92);

	glVertex2i(91, 80);
	glVertex2i(96, 80);
	glVertex2i(63, 80);
	glVertex2i(68, 80);

	glVertex2i(71, 67);
	glVertex2i(67, 62);
	glVertex2i(80, 68);
	glVertex2i(80, 60);
	glVertex2i(89, 67);
	glVertex2i(93, 62);
	glEnd();
}

void kapal() { //fungsi menggambar kapal
	glBegin(GL_POLYGON); //badan kapal
	glColor3ub(139, 5, 0);
	glVertex2i(-45, -8);
	glVertex2i(-40, -25);
	glVertex2i(-10, -25);
	glVertex2i(-5, -8);
	glEnd();

	glBegin(GL_POLYGON); //atap kapal
	glColor3ub(0, 0, 0);
	glVertex2i(-40, 8);
	glVertex2i(-40, -8);
	glVertex2i(-10, -8);
	glVertex2i(-15, 8);
	glEnd();

	//jendela kapal menggunakan titik dengan ukuran 12 dan warna putih
	glPointSize(12);
	glBegin(GL_POINTS);
	glColor3ub(255, 255, 255);
	glVertex2i(-37, 0);
	glVertex2i(-32, 0);
	glVertex2i(-27, 0);
	glVertex2i(-22, 0);
	glVertex2i(-17, 0);
	glEnd();
}

void gunungk() { //fungsi menggambar gunung besar dengan membuat gradasi warna
	glBegin(GL_POLYGON);
	glColor3ub(210, 105, 30);
	glVertex2i(0, 0);
	glVertex2i(50, 50);
	glColor3ub(150, 75, 0);
	glVertex2i(100, 0);
	glEnd();
}

void gunungb() { //fungsi menggambar gunung kecil dengan membuat gradasi warna
	glBegin(GL_POLYGON);
	glColor3ub(150, 75, 0);
	glVertex2i(55, 0);
	glVertex2i(0, 80);
	glColor3ub(210, 105, 30);
	glVertex2i(-55, 0);
	glEnd();
}

void danau() { //fungsi menggambar danau dengan membuat gradasi warna
	glBegin(GL_POLYGON);
	glColor3ub(135, 206, 235);
	glVertex2i(-100, 0);
	glColor3ub(43, 191, 254);
	glVertex2i(-100, -50);
	glColor3ub(135, 206, 235);
	glVertex2i(100, -50);
	glColor3ub(43, 191, 254);
	glVertex2i(100, 0);
	glEnd();
}

void jalan() { //fungsi menggambar aspal dijalan
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -50);
	glVertex2i(-100, -90);
	glVertex2i(100, -90);
	glVertex2i(100, -50);
	glEnd();
}

void marka() { //fungsi menggambar marka jalan atau garis putus-putus di aspal
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -67);
	glVertex2i(-100, -73);
	glVertex2i(-70, -73);
	glVertex2i(-70, -67);
	glEnd();
}

void rumput() { //fungsi menggambar rumput di jalan
	glBegin(GL_POLYGON);
	glColor3ub(107, 142, 35);
	glVertex2i(-100, -50);
	glVertex2i(100, -50);
	glColor3ub(19, 100, 0);
	glVertex2i(100, -150);
	glVertex2i(-100, -150);
	glEnd();
}

void gubuk() { //fungi menggambar gubuk
	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(139, 69, 19);
	glVertex2f(41, -115);
	glVertex2f(41, -150);
	glVertex2f(44, -115);
	glVertex2f(44, -150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19);
	glVertex2i(41, -140);
	glVertex2i(59, -140);
	glColor3ub(139, 5, 0);
	glVertex2i(62, -135);
	glVertex2i(44, -135);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(139, 69, 19);
	glVertex2f(59, -115);
	glVertex2f(59, -150);
	glVertex2f(62, -108);
	glVertex2f(62, -150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19);
	glVertex2i(50, -100);
	glVertex2i(40, -115);
	glColor3ub(139, 5, 0);
	glVertex2i(60, -115);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19);
	glVertex2i(50, -100);
	glVertex2i(60, -115);
	glColor3ub(139, 5, 0);
	glVertex2i(63, -107);
	glEnd();

	glLineWidth(3); //membuat titik titik hingga membentuk garis untuk mempercantik gubuk
	glColor3ub(210, 105, 30);
	glBegin(GL_LINES);
	glVertex2f(50, -100);
	glVertex2f(60, -115);
	glVertex2f(50, -100);
	glVertex2f(40, -115);
	glVertex2f(50, -100);
	glVertex2f(63, -107);
	glEnd();
}

void sawah() {
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(34, 139, 35);
	glVertex2f(20, -99);
	glColor3ub(173, 255, 48);
	glVertex2f(20, -103);
	glColor3ub(34, 139, 35);
	glVertex2f(18, -100);
	glColor3ub(173, 255, 48);
	glVertex2f(20, -103);
	glColor3ub(34, 139, 35);
	glVertex2f(22, -100);
	glColor3ub(173, 255, 48);
	glVertex2f(20, -103);
	glEnd();
}

void mobil() { //fungsi menggambar mobil
	//untuk lampu di depan mobil
	glPushMatrix();
	glColor3ub(252, 192, 203);
	glTranslatef(32, -69, 0);
	roda();
	glPopMatrix();

	//atap mobil
	glBegin(GL_POLYGON);
	glColor3ub(219, 112, 147);
	glVertex2f(34, -66);
	glVertex2f(42, -55);
	glColor3ub(252, 192, 203);
	glVertex2f(60, -55);
	glVertex2f(66, -66);
	glEnd();

	//badan mobil
	glBegin(GL_POLYGON);
	glColor3ub(252, 192, 203);
	glVertex2f(66, -66);
	glColor3ub(219, 112, 147);
	glVertex2f(32, -66);
	glVertex2f(32, -77);
	glVertex2f(66, -77);
	glEnd();

	//kaca pertama
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2f(43, -57);
	glVertex2f(45, -57);
	glVertex2f(45, -64);
	glVertex2f(38, -64);
	glEnd();

	//kaca kedua
	glBegin(GL_POLYGON);
	glVertex2f(47, -57);
	glVertex2f(55, -57);
	glVertex2f(55, -64);
	glVertex2f(47, -64);
	glEnd();

	//kaca ketiga
	glBegin(GL_POLYGON);
	glVertex2f(57, -57);
	glVertex2f(59, -57);
	glVertex2f(63, -64);
	glVertex2f(57, -64);
	glEnd();

	//pegangan pintu belakang
	glLineWidth(2); //ukuran garis nya
	glColor3ub(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP); //membuat titik-titik
	glVertex2f(47, -68);
	glVertex2f(47, -70);
	glVertex2f(49, -70);
	glVertex2f(49, -68);
	glVertex2f(47, -68);
	glEnd();

	//pegangan pintu depan
	glLineWidth(2);
	glColor3ub(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(43, -68);
	glVertex2f(43, -70);
	glVertex2f(45, -70);
	glVertex2f(45, -68);
	glVertex2f(43, -68);
	glEnd();

	//ban mobil depan
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = (xp+40) + r/3 * cos(i * a);
		y = (yp-78) + r/3 * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();

	//ban mobil belakang
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = (xp+58) + r/3 * cos(i * a);
		y = (yp-78) + r/3 * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();
}

void truk() { //fungsi menggambar truk sawah
	glBegin(GL_POLYGON);
	glColor3ub(251, 127, 80);
	glVertex2f(-70, -110);
	glVertex2f(-70, -130);
	glVertex2f(-63, -130);
	glVertex2f(-63, -110);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(251, 127, 80);
	glVertex2f(-63, -110);
	glVertex2f(-63, -130);
	glVertex2f(-59, -130);
	glVertex2f(-59, -110);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-63, -110);
	glVertex2f(-63, -118);
	glVertex2f(-59, -118);
	glVertex2f(-59, -110);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-59, -110);
	glVertex2f(-55, -110);
	glVertex2f(-55, -118);
	glVertex2f(-59, -118);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(251, 140, 0);
	glVertex2f(-59, -118);
	glVertex2f(-50, -118);
	glVertex2f(-50, -130);
	glVertex2f(-59, -130);
	glEnd();

	glLineWidth(2); //membuat titik titik hingga membentuk garis untuk mempercantik truk
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-70, -110);
	glVertex2f(-70, -130);
	glVertex2f(-63, -110);
	glVertex2f(-63, -130);
	glVertex2f(-59, -110);
	glVertex2f(-59, -130);
	glVertex2f(-55, -110);
	glVertex2f(-55, -118);
	glVertex2f(-50, -118);
	glVertex2f(-50, -130);
	glVertex2f(-59, -118);
	glVertex2f(-50, -118);
	glVertex2f(-70, -110);
	glVertex2f(-55, -110);
	glVertex2f(-70, -130);
	glVertex2f(-50, -130);
	glEnd();

	glLineWidth(2);
	glColor3ub(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-59, -121);
	glVertex2f(-61, -121);
	glVertex2f(-61, -125);
	glVertex2f(-59, -125);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = (xp-65) + r/2.5 * cos(i * a);
		y = (yp-134) + r/2.5 * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = (xp-55) + r/2.5 * cos(i * a);
		y = (yp-134) + r/2.5 * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();

	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef(-65, -134, 0);
	roda();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-55, -134, 0);
	roda();
	glPopMatrix();
}

void display() //fungsi memanggil objek untuk ditampilkan
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ////membersihkan layar backround menjadi warna hitam
	
	//memanggil fungsi awan
	awan();
	glPushMatrix();
	glTranslatef(85, 0, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(70, 0, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(175, 3, 0);
	awan();
	glPopMatrix();
	
	sun(); //memanggil fungsi matahari
	gunungk(); //memanggil fungsi gunung kecil
	gunungb(); //memanggil fungsi gunung besar

	glPushMatrix(); 
	glTranslatef(-100, 0, 0); 
	gunungk(); //memanggil fungsi kunung kecil ditranslate kekiri
	glPopMatrix();

	rumput(); //memanggil fungsi rumput
	jalan(); //memanggilfungsi jalan aspal
	//melakukan perulangan untuk memanggil fungsi marka atau garis putus-putus di aspal
	for (float i = -100; i < 300; i += 40) { 
		glPushMatrix();
		glTranslatef(i, 0, 0);
		marka();
		glPopMatrix();
		glEnd();
	}
	danau(); //memanggil fungsi danau

	glPushMatrix(); 
	glTranslatef(g, h, 0); //membuat variabel di translate untuk dipanggil di fungsi keyboard
	truk(); //memanggil fungsi truk sawah 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p, q, 0); //membuat variabel di translate untuk dipanggil di fungsi mouse
	mobil(); //memanggil fungsi mobil
	glPopMatrix();

	//melakukan perulangan untuk memanggil fungsi pohon 
	for (float i = -105; i < 105; i += 10) {
		glPushMatrix();
		glTranslatef(i, -5, 0); //ditranslasikan kedalam variabel i
		glScalef(-0.5, -0.5, 0); //diperkecil objek x,y sebanyak setengah
		glRotatef(180, 0, 0, 1.0); //dirotasikan objek ke 180 derajat agar posisi seperti semula
		pohon(); //memangggil fungsi pohon
		glPopMatrix();
		glEnd();
	}

	//melakukan perulangan untuk memanggil fungsi sawah
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -5, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -10, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -15, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -20, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -25, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -30, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -35, 0);
		sawah();
		glPopMatrix();
	}
	for (float i = -10; i < 40; i += 5) {
		glPushMatrix();
		glTranslatef(i, -40, 0);
		sawah();
		glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(k, l, 0); //membuat variabel di translate untuk dipanggil di fungsi keyboard
	kapal(); //memanggil fungsi kapal
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 0, 0);
	gubuk(); //memanggil fungsi gubuk di translate kan ke kanan
	glPopMatrix();

	glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y) { //fungsi keyboard untuk menggerakkan truk sawah
	switch (key)
	{
	case 13: //menggunakan ASCII 13 untuk exit
		exit(0);
		break;
	case 'w': //menggunakan huruf W/w di keyboard untuk ke kiri
	case 'W':
		if (h <= 0)
		h += 10;
		break;
	case 'a': //menggunakan huruf A/a di keyboard untuk mundur
	case 'A':
		g -= 10;
		break;
	case 's': //menggunakan huruf S/s di keyboard untuk ke kanan
	case 'S':
		h -= 10;
		break;
	case 'd': //menggunakan huruf D/d di keyboard untuk maju
	case 'D':
		g += 10;
		break;
	}
	glutPostRedisplay();
}

void specialKey(int key, int x, int y) //fungsi special key untuk menggerakkan kapal
{
	switch (key)
	{
	case GLUT_KEY_UP: //panah atas di keyboard untuk ke kiri
		if (l <= 10)
		l += 5;
		break;
	case GLUT_KEY_LEFT: //panah kiri di keyboard untuk mundur
		k -= 5;
		break;
	case GLUT_KEY_DOWN: //panah bawah di keyboard untuk ke kanan
		if (l >= -15)
		l -= 5;
		break;
	case GLUT_KEY_RIGHT: //panah kanan di keyboard untuk maju
		k += 5;
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int xmouse, int ymouse) { //fungsi mouse untuk menggerakkan mobil
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)  //jika tombol/klik kiri di pencet di mouse
		p -= 10;										   //maka akan maju mobilnya bergerak ke arah koordinat negatif
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //jika tombol/klik kanan di pencet di mouse
		p += 10;										   //maka akan mundur mobilnya ke arah koordinat positif
	glutPostRedisplay();
}

int main(int argc, char* argv[]) //fungsi main untuk nge run
{
	glutInit(&__argc, __argv); //menginisialisasi glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //mengaktifkan mode bugger ganda
	glutInitWindowPosition(10, 10); //posisi window di layar komputer anda
	glutInitWindowSize(1000, 600); //ukuran window di layar komputer anda
	glutCreateWindow("UTS - Rhisa Adika Putri (191401119)"); //judul window
	init(); //memanggil fungsi init
	glutDisplayFunc(display); //memanggil dan menginisialisasi fungsi display
	glutKeyboardFunc(myKeyboard); //memanggil dan menginisialisasi fungsi keyboard
	glutSpecialFunc(specialKey); //memanggil dan menginisialisasi fungsi special keyboard
	glutMouseFunc(mouse); //memanggil dan menginisialisasi fungsi mouse
	glutMainLoop(); //melakukan perulangan terus ketika layar dijalankan atau di run
	return EXIT_SUCCESS;
}