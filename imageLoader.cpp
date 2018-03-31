
// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only. 
int ImageLoader::ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL){
    	printf("File Not Found : %s\n",filename);
    	return 0;
    }
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);
    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
    	printf("Error reading width from %s.\n", filename);
    	return 0;
    }
    // read the height 
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
    	printf("Error reading height from %s.\n", filename);
    	return 0;
    }    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;
    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
    	printf("Error reading planes from %s.\n", filename);
    	return 0;
    }
    if (planes != 1) {
    	printf("Planes from %s is not 1: %u\n", filename, planes);
    	return 0;
    }
    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
    	printf("Error reading bpp from %s.\n", filename);
    	return 0;
    }
    if (bpp != 24) {
    	printf("Bpp from %s is not 24: %u\n", filename, bpp);
    	return 0;
    }
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);
    // read the data. 
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
    	printf("Error allocating memory for color-corrected image data");
    	return 0;	
    }
    if ((i = fread(image->data, size, 1, file)) != 1) {
    	printf("Error reading image data from %s.\n", filename);
    	return 0;
    }
    for (i=0;i<size;i+=3) {                           // reverse all of the colors. (bgr -> rgb)
    	temp = image->data[i];
    	image->data[i] = image->data[i+2];
    	image->data[i+2] = temp;
    }   
    // we're done.
    return 1;
}

void ImageLoader::ashImageLoad(GLuint *ashTexture){
    int i=0;
    Image *ashImage[7];
    char integer_string[10];
    
    //ash image
    for(i=0;i<7;i++){
        ashImage[i] = (Image *) malloc(sizeof(Image));

        if (ashImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Ash/ash_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");

        if (!ImageLoad(imageName, ashImage[i])) {
        exit(1);
        }        

        // Create Texture   
        glGenTextures(1, &ashTexture[i]);
        glBindTexture(GL_TEXTURE_2D, ashTexture[i]);   // 2d texture (x and y size)

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
        // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
        glTexImage2D(GL_TEXTURE_2D, 0, 3, ashImage[i]->sizeX, ashImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, ashImage[i]->data);
    }
}

void ImageLoader::pikachuImageLoad(GLuint *pikaTexture){
    // Load Texture
    int i=0;
    Image *pikaImage[5];
    char integer_string[10];

    //pikachu image
    for(i=0;i<5;i++){
        pikaImage[i] = (Image *) malloc(sizeof(Image));

        if (pikaImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Pikachu/pika_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");

        if (!ImageLoad(imageName, pikaImage[i])) {
        exit(1);
        }        

        // Create Texture   
        glGenTextures(1, &pikaTexture[i]);
        glBindTexture(GL_TEXTURE_2D, pikaTexture[i]);   // 2d texture (x and y size)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, pikaImage[i]->sizeX, pikaImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pikaImage[i]->data);
    }
}

void ImageLoader::garyImageLoad(GLuint *garyTexture){
    // Load Texture
    int i=0;
    Image *garyImage[7];
    char integer_string[10];

    //gary image
    for(i=0;i<7;i++){
        garyImage[i] = (Image *) malloc(sizeof(Image));

        if (garyImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Gary/gary_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");

        if (!ImageLoad(imageName, garyImage[i])) {
        exit(1);
        }        

        // Create Texture   
        glGenTextures(1, &garyTexture[i]);
        glBindTexture(GL_TEXTURE_2D, garyTexture[i]);   // 2d texture (x and y size)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, garyImage[i]->sizeX, garyImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, garyImage[i]->data);
    }
}


void ImageLoader::marillImageLoad(GLuint *marillTexture){
    // Load Texture
    int i=0;
    Image *marillImage[4];
    char integer_string[10];

    //MARILL image
    for(i=0;i<4;i++){
        marillImage[i] = (Image *) malloc(sizeof(Image));

        if (marillImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Marill/mar_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");
        //imageName[i] = "Data/Pickachu/pika_"+ std::to_string (i) +".bmp";

        if (!ImageLoad(imageName, marillImage[i])) {
        exit(1);
        }        

        // Create Texture   
        glGenTextures(1, &marillTexture[i]);
        glBindTexture(GL_TEXTURE_2D, marillTexture[i]);   // 2d texture (x and y size)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, marillImage[i]->sizeX, marillImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, marillImage[i]->data);
    }
}

void ImageLoader::startScreenImageLoad(GLuint *texture){
    Image *image;

    image = (Image *) malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!ImageLoad("Data/startScreen.bmp", image)) {
        exit(1);
    }        

    // Create Texture   
    glGenTextures(1,&texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
}

void ImageLoader::aboutScreenImageLoad(GLuint *texture){
    Image *image;

    image = (Image *) malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!ImageLoad("Data/aboutScreen.bmp", image)) {
        exit(1);
    }        

    // Create Texture   
    glGenTextures(1,&texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
}

void ImageLoader::mainPageImageLoad(GLuint *texture){
    Image *image1,*image2,*image3,*image4,*image5,*image6,*image7;

    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!ImageLoad("Data/pokeball.bmp", image1)) {
        exit(1);
    }        

    // Create Texture   
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    // allocate space for texture
    image2 = (Image *) malloc(sizeof(Image));
    if (image2 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/pokeGrass.bmp", image2)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);

    image3 = (Image *) malloc(sizeof(Image));
    if (image3 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!ImageLoad("Data/battleground.bmp", image3)) {
        exit(1);
    }        


    // Create Texture   
    glGenTextures(1, &texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);


    image4 = (Image *) malloc(sizeof(Image));
    if (image4 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/bg09.bmp", image4)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image4->data);


    image5 = (Image *) malloc(sizeof(Image));
    if (image5 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/title.bmp", image5)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture[4]);
    glBindTexture(GL_TEXTURE_2D, texture[4]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image5->sizeX, image5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image5->data);

    image6 = (Image *) malloc(sizeof(Image));
    if (image6 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/BrickWall.bmp", image6)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture[5]);
    glBindTexture(GL_TEXTURE_2D, texture[5]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image6->sizeX, image6->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image6->data);

    image7 = (Image *) malloc(sizeof(Image));
    if (image7 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/ground.bmp", image7)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture[6]);
    glBindTexture(GL_TEXTURE_2D, texture[6]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image7->sizeX, image7->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image7->data);
}

void ImageLoader::charmanderImageLoad(GLuint *charmanderTexture){
    // Load Texture
    int i=0;
    Image *charmanderImage[5];
    char integer_string[10];

    //charmander image
    for(i=0;i<5;i++){
        charmanderImage[i] = (Image *) malloc(sizeof(Image));

        if (charmanderImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Charmander/char_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");

        if (!ImageLoad(imageName, charmanderImage[i])) {
        exit(1);
        }        

        // Create Texture   
        glGenTextures(1, &charmanderTexture[i]);
        glBindTexture(GL_TEXTURE_2D, charmanderTexture[i]);   // 2d texture (x and y size)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, charmanderImage[i]->sizeX, charmanderImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, charmanderImage[i]->data);
    }
}

void ImageLoader::oddishImageLoad(GLuint *oddishTexture2){
    // Load Texture
    int i=0;
    Image *oddishImage[2];
    char integer_string[10];

    //oddish image
    for(i=0;i<2;i++){
        oddishImage[i] = (Image *) malloc(sizeof(Image));

        if (oddishImage[i] == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }

        sprintf(integer_string, "%d", i+1);
        char imageName[64] = "Data/Oddish/odd_"; // make sure you allocate enough space to append the other string
        strcat(imageName, integer_string); // other_string now contains "Integer: 1234"
        strcat(imageName,".bmp");

        if (!ImageLoad(imageName, oddishImage[i])) {
            exit(1);
        }        
        // Create Texture   
        glGenTextures(1, &oddishTexture2[i]);
        glBindTexture(GL_TEXTURE_2D, oddishTexture2[i]);   // 2d texture (x and y size)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, oddishImage[i]->sizeX, oddishImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, oddishImage[i]->data);
    }
}

void ImageLoader::battleImageLoad(GLuint *texture200){
    Image *image1,*image2;

    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("Data/ground.bmp", image1)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture200[0]);
    glBindTexture(GL_TEXTURE_2D, texture200[0]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    // allocate space for texture
    image2 = (Image *) malloc(sizeof(Image));
    if (image2 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!ImageLoad("Data/pokeball.bmp", image2)) {
        exit(1);
    }        
    // Create Texture   
    glGenTextures(1, &texture200[1]);
    glBindTexture(GL_TEXTURE_2D, texture200[1]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);

}  



    


