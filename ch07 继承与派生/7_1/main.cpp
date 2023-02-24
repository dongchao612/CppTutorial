#include<iostream>

using namespace std;

class Point
{
public:
	void initPoint(float x = 0, float y = 0) {
		this->x = x;
		this->y = y;
	}
	void move(float offx, float offy) {
		this->x += offx;
		this->y += offy;
	}
	float getX() const {
		return x;
	}
	float getY()const {
		return y;
	}

private:
	float x, y;
};
class Rectangle :public Point
{
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);
		this->w = w;
		this->h = h;
	}
	float getH() const {
		return h;
	}
	float getW()const {
		return w;
	}
private:
	float w, h;
};
int main()
{
	Rectangle rect;
	rect.initRectangle(2, 3, 20, 10);
	rect.move(3, 2);
	cout << "The data of rect is :\n" << rect.getX() << ", " << rect.getY() << ", " << rect.getH() << ", " << rect.getW() << endl;
	return 0;
}