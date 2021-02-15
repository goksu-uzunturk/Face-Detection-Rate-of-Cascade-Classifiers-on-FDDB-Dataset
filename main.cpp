
#include "ReadingAnnotations.h"
#include "Cascade_Classifier.h"

//The function compares the detected faces coordinates with FDDB annotaion coordinates and prints the results
void Testing(int number_of_test_images)
{

    int right_detection = 0;
    int wrong_detection = 0;
    int missing_detection = 0;
    int same_detection = 0;

    int detection_number[50];

    int total_number_of_faces = 0;
    int total_number_of_detected_faces = 0;
    int total_right_detection = 0;
    int total_wrong_detection = 0;
    int total_missing_detection = 0;
    int total_same_detection = 0;

    string path0 = "C:/Users/User/Desktop/Face Detection Staj/Test Images/" ; //path of FDDB images
    string path1 = "C:/Users/User/Desktop/Face Detection Staj/Annotations/FDDB-fold-01.txt"; //path of FDDB annotation txt file which indicates path of test images
    string path2 = "C:/Users/User/Desktop/Face Detection Staj/Annotations/FDDB-fold-01-ellipseList.txt"; // path of FDDB annotation txt file which indicates cooradinates of test iamges
    string path3 = "C:/Users/User/Downloads/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml"; //path of cascade classifier
    string path4 = "C:/Users/User/Desktop/Face Detection Staj/Test Image Results/Testing Image "; //path of the resulting images for saving


    ReadingAnnotations annotation(path0,path1, path2);
    Cascade_Classifier classifier(path3, path4);


    for (int i = 0; i < number_of_test_images; i++)
    {
        string image_path = annotation.Annotations_Image_Paths(); //i th test image path
        auto [number_of_faces, left_x, right_x, bottom_y, top_y] = annotation.Annotations_Coordinates(); // actual face coordinates and numbers of i th test image                          
        auto [number_of_detected_faces, detected_center_x, detected_center_y] = classifier.Detecting_Faces(image_path); // detected face coordinates and numbers of i th test image 

        
        for (int k = 0; k < number_of_detected_faces; k++)
        {
            for (int l = 0; l < number_of_faces; l++)
            {
                if (detection_number[l] == 1 and detected_center_x[k] > left_x[l] and detected_center_x[k] < right_x[l] and detected_center_y[k] > bottom_y[l] and detected_center_y[k] < top_y[l])
                   same_detection++;

                else if (detected_center_x[k] > left_x[l] and detected_center_x[k] < right_x[l] and detected_center_y[k] > bottom_y[l] and detected_center_y[k] < top_y[l])
                {
                    right_detection++;
                    detection_number[l] = 1;
              
                }      
                
            }
        }

        wrong_detection = number_of_detected_faces - right_detection - same_detection;
        missing_detection = number_of_faces - right_detection;

        cout << "Testing Image " << i + 1 << endl;
        cout << "The Number of Faces: " << number_of_faces << endl;
        cout << "The Number of Detected Faces: " << number_of_detected_faces << endl;
        cout << "The Number of Right Detection: " << right_detection << endl;
        cout << "The Number of Wrong Detection: " << wrong_detection << endl;
        cout << "The Number of Missing Detection: " << missing_detection << endl;
        cout << "The Number of Same Detection: " << same_detection << endl;
        cout << "--------------" << endl;

        total_number_of_faces += number_of_faces;
        total_number_of_detected_faces += number_of_detected_faces;
        total_right_detection += right_detection;
        total_wrong_detection += wrong_detection;
        total_missing_detection += missing_detection;
        total_same_detection += same_detection;

        right_detection = 0;
        wrong_detection = 0;
        missing_detection = 0;
        same_detection = 0;
        for (int x = 0; x < 50 ; x++) {
            detection_number[x] = 0;
        }

    }
    cout << "The Number of Total Faces: " << total_number_of_faces << endl;
    cout << "The Number of Total Detected Faces: " << total_number_of_detected_faces << endl;
    cout << "The Number of Total Right Detection: " << total_right_detection << endl;
    cout << "The Number of Total Wrong Detection: " << total_wrong_detection << endl;
    cout << "The Number of Total Missing Detection: " << total_missing_detection << endl;
    cout << "The Number of Total Same Detection: " << total_same_detection << endl;
    cout << "--------------" << endl;

}

int main()
{
    int number_of_test_images = 100; // The maximum value of number of test images is determined by the number of images specified by FDDB annotations txt file
    Testing(number_of_test_images);

    return 0;
}
