/* This program reads a bitmap image file. It performs vertical mirror relfection transformation. */
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
  FILE *fptr; // File pointer 
  Header	header; // Bitmap file header
  unsigned char	*palette; // Pointer: palette.
  unsigned char	*imageData; // Pointer: Image pixel data.
  int rowSize; // Number of bytes in a row. 
  int fillings; // Number of bytes of padding 0's.
  int i, j; // Loop variable.
  int k_left; // Index of the left-half pixel.
  int k_right; // Index of the right-half pixel.
  unsigned int temp; // Temporary memory for pixel swapping.

  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter the image file name.\n");
    system("pause");
    return 1;
  }
  else if (argc>3) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered.\n");
    system("pause");
    return 1;
  }

  // The input command has two or three strings, the 2nd one is the name of the input file.
  fptr = fopen(argv[1], "rb"); // Open the input file using binary mode.
  if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", argv[1]); // Print error message.
    return 1; // Terminate the program.
  }  

 // Input the colored image file.
  fread(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
  fread(&header.Size, 4, 1, fptr); // File size in bytes.
  fread(&header.Reserved, 1, 4, fptr); // Reserved field.
  fread(&header.OffsetBits, 4, 1, fptr); // Offset.
  fread(&header.InfoSize, 4, 1, fptr); // Information size in byte.
  fread(&header.Width, 4, 1, fptr); // Image width in byte.
  fread(&header.Height, 4, 1, fptr); // Image height in byte.
  fread(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  fread(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  fread(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fread(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fread(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  fread(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  fread(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
  fread(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

  palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14); // Allocate memory space for the palette.
  fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

  imageData = (unsigned char *) malloc(header.ImageSize); // Allocate memory space for image pixel data.
  fread(imageData, header.ImageSize, 1, fptr); // Read image pixel data from the image file.
	
  fclose(fptr); // Close the input file.

  fillings = (4 - (header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = header.Width * 3 + fillings; // The number of bytes in a row.
  for (i = 0; i < header.Height; i++) { // Go through all rows.
    for (j = 0; j < header.Width / 2; j++) { // Split the image in to the left half and the right half.
      k_left = i * rowSize + j * 3; // The index of the swapped pixel on the left hlaf in row i.
      k_right = i * rowSize + (header.Width - 1 - j) * 3; // The index of the swapped pixel on the right hlaf in row i.
      // Swap the j-th pixel and (Width-1-j)-th pixel in the i-th row.
      // Swap blue level.
      temp = imageData[k_left]; // Store the left value to temporary memory.
      imageData[k_left] = imageData[k_right]; // Copy the right value to the left.
      imageData[k_right] = temp; // Copy the old left value to the right.
      // Swap the green level.
      temp = imageData[k_left+1]; // Store the left value to temporary memory.
      imageData[k_left+1] = imageData[k_right+1]; // Copy the right value to the left.
      imageData[k_right+1] = temp; // Copy the old left value to the right.
      // Swap the red level.
      temp = imageData[k_left+2]; // Store the left value to temporary memory.
      imageData[k_left+2] = imageData[k_right+2]; // Copy the right value to the left.
      imageData[k_right+2] = temp; // Copy the old left value to the right.
    }
  }
  
  // If the input command has three strings, use the 3rd one as the output file name;
  // otherwise, use the default file name "vertical_mirror_reflection.bmp".
  if (argc==3) { // User provided output file name.
    fptr = fopen(argv[2], "wb"); // Open the output file using binary mode.
    printf("\nThe vertical mirror reflection image is \"%s\".\n\n", argv[2]); // Print the output file name message.
  } 
  else { // Default output file name.
    fptr = fopen("vertical_mirror_reflection.bmp", "wb"); // Open the output file using binary mode.
    printf("\nThe vertical mirror reflection image is \"vertical_mirror_reflection.bmp\".\n\n"); // Print the output file name message.
  }  
  // Output the vertical mirror reflection image file.
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

  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
  fwrite(imageData, 1, header.ImageSize, fptr); // Write the image pixel data.
  fclose(fptr); // Close the output file.
 
  // Print the vertical mirror reflection image file head.
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

  free(palette); // Release memory space of palette.
  free(imageData); // Release memory space of image pixel data.
  return 0;
}