#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat image;
    image = imread("nps_logo.jpg");

    if(image.empty()){
        cout << "Image error";
        return -1;
    }

    Mat smImage;
    resize(image,smImage,Size(),0.2,0.5);
    
    Mat gray;
    cvtColor(smImage,gray,COLOR_BGR2GRAY);
    
    cout << "Before resizing: " << image.rows << 'x' << image.cols << "\n";
    cout << "After resizing: " << smImage.rows << 'x' << smImage.cols << "\n";
    cout << "Gray: " << gray.rows << 'x' << gray.cols << "\n";

    imshow("Logo",image);
    imshow("Small",smImage);
    imshow("Gray",gray);
    waitKey(0);
    destroyAllWindows();

    Mat out;
    gray.copyTo(out);
    bitwise_not(out,out);
    cout << "Inverted image\n";
    imshow("Inverted",out);
    waitKey(0);
    destroyAllWindows();

    gray.copyTo(out);
    Point p;
    for(int row = 0; row < gray.rows; row++){
        for(int col = 0; col < gray.cols; col++){
            p = Point(col,row);
            out.at<uchar>(p) = -out.at<uchar>(p);
        }
    }
    imshow("Inverted 2", out);
    waitKey(0);

    return 0;
}
 