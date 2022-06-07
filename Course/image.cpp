#include "image.h"
#include <QImage>
#include <QColor>
#include <QMessageBox>
#include <QString>
#include <cmath>


Image::Image(QObject *parent) : QObject(parent) {
    this->createImage();
}

Image::~Image() {}

int Image::open_file(const char* file) {
    size_t padding = 0;

    FILE* f;
    f = fopen(file, "rb");

    if (!f)
        return -1;

    fread(&b_h, sizeof(b_h), 1, f);
    fread(&b_i, b_h.bfOffBits - 14, 1, f);

    if (b_h.bfReserved1 != 0 ||
            b_h.bfReserved2 != 0 ||
            (b_i.biSize != 40 && b_i.biSize != 108 && b_i.biSize != 124) ||
            b_h.bfOffBits != 14 + b_i.biSize ||
            b_i.biWidth < 1 || b_i.biWidth > 10000 ||
            b_i.biSize < 1 || b_i.biWidth > 10000 ||
            b_i.biCompression != 0 ||
            b_i.biBitCount != 24) {
        fclose(f);
        return -1;
    }

    if ((b_i.biWidth * 3) % 4)
        padding = 4 - (b_i.biWidth * 3) % 4;

    rgb = new RGBTRIPLE* [b_i.biHeight];
    for (int i = 0; i < static_cast<int>(b_i.biHeight); i++) {
        rgb[i] = new RGBTRIPLE [b_i.biWidth + padding];
    }

    for (unsigned int i = 0; i < b_i.biHeight; i++) {
        int j;
        for (j = 0; j < static_cast<int>(b_i.biWidth); j++) {
            fread(&rgb[i][j], sizeof(RGBTRIPLE), 1, f);
        }
        if (padding) {
            fread(&rgb[i][j], padding, 1, f);
        }
    }

    fclose(f);
    return 0;
}

int Image::save_file(const char* file) {
    size_t padding = 0;

    FILE* f = fopen(file, "wb");
     if(!f)
         return -1;

     fwrite(&b_h, sizeof(b_h), 1, f);
     fwrite(&b_i, sizeof(b_i), 1, f);

     if ((b_i.biWidth * 3) % 4)
         padding = 4 - (b_i.biWidth * 3) % 4;

     for (int i = 0; i < static_cast<int>(b_i.biHeight); i++) {
         int j;
         for (j = 0; j < static_cast<int>(b_i.biWidth); j++) {
             fwrite(&rgb[i][j], sizeof(RGBTRIPLE), 1, f);
         }
         if (padding) {
             fwrite(&rgb[i][j], padding, 1, f);
         }
     }

    fclose(f);
    return 0;
}

QPixmap Image::getPixMap() {
    QColor pixColor;
    QImage *img = new QImage(static_cast<int>(b_i.biWidth), static_cast<int>(b_i.biHeight), QImage::Format_RGB32);

    for (int i = 0; i < static_cast<int>(b_i.biHeight); i++) {
        for (int j = 0; j < static_cast<int>(b_i.biWidth); j++) {
            pixColor.setRed(rgb[static_cast<int>(b_i.biHeight) - i - 1][j].red);
            pixColor.setGreen(rgb[static_cast<int>(b_i.biHeight) - i - 1][j].green);
            pixColor.setBlue(rgb[static_cast<int>(b_i.biHeight) - i - 1][j].blue);
            img->setPixel(j, i, pixColor.rgb());
        }
    }
    QPixmap tmp;
    tmp.convertFromImage(*img);
    delete img;
    return tmp;
}

void Image::createImage() {
    unsigned int width = 1000;
    unsigned int height = 1000;
    size_t padding = 4 - (width * 3) % 4;
    if (padding == 4)
        padding = 0;
    unsigned int sizeOfFile = width * height * 3 + static_cast<unsigned int>(padding) * height + 54;

    memset(&b_h, 0, sizeof(b_h));
    memset(&b_i, 0, sizeof(b_i));
    b_i.biSize = sizeof(b_i);
    b_i.biPlanes = 1;
    b_i.biWidth = width;
    b_i.biHeight = height;
    b_i.biBitCount = 24;
    b_h.bfType = 0x4d42;
    b_h.bfSize = sizeOfFile;
    b_h.bfOffBits = b_i.biSize + 14;

    rgb = new RGBTRIPLE* [b_i.biHeight];
    for (int i = 0; i < static_cast<int>(b_i.biHeight); i++) {
        rgb[i] = new RGBTRIPLE [b_i.biWidth + padding];
    }
    for (int i = 0; i < static_cast<int>(b_i.biHeight); i++) {
        for (int j = 0; j < static_cast<int>(b_i.biWidth); j++) {
            rgb[i][j].red = 255;
            rgb[i][j].blue = 255;
            rgb[i][j].green = 255;
        }
    }
}

void Image::invertCircle(int x, int y, int r){
    if((x+r+1) > static_cast<int>(b_i.biWidth) || (x-r-1) < 1 || (y+r) > static_cast<int>(b_i.biHeight) || (y-r-1) < 1){
        QMessageBox err;
        err.setWindowTitle("ERROR");
        err.setText("Circle does not fit on the image");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        return;
    }

    int i,j;

    for(i = 1; i <= r; i++) {
        for(j = 1; j <= r; j++) {
            if( (i*i + j*j) <= r*r) {
                rgb[y + j][x - i].red = 255 - rgb[y + j][x - i].red;
                rgb[y + j][x - i].green = 255 - rgb[y + j][x - i].green;
                rgb[y + j][x - i].blue = 255 - rgb[y + j][x - i].blue;
                rgb[y + j][x + i].red = 255 - rgb[y + j][x + i].red;
                rgb[y + j][x + i].green = 255 - rgb[y + j][x + i].green;
                rgb[y + j][x + i].blue = 255 - rgb[y + j][x + i].blue;
                rgb[y - j][x - i].red = 255 - rgb[y - j][x - i].red;
                rgb[y - j][x - i].green = 255 - rgb[y - j][x - i].green;
                rgb[y - j][x - i].blue = 255 - rgb[y - j][x - i].blue;
                rgb[y - j][x + i].red = 255 - rgb[y - j][x + i].red;
                rgb[y - j][x + i].green = 255 - rgb[y - j][x + i].green;
                rgb[y - j][x + i].blue = 255 - rgb[y - j][x + i].blue;
            }
        }
    }
    for(i = 0; i <= r; i++) {
        rgb[y][x + i].red = 255 - rgb[y][x + i].red;
        rgb[y][x + i].green = 255 - rgb[y][x + i].green;
        rgb[y][x + i].blue = 255 - rgb[y][x + i].blue;
            if (i != 0) {
                rgb[y][x - i].red = 255 - rgb[y][x - i].red;
                rgb[y][x - i].green = 255 - rgb[y][x - i].green;
                rgb[y][x - i].blue = 255 - rgb[y][x - i].blue;
                rgb[y + i][x].red = 255 - rgb[y + i][x].red;
                rgb[y + i][x].green = 255 - rgb[y + i][x].green;
                rgb[y + i][x].blue = 255 - rgb[y + i][x].blue;
                rgb[y - i][x].red = 255 - rgb[y - i][x].red;
                rgb[y - i][x].green = 255 - rgb[y - i][x].green;
                rgb[y - i][x].blue = 255 - rgb[y - i][x].blue;
            }
    }
    emit changed(this->getPixMap());
}

void Image::cutter(int x1, int y1, int x2, int y2){
    if((y2<y1) || (x2<x1)){
        QMessageBox err;
        err.setWindowTitle("ERROR");
        err.setText("wrong boundaries");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        return;
    }
    else{
        if((y2 <= static_cast<int>(b_i.biHeight)) && (x2 <= static_cast<int>(b_i.biWidth))){
            for(int i=0; i<=x2-x1; i++){
                int k = 0;
                for(int j=0;j <= y2-y1; j++){
                    rgb[j][i].red = rgb[y1+k][x1+i].red;
                    rgb[j][i].green = rgb[y1+k][x1+i].green;
                    rgb[j][i].blue = rgb[y1+k][x1+i].blue;
                    k++;
                }
            }
            b_i.biHeight = static_cast<unsigned int>(y2-y1);
            b_i.biWidth = static_cast<unsigned int>(x2-x1);
            emit changed(this->getPixMap());
        }
        else{
           QMessageBox err;
           err.setWindowTitle("ERROR");
           err.setText("values ​​are outside the picture");
           err.setIcon(QMessageBox::Critical);
           err.exec();
           return;
        }
    }
}

void Image::draw(int x1, int y1, int x2, int y2, int r, QColor* rectangle){
    int c;
    if((x1+r/2+1 <= static_cast<int>(b_i.biWidth)) && (y1+r/2+1 <= static_cast<int>(b_i.biHeight)) && (x2+r/2+1 <= static_cast<int>(b_i.biWidth)) && (y2+r/2+1 <= static_cast<int>(b_i.biHeight))){
    	if(((x1 >= x2)&&(y1 >= y2))||(((x1 <= x2)&&(y1 <= y2)))){
    	    if ((x1 >= x2)&&(y1 >= y2)) {
    	        c = x2;
    	        x2 = x1;
    	        x1 = c;
    	        c = y2;
    	        y2 = y1;
    	        y1 = c;
    	    }
    	    int lenX = x2 - x1 + 1;
    	    int lenY = y2 - y1 + 1;
    	    int error = lenX - lenY;
    	    int errorDouble;
    	    x1 += r/2;
    	    y1 += r/2;
    	    while ((x1 <= x2) || (y1 <= y2)){
    	        for (int i = 0; i <= r/2; i++){
    	            for (int j = 0; j <= r/2; j++){
    	                if (i*i + j*j <= r*r/4){
    	                    rgb[y1+j][x1+i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1+j][x1+i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1+j][x1+i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1-j][x1+i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1-j][x1+i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1-j][x1+i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1-j][x1-i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1-j][x1-i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1-j][x1-i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1+j][x1-i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1+j][x1-i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1+j][x1-i].green = static_cast<unsigned char>(rectangle->green());
    	                }
    	            }
    	        }
    	        errorDouble = error * 2;
    	        if (errorDouble > -lenY){
    	            error -= lenY;
    	            x1++;
    	        }
    	        if (errorDouble < lenX){
    	            error += lenX;
    	            y1++;
    	        }
    	    }
    	}
    	else{
    	    if ((x1 > x2)&&(y1 < y2)) {
    	        c = x2;
    	        x2 = x1;
    	        x1 = c;
    	        c = y2;
    	        y2 = y1;
    	        y1 = c;
    	    }
    	    int lenX = x2 - x1 + 1;
    	    int lenY = y1 - y2 + 1;
    	    int error = lenX - lenY;
    	    int errorDouble;
    	    x1 += r/2;
    	    y1 += r/2;
    	    while ((x1 <= x2) || (y1 >= y2)){
    	        for (int i = 0; i <= r/2; i++){
    	            for (int j = 0; j <= r/2; j++){
    	                if (i*i + j*j <= r*r/4){
    	                    rgb[y1+j][x1+i].red = static_cast<unsigned char>(rectangle->red());
     	                    rgb[y1+j][x1+i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1+j][x1+i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1-j][x1+i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1-j][x1+i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1-j][x1+i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1-j][x1-i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1-j][x1-i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1-j][x1-i].green = static_cast<unsigned char>(rectangle->green());
    	                    rgb[y1+j][x1-i].red = static_cast<unsigned char>(rectangle->red());
    	                    rgb[y1+j][x1-i].blue = static_cast<unsigned char>(rectangle->blue());
    	                    rgb[y1+j][x1-i].green = static_cast<unsigned char>(rectangle->green());
    	                }
    	            }
    	        }
        	    errorDouble = error * 2;
        	    if (errorDouble > -lenY){
        	        error -= lenY;
        	        x1++;
        	    }
        	    if (errorDouble < lenX){
        	        error += lenX;
        	        y1--;
        	    }
        	}
    	}
    	emit changed(this->getPixMap());
    }
    else {
        QMessageBox err;
        err.setWindowTitle("ERROR");
        err.setText("values ​​are outside the picture");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        return;
    }
}

void Image::gain(int n){
    b_i.biHeight = b_i.biHeight * static_cast<unsigned int>(n);
    b_i.biWidth = b_i.biWidth * static_cast<unsigned int>(n);
    //emit changed(this->getPixMap());
    for (int i = 0; i < static_cast<int>(b_i.biHeight)*n; i++) {
        if(i % 2 == 1){
            for (int j = 0; j < static_cast<int>(b_i.biWidth)*n; j++) {
                rgb[j][i].red = rgb[j - 1][i].red ;
                rgb[j][i].blue = rgb[j - 1][i].blue;
                rgb[j][i].green = rgb[j - 1][i].green;
            }
        }
        else{
            for (int j = 0; j < static_cast<int>(b_i.biWidth)*n; j++) {
                if(j % 2 == 1){
                    rgb[j][i].red = rgb[j / 2 -1][i].red ;
                    rgb[j][i].blue = rgb[j / 2 -1][i].blue;
                    rgb[j][i].green = rgb[j / 2 -1][i].green;
                }
                else{
                    rgb[j][i].red = rgb[j / 2][i].red ;
                    rgb[j][i].blue = rgb[j / 2][i].blue;
                    rgb[j][i].green = rgb[j / 2][i].green;
                }
            }
        }
    }
    emit changed(this->getPixMap());
}

Image::Image(const char* filename, QObject *parrent) : QObject(parrent){
    this->open_file(filename);
}
