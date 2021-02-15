#include "Cascade_Classifier.h"

Cascade_Classifier::Cascade_Classifier(string path1, string path2)
{
    path_for_cascade_classifier = path1;
    path_for_saving_images = path2;
}

tuple<int, int*, int*> Cascade_Classifier::Detecting_Faces(string image_path)
{
    //reading the test image whose path is specified by the return value of Function 2
    Mat image;
    image = imread(image_path, COLOR_BGR2GRAY);

    //detecting the faces in the test image 
    CascadeClassifier face_cascade;

    face_cascade.load(path_for_cascade_classifier); //path of the cascade classifier
    vector<Rect> detected_faces;
    face_cascade.detectMultiScale(image, detected_faces);

    static int detected_center_x[50], detected_center_y[50]; //50 represents the maximum number of faces that test image can contain
    for (size_t i = 0; i < detected_faces.size(); i++)
    {
        detected_center_x[i] = detected_faces[i].x + detected_faces[i].width / 2;
        detected_center_y[i] = detected_faces[i].y + detected_faces[i].height / 2;


        //drawing an ellipse around faces
        Point frontal_center(detected_faces[i].x + detected_faces[i].width / 2, detected_faces[i].y + detected_faces[i].height / 2);
        ellipse(image, frontal_center, Size(detected_faces[i].width / 2, detected_faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);


    }

    //showing the resulting test image 
    imshow("Detected Faces", image);
    waitKey(0);

    //saving the resulting test image to the writing path
    static int no = 1;
    string writing_path = path_for_saving_images + to_string(no) + ".jpg"; //the path of the resulting images for saving
    imwrite(writing_path, image);
    no++;

    return { detected_faces.size(), detected_center_x, detected_center_y };
}