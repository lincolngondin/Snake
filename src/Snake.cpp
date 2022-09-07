#include "Snake.h"
Snake::Snake(){
    this->body = new Point2d[this->maxSize];
    this->pos = {10, 10};
    this->dir = {0, 1};
}
Snake::~Snake(){
    delete[] this->body;
}

void Snake::grow(){
    this->size++;
    if(this->size == this->maxSize){
        Point2d* temp = new Point2d[this->maxSize+this->tamanhoAumento];
        for(int i = 0; i < this->maxSize; i++){
            *(temp + i) = *(this->body + i);
        }
        this->maxSize += this->tamanhoAumento;
        delete[] this->body;
        this->body = temp;
    }
    this->body[this->size] = {this->pos.x, this->pos.y};
}

void Snake::updateSnake(){
    Point2d posAtual = this->pos;
    Point2d posAnterior;
    this->pos.x += this->dir.x;
    this->pos.y += this->dir.y;
    for(int i = 0; i < this->size; i++){
        posAnterior = this->body[i];
        this->body[i] = posAtual;
        posAtual = posAnterior;
    }
}