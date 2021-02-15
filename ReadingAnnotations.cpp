#include "ReadingAnnotations.h"

ReadingAnnotations::ReadingAnnotations(string path0, string path1, string path2)
{
    path_for_dataset = path0;
    file_path_for_image_path = path1;
    file_path_for_coordinates = path2;

}

void ReadingAnnotations::Skip(istream& data, size_t n, char stop)
{
    size_t i = 0;
    while (i++ < n)
    data.ignore(80, stop); //It skips the characters until it shows stop in txt file
}

string ReadingAnnotations::Annotations_Image_Paths()
{
    //opening txt file
    ifstream data;
    data.open(file_path_for_image_path); 

    //checking whether txt file is opened or not
    if (!data) {
        cerr << "Unable to open txt file";
        exit(1);
    }

    //reading txt file
    static int skipping_line_number = 0;
    string image_path_in_dataset;
    string image_path;

    Skip(data, skipping_line_number, '\n'); // It skips the number of skipping_line_number in txt file
    data >> image_path_in_dataset; // It reads the string in the (skipping_line_number + 1)th line in txt file
    image_path = path_for_dataset + image_path_in_dataset + ".jpg"; //path of FDDB dataset in my computer + image_path_in_dataset

    skipping_line_number++; //When the function is called again, the function reads the path of following image in txt file.

    //closing txt file
    data.close();

    return image_path;
}

tuple<int, int*, int*, int*, int*> ReadingAnnotations::Annotations_Coordinates()
{
    //opening txt file
    ifstream data;
    data.open(file_path_for_coordinates); //path of annotations txt file

    //checking whether txt file is opened or not
    if (!data) {
        cerr << "Unable to open txt file";
        exit(1);
    }

    //reading txt file
    static int skipping_line_number = 1;
    int number_of_faces;
    static float major_axis_radius[50], minor_axis_radius[50], angle[50], center_x[50], center_y[50], end; //50 represents the maximum number of faces that test image can contain
    static int left_x[50], right_x[50], bottom_y[50], top_y[50]; //50 represents the maximum number of faces that test image can contain

    Skip(data, skipping_line_number, '\n'); // It skips the number of skipping_line_number in txt file
    data >> number_of_faces; // It reads the string in the (skipping_line_number + 1)th line in txt file

    // major_axis_radius[0], minor_axis_radius[0]...are filled with the first face coordinates in the test image
    // ...
    // major_axis_radius[number_of_faces-1], minor_axis_radius[(number_of_faces)-1]]...are filled with (the number_of_faces)th face coordinates in the test image
    // left_x[0], right_x[0]...are filled with the first face coordinates in the test image
    // ...
    // left_x[number_of_faces-1], rigth_x[(number_of_faces)-1]]...are filled with (the number_of_faces)th face coordinates in the test image  
    for (int i = 0; i < number_of_faces; i++)
    {
        data >> major_axis_radius[i] >> minor_axis_radius[i] >> angle[i] >> center_x[i] >> center_y[i] >> end;

        left_x[i] = center_x[i] - minor_axis_radius[i];
        right_x[i] = center_x[i] + minor_axis_radius[i];
        bottom_y[i] = center_y[i] - major_axis_radius[i];
        top_y[i] = center_y[i] + major_axis_radius[i];

    }
    skipping_line_number += number_of_faces + 2; //When the function is called again, the function reads the coordinates of following image in txt file.

    //closing txt file
    data.close();

    return  { number_of_faces, left_x, right_x, bottom_y, top_y };

}

