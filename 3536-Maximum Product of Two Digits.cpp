class Solution {
public:
    int maxProduct(int n) {

        // Second Method
        int arr[10];
        int i = 0;

        //Converting into array
        while(n>9){
            int num = n % 10;
            n /= 10;
            arr[i] = num;
            i++;
        }
        arr[i] = n;

        //Sorting
        for(int j=0; j<=i; j++){
            int min = j;
            for(int k=j; k<=i; k++){
                if(arr[min] > arr[k])
                    min = k;
            }
            //Swapping
            if(min != j){
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }

        //Extracting and returning
        return (arr[i]*arr[i-1]);

    }
};