#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() 
{
    VideoCapture cap("video.mp4");

    if(!cap.isOpened()) 
    {
        cout << "Cannot open video file\n";
        return -1;
    }

    Mat frame, gray, prevGray, diff, thresh;

    // Read first frame
    cap >> frame;
    if(frame.empty()) 
    {
        cout << "Video is empty!" << endl;
        return -1;
    }

    int width = frame.cols;
    int height = frame.rows;

    // Video writer to save motion-marked video
    VideoWriter out("motion_output.mp4",
                    VideoWriter::fourcc('m','p','4','v'),
                    30,
                    Size(width, height));

    // Prepare previous frame
    cvtColor(frame, prevGray, COLOR_BGR2GRAY);
    GaussianBlur(prevGray, prevGray, Size(21, 21), 0);

    while (true) 
    {
        bool ret = cap.read(frame);
        if (!ret) break;

        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(21, 21), 0);

        // Find frame difference
        absdiff(prevGray, gray, diff);
        threshold(diff, thresh, 25, 255, THRESH_BINARY);

        // Expand bright areas
        dilate(thresh, thresh, Mat(), Point(-1, -1), 3);

        // Find movement
        vector<vector<Point>> contours;
        findContours(thresh, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for(auto &c : contours) 
        {

            if(contourArea(c) < 800) continue;  // ignore small motion

            Rect box = boundingRect(c);
            rectangle(frame, box, Scalar(0, 0, 255), 2);

        }

        out.write(frame);
        prevGray = gray.clone();

        if (waitKey(1) == 27) break; // ESC to exit
    }

    out.release();
    cap.release();
    return 0;
}
