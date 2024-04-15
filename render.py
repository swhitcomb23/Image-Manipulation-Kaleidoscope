# TODO: you will need to install cv2
# Run "pip3 install opencv-python" in CLI
import cv2
import sys
# Kaleidoscope requires numpy. Uncomment this line and install it if you need to.
import numpy as np

# Store command line arguments in variables
# change the next line to store the filename
filename = sys.argv[1]
manip = sys.argv[2]

# Open the image file
img = cv2.imread(filename)
# Get the dimensions (in pixels) of the image
dimensions = img.shape
# Copy the original image into an image for manipulation
img_manip = cv2.resize(img, (dimensions[1], dimensions[0]))
top_right = cv2.resize(img, (dimensions[1], dimensions[0]))
bottom_left = cv2.resize(img, (dimensions[1], dimensions[0]))
bottom_right = cv2.resize(top_right, (dimensions[1], dimensions[0]))
# Store white in a list, where each of the three parts is on a scale of [0, 255]
white = [255, 255, 255]
for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        if manip == 'flip':
            img_manip[x, y] = img[dimensions[0]-1-x, y]
        elif manip == 'mirror':
            # mirror the image and store in img_manip[x, y]
            img_manip[x, y] = img[x, dimensions[1]-1-y]
        elif manip == 'invert':
            # invert the image and store in img_manip[x, y]
            # Hint: img[x, y] returns the color of the pixel at that coordinate.
            # You can invert by subtracting that color from white.
            img_manip[x, y] = white - img[x, y]
        

# Displays the original image in the top left corner of the screen.
image = 'Original image'
cv2.namedWindow(image)
cv2.moveWindow(image, 0, 0)
cv2.imshow(image, img)
# Display the manipulated image alongside the original image.
manip_image = 'Manipulated image'
cv2.namedWindow(manip_image)
cv2.moveWindow(manip_image, 400, 0)
cv2.imshow(manip_image, img_manip)

for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        top_right[x, y] = img[x, dimensions[1]-1-y]    
        bottom_left[x, y] = img[dimensions[0]-1-x, y]

for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        bottom_right[x, y] = top_right[dimensions[0]-1-x, y]

# Create a kaleidoscope image, display it, and save it to a file.
top_horizontal_concat = np.concatenate((img, top_right), axis=1)
bottom_horizontal_concat = np.concatenate((bottom_left, bottom_right), axis=1)
vertical_concat = np.concatenate((top_horizontal_concat, bottom_horizontal_concat), axis=0)
vertical_concat = cv2.resize(vertical_concat, (dimensions[1], dimensions[0]))
# TODO: Save the image using the imwrite method from cv2
new_filename = 'kaleidoscope_img.jpg'
cv2.imwrite(new_filename, vertical_concat)
# Show the image
cv2.imshow('Kaleidoscope', vertical_concat)



# Infinite loop to keep the windows open until the escape key is pressed.
while True:
    k = cv2.waitKey(1)
    if k == 27:
        cv2.destroyAllWindows()
        exit()

