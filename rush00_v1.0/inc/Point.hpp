#ifndef POINT_HPP
#define POINT_HPP


class Point {
public:
    Point();
    Point(int x, int y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    void addX(int value);
    void addY(int value);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    Point operator+(const Point& other);
    Point operator-(const Point& other);
    bool operator==(const Point& other);
    bool operator!=(const Point& other);

private:
    int x;
    int y;
};


#endif //POINT_HPP
