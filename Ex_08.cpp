#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Solid {
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Box :Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(
		double width,
		double height,
		double depth
	) :Solid() {
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetWidth() {
		return width;
	}
	double GetHeight() {
		return height;
	}
	double GetDepth() {
		return depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height + height * depth + depth * width) * 2;
	}
};
class Cylinder :Solid {
private:
	double radius;
	double height;

public:
	Cylinder(
		double radius,
		double height
	) :Solid() {

		this->radius = radius;
		this->height = height;
	}
	double GetRadius() {
		return radius;
	}
	double Getheight() {
		return height;
	}
	double GetVolume() {
		return M_PI * radius * radius * height;
	}
	double GetSurface() {
		return 2 * M_PI * radius * (height + radius);
	}
};
class Cone :Solid {
private:
	double radius;
	double height;

public:
	Cone(
		double radius,
		double height
	) :Solid() {
		this->radius = radius;
		this->height = height;
	}
	double GetRadius() {
		return radius;
	}
	double Getheight() {
		return height;
	}
	double GetVolume() {
		return M_PI * radius * radius * height / 3;
	}
	double GetSurface() {
		double L = radius * radius + height * height;
		return M_PI * radius * (sqrt(L) + radius);
	}
};
class Sphere :Solid {
private:
	double radius;

public:
	Sphere(
		double radius
	) :Solid() {
		this->radius = radius;
	}
	double GetRadius() {
		return radius;
	}
	double GetVolume() {
		return 4 / 3 * M_PI * radius * radius;
	}
	double GetSurface() {
		return 4 * M_PI * radius * radius;
	}
};
void DisplayVolumeSurface(Solid* solid) {
	cout << "�̐�=" << solid->GetVolume() << endl;
	cout << "�\�ʐ�=" << solid->GetSurface() << endl;
}
int main()
{
	Box box{ 3,5,2.5 };
	Cylinder cylinder{ 3,5 };
	Cone cone{ 3,5 };
	Sphere sphere{ 3 };
	const int Nunber = 4;
	Solid* solid[Nunber] = { &box, &cylinder,&cone,&sphere };
	for (int i = 0; i < Nunber; i++) {
		DisplayVolumeSurface(solid[i]);
	}
	int kuroSize[] = { 60,80,100,120,140,160,180,200 };
	int jppostSize[] = { 60,80,100,120,140,160,170 };
	int i;
	double length;

	length = box.GetWidth() + box.GetHeight() + box.GetDepth();

	for (i = 0; i < _countof(kuroSize); i++) {
		if (length <= kuroSize[i]) {
			break;
		}
	}
	for (i = 0; i < _countof(jppostSize); i++) {
		if (length <= jppostSize[i]) {
			break;
		}
	}
	if (i < _countof(kuroSize)) {
		cout << "���̃T�C�Y��" << kuroSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�N���l�R���}�g�ő���܂�" << endl;
	}
	else if (!(i < _countof(kuroSize))) {
		cout << "���̔��̓N���l�R���}�g�ł͑���܂���" << endl;
	}
	if (i < _countof(jppostSize)) {
		cout << "���̃T�C�Y��" << jppostSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�䂤�p�b�N�ő���܂�" << endl;
	}
	else if (!(i < _countof(jppostSize))) {
		cout << "���̔��͂䂤�p�b�N�ł͑���܂���" << endl;
	}

	length = cylinder.GetRadius() * 4 + cylinder.GetHeight();
	for (i = 0; i < _countof(kuroSize); i++) {
		if (length <= kuroSize[i]) {
			break;
		}
	}
	for (i = 0; i < _countof(jppostSize); i++) {
		if (length <= jppostSize[i]) {
			break;
		}
	}
	if (i < _countof(kuroSize)) {
		cout << "�~���̃T�C�Y��" << kuroSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�N���l�R���}�g�ő���܂�" << endl;
	}
	else if (!(i < _countof(kuroSize))) {
		cout << "���̉~���̓N���l�R���}�g�ł͑���܂���" << endl;
	}
	if (i < _countof(jppostSize)) {
		cout << "�~���̃T�C�Y��" << jppostSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�䂤�p�b�N�ő���܂�" << endl;
	}
	else if (!(i < _countof(jppostSize))) {
		cout << "���̉~���͂䂤�p�b�N�ł͑���܂���" << endl;
	}
	length = cone.GetRadius() * 4 + cone.GetHeight();
	for (i = 0; i < _countof(kuroSize); i++) {
		if (length <= kuroSize[i]) {
			break;
		}
	}
	for (i = 0; i < _countof(jppostSize); i++) {
		if (length <= jppostSize[i]) {
			break;
		}
	}
	if (i < _countof(kuroSize)) {
		cout << "�~���̃T�C�Y��" << kuroSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�N���l�R���}�g�ő���܂�" << endl;
	}
	else if (!(i < _countof(kuroSize))) {
		cout << "���̉~���̓N���l�R���}�g�ł͑���܂���" << endl;
	}
	if (i < _countof(jppostSize)) {
		cout << "�~���̃T�C�Y��" << jppostSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�䂤�p�b�N�ő���܂�" << endl;
	}
	else if (!(i < _countof(jppostSize))) {
		cout << "���̉~���͂䂤�p�b�N�ł͑���܂���" << endl;
	}

	length = sphere.GetRadius() * 6;
	for (i = 0; i < _countof(kuroSize); i++) {
		if (length <= kuroSize[i]) {
			break;
		}
	}
	for (i = 0; i < _countof(jppostSize); i++) {
		if (length <= jppostSize[i]) {
			break;
		}
	}
	if (i < _countof(kuroSize)) {
		cout << "���̃T�C�Y��" << kuroSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�N���l�R���}�g�ő���܂�" << endl;
	}
	else if (!(i < _countof(kuroSize))) {
		cout << "���̋��̓N���l�R���}�g�ł͑���܂���" << endl;
	}
	if (i < _countof(jppostSize)) {
		cout << "���̃T�C�Y��" << jppostSize[i] << "�T�C�Y�ł�" << endl;
		cout << "�䂤�p�b�N�ő���܂�" << endl;
	}
	else if (!(i < _countof(jppostSize))) {
		cout << "���̋��͂䂤�p�b�N�ł͑���܂���" << endl;
	}

}
