#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

using namespace std;

class ReadingAnnotations
{
private:
	string file_path_for_image_path;
	string file_path_for_coordinates;
	void Skip(istream& data, size_t n, char stop); //The function skips the number of n line in a txt file when stop is declared as '\n'

public:

	ReadingAnnotations(string path1, string path2); //constructer

	string Annotations_Image_Paths(); // The function returns the path of test images by reading annotations 
									  // 1st function call returns the path of 1st test image, 2nd function call returns the path of 2nd test image etc.

	tuple<int, int*, int*, int*, int*> Annotations_Coordinates(); // The function returns the number of faces and the corner coodinates of the faces in the test images 
																  // 1st function call returns the number of faces and the corner coordinates of the faces in the 1st test image, 2nd function call returns the number of faces and the corner coordinates of the faces in the 2nd test image
};