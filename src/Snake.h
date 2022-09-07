
#ifndef _SNAKE_H_
#define _SNAKE_H_

struct Point2d{
    int x = 0, y = 0;
};

class Snake{
    private:
        int maxSize = 10;
        int tamanhoAumento = 5;
    public:
        Point2d pos;
        Point2d dir;
        Point2d* body = nullptr;
        int size = 0;
    public:
        Snake();
        ~Snake();
        void grow();
        void updateSnake();
};

#endif