
Mat Transparent(Mat frame1, Mat frame2, uchar xp)
{
	Vec3b Pixel_1;
	Vec3b Pixel_2;
	Mat output;
	frame1.copyTo(output);
	xp = (int)xp / 10;

	for (int y = 0; y < frame2.rows; y++)
	{
		for (int x = 0; x < frame2.cols; x++)
		{
			Pixel_1 = frame1.at<Vec3b>(y, x);
			Pixel_2 = frame2.at<Vec3b>(y, x);

			Pixel_1.val[0] = (Pixel_1.val[0] + (xp - 1)*Pixel_2.val[0]) / xp;
			Pixel_1.val[1] = (Pixel_1.val[1] + (xp - 1)*Pixel_2.val[1]) / xp;
			Pixel_1.val[2] = (Pixel_1.val[2] + (xp - 1)*Pixel_2.val[2]) / xp;

			output.at<Vec3b>(Point(x, y)) = Pixel_1;
		}
	}

	return output;
}