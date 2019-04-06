#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {
    Mat frame;
    VideoCapture camera;
    camera.open(0);
    
    if (!camera.isOpened()) {
        cerr << "Unable to open camera\n";
        return -1;
    }
    
    for (;;) {
        camera.read(frame);
        if (frame.empty()) {
            cerr << "Blank frame grabbed :(\n";
            break;
        }
        imshow("ttcv", frame);
        if (waitKey(5) >= 0) {
            break;
        }
    }
    return 0;
}
