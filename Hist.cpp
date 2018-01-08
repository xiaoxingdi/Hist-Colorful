
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
//彩色图像的直方图均衡化
Mat EqualizeHistColorImage(Mat srcImage){

	vector<Mat> channels(3);
	split(srcImage, channels);
	vector<Mat> distChannel(3);
	Mat channeltemp;
	Mat distImage;

	for (int i = 0; i < channels.size(); i++){
		equalizeHist(channels[i], distChannel[i]);//这里的输出不要带有其他形式！！
		}

	merge(distChannel, distImage);
	return distImage;
}




int main(int argc, char** argv)
{
	Mat srcImage = imread("G:/Robot/test.jpg",IMREAD_COLOR);
	Mat dstImage = EqualizeHistColorImage(srcImage);
	imwrite("Hist.jpg", dstImage);
	Mat thredImage;
	Canny(dstImage, thredImage, 100, 150, 3);
	imshow("输出原图", srcImage);
	imshow("输出均衡化", dstImage);
	imshow("边缘检测", thredImage);
	waitKey(0);
	


	
	return 0;
}



