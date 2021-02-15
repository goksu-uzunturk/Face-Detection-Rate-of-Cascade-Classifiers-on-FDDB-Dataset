#include <iostream>
#include <string>
#include <tuple>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

class Cascade_Classifier
{
private:
	string path_for_cascade_classifier;
	string path_for_saving_images;

public:
	Cascade_Classifier(string path1, string path2); //constructer

	tuple<int, int*, int*> Detecting_Faces(string image_path); // The function detects the faces by cascade classifier and returns the center coordinates of detected faces  
															  // The function saves the resulting images to writing_path
															  // 1st function call saves the resulting image under the name of Testing Image 1, 2nd function call saves the resulting image under thr name of Testing Image 2

};