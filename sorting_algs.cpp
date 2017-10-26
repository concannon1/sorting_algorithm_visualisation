#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

bool do1swap(int i, Mat* image){

		int temp;
		bool swapped = false;
		int colIndex = 0;
		//go to the end of the sorted part of the list -- [1, 3, 5, 6{here}, 3, 4, 1]
		
		while(image->at<Vec3b>(i, colIndex)[0] > image->at<Vec3b>(i, colIndex + 1)[0])
			colIndex++;
		if(colIndex < image->cols && image->at<Vec3b>(i, colIndex)[0] < image->at<Vec3b>(i, colIndex + 1)[0]){

			temp = image->at<Vec3b>(i, colIndex)[0];
			image->at<Vec3b>(i, colIndex)[0] = image->at<Vec3b>(i, colIndex+1)[0];
			image->at<Vec3b>(i, colIndex)[1] = image->at<Vec3b>(i, colIndex+1)[1];
			image->at<Vec3b>(i, colIndex)[2] = image->at<Vec3b>(i, colIndex+1)[2];
			image->at<Vec3b>(i, colIndex+1)[0] = temp;
			image->at<Vec3b>(i, colIndex+1)[1] = temp;
			image->at<Vec3b>(i, colIndex+1)[2] = temp;
			swapped = true;

    		
		//	cout << "swapping" << colIndex << " and " << colIndex+1<<std::endl;

		}
		return swapped;

} 

int main(int argc, char** argv )
{
    Mat image(1000,256, CV_8UC3, Scalar(0,0,0)); 

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }


	//populate image with pixels going from black to white left to right
	for(int i = 0; i < image.rows; i++){
		int colour = 0;
		int n = 0;
		for(int j = 0; j < image.cols; j++){
			
			image.at<Vec3b>(i,j)[0] = colour; 
			image.at<Vec3b>(i,j)[1] = colour;
			image.at<Vec3b>(i,j)[2] = colour;
			n++;
			colour++;

		}
	}


	/*
		while(swap)
			for every row
				do 1 swap
			show image		
		
	
	*/
	
	namedWindow("bubblesort", WINDOW_AUTOSIZE );
	bool swap = false;
	int c = 0;
	do{
		for(int i = 0; i < image.rows; i++)
			swap = do1swap(i, &image);
		//cout<<"c="<<c<<"\n";
	//	namedWindow("Display Image", WINDOW_AUTOSIZE );
		imshow("bubblesort", image);
		waitKey(1);
		c++;
	}while(swap);
	
}
	
	


