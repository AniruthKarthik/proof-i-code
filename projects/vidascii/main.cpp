#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

const std::string asciis = "@%#*=-:. ";

void print_ascii_frame(const cv::Mat &frame) {
    std::ios::sync_with_stdio(false);
    // 2 matrices gray and small 
    cv::Mat gray, small;
    
    // convert rgb to grayscale
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    int new_width = 600;
    int new_height = (gray.rows * new_width * 0.55) / gray.cols;

    cv::resize(gray, small, cv::Size(new_width, new_height));

    std::string output = "";

    for (int i = 0; i < small.rows; i++) {
        for (int j = 0; j < small.cols; ++j) {
            // access the pixel at i,j
            uchar pixel = small.at<uchar>(i, j);

            // maps the brightness to a character index 
            int index = (pixel * asciis.length()) / 256;

            output += asciis[index];
        }
        output += "\n";
    }

    // clears the screen and moves the cursor to the top left corner
    std::cout << "\033[H";

    std::cout << output << std::flush;

    usleep(33000);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << " usage: ./ascii_player <video_file>" << std::endl;
        return -1;
    }

    cv::VideoCapture cap(argv[1]);

    if (!cap.isOpened()) {
        std::cerr << "error opening the video" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (cap.read(frame)) {
        print_ascii_frame(frame);
    }

    return 0;
}
