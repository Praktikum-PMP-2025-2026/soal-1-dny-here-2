/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Data Manipulation and External File
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Danny Rahmat Pratama (13224019)
 *   Nama File           : Soal1.c
 *   Deskripsi           : Membuat sensor minecraft
 * 
 */

#include <stdio.h>

int floor_new(float num){
    if(num < 0 && (num - (int)(num) != 0)){
        num = (int)(num - 1);
    }
    if(num > 0){
        (int)num;
    } 
    
    return num;
}


int main(){
    int N = 0;
    int j = 0;
    int k = 0;
    int tempj = -1;
    int tempk = -1;
    scanf("%d", &N);

    int Array[N];
    int maxsum = -9999;
    int current = 0;

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
                Array[i] = floor_new(((float)(tempj + tempk) / 2));
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
    }

    for(int i = 0; i < N ; i++){
        for(int j = i; j < N; j++){
            current += Array[j];
            if(current > maxsum){
                maxsum = current;
            }
        }
        
        current = 0;
    }
    printf("%d\n", Array[N-1]);
    printf("MAX_SUM %d", maxsum);

    return 0;
}
