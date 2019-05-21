#include <stdio.h>

int main(){
int PATH_MAX = 256;
FILE *fp;
int status;
char path[PATH_MAX];


fp = popen("nvidia-smi | grep '[0-9][0-9]C' | awk '{print $3}' | sed 's/C//'", "r");
if (fp == NULL)
    return 1;


while (fgets(path, PATH_MAX, fp) != NULL)
    printf("%s", path);


status = pclose(fp);
return 0;
}