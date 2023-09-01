#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
//#include <onnx_runtime>
//#include "PID.h"
#include <chrono>
using namespace cv;
using namespace std;
int main() {
    Mat src = imread("/home/heygears/CLionProject/ALL/1.png", IMREAD_REDUCED_COLOR_4);
    if(src.empty()){
        cout << "src is empty" << endl;
        return 0;
    }
    imshow("1", src);
    waitKey();
    return 0;
}
