#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "myBMP.h"


MyImage::MyImage(QObject *parent) : QObject(parent)
{
    BMInfoHeader = {};
    BMFileHeader = {};
    Rgbtriple = {};
    strcpy(fileName, "");
}

MyImage::~MyImage()
{
    delete Rgbtriple;
}

MyImage::MyImage(const char* filename, QObject *parent) : QObject(parent)
{
    this->loadimage(filename);
}

int MyImage::loadimage(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (!f) return 0;

    fread(&BMFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
    if (BMFileHeader.bfType != 0x4D42 && BMFileHeader.bfType != 0x4349 && BMFileHeader.bfType != 0x5450)
    {
        fclose(f);
        return 0;
    }

    fread(&BMInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
    if (BMFileHeader.bfReserved1 != 0 ||
        BMFileHeader.bfReserved2 != 0 ||
        (BMInfoHeader.biSize != 40 && BMInfoHeader.biSize != 108 && BMInfoHeader.biSize != 124) ||
        BMFileHeader.bfOffBits != 14 + BMInfoHeader.biSize ||
        BMInfoHeader.biWidth < 1 || BMInfoHeader.biWidth > 10000 ||
        BMInfoHeader.biSize < 1 || BMInfoHeader.biWidth > 10000 ||
        BMInfoHeader.biCompression != 0 ||
        BMInfoHeader.biBitCount != 24)
    {
        std::cout << "Wrong!\n";
        fclose(f);
        return -1;
    }

    this->imageinfo();

    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4) {
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;
    }

    Rgbtriple = new RGBTRIPLE * [BMInfoHeader.biHeight];
    for (int i = 0; i < BMInfoHeader.biHeight; i++)
        Rgbtriple[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++) {
            fread(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding != 0) {
            fread(&Rgbtriple[i][j], padding, 1, f);
        }
    }

    if (!Rgbtriple)
        return 0;
    fclose(f);
    return 1;
}

void MyImage::imageinfo()
{
    BITMAPINFOHEADER* bmp = &BMInfoHeader;
    std::cout << "Bytes: " << bmp->biSize << "\n";
    std::cout << "Height: " << bmp->biWidth << "\n";
    std::cout << "Width: " << bmp->biHeight << "\n";
    std::cout << "BitCount:" << bmp->biBitCount << "\n";
    std::cout << "Compression: " << bmp->biCompression << "\n";
    std::cout << "SizeImage: " << bmp->biSizeImage << "\n";
    return;
}

void MyImage::resetimage(const char* filename)
{
    int key;
    FILE* fFrom = fopen(filename, "rb");
    FILE* fTo = fopen("D://out.bmp", "wb");
    if (!fFrom || !fTo)
        return;

    while ((key = fgetc(fFrom)) != EOF)
    {
        fputc(key, fTo);
    }

    fread(&BMFileHeader, sizeof(BITMAPFILEHEADER), 1, fFrom);
    if (BMFileHeader.bfType != 0x4D42 && BMFileHeader.bfType != 0x4349 && BMFileHeader.bfType != 0x5450)
    {
        fclose(fFrom);
        return;
    }

    fread(&BMInfoHeader, sizeof(BITMAPINFOHEADER), 1, fFrom);
    if (BMFileHeader.bfReserved1 != 0 ||
        BMFileHeader.bfReserved2 != 0 ||
        (BMInfoHeader.biSize != 40 && BMInfoHeader.biSize != 108 && BMInfoHeader.biSize != 124) ||
        BMFileHeader.bfOffBits != 14 + BMInfoHeader.biSize ||
        BMInfoHeader.biWidth < 1 || BMInfoHeader.biWidth > 10000 ||
        BMInfoHeader.biSize < 1 || BMInfoHeader.biWidth > 10000 ||
        BMInfoHeader.biCompression != 0 ||
        BMInfoHeader.biBitCount != 24)
    {
        fclose(fFrom);
        return;
    }

    fseek(fFrom, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4) {
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;
    }

    Rgbtriple = new RGBTRIPLE * [BMInfoHeader.biHeight];
    for (int i = 0; i < BMInfoHeader.biHeight; i++)
        Rgbtriple[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++) {
            fread(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, fFrom);
        }
        if (padding != 0) {
            fread(&Rgbtriple[i][j], padding, 1, fFrom);
        }
    }

    if (!Rgbtriple)
        return;
    fclose(fFrom); fclose(fTo);
}

void MyImage::inversion(int lx, int ly, int rx, int ry)
{
    if (lx > BMInfoHeader.biHeight || rx > BMInfoHeader.biHeight || ly > BMInfoHeader.biWidth || ry > BMInfoHeader.biWidth)
    {
        QMessageBox::critical(nullptr, "ERROR", "wrong coords");
        return;
    }
    const char* fileName = "D://out.bmp";
    FILE* f = fopen(fileName, "wb");
    if (!f)
    {
        return;
    }
    fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
    fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4)
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

    lx = BMInfoHeader.biHeight - lx;
    rx = BMInfoHeader.biHeight - rx;
    for (int i = rx; i < lx; i++)
    {
        for (int j = ly; j < ry; j++)
        {
            Rgbtriple[i][j].Blue = 255 - Rgbtriple[i][j].Blue;
            Rgbtriple[i][j].Green = 255 - Rgbtriple[i][j].Green;
            Rgbtriple[i][j].Red = 255 - Rgbtriple[i][j].Red;
        }
    }

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++) {
            fwrite(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding != 0) {
            fwrite(&Rgbtriple[i][j], padding, 1, f);
        }
    }
    fclose(f);
}

void MyImage::monochrome(int lx, int ly, int rx, int ry)
{
    if (lx > BMInfoHeader.biHeight || rx > BMInfoHeader.biHeight || ly > BMInfoHeader.biWidth || ry > BMInfoHeader.biWidth)
    {
        QMessageBox::critical(nullptr, "ERROR", "wrong coordinates");
        return;
    }

    const char* fileName = "D://out.bmp";
    FILE* f = fopen(fileName, "wb");
    if (!f)
    {
        return;
    }


    fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
    fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4)
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

    int color = 0;
    lx = BMInfoHeader.biHeight - lx;
    rx = BMInfoHeader.biHeight - rx;

    for (int i = rx; i < lx; i++)
    {
        for (int j = ly; j < ry; j++)
        {
            color = (Rgbtriple[i][j].Blue + Rgbtriple[i][j].Green + Rgbtriple[i][j].Red) / 3;
            Rgbtriple[i][j].Blue = color;
            Rgbtriple[i][j].Green = color;
            Rgbtriple[i][j].Red = color;
        }
    }

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++) {
            fwrite(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding != 0) {
            fwrite(&Rgbtriple[i][j], padding, 1, f);
        }
    }
    fclose(f);
}

void MyImage::increase(QColor* color, int point)
{
    const char* fileName = "D://out.bmp";
    FILE* f = fopen(fileName, "wb");
    if (!f)
    {
        return;
    }

    if (point == 0)
    {
        int difference = 100;
        BMInfoHeader.biWidth += difference * 2;
        BMInfoHeader.biHeight += difference * 2;

        fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
        fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
        fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

        RGBTRIPLE** tmp;

        size_t padding = 0;
        if ((BMInfoHeader.biWidth * 3) % 4)
            padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

        tmp = new RGBTRIPLE * [BMInfoHeader.biHeight];
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            tmp[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];
        int k = 0;
        int l = 0;
        for (int i = difference; i < BMInfoHeader.biHeight - difference; i++){
            for (int j = difference; j < BMInfoHeader.biWidth - difference; j++)
                tmp[i][j] = Rgbtriple[k][l++];
            l = 0;
            k++;
        }

        for (int i = 0; i < difference; i++)
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            for (int j = 0; j < difference; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        for (int i = BMInfoHeader.biHeight - difference; i < BMInfoHeader.biHeight; i++)
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            for (int j = BMInfoHeader.biWidth - difference; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }

        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            int j;
            for (j = 0; j < BMInfoHeader.biWidth; j++)
            {
                fwrite(&tmp[i][j], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&tmp[i][j], padding, 1, f);
        }
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            int j;
            for (j = 0; j < BMInfoHeader.biWidth; j++)
            {
                fwrite(&tmp[i][j], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&tmp[i][j], padding, 1, f);
        }

        Rgbtriple = new RGBTRIPLE * [BMInfoHeader.biHeight];
            for (int i = 0; i < BMInfoHeader.biHeight; i++)
                Rgbtriple[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];

        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                Rgbtriple[i][j] = tmp[i][j];
            }
        }

        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            delete [] tmp[i];
        delete [] tmp;
        fclose(f);
        return;
    }

    int difference = 100;
    BMInfoHeader.biWidth += difference;
    BMInfoHeader.biHeight += difference;

    fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
    fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    RGBTRIPLE** tmp;

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4)
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

    tmp = new RGBTRIPLE * [BMInfoHeader.biHeight];
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            tmp[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];

    if (point == 1)
    {
        int l = 0;
        for (int i = 0; i < BMInfoHeader.biHeight - difference; i++){
            l = 0;
            for (int j = difference; j < BMInfoHeader.biWidth; j++)
                tmp[i][j] = Rgbtriple[i][l++];
        }

        for (int i = BMInfoHeader.biHeight - difference; i < BMInfoHeader.biHeight; i++)
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            for (int j = 0; j < difference; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
    }
    if (point == 2)
    {
        int k = 0;
        int l = 0;
        for (int i = difference; i < BMInfoHeader.biHeight; i++)
        {
            for (int j = difference; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j] = Rgbtriple[k][l++];
            }
            k++;
            l = 0;
        }

        for (int i = 0; i < difference; i++)
        {
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        }

        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            for (int j = 0; j < difference; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        }
    }
    if (point == 3)
    {
        for (int i = 0; i < BMInfoHeader.biHeight - difference; i++)
        {
            for (int j = 0; j < BMInfoHeader.biWidth - difference; j++)
            {
                tmp[i][j] = Rgbtriple[i][j];
            }
        }

        for (int i = BMInfoHeader.biHeight - difference; i < BMInfoHeader.biHeight; i++)
        {
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        }

        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            for (int j = BMInfoHeader.biWidth - difference; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        }
    }
    if (point == 4)
    {
        int k = 0;
        for (int i = difference; i < BMInfoHeader.biHeight; i++){
            for (int j = 0; j < BMInfoHeader.biWidth - difference; j++)
                tmp[i][j] = Rgbtriple[k][j];
            k++;
        }

        for (int i = 0; i < difference; i++)
            for (int j = 0; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            for (int j = BMInfoHeader.biWidth - difference; j < BMInfoHeader.biWidth; j++)
            {
                tmp[i][j].Blue = color->blue();
                tmp[i][j].Green = color->green();
                tmp[i][j].Red = color->red();
            }
    }

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++)
        {
            fwrite(&tmp[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding != 0)
            fwrite(&tmp[i][j], padding, 1, f);
    }

    Rgbtriple = new RGBTRIPLE * [BMInfoHeader.biHeight];
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
            Rgbtriple[i] = new RGBTRIPLE[BMInfoHeader.biWidth + padding];

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        for (int j = 0; j < BMInfoHeader.biWidth; j++)
        {
            Rgbtriple[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
        delete [] tmp[i];
    delete [] tmp;

    fclose(f);
}

void MyImage::decrease(int point)
{
    const char* fileName = "D://out.bmp";
    FILE* f = fopen(fileName, "wb");
    if (!f)
    {
        return;
    }
    int previousWidth = BMInfoHeader.biWidth;
    int previousHeight = BMInfoHeader.biHeight;

    if (point == 0)
    {
        BMInfoHeader.biWidth -= 200;
        BMInfoHeader.biHeight -= 200;

        fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
        fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
        fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

        size_t padding = 0;
        if ((BMInfoHeader.biWidth * 3) % 4)
            padding = 4 - (BMInfoHeader.biWidth * 3) % 4;
        for (int i = 100; i < BMInfoHeader.biHeight + 100; i++)
        {
            int k;
            for (k = 100; k < BMInfoHeader.biWidth + 100; k++) {
                fwrite(&Rgbtriple[i][k], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&Rgbtriple[i][k], padding, 1, f);
        }
        fclose(f);
        return;
    }

    BMInfoHeader.biWidth -= 100;
    BMInfoHeader.biHeight -= 100;

    fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
    fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4)
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

    if (point == 1)
    {
        for (int i = 100; i < previousHeight; i++)
        {
            int l;
            for (l = 0; l < BMInfoHeader.biWidth; l++) {
                fwrite(&Rgbtriple[i][l], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&Rgbtriple[i][l], padding, 1, f);
        }
    }
    if (point == 2)
    {
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            int j;
            for (j = 0; j < BMInfoHeader.biWidth; j++) {
                fwrite(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&Rgbtriple[i][j], padding, 1, f);
        }
    }
    if (point == 3)
    {
        for (int i = 100; i < previousHeight; i++)
        {
            int h;
            for (h = 100; h < previousWidth; h++) {
                fwrite(&Rgbtriple[i][h], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&Rgbtriple[i][h], padding, 1, f);
        }
    }
    if (point == 4)
    {
        for (int i = 0; i < BMInfoHeader.biHeight; i++)
        {
            int g;
            for (g = 100; g < previousWidth; g++) {
                fwrite(&Rgbtriple[i][g], sizeof(RGBTRIPLE), 1, f);
            }
            if (padding != 0)
                fwrite(&Rgbtriple[i][g], padding, 1, f);
        }
    }
    fclose(f);
}

void MyImage::line(int sx, int sy, int ex, int ey, int width, QColor *color) {
    if (sx > BMInfoHeader.biHeight || ex > BMInfoHeader.biHeight || sy > BMInfoHeader.biWidth || ey > BMInfoHeader.biWidth)
    {
        QMessageBox::critical(nullptr, "ERROR", "wrong coordinates");
        return;
    }

    double k = (1.0 * ey - sy)/(1.0 * ex - sx);
    double t = -1 / k;

    int wx = (int)((width / 2.0) * cos(atan(t)));
    int wy = (int)((width / 2.0) * sin(atan(t)));

    if(sx - wx < 0 || sy - wy < 0 || ex - wx < 0 || ey - wy < 0 || sx + wx > BMInfoHeader.biHeight || ex + wx > BMInfoHeader.biHeight || sy + wy > BMInfoHeader.biWidth || ey + wy > BMInfoHeader.biWidth) {
        QMessageBox::critical(nullptr, "ERROR", "wrong coordinates");
        return;
    }

    const char* fileName = "D://out.bmp";
    FILE* f = fopen(fileName, "wb");
    if (!f)
    {
        return;
    }


    fwrite(&BMFileHeader, sizeof(BMFileHeader), 1, f);
    fwrite(&BMInfoHeader, sizeof(BMInfoHeader), 1, f);
    fseek(f, BMFileHeader.bfOffBits, SEEK_SET);

    size_t padding = 0;
    if ((BMInfoHeader.biWidth * 3) % 4)
        padding = 4 - (BMInfoHeader.biWidth * 3) % 4;

    sx = BMInfoHeader.biHeight - sx;
    ex = BMInfoHeader.biHeight - ex;
    sx = BMInfoHeader.biHeight - sx;
    ex = BMInfoHeader.biHeight - ex;

    if(wx < 0) {
        wx = -wx;
        wy = -wy;
    }

    for(int i = sx - wx, j = sy - wy; i <= sx && j != sy; i++, j += t) {
        Rgbtriple[i][j].Red = color->red();
        Rgbtriple[i][j].Green = color->green();
        Rgbtriple[i][j].Blue = color->blue();
        for(int a = i, b = j; a <= ex - i && b != sy; a++, j += k) {
            Rgbtriple[a][b].Red = color->red();
            Rgbtriple[a][b].Green = color->green();
            Rgbtriple[a][b].Blue = color->blue();
        }
    }

    for(int i = sx + wx, j = sy + wy; i >= sx && j != sy; i--, j -= t) {
        Rgbtriple[i][j].Red = color->red();
        Rgbtriple[i][j].Green = color->green();
        Rgbtriple[i][j].Blue = color->blue();
        for(int a = i, b = j; a >= ex - i && b != sy; a++, j += k) {
            Rgbtriple[a][b].Red = color->red();
            Rgbtriple[a][b].Green = color->green();
            Rgbtriple[a][b].Blue = color->blue();
        }
    }

    for (int i = 0; i < BMInfoHeader.biHeight; i++)
    {
        int j;
        for (j = 0; j < BMInfoHeader.biWidth; j++) {
            fwrite(&Rgbtriple[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding != 0) {
            fwrite(&Rgbtriple[i][j], padding, 1, f);
        }
    }
    fclose(f);
}
