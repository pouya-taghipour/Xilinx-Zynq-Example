
void PrepareFrames()
{
	int startX, startY, width, height;

	//Remove black border around orginal infrared camera frame.
	//Final frame size will be 580x404
	startX = 30, startY = 35, width = 580, height = 404;
	Mat ROI1(Infrared_Mat, Rect(startX, startY, width, height));
	ROI1.copyTo(Infrared_Mat);

	//Define New ROI for infrared image to reach 580x360 frame.
	//It sould be noted that the current height is 404, so we have to cut 22 pixels from top & 22 pixels from bottom.
	startX = 0, startY = 22, width = 580, height = 320;
	Mat ROI2(Infrared_Mat, Rect(startX, startY, width, height));
	ROI2.copyTo(Infrared_Mat);

	//Define New ROI for visor image to reach 580x360 frame.
	//It sould be noted that the current width is 640, so we have to cut 30 pixels from left & 30 pixels from right.
	//to callibrate system we move visor frame in horizontal so Cx used for this goal.
	startX = Cx, startY = Cy, width = 580, height = 320;
	if (startX < 0) startX = 0;
	Mat ROI3(Visible_Mat, Rect(startX, startY, width, height));
	ROI3.copyTo(Visible_Mat);
	
	//addWeighted(Visible_Mat, 0, Visible_Mat, 3, 0.0, Visible_Mat);/////////////////////////////////////////////////




}