
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
//��ɫͼ���ֱ��ͼ���⻯
Mat EqualizeHistColorImage(Mat srcImage){

	vector<Mat> channels(3);
	split(srcImage, channels);
	vector<Mat> distChannel(3);
	Mat channeltemp;
	Mat distImage;

	for (int i = 0; i < channels.size(); i++){
		equalizeHist(channels[i], distChannel[i]);//����������Ҫ����������ʽ����
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
	imshow("���ԭͼ", srcImage);
	imshow("������⻯", dstImage);
	imshow("��Ե���", thredImage);
	waitKey(0);
	


	
	return 0;
}



