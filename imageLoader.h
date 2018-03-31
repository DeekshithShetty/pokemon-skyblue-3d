#ifndef _IMAGELOADER_H_
#define _IMAGELOADER_H_


 class ImageLoader{
	 public:
		ImageLoader(){}
		~ImageLoader(){}
		int ImageLoad(char *filename, Image *image);
		void ashImageLoad(GLuint *);
		void pikachuImageLoad(GLuint *);
		void garyImageLoad(GLuint *);
		void marillImageLoad(GLuint *);
		void charmanderImageLoad(GLuint *);
		void oddishImageLoad(GLuint *);
		void mainPageImageLoad(GLuint *);
		void battleImageLoad(GLuint *);
		void startScreenImageLoad(GLuint *);
		void aboutScreenImageLoad(GLuint *);       
};

#include "imageLoader.cpp"

#endif
