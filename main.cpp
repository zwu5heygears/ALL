#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
//#include <onnx_runtime>
//#include "PID.h"
#include <chrono>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/thread.hpp>

using namespace cv;
using namespace std;

void ShowMat(){
    Mat src = imread("/home/heygears/CLionProject/ALL/1.png", IMREAD_REDUCED_COLOR_4);
    if(src.empty()){
        cout << "src is empty" << endl;
    }
    imshow("0", src);
    waitKey();
}
int main() {
    boost::asio::thread_pool mPool(2);
    boost::asio::post(mPool, ShowMat);
    boost::asio::post(mPool, ShowMat);
    ShowMat();

    auto time = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(time);
    auto tm_now = localtime(&time_t);
    cout << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << endl;
    stringstream ss;
    ss << put_time(tm_now, "%Y-%m-%d %H:%M:%S");
    string timestr = ss.str();
    cout << timestr << endl;
    return 0;
}
