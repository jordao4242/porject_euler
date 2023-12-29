#include <stdio.h>

// Define preprocessor constants for the number of rows and columns in the file,
// the 2D array will be declared using these and the constants will be used
// to help read the file contents and output the 2D array.
#define ROWS 20
#define COLUMNS 20

int main(void)
{
  // Declare the 2D array of floats with ROWS number of rows and COLUMNS number
  // of columns
  int array[ROWS][COLUMNS];

  // Declare a file pointer variable called file to access and read the file
  FILE *file;

  // Attempt to open the file named file.txt for reading
  file = fopen("project_euler_0011.txt", "r");

  // If fopen() fails to open the file, for example because the file does not
  // exist, it will return NULL and NULL will be assigned to file.  Before
  // proceeding, check to see if file is NULL (i.e. that opening the file
  // failed) and exit the program with an error message and status if so.
  // Returning 1 instead of returning 0 with exit the program with a status
  // that signals to the shell that an error has occurred.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // row will keep track of which row in the 2D array we are storing numbers
  // into, as in the loop beloe we'll read the file into the 2D array one
  // line ('row') at a time
  int row = 0;

  // Continue the loop until we reach the end of the file (as feof() returns
  // true once we reach the end of the file).
  while (!feof(file))
  {
    // Check if an error has occured while reading the file and exit with an
    // error message and status similar to how we did above (ferror() will
    // return true if an error has occurred while reading the file).
    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }

    // The outer loop will read in each line/row of data, this inner loop will
    // read the value at each column in that row and store them into the 2D
    // array.  The counter variable i goes from 0 to the number of columns.
    for (int i = 0; i < COLUMNS; i++)
    {
      // fscanf() will read the next value from the file and store into the
      // row/column index as given by row/i (where row is the current row
      // being stored, and i the current column).  The fscanf() function
      // automatically skips over whitespace characters when reading the next
      // float value, so the spaces separating values on a line and the newlines
      // separating each row will be automatically skipped.  It's possible that
      // the file could end with trailing whitespace characters scuh as trailing
      // newlines, if so the feof() call above in the while loop condition
      // will not recogonize the end of the file.  fscanf() will return EOF
      // in this case though, as it will attempt to read another number but
      // there will be no additional number.  We use break to stop the
      // inner loop if this occurs.
      if (fscanf(file, "%d", &array[row][i]) == EOF)
        break;
    }

    // Increment row so that the numbers on the next row/line in the file are
    // stored in the next row of the 2D array
    row++;

    // If we've reached the "capacity" of the 2D array in that all rows are
    // now filled with data, we can break to stop the loop as we cannot
    // store anymore data.
    if (row == ROWS) break;
  }

  // close the file as we are done working with it
  fclose(file);

  // Output the values in the 2D array.  The outer loop uses the counter
  // variable i to loop over all row indexes and the inner loop that executes
  // for each row index i will loop over all column indexes using counter
  // variable j.  We output the values at the row/column index given by i/j
  // and output a newline after outputing the values on each row so that the
  // next row appears on the next line.

  long int produto = 0;
  int prod_linha, prod_coluna, prod_diagonal, prod_diagonal_inversa;
  int i, j;
  int num1, num2, num3, num4;
  for(i=0;i<17;i++){
    for(j=0;j<17;j++){
        prod_coluna = array[i][j]*array[i+1][j]*array[i+2][j]*array[i+3][j];
        if(produto<prod_coluna){
            produto = prod_coluna;
            num1 = array[i][j];
            num2 = array[i+1][j];
            num3 = array[i+2][j];
            num4 = array[i+3][j];
        }
        prod_linha = array[i][j]*array[i][j+1]*array[i][j+2]*array[i][j+3];
        if(produto<prod_linha){
            produto = prod_linha;
            num1 = array[i][j];
            num2 = array[i][j+1];
            num3 = array[i][j+2];
            num4 = array[i][j+3];
        }        
        prod_diagonal = array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
        if(produto<prod_diagonal){
            produto = prod_diagonal;
            num1 = array[i][j];
            num2 = array[i+1][j+1];
            num3 = array[i+2][j+2];
            num4 = array[i+3][j+3];           
        } 
        if(i<=17 && j>=3){
            prod_diagonal_inversa = array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3];
            if(produto<prod_diagonal_inversa){
                produto = prod_diagonal_inversa;
                num1 = array[i][j];
                num2 = array[i+1][j+1];
                num3 = array[i+2][j+2];
                num4 = array[i+3][j+3];  
            }
         
        } 
                       
    }
  }

  printf("%d %d %d %d %d %d\n", num1, num2, num3, num4, i, j);
  printf("%ld\n", produto);

  return 0;
}