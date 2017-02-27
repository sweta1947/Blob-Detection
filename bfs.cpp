#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <queue>
using namespace cv;
using namespace std;
typedef struct Point2{
	int x;
	int y;
};
int main()
{
	int c = 0;
	Mat var1 = imread("img.jpg", 1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	queue <Point2> S;
	Point2 a, b;
	for (int i = 0; i < var1.rows; i++){
		for (int j = 0; j < var1.cols; j++)
		{
			if (var1.at<Vec3b>(i, j)[2] > 200 && var2.at<uchar>(i, j) == 0)
			{
				b.x = i;
				b.y = j;
				S.push(b);
				var2.at<uchar>(i, j) = 255;
				c++;
			}

			while (S.empty() == 0)
			{
				a = S.front();
				S.pop();
				if (a.x - 1 >= 0)
				{
					if (a.y - 1 >= 0)
					{
						if (var1.at<Vec3b>(a.x - 1, a.y - 1)[2] > 200 && var2.at<uchar>(a.x - 1, a.y - 1) == 0)
						{
							b.x = a.x - 1;
							b.y = a.y - 1;
							S.push(b);
							var2.at<uchar>(a.x - 1, a.y - 1) = 255;
						}
					}
					if (var1.at<Vec3b>(a.x - 1, a.y)[2] > 200 && var2.at<uchar>(a.x - 1, a.y) == 0)
					{
						b.x = a.x - 1;
						b.y = a.y;
						S.push(b);
						var2.at<uchar>(a.x - 1, a.y) = 255;
					}
					if (a.y + 1 < var1.cols)
					{
						if (var1.at<Vec3b>(a.x - 1, a.y + 1)[2] > 200 && var2.at<uchar>(a.x - 1, a.y + 1) == 0)
						{
							b.x = a.x - 1;
							b.y = a.y + 1;
							S.push(b);
							var2.at<uchar>(a.x - 1, a.y + 1) = 255;
						}
					}
				}
				if (a.x + 1 < var1.rows)
				{
					if (a.y - 1 >= 0)
					{
						if (var1.at<Vec3b>(a.x + 1, a.y - 1)[2] > 200 && var2.at<uchar>(a.x + 1, a.y - 1) == 0)
						{
							b.x = a.x + 1;
							b.y = a.y - 1;
							S.push(b);
							var2.at<uchar>(a.x + 1, a.y - 1) = 255;
						}
					}
					if (var1.at<Vec3b>(a.x + 1, a.y)[2] > 200 && var2.at<uchar>(a.x + 1, a.y) == 0)
					{
						b.x = a.x + 1;
						b.y = a.y;
						S.push(b);
						var2.at<uchar>(a.x + 1, a.y) = 255;
					}
					if (a.y + 1 < var1.cols)
					{
						if (var1.at<Vec3b>(a.x + 1, a.y + 1)[2] > 200 && var2.at<uchar>(a.x + 1, a.y + 1) == 0)
						{
							b.x = a.x + 1;
							b.y = a.y + 1;
							S.push(b);
							var2.at<uchar>(a.x + 1, a.y + 1) = 255;
						}
					}
				}
				if (a.y - 1 >= 0)
				{
					if (var1.at<Vec3b>(a.x, a.y - 1)[2] > 200 && var2.at<uchar>(a.x, a.y - 1) == 0)
					{
						b.x = a.x;
						b.y = a.y - 1;
						S.push(b);
						var2.at<uchar>(a.x, a.y - 1) = 255;
					}
				}
				if (a.y + 1 < var1.cols)
				{
					if (var1.at<Vec3b>(a.x, a.y + 1)[2] > 200 & var2.at<uchar>(a.x, a.y + 1) == 0)
					{
						b.x = a.x;
						b.y = a.y + 1;
						S.push(b);
						var2.at<uchar>(a.x, a.y + 1) = 255;
					}
				}
			}
		}
	}
	std::cout << c << endl;
	imshow("window1", var1);
	imshow("window2", var2);
	waitKey(0);
	return(0);
}