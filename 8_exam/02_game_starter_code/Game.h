#ifndef GAME_H
#define GAME_H

#include <opencv2/opencv.hpp>
#include <string>

class Game {
public:
    Game(const std::string& cascadePath);
    ~Game();
    bool initialize();
    void run();
private:
    cv::VideoCapture cap;
    cv::CascadeClassifier faceCascade;
    const std::string windowName = "Face Detection";
    int frameWidth;
    int frameHeight;
};

#endif // GAME_H
