#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int x, int y) : x(x), y(y) {}

    int getX() const {return x;}
    void setX(int x) {Point::x = x;}
    int getY() const {return y;}
    void setY(int y) {Point::y = y;}
    void print(){
        cout<< "( "<< this->x <<" : " << this->y << " )" <<endl;
    }
    friend Point operator+(Point p1 ,Point p2);
    Point operator=(Point p2);
    Point operator++(); // pre--increment // todo ++i
    Point operator++(int); // post--increment // todo i++
    Point operator+=(Point p1);
    friend bool operator==(Point p1 , Point P2);
    friend bool operator>(Point p1 , Point p2);
};
//Point Point::operator+(Point p2) {
//    Point temp;
//    temp.x = this->x + p2.x;
//    temp.y = this->y + p2.y;
//    return temp;
//}
Point operator+(Point p1 , Point p2){
    Point temp;
    temp.x = p1.x + p2.x;
    temp.y = p1.y + p2.y;
    return  temp;
}
Point Point::operator=(Point p2) {
       this->x = p2.x;
       this->y = p2.y;
    return *this;
}
// todo pre--increment
Point Point::operator++(){
    this->x++;
    this->y++;
    return *this;
}
// todo post--increment
Point Point::operator++(int){
    Point temp = *this;
    this->x++;
    this->y++;
    return temp;
}
Point Point::operator+=(Point p1){
    this->x = this->x + p1.x;
    this->y += p1.y;
    return *this;
}
bool  operator==(Point p1 , Point p2){
    return (p1.x == p2.x && p1.y == p2.y);
}
bool  operator>(Point p1 , Point p2){
    return ((p1.x * p1.x + p1.y * p1.y) > (p2.x * p2.x + p2.y * p2.y));

}
int main() {
    Point p1(2,2);
    Point p2(1,2);
    if(p1 > p2)
        cout<<"p1 is bigger"<<endl;
    else
        cout<<"p2 is bigger or equal"<< endl;

    cin.get();
    return 0;
}