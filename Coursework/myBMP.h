#ifndef MYBMP_H
#define MYBMP_H

#include <iostream>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QFile>
#include <QColor>
#include <QMessageBox>
#include <math.h>


#pragma pack(push, 1)
typedef struct                       /**** BMP file header structure ****/ {
    unsigned short bfType;           /* Magic number for file */
    unsigned int   bfSize;           /* Size of file */
    unsigned short bfReserved1;      /* Reserved */
    unsigned short bfReserved2;      /* ... */
    unsigned int   bfOffBits;        /* Offset to bitmap data */
} BITMAPFILEHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct                       /**** BMP file info structure ****/ {
    unsigned int   biSize;           /* Size of info header */
    int            biWidth;          /* Width of image */
    int            biHeight;         /* Height of image */
    unsigned short biPlanes;         /* Number of color planes */
    unsigned short biBitCount;       /* Number of bits per pixel */
    unsigned int   biCompression;    /* Type of compression to use */
    unsigned int   biSizeImage;      /* Size of image data */
    int            biXPelsPerMeter;  /* X pixels per meter */
    int            biYPelsPerMeter;  /* Y pixels per meter */
    unsigned int   biClrUsed;        /* Number of colors used */
    unsigned int   biClrImportant;   /* Number of important colors */
} BITMAPINFOHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    unsigned char Blue;
    unsigned char Green;
    unsigned char Red;
} RGBTRIPLE;
#pragma pack(pop)

class MyImage: public QObject {
    Q_OBJECT

public:
    explicit MyImage(QObject *parent = nullptr);
    MyImage(const char* filename, QObject *parent = nullptr);
    ~MyImage();
    BITMAPINFOHEADER BMInfoHeader;
    BITMAPFILEHEADER BMFileHeader;
    RGBTRIPLE** Rgbtriple;
    char fileName[100];
//signals:

public slots:
    int loadimage(const char* fileName);
    void imageinfo();
    void resetimage(const char* fileName);
    void inversion(int lx, int ly, int rx, int ry);
    void monochrome(int lx, int ly, int rx, int ry);
    void increase(QColor* color, int point);
    void decrease(int point);
    void line(int sx, int sy, int ex, int ey, int width, QColor *color);
};

#endif // MYBMP_H
