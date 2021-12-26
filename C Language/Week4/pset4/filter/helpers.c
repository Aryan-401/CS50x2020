#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int averageValue = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen)/ 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = averageValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        int bytePosition = 0;
        for (int j= width - 1; j >= 0;j--, bytePosition++)
        {
            temp[i][bytePosition] = image[i][j];

        }

    }

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = temp[k][l];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempValue[height][width];
    for (int r=0; r < height; r++)
    {
        for (int c=0; c < width; c++)
        {
            int counter = 0;
            int rowCoords[] = {r-1, r, r+1};
            int columnCoords[] = {c-1, c, c+1};
            float totalRed = 0;
            float totalBlue = 0;
            float totalGreen = 0;

            for (int i=0; i < 3; i++)
            {
                for (int j=0; j <3; j++)
                {
                    int CurrentColumn = columnCoords[j];
                    int CurrentRow = rowCoords[i];

                    if (CurrentRow >= 0 && CurrentRow < height && CurrentColumn >= 0 && CurrentColumn < width)
                    {
                        RGBTRIPLE pixel = image[CurrentRow][CurrentColumn];
                        totalRed += pixel.rgbtRed;
                        totalBlue += pixel.rgbtBlue;
                        totalGreen += pixel.rgbtGreen;
                        counter++;
                    }
                }
            }

            tempValue[r][c].rgbtRed = round(totalRed / counter);
            tempValue[r][c].rgbtBlue = round(totalBlue / counter);
            tempValue[r][c].rgbtGreen= round(totalGreen / counter);
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l=0; l < width; l++)
        {
            image[k][l] = tempValue[k][l];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0 ,2},
        {-1, 0, 1}
    };
    int gy[3][3] = {
        {-1, -2, -1},
        {0 ,0 ,0},
        {1, 2, 1}
    };

    for (int r =0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int counter = 0;
            int rowCoords[] = {r-1, r, r+1};
            int columnCoords[] = {c-1, c, c+1};
            float gRedx = 0;
            float gBluex = 0;
            float gGreenx = 0;
            float gRedy = 0;
            float gBluey = 0;
            float gGreeny = 0;

            for (int i=0; i < 3; i++)
            {
                for (int j=0; j <3; j++)
                {
                    int CurrentColumn = columnCoords[j];
                    int CurrentRow = rowCoords[i];

                    if (CurrentRow >= 0 && CurrentRow < height && CurrentColumn >= 0 && CurrentColumn < width)
                    {
                        RGBTRIPLE pixel = image[CurrentRow][CurrentColumn];
                        gRedx += gx[i][j] * pixel.rgbtRed;
                        gBluex += gx[i][j] * pixel.rgbtBlue;
                        gGreenx += gx[i][j] * pixel.rgbtGreen;

                        gRedy += gy[i][j] * pixel.rgbtRed;
                        gBluey += gy[i][j] * pixel.rgbtBlue;
                        gGreeny += gy[i][j] * pixel.rgbtGreen;
                        counter++;

                    }
                }
            }

            int finalRed = round(sqrt(pow(gRedx, 2) + pow(gRedy, 2)));
            int finalBlue = round(sqrt(pow(gBluex, 2) + pow(gBluey, 2)));
            int finalGreen = round(sqrt(pow(gGreenx, 2) + pow(gGreeny, 2)));

            temp[r][c].rgbtRed = finalRed > 255 ? 255:finalRed;
            temp[r][c].rgbtBlue = finalBlue > 255 ? 255:finalBlue;
            temp[r][c].rgbtGreen = finalGreen > 255 ? 255:finalGreen;

        }

    }




    for (int k = 0; k < height; k++)
    {
        for (int l=0; l < width; l++)
        {
            image[k][l] = temp[k][l];
        }
    }

    return;
}
