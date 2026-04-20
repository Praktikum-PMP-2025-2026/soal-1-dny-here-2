#include <stdio.h>

int main(){
    int N = 0;
    int j = 0;
    int k = 0;
    int tempj = 0;
    int tempk = 0;
    scanf("%d", &N);

    int Array[N];
    int maxsum = 0;

    for (int i = 0; i < N; i++){
        scanf("%d", &Array[i]);
    }

    for (int i = 0; i < N; i++){
        if(Array[i] == -1){
            j = i - 1;
            k = i + 1;

            while(j != -1){
                if(Array[j] != -1){
                    tempj = Array[j];
                    break;
                } else{
                    tempj = -1;
                }
                j--;
            }
            
            while(k != N){
                if(Array[k] != -1){
                    tempk = Array[k];
                    break;
                } else{
                    tempk = -1;
                }
                k++;
                
            }

            if(tempj != -1 && tempk != -1){
                Array[i] = (tempj + tempk) / 2;
            } else if(tempj != -1){
                Array[i] = tempj;
            } else if(tempk != -1){
                Array[i] = tempk;
            } else{
                Array[i] = 0;
            }

        }
    }

    printf("RECOVERED ");
    for(int i = 0; i < N-1; i++){
        printf("%d ", Array[i]);
        maxsum += Array[i];
    }
    printf("%d\n", Array[N-1]);
    printf("MAX_SUM %d", maxsum + Array[N-1]);

    return 0;
}
