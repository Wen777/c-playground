/* This program reads a bitmap image file. It performs horizontal mirror relfection transformation. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // File header: 14 bytes.
  char Type[2];         // Two fixed characters, "BM" for bitmap images.
  unsigned Size;        // File size in bytes.
  char Reserved[4];     // Reserved field.
  unsigned OffsetBits;  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
  // Image information: 40 bytes.
  unsigned InfoSize;    // Information size in byte.
  unsigned Width;       // Image width in byte.
  unsigned Height;      // Image height in byte.
  unsigned short Planes;       // Number of image planes in the image, must be 1.
  unsigned short BitPerPixel;  // Number of bits used to represent the data for each pixel.
  unsigned Compression;        // Value indicating what type of compression, if any, is used, (0: uncompressed).
  unsigned ImageSize;          // Size of the actual pixel data, in bytes.
  unsigned XResolution;        // Preferred horizontal resolution of the image, in pixels per meter.
  unsigned YResolution;        // Preferred vertical resolution of the image, in pixels per meter.
  unsigned Colors;             // Value is zero except for indexed images using fewer than the maximum number of colors.
  unsigned ImportantColors;    // Number of colors that are considered important when rendering the image.
} Header;


int main(int argc, char *argv[]) {
    FILE *fptr;
    unsigned char *palette;
    unsigned char *imageData, *smallImageData;
    int i, j, k_large, k_small;
    int rowSize, fillings, rowSize_large, fillings_large;
    Header header;

  if (argc==1) { // One argument in the command line. This argument must "image_horizontal_mirror_reflection", the executable code.
    printf("Please enter the image file name.\n");
    system("pause");
    return 1;
  }
  else if (argc>3) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered.\n");
    system("pause");
    return 1;
  }

  fptr = fopen(argv[1], "rb");
  if (fptr == NULL) {
      printf("Cannot open file %s\n", argv[1]);
      return 1;
  }

  fread(&header.Type, 1, 2, fptr);
  fread(&header.Size, 4, 1, fptr);
  fread(&header.Reserved, 1, 4, fptr);
  fread(&header.OffsetBits, 4, 1, fptr);
  fread(&header.InfoSize, 4, 1, fptr);
  fread(&header.Width, 4, 1, fptr);
  fread(&header.Height, 4, 1, fptr);
  fread(&header.Planes, 2, 1, fptr);
  fread(&header.BitPerPixel, 2, 1, fptr);
  fread(&header.Compression, 4, 1, fptr);
  fread(&header.ImageSize, 4, 1, fptr);
  fread(&header.XResolution, 4, 1, fptr);
  fread(&header.YResolution, 4, 1, fptr);
  fread(&header.Colors, 4, 1, fptr);
  fread(&header.ImportantColors, 4, 1, fptr);

  palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14);
  fread(palette, header.OffsetBits - header.InfoSize - 14,  1, fptr);

  imageData = (unsigned char *) malloc(header.ImageSize);
  fread(imageData, header.ImageSize, 1, fptr);

  fclose(fptr);
  
  // prepare for reduce

  fillings_large = (4 - (header.Width * 3) % 4) % 4;
  rowSize_large = header.Width * 3 + fillings_large;

  header.Width = header.Width / 2;
  header.Height = header.Height / 2;
  header.ImageSize = header.ImageSize / 4;
  header.Size = header.OffsetBits + header.ImageSize;

  smallImageData = (unsigned char *) malloc(header.ImageSize);

  fillings = (4 - (header.Width * 3 ) % 4 ) % 4;
  rowSize = header.Width * 3 + fillings;
  for (i = 0; i < header.Height; i++) {
      for (j = 0; j < header.Width; j++ ) {
          k_small = i * rowSize + j * 3;
          k_large = (2 * i) * rowSize_large + (2 * j) * 3;

          // blue
          smallImageData[k_small] = imageData[k_large];
          // green
          smallImageData[k_small + 1] = imageData[k_large + 1];
          // red
          smallImageData[k_small + 2] = imageData[k_large + 2];
      }
  }

  fptr = fopen(argv[2], "wb");
  if (fptr == NULL) {
      fptr = fopen("image_reduced", "wb");
  }

  // Output the horizontal mirror reflection image file.
  fwrite(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
  fwrite(&header.Size, 4, 1, fptr); // File size in bytes.
  fwrite(&header.Reserved, 1, 4, fptr); // Reserved field.
  fwrite(&header.OffsetBits, 4, 1, fptr); // Offset.
  fwrite(&header.InfoSize, 4, 1, fptr); // Information size in byte.
  fwrite(&header.Width, 4, 1, fptr); // Image width in byte.
  fwrite(&header.Height, 4, 1, fptr); // Image height in byte.
  fwrite(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  fwrite(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  fwrite(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fwrite(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fwrite(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  fwrite(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  fwrite(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
  fwrite(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

  fwrite(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);
  fwrite(smallImageData, header.ImageSize, 1, fptr);

  fclose(fptr);

  free(palette);
  free(smallImageData);
  free(imageData);

  // Print the horizontal mirror reflection image file head.
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]); // Two fixed characters, "BM".
  printf("Size:             %u\n", header.Size); // File size in bytes.
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], 
                                         header.Reserved[2], header.Reserved[3]); // Reserved field.
  printf("OffsetBits:       %u\n", header.OffsetBits); // Offset.
  printf("InfoSize:         %u\n", header.InfoSize); // Information size in byte.
  printf("Width:            %u\n", header.Width); // Image width in byte.
  printf("Height:           %u\n", header.Height); // Image height in byte.
  printf("Planes:           %d\n", header.Planes); // Number of image planes in the image, must be 1.
  printf("BitPerPixel:      %d\n", header.BitPerPixel); // Number of bits used to represent the data for each pixel.
  printf("Compression:      %u\n", header.Compression); // Value indicating what type of compression.
  printf("ImageSize:        %u\n", header.ImageSize); // Size of the actual pixel data, in bytes.
  // Preferred horizontal resolution of the image, in pixels per meter.
  printf("XResolution:      %u\n", header.XResolution);
  // Preferred vertical resolution of the image, in pixels per meter.
  printf("YResolution:      %u\n", header.YResolution);
  // Value is zero except for indexed images using fewer than the maximum number of colors.
  printf("Colors:           %u\n", header.Colors);
  // Number of colors that are considered important when rendering the image.
  printf("ImportantColors:  %u\n", header.ImportantColors);
  /* End of output commands */

  return 0;
}