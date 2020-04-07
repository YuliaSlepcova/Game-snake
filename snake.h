#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>

class Snake : public QWidget
{
public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    QImage dot;
    QImage head;
    QImage apple;

    static const int B_WIDTH    = 300;  //< size playground
    static const int B_HEIGHT   = 300;
    static const int DOT_SIZE   = 10;   //< size apple and snake parts
    static const int ALL_DOTS   = (B_WIDTH*B_HEIGHT) / (DOT_SIZE*DOT_SIZE);
    static const int RAND_POS   = 29;   //< for random
    static const int DELAY      = 140;  //< game speed

    int timerId;
    int dots;
    int apple_x;
    int apple_y;

    int x[ALL_DOTS];    //< position oll parts snake
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);
};
#endif // SNAKE_H
