#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <iostream>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <math.h>
#include <QColor>
#include <cstdlib>
#include <cstring>


typedef int FXPT2DOT30;

#pragma pack(push, 1)
typedef struct {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
} CIEXYZ;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
} CIEXYZTRIPLE;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct BITMAPFILEHEADER {
    unsigned __int16 bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct BITMAPINFOHEADER {
    unsigned int biSize;
    unsigned int biWidth;
    unsigned int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    unsigned int biXPelsPerMeter;
    unsigned int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
    unsigned int bV5RedMask;
    unsigned int bV5GreenMask;
    unsigned int bV5BlueMask;
    unsigned int bV5AlphaMask;
    unsigned int bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    unsigned int bV5GammaRed;
    unsigned int bV5GammaGreen;
    unsigned int bV5GammaBlue;
    unsigned int bV5Intent;
    unsigned int bV5ProfileData;
    unsigned int bV5ProfileSize;
    unsigned int bV5Reserved;
} BITMAPINFOHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RGBTRIPLE {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGBTRIPLE;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Point {
    int x;
    int y;
} Point;
#pragma pack(pop)


class Image : public QObject {
    Q_OBJECT
public:
    explicit Image(QObject *parent = nullptr);
    Image(const char* filename, QObject *parrent = nullptr);
    ~Image();
    BITMAPFILEHEADER b_h;
    BITMAPINFOHEADER b_i;
    RGBTRIPLE **rgb;


signals:
    void changed(QPixmap);
    void size_error();
public slots:
    int open_file(const char *file);
    int save_file(const char* file);
    void createImage();
    void cutter(int x1, int y1, int x2, int y2);
    void invertCircle(int x, int y, int r);
    void draw(int x1, int y1, int x2, int y2, int r, QColor* rectangle);
    void gain(int n);
    QPixmap getPixMap();
};

#endif // MYIMAGE_H
