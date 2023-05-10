int main(){


    int arr[10], a, b, i, j;
    //Gets user Decimal and stores it to varaible a
    printf("Decimal to Binary conversion\n");
    printf("Please give me a decimal number for a:  ");
    scanf("%d", &a);

    // Gets user Decimal Number store it to variable b 
    printf("Please give me a decimal number for b:  ");
    scanf("%d", &b);

    // coverting decimal to binary of a 
    printf("Binary Number of %d is =  ",a);
    for(i = 0; a > 0; i++)
    {
        arr[i] = a % 2;
        a = a / 2;
    }
    for(j = i - 1; j >= 0; j--)  {
        printf(" %d ", arr[j]);
    }
    printf("\n");


    //converting decimal to binary of b
    printf("Binary Number of %d is =  ",b);
    for(i = 0; b > 0; i++){
        arr[i] = b % 2;
        b = b / 2;
    }
    for(j = i - 1; j >= 0; j--)  {
        printf(" %d ", arr[j]);
    }
    printf("\n");


    // And Function
    int andFunction(int a, int b){
    int count = 0;
    // converting a to binary
      for(i = 0; a > 0; i++)
      {
        arr_a[i] = a % 2;
        a = a / 2;

      }
       // converting b to binary 
      for(i = 0; b > 0; i++){
        arr_b[i] = b % 2;
        b = b / 2;
      }
       //loop to go over the two arrays with the input numbers
       // compare the same bit an arr_a and arr_b
         for(i=1; i<a; i++){
           count=1;
         }
          for(i=0; i<10; i++){
          arr_result[i] = arr_b[i]*arr_a[i];
        }
       //Convert binary to decimal