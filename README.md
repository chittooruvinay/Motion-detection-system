🎥 Motion Detection System (C++ & OpenCV)

A simple and efficient motion-detection system built using C++ and OpenCV. This project detects movement in a video using frame differencing and highlights motion regions with red bounding boxes. It demonstrates how security systems identify movement without using deep learning models.

📌 Features

Detects motion using frame differencing
Highlights movement with red bounding boxes
Processes frames with grayscale, blur, thresholding & dilation
Uses contour detection to refine motion areas
Saves the processed video with detected motion
Lightweight and fast for basic surveillance tasks

🧠 How It Works

Load video using VideoCapture
Convert frames to grayscale and apply Gaussian blur
Compute absolute difference between consecutive frames
Apply thresholding & dilation to isolate motion regions
Detect contours and draw bounding boxes
Save output using VideoWriter

🛠️ Technologies Used

C++
OpenCV

📁 Project Structure
MotionDetection/

│── main.cpp

│── video.mp4

│── motion_output.mp4

│── README.md

▶️ Running the Project
g++ main.cpp -o motion `pkg-config --cflags --libs opencv4`

./motion

🚀 Future Enhancements

Real-time camera-based detection
Object classification
Email/SMS alerts on motion
Region masking for selective detection
