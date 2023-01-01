#include "helpers.h"

// Convert image to grayscale
void setPixels (int r, int g, int b, int nP, int hL, int wL, int h, int w, RGBTRIPLE image[h][w]){
    image[hL][wL].rgbtRed = r/nP;
    image[hL][wL].rgbtGreen = g/nP;
    image[hL][wL].rgbtBlue = b/nP;

}



void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]){
    int originalWidth = width - 1;
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){
            temp = image[i][j];
            image[i][j] = image[i][(-1*j) + originalWidth];
            image[i][(-1*j) + originalWidth] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int numberOfPixels = 0;
            int rTotal = 0; int gTotal = 0; int bTotal = 0;

            if (i == 0 || i == height - 1 || j == 0 || j == height -1 ){
                int Tbound = 0; int Bbound = 0; int Lbound = 0; int Rbound = 0;
                if (i == 0)             {Tbound = 1;}
                if (i == height - 1)    {Bbound = -1;}
                if (j == 0)             {Lbound = 1;}
                if (j == width - 1)     {Rbound = -1;}
                for (int h = -1 + Tbound; h < 2 + Bbound; h++){
                    for (int w = -1 + Lbound; w < 2 + Rbound; w++){

                            rTotal += image[i + h][j + w].rgbtRed;
                            gTotal += image[i + h][j + w].rgbtGreen;
                            bTotal += image[i + h][j + w].rgbtBlue;
                            numberOfPixels++;
                    }
                }

                setPixels(rTotal, gTotal, bTotal, numberOfPixels, i, j, height, width, image);
            }



            else { //no special cases
                for (int h = -1; h < 2; h++){
                    for (int w = -1; w < 2; w++){

                        rTotal += image[i + h][j + w].rgbtRed;
                        gTotal += image[i + h][j + w].rgbtGreen;
                        bTotal += image[i + h][j + w].rgbtBlue;
                        numberOfPixels++;
                    }
                }

                setPixels(rTotal, gTotal, bTotal, numberOfPixels, i, j, height, width, image);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
