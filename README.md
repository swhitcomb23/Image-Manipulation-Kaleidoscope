# Manipulating Images Using Python and C++

This Repo utilizes Python and C++ to either mirror, flip, or make a kaleidoscope image.

This program is meant to be run via the command line, the program begins in C++ and prompts the user for an image filename.
Once the filename is validated, it will ask the user for a manipulation. Once it has this information, it calls the Python file,
suppling the image file and manipulation type as command line arguments. The python file uses the CV2 libarary to created the manipulated image.

The program searches for the supplied image file in the same directory that the C++ file is in, if whatever filename you supplied is not found it will use
the default file `autumn.jpg`. The program is set to display the original image, the manipulated image and a kaleidoscope image side by side.

## Setup

In order to run this program you will need to install Python and C++, all the other includes and imports are already included in the C++ and Python files.

To run the program use the command line commands: `g++ -std=c++17 -o manipulator main.cpp` to compile and either `./manipulator` (Mac/Linux) or `manipulator` (Windows) to run.

To exit the program simply press the `esc` key once the images have loaded or `ctrl` + `c` to exit in the command line.

## Resources
- https://www.geeksforgeeks.org/how-to-validate-image-file-extension-using-regular-expression/
- https://stackoverflow.com/questions/59022814/how-to-check-if-a-file-exists-in-c

This project includes starter code from UVM professor Lisa Dion, I do not declare this project as solely my own.
